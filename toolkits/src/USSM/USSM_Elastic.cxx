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
#include <USSM_Elastic.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
USSM_Elastic::USSM_Elastic(const Standard_Real E)
{
    myParameters = USSMP_Elastic(E);
    RevertToInitialState();
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
USSM_Elastic::USSM_Elastic(const USSMP_Elastic& theParameters)
    : myParameters(theParameters)
{
    RevertToInitialState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
USSM_Elastic::~USSM_Elastic()
{

}

// ============================================================================
/*!
    \brief CommitState()
*/
// ============================================================================
Standard_Boolean USSM_Elastic::CommitState()
{
    myCommitStrain = myTrialStrain;
    return Standard_True;
}

// ============================================================================
/*!
    \brief GetInitialStiffness()
*/
// ============================================================================
Standard_Real USSM_Elastic::GetInitialStiffness()
{
    return myParameters.E();
}

// ============================================================================
/*!
    \brief GetTrialStiffness()
*/
// ============================================================================
Standard_Real USSM_Elastic::GetTrialStiffness()
{
    return myParameters.E();
}

// ============================================================================
/*!
    \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real USSM_Elastic::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
    \brief GetTrialStress()
*/
// ============================================================================
Standard_Real USSM_Elastic::GetTrialStress()
{
    return myTrialStrain * myParameters.E();
}

// ============================================================================
/*!
    \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean USSM_Elastic::RevertToCommitState()
{
    myTrialStrain = myCommitStrain;
    return Standard_True;
}

// ============================================================================
/*!
    \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean USSM_Elastic::RevertToInitialState()
{
    myCommitStrain = 0.;
    myTrialStrain = 0.;
    return Standard_True;
}

// ============================================================================
/*!
    \brief SetTrialStrain()
*/
// ============================================================================
Standard_Boolean USSM_Elastic::SetTrialStrain(const Standard_Real theStrain)
{
    myTrialStrain = theStrain;
    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(USSM_Elastic, USSM_Model)
IMPLEMENT_STANDARD_RTTIEXT(USSM_Elastic, USSM_Model)

