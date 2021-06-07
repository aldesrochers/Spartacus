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


#ifndef __SSCLM1d_Elastic_hxx__
#define __SSCLM1d_Elastic_hxx__

// SSCLM1d
#include <SSCLM1d_Model.hxx>

// Forward declarations
class SSCLM1d_Elastic;

// Handles
DEFINE_STANDARD_HANDLE(SSCLM1d_Elastic, SSCLM1d_Model);


// ============================================================================
/*!
    \brief SSCLM1d_Elastic
    Base class implementation of a uniaxial material.
*/
// ============================================================================
class SSCLM1d_Elastic : public SSCLM1d_Model
{

public:
    // constructors
    SSCLM1d_Elastic(const Standard_Real E);
    // destructors
    ~SSCLM1d_Elastic();

public:

    virtual Standard_Boolean    CommitState() Standard_OVERRIDE;
    virtual Standard_Real       GetInitialStiffness() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStiffness() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStrain() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStress() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToCommitState() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToInitialState() Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialStrain(const Standard_Real theStrain) Standard_OVERRIDE;

private:

    Standard_Real           myCommitStrain;
    Standard_Real           myCommitStress;
    Standard_Real           myE;
    Standard_Real           myTrialStrain;
    Standard_Real           myTrialStress;

public:

    DEFINE_STANDARD_RTTIEXT(SSCLM1d_Elastic, SSCLM1d_Model);

};

#endif  // __SSCLM1d_Elastic_hxx__
