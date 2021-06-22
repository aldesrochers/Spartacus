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
UCrM_CableWire01::UCrM_CableWire01(const UCrMP_CableWire01& theParameters)
    : myParameters(theParameters)
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
    \brief CommitState()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire01::CommitState()
{
    myCommitStrain = myTrialStrain;
    return Standard_True;
}

// ============================================================================
/*!
    \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real UCrM_CableWire01::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
    \brief GetTrialStress()
*/
// ============================================================================
Standard_Real UCrM_CableWire01::GetTrialStress()
{
    return myTrialStress;
}

// ============================================================================
/*!
    \brief GetTrialStressGrowthRate()
*/
// ============================================================================
Standard_Real UCrM_CableWire01::GetTrialStressGrowthRate()
{
    return myTrialStressGrowthRate;
}

// ============================================================================
/*!
    \brief GetTrialTemperature()
*/
// ============================================================================
Standard_Real UCrM_CableWire01::GetTrialTemperature()
{
    return myTrialTemperature;
}

// ============================================================================
/*!
    \brief GetTrialTemperatureGrowthRate()
*/
// ============================================================================
Standard_Real UCrM_CableWire01::GetTrialTemperatureGrowthRate()
{
        return myTrialTemperatureGrowthRate;
}

// ============================================================================
/*!
    \brief GetTrialTime()
*/
// ============================================================================
Standard_Real UCrM_CableWire01::GetTrialTime()
{
    return myTrialTime;
}

// ============================================================================
/*!
    \brief GetTrialTimeGrowthRate()
*/
// ============================================================================
Standard_Real UCrM_CableWire01::GetTrialTimeGrowthRate()
{
    return myTrialStressGrowthRate;
}

// ============================================================================
/*!
    \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire01::RevertToCommitState()
{
    myTrialStrain = myCommitStrain;
    return Standard_True;
}

// ============================================================================
/*!
    \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire01::RevertToInitialState()
{
    myCommitStrain = 0.;
    myTrialStrain = 0.;
    return Standard_True;
}

// ============================================================================
/*!
    \brief SetTrialStress()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire01::SetTrialStress(const Standard_Real theStress)
{
    myTrialStress = theStress;
    return UpdateInternalState();
}

// ============================================================================
/*!
    \brief SetTrialTemperature()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire01::SetTrialTemperature(const Standard_Real theTemperature)
{
    myTrialTemperature = theTemperature;
    return UpdateInternalState();
}

// ============================================================================
/*!
    \brief SetTrialTime()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire01::SetTrialTime(const Standard_Real theTime)
{
    myTrialTime = theTime;
    return UpdateInternalState();
}

// ============================================================================
/*!
    \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire01::UpdateInternalState()
{
    // compute functions
    Standard_Real f1 = myParameters.A1()
            * Pow(myParameters.A2()*myTrialStress, myParameters.A3());
    Standard_Real f2 = myParameters.B1()*Pow(myTrialStress, 2.)
            + myParameters.B2() * myTrialStress + myParameters.B3();
    Standard_Real f3 = Exp(myParameters.C()
                           * (myTrialTemperature - myParameters.T0()));

    // compute equivalent time
    Standard_Real tEq = Pow(myCommitStrain/(f1*f3), 1./f2)
            + (myTrialTime - myCommitTime);

    // update current strain
    myTrialStrain = f1*f3*Pow(tEq, f2);

    // update growth rates
    if(!UpdateTrialStressGrowthRate(tEq))
        return Standard_False;
    if(!UpdateTrialTemperatureGrowthRate(tEq))
        return Standard_False;
    if(!UpdateTrialTimeGrowthRate(tEq))
        return Standard_False;

    return Standard_True;
}

// ============================================================================
/*!
    \brief UpdateTrialStressGrowthRate()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire01::UpdateTrialStressGrowthRate(const Standard_Real tEq)
{
    Standard_Real e1 = myParameters.A1()
            * Pow(myParameters.A2()*myTrialStress, myParameters.A3());
    Standard_Real e2 = Pow(tEq, myParameters.B1()
                           * Pow(myTrialStress, 2.) + myParameters.B1()
                           * myTrialStress + myParameters.B2());
    Standard_Real e3 = Exp(myParameters.C()
                           * (myTrialTemperature - myParameters.T0()));
    Standard_Real e4 = 2.*myParameters.B1()*Log(tEq)*Pow(myTrialStress, 2.)
            + myParameters.B2()*Log(tEq)*myTrialStress + myParameters.A3();
    myTrialStressGrowthRate = e1 * e2 * e3 * e4 / myTrialStress;
    return Standard_True;
}

// ============================================================================
/*!
    \brief UpdateTrialTemperatureGrowthRate()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire01::UpdateTrialTemperatureGrowthRate(const Standard_Real tEq)
{
    Standard_Real e1 = myParameters.A1()
            * Pow(myParameters.A2()*myTrialStress, myParameters.A3());
    Standard_Real e2 = Pow(tEq, myParameters.B1()
                           * Pow(myTrialStress, 2.) + myParameters.B1()
                           * myTrialStress + myParameters.B2());
    myTrialTemperatureGrowthRate = myParameters.C() * e1 * e2
            * Exp(myParameters.C() * (myTrialTemperature - myParameters.T0()));
    return Standard_True;
}

// ============================================================================
/*!
    \brief UpdateTrialTimeGrowthRate()
*/
// ============================================================================
Standard_Boolean UCrM_CableWire01::UpdateTrialTimeGrowthRate(const Standard_Real tEq)
{
    Standard_Real e1 = myParameters.A1()
            * Pow(myParameters.A2()*myTrialStress, myParameters.A3());
    Standard_Real e2 = Exp(myParameters.C()*(myTrialTemperature-myParameters.T0()));
    Standard_Real e3 = myParameters.B1()*Pow(myTrialStress,2.)
            + myParameters.B2()*myTrialStress + myParameters.B3();
    myTrialTimeGrowthRate = e1 * e2 * e3 * Pow(tEq, e3 - 1.);
    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(UCrM_CableWire01, UCrM_Model)
IMPLEMENT_STANDARD_RTTIEXT(UCrM_CableWire01, UCrM_Model)

