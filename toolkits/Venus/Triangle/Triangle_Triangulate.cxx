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


// OpenCASCADE
#include <TCollection_AsciiString.hxx>

// Spartacus
#include <Triangle_Triangulate.hxx>

// triangle
#include <triangle.h>



// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Triangle_Triangulate::Triangle_Triangulate()
    : myError(Triangle_NoError)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Triangle_Triangulate::Triangle_Triangulate(const Handle(Triangle_Model)& theInputModel,
                                           const Triangle_Parameters& myParameters)
    : myError(Triangle_NoError), 
    myInputModel(theInputModel), 
    myParameters(myParameters)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Triangle_Triangulate::~Triangle_Triangulate()
{
    
}

// ============================================================================
/*!
    \brief Error()
*/
// ============================================================================
const Triangle_Error& Triangle_Triangulate::Error() const
{
    return myError;
}

// ============================================================================
/*!
    \brief InputModel()
*/
// ============================================================================
const Handle(Triangle_Model)& Triangle_Triangulate::InputModel() const
{
    return myInputModel;
}

// ============================================================================
/*!
    \brief IsDone()
*/
// ============================================================================
Standard_Boolean Triangle_Triangulate::IsDone() const
{
    return myIsDone;
}

// ============================================================================
/*!
    \brief OutputModel()
*/
// ============================================================================
const Handle(Triangle_Model)& Triangle_Triangulate::OutputModel() const
{
    return myOutputModel;
}

// ============================================================================
/*!
    \brief Parameters()
*/
// ============================================================================
const Triangle_Parameters& Triangle_Triangulate::Parameters() const
{
    return myParameters;
}

// ============================================================================
/*!
    \brief Perform()
*/
// ============================================================================
void Triangle_Triangulate::Perform()
{

    // ===
    // process input model
    // ===

    struct triangulateio anInput;

    // check if valid input model
    if(myInputModel.IsNull()) {
        myError = Triangle_InputModelError;
        return;
    }

    // try to populate input model
    try {

        // process edges
        anInput.numberofedges = myInputModel->NbEdges();

        anInput.edgelist = (int*) malloc(anInput.numberofedges * 2 * sizeof(int));
        anInput.edgemarkerlist = new int[anInput.numberofedges];
        for(Standard_Integer i = 0; i < anInput.numberofedges; i++) {
            Standard_Integer aNode1, aNode2;
            myInputModel->Edge(i+1, aNode1, aNode2);
            anInput.edgelist[2 * i + 0] = aNode1;
            anInput.edgelist[2 * i + 1] = aNode2;

            Standard_Integer aMarker;
            myInputModel->EdgeMarker(i+1, aMarker);
            anInput.edgemarkerlist[i] = aMarker;
        }

        // process holes
        anInput.numberofholes = myInputModel->NbHoles();
        anInput.holelist = (REAL*) malloc(anInput.numberofholes * 2 * sizeof(REAL));
        for(Standard_Integer i = 0; i < anInput.numberofholes; i++) {
            Standard_Real X, Y;
            myInputModel->Hole(i+1, X, Y);
            anInput.holelist[2 * i + 0] = X;
            anInput.holelist[2 * i + 1] = Y;
        }

        // process normals
        Standard_Integer nbNormals = myInputModel->NbNormals();
        anInput.normlist = (REAL*) malloc(nbNormals * 2 * sizeof(REAL));
        for(Standard_Integer i = 0; i < nbNormals; i++) {
            Standard_Real X, Y;
            myInputModel->Normal(i+1, X, Y);
            anInput.normlist[2 * i + 0] = X;
            anInput.normlist[2 * i + 1] = Y;
        }

        // process points
        anInput.numberofpoints = myInputModel->NbPoints();
        anInput.numberofpointattributes = myInputModel->NbPointAttributes();

        anInput.pointlist = (REAL*) malloc(anInput.numberofpoints * 2 * sizeof(REAL));
        anInput.pointattributelist = (REAL*) malloc(anInput.numberofpoints * anInput.numberofpointattributes * sizeof(REAL));
        anInput.pointmarkerlist = new int[anInput.numberofpoints];

        for(Standard_Integer i = 0; i < anInput.numberofpoints; i++) {
            Standard_Real X, Y;
            myInputModel->Point(i+1, X, Y);
            anInput.pointlist[2 * i + 0] = X;
            anInput.pointlist[2 * i + 1] = Y;

            Standard_Integer aMarker;
            myInputModel->PointMarker(i+1, aMarker);
            anInput.pointmarkerlist[i] = aMarker;

            if(myInputModel->NbPointAttributes() > 0) {
                for(Standard_Integer j = 0; j < anInput.numberofpointattributes; j++) {
                    Standard_Real aValue;
                    myInputModel->PointAttribute(i+1, j+1, aValue);
                    anInput.pointattributelist[anInput.numberofpoints * j + i] = aValue;
                }
            }

        }

        // process regions
        anInput.numberofregions = myInputModel->NbRegions();
        anInput.regionlist = (REAL *) malloc(anInput.numberofregions * 3 * sizeof(REAL));
        for(Standard_Integer i = 0; i < anInput.numberofregions; i++) {
            Standard_Real X, Y, MaxArea;
            myInputModel->Region(i+1, X, Y, MaxArea);
            anInput.regionlist[3 * i + 0] = X;
            anInput.regionlist[3 * i + 1] = Y;
            anInput.regionlist[3 * i + 2] = MaxArea;
        }

        // process segments
        anInput.numberofsegments = myInputModel->NbSegments();

        anInput.segmentlist = (int*) malloc(anInput.numberofsegments * 2 * sizeof(int));
        anInput.segmentmarkerlist = new int[anInput.numberofsegments];

        for(Standard_Integer i = 0; i < anInput.numberofsegments; i++) {
            Standard_Integer aPoint1, aPoint2;
            myInputModel->Segment(i+1, aPoint1, aPoint2);
            anInput.segmentlist[2 * i + 0] = aPoint1;
            anInput.segmentlist[2 * i + 1] = aPoint2;

            Standard_Integer aMarker;
            myInputModel->SegmentMarker(i+1, aMarker);
            anInput.segmentmarkerlist[i] = aMarker;
        }

        // process triangles
        anInput.numberoftriangles = myInputModel->NbTriangles();
        anInput.numberofcorners = myInputModel->NbTriangleCorners();
        anInput.numberoftriangleattributes = myInputModel->NbTriangleAttributes();

        anInput.trianglelist = (int*) malloc(anInput.numberoftriangles * anInput.numberofcorners * sizeof(int));
        anInput.triangleattributelist = (REAL*) malloc(anInput.numberoftriangles * anInput.numberoftriangleattributes * sizeof(REAL));
        
        for(Standard_Integer i = 0; i < anInput.numberoftriangles; i++) {
            for(Standard_Integer j = 0; j < anInput.numberofcorners; j++) {
                Standard_Integer aPoint;
                myInputModel->TriangleCorner(i+1, j+1, aPoint);
                anInput.trianglelist[anInput.numberofcorners * i + j] = aPoint;
            }

            for(Standard_Integer j = 0; j < anInput.numberoftriangleattributes; j++) {
                Standard_Real aValue;
                myInputModel->TriangleAttribute(i+1, j+1, aValue);
                anInput.triangleattributelist[anInput.numberoftriangleattributes * i + j] = aValue;
            }
        }

        // process triangle neighbors
        anInput.neighborlist = (int*) malloc(3 * anInput.numberoftriangles * sizeof(int));
        for(Standard_Integer i = 0; i < anInput.numberoftriangles; i++) {
            for(Standard_Integer j = 0; j < 3; j++) {
                Standard_Integer aNeighbor;
                myInputModel->TriangleNeighbor(i+1, j+1, aNeighbor);
                anInput.neighborlist[3 * i + j] = aNeighbor;
            }
        }

        // process triangle areas
        anInput.trianglearealist = (REAL*) malloc(anInput.numberoftriangles * sizeof(REAL));
        for(Standard_Integer i = 0; i < anInput.numberoftriangles; i++) {
            Standard_Real aArea;
            myInputModel->TriangleMaxArea(i+1, aArea);
            anInput.trianglearealist[i] = aArea;
        }

    } catch (const std::exception& e) {
        myError = Triangle_InputModelError;
        return;
    }

    // ===
    // process meshing parameters
    // ===

    TCollection_AsciiString aString;
    if(myParameters.MeshPSLG())
        aString += "p";
    if(myParameters.RefineMesh())
        aString += "r";
    if(myParameters.QualityMesh())
        aString += "q";
    if(myParameters.HasMaxArea()) {
        aString += "a";
        aString += myParameters.MaxArea();
    }
    if(myParameters.EncloseConvexHull())
        aString += "c";
    if(myParameters.ConformingDelaunay())
        aString += "D";
    if(myParameters.IgnoreHoles())
        aString += "O";
    if(!myParameters.ExactArithmetic())
        aString += "X";
    if(myParameters.GenerateSecondOrder())
        aString += "o2";
    if(myParameters.Algorithm() == Triangle_ALGO_Incremental)
        aString += "i";
    if(myParameters.Algorithm() == Triangle_ALGO_Sweepline)
        aString += "F";
    if(myParameters.CheckConformity())
        aString += "C";
    if(myParameters.IsQuiet())
        aString += "Q";
    if(myParameters.IsVerbose())
        aString += "V";
    aString += "e";
    aString += "v";
    aString += "n";

    // ===
    // initialize output data structures
    // ===

    struct triangulateio anOutput, aVoronoi;

    // initialize output
    anOutput.pointattributelist = (REAL*) NULL;
    anOutput.pointlist = (REAL*) NULL;
    anOutput.pointmarkerlist = (int*) NULL;
    anOutput.segmentlist = (int*) NULL;
    anOutput.segmentmarkerlist = (int*) NULL;
    anOutput.trianglelist = (int*) NULL;
    anOutput.triangleattributelist = (REAL*) NULL;
    anOutput.trianglearealist = (REAL*) NULL;
    anOutput.neighborlist = (int*) NULL;
    anOutput.regionlist = (REAL*) NULL;
    anOutput.holelist = (REAL*) NULL;
    anOutput.edgelist = (int*) NULL;

    // initialize Voronoi
    aVoronoi.pointattributelist = (REAL*) NULL;
    aVoronoi.pointlist = (REAL*) NULL;
    aVoronoi.edgelist = (int*) NULL;
    aVoronoi.normlist = (REAL*) NULL;

    // ===
    // triangulate
    // ===
    try {
        triangulate((char*) aString.ToCString(), &anInput, &anOutput, &aVoronoi);
    } catch (const std::exception& e) {
        myError = Triangle_TriangulationError;
        return;
    }


    // ===
    // process output model
    // ===

    // initialize output model
    myOutputModel = new Triangle_Model();

    try {

        // process edges
        if(anOutput.numberofedges > 0) {
            myOutputModel->ResizeEdges(anOutput.numberofedges);
            for(Standard_Integer i = 0; i < anOutput.numberofedges; i++) {
                Standard_Integer aPoint1 = anOutput.edgelist[2 * i + 0] + 1;
                Standard_Integer aPoint2 = anOutput.edgelist[2 * i + 1] + 1;
                myOutputModel->SetEdge(i+1, aPoint1, aPoint2);

                if(anOutput.edgemarkerlist != NULL) {
                    Standard_Integer aMarker = anOutput.edgemarkerlist[i];
                    myOutputModel->SetEdgeMarker(i+1, aMarker);
                }
            }
        }

        // process holes
        if(anOutput.numberofholes > 0) {
            myOutputModel->ResizeHoles(anOutput.numberofholes);
            for(Standard_Integer i = 0; i < anOutput.numberofholes; i++) {
                Standard_Real aX = anOutput.holelist[2 * i + 0];
                Standard_Real aY = anOutput.holelist[2 * i + 1];
                myOutputModel->SetHole(i+1, aX, aY);
            }
        }
        
        // process points
        if(anOutput.numberofpoints > 0) {
            myOutputModel->ResizePoints(anOutput.numberofpoints, anOutput.numberofpointattributes);
            for(Standard_Integer i = 0; i < anOutput.numberofpoints; i++) {
                Standard_Real aX = anOutput.pointlist[2 * i + 0];
                Standard_Real aY = anOutput.pointlist[2 * i + 1];
                myOutputModel->SetPoint(i+1, aX, aY);

                if(anOutput.pointattributelist != NULL) {
                    for(Standard_Integer j = 0; j < anOutput.numberofpointattributes; j++) {
                        Standard_Real aValue = anOutput.pointattributelist[anOutput.numberofpoints * j + i];
                        myOutputModel->SetPointAttribute(i+1, j+1, aValue);
                    }
                }

                if(anOutput.pointmarkerlist != NULL) {
                    Standard_Integer aMarker = anOutput.pointmarkerlist[i];
                    myOutputModel->SetPointMarker(i+1, aMarker);
                }
            }
        }
        
        // process regions
        if(anOutput.numberofregions > 0 ) {
            myOutputModel->ResizeRegions(anOutput.numberofregions);
            for(Standard_Integer i = 0; i < anOutput.numberofregions; i++) {
                Standard_Real aX = anOutput.regionlist[3 * i + 0];
                Standard_Real aY = anOutput.regionlist[3 * i + 1];
                Standard_Real aMaxArea = anOutput.regionlist[3 * i + 2];
                myOutputModel->SetRegion(i+1, aX, aY, aMaxArea);
            }
        }

        // process segments
        if(anOutput.numberofsegments > 0) {
            myOutputModel->ResizeSegments(anOutput.numberofsegments);
            for(Standard_Integer i = 0; i < anOutput.numberofsegments; i++) {
                Standard_Integer aPoint1 = anOutput.segmentlist[2 * i + 0];
                Standard_Integer aPoint2 = anOutput.segmentlist[2 * i + 1];
                myOutputModel->SetSegment(i+1, aPoint1, aPoint2);

                if(anOutput.segmentmarkerlist != NULL) {
                    Standard_Integer aMarker = anOutput.segmentmarkerlist[i];
                    myOutputModel->SetSegmentMarker(i+1, aMarker);
                }
            }
        }

        // process triangles
        if(anOutput.numberoftriangles > 0 && anOutput.numberofcorners > 0) {
            Standard_Boolean hasMaxArea = (anOutput.trianglearealist != NULL);
            myOutputModel->ResizeTriangles(anOutput.numberoftriangles, 
                                    anOutput.numberofcorners, 
                                    anOutput.numberoftriangleattributes,
                                    hasMaxArea);

            for(Standard_Integer i = 0; i < anOutput.numberoftriangles; i++) {
                for(Standard_Integer j = 0; j < anOutput.numberofcorners; j++) {
                    Standard_Integer aPoint = anOutput.trianglelist[anOutput.numberofcorners * i + j];
                    myOutputModel->SetTriangleCorner(i+1, j+1, aPoint);
                }

                if(anOutput.numberofpointattributes > 0) {
                    for(Standard_Integer j = 0; j < anOutput.numberoftriangleattributes; j++) {
                        Standard_Real aValue = anOutput.triangleattributelist[anOutput.numberoftriangleattributes * i + j];
                        myOutputModel->SetTriangleAttribute(i+1, j+1, aValue);
                    }
                }
            }
        }

        if(anOutput.neighborlist != NULL) {
            for(Standard_Integer i = 0; i < anOutput.numberoftriangles; i++) {
                for(Standard_Integer j = 0; j < 3; j++) {
                    Standard_Integer aNeighbor = anOutput.neighborlist[3 * i + j];
                    myOutputModel->SetTriangleNeighbor(i+1, j+1, aNeighbor);
                }
            }
        }

        if(anOutput.trianglearealist != NULL) {
            for(Standard_Integer i = 0; i < anOutput.numberoftriangles; i++) {
                Standard_Real aArea = anOutput.trianglearealist[i];
                myOutputModel->SetTriangleMaxArea(i+1, aArea);
            }
        }

    } catch (const std::exception& e) {
        myError = Triangle_OutputModelError;
        return;
    }


    // ===
    // process voronoi model
    // ===

    try {

        // initialize voronoi model
        myVoronoiModel = new Triangle_Model();
    
        // process edges
        if(aVoronoi.numberofedges > 0) {
            myVoronoiModel->ResizeEdges(aVoronoi.numberofedges);
            for(Standard_Integer i = 0; i < aVoronoi.numberofedges; i++) {
                Standard_Integer aPoint1 = aVoronoi.edgelist[2 * i + 0];
                Standard_Integer aPoint2 = aVoronoi.edgelist[2 * i + 1];
                myVoronoiModel->SetEdge(i+1, aPoint1, aPoint2);

                if(aVoronoi.edgemarkerlist != NULL) {
                    Standard_Integer aMarker = aVoronoi.edgemarkerlist[i];
                    myVoronoiModel->SetEdgeMarker(i+1, aMarker);
                }
            }
        }

        // process points
        if(aVoronoi.numberofpoints > 0) {
            myVoronoiModel->ResizePoints(aVoronoi.numberofpoints, aVoronoi.numberofpointattributes);
            for(Standard_Integer i = 0; i < aVoronoi.numberofpoints; i++) {
                Standard_Real aX = aVoronoi.pointlist[2 * i + 0];
                Standard_Real aY = aVoronoi.pointlist[2 * i + 1];
                myVoronoiModel->SetPoint(i+1, aX, aY);

                if(aVoronoi.pointattributelist != NULL) {
                    for(Standard_Integer j = 0; j < aVoronoi.numberofpointattributes; j++) {
                        Standard_Real aValue = aVoronoi.pointattributelist[aVoronoi.numberofpoints * j + i];
                        myVoronoiModel->SetPointAttribute(i+1, j+1, aValue);
                    }
                }
            }
        }
    
        // process norms
        if(aVoronoi.numberofedges > 0) {
            myVoronoiModel->ResizeNormals(aVoronoi.numberofedges);
            for(Standard_Integer i = 0; i < aVoronoi.numberofedges; i++) {
                Standard_Real aNormX = aVoronoi.normlist[2 * i + 0];
                Standard_Real aNormY = aVoronoi.normlist[2 * i + 1];
                myVoronoiModel->SetNormal(i+1, aNormX, aNormY);
            }
        }

    } catch (const std::exception& e) {
        myError = Triangle_OutputModelError;
        return;
    }

    // free input memory
    free(anInput.edgelist);
    free(anInput.edgemarkerlist);
    free(anInput.holelist);
    free(anInput.normlist);
    free(anInput.pointlist);
    free(anInput.pointattributelist);
    free(anInput.pointmarkerlist);
    free(anInput.regionlist);
    free(anInput.trianglelist);
    free(anInput.trianglearealist);
    free(anInput.triangleattributelist);
    free(anInput.segmentlist);
    free(anInput.segmentmarkerlist);

    // free output memory
    free(anOutput.edgelist);
    free(anOutput.edgemarkerlist);
    //free(anOutput.holelist);
    //free(anOutput.normlist);
    free(anOutput.pointlist);
    free(anOutput.pointattributelist);
    free(anOutput.pointmarkerlist);
    //free(anOutput.regionlist);
    free(anOutput.trianglelist);
    free(anOutput.trianglearealist);
    free(anOutput.triangleattributelist);
    free(anOutput.segmentlist);
    free(anOutput.segmentmarkerlist);

    // free voronoi memory
    free(aVoronoi.edgelist);
    free(aVoronoi.pointlist);
    free(aVoronoi.pointattributelist);
    free(aVoronoi.normlist);

    // update internal state
    myError = Triangle_NoError;
    myIsDone = Standard_True;
}

// ============================================================================
/*!
    \brief SetInputModel()
*/
// ============================================================================
void Triangle_Triangulate::SetInputModel(const Handle(Triangle_Model)& theInputModel)
{
    myInputModel = theInputModel;
}

// ============================================================================
/*!
    \brief SetParameters()
*/
// ============================================================================
void Triangle_Triangulate::SetParameters(const Triangle_Parameters& theParameters)
{
    myParameters = theParameters;
}

// ============================================================================
/*!
    \brief VoronoiModel()
*/
// ============================================================================
const Handle(Triangle_Model)& Triangle_Triangulate::VoronoiModel() const
{
    return myVoronoiModel;
}
