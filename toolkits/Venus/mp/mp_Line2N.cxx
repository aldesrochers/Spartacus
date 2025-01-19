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
#include <mp_Line2N.hxx>



// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
mp_Line2N::mp_Line2N()
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
mp_Line2N::~mp_Line2N()    
{
    
}

// ============================================================================
/*!
    \brief Point1()
*/
// ============================================================================
const gp_Pnt& mp_Line2N::Point1() const
{
    return myPoint1;
}   

// ============================================================================
/*!
    \brief Point2()
*/
// ============================================================================
const gp_Pnt& mp_Line2N::Point2() const
{
    return myPoint2;
}

// ============================================================================
/*!
    \brief SetPoint1()
*/
// ============================================================================
void mp_Line2N::SetPoint1(const gp_Pnt& thePoint1)
{
    myPoint1 = thePoint1;
}

// ============================================================================
/*!
    \brief SetPoint2()
*/
// ============================================================================
void mp_Line2N::SetPoint2(const gp_Pnt& thePoint2)
{
    myPoint2 = thePoint2;
}   
