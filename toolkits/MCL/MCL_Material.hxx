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


#ifndef __MCL_Material_hxx__
#define __MCL_Material_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_Transient.hxx>
#include <Standard_DefineHandle.hxx>

// Forward declarations
class MCL_Material;

// Handles
DEFINE_STANDARD_HANDLE(MCL_Material, Standard_Transient);


// ============================================================================
/*!
    \brief MCL_Material
    Base class implementation of a material constitutive law.
*/
// ============================================================================
class MCL_Material : public Standard_Transient
{

public:
    // constructors
    MCL_Material();
    // destructors
    ~MCL_Material();

public:

    DEFINE_STANDARD_RTTIEXT(MCL_Material, Standard_Transient);

};

#endif  // __MCL_Material_hxx__
