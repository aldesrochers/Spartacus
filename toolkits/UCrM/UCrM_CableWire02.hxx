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


#ifndef __UCrM_CableWire02_hxx__
#define __UCrM_CableWire02_hxx__

// Spartacus
#include <UCrM_Model.hxx>
#include <UCrMP_CableWire02.hxx>

// Forward declarations
class UCrM_CableWire02;

// Handles
DEFINE_STANDARD_HANDLE(UCrM_CableWire02, UCrM_Model);


// ============================================================================
/*!
    \brief UCrM_CableWire02
*/
// ============================================================================
class UCrM_CableWire02 : public UCrM_Model
{

public:
    // constructors
    UCrM_CableWire02(const UCrMP_CableWire02& theParameters);
    // destructors
    ~UCrM_CableWire02();

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

    Standard_Real               F1(const Standard_Real Eps);
    Standard_Real               F2(const Standard_Real Eps);
    Standard_Real               F3(const Standard_Real Eps);
    Standard_Real               F4(const Standard_Real Eps);

    Standard_Boolean            UpdateInternalState();
    Standard_Boolean            UpdateTrialStressGrowthRate(const Standard_Real tEq,
                                                            const Standard_Real Eps);
    Standard_Boolean            UpdateTrialTemperatureGrowthRate(const Standard_Real tEq,
                                                                 const Standard_Real Eps);
    Standard_Boolean            UpdateTrialTimeGrowthRate(const Standard_Real tEq,
                                                          const Standard_Real Eps);

private:

    // Parameters
    UCrMP_CableWire02           myParameters;

    // History
    Standard_Real               myCommitStrain;
    Standard_Real               myCommitTime;
    Standard_Real               myTrialStrain;
    Standard_Real               myTrialStress;
    Standard_Real               myTrialStressGrowthRate;
    Standard_Real               myTrialTemperature;
    Standard_Real               myTrialTemperatureGrowthRate;
    Standard_Real               myTrialTime;
    Standard_Real               myTrialTimeGrowthRate;

public:

    DEFINE_STANDARD_RTTIEXT(UCrM_CableWire02, UCrM_Model);

};

#endif  // __UCrM_CableWire02_hxx__
