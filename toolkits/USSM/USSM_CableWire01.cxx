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


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
USSM_CableWire01::USSM_CableWire01(const Standard_Real Ei,
                                   const Standard_Real Ef,
                                   const Standard_Real EpsMax,
                                   const Standard_Real A0,
                                   const Standard_Real A1,
                                   const Standard_Real A2,
                                   const Standard_Real A3,
                                   const Standard_Real A4,
                                   const Standard_Real A5,
                                   const Standard_Real R)
    : myA0(A0), myA1(A1), myA2(A2), myA3(A3), myA4(A4), myA5(A5),
      myEf(Ef), myEi(Ei), myEpsMax(EpsMax),
      myR(R),
      myIsInitialLoading(Standard_True),
      myPreviousDirection(0)
{

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
    return USSM_Model::CommitState();
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
    \brief MenegottoStiffness()
*/
// ============================================================================
Standard_Real USSM_CableWire01::MenegottoStiffness(const Standard_Real theStrain)
{
    Standard_Real Et = MonotonicStiffness(myEpsMax);
    Standard_Real b = Et/myEf;
    Standard_Real D = (1.-b)/Pow((Pow(theStrain, myR) + 1.), 1./myR)
            - (1.-b) * Pow(theStrain, myR)
            * Pow(Pow(theStrain, myR) + 1., (-1./myR)-1.) + b;
    return D;
}

// ============================================================================
/*!
    \brief MenegottoStress()
*/
// ============================================================================
Standard_Real USSM_CableWire01::MenegottoStress(const Standard_Real theStrain)
{
    Standard_Real Et = MonotonicStiffness(myEpsMax);
    Standard_Real b = Et/myEf;
    Standard_Real F = b*theStrain
            + ((1.-b)*theStrain)/Pow(1.+Pow(theStrain, myR), 1./myR);
    return F;
}

// ============================================================================
/*!
    \brief MonotonicStiffness()
*/
// ============================================================================
Standard_Real USSM_CableWire01::MonotonicStiffness(const Standard_Real theStrain)
{
    if(theStrain > myEpsMax) {
        return PolynomialStiffness(myEpsMax);
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
    if(theStrain > myEpsMax) {
        return PolynomialStress(myEpsMax)
                + PolynomialStiffness(myEpsMax) * (theStrain - myEpsMax);
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
    Standard_Real D = (5.*myA5*Pow(theStrain, 4.) + 4.*myA4*Pow(theStrain, 3.)
            + 3.*myA3*Pow(theStrain, 2.) + 2.*myA2*Pow(theStrain, 1.)
            + 1.*myA1*Pow(theStrain, 0.)) * myEi;
    return D;
}

// ============================================================================
/*!
    \brief PolynomialStress()
*/
// ============================================================================
Standard_Real USSM_CableWire01::PolynomialStress(const Standard_Real theStrain)
{
    Standard_Real S = (myA5*Pow(theStrain, 5.) + myA4*Pow(theStrain, 4.)
            + myA3*Pow(theStrain, 3.) + myA2*Pow(theStrain, 2.)
            + myA1*Pow(theStrain, 1.) + myA0) * myEi;
    return S;
}

// ============================================================================
/*!
    \brief RevertToInitialState()
*/
// ============================================================================
Standard_Boolean USSM_CableWire01::RevertToInitialState()
{
    myCurrentMaxStrain = 0.;
    myCurrentMaxStress = 0.;
    myCurrentMinStrain = 0.;
    myCurrentMinStress = 0.;
    return USSM_Model::RevertToInitialState();
}

// ============================================================================
/*!
    \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean USSM_CableWire01::UpdateInternalState()
{
    Standard_Real EpsL = myEpsMax;
    Standard_Real Et = MonotonicStiffness(myEpsMax);
    Standard_Real SigL = MonotonicStress(myEpsMax);

    // check loading direction
    if(myTrialStrain > myCommitStrain && myPreviousDirection == 2) {
        myCurrentMinStrain = myCommitStrain;
        myCurrentMinStress = myCommitStress;
        myIsInitialLoading = Standard_False;
    }

    if(myTrialStrain < myCommitStrain && myPreviousDirection == 1) {
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
                                  - EpsL * Et + myCurrentMinStrain * myEf) / (myEf - Et);
            Standard_Real Sig0 = (Eps0 - myCurrentMinStrain) * myEf + myCurrentMinStress;
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
                                  + EpsL * Et + myCurrentMaxStrain * myEf) / (myEf - Et);
            Standard_Real Sig0 = (Eps0 - myCurrentMaxStrain) * myEf + myCurrentMaxStress;
            Standard_Real Eps = (myTrialStrain-myCurrentMaxStrain) /
                    (Eps0 - myCurrentMaxStrain);
            Standard_Real F = MenegottoStress(Eps);
            myTrialStress = F * (Sig0 - myCurrentMaxStress)
                    + myCurrentMaxStress;
            myTrialStiffness = MenegottoStiffness(Eps)
                    * (Sig0 - myCurrentMaxStress)/(Eps0 - myCurrentMaxStrain);
        }
    }

    myMustBeUpdated = Standard_False;
    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(USSM_CableWire01, USSM_Model)
IMPLEMENT_STANDARD_RTTIEXT(USSM_CableWire01, USSM_Model)

