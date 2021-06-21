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

// cable
#include <mmp_Elastic.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
mmp_Elastic::mmp_Elastic()
    : myE(0.), myNu(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
mmp_Elastic::mmp_Elastic(const Standard_Real E)
    : myE(E), myNu(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
mmp_Elastic::mmp_Elastic(const Standard_Real E,
                           const Standard_Real Nu)
    : myE(E), myNu(Nu)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
mmp_Elastic::~mmp_Elastic()
{

}

// ============================================================================
/*!
    \brief E()
*/
// ============================================================================
Standard_Real mmp_Elastic::E() const
{
    return myE;
}

// ============================================================================
/*!
    \brief Nu()
*/
// ============================================================================
Standard_Real mmp_Elastic::Nu() const
{
    return myNu;
}

// ============================================================================
/*!
    \brief SetE()
*/
// ============================================================================
void mmp_Elastic::SetE(const Standard_Real E)
{
    myE = E;
}

// ============================================================================
/*!
    \brief SetNu()
*/
// ============================================================================
void mmp_Elastic::SetNu(const Standard_Real Nu)
{
    myNu = Nu;
}

