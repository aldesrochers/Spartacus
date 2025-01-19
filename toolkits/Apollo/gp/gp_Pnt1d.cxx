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
#include <gp_Pnt1d.hxx>

// OpenCascade
#include <Standard_ConstructionError.hxx>



// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
gp_Pnt1d::gp_Pnt1d()
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
gp_Pnt1d::gp_Pnt1d(const Standard_Real theX)
    : myX(theX)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
gp_Pnt1d::~gp_Pnt1d()
{

}

// ============================================================================
/*!
 *  \brief Distance()
*/
// ============================================================================
Standard_Real gp_Pnt1d::Distance(const gp_Pnt1d &theOther) const
{
    return Abs(theOther.X() - myX);
}

// ============================================================================
/*!
 *  \brief IsEqual()
*/
// ============================================================================
Standard_Boolean gp_Pnt1d::IsEqual(const gp_Pnt1d &theOther, const Standard_Real theLinearTolerance) const
{
    if(Distance(theOther) <= theLinearTolerance)
        return Standard_True;
    return Standard_False;
}

// ============================================================================
/*!
 *  \brief SetX()
*/
// ============================================================================
void gp_Pnt1d::SetX(const Standard_Real theX)
{
    myX = theX;
}

// ============================================================================
/*!
 *  \brief X()
*/
// ============================================================================
Standard_Real gp_Pnt1d::X() const
{
    return myX;
}

