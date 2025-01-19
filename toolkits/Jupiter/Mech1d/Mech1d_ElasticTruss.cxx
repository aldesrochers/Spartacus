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
#include <Mech1d_ElasticTruss.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mech1d_ElasticTruss::Mech1d_ElasticTruss()    
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mech1d_ElasticTruss::Mech1d_ElasticTruss(const gp_Pnt1d& thePoint1,
                                         const gp_Pnt1d& thePoint2)
    : Mech1d_Truss(thePoint1, thePoint2)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Mech1d_ElasticTruss::~Mech1d_ElasticTruss()    
{
    
}

// ============================================================================
/*!
    \brief Area()
    Get the area of the truss element.
*/ 
// ============================================================================
Standard_Real Mech1d_ElasticTruss::Area() const
{
    return myArea;
}

// ============================================================================
/*!
    \brief Modulus()
    Get the modulus of the truss element.
*/
// ============================================================================
Standard_Real Mech1d_ElasticTruss::Modulus() const
{
    return myModulus;
}

// ============================================================================
/*!
    \brief SetArea()
    Set the area of the truss element.
*/
// ============================================================================
void Mech1d_ElasticTruss::SetArea(const Standard_Real theArea)
{
    myArea = theArea;
}

// ============================================================================
/*!
    \brief SetModulus()
    Set the modulus of the truss element.
*/
// ============================================================================
void Mech1d_ElasticTruss::SetModulus(const Standard_Real theModulus)
{
    myModulus = theModulus;
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Mech1d_ElasticTruss, Mech1d_Truss)
IMPLEMENT_STANDARD_RTTIEXT(Mech1d_ElasticTruss, Mech1d_Truss)