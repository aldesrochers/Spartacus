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


#ifndef __XSM_BimetallicCable01_hxx__
#define __XSM_BimetallicCable01_hxx__

// XSM
#include <XSM_Model.hxx>
#include <XSMP_BimetallicCable01.hxx>

// Forward declarations
class XSM_BimetallicCable01;

// Handles
DEFINE_STANDARD_HANDLE(XSM_BimetallicCable01, XSM_Model);


// ============================================================================
/*!
    \brief XSM_BimetallicCable01

    Class implementation of a bimetallic cable model. This table model used
    two stress-strain models to describe the cable mechanical behaviour, two
    thermal models and a single creep model for the whole cable.
*/
// ============================================================================
class XSM_BimetallicCable01 : public XSM_Model
{

public:
    // constructors
    XSM_BimetallicCable01(const XSMP_BimetallicCable01& theParameters,
                          const Standard_Real theTolerance = 1E-8,
                          const Standard_Integer theMaxNbIterations = 100);
    // destructors
    ~XSM_BimetallicCable01();

public:

    Standard_Boolean        CommitState() Standard_OVERRIDE;
    Standard_Real           GetInitialStiffness() Standard_OVERRIDE;
    Standard_Real           GetTrialForce() Standard_OVERRIDE;
    Standard_Real           GetTrialStiffness() Standard_OVERRIDE;
    Standard_Real           GetTrialStrain() Standard_OVERRIDE;
    Standard_Real           GetTrialTemperature() Standard_OVERRIDE;
    Standard_Real           GetTrialTime() Standard_OVERRIDE;
    Standard_Boolean        RevertToCommitState() Standard_OVERRIDE;
    Standard_Boolean        RevertToInitialState() Standard_OVERRIDE;
    Standard_Boolean        SetTrialStrain(const Standard_Real theStrain) Standard_OVERRIDE;
    Standard_Boolean        SetTrialTemperature(const Standard_Real theTemperature) Standard_OVERRIDE;
    Standard_Boolean        SetTrialTime(const Standard_Real theTime) Standard_OVERRIDE;
    Standard_Boolean        UpdateInternalState() Standard_OVERRIDE;

protected:

    // Parameters
    XSMP_BimetallicCable01      myParameters;

    // Equilibrium
    Standard_Integer            myMaxNbIterations;
    Standard_Real               myTolerance;

    // History
    Standard_Real               myCommitCreepStress;
    Standard_Real               myCommitStrain;
    Standard_Real               myCommitTemperature;
    Standard_Real               myCommitTime;
    Standard_Real               myTrialCreepStress;
    Standard_Real               myTrialStrain;
    Standard_Real               myTrialTemperature;
    Standard_Real               myTrialTime;

public:

    DEFINE_STANDARD_RTTIEXT(XSM_BimetallicCable01, XSM_Model);

};

#endif  // __XSM_BimetallicCable01_hxx__
