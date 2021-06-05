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


#ifndef __Caelus_SubSection_hxx__
#define __Caelus_SubSection_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Real.hxx>

// Caelus
#include <Caelus_CreepCurve.hxx>
#include <Caelus_StressStrainCurve.hxx>


// ============================================================================
/*!
 *  \brief Caelus_SubSection
*/
// ============================================================================
class Caelus_SubSection
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Caelus_SubSection();
    Caelus_SubSection(const Standard_Real theArea);
    Caelus_SubSection(const Standard_Real theArea,
                      const Standard_Real theThermalExpansionCoefficient);
    Caelus_SubSection(const Standard_Real theArea,
                      const Standard_Real theThermalExpansionCoefficient,
                      const Caelus_StressStrainCurve& theStressStrainCurve);
    Caelus_SubSection(const Standard_Real theArea,
                      const Standard_Real theThermalExpansionCoefficient,
                      const Caelus_StressStrainCurve& theStressStrainCurve,
                      const Caelus_CreepCurve& theCreepCurve);
    // destructors
    ~Caelus_SubSection();

public:

    Standard_Real               Area() const;
    Caelus_CreepCurve           CreepCurve() const;
    Caelus_StressStrainCurve    StressStrainCurve() const;
    Standard_Real               ThermalExpansionCoefficient() const;

    void            SetArea(const Standard_Real theArea);
    void            SetCreepCurve(const Caelus_CreepCurve& theCreepCurve);
    void            SetStressStrainCurve(const Caelus_StressStrainCurve& theStressStrainCurve);
    void            SetThermalExpansionCoefficient(const Standard_Real theThermalExpansionCoefficient);

private:

    Standard_Real               myArea;
    Caelus_CreepCurve           myCreepCurve;
    Caelus_StressStrainCurve    myStressStrainCurve;
    Standard_Real               myThermalExpansionCoefficient;

};

#endif  // __Caelus_SubSection_hxx__
