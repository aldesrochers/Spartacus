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


#ifndef __UMM_CableWire01_hxx__
#define __UMM_CableWire01_hxx__

// Spartacus
#include <UMM_Model.hxx>
#include <mmp_CableWireStressStrain01.hxx>
#include <mmp_CableWireCreep01.hxx>

// Forward declarations
class UMM_CableWire01;

// Handles
DEFINE_STANDARD_HANDLE(UMM_CableWire01, UMM_Model);


// ============================================================================
/*!
    \brief UMM_CableWire01
*/
// ============================================================================
class UMM_CableWire01 : public UMM_Model
{

public:
    // constructors
    UMM_CableWire01(const mmp_CableWireStressStrain01& StressStrainParameters,
                    const mmp_CableWireCreep01& CreepParameters,
                    const Standard_Real Alpha);
    // destructors
    ~UMM_CableWire01();

public:

    virtual Standard_Boolean    UpdateInternalState() Standard_OVERRIDE;

private:

    Standard_Real               PolynomialCurveDerivative(const Standard_Real StressStrain);
    Standard_Real               PolynomialCurveFunction(const Standard_Real StressStrain);

private:

    // Parameters
    Standard_Real               myAlpha;
    mmp_CableWireCreep01       myCreepParameters;
    mmp_CableWireStressStrain01     myStressStrainParameters;

    // History
    Standard_Real               myCurrentMaxStrain;
    Standard_Real               myCurrentMaxStress;
    Standard_Real               myCurrentMinStrain;
    Standard_Real               myCurrentMinStress;
    Standard_Real               myMaxStrain;
    Standard_Real               myMaxStress;
    Standard_Real               myMinStrain;
    Standard_Real               myMinStress;


public:

    DEFINE_STANDARD_RTTIEXT(UMM_CableWire01, UMM_Model);

};

#endif  // __UMM_CableWire01_hxx__
