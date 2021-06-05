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


#ifndef __MCL_UniaxialCableMaterial01_hxx__
#define __MCL_UniaxialCableMaterial01_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>

// Forward declarations
class MCL_UniaxialCableMaterial01;

// Handles
DEFINE_STANDARD_HANDLE(MCL_UniaxialCableMaterial01, Standard_Transient);


// ============================================================================
/*!
    \brief MCL_UniaxialCableMaterial01
*/
// ============================================================================
class MCL_UniaxialCableMaterial01 : public Standard_Transient
{

public:
    // constructors
    MCL_UniaxialCableMaterial01();
    // destructors
    ~MCL_UniaxialCableMaterial01();

public:

    virtual Standard_Boolean    CommitState();
    virtual Standard_Boolean    ComputeInternalState();
    virtual Standard_Real       CurrentStiffness() const;
    virtual Standard_Real       CurrentStress() const;
    virtual Standard_Real       InitialStiffness() const;

private:

    Standard_Real           myA0;
    Standard_Real           myA1;
    Standard_Real           myA2;
    Standard_Real           myA3;
    Standard_Real           myA4;
    Standard_Real           myA5;
    Standard_Real           myA6;
    Standard_Real           myBeta;
    Standard_Real           myLimitTensionStrain;
    Standard_Real           myLimitCompressionStress;


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

    DEFINE_STANDARD_RTTIEXT(MCL_UniaxialCableMaterial01, Standard_Transient);

};

#endif  // __MCL_UniaxialCableMaterial01_hxx__
