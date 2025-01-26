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
#include <MeshModel_Edge.hxx>

// OpenCASCADE
#include <TopoDS.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshModel_Edge::MeshModel_Edge(const TopoDS_Edge& theEdge)
    : MeshModel_Shape(theEdge)    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MeshModel_Edge::~MeshModel_Edge()    
{
    
}

// ============================================================================
/*!
    \brief Curve()
*/
// ============================================================================
const Handle(MeshModel_Curve)& MeshModel_Edge::Curve() const
{
    return myCurve;
}

// ============================================================================
/*!
    \brief Edge()
*/
// ============================================================================
const TopoDS_Edge& MeshModel_Edge::Edge() const
{
    return TopoDS::Edge(Shape());
}

// ============================================================================
/*!
    \brief SetCurve()
*/
// ============================================================================
void MeshModel_Edge::SetCurve(const Handle(MeshModel_Curve)& theCurve)
{
    myCurve = theCurve;
}

// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshModel_Edge, MeshModel_Shape)
IMPLEMENT_STANDARD_RTTIEXT(MeshModel_Edge, MeshModel_Shape)