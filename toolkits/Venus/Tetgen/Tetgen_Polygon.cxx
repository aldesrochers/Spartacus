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
#include <Tetgen_Polygon.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Tetgen_Polygon::Tetgen_Polygon()    
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Tetgen_Polygon::Tetgen_Polygon(const Standard_Integer theNbPoints)    
{
    ResizePoints(theNbPoints);
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Tetgen_Polygon::~Tetgen_Polygon()    
{
    
}

// ============================================================================
/*!
    \brief NbPoints()
*/
// ============================================================================
Standard_Integer Tetgen_Polygon::NbPoints() const
{
    return myPoints.Length();
}

// ============================================================================
/*!
    \brief Point()
*/
// ============================================================================
Standard_Integer Tetgen_Polygon::Point(const Standard_Integer theIndex) const
{
    return myPoints.Value(theIndex);
}

// ============================================================================
/*!
    \brief Point()
*/
// ============================================================================
void Tetgen_Polygon::Point(const Standard_Integer theIndex, 
                           Standard_Integer& thePoint) const
{
    thePoint = myPoints.Value(theIndex);
}

// ============================================================================
/*!
    \brief ResizePoints()
*/
// ============================================================================
void Tetgen_Polygon::ResizePoints(const Standard_Integer theNbPoints,
                                  const Standard_Boolean toCopyData)
{
    myPoints.Resize(1, theNbPoints, toCopyData);
}

// ============================================================================
/*!
    \brief SetPoint()
*/
// ============================================================================
void Tetgen_Polygon::SetPoint(const Standard_Integer theIndex, 
                              const Standard_Integer thePoint)
{
    myPoints.SetValue(theIndex, thePoint);
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Tetgen_Polygon, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(Tetgen_Polygon, Standard_Transient)