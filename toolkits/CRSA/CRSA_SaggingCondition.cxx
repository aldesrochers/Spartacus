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
#include <CRSA_SaggingCondition.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
CRSA_SaggingCondition::CRSA_SaggingCondition()
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
CRSA_SaggingCondition::CRSA_SaggingCondition(Handle(CRSA_LoadCase) theLoadCase,
                                             const Standard_Real theHorizontalTension)
    : myLoadCase(theLoadCase),
      myHorizontalTension(theHorizontalTension)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
CRSA_SaggingCondition::~CRSA_SaggingCondition()
{

}

// ============================================================================
/*!
 *  \brief GetHorizontalTension()
*/
// ============================================================================
Standard_Real CRSA_SaggingCondition::GetHorizontalTension()
{
    return myHorizontalTension;
}

// ============================================================================
/*!
 *  \brief GetLoadCase()
*/
// ============================================================================
Handle(CRSA_LoadCase) CRSA_SaggingCondition::GetLoadCase()
{
    return myLoadCase;
}

// ============================================================================
/*!
 *  \brief SetHorizontalTension()
*/
// ============================================================================
void CRSA_SaggingCondition::SetHorizontalTension(const Standard_Real theHorizontalTension)
{
    myHorizontalTension = theHorizontalTension;
}

// ============================================================================
/*!
 *  \brief SetLoadCase()
*/
// ============================================================================
void CRSA_SaggingCondition::SetLoadCase(Handle(CRSA_LoadCase) theLoadCase)
{
    myLoadCase = theLoadCase;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(CRSA_SaggingCondition, Standard_Transient);
IMPLEMENT_STANDARD_RTTIEXT(CRSA_SaggingCondition, Standard_Transient);
