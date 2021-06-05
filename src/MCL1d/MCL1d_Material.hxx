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

// OpenCascade
#include <Standard.hxx>
#include <Standard_Transient.hxx>
#include <Standard_DefineHandle.hxx>

// Forward declarations
class MCL1d_Material;

// Handles
DEFINE_STANDARD_HANDLE(MCL1d_Material, Standard_Transient);


// ============================================================================
/*!
    \brief MCL1d_Material
    Base class implementation of a material constitutive law.
*/
// ============================================================================
class MCL1d_Material : public Standard_Transient
{

public:
    // constructors
    MCL1d_Material();
    // destructors
    ~MCL1d_Material();

public:

    virtual Standard_Boolean    CommitState() = 0;
    virtual Standard_Boolean    ComputeInternalState() = 0;
    virtual Standard_Real       CurrentStiffness() const = 0;
    virtual Standard_Real       CurrentStress() const = 0;
    virtual Standard_Real       InitialStiffness() const = 0;
    virtual Standard_Real       InitialTemperature() const;

    virtual void                SetInitialTemperature(const Standard_Real theTemperature);
    virtual void                SetTrialStrain(const Standard_Real theStrain);
    virtual void                SetTrialTemperature(const Standard_Real theTemperature);

protected:

    Standard_Real       myInitialTemperature;
    Standard_Real       myTrialStrain;
    Standard_Real       myTrialTemperature;

public:

    DEFINE_STANDARD_RTTIEXT(MCL1d_Material, Standard_Transient);

};

#endif  // __MCL1d_Material_hxx__
