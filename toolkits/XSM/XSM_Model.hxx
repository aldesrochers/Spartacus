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


#ifndef __XSM_Model_hxx__
#define __XSM_Model_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_Transient.hxx>
#include <Standard_DefineHandle.hxx>

// Forward declarations
class XSM_Model;

// Handles
DEFINE_STANDARD_HANDLE(XSM_Model, Standard_Transient);


// ============================================================================
/*!
    \brief XSM_Model
    Base class implementation of cross-section behaviour.
*/
// ============================================================================
class XSM_Model : public Standard_Transient
{

public:
    // constructors
    XSM_Model();
    // destructors
    ~XSM_Model();

public:

    virtual Standard_Boolean    CommitState() = 0;
    virtual Standard_Real       GetCommitForce() = 0;
    virtual Standard_Real       GetCommitStiffness() = 0;
    virtual Standard_Real       GetCommitStrain() = 0;
    virtual Standard_Real       GetCommitTemperature() = 0;
    virtual Standard_Real       GetCommitTime() = 0;
    virtual Standard_Real       GetInitialStiffness() = 0;
    virtual Standard_Real       GetTrialForce() = 0;
    virtual Standard_Real       GetTrialStiffness() = 0;
    virtual Standard_Real       GetTrialStrain() = 0;
    virtual Standard_Real       GetTrialTemperature() = 0;
    virtual Standard_Real       GetTrialTime() = 0;
    virtual Standard_Boolean    MustBeUpdated() = 0;
    virtual Standard_Boolean    RevertToCommitState() = 0;
    virtual Standard_Boolean    RevertToInitialState() = 0;
    virtual Standard_Boolean    SetTrialStrain(const Standard_Real theStrain) = 0;
    virtual Standard_Boolean    SetTrialTemperature(const Standard_Real theTemperature) = 0;
    virtual Standard_Boolean    SetTrialTime(const Standard_Real theTime) = 0;
    virtual Standard_Boolean    UpdateInternalState() = 0;

public:

    DEFINE_STANDARD_RTTIEXT(XSM_Model, Standard_Transient);

};

#endif  // __XSM_Model_hxx__
