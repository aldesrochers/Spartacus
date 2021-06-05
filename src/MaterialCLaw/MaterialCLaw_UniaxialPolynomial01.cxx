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

// MaterialCLaw
#include <MaterialCLaw_UniaxialPolynomial01.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MaterialCLaw_UniaxialPolynomial01::MaterialCLaw_UniaxialPolynomial01(const Standard_Real E,
                                                                     const Standard_Real EpsM,
                                                                     const Standard_Real Fyc,
                                                                     const Standard_Real Beta,
                                                                     const Standard_Real A0,
                                                                     const Standard_Real A1,
                                                                     const Standard_Real A2,
                                                                     const Standard_Real A3,
                                                                     const Standard_Real A4,
                                                                     const Standard_Real A5,
                                                                     const Standard_Real A6)
    : myE(E), myEpsM(EpsM), myFyc(Fyc), myBeta(Beta),
      myA0(A0), myA1(A1), myA2(A2), myA3(A3), myA4(A4), myA5(A5), myA6(A6)
{
    InitializeEt();
    InitializeEpsC();
    InitializeEpsCM();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MaterialCLaw_UniaxialPolynomial01::~MaterialCLaw_UniaxialPolynomial01()
{

}

// ============================================================================
/*!
    \brief CommitState()
*/
// ============================================================================
Standard_Boolean MaterialCLaw_UniaxialPolynomial01::CommitState()
{
    if(myTrialStrain > myPreviousStrain && myTrialStrain > myCurrentMaxStrain) {
        myCurrentMaxStrain = myTrialStrain;
        myCurrentMaxStress = myTrialStress;
    }
    if(myTrialStrain < myPreviousStrain && myTrialStrain < myCurrentMinStrain) {
        myCurrentMinStrain = myTrialStrain;
        myCurrentMinStress = myTrialStress;
    }
    myPreviousStrain = myTrialStrain;
}

// ============================================================================
/*!
    \brief CurrentStress()
*/
// ============================================================================
Standard_Real MaterialCLaw_UniaxialPolynomial01::CurrentStress()
{
    return myTrialStress;
}

// ============================================================================
/*!
    \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean MaterialCLaw_UniaxialPolynomial01::UpdateInternalState()
{
    if(myTrialStrain  < myPreviousStrain) {
        Standard_Real Eps1 = (myCurrentMaxStress-myCurrentMaxStrain*myE)/(myEt-myE);
        Standard_Real Sig1 = (Eps1-myCurrentMaxStrain)*myE + myCurrentMaxStress;
        Standard_Real Eps2 = Eps1 - myEpsC;
        Standard_Real Sig2 = -1.*MonotonicFunction(Eps1-Eps2) + Sig1;
        if(myTrialStrain >= Eps1) {
            myTrialStress = (myTrialStrain-myCurrentMaxStrain)*myE + myCurrentMaxStress;
        } else if(myTrialStrain >= Eps2) {
            Standard_Real Eps = Eps1 - myTrialStrain;
            myTrialStress = -1.*MonotonicFunction(Eps) + Sig1;
        } else {
            Standard_Real Eps = Eps2 - myTrialStrain;
            myTrialStress = Sig2*Pow((1-Eps), myBeta);
        }
    } else {
        Standard_Real Eps1 = (myCurrentMaxStress-myCurrentMaxStrain*myE)/(myEt-myE);
        Standard_Real Eps0 = Eps1 - myEpsC - myEpsCM;
        if(myCurrentMinStrain < Eps0) {
            myTrialStress = 0.;
        } else {
            Standard_Real Eps3 = (myCurrentMinStress-myE*myCurrentMinStrain)/(myEt-myE);
            cout << Eps3 << endl;
            Standard_Real Eps4 = Eps3 + myEpsM;
            if(myTrialStrain < Eps3) {
                myTrialStress = (myTrialStrain-myCurrentMinStrain)*myE + myCurrentMinStress;
            }

        }
    }
}

// ============================================================================
/*!
    \brief EpsC()
*/
// ============================================================================
Standard_Real MaterialCLaw_UniaxialPolynomial01::EpsC() const
{
    return myEpsC;
}

// ============================================================================
/*!
    \brief EpsCM()
*/
// ============================================================================
Standard_Real MaterialCLaw_UniaxialPolynomial01::EpsCM() const
{
    return myEpsCM;
}

// ============================================================================
/*!
    \brief Et()
*/
// ============================================================================
Standard_Real MaterialCLaw_UniaxialPolynomial01::Et() const
{
    return myEt;
}

// ============================================================================
/*!
    \brief InitializeEpsC()
*/
// ============================================================================
void MaterialCLaw_UniaxialPolynomial01::InitializeEpsC()
{
    Standard_Real aGuess = 0.01;
    Standard_Real aPrecision = 1E-8;
    Standard_Real Fn = MonotonicFunction(aGuess) - myFyc;
    Standard_Real Dn = MonotonicDerivative(aGuess);
    while(Sqrt(Abs(Fn)) > aPrecision) {
        Fn = MonotonicFunction(aGuess) - myFyc;
        Dn = MonotonicDerivative(aGuess);
        aGuess = aGuess - Fn/Dn;
    }
    myEpsC = aGuess;
}

// ============================================================================
/*!
    \brief InitializeEpsCM()
*/
// ============================================================================
void MaterialCLaw_UniaxialPolynomial01::InitializeEpsCM()
{
    Standard_Real aGuess = 0.01;
    Standard_Real aPrecision = 1E-2;
    Standard_Real Fn = myFyc*Pow((1.-aGuess),myBeta) - aGuess*myEt - myEpsC*myEt;
    Standard_Real Dn = -myBeta*myFyc*Pow((1.-aGuess), myBeta-1.) - myEt;
    while(Sqrt(Abs(Fn)) > aPrecision) {
        Fn = myFyc*Pow((1.-aGuess),myBeta) - aGuess*myEt - myEpsC*myEt;
        Dn = Dn = -myBeta*myFyc*Pow((1.-aGuess), myBeta-1.) - myEt;
        aGuess = aGuess - Fn/Dn;
    }
    myEpsCM = aGuess;
}

// ============================================================================
/*!
    \brief InitializeEt()
*/
// ============================================================================
void MaterialCLaw_UniaxialPolynomial01::InitializeEt()
{
    myEt = MonotonicDerivative(myEpsM);
}

// ============================================================================
/*!
    \brief MonotonicDerivative()
*/
// ============================================================================
Standard_Real MaterialCLaw_UniaxialPolynomial01::MonotonicDerivative(const Standard_Real Eps)
{
    return (6.*myA6*Pow(Eps,5) + 5.*myA5*Pow(Eps,4) + 4.*myA4*Pow(Eps,3)
            + 3.*myA3*Pow(Eps,2) + 2.*myA2*Pow(Eps,1) + 1.*myA1) * myE;
}

// ============================================================================
/*!
    \brief MonotonicDerivativeDerivative()
*/
// ============================================================================
Standard_Real MaterialCLaw_UniaxialPolynomial01::MonotonicDerivativeDerivative(const Standard_Real Eps)
{
    return (5.*6.*myA6*Pow(Eps,4) + 4.*5.*myA5*Pow(Eps,3) + 3.*4.*myA4*Pow(Eps,2)
            + 2.*3.*myA3*Pow(Eps,1) + 1.*2.*myA2) * myE;
}

// ============================================================================
/*!
    \brief MonotonicFunction()
*/
// ============================================================================
Standard_Real MaterialCLaw_UniaxialPolynomial01::MonotonicFunction(const Standard_Real Eps)
{
    return (myA6*Pow(Eps,6) + myA5*Pow(Eps,5) + myA4*Pow(Eps,4)
            + myA3*Pow(Eps,3) + myA2*Pow(Eps,2) + myA1*Pow(Eps,1) + myA0) * myE;
}

// ============================================================================
/*!
    \brief SetTrialStrain()
*/
// ============================================================================
void MaterialCLaw_UniaxialPolynomial01::SetTrialStrain(const Standard_Real theStrain)
{
    myTrialStrain = theStrain;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MaterialCLaw_UniaxialPolynomial01, Standard_Transient);
IMPLEMENT_STANDARD_RTTIEXT(MaterialCLaw_UniaxialPolynomial01, Standard_Transient);



