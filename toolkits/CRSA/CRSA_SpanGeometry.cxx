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


// RS
#include <CRSA_SpanGeometry.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
CRSA_SpanGeometry::CRSA_SpanGeometry(const Standard_Real Length)
    : myLength(Length),
      mySlope(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
CRSA_SpanGeometry::CRSA_SpanGeometry(const Standard_Real Length,
                                     const Standard_Real Slope)
    : myLength(Length),
      mySlope(Slope)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
CRSA_SpanGeometry::~CRSA_SpanGeometry()
{

}

// ============================================================================
/*!
    \brief Length()
*/
// ============================================================================
Standard_Real CRSA_SpanGeometry::Length() const
{
    return myLength;
}

// ============================================================================
/*!
    \brief Slope()
*/
// ============================================================================
Standard_Real CRSA_SpanGeometry::Slope() const
{
    return mySlope;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(CRSA_SpanGeometry, Standard_Transient);
IMPLEMENT_STANDARD_RTTIEXT(CRSA_SpanGeometry, Standard_Transient);


