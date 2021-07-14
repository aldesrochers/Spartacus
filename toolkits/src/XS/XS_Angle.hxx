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


#ifndef __XS_Angle_hxx__
#define __XS_Angle_hxx__

// Spartacus
#include <XS_Shape.hxx>


// ============================================================================
/*!
 *  \brief XS_Angle
 *  Class implementation of an angle shape.
*/
// ============================================================================
class XS_Angle : public XS_Shape
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    XS_Angle();
    // destructors
    ~XS_Angle();

public:

    Standard_Real       B() const;
    Standard_Real       D() const;
    Standard_Real       R1() const;
    Standard_Real       R2() const;
    Standard_Real       T() const;

    void        SetB(const Standard_Real B);
    void        SetD(const Standard_Real D);
    void        SetR1(const Standard_Real R1);
    void        SetR2(const Standard_Real R2);
    void        SetT(const Standard_Real T);

private:

    Standard_Real   myB;
    Standard_Real   myD;
    Standard_Real   myR1;
    Standard_Real   myR2;
    Standard_Real   myT;

};

#endif  // __XS_Angle_hxx__
