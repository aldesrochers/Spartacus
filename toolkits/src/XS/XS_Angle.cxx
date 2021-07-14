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
#include <XS_Angle.hxx>


// ============================================================================
/*!
 *  \brief Constructor
 *  Create an indefinite angle section.
*/
// ============================================================================
XS_Angle::XS_Angle()
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
XS_Angle::~XS_Angle()
{

}

// ============================================================================
/*!
 *  \brief B()
*/
// ============================================================================
Standard_Real XS_Angle::B() const
{
    return myB;
}

// ============================================================================
/*!
 *  \brief D()
*/
// ============================================================================
Standard_Real XS_Angle::D() const
{
    return myD;
}

// ============================================================================
/*!
 *  \brief R1()
*/
// ============================================================================
Standard_Real XS_Angle::R1() const
{
    return myR1;
}

// ============================================================================
/*!
 *  \brief R2()
*/
// ============================================================================
Standard_Real XS_Angle::R2() const
{
    return myR2;
}

// ============================================================================
/*!
 *  \brief SetB()
*/
// ============================================================================
void XS_Angle::SetB(const Standard_Real B)
{
    myB = B;
}

// ============================================================================
/*!
 *  \brief SetD()
*/
// ============================================================================
void XS_Angle::SetD(const Standard_Real D)
{
    myD = D;
}

// ============================================================================
/*!
 *  \brief SetR1()
*/
// ============================================================================
void XS_Angle::SetR1(const Standard_Real R1)
{
    myR1 = R1;
}

// ============================================================================
/*!
 *  \brief SetR2()
*/
// ============================================================================
void XS_Angle::SetR2(const Standard_Real R2)
{
    myR2 = R2;
}

// ============================================================================
/*!
 *  \brief SetT()
*/
// ============================================================================
void XS_Angle::SetT(const Standard_Real T)
{
    myT = T;
}

// ============================================================================
/*!
 *  \bref T()
*/
// ============================================================================
Standard_Real XS_Angle::T() const
{
    return myT;
}
