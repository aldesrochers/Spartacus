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
#include <fp_MenegottoPinto.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
fp_MenegottoPinto::fp_MenegottoPinto()
    : myB(0.),
      myR(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
fp_MenegottoPinto::fp_MenegottoPinto(const Standard_Real B)
    : myB(B),
      myR(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
fp_MenegottoPinto::fp_MenegottoPinto(const Standard_Real B,
                                     const Standard_Real R)
    : myB(B),
      myR(R)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
fp_MenegottoPinto::~fp_MenegottoPinto()
{

}

// ============================================================================
/*!
 *  \brief B()
*/
// ============================================================================
Standard_Real fp_MenegottoPinto::B() const
{
    return myB;
}

// ============================================================================
/*!
 *  \brief R()
*/
// ============================================================================
Standard_Real fp_MenegottoPinto::R() const
{
    return myR;
}

// ============================================================================
/*!
 *  \brief SetB()
*/
// ============================================================================
void fp_MenegottoPinto::SetB(const Standard_Real B)
{
    myB = B;
}

// ============================================================================
/*!
 *  \brief SetR()
*/
// ============================================================================
void fp_MenegottoPinto::SetR(const Standard_Real R)
{
    myR = R;
}
