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


#ifndef __Mech1d_Truss_hxx__
#define __Mech1d_Truss_hxx__

// Spartacus
#include <gp_Pnt1d.hxx>
#include <Mech1d_Element.hxx>

// Handles
DEFINE_STANDARD_HANDLE(Mech1d_Truss, Mech1d_Element)

// ============================================================================
/*
    \brief Mech1d_Truss
*/
// ============================================================================
class Mech1d_Truss : public Mech1d_Element
{
    
public:
    // constructors
    Standard_EXPORT Mech1d_Truss();
    Standard_EXPORT Mech1d_Truss(const gp_Pnt1d& thePoint1,
                                 const gp_Pnt1d& thePoint2);
    // destructors
    Standard_EXPORT ~Mech1d_Truss();

public:

    Standard_EXPORT const gp_Pnt1d&     Point1() const;
    Standard_EXPORT const gp_Pnt1d&     Point2() const;
    Standard_EXPORT void                SetPoint1(const gp_Pnt1d& thePoint1);
    Standard_EXPORT void                SetPoint2(const gp_Pnt1d& thePoint2);

private:

    gp_Pnt1d    myPoint1;
    gp_Pnt1d    myPoint2;

public:

    DEFINE_STANDARD_RTTIEXT(Mech1d_Truss, Mech1d_Element)

};

#endif // __Mech1d_Truss_hxx__
