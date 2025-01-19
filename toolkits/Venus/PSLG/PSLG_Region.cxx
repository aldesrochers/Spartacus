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
#include <PSLG_Region.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Region::PSLG_Region()    
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Region::PSLG_Region(const gp_Pnt2d& thePoint)   
    : myPoint(thePoint)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Region::PSLG_Region(const gp_Pnt2d& thePoint,    
                         const Standard_Real theAttribute)   
    : myPoint(thePoint), 
    myAttribute(theAttribute)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Region::PSLG_Region(const gp_Pnt2d& thePoint,       
                         const Standard_Real theAttribute,        
                         const Standard_Real theMaximumArea)
    : myPoint(thePoint), 
    myAttribute(theAttribute), 
    myMaximumArea(theMaximumArea)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
PSLG_Region::~PSLG_Region()    
{
    
}

// ============================================================================
/*!
    \brief Attribute()
*/
// ============================================================================
Standard_Real PSLG_Region::Attribute() const
{
    return myAttribute;
}

// ============================================================================
/*!
    \brief MaximumArea()
*/
// ============================================================================
Standard_Real PSLG_Region::MaximumArea() const  
{
    return myMaximumArea;
}

// ============================================================================
/*!
    \brief Point()
*/
// ============================================================================
const gp_Pnt2d& PSLG_Region::Point() const 
{
    return myPoint;
}

// ============================================================================
/*!
    \brief SetAttribute()
*/
// ============================================================================
void PSLG_Region::SetAttribute(const Standard_Real theAttribute) 
{
    myAttribute = theAttribute;
}

// ============================================================================
/*!
    \brief SetMaximumArea()
*/
// ============================================================================
void PSLG_Region::SetMaximumArea(const Standard_Real theMaximumArea) 
{
    myMaximumArea = theMaximumArea;
}

// ============================================================================
/*!
    \brief SetPoint()
*/
// ============================================================================
void PSLG_Region::SetPoint(const gp_Pnt2d& thePoint) 
{
    myPoint = thePoint;
}

// ============================================================================
/*!
    \brief SetX()
*/
// ============================================================================
void PSLG_Region::SetX(const Standard_Real theX) 
{
    myPoint.SetX(theX);
}

// ============================================================================
/*!
    \brief SetY()
*/
// ============================================================================
void PSLG_Region::SetY(const Standard_Real theY) 
{
    myPoint.SetY(theY);
}

// ============================================================================
/*!
    \brief X()
*/
// ============================================================================
Standard_Real PSLG_Region::X() const 
{
    return myPoint.X();
}

// ============================================================================
/*!
    \brief Y()
*/
// ============================================================================
Standard_Real PSLG_Region::Y() const 
{
    return myPoint.Y();
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(PSLG_Region, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(PSLG_Region, Standard_Transient)