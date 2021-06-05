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

// Spartacus
#include <MCL_UniaxialCableMaterial01.hxx>



// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MCL_UniaxialCableMaterial01::MCL_UniaxialCableMaterial01()
    : myMaxStrain(0.),
      myMinStrain(0.),
      myMaxStress(0.),
      myMinStress(0.),
      myPreviousStrain(0.),
      myPreviousStress(0.),
      myCurrentMaxStrain(0.),
      myCurrentMinStrain(0.),
      myCurrentMaxStress(0.),
      myCurrentMinStress(0.)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MCL_UniaxialCableMaterial01::~MCL_UniaxialCableMaterial01()
{

}

// ============================================================================
/*!
    \brief CommitState()
*/
// ============================================================================
Standard_Boolean MCL_UniaxialCableMaterial01::CommitState()
{

}


// ============================================================================
/*!
    \brief ComputeInternalState()
*/
// ============================================================================
Standard_Boolean MCL_UniaxialCableMaterial01::ComputeInternalState()
{

}

// ============================================================================
/*!
    \brief CurrentStiffness()
*/
// ============================================================================
Standard_Real MCL_UniaxialCableMaterial01::CurrentStiffness() const
{

}

// ============================================================================
/*!
    \brief CurrentStress()
*/
// ============================================================================
Standard_Real MCL_UniaxialCableMaterial01::CurrentStress() const
{

}

// ============================================================================
/*!
    \brief InitialStiffness()
*/
// ============================================================================
Standard_Real MCL_UniaxialCableMaterial01::InitialStiffness() const
{

}



// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MCL_UniaxialCableMaterial01, Standard_Transient);
IMPLEMENT_STANDARD_RTTIEXT(MCL_UniaxialCableMaterial01, Standard_Transient);
