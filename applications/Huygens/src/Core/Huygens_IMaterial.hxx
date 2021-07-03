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

#ifndef __Huygens_IMaterial_hxx__
#define __Huygens_IMaterial_hxx__

// Huygens
#include <Huygens_Material.hxx>

// Properties
#define ATTR_E      1
#define ATTR_EpsL   2
#define ATTR_A0     3
#define ATTR_A1     4
#define ATTR_A2     5
#define ATTR_A3     6
#define ATTR_A4     7
#define ATTR_A5     8
#define ATTR_A6     9
#define ATTR_Alpha  10
#define ATTR_B1     11
#define ATTR_B2     12
#define ATTR_B3     13
#define ATTR_B4     14
#define ATTR_B5     15
#define ATTR_B6     16
#define ATTR_C      17
#define ATTR_T0     18


// ============================================================================
/*!
 *  \brief Huygens_IMaterial
*/
// ============================================================================
class Huygens_IMaterial
{

public:
    // constructors
    Huygens_IMaterial(Handle(Huygens_Material) theObject)
        : myObject(theObject) {}

public:

    Standard_Real   GetA0() {return myObject->GetRealAttr(ATTR_A0);}
    Standard_Real   GetA1() {return myObject->GetRealAttr(ATTR_A1);}
    Standard_Real   GetA2() {return myObject->GetRealAttr(ATTR_A2);}
    Standard_Real   GetA3() {return myObject->GetRealAttr(ATTR_A3);}
    Standard_Real   GetA4() {return myObject->GetRealAttr(ATTR_A4);}
    Standard_Real   GetA5() {return myObject->GetRealAttr(ATTR_A5);}
    Standard_Real   GetA6() {return myObject->GetRealAttr(ATTR_A6);}
    Standard_Real   GetAlpha() {return myObject->GetRealAttr(ATTR_Alpha);}
    Standard_Real   GetB1() {return myObject->GetRealAttr(ATTR_B1);}
    Standard_Real   GetB2() {return myObject->GetRealAttr(ATTR_B2);}
    Standard_Real   GetB3() {return myObject->GetRealAttr(ATTR_B3);}
    Standard_Real   GetB4() {return myObject->GetRealAttr(ATTR_B4);}
    Standard_Real   GetB5() {return myObject->GetRealAttr(ATTR_B5);}
    Standard_Real   GetB6() {return myObject->GetRealAttr(ATTR_B6);}
    Standard_Real   GetC() {return myObject->GetRealAttr(ATTR_C);}
    Standard_Real   GetE() {return myObject->GetRealAttr(ATTR_E);}
    Standard_Real   GetEpsL() {return myObject->GetRealAttr(ATTR_EpsL);}
    Standard_Real   GetT0() {return myObject->GetRealAttr(ATTR_T0);}

    void    SetA0(const Standard_Real A0) {myObject->SetRealAttr(ATTR_A0, A0);}
    void    SetA1(const Standard_Real A1) {myObject->SetRealAttr(ATTR_A1, A1);}
    void    SetA2(const Standard_Real A2) {myObject->SetRealAttr(ATTR_A2, A2);}
    void    SetA3(const Standard_Real A3) {myObject->SetRealAttr(ATTR_A3, A3);}
    void    SetA4(const Standard_Real A4) {myObject->SetRealAttr(ATTR_A4, A4);}
    void    SetA5(const Standard_Real A5) {myObject->SetRealAttr(ATTR_A5, A5);}
    void    SetA6(const Standard_Real A6) {myObject->SetRealAttr(ATTR_A6, A6);}
    void    SetAlpha(const Standard_Real Alpha) {myObject->SetRealAttr(ATTR_Alpha, Alpha);}
    void    SetB1(const Standard_Real B1) {myObject->SetRealAttr(ATTR_B1, B1);}
    void    SetB2(const Standard_Real B2) {myObject->SetRealAttr(ATTR_B2, B2);}
    void    SetB3(const Standard_Real B3) {myObject->SetRealAttr(ATTR_B3, B3);}
    void    SetB4(const Standard_Real B4) {myObject->SetRealAttr(ATTR_B4, B4);}
    void    SetB5(const Standard_Real B5) {myObject->SetRealAttr(ATTR_B5, B5);}
    void    SetB6(const Standard_Real B6) {myObject->SetRealAttr(ATTR_B6, B6);}
    void    SetC(const Standard_Real C) {myObject->SetRealAttr(ATTR_C, C);}
    void    SetE(const Standard_Real E) {myObject->SetRealAttr(ATTR_E, E);}
    void    SetEpsL(const Standard_Real EpsL) {myObject->SetRealAttr(ATTR_EpsL, EpsL);}
    void    SetT0(const Standard_Real T0) {myObject->SetRealAttr(ATTR_T0, T0);}

private:

    Handle(Huygens_Material)  myObject;

};

#endif  // __Huygens_IMaterial_hxx__
