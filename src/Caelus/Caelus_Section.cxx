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
#include <Caelus_Section.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_Section::Caelus_Section()
    : myDiameter(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_Section::Caelus_Section(const Standard_Real theDiameter)
    : myDiameter(theDiameter)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_Section::Caelus_Section(const Standard_Real theDiameter,
                               const Caelus_SequenceOfSubSection& theSubSections)
    : myDiameter(theDiameter),
      mySubSections(theSubSections)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Caelus_Section::~Caelus_Section()
{

}

// ============================================================================
/*!
    \brief Diameter()
*/
// ============================================================================
Standard_Real Caelus_Section::Diameter() const
{
    return myDiameter;
}

// ============================================================================
/*!
    \brief SubSections()
*/
// ============================================================================
Caelus_SequenceOfSubSection Caelus_Section::SubSections() const
{
    return mySubSections;
}

// ============================================================================
/*!
    \brieef SetDiameter()
*/
// ============================================================================
void Caelus_Section::SetDiameter(const Standard_Real theDiameter)
{
    myDiameter = theDiameter;
}

// ============================================================================
/*!
    \brief SetSubSections()
*/
// ============================================================================
void Caelus_Section::SetSubSections(const Caelus_SequenceOfSubSection &theSubSections)
{
    mySubSections = theSubSections;
}

