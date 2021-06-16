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


// MCLM1d
#include <UMM_Elastic.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UMM_Elastic::UMM_Elastic(const Standard_Real E)
    : myAlpha(0.),
      myE(E)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
UMM_Elastic::UMM_Elastic(const Standard_Real E,
                         const Standard_Real Alpha)
    : myAlpha(Alpha),
      myE(E)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
UMM_Elastic::~UMM_Elastic()
{

}

// ============================================================================
/*!
    \brief UpdateInternalState()
*/
// ============================================================================
Standard_Boolean UMM_Elastic::UpdateInternalState()
{
    // compute thermal strain
    myTrialThermalStrain = myCommitThermalStrain
            + myAlpha * (myTrialTemperature - myCommitTemperature);
    // compute stress strain
    myTrialStressStrain = myTrialStrain - myTrialThermalStrain;
    // compute stress
    myTrialStress = myE * myTrialStressStrain;
    // compute tangent stiffness
    myTrialStiffness = myE;
    // setup update flag
    myMustBeUpdated = Standard_False;
    return Standard_True;
}



// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(UMM_Elastic, UMM_Model)
IMPLEMENT_STANDARD_RTTIEXT(UMM_Elastic, UMM_Model)

