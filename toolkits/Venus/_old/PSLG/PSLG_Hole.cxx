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
#include <PSLG_Hole.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Hole::PSLG_Hole()    
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Hole::PSLG_Hole(const gp_Pnt2d& thePoint)   
    : myPoint(thePoint)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
PSLG_Hole::~PSLG_Hole()    
{
    
}

// ============================================================================
/*!
    \brief Point()
*/
// ============================================================================
const gp_Pnt2d& PSLG_Hole::Point() const 
{
    return myPoint;
}

// ============================================================================
/*!
    \brief SetPoint()
*/
// ============================================================================
void PSLG_Hole::SetPoint(const gp_Pnt2d& thePoint) 
{
    myPoint = thePoint;
}

// ============================================================================
/*!
    \brief SetX()
*/
// ============================================================================
void PSLG_Hole::SetX(const Standard_Real theX) 
{
    myPoint.SetX(theX);
}

// ============================================================================
/*!
    \brief SetY()
*/
// ============================================================================
void PSLG_Hole::SetY(const Standard_Real theY) 
{
    myPoint.SetY(theY);
}

// ============================================================================
/*!
    \brief X()
*/
// ============================================================================
Standard_Real PSLG_Hole::X() const 
{
    return myPoint.X();
}

// ============================================================================
/*!
    \brief Y()
*/
// ============================================================================
Standard_Real PSLG_Hole::Y() const 
{
    return myPoint.Y();
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(PSLG_Hole, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(PSLG_Hole, Standard_Transient)