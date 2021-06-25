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


#ifndef __fp_Polynomial_hxx__
#define __fp_Polynomial_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <TColStd_Array1OfReal.hxx>


// ============================================================================
/*!
    \brief fp_Polynomial
*/
// ============================================================================
class fp_Polynomial
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    fp_Polynomial();
    fp_Polynomial(const Standard_Real C0);
    fp_Polynomial(const Standard_Real C0,
                  const Standard_Real C1);
    fp_Polynomial(const Standard_Real C0,
                  const Standard_Real C1,
                  const Standard_Real C2);
    fp_Polynomial(const Standard_Real C0,
                  const Standard_Real C1,
                  const Standard_Real C2,
                  const Standard_Real C3);
    fp_Polynomial(const Standard_Real C0,
                  const Standard_Real C1,
                  const Standard_Real C2,
                  const Standard_Real C3,
                  const Standard_Real C4);
    fp_Polynomial(const Standard_Real C0,
                  const Standard_Real C1,
                  const Standard_Real C2,
                  const Standard_Real C3,
                  const Standard_Real C4,
                  const Standard_Real C5);
    fp_Polynomial(const Standard_Real C0,
                  const Standard_Real C1,
                  const Standard_Real C2,
                  const Standard_Real C3,
                  const Standard_Real C4,
                  const Standard_Real C5,
                  const Standard_Real C6);
    fp_Polynomial(const TColStd_Array1OfReal& theCoefficients);
    // destructors
    ~fp_Polynomial();

public:

    Standard_Real           C0() const;
    Standard_Real           C1() const;
    Standard_Real           C2() const;
    Standard_Real           C3() const;
    Standard_Real           C4() const;
    Standard_Real           C5() const;
    Standard_Real           C6() const;
    Standard_Real           Coefficient(const Standard_Integer theDegree) const;
    TColStd_Array1OfReal    Coefficients() const;

    void                    SetC0(const Standard_Real C0);
    void                    SetC1(const Standard_Real C1);
    void                    SetC2(const Standard_Real C2);
    void                    SetC3(const Standard_Real C3);
    void                    SetC4(const Standard_Real C4);
    void                    SetC5(const Standard_Real C5);
    void                    SetC6(const Standard_Real C6);
    void                    SetCoefficient(const Standard_Integer theDegree,
                                           const Standard_Real theCoefficient);

private:

    TColStd_Array1OfReal    myCoefficients;

};

#endif  // __fp_Polynomial_hxx__
