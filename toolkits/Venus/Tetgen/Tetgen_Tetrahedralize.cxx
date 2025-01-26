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

#include <iostream>
using namespace std;

// OpenCASCADE
#include <TCollection_AsciiString.hxx>

// Spartacus
#include <Tetgen_Tetrahedralize.hxx>

// Tetgen
#include <tetgen.h>



// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Tetgen_Tetrahedralize::Tetgen_Tetrahedralize()
    : myError(Tetgen_NoError)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Tetgen_Tetrahedralize::Tetgen_Tetrahedralize(const Handle(Tetgen_Model)& theInputModel,
                                             const Tetgen_Parameters& myParameters)
    : myError(Tetgen_NoError), 
    myInputModel(theInputModel), 
    myParameters(myParameters)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Tetgen_Tetrahedralize::~Tetgen_Tetrahedralize()
{
    
}

// ============================================================================
/*!
    \brief Error()
*/
// ============================================================================
const Tetgen_Error& Tetgen_Tetrahedralize::Error() const
{
    return myError;
}

// ============================================================================
/*!
    \brief InputModel()
*/
// ============================================================================
const Handle(Tetgen_Model)& Tetgen_Tetrahedralize::InputModel() const
{
    return myInputModel;
}

// ============================================================================
/*!
    \brief IsDone()
*/
// ============================================================================
Standard_Boolean Tetgen_Tetrahedralize::IsDone() const
{
    return myIsDone;
}

// ============================================================================
/*!
    \brief OutputModel()
*/
// ============================================================================
const Handle(Tetgen_Model)& Tetgen_Tetrahedralize::OutputModel() const
{
    return myOutputModel;
}

// ============================================================================
/*!
    \brief Parameters()
*/
// ============================================================================
const Tetgen_Parameters& Tetgen_Tetrahedralize::Parameters() const
{
    return myParameters;
}

// ============================================================================
/*!
    \brief Perform()
*/
// ============================================================================
void Tetgen_Tetrahedralize::Perform()
{
    tetgenio::facet* f;
    tetgenio::polygon* p;

    // ===
    // process input model
    // ===

    struct tetgenio anInput;

    // check if valid input model
    if(myInputModel.IsNull()) {
        myError = Tetgen_InputModelError;
        return;
    }

    // try to populate the input model
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
        
        // process facets
        anInput.numberoffacets = myInputModel->NbFacets();

        anInput.facetlist = new tetgenio::facet[anInput.numberoffacets];
        anInput.facetmarkerlist = new int[anInput.numberoffacets];
        
        for(Standard_Integer i = 0; i < anInput.numberoffacets; i++) {
            Handle(Tetgen_Facet) aFacet = myInputModel->Facet(i+1);
            f = &anInput.facetlist[i];
            f->numberofholes = aFacet->NbHoles();
            f->numberofpolygons = aFacet->NbPolygons();
            f->polygonlist = new tetgenio::polygon[f->numberofpolygons];
            f->holelist = new REAL[f->numberofholes * 3];
            
            for(Standard_Integer j = 0; j < f->numberofholes; j++) {
                Standard_Real aX, aY, aZ;
                aFacet->Hole(j+1, aX, aY, aZ);
                f->holelist[3 * j + 0] = aX;
                f->holelist[3 * j + 1] = aY;
                f->holelist[3 * j + 2] = aZ;
            }
            
            for(Standard_Integer j = 0; j < f->numberofpolygons; j++) {
                Handle(Tetgen_Polygon) aPolygon = aFacet->Polygon(j+1);
                p = &f->polygonlist[j];
                p->numberofvertices = aPolygon->NbPoints();
                p->vertexlist = new int[p->numberofvertices];
                
                for(Standard_Integer k = 0; k < p->numberofvertices; k++) {
                    Standard_Integer aPoint;
                    aPolygon->Point(k+1, aPoint);
                    p->vertexlist[k] = aPoint - 1;
                }
            }
 
            Standard_Integer aMarker;
            myInputModel->FacetMarker(i+1, aMarker);
            anInput.facetmarkerlist[i] = aMarker;
 
        }
        
        // process facet constraints
        anInput.numberoffacetconstraints = myInputModel->NbFacetConstraints();

        anInput.facetconstraintlist = (REAL*) malloc(anInput.numberoffacetconstraints * 2 * sizeof(REAL));
        for(Standard_Integer i = 0; i < anInput.numberoffacetconstraints; i++) {
            Standard_Integer aMarker;
            Standard_Real aMaxArea;
            myInputModel->FacetConstraint(i+1, aMarker, aMaxArea);
            anInput.facetconstraintlist[2 * i + 0] = aMarker;
            anInput.facetconstraintlist[2 * i + 1] = aMaxArea;
        }

        // process holes
        anInput.numberofholes = myInputModel->NbHoles();

        anInput.holelist = (REAL*) malloc(anInput.numberofholes * 3 * sizeof(REAL));
        for(Standard_Integer i = 0; i < anInput.numberofholes; i++) {
            Standard_Real aX, aY, aZ;
            myInputModel->Hole(i, aX, aY, aZ);
            anInput.holelist[3 * i + 0] = aX;
            anInput.holelist[3 * i + 1] = aY;
            anInput.holelist[3 * i + 2] = aZ;
        }

        // process points
        anInput.numberofpoints = myInputModel->NbPoints();
        anInput.numberofpointattributes = myInputModel->NbPointAttributes();

        anInput.pointattributelist = (REAL*) malloc(anInput.numberofpoints * anInput.numberofpointattributes * sizeof(REAL));
        anInput.pointmarkerlist = new int[anInput.numberofpoints];
        anInput.pointmtrlist = (REAL*) malloc(anInput.numberofpoints * anInput.numberofpointmtrs * sizeof(REAL));
        anInput.pointlist = (REAL*) malloc(anInput.numberofpoints * 3 * sizeof(REAL));

        for(Standard_Integer i = 0; i < anInput.numberofpoints; i++) {
            Standard_Real aX, aY, aZ;
            myInputModel->Point(i+1, aX, aY, aZ);
            anInput.pointlist[3 * i + 0] = aX;
            anInput.pointlist[3 * i + 1] = aY;
            anInput.pointlist[3 * i + 2] = aZ;
            
            Standard_Integer aMarker;
            myInputModel->PointMarker(i+1, aMarker);
            anInput.pointmarkerlist[i] = aMarker;

            for(Standard_Integer j = 0; j < anInput.numberofpointattributes; j++) {
                Standard_Real aValue;
                myInputModel->PointAttribute(i+1, j+1, aValue);
                anInput.pointattributelist[anInput.numberofpoints * j + i] = aValue;
            }
        }

        // process regions
        anInput.numberofregions = myInputModel->NbRegions();

        anInput.regionlist = (REAL*) malloc(anInput.numberofregions * 4 * sizeof(REAL));
        for(Standard_Integer i = 0; i < anInput.numberofregions; i++) {
            Standard_Real aX, aY, aZ, aMaxVolume;
            myInputModel->Region(i+1, aX, aY, aZ, aMaxVolume);
            anInput.regionlist[2 * i + 0] = aX;
            anInput.regionlist[2 * i + 1] = aY;
            anInput.regionlist[2 * i + 2] = aZ;
            anInput.regionlist[2 * i + 3] = aMaxVolume;
        }

        // process segment constraints
        anInput.numberofsegmentconstraints = myInputModel->NbSegmentConstraints();

        anInput.segmentconstraintlist = (REAL*) malloc(anInput.numberofsegmentconstraints * 2 * sizeof(REAL));
        for(Standard_Integer i = 0; i < anInput.numberofsegmentconstraints; i++) {
            Standard_Integer aPoint;
            Standard_Real aMaxLength;
            myInputModel->SegmentConstraint(i+1, aPoint, aMaxLength);
            anInput.segmentconstraintlist[2 * i + 0] = aPoint - 1;
            anInput.segmentconstraintlist[2 * i + 1] = aMaxLength;
        }

        // process tetrahedrons
        anInput.numberoftetrahedra = myInputModel->NbTetrahedrons();
        anInput.numberofcorners = myInputModel->NbTetrahedronCorners();
        anInput.numberoftetrahedronattributes = myInputModel->NbTetrahedronAttributes();

        anInput.tetrahedronattributelist = (REAL*) malloc(anInput.numberoftetrahedra * anInput.numberoftetrahedronattributes * sizeof(REAL));
        anInput.tetrahedronlist = (int*) malloc(anInput.numberoftetrahedra * 4 * sizeof(int));

        for(Standard_Integer i = 0; i < anInput.numberoftetrahedra; i++) {
            for(Standard_Integer j = 0; j < anInput.numberofcorners; j++) {
                Standard_Integer aPoint;
                myInputModel->TetrahedronCorner(i+1, j+1, aPoint);
                anInput.tetrahedronlist[anInput.numberofcorners * i + j] = aPoint - 1;
            }
        
            for(Standard_Integer j = 0; j < anInput.numberoftetrahedronattributes; j++) {
                Standard_Real aValue;
                myInputModel->TetrahedronAttribute(i+1, j+1, aValue);
                anInput.tetrahedronattributelist[anInput.numberoftetrahedronattributes * i + j] = aValue;
            }
        }

        // process tetrahedron neighbors
        anInput.neighborlist = (int*) malloc(anInput.numberoftetrahedra * 4 * sizeof(int));
        for(Standard_Integer i = 0; i < anInput.numberoftetrahedra; i++) {
            for(Standard_Integer j = 0; j < 4; j++) {
                Standard_Integer aNeighbor;
                myInputModel->TetrahedronNeighbor(i+1, j+1, aNeighbor);
                anInput.neighborlist[4 * i + j] = aNeighbor - 1;
            }
        }

        // process tetrahedron volumes
        anInput.tetrahedronvolumelist = (REAL*) malloc(anInput.numberoftetrahedra * sizeof(REAL));
        for(Standard_Integer i = 0; i < anInput.numberoftetrahedra; i++) {
            Standard_Real aVolume;
            myInputModel->TetrahedronMaxVolume(i+1, aVolume);
            anInput.tetrahedronvolumelist[i] = aVolume;
        }

        // process triangles
        anInput.numberoftrifaces = myInputModel->NbTriangles();

        anInput.trifacelist = (int*) malloc(anInput.numberoftrifaces * 3 * sizeof(int));
        anInput.trifacemarkerlist = (int*) malloc(anInput.numberoftrifaces * sizeof(int));

        for(Standard_Integer i = 0; i < anInput.numberoftrifaces; i++) {
            Standard_Integer aP1, aP2, aP3;
            myInputModel->Triangle(i+1, aP1, aP2, aP3);
            anInput.trifacelist[3 * i + 0] = aP1;
            anInput.trifacelist[3 * i + 1] = aP2;
            anInput.trifacelist[3 * i + 2] = aP3;

            Standard_Integer aMarker;
            myInputModel->TriangleMarker(i+1, aMarker);
            anInput.trifacemarkerlist[i] = aMarker;
        }

    } catch(const std::exception& e) {
        myError = Tetgen_InputModelError;
        return;
    }
    
    // ===
    // process meshing parameters
    // ===

    TCollection_AsciiString aString;
    if(myParameters.MeshPLC())
        aString += "p";
    if(myParameters.PreservesInputMesh())
        aString += "Y";
    if(myParameters.RefineMesh())
        aString += "r";
    if(myParameters.MeshCoarsening())
        aString += "R";
    if(myParameters.MaxVolume() > 0.0) {
        aString += "a";
        aString += myParameters.MaxVolume();
    }
    if(myParameters.GenerateSecondOrder())
        aString += "o2";
    if(myParameters.MeshOptimization() != 2) {
        aString += "O";
        aString += myParameters.MeshOptimization();
    }
    //if(myParameters.Tolerance() != 10^-8) {
    //    aString += "T";
    //    aString += myParameters.Tolerance();
    //}
    if(!myParameters.ExactArithmetic())
        aString += "X";
    if(!myParameters.MergeCoplanarFacets())
        aString += "M";
    if(myParameters.WeightedDelaunay())
        aString += "w";
    if(myParameters.RetainsConvexHull())
        aString += "c";
    if(myParameters.DetectSelfIntersections())
        aString += "d";
    aString += "f";
    aString += "e";
    aString += "n";
    //aString += "v";
    if(myParameters.CheckConformity())
        aString += "C";
    if(myParameters.IsQuiet())
        aString += "Q";
    if(myParameters.IsVerbose())
        aString += "V";
    
    // ===
    // initialize output data structures
    // ===

    struct tetgenio anOutput;

    // initialize output 
    anOutput.pointattributelist = (REAL*) NULL;
    anOutput.pointlist = (REAL*) NULL;
    anOutput.pointmarkerlist = (int*) NULL;
    anOutput.trifacelist = (int*) NULL;
    anOutput.trifacemarkerlist = (int*) NULL;
    anOutput.neighborlist = (int*) NULL;
    anOutput.tetrahedronattributelist = (REAL*) NULL;
    anOutput.tetrahedronlist = (int*) NULL;
    anOutput.tetrahedronvolumelist = (REAL*) NULL;
    anOutput.edgelist = (int*) NULL;
    anOutput.holelist = (REAL*) NULL;
    anOutput.regionlist = (REAL*) NULL;
    
    // ===
    // call tetgen
    // ===

    try {
        tetrahedralize((char*) aString.ToCString(), &anInput, &anOutput);
    } catch(const std::exception& e) {
        myError = Tetgen_TetrahedralizationError;
        return;
    }

    // ===
    // process output
    // ===

    myOutputModel = new Tetgen_Model();

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

        // process facets
        if(anOutput.numberoffacets > 0) {
            myOutputModel->ResizeFacets(anOutput.numberoffacets);

            // process facet data
            for(Standard_Integer i = 0; i < anOutput.numberoffacets; i++) {
                Handle(Tetgen_Facet) aFacet = new Tetgen_Facet();
                f = &anOutput.facetlist[i];
                aFacet->ResizeHoles(f->numberofholes);
                aFacet->ResizePolygons(f->numberofpolygons);

                for(Standard_Integer j = 0; j < f->numberofholes; j++) {
                    Standard_Real aX = f->holelist[3 * j + 0];
                    Standard_Real aY = f->holelist[3 * j + 1];
                    Standard_Real aZ = f->holelist[3 * j + 2];
                    aFacet->SetHole(j+1, aX, aY, aZ);
                }

                for(Standard_Integer j = 0; j < f->numberofpolygons; j++) {
                    Handle(Tetgen_Polygon) aPolygon = new Tetgen_Polygon();
                    p = &f->polygonlist[j];
                    aPolygon->ResizePoints(p->numberofvertices);
                    for(Standard_Integer k = 0; k < p->numberofvertices; k++) {
                        Standard_Integer aPoint = p->vertexlist[k] + 1;
                        aPolygon->SetPoint(k+1, aPoint);
                    }
                    aFacet->SetPolygon(j+1, aPolygon);
                }
                
                myOutputModel->SetFacet(i+1, aFacet);

                if(anOutput.facetmarkerlist != NULL) {
                    Standard_Integer aMarker = anOutput.facetmarkerlist[i];
                    myOutputModel->SetFacetMarker(i+1, aMarker);
                }
            }
        }

        // process facet constraints
        if(anOutput.numberoffacetconstraints > 0) {
            for(Standard_Integer i = 0; i < anOutput.numberoffacetconstraints; i++) {
                Standard_Integer aMarker = anOutput.facetconstraintlist[2 * i + 0];
                Standard_Real aMaxArea = anOutput.facetconstraintlist[2 * i + 1];
                myOutputModel->SetFacetConstraint(i+1, aMarker, aMaxArea);
            }
        }

        // process holes
        if(anOutput.numberofholes > 0) {
            myOutputModel->ResizeHoles(anOutput.numberofholes);
            for(Standard_Integer i = 0; i < anOutput.numberofholes; i++) {
                Standard_Real aX = anOutput.holelist[3 * i + 0];
                Standard_Real aY = anOutput.holelist[3 * i + 1];
                Standard_Real aZ = anOutput.holelist[3 * i + 2];
                myOutputModel->SetHole(i+1, aX, aY, aZ);
            }
        }

        // process points
        if(anOutput.numberofpoints > 0) {
            myOutputModel->ResizePoints(anOutput.numberofpoints, anOutput.numberofpointattributes);
            for(Standard_Integer i = 0; i < anOutput.numberofpoints; i++) {
                Standard_Real aX = anOutput.pointlist[3 * i + 0];
                Standard_Real aY = anOutput.pointlist[3 * i + 1];
                Standard_Real aZ = anOutput.pointlist[3 * i + 2];
                myOutputModel->SetPoint(i+1, aX, aY, aZ);

                Standard_Integer aMarker = anOutput.pointmarkerlist[i];
                myOutputModel->SetPointMarker(i+1, aMarker);

                for(Standard_Integer j = 0; j < anOutput.numberofpointattributes; j++) {
                    Standard_Real aValue = anOutput.pointattributelist[anOutput.numberofpoints * j + i];
                    myOutputModel->SetPointAttribute(i+1, j+1, aValue);
                }
            }
        }

        // process regions
        if(anOutput.numberofregions > 0) {
            myOutputModel->ResizeRegions(anOutput.numberofregions);
            for(Standard_Integer i = 0; i < anOutput.numberofregions; i++) {    
                Standard_Real aX = anOutput.regionlist[4 * i + 0];
                Standard_Real aY = anOutput.regionlist[4 * i + 1];
                Standard_Real aZ = anOutput.regionlist[4 * i + 2];
                Standard_Real aMaxVolume = anOutput.regionlist[4 * i + 3];
                myOutputModel->SetRegion(i+1, aX, aY, aZ, aMaxVolume);
            }
        }

        // process segment constraints
        if(anOutput.numberofsegmentconstraints > 0) {
            for(Standard_Integer i = 0; i < anOutput.numberofsegmentconstraints; i++) {
                Standard_Integer aPoint = anOutput.segmentconstraintlist[2 * i + 0] + 1;
                Standard_Real aMaxLength = anOutput.segmentconstraintlist[2 * i + 1];
                myOutputModel->SetSegmentConstraint(i+1, aPoint, aMaxLength);
            }
        }

        // process tetrahedrons
        if(anOutput.numberoftetrahedra > 0) {
            myOutputModel->ResizeTetrahedrons(anOutput.numberoftetrahedra, 
                                              anOutput.numberofcorners,
                                              anOutput.numberoftetrahedronattributes);

            for(Standard_Integer i = 0; i < anOutput.numberoftetrahedra; i++) {
                for(Standard_Integer j = 0; j < anOutput.numberofcorners; j++) {
                    Standard_Integer aPoint = anOutput.tetrahedronlist[anOutput.numberofcorners * i + j] + 1;
                    myOutputModel->SetTetrahedronCorner(i+1, j+1, aPoint);
                }

                for(Standard_Integer j = 0; j < anOutput.numberoftetrahedronattributes; j++) {
                    Standard_Real aValue = anOutput.tetrahedronattributelist[anOutput.numberoftetrahedronattributes * i + j];
                    myOutputModel->SetTetrahedronAttribute(i+1, j+1, aValue);
                }
            }
        }

        // process tetrahedrons neighbors
        if(anOutput.neighborlist != NULL) {
            for(Standard_Integer i = 0; i < anOutput.numberoftetrahedra; i++) {
                for(Standard_Integer j = 0; j < 4; j++) {
                    Standard_Integer aTetrahedron = anOutput.neighborlist[4 * i + j] + 1;
                    myOutputModel->SetTetrahedronNeighbor(i+1, j+1, aTetrahedron);
                }
            }
        }

        // process tetrahedrons volumes
        if(anOutput.tetrahedronvolumelist != NULL) {
            for(Standard_Integer i = 0; i < anOutput.numberoftetrahedra; i++) {
                Standard_Real aVolume = anOutput.tetrahedronvolumelist[i];
                myOutputModel->SetTetrahedronMaxVolume(i+1, aVolume);
            }
        }

        // process triangles
        if(anOutput.numberoftrifaces > 0) {
            myOutputModel->ResizeTriangles(anOutput.numberoftrifaces);
            for(Standard_Integer i = 0; i < anOutput.numberoftrifaces; i++) {
                Standard_Integer aPoint1 = anOutput.trifacelist[3 * i + 0] + 1;
                Standard_Integer aPoint2 = anOutput.trifacelist[3 * i + 1] + 1;
                Standard_Integer aPoint3 = anOutput.trifacelist[3 * i + 2] + 1;
                myOutputModel->SetTriangle(i+1, aPoint1, aPoint2, aPoint3);

                Standard_Integer aMarker = anOutput.trifacemarkerlist[i];
                myOutputModel->SetTriangleMarker(i+1, aMarker);
            }
        }

    } catch(const std::exception& e) {
        myError = Tetgen_OutputModelError;
        return;
    }

    // free input memory
    //free(anInput.edgelist);
    //free(anInput.edgemarkerlist);
    //free(anInput.facetmarkerlist);
    //free(anInput.holelist);
    //free(anInput.pointattributelist);
    //free(anInput.pointlist);
    //free(anInput.regionlist);
    //free(anInput.segmentconstraintlist);
    //free(anInput.tetrahedronlist);
    //free(anInput.tetrahedronattributelist);
    //free(anInput.neighborlist);
    //free(anInput.tetrahedronvolumelist);
    //free(anInput.trifacelist);
    //free(anInput.trifacemarkerlist);
    
    // free output memory
    //free(anOutput.edgelist);
    //free(anOutput.facetlist);
    //free(anOutput.facetmarkerlist);
    //free(anOutput.holelist);
    //free(anOutput.pointattributelist);
    //free(anOutput.pointlist);
    //free(anOutput.regionlist);
    //free(anOutput.segmentconstraintlist);
    //free(anOutput.tetrahedronlist);
    //free(anOutput.tetrahedronattributelist);
    //free(anOutput.neighborlist);
    //free(anOutput.tetrahedronvolumelist);
    //free(anOutput.trifacelist);
    //free(anOutput.trifacemarkerlist);

    // update internal state
    myError = Tetgen_NoError;
    myIsDone = Standard_True;
}

// ============================================================================
/*!
    \brief SetInputModel()
*/
// ============================================================================
void Tetgen_Tetrahedralize::SetInputModel(const Handle(Tetgen_Model)& theInputModel)
{
    myInputModel = theInputModel;
}

// ============================================================================
/*!
    \brief SetParameters()
*/
// ============================================================================
void Tetgen_Tetrahedralize::SetParameters(const Tetgen_Parameters& theParameters)
{
    myParameters = theParameters;
}

