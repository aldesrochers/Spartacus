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


#ifndef __XSM_Elastic_hxx__
#define __XSM_Elastic_hxx__

// XSM
#include <XSM_Model.hxx>

// Forward declarations
class XSM_Elastic;

// Handles
DEFINE_STANDARD_HANDLE(XSM_Elastic, XSM_Model);


// ============================================================================
/*!
    \brief XSM_Elastic
    Class implementation of a generic cross-section.
*/
// ============================================================================
class XSM_Elastic : public XSM_Model
{

public:
    // constructors
    XSM_Elastic(const Standard_Real theArea,
                const Standard_Real theElasticModulous);
    XSM_Elastic(const Standard_Real theArea,
                const Standard_Real theElasticModulous,
                const Standard_Real theThermalExpansionCoef);
    // destructors
    ~XSM_Elastic();

public:

    virtual Standard_Boolean    CommitState() Standard_OVERRIDE;
    virtual Standard_Real       GetInitialStiffness() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialForce() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStiffness() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStrain() Standard_OVERRIDE;
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

    // Parameters
    Standard_Real               myArea;
    Standard_Real               myElasticModulous;
    Standard_Real               myThermalExpansionCoef;

    // History
    Standard_Real               myCommitForce;
    Standard_Real               myCommitMechanicalStrain;
    Standard_Real               myCommitStiffness;
    Standard_Real               myCommitStrain;
    Standard_Real               myCommitTemperature;
    Standard_Real               myCommitThermalStrain;
    Standard_Real               myCommitTime;
    Standard_Real               myTrialForce;
    Standard_Real               myTrialMechanicalStrain;
    Standard_Real               myTrialStiffness;
    Standard_Real               myTrialStrain;
    Standard_Real               myTrialTemperature;
    Standard_Real               myTrialThermalStrain;
    Standard_Real               myTrialTime;

public:

    DEFINE_STANDARD_RTTIEXT(XSM_Elastic, XSM_Model);

};

#endif  // __XSM_Elastic_hxx__
