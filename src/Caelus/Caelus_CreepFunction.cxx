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
#include <Caelus_CreepFunction.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_CreepFunction::Caelus_CreepFunction()
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_CreepFunction::Caelus_CreepFunction(const Standard_Real C0)
{
    myCurve.SetC0(C0);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_CreepFunction::Caelus_CreepFunction(const Standard_Real C0,
                                                         const Standard_Real C1)
{
    myCurve.SetC0(C0);
    myCurve.SetC1(C1);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_CreepFunction::Caelus_CreepFunction(const Standard_Real C0,
                                                         const Standard_Real C1,
                                                         const Standard_Real C2)
{
    myCurve.SetC0(C0);
    myCurve.SetC1(C1);
    myCurve.SetC2(C2);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_CreepFunction::Caelus_CreepFunction(const Standard_Real C0,
                                                         const Standard_Real C1,
                                                         const Standard_Real C2,
                                                         const Standard_Real C3)
{
    myCurve.SetC0(C0);
    myCurve.SetC1(C1);
    myCurve.SetC2(C2);
    myCurve.SetC3(C3);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_CreepFunction::Caelus_CreepFunction(const Standard_Real C0,
                                                         const Standard_Real C1,
                                                         const Standard_Real C2,
                                                         const Standard_Real C3,
                                                         const Standard_Real C4)
{
    myCurve.SetC0(C0);
    myCurve.SetC1(C1);
    myCurve.SetC2(C2);
    myCurve.SetC3(C3);
    myCurve.SetC4(C4);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_CreepFunction::Caelus_CreepFunction(const Standard_Real C0,
                                                         const Standard_Real C1,
                                                         const Standard_Real C2,
                                                         const Standard_Real C3,
                                                         const Standard_Real C4,
                                                         const Standard_Real C5)
{
    myCurve.SetC0(C0);
    myCurve.SetC1(C1);
    myCurve.SetC2(C2);
    myCurve.SetC3(C3);
    myCurve.SetC4(C4);
    myCurve.SetC5(C5);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_CreepFunction::Caelus_CreepFunction(const Standard_Real C0,
                                                         const Standard_Real C1,
                                                         const Standard_Real C2,
                                                         const Standard_Real C3,
                                                         const Standard_Real C4,
                                                         const Standard_Real C5,
                                                         const Standard_Real C6)
{
    myCurve.SetC0(C0);
    myCurve.SetC1(C1);
    myCurve.SetC2(C2);
    myCurve.SetC3(C3);
    myCurve.SetC4(C4);
    myCurve.SetC5(C5);
    myCurve.SetC6(C6);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_CreepFunction::Caelus_CreepFunction(const Caelus_CreepCurve& theCurve)
    : myCurve(theCurve)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Caelus_CreepFunction::~Caelus_CreepFunction()
{

}

// ============================================================================
/*!
    \brief C0()
*/
// ============================================================================
Standard_Real Caelus_CreepFunction::C0() const
{
    return myCurve.C0();
}

// ============================================================================
/*!
    \brief C1()
*/
// ============================================================================
Standard_Real Caelus_CreepFunction::C1() const
{
    return myCurve.C1();
}

// ============================================================================
/*!
    \brief C2()
*/
// ============================================================================
Standard_Real Caelus_CreepFunction::C2() const
{
    return myCurve.C2();
}

// ============================================================================
/*!
    \brief C3()
*/
// ============================================================================
Standard_Real Caelus_CreepFunction::C3() const
{
    return myCurve.C3();
}

// ============================================================================
/*!
    \brief C4()
*/
// ============================================================================
Standard_Real Caelus_CreepFunction::C4() const
{
    return myCurve.C4();
}

// ============================================================================
/*!
    \brief C5()
*/
// ============================================================================
Standard_Real Caelus_CreepFunction::C5() const
{
    return myCurve.C5();
}

// ============================================================================
/*!
    \brief C6()
*/
// ============================================================================
Standard_Real Caelus_CreepFunction::C6() const
{
    return myCurve.C6();
}

// ============================================================================
/*!
    \brief Curve()
*/
// ============================================================================
Caelus_CreepCurve Caelus_CreepFunction::Curve() const
{
    return myCurve;
}

// ============================================================================
/*!
    \brief Derivative()
*/
// ============================================================================
Standard_Boolean Caelus_CreepFunction::Derivative(const Standard_Real X,
                                                         Standard_Real &D)
{
    D = 6.*C6()*Pow(X,5) + 5.*C5()*Pow(X,4) + 4.*C4()*Pow(X,3)
            + 3.*C3()*Pow(X,2) + 2.*C2()*Pow(X,1) + 1.*C1()*Pow(X,0);
    return Standard_True;
}

// ============================================================================
/*!
    \brief SetC0()
*/
// ============================================================================
void Caelus_CreepFunction::SetC0(const Standard_Real &theC0)
{
    myCurve.SetC0(theC0);
}

// ============================================================================
/*!
    \brief SetC1()
*/
// ============================================================================
void Caelus_CreepFunction::SetC1(const Standard_Real &theC1)
{
    myCurve.SetC1(theC1);
}

// ============================================================================
/*!
    \brief SetC2()
*/
// ============================================================================
void Caelus_CreepFunction::SetC2(const Standard_Real &theC2)
{
    myCurve.SetC2(theC2);
}

// ============================================================================
/*!
    \brief SetC3()
*/
// ============================================================================
void Caelus_CreepFunction::SetC3(const Standard_Real &theC3)
{
    myCurve.SetC3(theC3);
}

// ============================================================================
/*!
    \brief SetC4()
*/
// ============================================================================
void Caelus_CreepFunction::SetC4(const Standard_Real &theC4)
{
    myCurve.SetC4(theC4);
}

// ============================================================================
/*!
    \brief SetC5()
*/
// ============================================================================
void Caelus_CreepFunction::SetC5(const Standard_Real &theC5)
{
    myCurve.SetC5(theC5);
}

// ============================================================================
/*!
    \brief SetC6()
*/
// ============================================================================
void Caelus_CreepFunction::SetC6(const Standard_Real &theC6)
{
    myCurve.SetC6(theC6);
}

// ============================================================================
/*!
    \brief SetCurve()
*/
// ============================================================================
void Caelus_CreepFunction::SetCurve(const Caelus_CreepCurve &theCurve)
{
    myCurve = theCurve;
}

// ============================================================================
/*!
    \brief Value()
*/
// ============================================================================
Standard_Boolean Caelus_CreepFunction::Value(const Standard_Real X,
                                                    Standard_Real &F)
{
    F = C6()*Pow(X,6) + C5()*Pow(X,5) + C4()*Pow(X,4)
            + C3()*Pow(X,3) + C2()*Pow(X,2) + C1()*Pow(X,1) + C0();
    return Standard_True;
}

// ============================================================================
/*!
    \brief Values()
*/
// ============================================================================
Standard_Boolean Caelus_CreepFunction::Values(const Standard_Real X,
                                                     Standard_Real &F,
                                                     Standard_Real &D)
{
    Value(X, F);
    Derivative(X, D);
    return Standard_True;
}
