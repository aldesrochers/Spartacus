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


#ifndef __MaterialFLib_PolynomialCurve_hxx__
#define __MaterialFLib_PolynomialCurve_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <math_Vector.hxx>


// ============================================================================
/*!
 *  \brief MaterialFLib_PolynomialCurve
 *  Equation of the form A*x^6 + B*x^5 + C*x^4 + D*x^3 + E*x^2 + F*x + G
*/
// ============================================================================
class MaterialFLib_PolynomialCurve : public math_FunctionWithDerivative
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Standard_EXPORT MaterialFLib_PolynomialCurve(const Standard_Real A);
    Standard_EXPORT MaterialFLib_PolynomialCurve(const Standard_Real A,
                                                 const Standard_Real B);
    Standard_EXPORT MaterialFLib_PolynomialCurve(const Standard_Real A,
                                                 const Standard_Real B,
                                                 const Standard_Real C);
    Standard_EXPORT MaterialFLib_PolynomialCurve(const Standard_Real A,
                                                 const Standard_Real B,
                                                 const Standard_Real C,
                                                 const Standard_Real D);
    Standard_EXPORT MaterialFLib_PolynomialCurve(const Standard_Real A,
                                                 const Standard_Real B,
                                                 const Standard_Real C,
                                                 const Standard_Real D,
                                                 const Standard_Real E);
    Standard_EXPORT MaterialFLib_PolynomialCurve(const Standard_Real A,
                                                 const Standard_Real B,
                                                 const Standard_Real C,
                                                 const Standard_Real D,
                                                 const Standard_Real E,
                                                 const Standard_Real F);
    Standard_EXPORT MaterialFLib_PolynomialCurve(const Standard_Real A,
                                                 const Standard_Real B,
                                                 const Standard_Real C,
                                                 const Standard_Real D,
                                                 const Standard_Real E,
                                                 const Standard_Real F,
                                                 const Standard_Real G);
    // destructors
    Standard_EXPORT virtual ~MaterialFLib_PolynomialCurve();

public:

    Standard_EXPORT virtual Standard_Boolean Derivative(const Standard_Real X,
                                                        Standard_Real& D) Standard_OVERRIDE;
    Standard_EXPORT virtual Standard_Boolean Value(const Standard_Real X,
                                                   Standard_Real& F) Standard_OVERRIDE;
    Standard_EXPORT virtual Standard_Boolean Values(const Standard_Real X,
                                                    Standard_Real& F,
                                                    Standard_Real& D) Standard_OVERRIDE;

private:

    Standard_Real       myA;
    Standard_Real       myB;
    Standard_Real       myC;
    Standard_Real       myD;
    Standard_Real       myE;
    Standard_Real       myF;
    Standard_Real       myG;


};

#endif  // __MaterialFLib_PolynomialCurve_hxx__
