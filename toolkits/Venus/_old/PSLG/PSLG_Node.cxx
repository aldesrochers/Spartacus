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
#include <PSLG_Node.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Node::PSLG_Node()    
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Node::PSLG_Node(const gp_Pnt2d& thePoint)   
    : myPoint(thePoint)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Node::PSLG_Node(const gp_Pnt2d& thePoint,    
                     const TColStd_Array1OfReal& theAttributes)   
    : myPoint(thePoint), 
    myAttributes(theAttributes)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Node::PSLG_Node(const gp_Pnt2d& thePoint,       
                     const TColStd_Array1OfReal& theAttributes,        
                     const Standard_Integer theBoundaryMarker)
    : myPoint(thePoint), 
    myAttributes(theAttributes), 
    myBoundaryMarker(theBoundaryMarker)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
PSLG_Node::~PSLG_Node()    
{
    
}

// ============================================================================
/*!
    \brief Attributes()
*/
// ============================================================================
const TColStd_Array1OfReal& PSLG_Node::Attributes() const
{
    return myAttributes;
}

// ============================================================================
/*!
    \brief BoundaryMarker()
*/
// ============================================================================
Standard_Integer PSLG_Node::BoundaryMarker() const 
{
    return myBoundaryMarker;
}

// ============================================================================
/*!
    \brief Point()
*/
// ============================================================================
const gp_Pnt2d& PSLG_Node::Point() const 
{
    return myPoint;
}

// ============================================================================
/*!
    \brief SetAttributes()
*/
// ============================================================================
void PSLG_Node::SetAttributes(const TColStd_Array1OfReal& theAttributes) 
{
    myAttributes = theAttributes;
}

// ============================================================================
/*!
    \brief SetBoundaryMarker()
*/
// ============================================================================
void PSLG_Node::SetBoundaryMarker(const Standard_Integer theBoundaryMarker) 
{
    myBoundaryMarker = theBoundaryMarker;
}

// ============================================================================
/*!
    \brief SetPoint()
*/
// ============================================================================
void PSLG_Node::SetPoint(const gp_Pnt2d& thePoint) 
{
    myPoint = thePoint;
}

// ============================================================================
/*!
    \brief SetX()
*/
// ============================================================================
void PSLG_Node::SetX(const Standard_Real theX) 
{
    myPoint.SetX(theX);
}

// ============================================================================
/*!
    \brief SetY()
*/
// ============================================================================
void PSLG_Node::SetY(const Standard_Real theY) 
{
    myPoint.SetY(theY);
}

// ============================================================================
/*!
    \brief X()
*/
// ============================================================================
Standard_Real PSLG_Node::X() const 
{
    return myPoint.X();
}

// ============================================================================
/*!
    \brief Y()
*/
// ============================================================================
Standard_Real PSLG_Node::Y() const 
{
    return myPoint.Y();
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(PSLG_Node, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(PSLG_Node, Standard_Transient)