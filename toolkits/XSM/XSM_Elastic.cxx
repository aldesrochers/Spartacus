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


// XSM
#include <XSM_Elastic.hxx>

// OpenCascade
#include <Precision.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
XSM_Elastic::XSM_Elastic(const Standard_Real theArea,
                         const Standard_Real theElasticModulous)
    : myArea(theArea),
      myElasticModulous(theElasticModulous)
{
    RevertToInitialState();
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
XSM_Elastic::XSM_Elastic(const Standard_Real theArea,
                         const Standard_Real theElasticModulous,
                         const Standard_Real theThermalExpansionCoef)
    : myArea(theArea),
      myElasticModulous(theElasticModulous),
      myThermalExpansionCoef(theThermalExpansionCoef)
{
    RevertToInitialState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
XSM_Elastic::~XSM_Elastic()
{

}

// ============================================================================
/*!
 *  \brief CommitState()
*/
// ============================================================================
Standard_Boolean XSM_Elastic::CommitState()
{
    myCommitForce = myTrialForce;
    myCommitMechanicalStrain = myTrialMechanicalStrain;
    myCommitStiffness = myTrialStiffness;
    myCommitStrain = myTrialStrain;
    myCommitTemperature = myTrialTemperature;
    myCommitThermalStrain = myTrialThermalStrain;
    myCommitTime = myTrialTime;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief GetInitialStiffness()
*/
// ============================================================================
Standard_Real XSM_Elastic::GetInitialStiffness()
{
    return myElasticModulous;
}

// ============================================================================
/*!
 *  \brief GetTrialForce()
*/
// ============================================================================
Standard_Real XSM_Elastic::GetTrialForce()
{
    return myTrialForce;
}

// ============================================================================
/*!
 *  \brief GetTrialStiffness()
*/
// ============================================================================
Standard_Real XSM_Elastic::GetTrialStiffness()
{
    return myTrialStiffness;
}

// ============================================================================
/*!
 *  \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real XSM_Elastic::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
 *  \brief GetTrialTemperature()
*/
// ============================================================================
Standard_Real XSM_Elastic::GetTrialTemperature()
{
    return myTrialTemperature;
}

// ============================================================================
/*!
 *  \brief GetTrialTime()
*/
// ============================================================================
Standard_Real XSM_Elastic::GetTrialTime()
{
    return myTrialTime;
}

// ============================================================================
/*!
 *  \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean XSM_Elastic::RevertToCommitState()
{
    myTrialForce = myCommitForce;
    myTrialMechanicalStrain = myCommitMechanicalStrain;
    myTrialStiffness = myCommitStiffness;
    myTrialStrain = myCommitStrain;
    myTrialTemperature = myCommitTemperature;
    myTrialThermalStrain = myCommitThermalStrain;
    myTrialTime = myCommitTime;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean XSM_Elastic::RevertToInitialState()
{
    myCommitForce = 0.;
    myCommitMechanicalStrain = 0.;
    myCommitStiffness = 0.;
    myCommitStrain = 0.;
    myCommitTemperature = 0.;
    myCommitThermalStrain = 0.;
    myCommitTime = 0;
    myTrialForce = 0.;
    myTrialMechanicalStrain = 0.;
    myTrialStiffness = 0.;
    myTrialStrain = 0.;
    myTrialTemperature = 0.;
    myTrialThermalStrain = 0.;
    myTrialTime = 0.;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief SetTrialStrain()
*/
// ============================================================================
Standard_Boolean XSM_Elastic::SetTrialStrain(const Standard_Real theStrain)
{
    myTrialStrain = theStrain;
    return UpdateInternalState();
}

// ============================================================================
/*!
 *  \brief SetTrialTemperature()
*/
// ============================================================================
Standard_Boolean XSM_Elastic::SetTrialTemperature(const Standard_Real theTemperature)
{
    myTrialTemperature = theTemperature;
    return UpdateInternalState();
}

// ============================================================================
/*!
 *  \brief SetTrialTime()
*/
// ============================================================================
Standard_Boolean XSM_Elastic::SetTrialTime(const Standard_Real theTime)
{
    myTrialTime = theTime;
    return UpdateInternalState();
}

// ============================================================================
/*!
 *  \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean XSM_Elastic::UpdateInternalState()
{
    // compute thermal deformation
    myTrialThermalStrain = myCommitThermalStrain +
            myThermalExpansionCoef * (myTrialTemperature - myCommitTemperature);
    // compute mechanical deformation
    myTrialMechanicalStrain = myTrialStrain - myTrialThermalStrain;
    // compute mechnical force
    myTrialForce = myArea * myElasticModulous *
            (myTrialMechanicalStrain - myCommitMechanicalStrain) + myCommitForce;
    // compute trial stiffness
    myTrialStiffness = myArea * myElasticModulous;
    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(XSM_Elastic, XSM_Model)
IMPLEMENT_STANDARD_RTTIEXT(XSM_Elastic, XSM_Model)

