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


#ifndef __USSM_Elastic_hxx__
#define __USSM_Elastic_hxx__

// Spartacus
#include <USSM_Model.hxx>
#include <USSMP_Elastic.hxx>

// Forward declarations
class USSM_Elastic;

// Handles
DEFINE_STANDARD_HANDLE(USSM_Elastic, USSM_Model);


// ============================================================================
/*!
    \brief USSM_Elastic
*/
// ============================================================================
class USSM_Elastic : public USSM_Model
{

public:
    // constructors
    USSM_Elastic(const Standard_Real E);
    USSM_Elastic(const USSMP_Elastic& theParameters);
    // destructors
    ~USSM_Elastic();

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

    // Parameters
    USSMP_Elastic               myParameters;

    // History
    Standard_Real               myCommitStrain;
    Standard_Real               myTrialStrain;

public:

    DEFINE_STANDARD_RTTIEXT(USSM_Elastic, USSM_Model);

};

#endif  // __USSM_Elastic_hxx__
