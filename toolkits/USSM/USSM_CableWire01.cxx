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

// MCLM1d
#include <USSM_CableWire01.hxx>

// Declarations
#define Direction_NONE      0
#define Direction_FORWARD   1
#define Direction_BACKWARD  2


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
USSM_CableWire01::USSM_CableWire01(const USSMP_CableWire01& theParameters)
    : myParameters(theParameters)
{
    RevertToInitialState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
USSM_CableWire01::~USSM_CableWire01()
{

}

// ============================================================================
/*!
    \brief CommitState()
*/
// ============================================================================
Standard_Boolean USSM_CableWire01::CommitState()
{
    if(myTrialStrain > myCommitStrain)
        myPreviousDirection = 1;
    if(myTrialStrain < myCommitStrain)
        myPreviousDirection = 2;
    myCommitStrain = myTrialStrain;
    myCommitStress = myTrialStress;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief GetInitialStiffness()
*/
// ============================================================================
Standard_Real USSM_CableWire01::GetInitialStiffness()
{
    return PolynomialStiffness(0.);
}

// ============================================================================
/*!
    \brief GetTrialStiffness()
*/
// ============================================================================
Standard_Real USSM_CableWire01::GetTrialStiffness()
{
    return myTrialStiffness;
}

// ============================================================================
/*!
    \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real USSM_CableWire01::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
    \brief GetTrialStress()
*/
// ============================================================================
Standard_Real USSM_CableWire01::GetTrialStress()
{
    return myTrialStress;
}

// ============================================================================
/*!
    \brief MenegottoStiffness()
*/
// ============================================================================
Standard_Real USSM_CableWire01::MenegottoStiffness(const Standard_Real theStrain)
{
    Standard_Real Et = MonotonicStiffness(myParameters.EpsL());
    Standard_Real b = Et/myParameters.E();
    Standard_Real D = (1.-b)/Pow((Pow(theStrain, myParameters.R()) + 1.), 1./myParameters.R())
            - (1.-b) * Pow(theStrain, myParameters.R())
            * Pow(Pow(theStrain, myParameters.R()) + 1., (-1./myParameters.R())-1.) + b;
    return D;
}

// ============================================================================
/*!
    \brief MenegottoStress()
*/
// ============================================================================
Standard_Real USSM_CableWire01::MenegottoStress(const Standard_Real theStrain)
{
    Standard_Real Et = MonotonicStiffness(myParameters.EpsL());
    Standard_Real b = Et/myParameters.E();

    Standard_Real F = b*theStrain
            + ((1.-b)*theStrain)/Pow(1.+Pow(theStrain, myParameters.R()), 1./myParameters.R());
    return F;
}

// ============================================================================
/*!
    \brief MonotonicStiffness()
*/
// ============================================================================
Standard_Real USSM_CableWire01::MonotonicStiffness(const Standard_Real theStrain)
{
    if(theStrain > myParameters.EpsL()) {
        return PolynomialStiffness(myParameters.EpsL());
    } else {
        return PolynomialStiffness(theStrain);
    }
}

// ============================================================================
/*!
    \brief MonotonicStress()
*/
// ============================================================================
Standard_Real USSM_CableWire01::MonotonicStress(const Standard_Real theStrain)
{
    if(theStrain > myParameters.EpsL()) {
        return PolynomialStress(myParameters.EpsL())
                + PolynomialStiffness(myParameters.EpsL()) * (theStrain - myParameters.EpsL());
    } else {
        return PolynomialStress(theStrain);
    }
}

// ============================================================================
/*!
    \brief PolynomialStiffness()
*/
// ============================================================================
Standard_Real USSM_CableWire01::PolynomialStiffness(const Standard_Real theStrain)
{
    Standard_Real D = (6. * myParameters.A6() * Pow(theStrain, 5.)
            + 5. * myParameters.A5() * Pow(theStrain, 4.)
            + 4. * myParameters.A4() * Pow(theStrain, 3.)
            + 3. * myParameters.A3() * Pow(theStrain, 2.)
            + 2. * myParameters.A2() * Pow(theStrain, 1.)
            + 1. * myParameters.A1()) * myParameters.E();
    return D;
}

// ============================================================================
/*!
    \brief PolynomialStress()
*/
// ============================================================================
Standard_Real USSM_CableWire01::PolynomialStress(const Standard_Real theStrain)
{
    Standard_Real F = (myParameters.A6() * Pow(theStrain, 6.)
            + myParameters.A5() * Pow(theStrain, 5.)
            + myParameters.A4() * Pow(theStrain, 4.)
            + myParameters.A3() * Pow(theStrain, 3.)
            + myParameters.A2() * Pow(theStrain, 2.)
            + myParameters.A1() * Pow(theStrain, 1.)
            + myParameters.A0()) * myParameters.E();
    return F;
}

// ============================================================================
/*!
    \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean USSM_CableWire01::RevertToCommitState()
{
    myTrialStrain = myCommitStrain;
    myTrialStress = myCommitStress;
    return Standard_True;
}

// ============================================================================
/*!
    \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean USSM_CableWire01::RevertToInitialState()
{
    myCommitStrain = 0.;
    myCurrentDirection = Direction_NONE;
    myCurrentMaxStrain = 0.;
    myCurrentMaxStress = 0.;
    myCurrentMinStrain = 0.;
    myCurrentMinStress = 0.;
    myIsInitialLoading = Standard_True;
    myPreviousDirection = Direction_NONE;
    myTrialStrain = 0.;
    return Standard_True;
}

// ============================================================================
/*!
    \brief SetTrialStrain()
*/
// ============================================================================
Standard_Boolean USSM_CableWire01::SetTrialStrain(const Standard_Real theStrain)
{
    myTrialStrain = theStrain;
    return UpdateInternalState();
}

// ============================================================================
/*!
    \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean USSM_CableWire01::UpdateInternalState()
{
    Standard_Real EpsL = myParameters.EpsL();
    Standard_Real Et = MonotonicStiffness(EpsL);
    Standard_Real SigL = MonotonicStress(EpsL);

    // check loading direction
    if(myTrialStrain > myCommitStrain && myPreviousDirection == Direction_BACKWARD) {
        myCurrentMinStrain = myCommitStrain;
        myCurrentMinStress = myCommitStress;
        myIsInitialLoading = Standard_False;
    }

    if(myTrialStrain < myCommitStrain && myPreviousDirection == Direction_FORWARD) {
        myCurrentMaxStrain = myCommitStrain;
        myCurrentMaxStress = myCommitStress;
        myIsInitialLoading = Standard_False;
    }

    // compute stress/stiffness
    if(myTrialStrain >= myCommitStrain) {
        if(myTrialStrain >= myCurrentMaxStrain && myIsInitialLoading == Standard_True) {
            myTrialStress = 1. * MonotonicStress(Abs(myTrialStrain));
            myTrialStiffness = 1. * MonotonicStiffness(Abs(myTrialStrain));
        } else {
            Standard_Real Eps0 = (SigL - myCurrentMinStress
                                  - EpsL * Et + myCurrentMinStrain * myParameters.E()) / (myParameters.E() - Et);
            Standard_Real Sig0 = (Eps0 - myCurrentMinStrain) * myParameters.E() + myCurrentMinStress;
            Standard_Real Eps = (myTrialStrain-myCurrentMinStrain) /
                    (Eps0 - myCurrentMinStrain);
            Standard_Real F = MenegottoStress(Eps);
            myTrialStress = F * (Sig0 - myCurrentMinStress)
                    + myCurrentMinStress;
            myTrialStiffness = MenegottoStiffness(Eps)
                    * (Sig0 - myCurrentMinStress)/(Eps0 - myCurrentMinStrain);
        }
    } else {
        if(myTrialStrain <= myCurrentMinStrain && myIsInitialLoading == Standard_True) {
            myTrialStress = -1. * MonotonicStress(Abs(myTrialStrain));
            myTrialStiffness = 1. * MonotonicStiffness(Abs(myTrialStrain));
        } else {
            Standard_Real Eps0 = (-SigL - myCurrentMaxStress
                                  + EpsL * Et + myCurrentMaxStrain * myParameters.E()) / (myParameters.E() - Et);
            Standard_Real Sig0 = (Eps0 - myCurrentMaxStrain) * myParameters.E() + myCurrentMaxStress;
            Standard_Real Eps = (myTrialStrain-myCurrentMaxStrain) /
                    (Eps0 - myCurrentMaxStrain);
            Standard_Real F = MenegottoStress(Eps);
            myTrialStress = F * (Sig0 - myCurrentMaxStress)
                    + myCurrentMaxStress;
            myTrialStiffness = MenegottoStiffness(Eps)
                    * (Sig0 - myCurrentMaxStress)/(Eps0 - myCurrentMaxStrain);
        }
    }

    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(USSM_CableWire01, USSM_Model)
IMPLEMENT_STANDARD_RTTIEXT(USSM_CableWire01, USSM_Model)

