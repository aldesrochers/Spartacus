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

// Caelus
#include <Caelus_SubSection.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_SubSection::Caelus_SubSection()
    : myArea(0.),
      myThermalExpansionCoefficient(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_SubSection::Caelus_SubSection(const Standard_Real theArea)
    : myArea(theArea),
      myThermalExpansionCoefficient(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_SubSection::Caelus_SubSection(const Standard_Real theArea,
                                     const Standard_Real theThermalExpansionCoefficient)
    : myArea(theArea),
      myThermalExpansionCoefficient(theThermalExpansionCoefficient)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_SubSection::Caelus_SubSection(const Standard_Real theArea,
                                     const Standard_Real theThermalExpansionCoefficient,
                                     const Caelus_StressStrainCurve& theStressStrainCurve)
    : myArea(theArea),
      myThermalExpansionCoefficient(theThermalExpansionCoefficient),
      myStressStrainCurve(theStressStrainCurve)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_SubSection::Caelus_SubSection(const Standard_Real theArea,
                                     const Standard_Real theThermalExpansionCoefficient,
                                     const Caelus_StressStrainCurve& theStressStrainCurve,
                                     const Caelus_CreepCurve& theCreepCurve)
    : myArea(theArea),
      myThermalExpansionCoefficient(theThermalExpansionCoefficient),
      myStressStrainCurve(theStressStrainCurve),
      myCreepCurve(theCreepCurve)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Caelus_SubSection::~Caelus_SubSection()
{

}

// ============================================================================
/*!
    \brief Area()
*/
// ============================================================================
Standard_Real Caelus_SubSection::Area() const
{
    return myArea;
}

// ============================================================================
/*!
    \brief CreepCurve()
*/
// ============================================================================
Caelus_CreepCurve Caelus_SubSection::CreepCurve() const
{
    return myCreepCurve;
}

// ============================================================================
/*!
    \brief StressStrainCurve()
*/
// ============================================================================
Caelus_StressStrainCurve Caelus_SubSection::StressStrainCurve() const
{
    return myStressStrainCurve;
}

// ============================================================================
/*!
    \brief ThermalExpansionCoefficient()
*/
// ============================================================================
Standard_Real Caelus_SubSection::ThermalExpansionCoefficient() const
{
    return myThermalExpansionCoefficient;
}

// ============================================================================
/*!
    \brief SetArea()
*/
// ============================================================================
void Caelus_SubSection::SetArea(const Standard_Real theArea)
{
    myArea = theArea;
}

// ============================================================================
/*!
    \brief SetCreepCurve()
*/
// ============================================================================
void Caelus_SubSection::SetCreepCurve(const Caelus_CreepCurve &theCreepCurve)
{
    myCreepCurve = theCreepCurve;
}

// ============================================================================
/*!
    \brief SetStressStrainCurve()
*/
// ============================================================================
void Caelus_SubSection::SetStressStrainCurve(const Caelus_StressStrainCurve &theStressStrainCurve)
{
    myStressStrainCurve = theStressStrainCurve;
}

// ============================================================================
/*!
    \brief SetThermalExpansionCoefficient()
*/
// ============================================================================
void Caelus_SubSection::SetThermalExpansionCoefficient(const Standard_Real theThermalExpansionCoefficient)
{
    myThermalExpansionCoefficient = theThermalExpansionCoefficient;
}
