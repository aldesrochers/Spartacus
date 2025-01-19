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
#include <Cell_Polygon.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Cell_Polygon::Cell_Polygon()    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Cell_Polygon::~Cell_Polygon()    
{
    
}

// ============================================================================
/*!
    \brief Edge()
*/
// ============================================================================
const Handle(Cell_Edge)& Cell_Polygon::Edge(const Standard_Integer theIndex) const
{
    return myEdges(theIndex);
}

// ============================================================================
/*!
    \brief NbEdges()
*/
// ============================================================================
Standard_Integer Cell_Polygon::NbEdges() const
{
    return myEdges.Size();
}

// ============================================================================
/*!
    \brief ResizeEdges()
*/
// ============================================================================
void Cell_Polygon::ResizeEdges(const Standard_Integer theNbEdges,
                               const Standard_Boolean toCopyData)
{
    myEdges.Resize(1, theNbEdges, toCopyData);
}

// ============================================================================
/*!
    \brief SetEdge()
*/
// ============================================================================
void Cell_Polygon::SetEdge(const Standard_Integer theIndex,
                           const Handle(Cell_Edge)& theEdge)
{
    myEdges(theIndex) = theEdge;
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Cell_Polygon, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(Cell_Polygon, Standard_Transient)