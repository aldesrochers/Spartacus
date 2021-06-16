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
#include <UCrM_CableWire01.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UCrM_CableWire01::UCrM_CableWire01(const Standard_Real K,
                                   const Standard_Real Phi,
                                   const Standard_Real Alpha)
    : myAlpha(Alpha), myK(K), myMu(0.), myPhi(Phi)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UCrM_CableWire01::UCrM_CableWire01(const Standard_Real K,
                                   const Standard_Real Phi,
                                   const Standard_Real Alpha,
                                   const Standard_Real Mu)
    : myAlpha(Alpha), myK(K), myMu(Mu), myPhi(Phi)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
UCrM_CableWire01::~UCrM_CableWire01()
{

}

// ============================================================================
/*!
    \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire01::UpdateInternalState()
{
    // Convert stresses from Pa to kg/mm2
    Standard_Real Sig0 = myCommitStress / (1E6 * 9.80665);
    Standard_Real Sig1 = myTrialStress / (1E6 * 9.80665);
    // Convert strains from m/m to mm/km
    Standard_Real Eps0 = myCommitStrain * 1E6;
    // Update internal state
    Standard_Real A = Pow(Eps0/myK, myMu);
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
IMPLEMENT_STANDARD_HANDLE(UCrM_CableWire01, UCrM_Model)
IMPLEMENT_STANDARD_RTTIEXT(UCrM_CableWire01, UCrM_Model)

