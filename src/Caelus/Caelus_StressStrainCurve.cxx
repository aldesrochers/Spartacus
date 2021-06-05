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
#include <Caelus_StressStrainCurve.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_StressStrainCurve::Caelus_StressStrainCurve()
    : myA0(0.), myA1(0.), myA2(0.), myA3(0.), myA4(0.), myA5(0.), myA6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_StressStrainCurve::Caelus_StressStrainCurve(const Standard_Real A0)
    : myA0(A0), myA1(0.), myA2(0.), myA3(0.), myA4(0.), myA5(0.), myA6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_StressStrainCurve::Caelus_StressStrainCurve(const Standard_Real A0,
                                                   const Standard_Real A1)
    : myA0(A0), myA1(A1), myA2(0.), myA3(0.), myA4(0.), myA5(0.), myA6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_StressStrainCurve::Caelus_StressStrainCurve(const Standard_Real A0,
                                                   const Standard_Real A1,
                                                   const Standard_Real A2)
    : myA0(A0), myA1(A1), myA2(A2), myA3(0.), myA4(0.), myA5(0.), myA6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_StressStrainCurve::Caelus_StressStrainCurve(const Standard_Real A0,
                                                   const Standard_Real A1,
                                                   const Standard_Real A2,
                                                   const Standard_Real A3)
    : myA0(A0), myA1(A1), myA2(A2), myA3(A3), myA4(0.), myA5(0.), myA6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_StressStrainCurve::Caelus_StressStrainCurve(const Standard_Real A0,
                                                   const Standard_Real A1,
                                                   const Standard_Real A2,
                                                   const Standard_Real A3,
                                                   const Standard_Real A4)
    : myA0(A0), myA1(A1), myA2(A2), myA3(A3), myA4(A4), myA5(0.), myA6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_StressStrainCurve::Caelus_StressStrainCurve(const Standard_Real A0,
                                                   const Standard_Real A1,
                                                   const Standard_Real A2,
                                                   const Standard_Real A3,
                                                   const Standard_Real A4,
                                                   const Standard_Real A5)
    : myA0(A0), myA1(A1), myA2(A2), myA3(A3), myA4(A4), myA5(A5), myA6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_StressStrainCurve::Caelus_StressStrainCurve(const Standard_Real A0,
                                                   const Standard_Real A1,
                                                   const Standard_Real A2,
                                                   const Standard_Real A3,
                                                   const Standard_Real A4,
                                                   const Standard_Real A5,
                                                   const Standard_Real A6)
    : myA0(A0), myA1(A1), myA2(A2), myA3(A3), myA4(A4), myA5(A5), myA6(A6)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Caelus_StressStrainCurve::~Caelus_StressStrainCurve()
{

}

// ============================================================================
/*!
    \brief A0()
*/
// ============================================================================
Standard_Real Caelus_StressStrainCurve::A0() const
{
    return myA0;
}

// ============================================================================
/*!
    \brief A1()
*/
// ============================================================================
Standard_Real Caelus_StressStrainCurve::A1() const
{
    return myA1;
}

// ============================================================================
/*!
    \brief A2()
*/
// ============================================================================
Standard_Real Caelus_StressStrainCurve::A2() const
{
    return myA2;
}

// ============================================================================
/*!
    \brief A3()
*/
// ============================================================================
Standard_Real Caelus_StressStrainCurve::A3() const
{
    return myA3;
}

// ============================================================================
/*!
    \brief A4()
*/
// ============================================================================
Standard_Real Caelus_StressStrainCurve::A4() const
{
    return myA4;
}

// ============================================================================
/*!
    \brief A5()
*/
// ============================================================================
Standard_Real Caelus_StressStrainCurve::A5() const
{
    return myA5;
}

// ============================================================================
/*!
    \brief A6()
*/
// ============================================================================
Standard_Real Caelus_StressStrainCurve::A6() const
{
    return myA6;
}

// ============================================================================
/*!
    \brief SetA0()
*/
// ============================================================================
void Caelus_StressStrainCurve::SetA0(const Standard_Real A0)
{
    myA0 = A0;
}

// ============================================================================
/*!
    \brief SetA1()
*/
// ============================================================================
void Caelus_StressStrainCurve::SetA1(const Standard_Real A1)
{
    myA1 = A1;
}

// ============================================================================
/*!
    \brief SetA2()
*/
// ============================================================================
void Caelus_StressStrainCurve::SetA2(const Standard_Real A2)
{
    myA2 = A2;
}

// ============================================================================
/*!
    \brief SetA3()
*/
// ============================================================================
void Caelus_StressStrainCurve::SetA3(const Standard_Real A3)
{
    myA3 = A3;
}

// ============================================================================
/*!
    \brief SetA4()
*/
// ============================================================================
void Caelus_StressStrainCurve::SetA4(const Standard_Real A4)
{
    myA4 = A4;
}

// ============================================================================
/*!
    \brief SetA5()
*/
// ============================================================================
void Caelus_StressStrainCurve::SetA5(const Standard_Real A5)
{
    myA5 = A5;
}

// ============================================================================
/*!
    \brief SetA6()
*/
// ============================================================================
void Caelus_StressStrainCurve::SetA6(const Standard_Real A6)
{
    myA6 = A6;
}

