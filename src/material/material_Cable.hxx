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


#ifndef __material_Cable_hxx__
#define __material_Cable_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>


// ============================================================================
/*!
 *  \brief material_Cable
*/
// ============================================================================
class material_Cable
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    material_Cable();
    // destructors
    ~material_Cable();

public:

    Standard_Real   A0() const;
    Standard_Real   A1() const;
    Standard_Real   A2() const;
    Standard_Real   A3() const;
    Standard_Real   A4() const;
    Standard_Real   A5() const;
    Standard_Real   A6() const;
    Standard_Real   Alpha() const;
    Standard_Real   C0() const;
    Standard_Real   C1() const;
    Standard_Real   C2() const;
    Standard_Real   C3() const;
    Standard_Real   C4() const;
    Standard_Real   C5() const;
    Standard_Real   C6() const;
    Standard_Real   E() const;
    Standard_Real   Ect() const;
    Standard_Real   Fyc() const;

    void    SetA0(const Standard_Real A0);
    void    SetA1(const Standard_Real A1);
    void    SetA2(const Standard_Real A2);
    void    SetA3(const Standard_Real A3);
    void    SetA4(const Standard_Real A4);
    void    SetA5(const Standard_Real A5);
    void    SetA6(const Standard_Real A6);
    void    SetAlpha(const Standard_Real Alpha);
    void    SetC0(const Standard_Real C0);
    void    SetC1(const Standard_Real C1);
    void    SetC2(const Standard_Real C2);
    void    SetC3(const Standard_Real C3);
    void    SetC4(const Standard_Real C4);
    void    SetC5(const Standard_Real C5);
    void    SetC6(const Standard_Real C6);
    void    SetE(const Standard_Real E);
    void    SetEct(const Standard_Real Ect);
    void    SetFyc(const Standard_Real Fyc);

private:

    Standard_Real   myA0;
    Standard_Real   myA1;
    Standard_Real   myA2;
    Standard_Real   myA3;
    Standard_Real   myA4;
    Standard_Real   myA5;
    Standard_Real   myA6;
    Standard_Real   myAlpha;
    Standard_Real   myC0;
    Standard_Real   myC1;
    Standard_Real   myC2;
    Standard_Real   myC3;
    Standard_Real   myC4;
    Standard_Real   myC5;
    Standard_Real   myC6;
    Standard_Real   myE;
    Standard_Real   myEct;
    Standard_Real   myFyc;

};

#endif  // __material_Cable_hxx__
