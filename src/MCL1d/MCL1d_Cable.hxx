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


#ifndef __MCL1d_Cable_hxx__
#define __MCL1d_Cable_hxx__

// Spartacus
#include <MCL1d_Material.hxx>
#include <material_Cable.hxx>

// Forward declarations
class MCL1d_Cable;

// Handles
DEFINE_STANDARD_HANDLE(MCL1d_Cable, MCL1d_Material);


// ============================================================================
/*!
    \brief MCL1d_Cable
    Base class implementation of a material constitutive law.
*/
// ============================================================================
class MCL1d_Cable : public MCL1d_Material
{

public:
    // constructors
    MCL1d_Cable(const material_Cable& theMaterial);
    // destructors
    ~MCL1d_Cable();

public:

    virtual Standard_Boolean    CommitState();
    virtual Standard_Boolean    ComputeInternalState();
    virtual Standard_Real       CurrentStiffness() const;
    virtual Standard_Real       CurrentStress() const;
    virtual Standard_Real       InitialStiffness() const;

private:

    material_Cable          myMaterial;

    Standard_Real           myCurrentMaxStrain;
    Standard_Real           myCurrentMinStrain;
    Standard_Real           myCurrentMaxStress;
    Standard_Real           myCurrentMinStress;
    Standard_Real           myMaxStrain;
    Standard_Real           myMinStrain;
    Standard_Real           myMaxStress;
    Standard_Real           myMinStress;
    Standard_Real           myPreviousStrain;
    Standard_Real           myPreviousStress;
    Standard_Real           myTrialStress;

public:

    DEFINE_STANDARD_RTTIEXT(MCL1d_Cable, MCL1d_Material);

};

#endif  // __MCL1d_Cable_hxx__
