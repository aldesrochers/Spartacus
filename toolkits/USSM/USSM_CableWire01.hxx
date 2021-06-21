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


#ifndef __USSM_CableWire01_hxx__
#define __USSM_CableWire01_hxx__

// Spartacus
#include <USSM_Model.hxx>

// Forward declarations
class USSM_CableWire01;

// Handles
DEFINE_STANDARD_HANDLE(USSM_CableWire01, USSM_Model);


// ============================================================================
/*!
    \brief USSM_CableWire01

    Class implementation of a generic cable wire material with a polynomial
    monotonic stress-strain curve and a menegotto-pinto unloading/reloading
    curve.

    Ei, Ef -> Initial/Final elastic modulous
    A0-A5 -> Coefficients of the monotonic loading curve
    R -> Menegotto-Pinto shape parameter
*/
// ============================================================================
class USSM_CableWire01 : public USSM_Model
{

public:
    // constructors
    USSM_CableWire01(const Standard_Real Ei,
                     const Standard_Real Ef,
                     const Standard_Real EpsMax,
                     const Standard_Real A0,
                     const Standard_Real A1,
                     const Standard_Real A2,
                     const Standard_Real A3,
                     const Standard_Real A4,
                     const Standard_Real A5,
                     const Standard_Real R);
    // destructors
    ~USSM_CableWire01();

public:

    virtual Standard_Boolean    CommitState();
    virtual Standard_Real       GetInitialStiffness() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToInitialState();
    virtual Standard_Boolean    UpdateInternalState();

protected:

    virtual Standard_Real       MenegottoStiffness(const Standard_Real theStrain);
    virtual Standard_Real       MenegottoStress(const Standard_Real theStrain);
    virtual Standard_Real       MonotonicStiffness(const Standard_Real theStrain);
    virtual Standard_Real       MonotonicStress(const Standard_Real theStrain);
    virtual Standard_Real       PolynomialStiffness(const Standard_Real theStrain);
    virtual Standard_Real       PolynomialStress(const Standard_Real theStrain);

protected:

    // Parameters
    Standard_Real       myA0;
    Standard_Real       myA1;
    Standard_Real       myA2;
    Standard_Real       myA3;
    Standard_Real       myA4;
    Standard_Real       myA5;
    Standard_Real       myEf;
    Standard_Real       myEi;
    Standard_Real       myEpsMax;
    Standard_Real       myR;

    // Additionnal history
    Standard_Real       myCurrentMaxStrain;
    Standard_Real       myCurrentMaxStress;
    Standard_Real       myCurrentMinStrain;
    Standard_Real       myCurrentMinStress;
    Standard_Integer    myIsInitialLoading;
    Standard_Integer    myPreviousDirection;

public:

    DEFINE_STANDARD_RTTIEXT(USSM_CableWire01, USSM_Model);

};

#endif  // __USSM_CableWire01_hxx__
