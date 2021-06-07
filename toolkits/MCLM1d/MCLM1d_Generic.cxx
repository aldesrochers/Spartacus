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
#include <MCLM1d_Generic.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MCLM1d_Generic::MCLM1d_Generic()
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MCLM1d_Generic::~MCLM1d_Generic()
{

}

// ============================================================================
/*!
 *  \brief CommitState()
*/
// ============================================================================
Standard_Boolean MCLM1d_Generic::CommitState()
{
    // commit sub-models
    if(!myCreepModel.IsNull())
        myCreepModel->CommitState();
    if(!myStressStrainModel.IsNull())
        myStressStrainModel->CommitState();
    if(!myThermalModel.IsNull())
        myThermalModel->CommitState();
    // commit internal state
    myCommitStrain = myTrialStrain;
    myCommitTemperature = myTrialTemperature;
    myCommitTime = myTrialTime;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief GetTrialStiffness()
*/
// ============================================================================
Standard_Real MCLM1d_Generic::GetTrialStiffness()
{
    if(!myStressStrainModel.IsNull())
        return myStressStrainModel->GetTrialStiffness();
    return 0.;
}

// ============================================================================
/*!
 *  \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real MCLM1d_Generic::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
 *  \brief GetTrialStress()
*/
// ============================================================================
Standard_Real MCLM1d_Generic::GetTrialStress()
{
    if(!myStressStrainModel.IsNull())
        return myStressStrainModel->GetTrialStress();
    return 0.;
}

// ============================================================================
/*!
 *  \brief GetTrialTemperature()
*/
// ============================================================================
Standard_Real MCLM1d_Generic::GetTrialTemperature()
{
    return myTrialTemperature;
}

// ============================================================================
/*!
 *  \brief GetTrialTime()
*/
// ============================================================================
Standard_Real MCLM1d_Generic::GetTrialTime()
{
    return myTrialTime;
}

// ============================================================================
/*!
 *  \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean MCLM1d_Generic::RevertToCommitState()
{
    // revert sub-models
    if(!myCreepModel.IsNull())
        myCreepModel->RevertToCommitState();
    if(!myStressStrainModel.IsNull())
        myStressStrainModel->RevertToCommitState();
    if(!myThermalModel.IsNull())
        myThermalModel->RevertToCommitState();
    // revert internal variables
    myTrialStrain = myCommitStrain;
    myTrialTemperature = myCommitTemperature;
    myTrialTime = myCommitTime;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean MCLM1d_Generic::RevertToInitialState()
{
    // revert sub-models
    if(!myCreepModel.IsNull())
        myCreepModel->RevertToInitialState();
    if(!myStressStrainModel.IsNull())
        myStressStrainModel->RevertToInitialState();
    if(!myThermalModel.IsNull())
        myThermalModel->RevertToInitialState();
    // revert internal variables
    myCommitStrain = 0.;
    myCommitTemperature = 0.;
    myCommitTime = 0.;
    myTrialStrain = 0.;
    myTrialTemperature = 0.;
    myTrialTime = 0.;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief SetTrialStrain()
*/
// ============================================================================
Standard_Boolean MCLM1d_Generic::SetTrialStrain(const Standard_Real theStrain)
{
    myTrialStrain = theStrain;
    return UpdateInternalState();
}

// ============================================================================
/*!
 *  \brief SetTrialTemperature()
*/
// ============================================================================
Standard_Boolean MCLM1d_Generic::SetTrialTemperature(const Standard_Real theTemperature)
{
    myTrialTemperature = theTemperature;
    return UpdateInternalState();
}

// ============================================================================
/*!
 *  \brief SetTrialTime()
*/
// ============================================================================
Standard_Boolean MCLM1d_Generic::SetTrialTime(const Standard_Real theTime)
{
    myTrialTime = theTime;
    return UpdateInternalState();
}

// ============================================================================
/*!
 *  \brief UpdateInternalState()
 *  The model must solve internally for creep, mechanical and thermal
 *  displacements based on the current trial strain.
*/
// ============================================================================
Standard_Boolean MCLM1d_Generic::UpdateInternalState()
{

}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MCLM1d_Generic, MCLM1d_Model)
IMPLEMENT_STANDARD_RTTIEXT(MCLM1d_Generic, MCLM1d_Model)

