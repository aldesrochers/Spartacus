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


#ifndef __matp_WireStressStrain01_hxx__
#define __matp_WireStressStrain01_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>


// ============================================================================
/*!
    \brief matp_WireStressStrain01
    Class implementation of the parameters of a cable wire stress-strain
    model. The 01 model is composed of a generic polynomial loading curve
    and a menegotto-pinto unloading/reloading curve.
*/
// ============================================================================
class matp_WireStressStrain01
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    matp_WireStressStrain01();
    matp_WireStressStrain01(const Standard_Real Ei,
                            const Standard_Real Ef,
                            const Standard_Real A0,
                            const Standard_Real A1,
                            const Standard_Real A2,
                            const Standard_Real A3,
                            const Standard_Real A4,
                            const Standard_Real A5,
                            const Standard_Real A6,
                            const Standard_Real EpsMax,
                            const Standard_Real R);
    // destructors
    ~matp_WireStressStrain01();

public:

    Standard_Real       A0() const;
    Standard_Real       A1() const;
    Standard_Real       A2() const;
    Standard_Real       A3() const;
    Standard_Real       A4() const;
    Standard_Real       A5() const;
    Standard_Real       A6() const;
    Standard_Real       Ef() const;
    Standard_Real       Ei() const;
    Standard_Real       EpsMax() const;
    Standard_Real       R() const;

    void        SetA0(const Standard_Real A0);
    void        SetA1(const Standard_Real A1);
    void        SetA2(const Standard_Real A2);
    void        SetA3(const Standard_Real A3);
    void        SetA4(const Standard_Real A4);
    void        SetA5(const Standard_Real A5);
    void        SetA6(const Standard_Real A6);
    void        SetEf(const Standard_Real Ef);
    void        SetEi(const Standard_Real Ei);
    void        SetEpsMax(const Standard_Real EpsMax);
    void        SetR(const Standard_Real R);

private:

    // initial and final elastic modulous
    Standard_Real       myEi;
    Standard_Real       myEf;

    // polynomial monotonic curve parameters
    Standard_Real       myA0;
    Standard_Real       myA1;
    Standard_Real       myA2;
    Standard_Real       myA3;
    Standard_Real       myA4;
    Standard_Real       myA5;
    Standard_Real       myA6;

    // maximum strain of the polynomial curve
    Standard_Real       myEpsMax;

    // menegotto-pinto unloading/reloading parameter
    Standard_Real       myR;

};

#endif  // __matp_WireStressStrain01_hxx__
