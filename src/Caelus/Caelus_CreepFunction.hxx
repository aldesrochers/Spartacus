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


#ifndef __Caelus_CreepFunction_hxx__
#define __Caelus_CreepFunction_hxx__

// OpenCascade
#include <math_FunctionWithDerivative.hxx>

// Caelus
#include <Caelus_CreepCurve.hxx>


// ============================================================================
/*!
    \brief Caelus_CreepFunction
    Class implementation of a load case builder.
*/
// ============================================================================
class Caelus_CreepFunction
{

public:
    // constructors
    Caelus_CreepFunction();
    Caelus_CreepFunction(const Standard_Real C0);
    Caelus_CreepFunction(const Standard_Real C0,
                         const Standard_Real C1);
    Caelus_CreepFunction(const Standard_Real C0,
                         const Standard_Real C1,
                         const Standard_Real C2);
    Caelus_CreepFunction(const Standard_Real C0,
                         const Standard_Real C1,
                         const Standard_Real C2,
                         const Standard_Real C3);
    Caelus_CreepFunction(const Standard_Real C0,
                         const Standard_Real C1,
                         const Standard_Real C2,
                         const Standard_Real C3,
                         const Standard_Real C4);
    Caelus_CreepFunction(const Standard_Real C0,
                         const Standard_Real C1,
                         const Standard_Real C2,
                         const Standard_Real C3,
                         const Standard_Real C4,
                         const Standard_Real C5);
    Caelus_CreepFunction(const Standard_Real C0,
                         const Standard_Real C1,
                         const Standard_Real C2,
                         const Standard_Real C3,
                         const Standard_Real C4,
                         const Standard_Real C5,
                         const Standard_Real C6);
    Caelus_CreepFunction(const Caelus_CreepCurve& theCurve);
    // destructors
    ~Caelus_CreepFunction();

public:

    Standard_Real               C0() const;
    Standard_Real               C1() const;
    Standard_Real               C2() const;
    Standard_Real               C3() const;
    Standard_Real               C4() const;
    Standard_Real               C5() const;
    Standard_Real               C6() const;
    Caelus_CreepCurve           Curve() const;
    Standard_Boolean            Derivative(const Standard_Real X, Standard_Real& D);
    void                        SetC0(const Standard_Real& theC0);
    void                        SetC1(const Standard_Real& theC1);
    void                        SetC2(const Standard_Real& theC2);
    void                        SetC3(const Standard_Real& theC3);
    void                        SetC4(const Standard_Real& theC4);
    void                        SetC5(const Standard_Real& theC5);
    void                        SetC6(const Standard_Real& theC6);
    void                        SetCurve(const Caelus_CreepCurve& theCurve);
    Standard_Boolean            Value(const Standard_Real X, Standard_Real& F);
    Standard_Boolean            Values(const Standard_Real X, Standard_Real& F, Standard_Real& D);

private:

    Caelus_CreepCurve           myCurve;

};

#endif  // __Caelus_CreepFunction_hxx__
