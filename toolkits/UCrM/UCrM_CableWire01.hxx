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


#ifndef __UCrM_CableWire01_hxx__
#define __UCrM_CableWire01_hxx__

// Spartacus
#include <UCrM_Model.hxx>
#include <UCrMP_CableWire01.hxx>

// Forward declarations
class UCrM_CableWire01;

// Handles
DEFINE_STANDARD_HANDLE(UCrM_CableWire01, UCrM_Model);


// ============================================================================
/*!
    \brief UCrM_CableWire01

    This is an implementation of the uniaxial material creep model
    proposed by the CIGRE/Electra "Permanent elongation of conductors.
    Predictor equation and evaluation methods".

    The creep equation is K*exp(phi*T)*(sig^alpha)*(t^mu), where K, phi, alpha,
    mu are calibrated coefficients and T, t, and sig are respectively the
    temperature, the time and the mean stress.

    The equation is unit dependent, so T is in Celcius, t in hours and sig
    in Pa.

    The equation is only valid for a single wire loaded axially.

    The cummulated creep strain is calculated according to eq. A3-7 of the
    CIGRE/Electra brochure.
*/
// ============================================================================
class UCrM_CableWire01 : public UCrM_Model
{

public:
    // constructors
    UCrM_CableWire01(const UCrMP_CableWire01& theParameters);
    // destructors
    ~UCrM_CableWire01();

public:

    virtual Standard_Boolean    CommitState() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStrain() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStress() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStressGrowthRate() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialTemperature() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialTemperatureGrowthRate() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialTime() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialTimeGrowthRate() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToCommitState() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToInitialState() Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialStress(const Standard_Real theStress) Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialTemperature(const Standard_Real theTemperature) Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialTime(const Standard_Real theTime) Standard_OVERRIDE;

private:

    Standard_Boolean            UpdateInternalState();
    Standard_Boolean            UpdateTrialStressGrowthRate(const Standard_Real tEq);
    Standard_Boolean            UpdateTrialTemperatureGrowthRate(const Standard_Real tEq);
    Standard_Boolean            UpdateTrialTimeGrowthRate(const Standard_Real tEq);

private:

    // Parameters
    UCrMP_CableWire01           myParameters;

    // History
    Standard_Real               myCommitStrain;
    Standard_Real               myCommitStress;
    Standard_Real               myCommitTemperature;
    Standard_Real               myCommitTime;
    Standard_Real               myTrialStrain;
    Standard_Real               myTrialStress;
    Standard_Real               myTrialStressGrowthRate;
    Standard_Real               myTrialTemperature;
    Standard_Real               myTrialTemperatureGrowthRate;
    Standard_Real               myTrialTime;
    Standard_Real               myTrialTimeGrowthRate;

public:

    DEFINE_STANDARD_RTTIEXT(UCrM_CableWire01, UCrM_Model);

};

#endif  // __UCrM_CableWire01_hxx__
