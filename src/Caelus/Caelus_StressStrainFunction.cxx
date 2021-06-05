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


// Caelus
#include <Caelus_StressStrainFunction.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_StressStrainFunction::Caelus_StressStrainFunction()
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_StressStrainFunction::Caelus_StressStrainFunction(const Standard_Real A0)
{
    myCurve.SetA0(A0);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_StressStrainFunction::Caelus_StressStrainFunction(const Standard_Real A0,
                                                         const Standard_Real A1)
{
    myCurve.SetA0(A0);
    myCurve.SetA1(A1);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_StressStrainFunction::Caelus_StressStrainFunction(const Standard_Real A0,
                                                         const Standard_Real A1,
                                                         const Standard_Real A2)
{
    myCurve.SetA0(A0);
    myCurve.SetA1(A1);
    myCurve.SetA2(A2);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_StressStrainFunction::Caelus_StressStrainFunction(const Standard_Real A0,
                                                         const Standard_Real A1,
                                                         const Standard_Real A2,
                                                         const Standard_Real A3)
{
    myCurve.SetA0(A0);
    myCurve.SetA1(A1);
    myCurve.SetA2(A2);
    myCurve.SetA3(A3);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_StressStrainFunction::Caelus_StressStrainFunction(const Standard_Real A0,
                                                         const Standard_Real A1,
                                                         const Standard_Real A2,
                                                         const Standard_Real A3,
                                                         const Standard_Real A4)
{
    myCurve.SetA0(A0);
    myCurve.SetA1(A1);
    myCurve.SetA2(A2);
    myCurve.SetA3(A3);
    myCurve.SetA4(A4);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_StressStrainFunction::Caelus_StressStrainFunction(const Standard_Real A0,
                                                         const Standard_Real A1,
                                                         const Standard_Real A2,
                                                         const Standard_Real A3,
                                                         const Standard_Real A4,
                                                         const Standard_Real A5)
{
    myCurve.SetA0(A0);
    myCurve.SetA1(A1);
    myCurve.SetA2(A2);
    myCurve.SetA3(A3);
    myCurve.SetA4(A4);
    myCurve.SetA5(A5);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_StressStrainFunction::Caelus_StressStrainFunction(const Standard_Real A0,
                                                         const Standard_Real A1,
                                                         const Standard_Real A2,
                                                         const Standard_Real A3,
                                                         const Standard_Real A4,
                                                         const Standard_Real A5,
                                                         const Standard_Real A6)
{
    myCurve.SetA0(A0);
    myCurve.SetA1(A1);
    myCurve.SetA2(A2);
    myCurve.SetA3(A3);
    myCurve.SetA4(A4);
    myCurve.SetA5(A5);
    myCurve.SetA6(A6);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_StressStrainFunction::Caelus_StressStrainFunction(const Caelus_StressStrainCurve& theCurve)
    : myCurve(theCurve)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Caelus_StressStrainFunction::~Caelus_StressStrainFunction()
{

}

// ============================================================================
/*!
    \brief A0()
*/
// ============================================================================
Standard_Real Caelus_StressStrainFunction::A0() const
{
    return myCurve.A0();
}

// ============================================================================
/*!
    \brief A1()
*/
// ============================================================================
Standard_Real Caelus_StressStrainFunction::A1() const
{
    return myCurve.A1();
}

// ============================================================================
/*!
    \brief A2()
*/
// ============================================================================
Standard_Real Caelus_StressStrainFunction::A2() const
{
    return myCurve.A2();
}

// ============================================================================
/*!
    \brief A3()
*/
// ============================================================================
Standard_Real Caelus_StressStrainFunction::A3() const
{
    return myCurve.A3();
}

// ============================================================================
/*!
    \brief A4()
*/
// ============================================================================
Standard_Real Caelus_StressStrainFunction::A4() const
{
    return myCurve.A4();
}

// ============================================================================
/*!
    \brief A5()
*/
// ============================================================================
Standard_Real Caelus_StressStrainFunction::A5() const
{
    return myCurve.A5();
}

// ============================================================================
/*!
    \brief A6()
*/
// ============================================================================
Standard_Real Caelus_StressStrainFunction::A6() const
{
    return myCurve.A6();
}

// ============================================================================
/*!
    \brief Curve()
*/
// ============================================================================
Caelus_StressStrainCurve Caelus_StressStrainFunction::Curve() const
{
    return myCurve;
}

// ============================================================================
/*!
    \brief Derivative()
*/
// ============================================================================
Standard_Boolean Caelus_StressStrainFunction::Derivative(const Standard_Real X,
                                                         Standard_Real &D)
{
    D = 6.*A6()*Pow(X,5) + 5.*A5()*Pow(X,4) + 4.*A4()*Pow(X,3)
            + 3.*A3()*Pow(X,2) + 2.*A2()*Pow(X,1) + 1.*A1()*Pow(X,0);
    return Standard_True;
}

// ============================================================================
/*!
    \brief SetA0()
*/
// ============================================================================
void Caelus_StressStrainFunction::SetA0(const Standard_Real &theA0)
{
    myCurve.SetA0(theA0);
}

// ============================================================================
/*!
    \brief SetA1()
*/
// ============================================================================
void Caelus_StressStrainFunction::SetA1(const Standard_Real &theA1)
{
    myCurve.SetA1(theA1);
}

// ============================================================================
/*!
    \brief SetA2()
*/
// ============================================================================
void Caelus_StressStrainFunction::SetA2(const Standard_Real &theA2)
{
    myCurve.SetA2(theA2);
}

// ============================================================================
/*!
    \brief SetA3()
*/
// ============================================================================
void Caelus_StressStrainFunction::SetA3(const Standard_Real &theA3)
{
    myCurve.SetA3(theA3);
}

// ============================================================================
/*!
    \brief SetA4()
*/
// ============================================================================
void Caelus_StressStrainFunction::SetA4(const Standard_Real &theA4)
{
    myCurve.SetA4(theA4);
}

// ============================================================================
/*!
    \brief SetA5()
*/
// ============================================================================
void Caelus_StressStrainFunction::SetA5(const Standard_Real &theA5)
{
    myCurve.SetA5(theA5);
}

// ============================================================================
/*!
    \brief SetA6()
*/
// ============================================================================
void Caelus_StressStrainFunction::SetA6(const Standard_Real &theA6)
{
    myCurve.SetA6(theA6);
}

// ============================================================================
/*!
    \brief SetCurve()
*/
// ============================================================================
void Caelus_StressStrainFunction::SetCurve(const Caelus_StressStrainCurve &theCurve)
{
    myCurve = theCurve;
}

// ============================================================================
/*!
    \brief Value()
*/
// ============================================================================
Standard_Boolean Caelus_StressStrainFunction::Value(const Standard_Real X,
                                                    Standard_Real &F)
{
    F = A6()*Pow(X,6) + A5()*Pow(X,5) + A4()*Pow(X,4)
            + A3()*Pow(X,3) + A2()*Pow(X,2) + A1()*Pow(X,1) + A0();
    return Standard_True;
}

// ============================================================================
/*!
    \brief Values()
*/
// ============================================================================
Standard_Boolean Caelus_StressStrainFunction::Values(const Standard_Real X,
                                                     Standard_Real &F,
                                                     Standard_Real &D)
{
    Value(X, F);
    Derivative(X, D);
    return Standard_True;
}
