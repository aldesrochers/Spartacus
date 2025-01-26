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
#include <Tetgen_Parameters.hxx>



// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Tetgen_Parameters::Tetgen_Parameters()    
{
    myCheckConformity = Standard_False;
    myDetectSelfIntersections = Standard_False;
    myExactArithmetic = Standard_True;
    myGenerateSecondOrder = Standard_False;
    myIsQuiet = Standard_True;
    myIsVerbose = Standard_True;
    myMaxVolume = 0.0;
    myMergeCoplanarFacets = Standard_False;
    myMeshCoarsening = Standard_False;
    myMeshOptimization = 2;
    myMeshPLC = Standard_True;
    myPreserveInputMesh = Standard_False;
    myQualityMesh = Standard_True;
    myRefineMesh = Standard_False;
    myRetainsConvexHull = Standard_False;
    myTolerance = 10^-6;
    myWeightedDelaunay = Standard_False;
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Tetgen_Parameters::~Tetgen_Parameters()    
{
    
}

