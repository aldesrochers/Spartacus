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
#include <UThM_Linear.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UThM_Linear::UThM_Linear(const UThMP_Linear& theParameters)
    : myParameters(theParameters)
{
    RevertToInitialState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
UThM_Linear::~UThM_Linear()
{

}

// ============================================================================
/*!
 *  \brief CommitState()
*/
// ============================================================================
Standard_Boolean UThM_Linear::CommitState()
{
    myCommitTemperature = myTrialTemperature;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief GetGrowthRate()
*/
// ============================================================================
Standard_Real UThM_Linear::GetGrowthRate()
{
    return myParameters.Alpha();
}

// ============================================================================
/*!
 *  \brief GetInitialGrowthRate()
*/
// ============================================================================
Standard_Real UThM_Linear::GetInitialGrowthRate()
{
    return myParameters.Alpha();
}

// ============================================================================
/*!
 *  \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real UThM_Linear::GetTrialStrain()
{
    return myParameters.Alpha() * (myTrialTemperature - myParameters.T0());
}

// ============================================================================
/*!
 *  \brief GetTrialTemperature()
*/
// ============================================================================
Standard_Real UThM_Linear::GetTrialTemperature()
{
    return myTrialTemperature;
}

// ============================================================================
/*!
 *  \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean UThM_Linear::RevertToCommitState()
{
    myTrialTemperature = myCommitTemperature;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean UThM_Linear::RevertToInitialState()
{
    myCommitTemperature = 0.;
    myTrialTemperature = 0.;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief SetTrialTemperature()
*/
// ============================================================================
Standard_Boolean UThM_Linear::SetTrialTemperature(const Standard_Real theTemperature)
{
    myTrialTemperature = theTemperature;
    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(UThM_Linear, UThM_Model)
IMPLEMENT_STANDARD_RTTIEXT(UThM_Linear, UThM_Model)

