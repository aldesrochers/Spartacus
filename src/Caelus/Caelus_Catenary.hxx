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


#ifndef __Caelus_Catenary_hxx__
#define __Caelus_Catenary_hxx__

// OpenCascade
#include <Standard_Real.hxx>


// ============================================================================
/*!
 *  \brief Caelus_Catenary
 *  This class provide some standard 'catenary' equilibrium equations.
*/
// ============================================================================
class Caelus_Catenary
{

public:

    static Standard_Real    c(const Standard_Real a,
                              const Standard_Real b);
    static Standard_Real    Dn(const Standard_Real P,
                               const Standard_Real a);
    static Standard_Real    Dn(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a);
    static Standard_Real    F(const Standard_Real P,
                              const Standard_Real a,
                              const Standard_Real b);
    static Standard_Real    F(const Standard_Real H,
                              const Standard_Real w,
                              const Standard_Real a,
                              const Standard_Real b);
    static Standard_Real    Fn(const Standard_Real P,
                               const Standard_Real a);
    static Standard_Real    Fn(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a);
    static Standard_Real    TM(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a,
                               const Standard_Real b);
    static Standard_Real    TMn(const Standard_Real H,
                                const Standard_Real w,
                                const Standard_Real a);
    static Standard_Real    R1(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a,
                               const Standard_Real b);
    static Standard_Real    R2(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a,
                               const Standard_Real b);
    static Standard_Real    P(const Standard_Real H,
                              const Standard_Real w);
    static Standard_Real    S(const Standard_Real P,
                              const Standard_Real a,
                              const Standard_Real b);
    static Standard_Real    S(const Standard_Real H,
                              const Standard_Real w,
                              const Standard_Real a,
                              const Standard_Real b);
    static Standard_Real    s1(const Standard_Real P,
                               const Standard_Real a,
                               const Standard_Real b);
    static Standard_Real    s1(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a,
                               const Standard_Real b);
    static Standard_Real    s2(const Standard_Real P,
                               const Standard_Real a,
                               const Standard_Real b);
    static Standard_Real    s2(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a,
                               const Standard_Real b);
    static Standard_Real    Sn(const Standard_Real P,
                               const Standard_Real a);
    static Standard_Real    Sn(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a);
    static Standard_Real    T1(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a,
                               const Standard_Real b);
    static Standard_Real    T2(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a,
                               const Standard_Real b);
    static Standard_Real    Tn(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a);
    static Standard_Real    ub(const Standard_Real P,
                               const Standard_Real a,
                               const Standard_Real b);
    static Standard_Real    ub(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a,
                               const Standard_Real b);
    static Standard_Real    vb(const Standard_Real H,
                               const Standard_Real w,
                               const Standard_Real a,
                               const Standard_Real b);
    static Standard_Real    y(const Standard_Real P,
                              const Standard_Real x);
    static Standard_Real    y(const Standard_Real H,
                              const Standard_Real w,
                              const Standard_Real x);
    static Standard_Real    Z(const Standard_Real P,
                              const Standard_Real a);

};

#endif  // __Caelus_Catenary_hxx__
