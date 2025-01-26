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
#include <MeshTools_ObjectMapHasher.hxx>


// ============================================================================
/*!
 *  \brief operator()
*/
// ============================================================================
size_t MeshTools_ObjectMapHasher::operator()(const MeshDS_Object& theObject) const noexcept
{
    return opencascade::hash(theObject.TObject().get());
}

// ============================================================================
/*!
 *  \brief operator()
*/
// ============================================================================
bool MeshTools_ObjectMapHasher::operator()(const MeshDS_Object& theObject1, 
                                           const MeshDS_Object& theObject2) const noexcept
{
    return theObject1.IsEqual(theObject2);
}