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
#include <UCrM_CableCreep01.hxx>

// OpenCascade
#include <Precision.hxx>

#include <iostream>
using namespace std;


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UCrM_CableCreep01::UCrM_CableCreep01(const mmp_CableCreep01& theParameters)
    : myParameters(theParameters)
{
    RevertToInitialState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
UCrM_CableCreep01::~UCrM_CableCreep01()
{

}

// ============================================================================
/*!
 *  Parameters()
*/
// ============================================================================
UCrM_CableCreep01::UCrM_Coefficients UCrM_CableCreep01::Coefficients(const Standard_Real Sig)
{
    UCrM_Coefficients Coeffs;
    if(Sig < myParameters.Sig0()) {
        Coeffs.A = 0.;
        Coeffs.B = 0.;
        Coeffs.C = 0.;
        Coeffs.D = 0.;
    } else if(Sig < myParameters.Sig1()) {
        Coeffs.A = (myParameters.A1() - myParameters.A0())
                / (myParameters.Sig1() - myParameters.Sig0());
        Coeffs.B = myParameters.A0();
        Coeffs.C = (myParameters.B1() - myParameters.B0())
                / (myParameters.Sig1() - myParameters.Sig0());
        Coeffs.D = myParameters.B0();
    } else if(Sig < myParameters.Sig2()) {
        Coeffs.A = (myParameters.A2() - myParameters.A1())
                / (myParameters.Sig2() - myParameters.Sig1());
        Coeffs.B = myParameters.A1();
        Coeffs.C = (myParameters.B2() - myParameters.B1())
                / (myParameters.Sig2() - myParameters.Sig1());
        Coeffs.D = myParameters.B1();
    } else if(Sig < myParameters.Sig3()) {
        Coeffs.A = (myParameters.A3() - myParameters.A2())
                / (myParameters.Sig3() - myParameters.Sig2());
        Coeffs.B = myParameters.A2();
        Coeffs.C = (myParameters.B3() - myParameters.B2())
                / (myParameters.Sig3() - myParameters.Sig2());
        Coeffs.D = myParameters.B2();
    } else {
        Coeffs.A = (myParameters.A3() - myParameters.A2())
                / (myParameters.Sig3() - myParameters.Sig2());
        Coeffs.B = myParameters.A3();
        Coeffs.C = (myParameters.B3() - myParameters.B2())
                / (myParameters.Sig3() - myParameters.Sig2());
        Coeffs.D = myParameters.B3();
    }
    return Coeffs;
}

// ============================================================================
/*!
 *  \brief CreepEquivalentTime()
*/
// ============================================================================
Standard_Real UCrM_CableCreep01::CreepEquivalentTime(const Standard_Real Temp,
                                                     const Standard_Real Sig,
                                                     const Standard_Real Eps)
{
    if(F1(Sig) <= 0.)
        return 0.;
    Standard_Real cf1 = exp(myParameters.Phi() * (Temp - myParameters.T0()));
    Standard_Real cf2 = F1(Sig);
    return Pow((Eps/(cf1*cf2)), 1./F2(Sig));
}

// ============================================================================
/*!
 *  \brief CreepFunction()
*/
// ============================================================================
Standard_Real UCrM_CableCreep01::CreepFunction(const Standard_Real Temp,
                                               const Standard_Real Sig,
                                               const Standard_Real Time)
{
    Standard_Real cf1 = exp(myParameters.Phi() * (Temp - myParameters.T0()));
    Standard_Real cf2 = F1(Sig);
    Standard_Real cf3 = Pow(Time, F2(Sig));
    return cf1 * cf2 * cf3;
}

// ============================================================================
/*!
 *  \brief CreepFunctionStressRate()
*/
// ============================================================================
Standard_Real UCrM_CableCreep01::CreepFunctionStressRate(const Standard_Real Temp,
                                                         const Standard_Real Sig,
                                                         const Standard_Real Time)
{
    UCrM_Coefficients Coeffs = Coefficients(Sig);
    Standard_Real cf1 = exp(myParameters.Phi() * (Temp - myParameters.T0()));
    Standard_Real cf2 = Pow(Time, F2(Sig));
    Standard_Real cf3;
    if(Time <= Precision::Confusion()) {
        cf3 = Coeffs.A * Coeffs.C * log(Precision::Confusion()) * Sig
                + Coeffs.B * Coeffs.C * log(Precision::Confusion()) + Coeffs.A;
    } else {
        cf3 = Coeffs.A * Coeffs.C * log(Time) * Sig
                + Coeffs.B * Coeffs.C * log(Time) + Coeffs.A;
    }
    return cf1 * cf2 * cf3;
}

// ============================================================================
/*!
 *  \brief CreepFunctionTemperatureRate()
*/
// ============================================================================
Standard_Real UCrM_CableCreep01::CreepFunctionTemperatureRate(const Standard_Real Temp,
                                                              const Standard_Real Sig,
                                                              const Standard_Real Time)
{
    Standard_Real cf1 = myParameters.Phi()
            * exp(myParameters.Phi() * (Temp - myParameters.T0()));
    Standard_Real cf2 = F1(Sig);
    Standard_Real cf3 = Pow(Time, F2(Sig));
    return cf1 * cf2 * cf3;
}

// ============================================================================
/*!
 *  \brief CreepFunctionTimeRate()
*/
// ============================================================================
Standard_Real UCrM_CableCreep01::CreepFunctionTimeRate(const Standard_Real Temp,
                                                       const Standard_Real Sig,
                                                       const Standard_Real Time)
{
    UCrM_Coefficients Coeffs = Coefficients(Sig);
    Standard_Real cf1 = exp(myParameters.Phi() * (Temp - myParameters.T0()));
    Standard_Real cf2 = F1(Sig) * F2(Sig);
    Standard_Real cf3 = Pow(Time, F2(Sig) - 1.);
    return cf1 * cf2 * cf3;
}

// ============================================================================
/*!
 *  \brief F1()
*/
// ============================================================================
Standard_Real UCrM_CableCreep01::F1(const Standard_Real Sig)
{
    UCrM_Coefficients Coeffs = Coefficients(Sig);
    if(Sig < myParameters.Sig0()) {
        return 0.;
    } else if(Sig < myParameters.Sig1()) {
        return Coeffs.A * (Sig - myParameters.Sig0()) + Coeffs.B;
    } else if(Sig < myParameters.Sig2()) {
        return Coeffs.A * (Sig - myParameters.Sig1()) + Coeffs.B;
    } else if(Sig < myParameters.Sig3()) {
        return Coeffs.A * (Sig - myParameters.Sig2()) + Coeffs.B;
    } else {
        return Coeffs.A * (Sig - myParameters.Sig3()) + Coeffs.B;
    }
}

// ============================================================================
/*!
 *  \brief F2()
*/
// ============================================================================
Standard_Real UCrM_CableCreep01::F2(const Standard_Real Sig)
{
    UCrM_Coefficients Coeffs = Coefficients(Sig);
    if(Sig < myParameters.Sig0()) {
        return 0.;
    } else if(Sig < myParameters.Sig1()) {
        return Coeffs.C * (Sig - myParameters.Sig0()) + Coeffs.D;
    } else if(Sig < myParameters.Sig2()) {
        return Coeffs.C * (Sig - myParameters.Sig1()) + Coeffs.D;
    } else if(Sig < myParameters.Sig3()) {
        return Coeffs.C * (Sig - myParameters.Sig2()) + Coeffs.D;
    } else {
        return Coeffs.C * (Sig - myParameters.Sig3()) + Coeffs.D;
    }
}

// ============================================================================
/*!
    \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean UCrM_CableCreep01::UpdateInternalState()
{
    // compute 'equivalent' time based on deformation history and current
    // trial loading conditions
    Standard_Real teq = CreepEquivalentTime(myTrialTemperature,
                                            myTrialStress,
                                            myCommitStrain);

    // update time history
    Standard_Real th = teq + (myTrialTime - myCommitTime);

    // update trial strain
    myTrialStrain = CreepFunction(myTrialTemperature,
                                  myTrialStress,
                                  th);

    // update stress growth rate
    myTrialStressGrowthRate = CreepFunctionStressRate(myTrialTemperature,
                                                      myTrialStress,
                                                      th);

    // update temperature growth rate
    myTrialTemperatureGrowthRate = CreepFunctionTemperatureRate(myTrialTemperature,
                                                                myTrialStress,
                                                                th);

    // update time growth rate
    myTrialTimeGrowthRate = CreepFunctionTimeRate(myTrialTemperature,
                                                  myTrialStress,
                                                  th);

    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(UCrM_CableCreep01, UCrM_Model)
IMPLEMENT_STANDARD_RTTIEXT(UCrM_CableCreep01, UCrM_Model)

