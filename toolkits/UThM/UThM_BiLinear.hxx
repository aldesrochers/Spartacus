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


#ifndef __UThM_BiLinear_hxx__
#define __UThM_BiLinear_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <UThM_Model.hxx>

// Forward declarations
class UThM_BiLinear;

// Handles
DEFINE_STANDARD_HANDLE(UThM_BiLinear, UThM_Model);


// ============================================================================
/*!
    \brief UThM_BiLinear
*/
// ============================================================================
class UThM_BiLinear : public UThM_Model
{

public:
    // constructors
    UThM_BiLinear(const Standard_Real Alpha0,
                  const Standard_Real T0,
                  const Standard_Real Alpha1,
                  const Standard_Real DT);
    // destructors
    ~UThM_BiLinear();

public:

    virtual Standard_Boolean    UpdateInternalState() Standard_OVERRIDE;

protected:

    // Parameters
    Standard_Real       myAlpha0;
    Standard_Real       myAlpha1;
    Standard_Real       myT0;
    Standard_Real       myDT;

public:

    DEFINE_STANDARD_RTTIEXT(UThM_BiLinear, UThM_Model);

};

#endif  // __UThM_BiLinear_hxx__
