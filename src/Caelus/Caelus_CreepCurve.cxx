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
#include <Caelus_CreepCurve.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_CreepCurve::Caelus_CreepCurve()
    : myC0(0.), myC1(0.), myC2(0.), myC3(0.), myC4(0.), myC5(0.), myC6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_CreepCurve::Caelus_CreepCurve(const Standard_Real C0)
    : myC0(C0), myC1(0.), myC2(0.), myC3(0.), myC4(0.), myC5(0.), myC6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_CreepCurve::Caelus_CreepCurve(const Standard_Real C0,
                                                   const Standard_Real C1)
    : myC0(C0), myC1(C1), myC2(0.), myC3(0.), myC4(0.), myC5(0.), myC6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_CreepCurve::Caelus_CreepCurve(const Standard_Real C0,
                                                   const Standard_Real C1,
                                                   const Standard_Real C2)
    : myC0(C0), myC1(C1), myC2(C2), myC3(0.), myC4(0.), myC5(0.), myC6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_CreepCurve::Caelus_CreepCurve(const Standard_Real C0,
                                                   const Standard_Real C1,
                                                   const Standard_Real C2,
                                                   const Standard_Real C3)
    : myC0(C0), myC1(C1), myC2(C2), myC3(C3), myC4(0.), myC5(0.), myC6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_CreepCurve::Caelus_CreepCurve(const Standard_Real C0,
                                                   const Standard_Real C1,
                                                   const Standard_Real C2,
                                                   const Standard_Real C3,
                                                   const Standard_Real C4)
    : myC0(C0), myC1(C1), myC2(C2), myC3(C3), myC4(C4), myC5(0.), myC6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_CreepCurve::Caelus_CreepCurve(const Standard_Real C0,
                                                   const Standard_Real C1,
                                                   const Standard_Real C2,
                                                   const Standard_Real C3,
                                                   const Standard_Real C4,
                                                   const Standard_Real C5)
    : myC0(C0), myC1(C1), myC2(C2), myC3(C3), myC4(C4), myC5(C5), myC6(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_CreepCurve::Caelus_CreepCurve(const Standard_Real C0,
                                                   const Standard_Real C1,
                                                   const Standard_Real C2,
                                                   const Standard_Real C3,
                                                   const Standard_Real C4,
                                                   const Standard_Real C5,
                                                   const Standard_Real C6)
    : myC0(C0), myC1(C1), myC2(C2), myC3(C3), myC4(C4), myC5(C5), myC6(C6)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Caelus_CreepCurve::~Caelus_CreepCurve()
{

}

// ============================================================================
/*!
    \brief C0()
*/
// ============================================================================
Standard_Real Caelus_CreepCurve::C0() const
{
    return myC0;
}

// ============================================================================
/*!
    \brief C1()
*/
// ============================================================================
Standard_Real Caelus_CreepCurve::C1() const
{
    return myC1;
}

// ============================================================================
/*!
    \brief C2()
*/
// ============================================================================
Standard_Real Caelus_CreepCurve::C2() const
{
    return myC2;
}

// ============================================================================
/*!
    \brief C3()
*/
// ============================================================================
Standard_Real Caelus_CreepCurve::C3() const
{
    return myC3;
}

// ============================================================================
/*!
    \brief C4()
*/
// ============================================================================
Standard_Real Caelus_CreepCurve::C4() const
{
    return myC4;
}

// ============================================================================
/*!
    \brief C5()
*/
// ============================================================================
Standard_Real Caelus_CreepCurve::C5() const
{
    return myC5;
}

// ============================================================================
/*!
    \brief C6()
*/
// ============================================================================
Standard_Real Caelus_CreepCurve::C6() const
{
    return myC6;
}

// ============================================================================
/*!
    \brief SetC0()
*/
// ============================================================================
void Caelus_CreepCurve::SetC0(const Standard_Real C0)
{
    myC0 = C0;
}

// ============================================================================
/*!
    \brief SetC1()
*/
// ============================================================================
void Caelus_CreepCurve::SetC1(const Standard_Real C1)
{
    myC1 = C1;
}

// ============================================================================
/*!
    \brief SetC2()
*/
// ============================================================================
void Caelus_CreepCurve::SetC2(const Standard_Real C2)
{
    myC2 = C2;
}

// ============================================================================
/*!
    \brief SetC3()
*/
// ============================================================================
void Caelus_CreepCurve::SetC3(const Standard_Real C3)
{
    myC3 = C3;
}

// ============================================================================
/*!
    \brief SetC4()
*/
// ============================================================================
void Caelus_CreepCurve::SetC4(const Standard_Real C4)
{
    myC4 = C4;
}

// ============================================================================
/*!
    \brief SetC5()
*/
// ============================================================================
void Caelus_CreepCurve::SetC5(const Standard_Real C5)
{
    myC5 = C5;
}

// ============================================================================
/*!
    \brief SetC6()
*/
// ============================================================================
void Caelus_CreepCurve::SetC6(const Standard_Real C6)
{
    myC6 = C6;
}

