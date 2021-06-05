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


#ifndef __Caelus_SectionBuilder_hxx__
#define __Caelus_SectionBuilder_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>

// Caelus
#include <Caelus_Section.hxx>
#include <Caelus_SequenceOfSubSection.hxx>


// ============================================================================
/*!
    \brief Caelus_SectionBuilder
    Class implementation of a cable section builder.
*/
// ============================================================================
class Caelus_SectionBuilder
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Caelus_SectionBuilder();
    Caelus_SectionBuilder(const Standard_Real theDiameter);
    Caelus_SectionBuilder(const Standard_Real theDiameter,
                          const Caelus_SequenceOfSubSection& theSequenceOfSubSections);
    // destructors
    ~Caelus_SectionBuilder();

public:

    void                            AddSubSection(const Standard_Real theArea,
                                                  const Standard_Real theThermalExpansionCoefficient);
    void                            AddSubSection(const Standard_Real theArea,
                                                  const Standard_Real theThermalExpansionCoefficient,
                                                  const Caelus_StressStrainCurve& theStressStrainCurve);
    void                            AddSubSection(const Standard_Real theArea,
                                                  const Standard_Real theThermalExpansionCoefficient,
                                                  const Caelus_StressStrainCurve& theStressStrainCurve,
                                                  const Caelus_CreepCurve& theCreepCurve);
    void                            AddSubSection(const Caelus_SubSection& theSubSection);

    Standard_Real                   Diameter() const;

    Standard_Integer                NbSubSections();

    Caelus_Section                  Section() const;

private:

    Caelus_SequenceOfSubSection     SequenceOfSubSections() const;

private:

    Standard_Real                   myDiameter;
    Caelus_SequenceOfSubSection     mySequenceOfSubSections;

};

#endif  // __Caelus_SectionBuilder_hxx__
