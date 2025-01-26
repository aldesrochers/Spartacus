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
#include <PLC_Node.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PLC_Node::PLC_Node()    
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PLC_Node::PLC_Node(const gp_Pnt& thePoint)   
    : myPoint(thePoint)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PLC_Node::PLC_Node(const gp_Pnt& thePoint,    
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
PLC_Node::PLC_Node(const gp_Pnt& thePoint,       
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
PLC_Node::~PLC_Node()    
{
    
}

// ============================================================================
/*!
    \brief Attributes()
*/
// ============================================================================
const TColStd_Array1OfReal& PLC_Node::Attributes() const
{
    return myAttributes;
}

// ============================================================================
/*!
    \brief BoundaryMarker()
*/
// ============================================================================
Standard_Integer PLC_Node::BoundaryMarker() const 
{
    return myBoundaryMarker;
}

// ============================================================================
/*!
    \brief Point()
*/
// ============================================================================
const gp_Pnt& PLC_Node::Point() const 
{
    return myPoint;
}

// ============================================================================
/*!
    \brief SetAttributes()
*/
// ============================================================================
void PLC_Node::SetAttributes(const TColStd_Array1OfReal& theAttributes) 
{
    myAttributes = theAttributes;
}

// ============================================================================
/*!
    \brief SetBoundaryMarker()
*/
// ============================================================================
void PLC_Node::SetBoundaryMarker(const Standard_Integer theBoundaryMarker) 
{
    myBoundaryMarker = theBoundaryMarker;
}

// ============================================================================
/*!
    \brief SetPoint()
*/
// ============================================================================
void PLC_Node::SetPoint(const gp_Pnt& thePoint) 
{
    myPoint = thePoint;
}

// ============================================================================
/*!
    \brief SetX()
*/
// ============================================================================
void PLC_Node::SetX(const Standard_Real theX) 
{
    myPoint.SetX(theX);
}

// ============================================================================
/*!
    \brief SetY()
*/
// ============================================================================
void PLC_Node::SetY(const Standard_Real theY) 
{
    myPoint.SetY(theY);
}

// ============================================================================
/*!
    \brief SetZ()
*/
// ============================================================================
void PLC_Node::SetZ(const Standard_Real theZ) 
{
    myPoint.SetZ(theZ);
}

// ============================================================================
/*!
    \brief X()
*/
// ============================================================================
Standard_Real PLC_Node::X() const 
{
    return myPoint.X();
}

// ============================================================================
/*!
    \brief Y()
*/
// ============================================================================
Standard_Real PLC_Node::Y() const 
{
    return myPoint.Y();
}

// ============================================================================
/*!
    \brief Z()
*/
// ============================================================================
Standard_Real PLC_Node::Z() const   
{
    return myPoint.Z();
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(PLC_Node, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(PLC_Node, Standard_Transient)