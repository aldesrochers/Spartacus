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


#ifndef __MeshDS_TMesh_hxx__
#define __MeshDS_TMesh_hxx__

// Spartacus
#include <MeshDS_TObject.hxx>

// Handles
DEFINE_STANDARD_HANDLE(MeshDS_TMesh, MeshDS_TObject)


// ============================================================================
/*
    \brief MeshDS_TMesh
*/
// ============================================================================
class MeshDS_TMesh : public MeshDS_TObject
{
    
public:
    // constructors
    Standard_EXPORT MeshDS_TMesh();
    // destructors
    Standard_EXPORT ~MeshDS_TMesh();

public:

    Standard_EXPORT MeshAbs_TypeOfObject   ObjectType() const Standard_OVERRIDE;

public:

    DEFINE_STANDARD_RTTIEXT(MeshDS_TMesh, MeshDS_TObject)

};

#endif // __MeshDS_TMesh_hxx__
