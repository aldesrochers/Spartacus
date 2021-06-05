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


#ifndef __Caelus_SpanEquilibrium_hxx__
#define __Caelus_SpanEquilibrium_hxx__


// OpenCascade
#include <Standard.hxx>



// ============================================================================
/*!
 *  \brief Caelus_SpanEquilibrium
 *  Base class implementation of an SpanEquilibrium.
*/
// ============================================================================
class Caelus_SpanEquilibrium
{

public:
    // constructors
    Caelus_SpanEquilibrium(const Standard_Real a,
                           const Standard_Real H,
                           const Standard_Real q);
    Caelus_SpanEquilibrium(const Standard_Real a,
                           const Standard_Real b,
                           const Standard_Real H,
                           const Standard_Real q);
    // destructors
    virtual ~Caelus_SpanEquilibrium();

public:

    Standard_Real   a() const;
    Standard_Real   b() const;
    Standard_Real   Dn() const;
    Standard_Real   F() const;
    Standard_Real   Fn() const;
    Standard_Real   H() const;
    Standard_Real   P() const;
    Standard_Real   q() const;
    Standard_Real   S() const;
    Standard_Real   s1() const;
    Standard_Real   s2() const;
    Standard_Real   Sn() const;
    Standard_Real   T1() const;
    Standard_Real   T2() const;
    Standard_Real   Tm() const;
    Standard_Real   Tmn() const;
    Standard_Real   Tn() const;
    Standard_Real   ub() const;
    Standard_Real   V1() const;
    Standard_Real   V2() const;
    Standard_Real   vb() const;
    Standard_Real   Z() const;

private:

    Standard_Real   myA;
    Standard_Real   myB;
    Standard_Real   myH;
    Standard_Real   myQ;

};

#endif  // __Caelus_SpanEquilibrium_hxx__
