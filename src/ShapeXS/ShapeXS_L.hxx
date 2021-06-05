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


#ifndef __ShapeXS_L_hxx__
#define __ShapeXS_L_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>


// ============================================================================
/*!
 *  \brief ShapeXS_L
*/
// ============================================================================
class ShapeXS_L
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    ShapeXS_L();
    // destructors
    ~ShapeXS_L();

public:

    Standard_Real   B() const;
    Standard_Real   D() const;
    Standard_Real   T() const;

private:

    Standard_Real   myB;
    Standard_Real   myD;
    Standard_Real   myT;

};

#endif  // __ShapeXS_L_hxx__
