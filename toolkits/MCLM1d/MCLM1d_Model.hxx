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


#ifndef __MCLM1d_Model_hxx__
#define __MCLM1d_Model_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>

// Spartacus
#include <CCLM1d_Model.hxx>
#include <SSCLM1d_Model.hxx>
#include <TECLM1d_Model.hxx>

// Forward declarations
class MCLM1d_Model;

// Handles
DEFINE_STANDARD_HANDLE(MCLM1d_Model, Standard_Transient);


// ============================================================================
/*!
    \brief MCLM1d_Model
*/
// ============================================================================
class MCLM1d_Model : public Standard_Transient
{

public:
    // constructors
    MCLM1d_Model();
    // destructors
    ~MCLM1d_Model();

public:

    virtual Standard_Boolean    CommitState() = 0;
    virtual Standard_Real       GetTrialStiffness() = 0;
    virtual Standard_Real       GetTrialStrain() = 0;
    virtual Standard_Real       GetTrialStress() = 0;
    virtual Standard_Real       GetTrialTemperature() = 0;
    virtual Standard_Real       GetTrialTime() = 0;
    virtual Standard_Boolean    RevertToCommitState() = 0;
    virtual Standard_Boolean    RevertToInitialState() = 0;
    virtual Standard_Boolean    SetTrialStrain(const Standard_Real theStrain) = 0;
    virtual Standard_Boolean    SetTrialTemperature(const Standard_Real theTemperature) = 0;
    virtual Standard_Boolean    SetTrialTime(const Standard_Real theTime) = 0;

public:

    DEFINE_STANDARD_RTTIEXT(MCLM1d_Model, Standard_Transient);

};

#endif  // __MCLM1d_Model_hxx__
