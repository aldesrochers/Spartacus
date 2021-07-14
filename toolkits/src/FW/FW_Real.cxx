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
#include <FW_Real.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
FW_Real::FW_Real()
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
FW_Real::FW_Real(const int theValue)
    : myValue(theValue)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
FW_Real::~FW_Real()
{

}

// ============================================================================
/*!
 *  \brief ToDouble()
*/
// ============================================================================
double FW_Real::ToDouble() const
{
    return myValue;
}

// ============================================================================
/*!
 *  \brief ToStandardReal()
*/
// ============================================================================
Standard_Real FW_Real::ToStandardReal() const
{
    return (Standard_Real) myValue;
}
