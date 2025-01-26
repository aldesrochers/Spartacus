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
#include <Tetgen_Facet.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Tetgen_Facet::Tetgen_Facet()    
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Tetgen_Facet::Tetgen_Facet(const Standard_Integer theNbPolygons)  
{
    ResizePolygons(theNbPolygons, Standard_False);
}


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Tetgen_Facet::Tetgen_Facet(const Standard_Integer theNbPolygons,
                           const Standard_Integer theNbHoles)    
{
    ResizeHoles(theNbHoles, Standard_False);
    ResizePolygons(theNbPolygons, Standard_False);
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Tetgen_Facet::~Tetgen_Facet()    
{
    
}

// ============================================================================
/*!
    \brief Hole()
*/
// ============================================================================
void Tetgen_Facet::Hole(const Standard_Integer theIndex,
                        Standard_Real& theX,
                        Standard_Real& theY,
                        Standard_Real& theZ) const
{
    theX = myHoles.Value(theIndex, 1);
    theY = myHoles.Value(theIndex, 2);
    theZ = myHoles.Value(theIndex, 3);
}

// ============================================================================
/*!
    \brief NbHoles()
*/
// ============================================================================
Standard_Integer Tetgen_Facet::NbHoles() const
{
    return myHoles.NbRows();
}

// ============================================================================
/*!
    \brief NbPolygons()
*/
// ============================================================================
Standard_Integer Tetgen_Facet::NbPolygons() const
{
    return myPolygons.Length();
}

// ============================================================================
/*!
    \brief Polygon()
*/
// ============================================================================
const Handle(Tetgen_Polygon)& Tetgen_Facet::Polygon(const Standard_Integer theIndex) const
{
    return myPolygons.Value(theIndex);
}

// ============================================================================
/*!
    \brief Polygon()
*/
// ============================================================================
void Tetgen_Facet::Polygon(const Standard_Integer theIndex,
                           Handle(Tetgen_Polygon)& thePolygon) const
{
    thePolygon = myPolygons.Value(theIndex);
}

// ============================================================================
/*!
    \brief ResizeHoles()
*/
// ============================================================================
void Tetgen_Facet::ResizeHoles(const Standard_Integer theNbHoles,
                               const Standard_Boolean toCopyData)
{
    myHoles.Resize(1, theNbHoles, 1, 3, toCopyData);
}

// ============================================================================
/*!
    \brief ResizePolygons()
*/
// ============================================================================
void Tetgen_Facet::ResizePolygons(const Standard_Integer theNbPolygons,
                                 const Standard_Boolean toCopyData) 
{
    myPolygons.Resize(1, theNbPolygons, toCopyData);
}

// ============================================================================
/*!
    \brief SetHole()
*/
// ============================================================================
void Tetgen_Facet::SetHole(const Standard_Integer theIndex,
                           const Standard_Real theX,
                           const Standard_Real theY,
                           const Standard_Real theZ)
{
    myHoles.SetValue(theIndex, 1, theX);
    myHoles.SetValue(theIndex, 2, theY);
    myHoles.SetValue(theIndex, 3, theZ);
}

// ============================================================================
/*!
    \brief SetPolygon()
*/
// ============================================================================
void Tetgen_Facet::SetPolygon(const Standard_Integer theIndex,
                              const Handle(Tetgen_Polygon)& thePolygon) 
{
    myPolygons.SetValue(theIndex, thePolygon);
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Tetgen_Facet, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(Tetgen_Facet, Standard_Transient)