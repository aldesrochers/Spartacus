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


#ifndef __UCrM_Model_hxx__
#define __UCrM_Model_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>

// Forward declarations
class UCrM_Model;

// Handles
DEFINE_STANDARD_HANDLE(UCrM_Model, Standard_Transient);


// ============================================================================
/*!
    \brief UCrM_Model
*/
// ============================================================================
class UCrM_Model : public Standard_Transient
{

public:
    // constructors
    UCrM_Model();
    // destructors
    ~UCrM_Model();

public:

    virtual Standard_Boolean    CommitState() = 0;
    virtual Standard_Real       GetCommitStrain() = 0;
    virtual Standard_Real       GetCommitStress() = 0;
    virtual Standard_Real       GetCommitStressGrowthRate() = 0;
    virtual Standard_Real       GetCommitTemperature() = 0;
    virtual Standard_Real       GetCommitTemperatureGrowthRate() = 0;
    virtual Standard_Real       GetCommitTime() = 0;
    virtual Standard_Real       GetCommitTimeGrowthRate() = 0;
    virtual Standard_Real       GetTrialStrain() = 0;
    virtual Standard_Real       GetTrialStress() = 0;
    virtual Standard_Real       GetTrialStressGrowthRate() = 0;
    virtual Standard_Real       GetTrialTemperature() = 0;
    virtual Standard_Real       GetTrialTemperatureGrowthRate() = 0;
    virtual Standard_Real       GetTrialTime() = 0;
    virtual Standard_Real       GetTrialTimeGrowthRate() = 0;
    virtual Standard_Boolean    MustBeUpdated() = 0;
    virtual Standard_Boolean    RevertToCommitState() = 0;
    virtual Standard_Boolean    RevertToInitialState() = 0;
    virtual Standard_Boolean    SetTrialStress(const Standard_Real theStress) = 0;
    virtual Standard_Boolean    SetTrialTemperature(const Standard_Real theTemperature) = 0;
    virtual Standard_Boolean    SetTrialTime(const Standard_Real theTime) = 0;
    virtual Standard_Boolean    UpdateInternalState() = 0;

public:

    DEFINE_STANDARD_RTTIEXT(UCrM_Model, Standard_Transient);

};

#endif  // __UCrM_Model_hxx__
