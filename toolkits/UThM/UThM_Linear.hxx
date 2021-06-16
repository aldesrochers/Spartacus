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


#ifndef __UThM_Linear_hxx__
#define __UThM_Linear_hxx__

// Spartacus
#include <UThM_Model.hxx>

// Forward declarations
class UThM_Linear;

// Handles
DEFINE_STANDARD_HANDLE(UThM_Linear, UThM_Model);


// ============================================================================
/*!
    \brief UThM_Linear
*/
// ============================================================================
class UThM_Linear : public UThM_Model
{

public:
    // constructors
    UThM_Linear(const Standard_Real Alpha);
    UThM_Linear(const Standard_Real Alpha,
                const Standard_Real T0);
    // destructors
    ~UThM_Linear();

public:

    virtual Standard_Boolean    UpdateInternalState() Standard_OVERRIDE;

protected:

    // Parameters
    Standard_Real           myAlpha;
    Standard_Real           myT0;

public:

    DEFINE_STANDARD_RTTIEXT(UThM_Linear, UThM_Model);

};

#endif  // __UThM_Linear_hxx__
