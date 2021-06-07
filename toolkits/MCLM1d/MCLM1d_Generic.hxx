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


#ifndef __MCLM1d_Generic_hxx__
#define __MCLM1d_Generic_hxx__

// Spartacus
#include <MCLM1d_Model.hxx>
#include <CCLM1d_Model.hxx>
#include <SSCLM1d_Model.hxx>
#include <TECLM1d_Model.hxx>

// Forward declarations
class MCLM1d_Generic;

// Handles
DEFINE_STANDARD_HANDLE(MCLM1d_Generic, MCLM1d_Model);


// ============================================================================
/*!
    \brief MCLM1d_Generic
    This is a simple aggregation of a 1d material constitutive model.
*/
// ============================================================================
class MCLM1d_Generic : public MCLM1d_Model
{

public:
    // constructors
    MCLM1d_Generic();
    // destructors
    ~MCLM1d_Generic();

public:

    virtual Standard_Boolean    CommitState() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStiffness() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStrain() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStress() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialTemperature() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialTime() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToCommitState() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToInitialState() Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialStrain(const Standard_Real theStrain) Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialTemperature(const Standard_Real theTemperature) Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialTime(const Standard_Real theTime) Standard_OVERRIDE;

private:

    Standard_Boolean            UpdateInternalState();

private:

    Handle(CCLM1d_Model)        myCreepModel;
    Handle(SSCLM1d_Model)       myStressStrainModel;
    Handle(TECLM1d_Model)       myThermalModel;

private:

    Standard_Real               myCommitStrain;
    Standard_Real               myCommitTemperature;
    Standard_Real               myCommitTime;
    Standard_Real               myTrialStrain;
    Standard_Real               myTrialTemperature;
    Standard_Real               myTrialTime;

public:

    DEFINE_STANDARD_RTTIEXT(MCLM1d_Generic, MCLM1d_Model);

};

#endif  // __MCLM1d_Generic_hxx__
