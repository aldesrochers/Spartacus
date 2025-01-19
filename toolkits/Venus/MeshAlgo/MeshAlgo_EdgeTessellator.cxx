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
#include <MeshAlgo_EdgeTessellator.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshAlgo_EdgeTessellator::MeshAlgo_EdgeTessellator()    
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshAlgo_EdgeTessellator::MeshAlgo_EdgeTessellator(const Handle(MeshModel_Edge)& theEdge)
    : myEdge(theEdge)    
{
    
}


// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MeshAlgo_EdgeTessellator::~MeshAlgo_EdgeTessellator()    
{
    
}

// ============================================================================
/*!
    \brief Edge()
*/
// ===========================================================================
const Handle(MeshModel_Edge)& MeshAlgo_EdgeTessellator::Edge() const
{
    return myEdge;
}

// ============================================================================
/*!
    \brief SetEdge()
*/
// ===========================================================================
void MeshAlgo_EdgeTessellator::SetEdge(const Handle(MeshModel_Edge)& theEdge)
{
    myEdge = theEdge;
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshAlgo_EdgeTessellator, MeshAlgo_Tessellator)
IMPLEMENT_STANDARD_RTTIEXT(MeshAlgo_EdgeTessellator, MeshAlgo_Tessellator)