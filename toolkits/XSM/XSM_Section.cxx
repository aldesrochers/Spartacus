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


// XSM
#include <XSM_Section.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
XSM_Section::XSM_Section()
    : myTrialStrain(0.)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
XSM_Section::~XSM_Section()
{

}

// ============================================================================
/*!
    \brief GetTrialStrain()
*/
// ============================================================================
Standard_Real XSM_Section::GetTrialStrain() const
{
    return myTrialStrain;
}

// ============================================================================
/*!
    \brief SetTrialStrain()
*/
// ============================================================================
void XSM_Section::SetTrialStrain(const Standard_Real theStrain)
{
    myTrialStrain = theStrain;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(XSM_Section, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(XSM_Section, Standard_Transient)

