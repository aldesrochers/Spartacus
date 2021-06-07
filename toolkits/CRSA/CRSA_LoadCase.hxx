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


#ifndef __CRSA_LoadCase_hxx__
#define __CRSA_LoadCase_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>

// Forward declarations
class CRSA_LoadCase;

// Handles
DEFINE_STANDARD_HANDLE(CRSA_LoadCase, Standard_Transient);


// ============================================================================
/*!
    \brief CRSA_LoadCase
    Class implementation of a cable load case.
*/
// ============================================================================
class CRSA_LoadCase : public Standard_Transient
{

public:
    // constructors
    CRSA_LoadCase();
    CRSA_LoadCase(const Standard_Real theDeadLoad);
    CRSA_LoadCase(const Standard_Real theDeadLoad,
                  const Standard_Real theTemperature);
    CRSA_LoadCase(const Standard_Real theDeadLoad,
                  const Standard_Real theTemperature,
                  const Standard_Real theIceLoad);
    CRSA_LoadCase(const Standard_Real theDeadLoad,
                  const Standard_Real theTemperature,
                  const Standard_Real theIceLoad,
                  const Standard_Real theWindLoad);
    CRSA_LoadCase(const Standard_Real theDeadLoad,
                  const Standard_Real theTemperature,
                  const Standard_Real theIceLoad,
                  const Standard_Real theWindLoad,
                  const Standard_Real theDuration);
    // destructors
    ~CRSA_LoadCase();

public:

    Standard_Real       GetDeadLoad();
    Standard_Real       GetDuration();
    Standard_Real       GetIceLoad();
    Standard_Real       GetTemperature();
    Standard_Real       GetTotalLoad();
    Standard_Real       GetWindLoad();

    void                SetDeadLoad(const Standard_Real theDeadLoad);
    void                SetDuration(const Standard_Real theDuration);
    void                SetIceLoad(const Standard_Real theIceLoad);
    void                SetTemperature(const Standard_Real theTemperature);
    void                SetWindLoad(const Standard_Real theWindLoad);

private:

    Standard_Real       myDeadLoad;
    Standard_Real       myDuration;
    Standard_Real       myIceLoad;
    Standard_Real       myTemperature;
    Standard_Real       myWindLoad;

public:

    DEFINE_STANDARD_RTTIEXT(CRSA_LoadCase, Standard_Transient);

};

#endif  // __CRSA_LoadCase_hxx__
