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


#ifndef __gp_Pnt1d_hxx__
#define __gp_Pnt1d_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>

// ============================================================================
/*!
 *  \brief gp_Pnt1d
 *  Class implementation of a point in 1d space.
*/
// ============================================================================
class gp_Pnt1d
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Standard_EXPORT gp_Pnt1d();
    Standard_EXPORT gp_Pnt1d(const Standard_Real theX);
    // destructors
    Standard_EXPORT ~gp_Pnt1d();

public:

    Standard_EXPORT Standard_Real       Distance(const gp_Pnt1d& theOther) const;
    Standard_EXPORT Standard_Boolean    IsEqual(const gp_Pnt1d& theOther,
                                                const Standard_Real theLinearTolerance) const;
    Standard_EXPORT void                SetX(const Standard_Real theX);
    Standard_EXPORT Standard_Real       X() const;

private:

    Standard_Real       myX;

};


#endif // __gp_Pnt1d_hxx__
