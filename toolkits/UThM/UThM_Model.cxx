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
#include <UThM_Model.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UThM_Model::UThM_Model()
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
UThM_Model::~UThM_Model()
{

}

// ============================================================================
/*!
    \brief CommitState()
*/
// ============================================================================
Standard_Boolean UThM_Model::CommitState()
{
    myCommitStrain = myTrialStrain;
    myCommitTemperature = myTrialTemperature;
    return Standard_True;
}

// ============================================================================
/*!
    \brief GetCommitStrain()
*/
// ============================================================================
Standard_Real UThM_Model::GetCommitStrain()
{
    return myCommitStrain;
}

// ============================================================================
/*!
    \brief GetCommitTemperature()
*/
// ============================================================================
Standard_Real UThM_Model::GetCommitTemperature()
{
    return myCommitTemperature;
}

// ============================================================================
/*!
    \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real UThM_Model::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
    \brief GetTrialTemperature()
*/
// ============================================================================
Standard_Real UThM_Model::GetTrialTemperature()
{
    return myTrialTemperature;
}

// ============================================================================
/*!
    \brief MustBeUpdated()
*/
// ============================================================================
Standard_Boolean UThM_Model::MustBeUpdated()
{
    return myMustBeUpdated;
}

// ============================================================================
/*!
    \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean UThM_Model::RevertToCommitState()
{
    myTrialStrain = myCommitStrain;
    myTrialTemperature = myCommitTemperature;
    return Standard_True;
}

// ============================================================================
/*!
    \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean UThM_Model::RevertToInitialState()
{
    myCommitStrain = 0.;
    myCommitTemperature = 0.;
    myTrialStrain = 0.;
    myTrialTemperature = 0.;
    return Standard_True;
}

// ============================================================================
/*!
    \brief SetTrialTemperature()
*/
// ============================================================================
Standard_Boolean UThM_Model::SetTrialTemperature(const Standard_Real theTemperature)
{
    myTrialTemperature = theTemperature;
    myMustBeUpdated = Standard_True;
    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(UThM_Model, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(UThM_Model, Standard_Transient)

