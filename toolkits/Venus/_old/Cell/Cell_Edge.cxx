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
#include <Cell_Edge.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Cell_Edge::Cell_Edge()    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Cell_Edge::~Cell_Edge()    
{
    
}

// ============================================================================
/*!
    \brief NbNodes()
*/
// ============================================================================
Standard_Integer Cell_Edge::NbNodes() const   
{
    return myNodes.Size();
}

// ============================================================================
/*!
    \brief Node()
*/
// ============================================================================
Standard_Integer Cell_Edge::Node(const Standard_Integer theIndex) const   
{
    return myNodes.Value(theIndex);
}

// ============================================================================
/*!
    \brief ResizeNodes()
*/
// ============================================================================
void Cell_Edge::ResizeNodes(const Standard_Integer theNbNodes,
                            const Standard_Boolean toCopyData) 
{
    myNodes.Resize(1, theNbNodes, toCopyData);
}

// ============================================================================
/*!
    \brief SetNode()
*/
// ============================================================================
void Cell_Edge::SetNode(const Standard_Integer theIndex,
                        const Standard_Integer theNode) 
{
    myNodes.SetValue(theIndex, theNode);
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Cell_Edge, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(Cell_Edge, Standard_Transient)