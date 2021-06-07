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
#include <FLib_Catenary.hxx>


// ============================================================================
/*!
    \brief c()
*/
// ============================================================================
Standard_Real FLib_Catenary::c(const Standard_Real a,
                                 const Standard_Real b)
{
    return Sqrt(Pow(a, 2) + Pow(b, 2));
}

// ============================================================================
/*!
    \brief Dn()
*/
// ============================================================================
Standard_Real FLib_Catenary::Dn(const Standard_Real P,
                                  const Standard_Real a)
{
    return a * (Cosh(a/(2.*P)));
}

// ============================================================================
/*!
    \brief Dn()
*/
// ============================================================================
Standard_Real FLib_Catenary::Dn(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a)
{
    return Dn(P(H, w), a);
}

// ============================================================================
/*!
    \brief F()
*/
// ============================================================================
Standard_Real FLib_Catenary::F(const Standard_Real P,
                                 const Standard_Real a,
                                 const Standard_Real b)
{
    return S(P,a,b)/Sn(P,a) * Fn(P,a);
}

// ============================================================================
/*!
    \brief F()
*/
// ============================================================================
Standard_Real FLib_Catenary::F(const Standard_Real H,
                                 const Standard_Real w,
                                 const Standard_Real a,
                                 const Standard_Real b)
{
    return F(P(H,w), a, b);
}

// ============================================================================
/*!
    \brief Fn()
*/
// ============================================================================
Standard_Real FLib_Catenary::Fn(const Standard_Real P,
                                  const Standard_Real a)
{
    return P * (Cosh(a/(2.*P)) -1.);
}

// ============================================================================
/*!
    \brief Fn()
*/
// ============================================================================
Standard_Real FLib_Catenary::Fn(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a)
{
    return Fn(P(H, w), a);
}

// ============================================================================
/*!
    \brief TM()
*/
// ============================================================================
Standard_Real FLib_Catenary::TM(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a,
                                  const Standard_Real b)
{
    Standard_Real aS = S(H,w,a,b);
    Standard_Real aT1 = T1(H,w,a,b);
    Standard_Real aT2 = T2(H,w,a,b);
    Standard_Real as1 = s1(H,w,a,b);
    Standard_Real as2 = s2(H,w,a,b);
    return 0.5 * ((as1*aT1+as2*aT2)/aS + a*H/aS);
}

// ============================================================================
/*!
    \brief TMn()
*/
// ============================================================================
Standard_Real FLib_Catenary::TMn(const Standard_Real H,
                                   const Standard_Real w,
                                   const Standard_Real a)
{
    Standard_Real aTn = Tn(H, w, a);
    Standard_Real aSn = Sn(H, w, a);
    return 0.5 * ((H*a+aTn*aSn)/aSn);
}

// ============================================================================
/*!
    \brief R1()
*/
// ============================================================================
Standard_Real FLib_Catenary::R1(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a,
                                  const Standard_Real b)
{
    return w * s1(H,w,a,b);
}

// ============================================================================
/*!
    \brief R2()
*/
// ============================================================================
Standard_Real FLib_Catenary::R2(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a,
                                  const Standard_Real b)
{
    return w * s2(H,w,a,b);
}

// ============================================================================
/*!
    \brief P()
*/
// ============================================================================
Standard_Real FLib_Catenary::P(const Standard_Real H,
                                 const Standard_Real w)
{
    return H / w;
}

// ============================================================================
/*!
    \brief S()
*/
// ============================================================================
Standard_Real FLib_Catenary::S(const Standard_Real P,
                                 const Standard_Real a,
                                 const Standard_Real b)
{
    return Sn(P,a) * Sqrt(Pow(b/Sn(P,a), 2) + 1.);
}

// ============================================================================
/*!
    \brief S()
*/
// ============================================================================
Standard_Real FLib_Catenary::S(const Standard_Real H,
                                 const Standard_Real w,
                                 const Standard_Real a,
                                 const Standard_Real b)
{
    return S(P(H,w), a, b);
}

// ============================================================================
/*!
    \brief s1()
*/
// ============================================================================
Standard_Real FLib_Catenary::s1(const Standard_Real P,
                                  const Standard_Real a,
                                  const Standard_Real b)
{
    return P*Sinh(ub(P, a, b)/P);
}

// ============================================================================
/*!
    \brief s1()
*/
// ============================================================================
Standard_Real FLib_Catenary::s1(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a,
                                  const Standard_Real b)
{
    return s1(P(H,w), a, b);
}

// ============================================================================
/*!
    \brief s2()
*/
// ============================================================================
Standard_Real FLib_Catenary::s2(const Standard_Real P,
                                  const Standard_Real a,
                                  const Standard_Real b)
{
    return S(P,a,b) - s1(P,a,b);
}

// ============================================================================
/*!
    \brief s2()
*/
// ============================================================================
Standard_Real FLib_Catenary::s2(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a,
                                  const Standard_Real b)
{
    return s2(P(H,w), a, b);
}

// ============================================================================
/*!
    \brief Sn()
*/
// ============================================================================
Standard_Real FLib_Catenary::Sn(const Standard_Real P,
                                  const Standard_Real a)
{
    return 2.*P*Sinh(a/(2.*P));
}

// ============================================================================
/*!
    \brief Sn()
*/
// ============================================================================
Standard_Real FLib_Catenary::Sn(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a)
{
    return Sn(P(H, w), a);
}

// ============================================================================
/*!
    \brief T1()
*/
// ============================================================================
Standard_Real FLib_Catenary::T1(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a,
                                  const Standard_Real b)
{
    return H*Cosh(ub(P(H,w),a,b)/P(H,w));
}

// ============================================================================
/*!
    \brief T2()
*/
// ============================================================================
Standard_Real FLib_Catenary::T2(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a,
                                  const Standard_Real b)
{
    return H*Cosh((a-ub(P(H,w),a,b))/P(H,w));
}

// ============================================================================
/*!
    \brief Tn()
*/
// ============================================================================
Standard_Real FLib_Catenary::Tn(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a)
{
    return H*Cosh(a/(2.*P(H, w)));
}

// ============================================================================
/*!
    \brief ub()
*/
// ============================================================================
Standard_Real FLib_Catenary::ub(const Standard_Real P,
                                  const Standard_Real a,
                                  const Standard_Real b)
{
    return a/2. - P * ASinh(b/Sn(P,a));
}

// ============================================================================
/*!
    \brief ub()
*/
// ============================================================================
Standard_Real FLib_Catenary::ub(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a,
                                  const Standard_Real b)
{
    return ub(P(H,w), a, b);
}

// ============================================================================
/*!
    \brief vb()
*/
// ============================================================================
Standard_Real FLib_Catenary::vb(const Standard_Real H,
                                  const Standard_Real w,
                                  const Standard_Real a,
                                  const Standard_Real b)
{
    return P(H,w)*(1.-S(P(H,w),a,b)*Tn(H,w,a)/(Sn(P(H,w),a)*H)) + b/2.;
}

// ============================================================================
/*!
    \brief y()
*/
// ============================================================================
Standard_Real FLib_Catenary::y(const Standard_Real P,
                                 const Standard_Real x)
{
    return P * (Cosh(x/P) - 1.);
}

// ============================================================================
/*!
    \brief y()
*/
// ============================================================================
Standard_Real FLib_Catenary::y(const Standard_Real H,
                                 const Standard_Real w,
                                 const Standard_Real x)
{
    return y(P(H,w), x);
}

// ============================================================================
/*!
    \brief Z()
*/
// ============================================================================
Standard_Real FLib_Catenary::Z(const Standard_Real P,
                                 const Standard_Real a)
{
    return a / (2. * P);
}
