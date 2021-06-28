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
#include <XSM_BimetallicCable01.hxx>

// OpenCascade
#include <Precision.hxx>

#include <iostream>
using namespace std;


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
XSM_BimetallicCable01::XSM_BimetallicCable01(const XSMP_BimetallicCable01& theParameters,
                                             const Standard_Real theTolerance,
                                             const Standard_Integer theMaxNbIterations)
    : myParameters(theParameters),
      myTolerance(theTolerance),
      myMaxNbIterations(theMaxNbIterations)
{
    RevertToInitialState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
XSM_BimetallicCable01::~XSM_BimetallicCable01()
{

}

// ============================================================================
/*!
 *  \brief CommitState()
*/
// ============================================================================
Standard_Boolean XSM_BimetallicCable01::CommitState()
{
    // commit internal history
    myCommitCreepStress = myTrialCreepStress;
    myCommitStrain = myTrialStrain;
    myCommitTemperature = myTrialTemperature;
    myCommitTime = myTrialTime;
    // commit models
    myParameters.StressStrainModel1()->CommitState();
    myParameters.StressStrainModel2()->CommitState();
    myParameters.ThermalModel1()->CommitState();
    myParameters.ThermalModel2()->CommitState();
    myParameters.CreepModel1()->CommitState();
    myParameters.CreepModel2()->CommitState();
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief GetInitialStiffness()
*/
// ============================================================================
Standard_Real XSM_BimetallicCable01::GetInitialStiffness()
{
    Standard_Real K = 0.;
    K += myParameters.Area1() * myParameters.StressStrainModel1()->GetInitialStiffness();
    K += myParameters.Area2() * myParameters.StressStrainModel2()->GetInitialStiffness();
    return K;
}

// ============================================================================
/*!
 *  \brief GetTrialForce()
*/
// ============================================================================
Standard_Real XSM_BimetallicCable01::GetTrialForce()
{
    Standard_Real F = 0.;
    F += myParameters.Area1() * myParameters.StressStrainModel1()->GetTrialStress();
    F += myParameters.Area2() * myParameters.StressStrainModel2()->GetTrialStress();
    return F;
}

// ============================================================================
/*!
 *  \brief GetTrialStiffness()
*/
// ============================================================================
Standard_Real XSM_BimetallicCable01::GetTrialStiffness()
{
    Standard_Real K = 0.;
    K += myParameters.Area1() * myParameters.StressStrainModel1()->GetTrialStiffness();
    K += myParameters.Area2() * myParameters.StressStrainModel2()->GetTrialStiffness();
    return K;
}

// ============================================================================
/*!
 *  \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real XSM_BimetallicCable01::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
 *  \brief GetTrialTemperature()
*/
// ============================================================================
Standard_Real XSM_BimetallicCable01::GetTrialTemperature()
{
    return myTrialTemperature;
}

// ============================================================================
/*!
 *  \brief GetTrialTime()
*/
// ============================================================================
Standard_Real XSM_BimetallicCable01::GetTrialTime()
{
    return myTrialTime;
}

// ============================================================================
/*!
 *  \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean XSM_BimetallicCable01::RevertToCommitState()
{
    // revert internal history
    myTrialCreepStress = myCommitCreepStress;
    myTrialStrain = myCommitStrain;
    myTrialTemperature = myCommitTemperature;
    myTrialTime = myCommitTime;
    // revert models
    myParameters.StressStrainModel1()->RevertToCommitState();
    myParameters.StressStrainModel2()->RevertToCommitState();
    myParameters.ThermalModel1()->RevertToCommitState();
    myParameters.ThermalModel2()->RevertToCommitState();
    myParameters.CreepModel1()->RevertToCommitState();
    myParameters.CreepModel2()->RevertToCommitState();
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean XSM_BimetallicCable01::RevertToInitialState()
{
    // revert internal history
    myCommitCreepStress = 0.;
    myCommitStrain = 0.;
    myCommitTemperature = 0.;
    myCommitTime = 0.;
    myTrialCreepStress = 0.;
    myTrialStrain = 0.;
    myTrialTemperature = 0.;
    myTrialTime = 0.;
    // revert models
    myParameters.StressStrainModel1()->RevertToInitialState();
    myParameters.StressStrainModel2()->RevertToInitialState();
    myParameters.ThermalModel1()->RevertToInitialState();
    myParameters.ThermalModel2()->RevertToInitialState();
    myParameters.CreepModel1()->RevertToInitialState();
    myParameters.CreepModel2()->RevertToInitialState();
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief SetTrialStrain()
*/
// ============================================================================
Standard_Boolean XSM_BimetallicCable01::SetTrialStrain(const Standard_Real theStrain)
{
    myTrialStrain = theStrain;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief SetTrialTemperature()
*/
// ============================================================================
Standard_Boolean XSM_BimetallicCable01::SetTrialTemperature(const Standard_Real theTemperature)
{
    myTrialTemperature = theTemperature;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief SetTrialTime()
*/
// ============================================================================
Standard_Boolean XSM_BimetallicCable01::SetTrialTime(const Standard_Real theTime)
{
    myTrialTime = theTime;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean XSM_BimetallicCable01::UpdateInternalState()
{
    // ***
    // 1st material equilibrium
    // ***
    Standard_Real SigCreep1 = 0.;
    for(int i=0; i<myMaxNbIterations; i++) {
        // update thermal model
        myParameters.ThermalModel1()->SetTrialTemperature(myTrialTemperature);
        // update creep model
        myParameters.CreepModel1()->SetTrialStress(SigCreep1);
        myParameters.CreepModel1()->SetTrialTemperature(myTrialTemperature);
        myParameters.CreepModel1()->SetTrialTime(myTrialTime);
        // compute mechanical strain
        Standard_Real EpsMech = myTrialStrain
                - myParameters.ThermalModel1()->GetTrialStrain()
                - myParameters.CreepModel1()->GetTrialStrain();
        // update stress/strain model
        myParameters.StressStrainModel1()->SetTrialStrain(EpsMech);
        // compute stress/strain stress
        Standard_Real SigMech = myParameters.StressStrainModel1()->GetTrialStress();
        // check if within  tolerance
        Standard_Real R = SigCreep1 - SigMech;
        if(Abs(R) < myTolerance) {
            break;
        }
        // update trial
        Standard_Real D = 1. + myParameters.StressStrainModel1()->GetTrialStiffness()
                * myParameters.CreepModel1()->GetTrialStressGrowthRate();
        // update trial creep stress
        SigCreep1 = SigCreep1 - R/D;
    }

    // ***
    // 2nd material equilibrium
    // ***
    Standard_Real SigCreep2 = 0.;
    for(int i=0; i<myMaxNbIterations; i++) {
        // update thermal model
        myParameters.ThermalModel2()->SetTrialTemperature(myTrialTemperature);
        // update creep model
        myParameters.CreepModel2()->SetTrialStress(SigCreep2);
        myParameters.CreepModel2()->SetTrialTemperature(myTrialTemperature);
        myParameters.CreepModel2()->SetTrialTime(myTrialTime);
        // compute mechanical strain
        Standard_Real EpsMech = myTrialStrain
                - myParameters.ThermalModel2()->GetTrialStrain()
                - myParameters.CreepModel2()->GetTrialStrain();
        // update stress/strain model
        myParameters.StressStrainModel2()->SetTrialStrain(EpsMech);
        // compute stress/strain stress
        Standard_Real SigMech = myParameters.StressStrainModel2()->GetTrialStress();
        // check if within  tolerance
        Standard_Real R = SigCreep2 - SigMech;
        if(Abs(R) < myTolerance) {
            break;
        }
        // update trial
        Standard_Real D = 1. + myParameters.StressStrainModel2()->GetTrialStiffness()
                * myParameters.CreepModel2()->GetTrialStressGrowthRate();
        // update trial creep stress
        SigCreep2 = SigCreep2 - R/D;
    }

    return Standard_False;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(XSM_BimetallicCable01, XSM_Model)
IMPLEMENT_STANDARD_RTTIEXT(XSM_BimetallicCable01, XSM_Model)

