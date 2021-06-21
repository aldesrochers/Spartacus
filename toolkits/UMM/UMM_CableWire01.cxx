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
#include <UMM_CableWire01.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UMM_CableWire01::UMM_CableWire01(const mmp_CableWireStressStrain01& StressStrainParameters,
                                 const mmp_CableWireCreep01& CreepParameters,
                                 const Standard_Real Alpha)
    : myAlpha(Alpha),
      myCreepParameters(CreepParameters),
      myStressStrainParameters(StressStrainParameters)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
UMM_CableWire01::~UMM_CableWire01()
{

}

// ============================================================================
/*!
    \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean UMM_CableWire01::UpdateInternalState()
{
    // update thermal strain
    myTrialThermalStrain = myCommitThermalStrain +
            myAlpha * (myTrialTemperature - myCommitTemperature);

    // update stress strain
    myTrialStressStrain = myTrialStrain - myTrialThermalStrain;

    // forward loading
    Standard_Real EpsMax = myStressStrainParameters.EpsMax();

    if(myTrialStressStrain > myCommitStrain) {
        if(myTrialStressStrain > myMaxStrain) {
            if(myTrialStressStrain > EpsMax) {
                Standard_Real Kt = PolynomialCurveDerivative(EpsMax);
                myTrialStress = myCommitStress
                        + Kt * (myTrialStressStrain - myCommitStressStrain);
            } else {
                return PolynomialCurveFunction(myTrialStressStrain);
            }
        }
    }



    // update trial creep strain
    Standard_Real K = myCreepParameters.K();
    Standard_Real Phi = myCreepParameters.Phi();
    Standard_Real Alpha = myCreepParameters.Alpha();
    Standard_Real Mu = myCreepParameters.Mu();
    Standard_Real FC0 = Exp(Phi/Mu*myCommitTemperature)
            * Pow(myCommitStress, Alpha/Mu);
    Standard_Real FC1 = Exp(Phi/Mu*myTrialTemperature)
            * Pow(myTrialStress, Alpha/Mu);
    Standard_Real C = Pow(myCommitCreepStrain/K, Mu);
    Standard_Real dC = (myTrialTime - myCommitTime) * (FC1+FC0)/2.;
    //myTrialCreepStrain = K * Pow(C + dC, Mu);


}

// ============================================================================
/*!
    \brief PolynomialCurveDerivative()
*/
// ============================================================================
Standard_Real UMM_CableWire01::PolynomialCurveDerivative(const Standard_Real StressStrain)
{
    Standard_Real Eps = StressStrain;
    Standard_Real Ei  = myStressStrainParameters.Ei();
    Standard_Real A1 = myStressStrainParameters.A1();
    Standard_Real A2 = myStressStrainParameters.A2();
    Standard_Real A3 = myStressStrainParameters.A3();
    Standard_Real A4 = myStressStrainParameters.A4();
    Standard_Real A5 = myStressStrainParameters.A5();
    Standard_Real A6 = myStressStrainParameters.A6();
    Standard_Real D = 1.*A1 * Pow(Eps, 0.) + 2.*A2 * Pow(Eps, 1.)
            + 3.*A3 * Pow(Eps, 2) + 4.*A4 * Pow(Eps, 3.) + 5.*A5 * Pow(Eps, 4.)
            + 6.*A6 * Pow(Eps, 5.);
    return D * Ei;
}

// ============================================================================
/*!
    \brief PolynomialCurveFunction()
*/
// ============================================================================
Standard_Real UMM_CableWire01::PolynomialCurveFunction(const Standard_Real StressStrain)
{
    Standard_Real Eps = StressStrain;
    Standard_Real Ei  = myStressStrainParameters.Ei();
    Standard_Real A0 = myStressStrainParameters.A0();
    Standard_Real A1 = myStressStrainParameters.A1();
    Standard_Real A2 = myStressStrainParameters.A2();
    Standard_Real A3 = myStressStrainParameters.A3();
    Standard_Real A4 = myStressStrainParameters.A4();
    Standard_Real A5 = myStressStrainParameters.A5();
    Standard_Real A6 = myStressStrainParameters.A6();
    Standard_Real P = A0 + A1 * Pow(Eps, 1.) + A2 * Pow(Eps, 2.)
            + A3 * Pow(Eps, 3) + A4 * Pow(Eps, 4.) + A5 * Pow(Eps, 5.)
            + A6 * Pow(Eps, 6.);
    return P * Ei;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(UMM_CableWire01, UMM_Model)
IMPLEMENT_STANDARD_RTTIEXT(UMM_CableWire01, UMM_Model)

