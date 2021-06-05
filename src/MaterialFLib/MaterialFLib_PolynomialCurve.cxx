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

// material
#include <MaterialFLib_PolynomialCurve.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MaterialFLib_PolynomialCurve::MaterialFLib_PolynomialCurve(const Standard_Real A)
    : myA(A), myB(0.), myC(0.), myD(0.), myE(0.), myF(0.), myG(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MaterialFLib_PolynomialCurve::MaterialFLib_PolynomialCurve(const Standard_Real A,
                                                           const Standard_Real B)
    : myA(A), myB(B), myC(0.), myD(0.), myE(0.), myF(0.), myG(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MaterialFLib_PolynomialCurve::MaterialFLib_PolynomialCurve(const Standard_Real A,
                                                           const Standard_Real B,
                                                           const Standard_Real C)
    : myA(A), myB(B), myC(C), myD(0.), myE(0.), myF(0.), myG(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MaterialFLib_PolynomialCurve::MaterialFLib_PolynomialCurve(const Standard_Real A,
                                                           const Standard_Real B,
                                                           const Standard_Real C,
                                                           const Standard_Real D)
    : myA(A), myB(B), myC(C), myD(D), myE(0.), myF(0.), myG(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MaterialFLib_PolynomialCurve::MaterialFLib_PolynomialCurve(const Standard_Real A,
                                                           const Standard_Real B,
                                                           const Standard_Real C,
                                                           const Standard_Real D,
                                                           const Standard_Real E)
    : myA(A), myB(B), myC(C), myD(D), myE(E), myF(0.), myG(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MaterialFLib_PolynomialCurve::MaterialFLib_PolynomialCurve(const Standard_Real A,
                                                           const Standard_Real B,
                                                           const Standard_Real C,
                                                           const Standard_Real D,
                                                           const Standard_Real E,
                                                           const Standard_Real F)
    : myA(A), myB(B), myC(C), myD(D), myE(E), myF(F), myG(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MaterialFLib_PolynomialCurve::MaterialFLib_PolynomialCurve(const Standard_Real A,
                                                           const Standard_Real B,
                                                           const Standard_Real C,
                                                           const Standard_Real D,
                                                           const Standard_Real E,
                                                           const Standard_Real F,
                                                           const Standard_Real G)
    : myA(A), myB(B), myC(C), myD(D), myE(E), myF(F), myG(G)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MaterialFLib_PolynomialCurve::~MaterialFLib_PolynomialCurve()
{

}

// ============================================================================
/*!
    \brief Derivative()
*/
// ============================================================================
Standard_Boolean MaterialFLib_PolynomialCurve::Derivative(const Standard_Real X,
                                                          Standard_Real &D)
{
    D = 6.*myA*Pow(X,5) + 5.*myB*Pow(X,4) + 4.*myC*Pow(X,3)
            + 3.*myD*Pow(X,2) + 2.*myE*Pow(X,1) + 1.*myF;
    return Standard_True;
}

// ============================================================================
/*!
    \brief Value()
*/
// ============================================================================
Standard_Boolean MaterialFLib_PolynomialCurve::Value(const Standard_Real X,
                                                     Standard_Real &F)
{
    F = myA*Pow(X,6) + myB*Pow(X,5) + myC*Pow(X,4)
            + myD*Pow(X,3) + myE*Pow(X,2) + myF*Pow(X,1) + myG;
    return Standard_True;
}

// ============================================================================
/*!
    \brief Values()
*/
// ============================================================================
Standard_Boolean MaterialFLib_PolynomialCurve::Values(const Standard_Real X,
                                                      Standard_Real &F,
                                                      Standard_Real &D)
{
    Value(X,F);
    Derivative(X,D);
}




