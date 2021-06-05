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


// Caelus
#include <Caelus_Span.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_Span::Caelus_Span()
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_Span::Caelus_Span(const Standard_Real theLength)
    : myLength(theLength),
      mySlope(0.)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Caelus_Span::Caelus_Span(const Standard_Real theLength,
                                         const Standard_Real theSlope)
    : myLength(theLength),
      mySlope(theSlope)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Caelus_Span::~Caelus_Span()
{

}

// ============================================================================
/*!
    \brief Length()
*/
// ============================================================================
Standard_Real Caelus_Span::Length() const
{
    return myLength;
}

// ============================================================================
/*!
    \brief Slope()
*/
// ============================================================================
Standard_Real Caelus_Span::Slope() const
{
    return mySlope;
}

// ============================================================================
/*!
    \brief SetLength()
*/
// ============================================================================
void Caelus_Span::SetLength(const Standard_Real theLength)
{
    myLength = theLength;
}

// ============================================================================
/*!
    \brief SetSlope()
*/
// ============================================================================
void Caelus_Span::SetSlope(const Standard_Real theSlope)
{
    mySlope = theSlope;
}




