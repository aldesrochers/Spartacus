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

// cable
#include <fp_Polynomial.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
fp_Polynomial::fp_Polynomial()
{
    myCoefficients.Resize(0, 6, Standard_True);
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
fp_Polynomial::fp_Polynomial(const Standard_Real C0)
{
    myCoefficients.Resize(0, 6, Standard_True);
    myCoefficients.SetValue(0, C0);
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
fp_Polynomial::fp_Polynomial(const Standard_Real C0,
                             const Standard_Real C1)
{
    myCoefficients.Resize(0, 6, Standard_True);
    myCoefficients.SetValue(0, C0);
    myCoefficients.SetValue(1, C1);
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
fp_Polynomial::fp_Polynomial(const Standard_Real C0,
                             const Standard_Real C1,
                             const Standard_Real C2)
{
    myCoefficients.Resize(0, 6, Standard_True);
    myCoefficients.SetValue(0, C0);
    myCoefficients.SetValue(1, C1);
    myCoefficients.SetValue(2, C2);
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
fp_Polynomial::fp_Polynomial(const Standard_Real C0,
                             const Standard_Real C1,
                             const Standard_Real C2,
                             const Standard_Real C3)
{
    myCoefficients.Resize(0, 6, Standard_True);
    myCoefficients.SetValue(0, C0);
    myCoefficients.SetValue(1, C1);
    myCoefficients.SetValue(2, C2);
    myCoefficients.SetValue(3, C3);
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
fp_Polynomial::fp_Polynomial(const Standard_Real C0,
                             const Standard_Real C1,
                             const Standard_Real C2,
                             const Standard_Real C3,
                             const Standard_Real C4)
{
    myCoefficients.Resize(0, 6, Standard_True);
    myCoefficients.SetValue(0, C0);
    myCoefficients.SetValue(1, C1);
    myCoefficients.SetValue(2, C2);
    myCoefficients.SetValue(3, C3);
    myCoefficients.SetValue(4, C4);
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
fp_Polynomial::fp_Polynomial(const Standard_Real C0,
                             const Standard_Real C1,
                             const Standard_Real C2,
                             const Standard_Real C3,
                             const Standard_Real C4,
                             const Standard_Real C5)
{
    myCoefficients.Resize(0, 6, Standard_True);
    myCoefficients.SetValue(0, C0);
    myCoefficients.SetValue(1, C1);
    myCoefficients.SetValue(2, C2);
    myCoefficients.SetValue(3, C3);
    myCoefficients.SetValue(4, C4);
    myCoefficients.SetValue(5, C5);
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
fp_Polynomial::fp_Polynomial(const Standard_Real C0,
                             const Standard_Real C1,
                             const Standard_Real C2,
                             const Standard_Real C3,
                             const Standard_Real C4,
                             const Standard_Real C5,
                             const Standard_Real C6)
{
    myCoefficients.Resize(0, 6, Standard_True);
    myCoefficients.SetValue(0, C0);
    myCoefficients.SetValue(1, C1);
    myCoefficients.SetValue(2, C2);
    myCoefficients.SetValue(3, C3);
    myCoefficients.SetValue(4, C4);
    myCoefficients.SetValue(5, C5);
    myCoefficients.SetValue(6, C6);
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
fp_Polynomial::fp_Polynomial(const TColStd_Array1OfReal& theCoefficients)
    : myCoefficients(theCoefficients)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
fp_Polynomial::~fp_Polynomial()
{

}

// ============================================================================
/*!
 *  \brief C0()
*/
// ============================================================================
Standard_Real fp_Polynomial::C0() const
{
    return myCoefficients.Value(0);
}

// ============================================================================
/*!
 *  \brief C1()
*/
// ============================================================================
Standard_Real fp_Polynomial::C1() const
{
    return myCoefficients.Value(1);
}

// ============================================================================
/*!
 *  \brief C2()
*/
// ============================================================================
Standard_Real fp_Polynomial::C2() const
{
    return myCoefficients.Value(2);
}

// ============================================================================
/*!
 *  \brief C3()
*/
// ============================================================================
Standard_Real fp_Polynomial::C3() const
{
    return myCoefficients.Value(3);
}

// ============================================================================
/*!
 *  \brief C4()
*/
// ============================================================================
Standard_Real fp_Polynomial::C4() const
{
    return myCoefficients.Value(4);
}

// ============================================================================
/*!
 *  \brief C5()
*/
// ============================================================================
Standard_Real fp_Polynomial::C5() const
{
    return myCoefficients.Value(5);
}

// ============================================================================
/*!
 *  \brief C6()
*/
// ============================================================================
Standard_Real fp_Polynomial::C6() const
{
    return myCoefficients.Value(6);
}

// ============================================================================
/*!
 *  \brief Coefficient()
*/
// ============================================================================
Standard_Real fp_Polynomial::Coefficient(const Standard_Integer theDegree) const
{
    if(theDegree > myCoefficients.Size())
        return 0.;
    return myCoefficients.Value(theDegree);
}

// ============================================================================
/*!
 *  \brief Coefficients()
*/
// ============================================================================
TColStd_Array1OfReal fp_Polynomial::Coefficients() const
{
    return myCoefficients;
}

// ============================================================================
/*!
 *  \brief SetC0()
*/
// ============================================================================
void fp_Polynomial::SetC0(const Standard_Real C0)
{
    myCoefficients.SetValue(0, C0);
}

// ============================================================================
/*!
 *  \brief SetC1()
*/
// ============================================================================
void fp_Polynomial::SetC1(const Standard_Real C1)
{
    myCoefficients.SetValue(1, C1);
}

// ============================================================================
/*!
 *  \brief SetC2()
*/
// ============================================================================
void fp_Polynomial::SetC2(const Standard_Real C2)
{
    myCoefficients.SetValue(2, C2);
}

// ============================================================================
/*!
 *  \brief SetC3()
*/
// ============================================================================
void fp_Polynomial::SetC3(const Standard_Real C3)
{
    myCoefficients.SetValue(3, C3);
}

// ============================================================================
/*!
 *  \brief SetC4()
*/
// ============================================================================
void fp_Polynomial::SetC4(const Standard_Real C4)
{
    myCoefficients.SetValue(4, C4);
}

// ============================================================================
/*!
 *  \brief SetC5()
*/
// ============================================================================
void fp_Polynomial::SetC5(const Standard_Real C5)
{
    myCoefficients.SetValue(5, C5);
}

// ============================================================================
/*!
 *  \brief SetC6()
*/
// ============================================================================
void fp_Polynomial::SetC6(const Standard_Real C6)
{
    myCoefficients.SetValue(6, C6);
}

// ============================================================================
/*!
 *  \brief SetCoefficient()
*/
// ============================================================================
void fp_Polynomial::SetCoefficient(const Standard_Integer theDegree,
                                   const Standard_Real theCoefficient)
{
    if(theDegree > myCoefficients.Size())
        myCoefficients.Resize(0, theDegree, Standard_True);
    myCoefficients.SetValue(theDegree, theCoefficient);
}
