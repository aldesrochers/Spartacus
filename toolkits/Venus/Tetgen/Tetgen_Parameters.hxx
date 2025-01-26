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


#ifndef __Tetgen_Parameters_hxx__
#define __Tetgen_Parameters_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>


// ============================================================================
/*
    \brief Tetgen_Parameters
*/
// ============================================================================
class Tetgen_Parameters
{

public:

    DEFINE_STANDARD_ALLOC;
    
public:
    // constructors
    Standard_EXPORT Tetgen_Parameters();
    // destructors
    Standard_EXPORT ~Tetgen_Parameters();

public:

    Standard_EXPORT Standard_Boolean    CheckConformity() const {return myCheckConformity;}
    Standard_EXPORT Standard_Boolean    DetectSelfIntersections() const {return myDetectSelfIntersections;}
    Standard_EXPORT Standard_Boolean    ExactArithmetic() const {return myExactArithmetic;}
    Standard_EXPORT Standard_Boolean    GenerateSecondOrder() const {return myGenerateSecondOrder;}
    Standard_EXPORT Standard_Boolean    IsQuiet() const {return myIsQuiet;}
    Standard_EXPORT Standard_Boolean    IsVerbose() const {return myIsVerbose;}
    Standard_EXPORT Standard_Real       MaxVolume() const {return myMaxVolume;}
    Standard_EXPORT Standard_Boolean    MergeCoplanarFacets() const {return myMergeCoplanarFacets;}
    Standard_EXPORT Standard_Boolean    MeshCoarsening() const {return myMeshCoarsening;}
    Standard_EXPORT Standard_Integer    MeshOptimization() const {return myMeshOptimization;}
    Standard_EXPORT Standard_Boolean    MeshPLC() const {return myMeshPLC;}
    Standard_EXPORT Standard_Boolean    PreservesInputMesh() const {return myPreserveInputMesh;}
    Standard_EXPORT Standard_Boolean    QualityMesh() const {return myQualityMesh;}
    Standard_EXPORT Standard_Boolean    RefineMesh() const {return myRefineMesh;}
    Standard_EXPORT Standard_Boolean    RetainsConvexHull() const {return myRetainsConvexHull;}
    Standard_EXPORT Standard_Real       Tolerance() const {return myTolerance;}
    Standard_EXPORT Standard_Boolean    WeightedDelaunay() const {return myWeightedDelaunay;}

    Standard_EXPORT void                SetCheckConformity(const Standard_Boolean theCheckConformity) {myCheckConformity = theCheckConformity;}
    Standard_EXPORT void                SetDetectSelfIntersections(const Standard_Boolean theDetectSelfIntersections) {myDetectSelfIntersections = theDetectSelfIntersections;}
    Standard_EXPORT void                SetExactArithmetic(const Standard_Boolean theExactArithmetic) {myExactArithmetic = theExactArithmetic;}
    Standard_EXPORT void                SetGenerateSecondOrder(const Standard_Boolean theGenerateSecondOrder) {myGenerateSecondOrder = theGenerateSecondOrder;}
    Standard_EXPORT void                SetIsQuiet(const Standard_Boolean theIsQuiet) {myIsQuiet = theIsQuiet;}
    Standard_EXPORT void                SetIsVerbose(const Standard_Boolean theIsVerbose) {myIsVerbose = theIsVerbose;}
    Standard_EXPORT void                SetMaxVolume(const Standard_Real theMaxVolume) {myMaxVolume = theMaxVolume;}
    Standard_EXPORT void                SetMergeCoplanarFacets(const Standard_Boolean theMergeCoplanarFacets) {myMergeCoplanarFacets = theMergeCoplanarFacets;}
    Standard_EXPORT void                SetMeshCoarsening(const Standard_Boolean theMeshCoarsening) {myMeshCoarsening = theMeshCoarsening;}
    Standard_EXPORT void                SetMeshOptimization(const Standard_Integer theMeshOptimization) {myMeshOptimization = theMeshOptimization;}
    Standard_EXPORT void                SetMeshPLC(const Standard_Boolean theMeshPLC) {myMeshPLC = theMeshPLC;}
    Standard_EXPORT void                SetPreservesInputMesh(const Standard_Boolean thePreservesInputMesh) {myPreserveInputMesh = thePreservesInputMesh;}
    Standard_EXPORT void                SetQualityMesh(const Standard_Boolean theQualityMesh) {myQualityMesh = theQualityMesh;}
    Standard_EXPORT void                SetRefineMesh(const Standard_Boolean theRefineMesh) {myRefineMesh = theRefineMesh;}
    Standard_EXPORT void                SetRetainsConvexHull(const Standard_Boolean theRetainsConvexHull) {myRetainsConvexHull = theRetainsConvexHull;}
    Standard_EXPORT void                SetTolerance(const Standard_Real theTolerance) {myTolerance = theTolerance;}
    Standard_EXPORT void                SetWeightedDelaunay(const Standard_Boolean theWeightedDelaunay) {myWeightedDelaunay = theWeightedDelaunay;}

private:

    Standard_Boolean    myCheckConformity;
    Standard_Boolean    myDetectSelfIntersections;
    Standard_Boolean    myExactArithmetic;
    Standard_Boolean    myGenerateSecondOrder;
    Standard_Boolean    myIsQuiet;
    Standard_Boolean    myIsVerbose;
    Standard_Real       myMaxVolume;
    Standard_Boolean    myMergeCoplanarFacets;
    Standard_Boolean    myMeshCoarsening;
    Standard_Integer    myMeshOptimization;
    Standard_Boolean    myMeshPLC;
    Standard_Boolean    myPreserveInputMesh;
    Standard_Boolean    myQualityMesh;
    Standard_Boolean    myRefineMesh;
    Standard_Boolean    myRetainsConvexHull;
    Standard_Real       myTolerance;
    Standard_Boolean    myWeightedDelaunay;

};

#endif // __Tetgen_Parameters_hxx__
