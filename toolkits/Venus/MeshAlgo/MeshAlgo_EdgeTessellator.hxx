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


#ifndef __MeshAlgo_EdgeTessellator_hxx__
#define __MeshAlgo_EdgeTessellator_hxx__

// Spartacus
#include <MeshAlgo_Tessellator.hxx>
#include <MeshModel_Edge.hxx>

// Handles
DEFINE_STANDARD_HANDLE(MeshAlgo_EdgeTessellator, MeshAlgo_Tessellator)


// ============================================================================
/*
    \brief MeshAlgo_EdgeTessellator
*/
// ============================================================================
class MeshAlgo_EdgeTessellator : public MeshAlgo_Tessellator
{
    
public:
    // constructors
    Standard_EXPORT MeshAlgo_EdgeTessellator();
    Standard_EXPORT MeshAlgo_EdgeTessellator(const Handle(MeshModel_Edge)& theEdge);
    // destructors
    Standard_EXPORT ~MeshAlgo_EdgeTessellator();

public:

    Standard_EXPORT const Handle(MeshModel_Edge)&   Edge() const;
    Standard_EXPORT void                            SetEdge(const Handle(MeshModel_Edge)& theEdge);

protected:

    Handle(MeshModel_Edge)     myEdge;

public:

    DEFINE_STANDARD_RTTIEXT(MeshAlgo_EdgeTessellator, MeshAlgo_Tessellator)

};

#endif // __MeshAlgo_EdgeTessellator_hxx__
