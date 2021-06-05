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
#include <MCL1d_Elastic.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MCL1d_Elastic::MCL1d_Elastic(const Standard_Real E)
{
    myMaterial.SetE(E);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MCL1d_Elastic::MCL1d_Elastic(const Standard_Real E,
                             const Standard_Real Alpha)
{
    myMaterial.SetE(E);
    myMaterial.SetAlpha(Alpha);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MCL1d_Elastic::MCL1d_Elastic(const material_Elastic& theMaterial)
    : myMaterial(theMaterial)
{

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
    \brief Alpha()
*/
// ============================================================================
Standard_Real MCL1d_Elastic::Alpha() const
{
    return myMaterial.Alpha();
}

// ============================================================================
/*!
    \brief CurrentStiffness()
*/
// ============================================================================
Standard_Real MCL1d_Elastic::CurrentStiffness() const
{
    return InitialStiffness();
}

// ============================================================================
/*!
    \brief CurrentStress()
*/
// ============================================================================
Standard_Real MCL1d_Elastic::CurrentStress() const
{
    return InitialStiffness() * myTrialStrain;
}

// ============================================================================
/*!
    \brief E()
*/
// ============================================================================
Standard_Real MCL1d_Elastic::E() const
{
    return myMaterial.E();
}

// ============================================================================
/*!
    \brief InitialStiffness()
*/
// ============================================================================
Standard_Real MCL1d_Elastic::InitialStiffness() const
{
    return myMaterial.E();
}

// ============================================================================
/*!
    \brief Material()
*/
// ============================================================================
material_Elastic MCL1d_Elastic::Material() const
{
    return myMaterial;
}

// ============================================================================
/*!
    \brief SetAlpha()
*/
// ============================================================================
void MCL1d_Elastic::SetAlpha(const Standard_Real Alpha)
{
    myMaterial.SetAlpha(Alpha);
}

// ============================================================================
/*!
    \brief SetE()
*/
// ============================================================================
void MCL1d_Elastic::SetE(const Standard_Real E)
{
    myMaterial.SetE(E);
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MCL1d_Elastic, MCL1d_Material);
IMPLEMENT_STANDARD_RTTIEXT(MCL1d_Elastic, MCL1d_Material);
