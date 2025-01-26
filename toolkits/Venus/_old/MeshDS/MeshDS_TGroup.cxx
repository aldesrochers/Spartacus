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
#include <MeshDS_TGroup.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshDS_TGroup::MeshDS_TGroup()    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MeshDS_TGroup::~MeshDS_TGroup()    
{
    
}

// ============================================================================
/*!
    \brief ObjectType()
*/
// ============================================================================
MeshAbs_TypeOfObject MeshDS_TGroup::ObjectType() const
{
    return MeshAbs_OBJ_Group;
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshDS_TGroup, MeshDS_TObject)
IMPLEMENT_STANDARD_RTTIEXT(MeshDS_TGroup, MeshDS_TObject)