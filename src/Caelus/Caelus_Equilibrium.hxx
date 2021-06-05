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


#ifndef __Caelus_Equilibrium_hxx__
#define __Caelus_Equilibrium_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>

// Caelus
#include <Caelus_LoadCase.hxx>
#include <Caelus_Section.hxx>
#include <Caelus_Span.hxx>



// ============================================================================
/*!
 *  \brief Caelus_Equilibrium
*/
// ============================================================================
class Caelus_Equilibrium
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Caelus_Equilibrium();
    // destructors
    ~Caelus_Equilibrium();

public:

    Standard_Real       EmptyLength() const;

    Caelus_LoadCase     LoadCase() const;
    Caelus_Section      Section() const;
    Caelus_Span         Span() const;

    void                SetLoadCase(const Caelus_LoadCase& theLoadCase);
    void                SetSection(const Caelus_Section& theSection);
    void                SetSpan(const Caelus_Span& theSpan);

private:

    Caelus_LoadCase     myLoadCase;
    Caelus_Section      mySection;
    Caelus_Span         mySpan;

};

#endif  // __Caelus_Equilibrium_hxx__
