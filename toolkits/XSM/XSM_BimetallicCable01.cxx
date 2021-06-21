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
XSM_BimetallicCable01::XSM_BimetallicCable01(const Standard_Real theArea1,
                                             const Standard_Real theArea2,
                                             Handle(USSM_Model) theStressStrainModel1,
                                             Handle(USSM_Model) theStressStrainModel2,
                                             Handle(UThM_Model) theThermalModel1,
                                             Handle(UThM_Model) theThermalModel2,
                                             Handle(UCrM_Model) theCreepModel)
    : myArea1(theArea1),
      myArea2(theArea2),
      myStressStrainModel1(theStressStrainModel1),
      myStressStrainModel2(theStressStrainModel2),
      myThermalModel1(theThermalModel1),
      myThermalModel2(theThermalModel2),
      myCreepModel(theCreepModel)
{
    myMaxIterations = 10;
    myTolerance = 1E-6;
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
    myStressStrainModel1->CommitState();
    myStressStrainModel2->CommitState();
    myThermalModel1->CommitState();
    myThermalModel2->CommitState();
    myCreepModel->CommitState();
    // state
    myMustBeUpdated = Standard_False;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief GetCommitForce()
*/
// ============================================================================
Standard_Real XSM_BimetallicCable01::GetCommitForce()
{
    Standard_Real F = 0.;
    F += myArea1 * myStressStrainModel1->GetCommitStress();
    F += myArea2 * myStressStrainModel2->GetCommitStress();
    return F;
}

// ============================================================================
/*!
 *  \brief GetCommitStiffness()
*/
// ============================================================================
Standard_Real XSM_BimetallicCable01::GetCommitStiffness()
{
    Standard_Real K = 0.;
    K += myArea1 * myStressStrainModel1->GetCommitStiffness();
    K += myArea2 * myStressStrainModel2->GetCommitStiffness();
    return K;
}

// ============================================================================
/*!
 *  \brief GetCommitStrain()
*/
// ============================================================================
Standard_Real XSM_BimetallicCable01::GetCommitStrain()
{
    return myCommitStrain;
}

// ============================================================================
/*!
 *  \brief GetCommitTemperature()
*/
// ============================================================================
Standard_Real XSM_BimetallicCable01::GetCommitTemperature()
{
    return myCommitTemperature;
}

// ============================================================================
/*!
 *  \brief GetCommitTime()
*/
// ============================================================================
Standard_Real XSM_BimetallicCable01::GetCommitTime()
{
    return myCommitTime;
}

// ============================================================================
/*!
 *  \brief GetInitialStiffness()
*/
// ============================================================================
Standard_Real XSM_BimetallicCable01::GetInitialStiffness()
{
    Standard_Real K = 0.;
    K += myArea1 * myStressStrainModel1->GetInitialStiffness();
    K += myArea2 * myStressStrainModel2->GetInitialStiffness();
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
    F += myArea1 * myStressStrainModel1->GetTrialStress();
    F += myArea2 * myStressStrainModel2->GetTrialStress();
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
    K += myArea1 * myStressStrainModel1->GetTrialStiffness();
    K += myArea2 * myStressStrainModel2->GetTrialStiffness();
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
 *  \brief MustBeUpdated()
*/
// ============================================================================
Standard_Boolean XSM_BimetallicCable01::MustBeUpdated()
{
    return myMustBeUpdated;
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
    myStressStrainModel1->RevertToCommitState();
    myStressStrainModel2->RevertToCommitState();
    myThermalModel1->RevertToCommitState();
    myThermalModel2->RevertToCommitState();
    myCreepModel->RevertToCommitState();
    // state
    myMustBeUpdated = Standard_False;
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
    myStressStrainModel1->RevertToInitialState();
    myStressStrainModel2->RevertToInitialState();
    myThermalModel1->RevertToInitialState();
    myThermalModel2->RevertToInitialState();
    myCreepModel->RevertToInitialState();
    // state
    myMustBeUpdated = Standard_False;
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
    myMustBeUpdated = Standard_True;
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
    myMustBeUpdated = Standard_True;
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
    myMustBeUpdated = Standard_True;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean XSM_BimetallicCable01::UpdateInternalState()
{
    myTrialCreepStress = myCommitCreepStress;

    for (int i=0; i<myMaxIterations; i++) {
        // update thermal models
        myThermalModel1->SetTrialTemperature(myTrialTemperature);
        myThermalModel2->SetTrialTemperature(myTrialTemperature);
        myThermalModel1->UpdateInternalState();
        myThermalModel2->UpdateInternalState();
        // update creep models
        myCreepModel->SetTrialStress(myTrialCreepStress);
        myCreepModel->SetTrialTemperature(myTrialTemperature);
        myCreepModel->SetTrialTime(myTrialTime);
        myCreepModel->UpdateInternalState();
        // compute mechanical strains
        Standard_Real EpsMech1 = myTrialStrain
                - myThermalModel1->GetTrialStrain()
                - myCreepModel->GetTrialStrain();
        Standard_Real EpsMech2 = myTrialStrain
                - myThermalModel2->GetTrialStrain()
                - myCreepModel->GetTrialStrain();
        // update stress-strain models
        myStressStrainModel1->SetTrialStrain(EpsMech1);
        myStressStrainModel2->SetTrialStrain(EpsMech2);
        myStressStrainModel1->UpdateInternalState();
        myStressStrainModel2->UpdateInternalState();
        // check for equilibrium
        Standard_Real F1 = myTrialCreepStress * (myArea1 + myArea2);
        Standard_Real F2 = myArea1 * myStressStrainModel1->GetTrialStress();
        Standard_Real F3 = myArea2 * myStressStrainModel2->GetTrialStress();
        Standard_Real R = F2 + F3 - F1;
        // check if within  tolerance
        if(Abs(R) < myTolerance) {
            myMustBeUpdated = Standard_False;
            return Standard_True;
        }
        // compute equilibrium derivative
        Standard_Real D1 = myStressStrainModel1->GetTrialStiffness()
                * -1. * myCreepModel->GetTrialStressGrowthRate();
        Standard_Real D2 = myStressStrainModel2->GetTrialStiffness()
                * -1. * myCreepModel->GetTrialStressGrowthRate();
        Standard_Real dR = D1 * myArea1 + D2 * myArea2 - (myArea1 + myArea2);
        // update trial creep stress
        myTrialCreepStress = myTrialCreepStress - R/dR;


    }

    return Standard_False;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(XSM_BimetallicCable01, XSM_Model)
IMPLEMENT_STANDARD_RTTIEXT(XSM_BimetallicCable01, XSM_Model)

