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


#ifndef __UCrM_CableCreep01_hxx__
#define __UCrM_CableCreep01_hxx__

// Spartacus
#include <UCrM_Model.hxx>
#include <mmp_CableCreep01.hxx>

// Forward declarations
class UCrM_CableCreep01;

// Handles
DEFINE_STANDARD_HANDLE(UCrM_CableCreep01, UCrM_Model);


// ============================================================================
/*!
    \brief UCrM_CableCreep01

    This is an implementation of a creep model based on the equation
    proposed by the CIGRE/Electra "Permanent elongation of conductors.
    Predictor equation and evaluation methods" with coefficients fitted
    by multi-linear equations based on experimental data.

    The adapted equation is exp(phi*(T-T0))*f1(sig)*t^f2(sig), where f1(sig)
    and f2(sig) are multi-linear equations fitted on test data. So, the
    equation can be rewritten as exp(phi*(T-T0)*(A*sig+B)*t^(C*sig+D), where
    A, B, C and D are defined by multi-linear expression function of sig.
*/
// ============================================================================
class UCrM_CableCreep01 : public UCrM_Model
{

protected:

    // internal coefficients structure
    struct UCrM_Coefficients {
        Standard_Real A;
        Standard_Real B;
        Standard_Real C;
        Standard_Real D;
    };

public:
    // constructors
    UCrM_CableCreep01(const mmp_CableCreep01& theParameters);
    // destructors
    ~UCrM_CableCreep01();

public:

    virtual Standard_Boolean    UpdateInternalState() Standard_OVERRIDE;

protected:

    UCrM_Coefficients           Coefficients(const Standard_Real Sig);
    Standard_Real               CreepEquivalentTime(const Standard_Real Temp,
                                                    const Standard_Real Sig,
                                                    const Standard_Real Eps);
    Standard_Real               CreepFunction(const Standard_Real Temp,
                                              const Standard_Real Sig,
                                              const Standard_Real Time);
    Standard_Real               CreepFunctionStressRate(const Standard_Real Temp,
                                                        const Standard_Real Sig,
                                                        const Standard_Real Time);
    Standard_Real               CreepFunctionTemperatureRate(const Standard_Real Temp,
                                                             const Standard_Real Sig,
                                                             const Standard_Real Time);
    Standard_Real               CreepFunctionTimeRate(const Standard_Real Temp,
                                                      const Standard_Real Sig,
                                                      const Standard_Real Time);
    virtual Standard_Real       F1(const Standard_Real Sig);
    virtual Standard_Real       F2(const Standard_Real Sig);

protected:

    // Parameters
    mmp_CableCreep01       myParameters;

public:

    DEFINE_STANDARD_RTTIEXT(UCrM_CableCreep01, UCrM_Model);

};

#endif  // __UCrM_CableCreep01_hxx__
