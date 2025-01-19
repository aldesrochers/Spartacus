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
#include <Mesh_CellFactory.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mesh_CellFactory::Mesh_CellFactory()    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Mesh_CellFactory::~Mesh_CellFactory()    
{
    
}

// ============================================================================
/*!
    \brief MakeLinearLine()
*/
// ============================================================================
Handle(Mesh_Cell) Mesh_CellFactory::MakeLinearLine(const Standard_Integer theNode1,
                                                   const Standard_Integer theNode2)
{
    Handle(Mesh_Cell) aCell = new Mesh_Cell();
    aCell->ResizeNodes(2);
    aCell->SetNode(1, theNode1);
    aCell->SetNode(2, theNode2);
    aCell->SetType(Mesh_CELL_BAR2);
    return aCell;
}