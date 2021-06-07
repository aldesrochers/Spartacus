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


#ifndef __CCLM1d_CableWire01_hxx__
#define __CCLM1d_CableWire01_hxx__

// CCLM1d
#include <CCLM1d_Model.hxx>

// Forward declarations
class CCLM1d_CableWire01;

// Handles
DEFINE_STANDARD_HANDLE(CCLM1d_CableWire01, CCLM1d_Model);


// ============================================================================
/*!
    \brief CCLM1d_CableWire01

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
class CCLM1d_CableWire01 : public CCLM1d_Model
{

public:
    // constructors
    CCLM1d_CableWire01(const Standard_Real K,
                       const Standard_Real Phi,
                       const Standard_Real Alpha,
                       const Standard_Real Mu);
    // destructors
    ~CCLM1d_CableWire01();

public:

    virtual Standard_Boolean    CommitState() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStrain() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStress() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialTemperature() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialTime() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToCommitState() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToInitialState() Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialStress(const Standard_Real theStress) Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialTemperature(const Standard_Real theTemperature) Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialTime(const Standard_Real theTime) Standard_OVERRIDE;

private:

    virtual Standard_Boolean    UpdateInternalState();

private:

    // Parameters
    Standard_Real           myAlpha;
    Standard_Real           myK;
    Standard_Real           myMu;
    Standard_Real           myPhi;

    // history
    Standard_Real           myCommitStrain;
    Standard_Real           myCommitStress;
    Standard_Real           myCommitTemperature;
    Standard_Real           myCommitTime;
    Standard_Real           myTrialStrain;
    Standard_Real           myTrialStress;
    Standard_Real           myTrialTemperature;
    Standard_Real           myTrialTime;

public:

    DEFINE_STANDARD_RTTIEXT(CCLM1d_CableWire01, CCLM1d_Model);

};

#endif  // __CCLM1d_CableWire01_hxx__
