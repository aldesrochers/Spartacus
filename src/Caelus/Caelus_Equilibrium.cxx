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
#include <Caelus_Catenary.hxx>
#include <Caelus_Equilibrium.hxx>

#include <math_TrigonometricEquationFunction.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_Equilibrium::Caelus_Equilibrium()
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Caelus_Equilibrium::~Caelus_Equilibrium()
{

}

// ============================================================================
/*!
    \brief EmptyLength()
    S - S0(1 + e) = 0
*/
// ============================================================================
Standard_Real Caelus_Equilibrium::EmptyLength() const
{
    Standard_Real P = 1000.;
    for(int i=0; i<100; i++) {

    }
}

// ============================================================================
/*!
    \brief LoadCase()
*/
// ============================================================================
Caelus_LoadCase Caelus_Equilibrium::LoadCase() const
{
    return myLoadCase;
}

// ============================================================================
/*!
    \brief Section()
*/
// ============================================================================
Caelus_Section Caelus_Equilibrium::Section() const
{
    return mySection;
}

// ============================================================================
/*!
    \brief Span()
*/
// ============================================================================
Caelus_Span Caelus_Equilibrium::Span() const
{
    return mySpan;
}

// ============================================================================
/*!
    \brief SetLoadCase()
*/
// ============================================================================
void Caelus_Equilibrium::SetLoadCase(const Caelus_LoadCase &theLoadCase)
{
    myLoadCase = theLoadCase;
}

// ============================================================================
/*!
    \brief SetSection()
*/
// ============================================================================
void Caelus_Equilibrium::SetSection(const Caelus_Section &theSection)
{
    mySection = theSection;
}

// ============================================================================
/*!
    \brief SetSpan()
*/
// ============================================================================
void Caelus_Equilibrium::SetSpan(const Caelus_Span &theSpan)
{
    mySpan = theSpan;
}

