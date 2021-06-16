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


// MCLM1d
#include <UThM_BiLinear.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UThM_BiLinear::UThM_BiLinear(const Standard_Real Alpha0,
                             const Standard_Real T0,
                             const Standard_Real Alpha1,
                             const Standard_Real DT)
    : myAlpha0(Alpha0), myAlpha1(Alpha1), myT0(T0), myDT(DT)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
UThM_BiLinear::~UThM_BiLinear()
{

}

// ============================================================================
/*!
    \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean UThM_BiLinear::UpdateInternalState()
{
    // update the thermal strain
    if(myTrialTemperature > myT0 + myDT) {
        myTrialStrain = myAlpha0 * myDT
                + myAlpha1 * (myTrialTemperature - myT0 - myDT);
    } else if(myTrialTemperature > myT0 - myDT) {
        myTrialStrain = myAlpha0 * (myTrialTemperature - myT0);
    } else {
        myTrialStrain = -myAlpha0 * myDT
                + myAlpha1 * (myTrialTemperature - myT0 + myDT);
    }
    // set must be update flag
    myMustBeUpdated = Standard_False;
    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(UThM_BiLinear, UThM_Model)
IMPLEMENT_STANDARD_RTTIEXT(UThM_BiLinear, UThM_Model)

