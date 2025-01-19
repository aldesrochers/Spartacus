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


#ifndef __MeshGen_CurveTessellator_hxx__
#define __MeshGen_CurveTessellator_hxx__

// Spartacus
#include <MeshGen_Algorithm.hxx>
#include <MeshGen_Edge.hxx>

// Handles
DEFINE_STANDARD_HANDLE(MeshGen_CurveTessellator, MeshGen_Algorithm)


// ============================================================================
/*
    \brief MeshGen_CurveTessellator
*/
// ============================================================================
class MeshGen_CurveTessellator : public MeshGen_Algorithm
{
    
public:
    // constructors
    Standard_EXPORT MeshGen_CurveTessellator();
    // destructors
    Standard_EXPORT ~MeshGen_CurveTessellator();

public:
    
    Standard_EXPORT const Handle(MeshGen_Edge)&     Edge() const;
    Standard_EXPORT void                            SetEdge(const Handle(MeshGen_Edge)& theEdge);

private:

    Handle(MeshGen_Edge)    myEdge;

public:

    DEFINE_STANDARD_RTTIEXT(MeshGen_CurveTessellator, MeshGen_Algorithm)

};

#endif // __MeshGen_CurveTessellator_hxx__
