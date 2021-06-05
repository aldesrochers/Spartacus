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


#ifndef __MCL1d_Material_hxx__
#define __MCL1d_Material_hxx__

// MCL
#include <MCL_Material.hxx>

// Forward declarations
class MCL1d_Material;

// Handles
DEFINE_STANDARD_HANDLE(MCL1d_Material, MCL_Material);


// ============================================================================
/*!
    \brief MCL1d_Material
    Base class implementation of a uniaxial material.
*/
// ============================================================================
class MCL1d_Material : public MCL_Material
{

public:
    // constructors
    MCL1d_Material();
    // destructors
    ~MCL1d_Material();

public:

    virtual Standard_Real   GetCommitStiffness() const = 0;
    virtual Standard_Real   GetCommitStrain() const = 0;
    virtual Standard_Real   GetCommitStress() const = 0;
    virtual Standard_Real   GetInitialStiffness() const = 0;
    virtual Standard_Real   GetTrialStiffness() const = 0;
    virtual Standard_Real   GetTrialStrain() const;
    virtual Standard_Real   GetTrialStress() const = 0;
    virtual void            RevertToInitialState() = 0;
    virtual void            SetTrialStrain(const Standard_Real theStrain);

protected:

    Standard_Real           myTrialStrain;

public:

    DEFINE_STANDARD_RTTIEXT(MCL1d_Material, MCL_Material);

};

#endif  // __MCL1d_Material_hxx__
