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
#include <Caelus_SpanEquilibrium.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_SpanEquilibrium::Caelus_SpanEquilibrium(const Standard_Real a,
                                               const Standard_Real H,
                                               const Standard_Real q)
    : myA(a), myB(0.), myH(H), myQ(q)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Caelus_SpanEquilibrium::Caelus_SpanEquilibrium(const Standard_Real a,
                                               const Standard_Real b,
                                               const Standard_Real H,
                                               const Standard_Real q)
    : myA(a), myB(b), myH(H), myQ(q)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Caelus_SpanEquilibrium::~Caelus_SpanEquilibrium()
{

}

// ============================================================================
/*!
 *  \brief a()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::a() const
{
    return myA;
}

// ============================================================================
/*!
 *  \brief b()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::b() const
{
    return myB;
}

// ============================================================================
/*!
 *  \brief Dn()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::Dn() const
{
    return a() * Cosh(a() / (2. * P()));
}

// ============================================================================
/*!
 *  \brief F()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::F() const
{
    return S() / Sn() * Fn();
}

// ============================================================================
/*!
 *  \brief Fn()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::Fn() const
{
    return P() * (Cosh(a() / (2. * P())) - 1.);
}

// ============================================================================
/*!
 *  \brief H()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::H() const
{
    return myH;
}

// ============================================================================
/*!
 *  \brief P()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::P() const
{
    return H() / q();
}

// ============================================================================
/*!
 *  \brief q()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::q() const
{
    return myQ;
}

// ============================================================================
/*!
 *  \brief S()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::S() const
{
    return Sqrt(Pow(Sn(), 2.) + Pow(b(), 2.));
}

// ============================================================================
/*!
 *  \brief s1()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::s1() const
{
    return P() * Sinh(ub() / P());
}

// ============================================================================
/*!
 *  \brief s2()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::s2() const
{
    return S() - s1();
}

// ============================================================================
/*!
 *  \brief Sn()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::Sn() const
{
    return 2. * P() * Sinh(a() / (2. * P()));
}

// ============================================================================
/*!
 *  \brief T1()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::T1() const
{
    return S() / Sn() * Tn() - q() * b() / 2.;
}

// ============================================================================
/*!
 *  \brief T2()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::T2() const
{
    return S() / Sn() * Tn() + q() * b() / 2.;
}

// ============================================================================
/*!
 *  \brief Tm()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::Tm() const
{
    return 1. / 2. * ((s1() * T1() + s2() * T2())/S() + a() * H()/S());
}

// ============================================================================
/*!
 *  \brief Tmn()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::Tmn() const
{
    return 1./2. * ((H() * a() + Tn() * Sn())/Sn());
}

// ============================================================================
/*!
 *  \brief Tn()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::Tn() const
{
    return H() * Cosh(a() / (2. * P()));
}

// ============================================================================
/*!
 *  \brief ub()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::ub() const
{
    return a() / 2. - P() * ASinh(b() / Sn());
}

// ============================================================================
/*!
 *  \brief V1()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::V1() const
{
    return q() * s1();
}

// ============================================================================
/*!
 *  \brief V2()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::V2() const
{
    return q() * s2();
}

// ============================================================================
/*!
 *  \brief vb()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::vb() const
{
    return P() * (1. - Cosh(ub() / P()));
}

// ============================================================================
/*!
 *  \brief Z()
*/
// ============================================================================
Standard_Real Caelus_SpanEquilibrium::Z() const
{
    return a() / (2. * P());
}
