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
#include <USSMP_CableWire02.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
USSMP_CableWire02::USSMP_CableWire02(const Standard_Real R,
                                     const Standard_Real B)
    : myA0(0.), myA1(0.), myA2(0.), myA3(0.), myA4(0.), myA5(0.), myA6(0.),
      myB(B), myE(0.), myEpsL(0.), myFc(0.), myR(R)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
USSMP_CableWire02::USSMP_CableWire02(const Standard_Real E,
                                     const Standard_Real Fc,
                                     const Standard_Real A0,
                                     const Standard_Real A1,
                                     const Standard_Real A2,
                                     const Standard_Real EpsL,
                                     const Standard_Real R,
                                     const Standard_Real B)
    : myA0(A0), myA1(A1), myA2(A2), myA3(0.), myA4(0.), myA5(0.), myA6(0.),
      myB(B), myE(E), myEpsL(EpsL), myFc(Fc), myR(R)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
USSMP_CableWire02::USSMP_CableWire02(const Standard_Real E,
                                     const Standard_Real Fc,
                                     const Standard_Real A0,
                                     const Standard_Real A1,
                                     const Standard_Real A2,
                                     const Standard_Real A3,
                                     const Standard_Real EpsL,
                                     const Standard_Real R,
                                     const Standard_Real B)
    : myA0(A0), myA1(A1), myA2(A2), myA3(A3), myA4(0.), myA5(0.), myA6(0.),
      myB(B), myE(E), myEpsL(EpsL), myFc(Fc), myR(R)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
USSMP_CableWire02::USSMP_CableWire02(const Standard_Real E,
                                     const Standard_Real Fc,
                                     const Standard_Real A0,
                                     const Standard_Real A1,
                                     const Standard_Real A2,
                                     const Standard_Real A3,
                                     const Standard_Real A4,
                                     const Standard_Real EpsL,
                                     const Standard_Real R,
                                     const Standard_Real B)
    : myA0(A0), myA1(A1), myA2(A2), myA3(A3), myA4(A4), myA5(0.), myA6(0.),
      myB(B), myE(E), myEpsL(EpsL), myFc(Fc), myR(R)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
USSMP_CableWire02::USSMP_CableWire02(const Standard_Real E,
                                     const Standard_Real Fc,
                                     const Standard_Real A0,
                                     const Standard_Real A1,
                                     const Standard_Real A2,
                                     const Standard_Real A3,
                                     const Standard_Real A4,
                                     const Standard_Real A5,
                                     const Standard_Real EpsL,
                                     const Standard_Real R,
                                     const Standard_Real B)
    : myA0(A0), myA1(A1), myA2(A2), myA3(A3), myA4(A4), myA5(A5), myA6(0.),
      myB(B), myE(E), myEpsL(EpsL), myFc(Fc), myR(R)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
USSMP_CableWire02::USSMP_CableWire02(const Standard_Real E,
                                     const Standard_Real Fc,
                                     const Standard_Real A0,
                                     const Standard_Real A1,
                                     const Standard_Real A2,
                                     const Standard_Real A3,
                                     const Standard_Real A4,
                                     const Standard_Real A5,
                                     const Standard_Real A6,
                                     const Standard_Real EpsL,
                                     const Standard_Real R,
                                     const Standard_Real B)
    : myA0(A0), myA1(A1), myA2(A2), myA3(A3), myA4(A4), myA5(A5), myA6(A6),
      myB(B), myE(E), myEpsL(EpsL), myFc(Fc), myR(R)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
USSMP_CableWire02::~USSMP_CableWire02()
{

}

// ============================================================================
/*!
    \brief A0()
*/
// ============================================================================
Standard_Real USSMP_CableWire02::A0() const
{
    return myA0;
}

// ============================================================================
/*!
 *  \brief A1()
*/
// ============================================================================
Standard_Real USSMP_CableWire02::A1() const
{
    return myA1;
}

// ============================================================================
/*!
 *  \brief A2()
*/
// ============================================================================
Standard_Real USSMP_CableWire02::A2() const
{
    return myA2;
}

// ============================================================================
/*!
 *  \brief A3()
*/
// ============================================================================
Standard_Real USSMP_CableWire02::A3() const
{
    return myA3;
}

// ============================================================================
/*!
 *  \brief A4()
*/
// ============================================================================
Standard_Real USSMP_CableWire02::A4() const
{
    return myA4;
}

// ============================================================================
/*!
 *  \brief A5()
*/
// ============================================================================
Standard_Real USSMP_CableWire02::A5() const
{
    return myA5;
}

// ============================================================================
/*!
 *  \brief A6()
*/
// ============================================================================
Standard_Real USSMP_CableWire02::A6() const
{
    return myA6;
}

// ============================================================================
/*!
 *  \brief B()
*/
// ============================================================================
Standard_Real USSMP_CableWire02::B() const
{
    return myB;
}

// ============================================================================
/*!
 *  \brief E()
*/
// ============================================================================
Standard_Real USSMP_CableWire02::E() const
{
    return myE;
}

// ============================================================================
/*!
    \brief EpsL()
*/
// ============================================================================
Standard_Real USSMP_CableWire02::EpsL() const
{
    return myEpsL;
}

// ============================================================================
/*!
 *  \brief Fc()
*/
// ============================================================================
Standard_Real USSMP_CableWire02::Fc() const
{
    return myFc;
}

// ============================================================================
/*!
    \brief R()
*/
// ============================================================================
Standard_Real USSMP_CableWire02::R() const
{
    return myR;
}

// ============================================================================
/*!
    \brief SetA0()
*/
// ============================================================================
void USSMP_CableWire02::SetA0(const Standard_Real A0)
{
    myA0 = A0;
}

// ============================================================================
/*!
 *  \brief SetA1()
*/
// ============================================================================
void USSMP_CableWire02::SetA1(const Standard_Real A1)
{
    myA1 = A1;
}

// ============================================================================
/*!
 *  \brief SetA2()
*/
// ============================================================================
void USSMP_CableWire02::SetA2(const Standard_Real A2)
{
    myA2 = A2;
}


// ============================================================================
/*!
 *  \brief SetA3()
*/
// ============================================================================
void USSMP_CableWire02::SetA3(const Standard_Real A3)
{
    myA3 = A3;
}

// ============================================================================
/*!
 *  \brief SetA4()
*/
// ============================================================================
void USSMP_CableWire02::SetA4(const Standard_Real A4)
{
    myA4 = A4;
}

// ============================================================================
/*!
 *  \brief SetA5()
*/
// ============================================================================
void USSMP_CableWire02::SetA5(const Standard_Real A5)
{
    myA5 = A5;
}

// ============================================================================
/*!
 *  \brief SetA6()
*/
// ============================================================================
void USSMP_CableWire02::SetA6(const Standard_Real A6)
{
    myA6 = A6;
}

// ============================================================================
/*!
 *  \brief SetB()
*/
// ============================================================================
void USSMP_CableWire02::SetB(const Standard_Real B)
{
    myB = B;
}

// ============================================================================
/*!
 *  \brief SetE()
*/
// ============================================================================
void USSMP_CableWire02::SetE(const Standard_Real E)
{
    myE = E;
}

// ============================================================================
/*!
    \brief SetEpsL()
*/
// ============================================================================
void USSMP_CableWire02::SetEpsL(const Standard_Real EpsL)
{
    myEpsL = EpsL;
}

// ============================================================================
/*!
 *  \brief SetFc()
*/
// ============================================================================
void USSMP_CableWire02::SetFc(const Standard_Real Fc)
{
    myFc = Fc;
}

// ============================================================================
/*!
    \brief SetR()
*/
// ============================================================================
void USSMP_CableWire02::SetR(const Standard_Real R)
{
    myR = R;
}
