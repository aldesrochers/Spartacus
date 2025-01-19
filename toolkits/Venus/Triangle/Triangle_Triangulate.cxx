// ============================================================================
// Copyright (C) 2021-
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// Alexis L. Desrochers (alexisdesrochers@gmail.com)
//
// ============================================================================


// Spartacus
#include <Triangle_Triangulate.hxx>

// Triangle
#include <triangle.h>


// ============================================================================
/*!
 *  \brief Constructor()
*/
// ============================================================================
Triangle_Triangulate::Triangle_Triangulate()
    : myError(Triangle_NoError),
    myIsDone(Standard_False)
{

}

// ============================================================================
/*!
 *  \brief Destructor()
*/
// ============================================================================
Triangle_Triangulate::~Triangle_Triangulate()
{

}

// ============================================================================
/*!
 *  \brief Error()
*/
// ============================================================================
Triangle_Error Triangle_Triangulate::Error() const
{
    return myError;
}

// ============================================================================
/*!
 *  \brief Grid()
*/
// ============================================================================
const Handle(Mesh2d_Grid)& Triangle_Triangulate::Grid() const
{
    return myGrid;
}

// ============================================================================
/*!
 *  \brief IsDone()
*/
// ============================================================================
Standard_Boolean Triangle_Triangulate::IsDone() const
{
    return myIsDone;
}

// ============================================================================
/*!
 *  \brief Model()
*/
// ============================================================================
const Handle(PSLG_Model)& Triangle_Triangulate::Model() const
{
    return myModel;
}

// ============================================================================
/*!
 *  \brief Parameters()
*/
// ============================================================================
const Triangle_Parameters& Triangle_Triangulate::Parameters() const
{
    return myParameters;
}

// ============================================================================
/*!
 *  \brief Perform()
*/
// ============================================================================
void Triangle_Triangulate::Perform()
{
    // check model validity
    if(myModel.IsNull()) {
        myError = Triangle_ModelError;
        return;
    }
    
    // retrieve internal data from the PSLG model
    const PSLG_Array1OfHole& holes = myModel->Holes();
    const PSLG_Array1OfNode& points = myModel->Nodes();
    const PSLG_Array1OfRegion& regions = myModel->Regions();
    const PSLG_Array1OfSegment& segments = myModel->Segments();

    // initialize triangulateio data structures
    struct triangulateio in, out, vorout;
    
    // populate input triangulateio data structures
    in.numberofpoints = points.Size();
    in.pointlist = (REAL*) malloc(in.numberofpoints * 2 * sizeof(REAL));
    for (Standard_Integer i = 0; i < in.numberofpoints; i++) {
        in.pointlist[2 * i + 0] = points(i + 1)->X();
        in.pointlist[2 * i + 1] = points(i + 1)->Y();
    }

    in.numberofsegments = segments.Size();
    in.segmentlist = (int*) malloc(in.numberofsegments * 2 * sizeof(int));
    for (Standard_Integer i = 0; i < in.numberofsegments; i++) {
        in.segmentlist[2 * i + 0] = segments(i + 1)->Node1();
        in.segmentlist[2 * i + 1] = segments(i + 1)->Node2();
    }

    in.numberofholes = holes.Size();
    in.holelist = (REAL*) malloc(in.numberofholes * 2 * sizeof(REAL));
    for (Standard_Integer i = 0; i < in.numberofholes; i++) {
        in.holelist[2 * i + 0] = holes(i + 1)->X();
        in.holelist[2 * i + 1] = holes(i + 1)->Y();
    }

    in.numberofregions = regions.Size();
    in.regionlist = (REAL*) malloc(in.numberofregions * 4 * sizeof(REAL));
    for (Standard_Integer i = 0; i < in.numberofregions; i++) {
        in.regionlist[4 * i + 0] = regions(i + 1)->X();
        in.regionlist[4 * i + 1] = regions(i + 1)->Y();
        in.regionlist[4 * i + 2] = regions(i + 1)->Attribute();
        in.regionlist[4 * i + 3] = regions(i + 1)->MaximumArea();
    }

    // prepare triangulate switches based on parameters
    TCollection_AsciiString switches;
    switches += "p";
    if(myParameters.ComformingDelaunay)
        switches += "D";
    if(myParameters.Algorithm == Triangle_ALGO_Incremental)
        switches += "i";
    if(myParameters.Algorithm == Triangle_ALGO_Sweepline)
        switches += "F";
    if(myParameters.ComformingDelaunay)
        switches += "D";
    if(!myParameters.ExactArithmetic)
        switches += "X";
    if(myParameters.QualityMesh)
        switches += "q";
    if(myParameters.SecondOrder)
        switches += "o2";
    if(myParameters.MaximumArea > 0.) {
        switches += "a";
        switches += myParameters.MaximumArea;
    }
    switches += "Q";

    // initialize output data structures
    out.pointlist = (REAL*) NULL;
    out.trianglelist = (int*) NULL;
    out.segmentlist = (int*) NULL;

    // perform triangulation
    try {
        triangulate((char*) switches.ToCString(), &in, &out, &vorout);
    } catch (const std::exception& e) {
        myError = Triangle_TriangulationError;
        return;
    }

    #include <iostream>
    using namespace std;

    // populate Mesh2d grid from output triangulateio data structures
    myGrid = new Mesh2d_Grid();
    myGrid->ResizeCells(out.numberoftriangles, Standard_False);
    myGrid->ResizeNodes(out.numberofpoints, Standard_False);

    // add nodes to grid
    for(Standard_Integer i = 0; i<out.numberofpoints; i++) {
        Standard_Real X = out.pointlist[2 * i + 0];
        Standard_Real Y = out.pointlist[2 * i + 1];
        gp_Pnt2d aPoint(X, Y);
        myGrid->SetNode(i + 1, new Mesh2d_Node(aPoint));
    }
    
    // add triangles to grid
    for(Standard_Integer i = 0; i<out.numberoftriangles; i++) {
        if(out.numberofcorners == 3) {
            Handle(Mesh2d_Cell) aCell = new Mesh2d_Cell(3, Mesh2d_CELL_LinearTriangle3N);
            aCell->SetNode(1, out.trianglelist[3 * i + 0]);
            aCell->SetNode(2, out.trianglelist[3 * i + 1]);
            aCell->SetNode(3, out.trianglelist[3 * i + 2]);
            myGrid->SetCell(i + 1, aCell);
        } else if (out.numberofcorners == 6) {
            Handle(Mesh2d_Cell) aCell = new Mesh2d_Cell(6, Mesh2d_CELL_QuadraticTriangle6N);
            aCell->SetNode(1, out.trianglelist[3 * i + 0]);
            aCell->SetNode(2, out.trianglelist[3 * i + 1]);
            aCell->SetNode(3, out.trianglelist[3 * i + 2]);
            aCell->SetNode(4, out.trianglelist[3 * i + 3]);
            aCell->SetNode(5, out.trianglelist[3 * i + 4]);
            aCell->SetNode(6, out.trianglelist[3 * i + 5]);
            myGrid->SetCell(i + 1, aCell);
        }
    }

    // free allocated memory
    free(in.pointlist);
    free(in.segmentlist);
    free(in.holelist);
    free(in.regionlist);

    free(out.pointlist);
    free(out.trianglelist);
    free(out.segmentlist);

    //free(vorout.pointlist);
    //free(vorout.edgelist);

    // update internal state
    myIsDone = Standard_True;
}

// ============================================================================
/*!
 *  \brief SetDone()
*/
// ============================================================================
void Triangle_Triangulate::SetDone()
{
    myIsDone = Standard_True;
}

// ============================================================================
/*!
 *  \brief SetNotDone()
*/
// ============================================================================
void Triangle_Triangulate::SetNotDone()
{
    myIsDone = Standard_False;
}

// ============================================================================
/*!
 *  \brief SetModel()
*/
// ============================================================================
void Triangle_Triangulate::SetModel(const Handle(PSLG_Model)& theModel)
{
    myModel = theModel;
}

// ============================================================================
/*!
 *  \brief SetParameters()
*/
// ============================================================================
void Triangle_Triangulate::SetParameters(const Triangle_Parameters& theParameters)
{
    myParameters = theParameters;
}