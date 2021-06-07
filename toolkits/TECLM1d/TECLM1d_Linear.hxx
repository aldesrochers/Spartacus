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


#ifndef __TECLM1d_Linear_hxx__
#define __TECLM1d_Linear_hxx__

// TECLM1d
#include <TECLM1d_Model.hxx>

// Forward declarations
class TECLM1d_Linear;

// Handles
DEFINE_STANDARD_HANDLE(TECLM1d_Linear, TECLM1d_Model);


// ============================================================================
/*!
    \brief TECLM1d_Linear
    Compute a linear thermal expansion of type Eps = Alpha * (T-T0)
*/
// ============================================================================
class TECLM1d_Linear : public TECLM1d_Model
{

public:
    // constructors
    TECLM1d_Linear(const Standard_Real Alpha);
    TECLM1d_Linear(const Standard_Real Alpha,
                   const Standard_Real InitialTemperature);
    // destructors
    ~TECLM1d_Linear();

public:

    virtual Standard_Boolean    CommitState() Standard_OVERRIDE;
    virtual Standard_Real       GetInitialTemperature() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialStrain() Standard_OVERRIDE;
    virtual Standard_Real       GetTrialTemperature() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToCommitState() Standard_OVERRIDE;
    virtual Standard_Boolean    RevertToInitialState() Standard_OVERRIDE;
    virtual Standard_Boolean    SetTrialTemperature(const Standard_Real theTemperature) Standard_OVERRIDE;


private:

    // Parameters
    Standard_Real           myAlpha;
    Standard_Real           myInitialTemperature;

    // History
    Standard_Real           myCommitTemperature;
    Standard_Real           myCommitStrain;
    Standard_Real           myTrialTemperature;
    Standard_Real           myTrialStrain;

public:

    DEFINE_STANDARD_RTTIEXT(TECLM1d_Linear, TECLM1d_Model);

};

#endif  // __TECLM1d_Linear_hxx__
