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
#include <Mesh2d_Grid.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mesh2d_Grid::Mesh2d_Grid()    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Mesh2d_Grid::~Mesh2d_Grid()    
{
    
}

// ============================================================================
/*!
    \brief Cell()
*/
// ============================================================================
const Handle(Mesh2d_Cell)& Mesh2d_Grid::Cell(const Standard_Integer theIndex) const 
{
    return myCells(theIndex);
}

// ============================================================================
/*!
    \brief NbCells()
*/
// ============================================================================
Standard_Integer Mesh2d_Grid::NbCells() const 
{
    return myCells.Size();
}

// ============================================================================
/*!
    \brief NbNodes()
*/
// ============================================================================
Standard_Integer Mesh2d_Grid::NbNodes() const   
{
    return myNodes.Size();
}

// ============================================================================
/*!
    \brief Node()
*/
// ============================================================================
const Handle(Mesh2d_Node)& Mesh2d_Grid::Node(const Standard_Integer theIndex) const 
{
    return myNodes(theIndex);
}

// ============================================================================
/*!
    \brief ResizeCells()
*/
// ============================================================================
void Mesh2d_Grid::ResizeCells(const Standard_Integer theNbCells,
                              const Standard_Boolean toCopyData) 
{
    myCells.Resize(1, theNbCells, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeNodes()
*/
// ============================================================================
void Mesh2d_Grid::ResizeNodes(const Standard_Integer theNbNodes,
                              const Standard_Boolean toCopyData) 
{
    myNodes.Resize(1, theNbNodes, toCopyData);
}

// ============================================================================
/*!
    \brief SetCell()
*/
// ============================================================================
void Mesh2d_Grid::SetCell(const Standard_Integer theIndex,
                          const Handle(Mesh2d_Cell)& theCell) 
{
    myCells.SetValue(theIndex, theCell);
}

// ============================================================================
/*!
    \brief SetNode()
*/
// ============================================================================
void Mesh2d_Grid::SetNode(const Standard_Integer theIndex,
                          const Handle(Mesh2d_Node)& theNode) 
{
    myNodes.SetValue(theIndex, theNode);
}



// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Mesh2d_Grid, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(Mesh2d_Grid, Standard_Transient)