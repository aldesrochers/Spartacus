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
#include <Mesh2d_Cell.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mesh2d_Cell::Mesh2d_Cell()    
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mesh2d_Cell::Mesh2d_Cell(const Standard_Integer theNbNodes, 
                         Mesh2d_TypeOfCell theCellType)
    : myCellType(theCellType)
{
    myNodes.Resize(1, theNbNodes, Standard_False);
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Mesh2d_Cell::~Mesh2d_Cell()    
{
    
}

// ============================================================================
/*!
    \brief CellType()
*/
// ============================================================================
Mesh2d_TypeOfCell Mesh2d_Cell::CellType() const
{
    return myCellType;
}

// ============================================================================
/*!
    \brief NbNodes()
*/
// ============================================================================
Standard_Integer Mesh2d_Cell::NbNodes() const
{
    return myNodes.Size();
}

// ============================================================================
/*!
    \brief Node()
*/
// ============================================================================
Standard_Integer Mesh2d_Cell::Node(const Standard_Integer theIndex) const
{
    return myNodes.Value(theIndex);
}

// ============================================================================
/*!
    \brief ResizeNodes()
*/
// ============================================================================
void Mesh2d_Cell::ResizeNodes(const Standard_Integer theNbNodes,
                              const Standard_Boolean toCopyData)
{
    myNodes.Resize(1, theNbNodes, toCopyData);
}

// ============================================================================
/*!
    \brief SetCellType()
*/
// ============================================================================
void Mesh2d_Cell::SetCellType(const Mesh2d_TypeOfCell theCellType)
{
    myCellType = theCellType;
}

// ============================================================================
/*!
    \brief SetNode()
*/
// ============================================================================
void Mesh2d_Cell::SetNode(const Standard_Integer theIndex,
                          const Standard_Integer theNode)
{
    myNodes.SetValue(theIndex, theNode);    
}



// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Mesh2d_Cell, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(Mesh2d_Cell, Standard_Transient)