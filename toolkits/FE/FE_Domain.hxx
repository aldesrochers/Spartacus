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


#ifndef __FE_Domain_hxx__
#define __FE_Domain_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_Transient.hxx>
#include <Standard_DefineHandle.hxx>

// Forward declarations
class FE_Domain;

// Handles
DEFINE_STANDARD_HANDLE(FE_Domain, Standard_Transient);


// ============================================================================
/*!
    \brief FE_Domain
    Class implementation of a FE domain.
*/
// ============================================================================
class FE_Domain : public Standard_Transient
{

public:
    // constructors
    FE_Domain();
    // destructors
    ~FE_Domain();

public:

    DEFINE_STANDARD_RTTIEXT(FE_Domain, Standard_Transient);

};

#endif  // __FE_Domain_hxx__
