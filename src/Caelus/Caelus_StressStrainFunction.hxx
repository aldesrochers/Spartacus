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


#ifndef __Caelus_StressStrainFunction_hxx__
#define __Caelus_StressStrainFunction_hxx__

// OpenCascade
#include <math_FunctionWithDerivative.hxx>

// Caelus
#include <Caelus_StressStrainCurve.hxx>


// ============================================================================
/*!
    \brief Caelus_StressStrainFunction
    Class implementation of a load case builder.
*/
// ============================================================================
class Caelus_StressStrainFunction
{

public:
    // constructors
    Caelus_StressStrainFunction();
    Caelus_StressStrainFunction(const Standard_Real A0);
    Caelus_StressStrainFunction(const Standard_Real A0,
                                const Standard_Real A1);
    Caelus_StressStrainFunction(const Standard_Real A0,
                                const Standard_Real A1,
                                const Standard_Real A2);
    Caelus_StressStrainFunction(const Standard_Real A0,
                                const Standard_Real A1,
                                const Standard_Real A2,
                                const Standard_Real A3);
    Caelus_StressStrainFunction(const Standard_Real A0,
                                const Standard_Real A1,
                                const Standard_Real A2,
                                const Standard_Real A3,
                                const Standard_Real A4);
    Caelus_StressStrainFunction(const Standard_Real A0,
                                const Standard_Real A1,
                                const Standard_Real A2,
                                const Standard_Real A3,
                                const Standard_Real A4,
                                const Standard_Real A5);
    Caelus_StressStrainFunction(const Standard_Real A0,
                                const Standard_Real A1,
                                const Standard_Real A2,
                                const Standard_Real A3,
                                const Standard_Real A4,
                                const Standard_Real A5,
                                const Standard_Real A6);
    Caelus_StressStrainFunction(const Caelus_StressStrainCurve& theCurve);
    // destructors
    ~Caelus_StressStrainFunction();

public:

    Standard_Real               A0() const;
    Standard_Real               A1() const;
    Standard_Real               A2() const;
    Standard_Real               A3() const;
    Standard_Real               A4() const;
    Standard_Real               A5() const;
    Standard_Real               A6() const;
    Caelus_StressStrainCurve    Curve() const;
    Standard_Boolean            Derivative(const Standard_Real X, Standard_Real& D);
    void                        SetA0(const Standard_Real& theA0);
    void                        SetA1(const Standard_Real& theA1);
    void                        SetA2(const Standard_Real& theA2);
    void                        SetA3(const Standard_Real& theA3);
    void                        SetA4(const Standard_Real& theA4);
    void                        SetA5(const Standard_Real& theA5);
    void                        SetA6(const Standard_Real& theA6);
    void                        SetCurve(const Caelus_StressStrainCurve& theCurve);
    Standard_Boolean            Value(const Standard_Real X, Standard_Real& F);
    Standard_Boolean            Values(const Standard_Real X, Standard_Real& F, Standard_Real& D);

private:

    Caelus_StressStrainCurve    myCurve;

};

#endif  // __Caelus_StressStrainFunction_hxx__
