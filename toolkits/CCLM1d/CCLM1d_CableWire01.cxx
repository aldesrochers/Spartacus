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


// CCLM1d
#include <CCLM1d_CableWire01.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
CCLM1d_CableWire01::CCLM1d_CableWire01(const Standard_Real K,
                                       const Standard_Real Phi,
                                       const Standard_Real Alpha,
                                       const Standard_Real Mu)
    : myK(K), myPhi(Phi), myAlpha(Alpha), myMu(Mu)
{
    RevertToInitialState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
CCLM1d_CableWire01::~CCLM1d_CableWire01()
{

}

// ============================================================================
/*!
 *  \brief CommitState()
*/
// ============================================================================
Standard_Boolean CCLM1d_CableWire01::CommitState()
{
    myCommitStrain = myTrialStrain;
    myCommitStress = myTrialStress;
    myCommitTemperature = myTrialTemperature;
    myCommitTime = myTrialTime;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real CCLM1d_CableWire01::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
 *  \brief GetTrialStress()
*/
// ============================================================================
Standard_Real CCLM1d_CableWire01::GetTrialStress()
{
    return myTrialStress;
}

// ============================================================================
/*!
 *  \brief GetTrialTemperature()
*/
// ============================================================================
Standard_Real CCLM1d_CableWire01::GetTrialTemperature()
{
    return myTrialTemperature;
}

// ============================================================================
/*!
 *  \brief GetTrialTime()
*/
// ============================================================================
Standard_Real CCLM1d_CableWire01::GetTrialTime()
{
    return myTrialTime;
}

// ============================================================================
/*!
 *  \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean CCLM1d_CableWire01::RevertToCommitState()
{
    myTrialStrain = myCommitStrain;
    myTrialStress = myCommitStress;
    myTrialTemperature = myCommitTemperature;
    myTrialTime = myCommitTime;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean CCLM1d_CableWire01::RevertToInitialState()
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
 *  \brief SetTrialStress()
*/
// ============================================================================
Standard_Boolean CCLM1d_CableWire01::SetTrialStress(const Standard_Real theStress)
{
    myTrialStress = theStress;
    return UpdateInternalState();
}

// ============================================================================
/*!
 *  \brief SetTrialTemperature()
*/
// ============================================================================
Standard_Boolean CCLM1d_CableWire01::SetTrialTemperature(const Standard_Real theTemperature)
{
    myTrialTemperature = theTemperature;
    return UpdateInternalState();
}

// ============================================================================
/*!
 *  \brief SetTrialTime()
*/
// ============================================================================
Standard_Boolean CCLM1d_CableWire01::SetTrialTime(const Standard_Real theTime)
{
    myTrialTime = theTime;
    return UpdateInternalState();
}

#include <iostream>
using namespace std;

// ============================================================================
/*!
 *  \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean CCLM1d_CableWire01::UpdateInternalState()
{
    // Convert stresses from Pa to kg/mm2
    Standard_Real Sig0 = myCommitStress / (1E6 * 9.80665);
    Standard_Real Sig1 = myTrialStress / (1E6 * 9.80665);
    // Convert strains from m/m to mm/km
    Standard_Real Eps0 = myCommitStrain * 1E6;
    Standard_Real Eps1 = myTrialStrain * 1E6;
    // Update internal state
    Standard_Real A = Pow(myCommitStrain/myK, myMu);
    Standard_Real FT0 = Exp(myPhi/myMu*myCommitTemperature)
            * Pow(Sig0, myAlpha/myMu);
    Standard_Real FT1 = Exp(myPhi/myMu*myTrialTemperature)
            * Pow(Sig1, myAlpha/myMu);
    Standard_Real dA = (myTrialTime - myCommitTime) * (FT1 + FT0)/2.;
    Standard_Real Eps = myK * Pow(A + dA, myMu);
    // Update internal strain in (m/m)
    myTrialStrain = Eps / 1E6;
    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(CCLM1d_CableWire01, CCLM1d_Model)
IMPLEMENT_STANDARD_RTTIEXT(CCLM1d_CableWire01, CCLM1d_Model)

