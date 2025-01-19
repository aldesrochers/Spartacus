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
#include <MeshAlgo_UniformAbscissaTessellator.hxx>
#include <MeshModel_Curve.hxx>

// OpenCASCADE
#include <BRepAdaptor_Curve.hxx>
#include <GCPnts_UniformAbscissa.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshAlgo_UniformAbscissaTessellator::MeshAlgo_UniformAbscissaTessellator()   
    : myNbPoints(10)
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshAlgo_UniformAbscissaTessellator::MeshAlgo_UniformAbscissaTessellator(const Handle(MeshModel_Edge)& theEdge)
    : MeshAlgo_EdgeTessellator(theEdge),
    myNbPoints(10)
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MeshAlgo_UniformAbscissaTessellator::~MeshAlgo_UniformAbscissaTessellator()    
{
    
}

// ============================================================================
/*!
    \brief Perform()
*/
// ============================================================================
void MeshAlgo_UniformAbscissaTessellator::Perform() 
{
    #include <iostream>
    using namespace std;

    const TopoDS_Edge& anEdge = myEdge->Edge();
    BRepAdaptor_Curve anAdaptor(anEdge);

    Standard_Real U1 = anAdaptor.FirstParameter();
    Standard_Real U2 = anAdaptor.LastParameter();

    GCPnts_UniformAbscissa aMesher(anAdaptor, myNbPoints, U1, U2);
    if(!aMesher.IsDone())
        return;    

    Handle(MeshModel_Curve) aCurve = new MeshModel_Curve();

    for(Standard_Integer i=1; i<=myNbPoints; i++) {
        Standard_Real U = aMesher.Parameter(i);
        gp_Pnt aPnt = anAdaptor.Value(U);
        aCurve->AddPoint(aPnt, U);
    }

    myEdge->SetCurve(aCurve);
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshAlgo_UniformAbscissaTessellator, MeshAlgo_EdgeTessellator)
IMPLEMENT_STANDARD_RTTIEXT(MeshAlgo_UniformAbscissaTessellator, MeshAlgo_EdgeTessellator)