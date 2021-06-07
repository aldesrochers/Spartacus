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


// TECLM1d
#include <TECLM1d_Linear.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
TECLM1d_Linear::TECLM1d_Linear(const Standard_Real Alpha)
    : myAlpha(Alpha),
      myInitialTemperature(0.)
{
    RevertToInitialState();
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
TECLM1d_Linear::TECLM1d_Linear(const Standard_Real Alpha,
                               const Standard_Real InitialTemperature)
    : myAlpha(Alpha),
      myInitialTemperature(InitialTemperature)
{
    RevertToInitialState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
TECLM1d_Linear::~TECLM1d_Linear()
{

}

// ============================================================================
/*!
 *  \brief CommitState()
*/
// ============================================================================
Standard_Boolean TECLM1d_Linear::CommitState()
{
    myCommitStrain = myTrialStrain;
    myCommitTemperature = myTrialTemperature;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief GetInitialTemperature()
*/
// ============================================================================
Standard_Real TECLM1d_Linear::GetInitialTemperature()
{
    return myInitialTemperature;
}

// ============================================================================
/*!
 *  \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real TECLM1d_Linear::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
 *  \brief GetTrialTemperature()
*/
// ============================================================================
Standard_Real TECLM1d_Linear::GetTrialTemperature()
{
    return myTrialTemperature;
}

// ============================================================================
/*!
 *  \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean TECLM1d_Linear::RevertToCommitState()
{
    myTrialStrain = myCommitStrain;
    myTrialTemperature = myCommitTemperature;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean TECLM1d_Linear::RevertToInitialState()
{
    myCommitStrain = 0.;
    myCommitTemperature = 0.;
    myTrialStrain = 0.;
    myTrialTemperature = 0.;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief SetTrialTemperature()
*/
// ============================================================================
Standard_Boolean TECLM1d_Linear::SetTrialTemperature(const Standard_Real theTemperature)
{
    myTrialTemperature = theTemperature;
    myTrialStrain = myAlpha * (myTrialTemperature - myInitialTemperature);
    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(TECLM1d_Linear, TECLM1d_Model)
IMPLEMENT_STANDARD_RTTIEXT(TECLM1d_Linear, TECLM1d_Model)

