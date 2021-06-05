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


// MCL1d
#include <MCL1d_Elastic.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MCL1d_Elastic::MCL1d_Elastic(const Standard_Real E)
    : myE(E)
{
    RevertToInitialState();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MCL1d_Elastic::~MCL1d_Elastic()
{

}

// ============================================================================
/*!
    \brief GetCommitStiffness()
*/
// ============================================================================
Standard_Real MCL1d_Elastic::GetCommitStiffness() const
{
    return myE;
}

// ============================================================================
/*!
    \brief GetCommitStrain()
*/
// ============================================================================
Standard_Real MCL1d_Elastic::GetCommitStrain() const
{
    return myCommitStrain;
}

// ============================================================================
/*!
    \brief GetCommitStress()
*/
// ============================================================================
Standard_Real MCL1d_Elastic::GetCommitStress() const
{
    return myE * myCommitStrain;
}

// ============================================================================
/*!
    \brief GetInitialStiffness()
*/
// ============================================================================
Standard_Real MCL1d_Elastic::GetInitialStiffness() const
{
    return myE;
}

// ============================================================================
/*!
    \brief GetTrialStiffness()
*/
// ============================================================================
Standard_Real MCL1d_Elastic::GetTrialStiffness() const
{
    return myE;
}

// ============================================================================
/*!
    \brief GetTrialStress()
*/
// ============================================================================
Standard_Real MCL1d_Elastic::GetTrialStress() const
{
    return myE * myTrialStrain;
}

// ============================================================================
/*!
    \brief RevertToInitialState()
*/
// ============================================================================
void MCL1d_Elastic::RevertToInitialState()
{
    myCommitStrain = 0.;
    myTrialStrain = 0.;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MCL1d_Elastic, MCL1d_Material)
IMPLEMENT_STANDARD_RTTIEXT(MCL1d_Elastic, MCL1d_Material)

