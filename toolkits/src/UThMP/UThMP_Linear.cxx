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
#include <UThMP_Linear.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
UThMP_Linear::UThMP_Linear()
    : myAlpha(0.), myT0(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UThMP_Linear::UThMP_Linear(const Standard_Real Alpha)
    : myAlpha(Alpha), myT0(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UThMP_Linear::UThMP_Linear(const Standard_Real Alpha,
                           const Standard_Real T0)
    : myAlpha(Alpha), myT0(T0)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
UThMP_Linear::~UThMP_Linear()
{

}

// ============================================================================
/*!
 *  \brief Alpha()
*/
// ============================================================================
Standard_Real UThMP_Linear::Alpha() const
{
    return myAlpha;
}

// ============================================================================
/*!
 *  \brief T0()
*/
// ============================================================================
Standard_Real UThMP_Linear::T0() const
{
    return myT0;
}

// ============================================================================
/*!
 *  \brief SetAlpha()
*/
// ============================================================================
void UThMP_Linear::SetAlpha(const Standard_Real Alpha)
{
    myAlpha = Alpha;
}

// ============================================================================
/*!
 *  \brief SetT0()
*/
// ============================================================================
void UThMP_Linear::SetT0(const Standard_Real T0)
{
    myT0 = T0;
}
