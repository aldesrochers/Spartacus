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


#ifndef __XSM_Generic_hxx__
#define __XSM_Generic_hxx__

// XSM
#include <XSM_Section.hxx>

// Forward declarations
class XSM_Generic;

// Handles
DEFINE_STANDARD_HANDLE(XSM_Generic, XSM_Section);


// ============================================================================
/*!
    \brief XSM_Generic
    Class implementation of a generic cross-section.
*/
// ============================================================================
class XSM_Generic : public XSM_Section
{

public:
    // constructors
    XSM_Generic();
    // destructors
    ~XSM_Generic();

public:

    virtual Standard_Real       GetCommitForce() const = 0;
    virtual Standard_Real       GetCommitStiffness() const = 0;
    virtual Standard_Real       GetCommitStrain() const = 0;
    virtual Standard_Real       GetInitialStiffnes() const = 0;
    virtual Standard_Real       GetTrialForce() const = 0;
    virtual Standard_Real       GetTrialStiffness() const = 0;
    virtual void                RevertToInitialState() = 0;

public:

    DEFINE_STANDARD_RTTIEXT(XSM_Generic, XSM_Section);

};

#endif  // __XSM_Generic_hxx__
