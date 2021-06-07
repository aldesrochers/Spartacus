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


// SSCLM1d
#include <SSCLM1d_Elastic.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
SSCLM1d_Elastic::SSCLM1d_Elastic(const Standard_Real E)
    : myE(E)
{
    RevertToInitialState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
SSCLM1d_Elastic::~SSCLM1d_Elastic()
{

}

// ============================================================================
/*!
 *  \brief CommitState()
*/
// ============================================================================
Standard_Boolean SSCLM1d_Elastic::CommitState()
{
    myCommitStrain = myTrialStrain;
    myCommitStress = myTrialStress;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief GetInitialStiffness()
*/
// ============================================================================
Standard_Real SSCLM1d_Elastic::GetInitialStiffness()
{
    return myE;
}

// ============================================================================
/*!
 *  \brief GetTrialStiffness()
*/
// ============================================================================
Standard_Real SSCLM1d_Elastic::GetTrialStiffness()
{
    return myE;
}

// ============================================================================
/*!
 *  \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real SSCLM1d_Elastic::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
 *  \brief GetTrialStress()
*/
// ============================================================================
Standard_Real SSCLM1d_Elastic::GetTrialStress()
{
    return myTrialStress;
}

// ============================================================================
/*!
 *  \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean SSCLM1d_Elastic::RevertToCommitState()
{
    myTrialStrain = myCommitStrain;
    myTrialStress = myCommitStress;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean SSCLM1d_Elastic::RevertToInitialState()
{
    myCommitStrain = 0.;
    myCommitStress = 0.;
    myTrialStrain = 0.;
    myTrialStress = 0.;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief SetTrialStrain()
*/
// ============================================================================
Standard_Boolean SSCLM1d_Elastic::SetTrialStrain(const Standard_Real theStrain)
{
    myTrialStrain = theStrain;
    myTrialStress = theStrain * myE;
    return Standard_True;
}



// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(SSCLM1d_Elastic, SSCLM1d_Model)
IMPLEMENT_STANDARD_RTTIEXT(SSCLM1d_Elastic, SSCLM1d_Model)

