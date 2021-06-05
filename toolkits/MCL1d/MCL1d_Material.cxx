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
#include <MCL1d_Material.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MCL1d_Material::MCL1d_Material()
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MCL1d_Material::~MCL1d_Material()
{

}

// ============================================================================
/*!
    \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real MCL1d_Material::GetTrialStrain() const
{
    return myTrialStrain;
}

// ============================================================================
/*!
    \brief SetTrialStrain()
*/
// ============================================================================
void MCL1d_Material::SetTrialStrain(const Standard_Real theStrain)
{
    myTrialStrain = theStrain;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MCL1d_Material, MCL_Material)
IMPLEMENT_STANDARD_RTTIEXT(MCL1d_Material, MCL_Material)

