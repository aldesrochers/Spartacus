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


#ifndef __MeshGen_MeshBuilder_hxx__
#define __MeshGen_MeshBuilder_hxx__

// OpenCASCADE
#include <Message_Algorithm.hxx>

// Handles
DEFINE_STANDARD_HANDLE(MeshGen_MeshBuilder, Message_Algorithm)


// ============================================================================
/*
    \brief MeshGen_MeshBuilder
*/
// ============================================================================
class MeshGen_MeshBuilder : public Message_Algorithm
{
    
public:
    // constructors
    Standard_EXPORT MeshGen_MeshBuilder();
    // destructors
    Standard_EXPORT ~MeshGen_MeshBuilder();

public:

    DEFINE_STANDARD_RTTIEXT(MeshGen_MeshBuilder, Message_Algorithm)

};

#endif // __MeshGen_MeshBuilder_hxx__
