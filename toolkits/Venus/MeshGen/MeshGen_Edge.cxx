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
#include <MeshGen_Edge.hxx>

// OpenCASCADE
#include <TopoDS.hxx>


// ============================================================================
/*!
 *  \brief Constructor()
*/
// ============================================================================
MeshGen_Edge::MeshGen_Edge(const TopoDS_Edge& theEdge)
    : MeshGen_Shape(theEdge)
{

}

// ============================================================================
/*!
 *  \brief Destructor()
*/
// ============================================================================
MeshGen_Edge::~MeshGen_Edge()
{

}

// ============================================================================
/*!
 *  \brief Edge()
*/
// ============================================================================
const TopoDS_Edge& MeshGen_Edge::Edge() const
{
    return TopoDS::Edge(Shape());
}

// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshGen_Edge, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(MeshGen_Edge, Standard_Transient)