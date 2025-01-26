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


#ifndef __MeshModel_Model_hxx__
#define __MeshModel_Model_hxx__

// Spartacus
#include <MeshModel_DiscreteShape.hxx>

// Handles
DEFINE_STANDARD_HANDLE(MeshModel_Model, MeshModel_DiscreteShape)

// ============================================================================
/*
    \brief MeshModel_Model
*/
// ============================================================================
class MeshModel_Model : public MeshModel_DiscreteShape
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Standard_EXPORT MeshModel_Model();
    // destructors
    Standard_EXPORT ~MeshModel_Model();

public:

    DEFINE_STANDARD_RTTIEXT(MeshModel_Model, MeshModel_DiscreteShape)

};

#endif // __MeshModel_Model_hxx__
