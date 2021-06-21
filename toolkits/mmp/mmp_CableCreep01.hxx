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


#ifndef __mmp_CableCreep01_hxx__
#define __mmp_CableCreep01_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>


// ============================================================================
/*!
    \brief mmp_CableCreep01

    Class implementation of CabelCreep01 model parameters. This model is a
    simple multi-linear that must be fitted on experimental data.
*/
// ============================================================================
class mmp_CableCreep01
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    mmp_CableCreep01();
    // destructors
    ~mmp_CableCreep01();

public:

    Standard_Real   A0() const;
    Standard_Real   A1() const;
    Standard_Real   A2() const;
    Standard_Real   A3() const;
    Standard_Real   B0() const;
    Standard_Real   B1() const;
    Standard_Real   B2() const;
    Standard_Real   B3() const;
    Standard_Real   Phi() const;
    Standard_Real   Sig0() const;
    Standard_Real   Sig1() const;
    Standard_Real   Sig2() const;
    Standard_Real   Sig3() const;
    Standard_Real   T0() const;

    void        SetA0(const Standard_Real A0);
    void        SetA1(const Standard_Real A1);
    void        SetA2(const Standard_Real A2);
    void        SetA3(const Standard_Real A3);
    void        SetB0(const Standard_Real B0);
    void        SetB1(const Standard_Real B1);
    void        SetB2(const Standard_Real B2);
    void        SetB3(const Standard_Real B3);
    void        SetPhi(const Standard_Real Phi);
    void        SetSig0(const Standard_Real Sig0);
    void        SetSig1(const Standard_Real Sig1);
    void        SetSig2(const Standard_Real Sig2);
    void        SetSig3(const Standard_Real Sig3);
    void        SetT0(const Standard_Real T0);

private:

    Standard_Real   myA0;
    Standard_Real   myA1;
    Standard_Real   myA2;
    Standard_Real   myA3;
    Standard_Real   myB0;
    Standard_Real   myB1;
    Standard_Real   myB2;
    Standard_Real   myB3;
    Standard_Real   myPhi;
    Standard_Real   mySig0;
    Standard_Real   mySig1;
    Standard_Real   mySig2;
    Standard_Real   mySig3;
    Standard_Real   myT0;

};

#endif  // __mmp_CableCreep01_hxx__
