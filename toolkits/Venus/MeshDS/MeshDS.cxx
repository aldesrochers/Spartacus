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
#include <MeshDS.hxx>

// OpenCascade
#include <Standard_TypeMismatch.hxx>



// ============================================================================
/*!
 *  \brief TypeMismatch()
*/
// ============================================================================
Standard_Boolean MeshDS::TypeMismatch(const MeshDS_Object &theObject,
                                      const MeshAbs_TypeOfObject theObjectType)
{
    return theObject.IsNull() ? Standard_False : theObject.ObjectType() != theObjectType;
}

// ============================================================================
/*!
 *  \brief Cell()
*/
// ============================================================================
const MeshDS_Cell& MeshDS::Cell(const MeshDS_Object& theObject)
{
    Standard_TypeMismatch_Raise_if(MeshDS::TypeMismatch(theObject, MeshAbs_OBJ_Cell),
                                   "MeshDS::Cell()->Type mismatch.");
    return *(MeshDS_Cell*) &theObject;
}

// ============================================================================
/*!
 *  \brief Cell()
*/
// ============================================================================
MeshDS_Cell& MeshDS::Cell(MeshDS_Object& theObject)
{
    Standard_TypeMismatch_Raise_if(MeshDS::TypeMismatch(theObject, MeshAbs_OBJ_Cell),
                                   "MeshDS::Cell()->Type mismatch.");
    return *(MeshDS_Cell*) &theObject;
}

// ============================================================================
/*!
 *  \brief Group()
*/
// ============================================================================
const MeshDS_Group& MeshDS::Group(const MeshDS_Object& theObject)
{
    Standard_TypeMismatch_Raise_if(MeshDS::TypeMismatch(theObject, MeshAbs_OBJ_Group),
                                   "MeshDS::Group()->Type mismatch.");
    return *(MeshDS_Group*) &theObject;
}

// ============================================================================
/*!
 *  \brief Group()
*/
// ============================================================================
MeshDS_Group& MeshDS::Group(MeshDS_Object& theObject)
{
    Standard_TypeMismatch_Raise_if(MeshDS::TypeMismatch(theObject, MeshAbs_OBJ_Group),
                                   "MeshDS::Group()->Type mismatch.");
    return *(MeshDS_Group*) &theObject;
}

// ============================================================================
/*!
 *  \brief Mesh()
*/
// ============================================================================
const MeshDS_Mesh& MeshDS::Mesh(const MeshDS_Object& theObject)
{
    Standard_TypeMismatch_Raise_if(MeshDS::TypeMismatch(theObject, MeshAbs_OBJ_Mesh),
                                   "MeshDS::Mesh()->Type mismatch.");
    return *(MeshDS_Mesh*) &theObject;
}

// ============================================================================
/*!
 *  \brief Mesh()
*/
// ============================================================================
MeshDS_Mesh& MeshDS::Mesh(MeshDS_Object& theObject)
{
    Standard_TypeMismatch_Raise_if(MeshDS::TypeMismatch(theObject, MeshAbs_OBJ_Mesh),
                                   "MeshDS::Mesh()->Type mismatch.");
    return *(MeshDS_Mesh*) &theObject;
}

// ============================================================================
/*!
 *  \brief Vertex()
*/
// ============================================================================
const MeshDS_Vertex& MeshDS::Vertex(const MeshDS_Object& theObject)
{
    Standard_TypeMismatch_Raise_if(MeshDS::TypeMismatch(theObject, MeshAbs_OBJ_Vertex),
                                   "MeshDS::Vertex()->Type mismatch.");
    return *(MeshDS_Vertex*) &theObject;
}

// ============================================================================
/*!
 *  \brief Vertex()
*/
// ============================================================================
MeshDS_Vertex& MeshDS::Vertex(MeshDS_Object& theObject)
{
    Standard_TypeMismatch_Raise_if(MeshDS::TypeMismatch(theObject, MeshAbs_OBJ_Vertex),
                                   "MeshDS::Vertex()->Type mismatch.");
    return *(MeshDS_Vertex*) &theObject;
}

