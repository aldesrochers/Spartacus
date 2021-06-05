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


// Caelus
#include <Caelus_Equations.hxx>


// ============================================================================
/*!
    \brief Catenary2d()
    H : Horizontal tension
    w : Weight per unit length
    x : Position along the axis
*/
// ============================================================================
Standard_Real Caelus_Equations::Catenary2d(const Standard_Real H,
                                           const Standard_Real w,
                                           const Standard_Real x)
{
    return H/w * (Cosh(w*x/H)  - 1.);
}

// ============================================================================
/*!
    \brief Parabola2d()
    H : Horizontal tension
    w : Weight per unit length
    x : Position along the axis
*/
// ============================================================================
Standard_Real Caelus_Equations::Parabola2d(const Standard_Real H,
                                           const Standard_Real w,
                                           const Standard_Real x)
{
    return w*Pow(x, 2.)/(2*H);
}

