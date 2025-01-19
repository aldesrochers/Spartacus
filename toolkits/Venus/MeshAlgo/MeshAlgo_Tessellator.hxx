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


#ifndef __MeshAlgo_Tessellator_hxx__
#define __MeshAlgo_Tessellator_hxx__

// Spartacus
#include <MeshAlgo_Algorithm.hxx>

// Handles
DEFINE_STANDARD_HANDLE(MeshAlgo_Tessellator, MeshAlgo_Algorithm)


// ============================================================================
/*
    \brief MeshAlgo_Tessellator
*/
// ============================================================================
class MeshAlgo_Tessellator : public MeshAlgo_Algorithm
{
    
public:
    // constructors
    Standard_EXPORT MeshAlgo_Tessellator();
    // destructors
    Standard_EXPORT ~MeshAlgo_Tessellator();

public:

    DEFINE_STANDARD_RTTIEXT(MeshAlgo_Tessellator, MeshAlgo_Algorithm)

};

#endif // __MeshAlgo_Tessellator_hxx__
