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


#ifndef __MeshDS_hxx__
#define __MeshDS_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>

// Spartacus
#include <MeshAbs_TypeOfObject.hxx>
#include <MeshDS_Cell.hxx>
#include <MeshDS_Group.hxx>
#include <MeshDS_Mesh.hxx>
#include <MeshDS_Object.hxx>
#include <MeshDS_Vertex.hxx>


// ============================================================================
/*!
 *  \brief MeshDS
*/
// ============================================================================
class MeshDS
{

public:

    DEFINE_STANDARD_ALLOC

public:

    static Standard_EXPORT const MeshDS_Cell&       Cell(const MeshDS_Object& theObject);
    static Standard_EXPORT MeshDS_Cell&             Cell(MeshDS_Object& theObject);

    static Standard_EXPORT const MeshDS_Group&      Group(const MeshDS_Object& theObject);
    static Standard_EXPORT MeshDS_Group&            Group(MeshDS_Object& theObject);

    static Standard_EXPORT const MeshDS_Mesh&       Mesh(const MeshDS_Object& theObject);
    static Standard_EXPORT MeshDS_Mesh&             Mesh(MeshDS_Object& theObject);

    static Standard_EXPORT const MeshDS_Vertex&     Vertex(const MeshDS_Object& theObject);
    static Standard_EXPORT MeshDS_Vertex&           Vertex(MeshDS_Object& theObject);


protected:

    static Standard_EXPORT Standard_Boolean     TypeMismatch(const MeshDS_Object& theObject,
                                                             const MeshAbs_TypeOfObject theObjectType);

};


#endif // __MeshDS_hxx__
