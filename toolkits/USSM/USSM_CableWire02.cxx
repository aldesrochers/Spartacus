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


// Spartacus
#include <USSM_CableWire02.hxx>
#include <FLib_StressStrain.hxx>

// Declarations
#define Direction_NONE      0
#define Direction_FORWARD   1
#define Direction_BACKWARD  2


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
USSM_CableWire02::USSM_CableWire02(const USSMP_CableWire02& theParameters)
    : myParameters(theParameters)
{
    RevertToInitialState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
USSM_CableWire02::~USSM_CableWire02()
{

}

// ============================================================================
/*!
    \brief CommitState()
*/
// ============================================================================
Standard_Boolean USSM_CableWire02::CommitState()
{
    myPreviousDirection = myCurrentDirection;
    myCommitStrain = myTrialStrain;
    myCommitStress = myTrialStress;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief GetInitialStiffness()
*/
// ============================================================================
Standard_Real USSM_CableWire02::GetInitialStiffness()
{
    return PolynomialStiffness(0.);
}

// ============================================================================
/*!
    \brief GetTrialStiffness()
*/
// ============================================================================
Standard_Real USSM_CableWire02::GetTrialStiffness()
{
    return myTrialStiffness;
}

// ============================================================================
/*!
    \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real USSM_CableWire02::GetTrialStrain()
{
    return myTrialStrain;
}

// ============================================================================
/*!
    \brief GetTrialStress()
*/
// ============================================================================
Standard_Real USSM_CableWire02::GetTrialStress()
{
    return myTrialStress;
}

// ============================================================================
/*!
    \brief MenegottoStiffness()
*/
// ============================================================================
Standard_Real USSM_CableWire02::MenegottoStiffness(const Standard_Real Eps,
                                                   const Standard_Real B)
{
    Standard_Real D = (1.-B)/Pow((Pow(Eps, myParameters.R()) + 1.), 1./myParameters.R())
            - (1.-B) * Pow(Eps, myParameters.R())
            * Pow(Pow(Eps, myParameters.R()) + 1., (-1./myParameters.R())-1.) + B;
    return D;
}

// ============================================================================
/*!
    \brief MenegottoStress()
*/
// ============================================================================
Standard_Real USSM_CableWire02::MenegottoStress(const Standard_Real Eps,
                                                const Standard_Real B)
{
    Standard_Real F = B * Eps
            + ((1.-B)*Eps)/Pow(1.+Pow(Eps, myParameters.R()), 1./myParameters.R());
    return F;
}

// ============================================================================
/*!
    \brief MonotonicStiffness()
*/
// ============================================================================
Standard_Real USSM_CableWire02::MonotonicStiffness(const Standard_Real Eps)
{
    if(Eps > myParameters.EpsL()) {
        return PolynomialStiffness(myParameters.EpsL());
    } else {
        return PolynomialStiffness(Eps);
    }
}

// ============================================================================
/*!
    \brief MonotonicStress()
*/
// ============================================================================
Standard_Real USSM_CableWire02::MonotonicStress(const Standard_Real Eps)
{
    if(Eps > myParameters.EpsL()) {
        return PolynomialStress(myParameters.EpsL())
                + PolynomialStiffness(myParameters.EpsL()) * (Eps - myParameters.EpsL());
    } else {
        return PolynomialStress(Eps);
    }
}

// ============================================================================
/*!
    \brief PolynomialStiffness()
*/
// ============================================================================
Standard_Real USSM_CableWire02::PolynomialStiffness(const Standard_Real Eps)
{
    Standard_Real D = (6. * myParameters.A6() * Pow(Eps, 5.)
            + 5. * myParameters.A5() * Pow(Eps, 4.)
            + 4. * myParameters.A4() * Pow(Eps, 3.)
            + 3. * myParameters.A3() * Pow(Eps, 2.)
            + 2. * myParameters.A2() * Pow(Eps, 1.)
            + 1. * myParameters.A1()) * myParameters.E();
    return D;
}

// ============================================================================
/*!
    \brief PolynomialStress()
*/
// ============================================================================
Standard_Real USSM_CableWire02::PolynomialStress(const Standard_Real Eps)
{
    Standard_Real F = (myParameters.A6() * Pow(Eps, 6.)
            + myParameters.A5() * Pow(Eps, 5.)
            + myParameters.A4() * Pow(Eps, 4.)
            + myParameters.A3() * Pow(Eps, 3.)
            + myParameters.A2() * Pow(Eps, 2.)
            + myParameters.A1() * Pow(Eps, 1.)
            + myParameters.A0()) * myParameters.E();
    return F;
}

// ============================================================================
/*!
    \brief RevertToCommitState()
*/
// ============================================================================
Standard_Boolean USSM_CableWire02::RevertToCommitState()
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
Standard_Boolean USSM_CableWire02::RevertToInitialState()
{
    myCommitStrain = 0.;
    myCommitStress = 0.;
    myCurrentDirection = Direction_NONE;
    myCurrentMaxStrain = 0.;
    myCurrentMaxStress = 0.;
    myCurrentMinStrain = 0.;
    myCurrentMinStress = 0.;
    myIsInitialLoading = Standard_True;
    myPreviousDirection = Direction_NONE;
    myTrialStrain = 0.;
    myTrialStress = 0.;
    return Standard_True;
}

// ============================================================================
/*!
    \brief SetTrialStrain()
*/
// ============================================================================
Standard_Boolean USSM_CableWire02::SetTrialStrain(const Standard_Real theStrain)
{
    myTrialStrain = theStrain;
    return UpdateInternalState();
}

// ============================================================================
/*!
    \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean USSM_CableWire02::UpdateInternalState()
{
    Standard_Real EpsL = myParameters.EpsL();
    Standard_Real Ei = MonotonicStiffness(0.);
    Standard_Real Et = MonotonicStiffness(EpsL);
    Standard_Real SigL = MonotonicStress(EpsL);
    Standard_Real EpsFc = -1./Ei * myParameters.Fc();
    Standard_Real Ec = myParameters.B() * Ei;

    // update loading direction
    if(myTrialStrain > myCommitStrain) {
        myCurrentDirection = Direction_FORWARD;
        if(myPreviousDirection == Direction_BACKWARD) {
            myCurrentMinStrain = myCommitStrain;
            myCurrentMinStress = myCommitStress;
            myIsInitialLoading = Standard_False;
        }
    } else if(myTrialStrain < myCommitStrain) {
        myCurrentDirection = Direction_BACKWARD;
        if(myPreviousDirection == Direction_FORWARD) {
            myCurrentMaxStrain = myCommitStrain;
            myCurrentMaxStress = myCommitStress;
            myIsInitialLoading = Standard_False;
        }
    } else {
        myCurrentDirection = Direction_NONE;
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
            Standard_Real B = Et/myParameters.E();
            Standard_Real F = MenegottoStress(Eps, B);
            Standard_Real D = MenegottoStiffness(Eps, B);
            myTrialStress = F * (Sig0 - myCurrentMinStress)
                    + myCurrentMinStress;
            myTrialStiffness = D * (Sig0 - myCurrentMinStress)/(Eps0 - myCurrentMinStrain);
        }
    } else {
        if(myTrialStrain <= myCurrentMinStrain && myIsInitialLoading == Standard_True) {
            if(myTrialStrain >= EpsFc) {
                myTrialStress = Ei * myTrialStrain;
                myTrialStiffness = Ei;
            } else {
                myTrialStress = -1. * myParameters.Fc() + (myTrialStrain - EpsFc) * Ec;
                myTrialStiffness = Ec;
            }
        } else {
            Standard_Real Eps0 = (myParameters.Fc() + myCurrentMaxStress
                                  - myCurrentMaxStrain * myParameters.E() + Ec * EpsFc) / (Ec - myParameters.E());
            Standard_Real Sig0 = (Eps0 - EpsFc) * Ec - myParameters.Fc();

            Standard_Real Eps = (myTrialStrain-myCurrentMaxStrain) /
                    (Eps0 - myCurrentMaxStrain);
            Standard_Real F = MenegottoStress(Eps, myParameters.B());
            Standard_Real D = MenegottoStiffness(Eps, myParameters.B());
            myTrialStress = F * (Sig0 - myCurrentMaxStress)
                    + myCurrentMaxStress;
            myTrialStiffness = D* (Sig0 - myCurrentMaxStress)/(Eps0 - myCurrentMaxStrain);
        }
    }

    return Standard_True;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(USSM_CableWire02, USSM_Model)
IMPLEMENT_STANDARD_RTTIEXT(USSM_CableWire02, USSM_Model)

