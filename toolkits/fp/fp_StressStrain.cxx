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

// cable
#include <fp_StressStrain.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
fp_StressStrain::fp_StressStrain()
    : myStrain(0.),
      myStress(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
fp_StressStrain::fp_StressStrain(const Standard_Real Strain,
                                 const Standard_Real Stress)
    : myStrain(Strain),
      myStress(Stress)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
fp_StressStrain::~fp_StressStrain()
{

}

// ============================================================================
/*!
 *  \brief Strain()
*/
// ============================================================================
Standard_Real fp_StressStrain::Strain() const
{
    return myStrain;
}

// ============================================================================
/*!
 *  \brief Stress()
*/
// ============================================================================
Standard_Real fp_StressStrain::Stress() const
{
    return myStress;
}

// ============================================================================
/*!
 *  \brief SetStrain()
*/
// ============================================================================
void fp_StressStrain::SetStrain(const Standard_Real Strain)
{
    myStrain = Strain;
}

// ============================================================================
/*!
 *  \brief SetStress()
*/
// ============================================================================
void fp_StressStrain::SetStress(const Standard_Real Stress)
{
    myStress = Stress;
}
