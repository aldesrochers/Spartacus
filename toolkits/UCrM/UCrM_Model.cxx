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
#include <UCrM_Model.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UCrM_Model::UCrM_Model()
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
UCrM_Model::~UCrM_Model()
{

}

// ============================================================================
/*!
    \brief CommitState()
*/
// ============================================================================
Standard_Boolean UCrM_Model::CommitState()
{
    myCommitStrain = myTrialStrain;
    myCommitStress = myTrialStress;
    myCommitTemperature = myTrialTemperature;
    myCommitTime = myTrialTime;
    return Standard_True;
}

// ============================================================================
/*!
    \brief GetCommitStrain()
*/
// ============================================================================
Standard_Real UCrM_Model::GetCommitStrain()
{
    return myCommitStrain;
}

// ============================================================================
/*!
    \brief GetCommitStress()
*/
// ============================================================================
Standard_Real UCrM_Model::GetCommitStress()
{
    return myCommitStress;
}

// ============================================================================
/*!
    \brief GetCommitTemperature()
*/
// ============================================================================
Standard_Real UCrM_Model::GetCommitTemperature()
{
    return myCommitTemperature;
}

// ============================================================================
/*!
    \brief GetCommitTime()
*/
// ============================================================================
Standard_Real UCrM_Model::GetCommitTime()
{
    return myCommitTime;
}

// ============================================================================
/*!
    \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real UCrM_Model::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
    \brief GetTrialStress()
*/
// ============================================================================
Standard_Real UCrM_Model::GetTrialStress()
{
    return myTrialStress;
}

// ============================================================================
/*!
    \brief GetTrialTemperature()
*/
// ============================================================================
Standard_Real UCrM_Model::GetTrialTemperature()
{
    return myTrialTemperature;
}

// ============================================================================
/*!
    \brief GetTrialTime()
*/
// ============================================================================
Standard_Real UCrM_Model::GetTrialTime()
{
    return myTrialTime;
}

// ============================================================================
/*!
    \brief MustBeUpdated()
*/
// ============================================================================
Standard_Boolean UCrM_Model::MustBeUpdated()
{
    return myMustBeUpdated;
}

// ============================================================================
/*!
    \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean UCrM_Model::RevertToCommitState()
{
    myTrialStrain = myCommitStrain;
    myTrialStress = myCommitStress;
    myTrialTemperature = myCommitTemperature;
    myTrialTime = myCommitTime;
    return Standard_True;
}

// ============================================================================
/*!
    \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean UCrM_Model::RevertToInitialState()
{
    myCommitStrain = 0.;
    myCommitStress = 0.;
    myCommitTemperature = 0.;
    myCommitTime = 0.;
    myTrialStrain = 0.;
    myTrialStress = 0.;
    myTrialTemperature = 0.;
    myTrialTime = 0.;
    return Standard_True;
}

// ============================================================================
/*!
    \brief SetTrialStress()
*/
// ============================================================================
Standard_Boolean UCrM_Model::SetTrialStress(const Standard_Real theStress)
{
    myTrialStress = theStress;
    myMustBeUpdated = Standard_True;
    return Standard_True;
}

// ============================================================================
/*!
    \brief SetTrialTemperature()
*/
// ============================================================================
Standard_Boolean UCrM_Model::SetTrialTemperature(const Standard_Real theTemperature)
{
    myTrialTemperature = theTemperature;
    myMustBeUpdated = Standard_True;
    return Standard_True;
}

// ============================================================================
/*!
    \brief SetTrialTime()
*/
// ============================================================================
Standard_Boolean UCrM_Model::SetTrialTime(const Standard_Real theTime)
{
    myTrialTime = theTime;
    myMustBeUpdated = Standard_True;
    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(UCrM_Model, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(UCrM_Model, Standard_Transient)

