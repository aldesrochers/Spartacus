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


#ifndef __MeshModel_Face_hxx__
#define __MeshModel_Face_hxx__

// Spartacus
#include <MeshModel_Shape.hxx>

// OpenCASCADE
#include <TopoDS_Face.hxx>

// Handles
DEFINE_STANDARD_HANDLE(MeshModel_Face, MeshModel_Shape)


// ============================================================================
/*
    \brief MeshModel_Face
*/
// ============================================================================
class MeshModel_Face : public MeshModel_Shape
{
    
public:
    // constructors
    Standard_EXPORT MeshModel_Face(const TopoDS_Face& theFace);
    // destructors
    Standard_EXPORT ~MeshModel_Face();

public:

    Standard_EXPORT const TopoDS_Face&       Face() const;

public:

    DEFINE_STANDARD_RTTIEXT(MeshModel_Face, MeshModel_Shape)

};

#endif // __MeshModel_Face_hxx__
