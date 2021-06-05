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


#ifndef __MaterialCLaw_UniaxialPolynomial01_hxx__
#define __MaterialCLaw_UniaxialPolynomial01_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>

// Forward declarations
class MaterialCLaw_UniaxialPolynomial01;

// Handles
DEFINE_STANDARD_HANDLE(MaterialCLaw_UniaxialPolynomial01, Standard_Transient);


// ============================================================================
/*!
 *  \brief MaterialCLaw_UniaxialPolynomial01
*/
// ============================================================================
class MaterialCLaw_UniaxialPolynomial01 : public Standard_Transient
{

public:
    // constructors
    MaterialCLaw_UniaxialPolynomial01(const Standard_Real E,
                                      const Standard_Real EpsM,
                                      const Standard_Real Fyc,
                                      const Standard_Real Beta,
                                      const Standard_Real A0,
                                      const Standard_Real A1,
                                      const Standard_Real A2,
                                      const Standard_Real A3,
                                      const Standard_Real A4,
                                      const Standard_Real A5,
                                      const Standard_Real A6);
    // destructors
    ~MaterialCLaw_UniaxialPolynomial01();

public:

    Standard_Boolean    CommitState();
    Standard_Real       CurrentStress();
    Standard_Boolean    UpdateInternalState();
    void                SetTrialStrain(const Standard_Real theStrain);


public:

    Standard_Real       EpsC() const;
    Standard_Real       EpsCM() const;
    Standard_Real       Et() const;

private:

    void                InitializeEpsC();
    void                InitializeEpsCM();
    void                InitializeEt();
    Standard_Real       MonotonicDerivative(const Standard_Real Eps);
    Standard_Real       MonotonicDerivativeDerivative(const Standard_Real Eps);
    Standard_Real       MonotonicFunction(const Standard_Real Eps);

private:

    // Parameters
    Standard_Real   myA0;
    Standard_Real   myA1;
    Standard_Real   myA2;
    Standard_Real   myA3;
    Standard_Real   myA4;
    Standard_Real   myA5;
    Standard_Real   myA6;
    Standard_Real   myBeta;
    Standard_Real   myE;
    Standard_Real   myEpsM;
    Standard_Real   myFyc;

    // Computed parameters
    Standard_Real   myEpsC;
    Standard_Real   myEpsCM;
    Standard_Real   myEt;

    // History
    Standard_Real   myCurrentMaxStrain;
    Standard_Real   myCurrentMaxStress;
    Standard_Real   myCurrentMinStrain;
    Standard_Real   myCurrentMinStress;
    Standard_Real   myPreviousStrain;
    Standard_Real   myTrialStrain;
    Standard_Real   myTrialStress;




public:

    DEFINE_STANDARD_RTTIEXT(MaterialCLaw_UniaxialPolynomial01, Standard_Transient);

};

#endif  // __MaterialCLaw_UniaxialPolynomial01_hxx__
