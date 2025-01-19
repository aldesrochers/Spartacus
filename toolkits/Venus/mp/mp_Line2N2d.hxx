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


#ifndef __mp_Line2N2d_hxx__
#define __mp_Line2N2d_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>

// Spartacus
#include <gp_Pnt2d.hxx>


// ============================================================================
/*
    \brief mp_Line2N2d
*/
// ============================================================================
class mp_Line2N2d
{

public:

    DEFINE_STANDARD_ALLOC;
    
public:
    // constructors
    Standard_EXPORT mp_Line2N2d();
    // destructors
    Standard_EXPORT ~mp_Line2N2d();

public:

    Standard_EXPORT const gp_Pnt2d&     Point1() const;
    Standard_EXPORT const gp_Pnt2d&     Point2() const;
    Standard_EXPORT void                SetPoint1(const gp_Pnt2d& thePoint1);
    Standard_EXPORT void                SetPoint2(const gp_Pnt2d& thePoint2);

private:

    gp_Pnt2d    myPoint1;
    gp_Pnt2d    myPoint2;

};

#endif // __mp_Line2N2d_hxx__
