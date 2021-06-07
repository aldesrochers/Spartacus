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


#ifndef __CRSA_SaggingCondition_hxx__
#define __CRSA_SaggingCondition_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>

// Spartacus
#include <CRSA_LoadCase.hxx>

// Forward declarations
class CRSA_SaggingCondition;

// Handles
DEFINE_STANDARD_HANDLE(CRSA_SaggingCondition, Standard_Transient);


// ============================================================================
/*!
 *  \brief CRSA_SaggingCondition
 *  Class implementation of a cable sagging condition.
*/
// ============================================================================
class CRSA_SaggingCondition : public Standard_Transient
{

public:
    // constructors
    CRSA_SaggingCondition();
    CRSA_SaggingCondition(Handle(CRSA_LoadCase) theLoadCase,
                          const Standard_Real theHorizontalTension);
    // destructors
    ~CRSA_SaggingCondition();

public:

    Standard_Real           GetHorizontalTension();
    Handle(CRSA_LoadCase)   GetLoadCase();

    void                    SetHorizontalTension(const Standard_Real theHorizontalTension);
    void                    SetLoadCase(Handle(CRSA_LoadCase) theLoadCase);

private:

    Standard_Real           myHorizontalTension;
    Handle(CRSA_LoadCase)   myLoadCase;

public:

    DEFINE_STANDARD_RTTIEXT(CRSA_SaggingCondition, Standard_Transient);

};

#endif  // __CRSA_SaggingCondition_hxx__
