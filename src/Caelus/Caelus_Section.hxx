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


#ifndef __Caelus_Section_hxx__
#define __Caelus_Section_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>

// Caelus
#include <Caelus_SequenceOfSubSection.hxx>



// ============================================================================
/*!
 *  \brief Caelus_Section
*/
// ============================================================================
class Caelus_Section
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Caelus_Section();
    Caelus_Section(const Standard_Real theDiameter);
    Caelus_Section(const Standard_Real theDiameter,
                   const Caelus_SequenceOfSubSection& theSubSections);
    // destructors
    ~Caelus_Section();

public:

    Standard_Real               Diameter() const;
    Caelus_SequenceOfSubSection SubSections() const;

    void        SetDiameter(const Standard_Real theDiameter);
    void        SetSubSections(const Caelus_SequenceOfSubSection& theSubSections);

private:

    Standard_Real               myDiameter;
    Caelus_SequenceOfSubSection mySubSections;

};

#endif  // __Caelus_Section_hxx__
