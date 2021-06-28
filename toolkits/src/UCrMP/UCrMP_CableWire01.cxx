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


// Spartacus
#include <UCrMP_CableWire01.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
UCrMP_CableWire01::UCrMP_CableWire01()
    : myA1(0.), myA2(0.), myA3(0.),
      myB1(0.), myB2(0.), myB3(0.),
      myC(0.),
      myE(0.),
      myT0(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
UCrMP_CableWire01::UCrMP_CableWire01(const Standard_Real E,
                                     const Standard_Real A1,
                                     const Standard_Real A2,
                                     const Standard_Real A3,
                                     const Standard_Real B1,
                                     const Standard_Real B2,
                                     const Standard_Real B3)
    : myA1(A1), myA2(A2), myA3(A3),
      myB1(B1), myB2(B2), myB3(B3),
      myC(0.),
      myE(E),
      myT0(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
UCrMP_CableWire01::UCrMP_CableWire01(const Standard_Real E,
                                     const Standard_Real A1,
                                     const Standard_Real A2,
                                     const Standard_Real A3,
                                     const Standard_Real B1,
                                     const Standard_Real B2,
                                     const Standard_Real B3,
                                     const Standard_Real C)
    : myA1(A1), myA2(A2), myA3(A3),
      myB1(B1), myB2(B2), myB3(B3),
      myC(C),
      myE(E),
      myT0(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
UCrMP_CableWire01::UCrMP_CableWire01(const Standard_Real E,
                                     const Standard_Real A1,
                                     const Standard_Real A2,
                                     const Standard_Real A3,
                                     const Standard_Real B1,
                                     const Standard_Real B2,
                                     const Standard_Real B3,
                                     const Standard_Real C,
                                     const Standard_Real T0)
    : myA1(A1), myA2(A2), myA3(A3),
      myB1(B1), myB2(B2), myB3(B3),
      myC(C),
      myE(E),
      myT0(T0)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
UCrMP_CableWire01::~UCrMP_CableWire01()
{

}

// ============================================================================
/*!
 *  \brief A1()
*/
// ============================================================================
Standard_Real UCrMP_CableWire01::A1() const
{
    return myA1;
}

// ============================================================================
/*!
 *  \brief A2()
*/
// ============================================================================
Standard_Real UCrMP_CableWire01::A2() const
{
    return myA2;
}

// ============================================================================
/*!
 *  \brief A3()
*/
// ============================================================================
Standard_Real UCrMP_CableWire01::A3() const
{
    return myA3;
}

// ============================================================================
/*!
 *  \brief B1()
*/
// ============================================================================
Standard_Real UCrMP_CableWire01::B1() const
{
    return myB1;
}

// ============================================================================
/*!
 *  \brief B2()
*/
// ============================================================================
Standard_Real UCrMP_CableWire01::B2() const
{
    return myB2;
}

// ============================================================================
/*!
 *  \brief B3()
*/
// ============================================================================
Standard_Real UCrMP_CableWire01::B3() const
{
    return myB3;
}

// ============================================================================
/*!
 *  \brief C()
*/
// ============================================================================
Standard_Real UCrMP_CableWire01::C() const
{
    return myC;
}

// ============================================================================
/*!
 *  \brief E()
*/
// ============================================================================
Standard_Real UCrMP_CableWire01::E() const
{
    return myE;
}

// ============================================================================
/*!
    \brief T0()
*/
// ============================================================================
Standard_Real UCrMP_CableWire01::T0() const
{
    return myT0;
}

// ============================================================================
/*!
 *  \brief SetA1()
*/
// ============================================================================
void UCrMP_CableWire01::SetA1(const Standard_Real A1)
{
    myA1 = A1;
}

// ============================================================================
/*!
 *  \brief SetA2()
*/
// ============================================================================
void UCrMP_CableWire01::SetA2(const Standard_Real A2)
{
    myA2 = A2;
}


// ============================================================================
/*!
 *  \brief SetA3()
*/
// ============================================================================
void UCrMP_CableWire01::SetA3(const Standard_Real A3)
{
    myA3 = A3;
}

// ============================================================================
/*!
 *  \brief SetB1()
*/
// ============================================================================
void UCrMP_CableWire01::SetB1(const Standard_Real B1)
{
    myB1 = B1;
}

// ============================================================================
/*!
 *  \brief SetB2()
*/
// ============================================================================
void UCrMP_CableWire01::SetB2(const Standard_Real B2)
{
    myB2 = B2;
}


// ============================================================================
/*!
 *  \brief SetB3()
*/
// ============================================================================
void UCrMP_CableWire01::SetB3(const Standard_Real B3)
{
    myB3 = B3;
}

// ============================================================================
/*!
 *  \brief SetC()
*/
// ============================================================================
void UCrMP_CableWire01::SetC(const Standard_Real C)
{
    myC = C;
}

// ============================================================================
/*!
 *  \brief SetE()
*/
// ============================================================================
void UCrMP_CableWire01::SetE(const Standard_Real E)
{
    myE = E;
}

// ============================================================================
/*!
    \brief SetT0()
*/
// ============================================================================
void UCrMP_CableWire01::SetT0(const Standard_Real T0)
{
    myT0 = T0;
}
