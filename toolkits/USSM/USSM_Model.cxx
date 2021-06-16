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
#include <USSM_Model.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
USSM_Model::USSM_Model()
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
USSM_Model::~USSM_Model()
{

}

// ============================================================================
/*!
    \brief CommitState()
*/
// ============================================================================
Standard_Boolean USSM_Model::CommitState()
{
    myCommitStiffness = myTrialStiffness;
    myCommitStrain = myTrialStrain;
    myCommitStress = myTrialStress;
    return Standard_True;
}

// ============================================================================
/*!
    \brief GetCommitStiffness()
*/
// ============================================================================
Standard_Real USSM_Model::GetCommitStiffness()
{
    return myCommitStiffness;
}

// ============================================================================
/*!
    \brief GetCommitStrain()
*/
// ============================================================================
Standard_Real USSM_Model::GetCommitStrain()
{
    return myCommitStrain;
}

// ============================================================================
/*!
    \brief GetCommitStress()
*/
// ============================================================================
Standard_Real USSM_Model::GetCommitStress()
{
    return myCommitStress;
}

// ============================================================================
/*!
    \brief GetTrialStiffness()
*/
// ============================================================================
Standard_Real USSM_Model::GetTrialStiffness()
{
    return myTrialStiffness;
}

// ============================================================================
/*!
    \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real USSM_Model::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
    \brief GetTrialStress()
*/
// ============================================================================
Standard_Real USSM_Model::GetTrialStress()
{
    return myTrialStress;
}

// ============================================================================
/*!
    \brief MustBeUpdated()
*/
// ============================================================================
Standard_Boolean USSM_Model::MustBeUpdated()
{
    return myMustBeUpdated;
}

// ============================================================================
/*!
    \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean USSM_Model::RevertToCommitState()
{
    myTrialStiffness = myCommitStiffness;
    myTrialStrain = myCommitStrain;
    myTrialStress = myCommitStress;
    return Standard_True;
}

// ============================================================================
/*!
    \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean USSM_Model::RevertToInitialState()
{
    myCommitStiffness = 0.;
    myCommitStrain = 0.;
    myCommitStress = 0.;
    myTrialStiffness = 0.;
    myTrialStrain = 0.;
    myTrialStress = 0.;
    return Standard_True;
}

// ============================================================================
/*!
    \brief SetTrialStrain()
*/
// ============================================================================
Standard_Boolean USSM_Model::SetTrialStrain(const Standard_Real theStrain)
{
    myTrialStrain = theStrain;
    myMustBeUpdated = Standard_True;
    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(USSM_Model, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(USSM_Model, Standard_Transient)

