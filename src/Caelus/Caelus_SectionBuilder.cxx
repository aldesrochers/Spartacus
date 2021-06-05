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
#include <Caelus_SectionBuilder.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_SectionBuilder::Caelus_SectionBuilder()
    : myDiameter(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_SectionBuilder::Caelus_SectionBuilder(const Standard_Real theDiameter)
    : myDiameter(theDiameter)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_SectionBuilder::Caelus_SectionBuilder(const Standard_Real theDiameter,
                                             const Caelus_SequenceOfSubSection& theSequenceOfSubSections)
    : myDiameter(theDiameter),
      mySequenceOfSubSections(theSequenceOfSubSections)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Caelus_SectionBuilder::~Caelus_SectionBuilder()
{

}

// ============================================================================
/*!
    \brief AddSubSection()
*/
// ============================================================================
void Caelus_SectionBuilder::AddSubSection(const Standard_Real theArea,
                                          const Standard_Real theThermalExpansionCoefficient)
{
    Caelus_SubSection aSubSection(theArea, theThermalExpansionCoefficient);
    mySequenceOfSubSections.Append(aSubSection);
}

// ============================================================================
/*!
    \brief AddSubSection()
*/
// ============================================================================
void Caelus_SectionBuilder::AddSubSection(const Standard_Real theArea,
                                          const Standard_Real theThermalExpansionCoefficient,
                                          const Caelus_StressStrainCurve &theStressStrainCurve)
{
    Caelus_SubSection aSubSection(theArea, theThermalExpansionCoefficient, theStressStrainCurve);
    mySequenceOfSubSections.Append(aSubSection);
}

// ============================================================================
/*!
    \brief AddSubSection()
*/
// ============================================================================
void Caelus_SectionBuilder::AddSubSection(const Standard_Real theArea,
                                          const Standard_Real theThermalExpansionCoefficient,
                                          const Caelus_StressStrainCurve &theStressStrainCurve,
                                          const Caelus_CreepCurve &theCreepCurve)
{
    Caelus_SubSection aSubSection(theArea, theThermalExpansionCoefficient,
                                  theStressStrainCurve, theCreepCurve);
    mySequenceOfSubSections.Append(aSubSection);
}

// ============================================================================
/*!
    \brief AddSubSection()
*/
// ============================================================================
void Caelus_SectionBuilder::AddSubSection(const Caelus_SubSection &theSubSection)
{
    mySequenceOfSubSections.Append(theSubSection);
}

// ============================================================================
/*!
    \brief Diameter()
*/
// ============================================================================
Standard_Real Caelus_SectionBuilder::Diameter() const
{
    return myDiameter;
}

// ============================================================================
/*!
    \brief NbSubSections()
*/
// ============================================================================
Standard_Integer Caelus_SectionBuilder::NbSubSections()
{
    return mySequenceOfSubSections.Length();
}

// ============================================================================
/*!
    \brief Section()
    Return the cable section definition as a list of sub-sections.
*/
// ============================================================================
Caelus_Section Caelus_SectionBuilder::Section() const
{
    return Caelus_Section(myDiameter, mySequenceOfSubSections);
}

// ============================================================================
/*!
    \brief SequenceOfSubSections()
*/
// ============================================================================
Caelus_SequenceOfSubSection Caelus_SectionBuilder::SequenceOfSubSections() const
{
    return mySequenceOfSubSections;
}
