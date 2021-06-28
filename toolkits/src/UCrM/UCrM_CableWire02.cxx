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

#include <iostream>
using namespace std;

// Spartacus
#include <UCrM_CableWire02.hxx>

// OpenCascade
#include <Precision.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UCrM_CableWire02::UCrM_CableWire02(const UCrMP_CableWire02& theParameters)
    : myParameters(theParameters)
{
    UCrM_CableWire02::RevertToInitialState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
UCrM_CableWire02::~UCrM_CableWire02()
{

}

// ============================================================================
/*!
    \brief CommitState()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire02::CommitState()
{
    myCommitStrain = myTrialStrain;
    myCommitTime = myTrialTime;
    return Standard_True;
}

// ============================================================================
/*!
    \brief F1()
*/
// ============================================================================
Standard_Real UCrM_CableWire02::F1(const Standard_Real Eps)
{
    if(Eps <= myParameters.Eps0()) {
        return 0.;
    } else if(Eps <= myParameters.Eps1()) {
        return (myParameters.A1()-myParameters.A0())
                /(myParameters.Eps1()-myParameters.Eps0());
    } else if(Eps <= myParameters.Eps2()) {
        return (myParameters.A2()-myParameters.A1())
                /(myParameters.Eps2()-myParameters.Eps1());
    } else if(Eps <= myParameters.Eps3()) {
        return (myParameters.A3()-myParameters.A2())
                /(myParameters.Eps3()-myParameters.Eps2());
    } else {
        return (myParameters.A3()-myParameters.A2())
                /(myParameters.Eps3()-myParameters.Eps2());
    }
}

// ============================================================================
/*!
    \brief F2()
*/
// ============================================================================
Standard_Real UCrM_CableWire02::F2(const Standard_Real Eps)
{
    if(Eps <= myParameters.Eps0()) {
        return 0.;
    } else if(Eps <= myParameters.Eps1()) {
        return myParameters.A0();
    } else if(Eps <= myParameters.Eps2()) {
        return myParameters.A1();
    } else if(Eps <= myParameters.Eps3()) {
        return myParameters.A2();
    } else {
        return myParameters.A3();
    }
}

// ============================================================================
/*!
    \brief F3()
*/
// ============================================================================
Standard_Real UCrM_CableWire02::F3(const Standard_Real Eps)
{
    if(Eps <= myParameters.Eps0()) {
        return 0.;
    } else if(Eps <= myParameters.Eps1()) {
        return (myParameters.B1()-myParameters.B0())
                /(myParameters.Eps1()-myParameters.Eps0());
    } else if(Eps <= myParameters.Eps2()) {
        return (myParameters.B2()-myParameters.B1())
                /(myParameters.Eps2()-myParameters.Eps1());
    } else if(Eps <= myParameters.Eps3()) {
        return (myParameters.B3()-myParameters.B2())
                /(myParameters.Eps3()-myParameters.Eps2());
    } else {
        return (myParameters.B3()-myParameters.B2())
                /(myParameters.Eps3()-myParameters.Eps2());
    }
}

// ============================================================================
/*!
    \brief F4()
*/
// ============================================================================
Standard_Real UCrM_CableWire02::F4(const Standard_Real Eps)
{
    if(Eps <= myParameters.Eps0()) {
        return 0.;
    } else if(Eps <= myParameters.Eps1()) {
        return myParameters.B0();
    } else if(Eps <= myParameters.Eps2()) {
        return myParameters.B1();
    } else if(Eps <= myParameters.Eps3()) {
        return myParameters.B2();
    } else {
        return myParameters.B3();
    }
}

// ============================================================================
/*!
    \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real UCrM_CableWire02::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
    \brief GetTrialStress()
*/
// ============================================================================
Standard_Real UCrM_CableWire02::GetTrialStress()
{
    return myTrialStress;
}

// ============================================================================
/*!
    \brief GetTrialStressGrowthRate()
*/
// ============================================================================
Standard_Real UCrM_CableWire02::GetTrialStressGrowthRate()
{
    return myTrialStressGrowthRate;
}

// ============================================================================
/*!
    \brief GetTrialTemperature()
*/
// ============================================================================
Standard_Real UCrM_CableWire02::GetTrialTemperature()
{
    return myTrialTemperature;
}

// ============================================================================
/*!
    \brief GetTrialTemperatureGrowthRate()
*/
// ============================================================================
Standard_Real UCrM_CableWire02::GetTrialTemperatureGrowthRate()
{
        return myTrialTemperatureGrowthRate;
}

// ============================================================================
/*!
    \brief GetTrialTime()
*/
// ============================================================================
Standard_Real UCrM_CableWire02::GetTrialTime()
{
    return myTrialTime;
}

// ============================================================================
/*!
    \brief GetTrialTimeGrowthRate()
*/
// ============================================================================
Standard_Real UCrM_CableWire02::GetTrialTimeGrowthRate()
{
    return myTrialTimeGrowthRate;
}

// ============================================================================
/*!
    \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire02::RevertToCommitState()
{
    myTrialStrain = myCommitStrain;
    myTrialTime = myCommitTime;
    return Standard_True;
}

// ============================================================================
/*!
    \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire02::RevertToInitialState()
{
    myCommitStrain = 0.;
    myCommitTime = 0.;
    myTrialStrain = 0.;
    myTrialTime = 0.;
    return Standard_True;
}

// ============================================================================
/*!
    \brief SetTrialStress()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire02::SetTrialStress(const Standard_Real theStress)
{
    myTrialStress = theStress;
    return UpdateInternalState();
}

// ============================================================================
/*!
    \brief SetTrialTemperature()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire02::SetTrialTemperature(const Standard_Real theTemperature)
{
    myTrialTemperature = theTemperature;
    return UpdateInternalState();
}

// ============================================================================
/*!
    \brief SetTrialTime()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire02::SetTrialTime(const Standard_Real theTime)
{
    myTrialTime = theTime;
    return UpdateInternalState();
}

// ============================================================================
/*!
    \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire02::UpdateInternalState()
{
    // compute Eps
    Standard_Real Eps = myTrialStress / myParameters.E();

    // compute functions
    Standard_Real f1, f2;
    if(Eps < myParameters.Eps1()) {
        f1 = F1(Eps) * (Eps-myParameters.Eps0()) + F2(Eps);
        f2 = F3(Eps) * (Eps-myParameters.Eps0()) + F4(Eps);
    } else if(Eps < myParameters.Eps2()) {
        f1 = F1(Eps) * (Eps-myParameters.Eps1()) + F2(Eps);
        f2 = F3(Eps) * (Eps-myParameters.Eps1()) + F4(Eps);
    } else if(Eps < myParameters.Eps3()) {
        f1 = F1(Eps) * (Eps-myParameters.Eps2()) + F2(Eps);
        f2 = F3(Eps) * (Eps-myParameters.Eps2()) + F4(Eps);
    } else {
        f1 = F1(Eps) * (Eps-myParameters.Eps3()) + F2(Eps);
        f2 = F3(Eps) * (Eps-myParameters.Eps3()) + F4(Eps);
    }

    Standard_Real f3 = Exp(myParameters.C()
                           * (myTrialTemperature - myParameters.T0()));

    // compute equivalent time
    Standard_Real tEq = Pow(myCommitStrain/(f1*f3), 1./f2)
            + (myTrialTime - myCommitTime);

    // update current strain
    myTrialStrain = f1*f3*Pow(tEq, f2);

    // update growth rates
    if(!UpdateTrialStressGrowthRate(tEq, Eps))
        return Standard_False;
    if(!UpdateTrialTemperatureGrowthRate(tEq, Eps))
        return Standard_False;
    if(!UpdateTrialTimeGrowthRate(tEq, Eps))
        return Standard_False;

    return Standard_True;
}

// ============================================================================
/*!
    \brief UpdateTrialStressGrowthRate()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire02::UpdateTrialStressGrowthRate(const Standard_Real tEq,
                                                               const Standard_Real Eps)
{
    Standard_Real tEqC = tEq;
    Standard_Real EpsC = Eps;
    if(Eps <= 0.)
        EpsC = 1./Precision::Infinite();
    if(tEq <= 0.)
        tEqC = 1./Precision::Infinite();

    Standard_Real e1 = Exp(myParameters.C()
                           * (myTrialTemperature - myParameters.T0()));
    Standard_Real e2, e3;
    if(EpsC < myParameters.Eps1()) {
        e2 = Pow(tEqC, F3(EpsC) * (EpsC-myParameters.Eps0()) + F4(EpsC));
        e3 = F1(EpsC)*F3(EpsC)*Log(tEqC)*(EpsC-myParameters.Eps0())
                + F2(EpsC)*F3(EpsC)*Log(tEqC) + F1(EpsC);
    } else if(Eps < myParameters.Eps2()) {
        e2 = Pow(tEqC, F3(EpsC) * (EpsC-myParameters.Eps1()) + F4(EpsC));
        e3 = F1(EpsC)*F3(EpsC)*Log(tEqC)*(EpsC-myParameters.Eps1())
                + F2(EpsC)*F3(EpsC)*Log(tEqC) + F1(EpsC);
    } else if(Eps < myParameters.Eps3()) {
        e2 = Pow(tEqC, F3(EpsC) * (EpsC-myParameters.Eps2()) + F4(EpsC));
        e3 = F1(EpsC)*F3(EpsC)*Log(tEqC)*(EpsC-myParameters.Eps2())
                + F2(EpsC)*F3(EpsC)*Log(tEqC) + F1(EpsC);
    } else {
        e2 = Pow(tEqC, F3(EpsC) * (EpsC-myParameters.Eps3()) + F4(EpsC));
        e3 = F1(EpsC)*F3(EpsC)*Log(tEqC)*(EpsC-myParameters.Eps3())
                + F2(EpsC)*F3(EpsC)*Log(tEqC) + F1(EpsC);
    }

    myTrialStressGrowthRate = e1 * e2 * e3;
    return Standard_True;
}

// ============================================================================
/*!
    \brief UpdateTrialTemperatureGrowthRate()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire02::UpdateTrialTemperatureGrowthRate(const Standard_Real tEq,
                                                                    const Standard_Real Eps)
{
    Standard_Real e1 = myParameters.C() * Exp(myParameters.C()
                           * (myTrialTemperature - myParameters.T0()));

    Standard_Real e2, e3;
    if(Eps < myParameters.Eps1()) {
        e2 = Pow(tEq, F3(Eps) * (Eps-myParameters.Eps0()) + F4(Eps));
        e3 = F1(Eps) * (Eps-myParameters.Eps0()) + F2(Eps);
    } else if(Eps < myParameters.Eps2()) {
        e2 = Pow(tEq, F3(Eps) * (Eps-myParameters.Eps1()) + F4(Eps));
        e3 = F1(Eps) * (Eps-myParameters.Eps1()) + F2(Eps);
    } else if(Eps < myParameters.Eps3()) {
        e2 = Pow(tEq, F3(Eps) * (Eps-myParameters.Eps2()) + F4(Eps));
        e3 = F1(Eps) * (Eps-myParameters.Eps2()) + F2(Eps);
    } else {
        e2 = Pow(tEq, F3(Eps) * (Eps-myParameters.Eps3()) + F4(Eps));
        e3 = F1(Eps) * (Eps-myParameters.Eps3()) + F2(Eps);
    }
    myTrialTemperatureGrowthRate = e1 * e2 * e3;
    return Standard_True;
}

// ============================================================================
/*!
    \brief UpdateTrialTimeGrowthRate()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire02::UpdateTrialTimeGrowthRate(const Standard_Real tEq,
                                                             const Standard_Real Eps)
{
    if(tEq <= 0.) {
        myTrialTimeGrowthRate = 0.;
        return Standard_True;
    }
    Standard_Real e1 = Exp(myParameters.C()
                           * (myTrialTemperature - myParameters.T0()));
    Standard_Real e2, e3, e4;
    if(Eps < myParameters.Eps1()) {
        e2 = F1(Eps) * (Eps - myParameters.Eps0()) + F2(Eps);
        e3 = F3(Eps) * (Eps - myParameters.Eps0()) + F4(Eps);
        e4 = Pow(tEq, e3 - 1.);
    } else if(Eps < myParameters.Eps2()) {
        e2 = F1(Eps) * (Eps - myParameters.Eps1()) + F2(Eps);
        e3 = F3(Eps) * (Eps - myParameters.Eps1()) + F4(Eps);
        e4 = Pow(tEq, e3 - 1.);
    } else if(Eps < myParameters.Eps3()) {
        e2 = F1(Eps) * (Eps - myParameters.Eps2()) + F2(Eps);
        e3 = F3(Eps) * (Eps - myParameters.Eps2()) + F4(Eps);
        e4 = Pow(tEq, e3 - 1.);
    } else {
        e2 = F1(Eps) * (Eps - myParameters.Eps3()) + F2(Eps);
        e3 = F3(Eps) * (Eps - myParameters.Eps3()) + F4(Eps);
        e4 = Pow(tEq, e3 - 1.);
    }
    myTrialTimeGrowthRate = e1 * e2 * e3 * e4;
    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(UCrM_CableWire02, UCrM_Model)
IMPLEMENT_STANDARD_RTTIEXT(UCrM_CableWire02, UCrM_Model)

