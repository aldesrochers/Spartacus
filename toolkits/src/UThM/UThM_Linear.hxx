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
#include <UThMP_Linear.hxx>

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
    UThM_Linear(const UThMP_Linear& theParameters);
    // destructors
    ~UThM_Linear();

public:

    virtual Standard_Boolean    CommitState() Standard_OVERRIDE;
    virtual Standard_Real       GetGrowthRate() Standard_OVERRIDE;
    virtual Standard_Real       GetInitialGrowthRate() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStrain() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialTemperature() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToCommitState() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToInitialState() Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialTemperature(const Standard_Real theTemperature) Standard_OVERRIDE;

protected:

    // Parameters
    UThMP_Linear                myParameters;

    // History
    Standard_Real               myCommitTemperature;
    Standard_Real               myTrialTemperature;

public:

    DEFINE_STANDARD_RTTIEXT(UThM_Linear, UThM_Model);

};

#endif  // __UThM_Linear_hxx__
