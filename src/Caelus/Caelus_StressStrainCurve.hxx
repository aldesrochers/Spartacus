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


#ifndef __Caelus_StressStrainCurve_hxx__
#define __Caelus_StressStrainCurve_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>


// ============================================================================
/*!
 *  \brief Caelus_StressStrainCurve
*/
// ============================================================================
class Caelus_StressStrainCurve
{

public:
    // constructors
    Caelus_StressStrainCurve();
    Caelus_StressStrainCurve(const Standard_Real A0);
    Caelus_StressStrainCurve(const Standard_Real A0,
                             const Standard_Real A1);
    Caelus_StressStrainCurve(const Standard_Real A0,
                             const Standard_Real A1,
                             const Standard_Real A2);
    Caelus_StressStrainCurve(const Standard_Real A0,
                             const Standard_Real A1,
                             const Standard_Real A2,
                             const Standard_Real A3);
    Caelus_StressStrainCurve(const Standard_Real A0,
                             const Standard_Real A1,
                             const Standard_Real A2,
                             const Standard_Real A3,
                             const Standard_Real A4);
    Caelus_StressStrainCurve(const Standard_Real A0,
                             const Standard_Real A1,
                             const Standard_Real A2,
                             const Standard_Real A3,
                             const Standard_Real A4,
                             const Standard_Real A5);
    Caelus_StressStrainCurve(const Standard_Real A0,
                             const Standard_Real A1,
                             const Standard_Real A2,
                             const Standard_Real A3,
                             const Standard_Real A4,
                             const Standard_Real A5,
                             const Standard_Real A6);

    // destructors
    virtual ~Caelus_StressStrainCurve();

public:

    Standard_Real           A0() const;
    Standard_Real           A1() const;
    Standard_Real           A2() const;
    Standard_Real           A3() const;
    Standard_Real           A4() const;
    Standard_Real           A5() const;
    Standard_Real           A6() const;

    void        SetA0(const Standard_Real A0);
    void        SetA1(const Standard_Real A1);
    void        SetA2(const Standard_Real A2);
    void        SetA3(const Standard_Real A3);
    void        SetA4(const Standard_Real A4);
    void        SetA5(const Standard_Real A5);
    void        SetA6(const Standard_Real A6);

private:

    Standard_Real           myA0;
    Standard_Real           myA1;
    Standard_Real           myA2;
    Standard_Real           myA3;
    Standard_Real           myA4;
    Standard_Real           myA5;
    Standard_Real           myA6;

};

#endif  // __Caelus_StressStrainCurve_hxx__
