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


#ifndef __USSM_Model_hxx__
#define __USSM_Model_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>

// Forward declarations
class USSM_Model;

// Handles
DEFINE_STANDARD_HANDLE(USSM_Model, Standard_Transient);


// ============================================================================
/*!
    \brief USSM_Model
*/
// ============================================================================
class USSM_Model : public Standard_Transient
{

public:
    // constructors
    USSM_Model();
    // destructors
    ~USSM_Model();

public:

    virtual Standard_Boolean    CommitState();
    virtual Standard_Real       GetCommitStiffness();
    virtual Standard_Real       GetCommitStrain();
    virtual Standard_Real       GetCommitStress();
    virtual Standard_Real       GetTrialStiffness();
    virtual Standard_Real       GetTrialStrain();
    virtual Standard_Real       GetTrialStress();
    virtual Standard_Boolean    MustBeUpdated();
    virtual Standard_Boolean    RevertToCommitState();
    virtual Standard_Boolean    RevertToInitialState();
    virtual Standard_Boolean    SetTrialStrain(const Standard_Real theStrain);
    virtual Standard_Boolean    UpdateInternalState() = 0;

protected:

    // Internal state
    Standard_Real               myMustBeUpdated;

    // History
    Standard_Real               myCommitStiffness;
    Standard_Real               myCommitStrain;
    Standard_Real               myCommitStress;;
    Standard_Real               myTrialStiffness;
    Standard_Real               myTrialStrain;
    Standard_Real               myTrialStress;

public:

    DEFINE_STANDARD_RTTIEXT(USSM_Model, Standard_Transient);

};

#endif  // __USSM_Model_hxx__
