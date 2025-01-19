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
#include <Cell_Face.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Cell_Face::Cell_Face()    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Cell_Face::~Cell_Face()    
{
    
}

// ============================================================================
/*!
    \brief NbNodes()
*/
// ============================================================================
Standard_Integer Cell_Face::NbNodes() const   
{
    return myNodes.Size();
}

// ============================================================================
/*!
    \brief Node()
*/
// ============================================================================
Standard_Integer Cell_Face::Node(const Standard_Integer theIndex) const   
{
    return myNodes.Value(theIndex);
}

// ============================================================================
/*!
    \brief Polygon()
*/
// ============================================================================
const Handle(Cell_Polygon)& Cell_Face::Polygon() const   
{
    return myPolygon;
}

// ============================================================================
/*!
    \brief ResizeNodes()
*/
// ============================================================================
void Cell_Face::ResizeNodes(const Standard_Integer theNbNodes,
                            const Standard_Boolean toCopyData) 
{
    myNodes.Resize(1, theNbNodes, toCopyData);
}

// ============================================================================
/*!
    \brief SetNode()
*/
// ============================================================================
void Cell_Face::SetNode(const Standard_Integer theIndex,
                        const Standard_Integer theNode) 
{
    myNodes.SetValue(theIndex, theNode);
}

// ============================================================================
/*!
    \brief SetPolygon()
*/
// ============================================================================
void Cell_Face::SetPolygon(const Handle(Cell_Polygon)& thePolygon) 
{
    myPolygon = thePolygon;
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Cell_Face, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(Cell_Face, Standard_Transient)