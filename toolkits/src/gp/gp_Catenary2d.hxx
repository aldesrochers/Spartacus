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


#ifndef __gp_Catenary2d_hxx__
#define __gp_Catenary2d_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <gp_Ax22d.hxx>


// ============================================================================
/*!
 *  \brief gp_Catenary2d
 *  Class implementation of a catenary curve.
 *
 *  A catenary curve is defined by its bottom point location.
*/
// ============================================================================
class gp_Catenary2d
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    gp_Catenary2d();
    gp_Catenary2d(const gp_Ax22d& theAxis,
                  const Standard_Real theParameter);
    // destructors
    ~gp_Catenary2d();

private:

    gp_Ax22d        myAxis;
    Standard_Real   myParameter;


};

#endif  // __gp_Catenary2d_hxx__
