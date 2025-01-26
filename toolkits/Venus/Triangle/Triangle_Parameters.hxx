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


#ifndef __Triangle_Parameters_hxx__
#define __Triangle_Parameters_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>

// Spartacus
#include <Triangle_TypeOfAlgorithm.hxx>


// ============================================================================
/*
    \brief Triangle_Parameters
*/
// ============================================================================
class Triangle_Parameters 
{

public:
    // constructors
    Standard_EXPORT Triangle_Parameters();
    // destructors
    Standard_EXPORT ~Triangle_Parameters();

public:

    Standard_EXPORT Triangle_TypeOfAlgorithm    Algorithm() const {return myAlgorithm;}
    Standard_EXPORT Standard_Boolean            CheckConformity() const {return myCheckConformity;}
    Standard_EXPORT Standard_Boolean            ConformingDelaunay() const {return myConformingDelaunay;}
    Standard_EXPORT Standard_Boolean            EncloseConvexHull() const {return myEncloseConvexHull;}
    Standard_EXPORT Standard_Boolean            ExactArithmetic() const {return myExactArithmetic;}
    Standard_EXPORT Standard_Boolean            GenerateSecondOrder() const {return myGenerateSecondOrder;}
    Standard_EXPORT Standard_Boolean            HasMaxArea() const {return (myMaxArea > 0.0);}
    Standard_EXPORT Standard_Boolean            IgnoreHoles() const {return myIgnoreHoles;}
    Standard_EXPORT Standard_Boolean            IsQuiet() const {return myIsQuiet;}
    Standard_EXPORT Standard_Boolean            IsVerbose() const {return myIsVerbose;}
    Standard_EXPORT Standard_Real               MaxArea() const {return myMaxArea;}
    Standard_EXPORT Standard_Boolean            MeshPSLG() const {return myMeshPSLG;}
    Standard_EXPORT Standard_Boolean            QualityMesh() const {return myQualityMesh;}
    Standard_EXPORT Standard_Boolean            RefineMesh() const {return myRefineMesh;}
    
    Standard_EXPORT void                        SetAlgorithm(const Triangle_TypeOfAlgorithm theAlgorithm) {myAlgorithm = theAlgorithm;}
    Standard_EXPORT void                        SetCheckConformity(const Standard_Boolean theCheckConformity) {myCheckConformity = theCheckConformity;}
    Standard_EXPORT void                        SetConformingDelaunay(const Standard_Boolean theConformingDelaunay) {myConformingDelaunay = theConformingDelaunay;}
    Standard_EXPORT void                        SetEncloseConvexHull(const Standard_Boolean theIsEncloseConvexHull) {myEncloseConvexHull = theIsEncloseConvexHull;}
    Standard_EXPORT void                        SetExactArithmetic(const Standard_Boolean theIsExactArithmetic) {myExactArithmetic = theIsExactArithmetic;}
    Standard_EXPORT void                        SetGenerateSecondOrder(const Standard_Boolean theIsGenerateSecondOrder) {myGenerateSecondOrder = theIsGenerateSecondOrder;}
    Standard_EXPORT void                        SetIgnoreHoles(const Standard_Boolean theIsIgnoreHoles) {myIgnoreHoles = theIsIgnoreHoles;}
    Standard_EXPORT void                        SetMaxArea(const Standard_Real theMaxArea) {myMaxArea = theMaxArea;}
    Standard_EXPORT void                        SetMeshPSLG(const Standard_Boolean theMeshPSLG) {myMeshPSLG = theMeshPSLG;}
    Standard_EXPORT void                        SetQualityMesh(const Standard_Boolean theQualityMesh) {myQualityMesh = theQualityMesh;}
    Standard_EXPORT void                        SetQuiet(const Standard_Boolean theIsQuiet) {myIsQuiet = theIsQuiet;}
    Standard_EXPORT void                        SetRefineMesh(const Standard_Boolean theRefineMesh) {myRefineMesh = theRefineMesh;}
    Standard_EXPORT void                        SetVerbose(const Standard_Boolean theIsVerbose) {myIsVerbose = theIsVerbose;}

public:

    Triangle_TypeOfAlgorithm    myAlgorithm;
    Standard_Boolean            myCheckConformity;
    Standard_Boolean            myConformingDelaunay;
    Standard_Boolean            myEncloseConvexHull;
    Standard_Boolean            myExactArithmetic;
    Standard_Boolean            myGenerateSecondOrder;
    Standard_Boolean            myIgnoreHoles;
    Standard_Boolean            myIsQuiet;
    Standard_Boolean            myIsVerbose;
    Standard_Boolean            myMeshPSLG;
    Standard_Boolean            myQualityMesh;
    Standard_Boolean            myRefineMesh;
    Standard_Real               myMaxArea;   

};


#endif // __Triangle_Parameters_hxx__
