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
#include <matp_CableWireCreep01.hxx>

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
    UCrM_CableWire01(const Standard_Real K,
                     const Standard_Real Phi,
                     const Standard_Real Alpha);
    UCrM_CableWire01(const Standard_Real K,
                     const Standard_Real Phi,
                     const Standard_Real Alpha,
                     const Standard_Real Mu);
    // destructors
    ~UCrM_CableWire01();

public:

    virtual Standard_Boolean    UpdateInternalState() Standard_OVERRIDE;

protected:

    // Parameters
    Standard_Real           myAlpha;
    Standard_Real           myK;
    Standard_Real           myPhi;
    Standard_Real           myMu;

public:

    DEFINE_STANDARD_RTTIEXT(UCrM_CableWire01, UCrM_Model);

};

#endif  // __UCrM_CableWire01_hxx__
