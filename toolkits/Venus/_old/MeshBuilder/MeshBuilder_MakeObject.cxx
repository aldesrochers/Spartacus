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
#include <MeshBuilder_MakeObject.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
MeshBuilder_MakeObject::MeshBuilder_MakeObject()
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
MeshBuilder_MakeObject::~MeshBuilder_MakeObject()
{

}

// ============================================================================
/*!
 *  \brief Build()
*/
// ============================================================================
void MeshBuilder_MakeObject::Build()
{

}

// ============================================================================
/*!
 *  \brief Object()
*/
// ============================================================================
const MeshDS_Object& MeshBuilder_MakeObject::Object()
{
    if (!IsDone()) {
        ((MeshBuilder_MakeObject*) (void*) this)->Build();
        Check();
    }
    return myObject;
}

// ============================================================================
/*!
 *  \brief operator ObjectDS_Object()
*/
// ============================================================================
MeshBuilder_MakeObject::operator MeshDS_Object()
{
    return Object();
}
