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
#include <MeshModel_Face.hxx>

// OpenCASCADE
#include <TopoDS.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshModel_Face::MeshModel_Face(const TopoDS_Face& theFace)
    : MeshModel_Shape(theFace)    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MeshModel_Face::~MeshModel_Face()    
{
    
}

// ============================================================================
/*!
    \brief Face()
*/
// ============================================================================
const TopoDS_Face& MeshModel_Face::Face() const
{
    return TopoDS::Face(Shape());
}



// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshModel_Face, MeshModel_Shape)
IMPLEMENT_STANDARD_RTTIEXT(MeshModel_Face, MeshModel_Shape)