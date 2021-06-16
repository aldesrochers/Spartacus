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


#ifndef __UMM_Elastic_hxx__
#define __UMM_Elastic_hxx__

// Spartacus
#include <UMM_Model.hxx>

// Forward declarations
class UMM_Elastic;

// Handles
DEFINE_STANDARD_HANDLE(UMM_Elastic, UMM_Model);


// ============================================================================
/*!
    \brief UMM_Elastic
*/
// ============================================================================
class UMM_Elastic : public UMM_Model
{

public:
    // constructors
    UMM_Elastic(const Standard_Real E);
    UMM_Elastic(const Standard_Real E,
                const Standard_Real Alpha);
    // destructors
    ~UMM_Elastic();

public:

    virtual Standard_Boolean    UpdateInternalState() Standard_OVERRIDE;

private:

    // Parameters
    Standard_Real               myAlpha;
    Standard_Real               myE;

public:

    DEFINE_STANDARD_RTTIEXT(UMM_Elastic, UMM_Model);

};

#endif  // __UMM_Elastic_hxx__
