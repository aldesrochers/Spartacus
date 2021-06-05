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


#ifndef __Caelus_CreepCurve_hxx__
#define __Caelus_CreepCurve_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>


// ============================================================================
/*!
 *  \brief Caelus_CreepCurve
*/
// ============================================================================
class Caelus_CreepCurve
{

public:
    // constructors
    Caelus_CreepCurve();
    Caelus_CreepCurve(const Standard_Real C0);
    Caelus_CreepCurve(const Standard_Real C0,
                      const Standard_Real C1);
    Caelus_CreepCurve(const Standard_Real C0,
                      const Standard_Real C1,
                      const Standard_Real C2);
    Caelus_CreepCurve(const Standard_Real C0,
                      const Standard_Real C1,
                      const Standard_Real C2,
                      const Standard_Real C3);
    Caelus_CreepCurve(const Standard_Real C0,
                      const Standard_Real C1,
                      const Standard_Real C2,
                      const Standard_Real C3,
                      const Standard_Real C4);
    Caelus_CreepCurve(const Standard_Real C0,
                      const Standard_Real C1,
                      const Standard_Real C2,
                      const Standard_Real C3,
                      const Standard_Real C4,
                      const Standard_Real C5);
    Caelus_CreepCurve(const Standard_Real C0,
                      const Standard_Real C1,
                      const Standard_Real C2,
                      const Standard_Real C3,
                      const Standard_Real C4,
                      const Standard_Real C5,
                      const Standard_Real C6);
    // destructors
    virtual ~Caelus_CreepCurve();

public:

    Standard_Real           C0() const;
    Standard_Real           C1() const;
    Standard_Real           C2() const;
    Standard_Real           C3() const;
    Standard_Real           C4() const;
    Standard_Real           C5() const;
    Standard_Real           C6() const;

    void        SetC0(const Standard_Real C0);
    void        SetC1(const Standard_Real C1);
    void        SetC2(const Standard_Real C2);
    void        SetC3(const Standard_Real C3);
    void        SetC4(const Standard_Real C4);
    void        SetC5(const Standard_Real C5);
    void        SetC6(const Standard_Real C6);

private:

    Standard_Real           myC0;
    Standard_Real           myC1;
    Standard_Real           myC2;
    Standard_Real           myC3;
    Standard_Real           myC4;
    Standard_Real           myC5;
    Standard_Real           myC6;

};

#endif  // __Caelus_CreepCurve_hxx__
