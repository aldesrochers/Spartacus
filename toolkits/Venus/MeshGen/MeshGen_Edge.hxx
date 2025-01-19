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


#ifndef __MeshGen_Edge_hxx__
#define __MeshGen_Edge_hxx__

// Spartacus
#include <MeshGen_Shape.hxx>

// OpenCASCADE
#include <TopoDS_Edge.hxx>

// Handles
DEFINE_STANDARD_HANDLE(MeshGen_Edge, MeshGen_Shape)


// ============================================================================
/*
    \brief MeshGen_Edge
*/
// ============================================================================
class MeshGen_Edge : public MeshGen_Shape
{
    
public:
    // constructors
    Standard_EXPORT MeshGen_Edge(const TopoDS_Edge& theEdge);
    // destructors
    Standard_EXPORT ~MeshGen_Edge();

public:

    Standard_EXPORT const TopoDS_Edge&  Edge() const;

public:

    DEFINE_STANDARD_RTTIEXT(MeshGen_Edge, MeshGen_Shape)

};

#endif // __MeshGen_Edge_hxx__
