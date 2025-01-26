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
#include <MeshDS_Object.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
MeshDS_Object::MeshDS_Object()
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
MeshDS_Object::~MeshDS_Object()
{

}

// ============================================================================
/*!
 *  \brief IsEqual()
*/
// ============================================================================
Standard_Boolean MeshDS_Object::IsEqual(const MeshDS_Object &theOther) const
{
    return (myTObject == theOther.TObject());
}

// ============================================================================
/*!
 *  \brief IsNull()
*/
// ============================================================================
Standard_Boolean MeshDS_Object::IsNull() const
{
    return myTObject.IsNull();
}

// ============================================================================
/*!
 *  \brief ObjectType()
*/
// ============================================================================
MeshAbs_TypeOfObject MeshDS_Object::ObjectType() const
{
    return myTObject->ObjectType();
}

// ============================================================================
/*!
 *  \brief SetTObject()
*/
// ============================================================================
void MeshDS_Object::SetTObject(const Handle(MeshDS_TObject) &theTObject)
{
    myTObject = theTObject;
}

// ============================================================================
/*!
 *  \brief TObject()
*/
// ============================================================================
const Handle(MeshDS_TObject)& MeshDS_Object::TObject() const
{
    return myTObject;
}
