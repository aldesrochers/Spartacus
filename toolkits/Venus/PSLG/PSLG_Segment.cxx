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
#include <PSLG_Segment.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Segment::PSLG_Segment()    
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Segment::PSLG_Segment(const Standard_Integer theNode1,
                           const Standard_Integer theNode2)    
    : myNode1(theNode1), myNode2(theNode2)
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Segment::PSLG_Segment(const Standard_Integer theNode1,     
                           const Standard_Integer theNode2,     
                           const Standard_Integer theBoundaryMarker)    
    : myNode1(theNode1), myNode2(theNode2), myBoundaryMarker(theBoundaryMarker)
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
PSLG_Segment::~PSLG_Segment()    
{
    
}

// ============================================================================
/*!
    \brief BoundaryMarker()
*/
// ============================================================================
Standard_Integer PSLG_Segment::BoundaryMarker() const 
{
    return myBoundaryMarker;
}

// ============================================================================
/*!
    \brief Node1()
*/
// ============================================================================
Standard_Integer PSLG_Segment::Node1() const 
{
    return myNode1;
}

// ============================================================================
/*!
    \brief Node2()
*/
// ============================================================================
Standard_Integer PSLG_Segment::Node2() const 
{
    return myNode2;
}

// ============================================================================
/*!
    \brief SetBoundaryMarker()
*/
// ============================================================================
void PSLG_Segment::SetBoundaryMarker(const Standard_Integer theBoundaryMarker) 
{
    myBoundaryMarker = theBoundaryMarker;
}

// ============================================================================
/*!
    \brief SetNode1()
*/
// ============================================================================
void PSLG_Segment::SetNode1(const Standard_Integer theNode1) 
{
    myNode1 = theNode1;
}

// ============================================================================
/*!
    \brief SetNode2()
*/
// ============================================================================
void PSLG_Segment::SetNode2(const Standard_Integer theNode2) 
{
    myNode2 = theNode2;
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(PSLG_Segment, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(PSLG_Segment, Standard_Transient)