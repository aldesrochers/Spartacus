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


#ifndef __Caelus_LoadCase_hxx__
#define __Caelus_LoadCase_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Real.hxx>


// ============================================================================
/*!
    \brief Caelus_LoadCase
*/
// ============================================================================
class Caelus_LoadCase
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Caelus_LoadCase();
    Caelus_LoadCase(const Standard_Real theDeadLoad);
    Caelus_LoadCase(const Standard_Real theDeadLoad,
                    const Standard_Real theTemperature);
    Caelus_LoadCase(const Standard_Real theDeadLoad,
                    const Standard_Real theTemperature,
                    const Standard_Real theCreepTime);
    Caelus_LoadCase(const Standard_Real theDeadLoad,
                    const Standard_Real theTemperature,
                    const Standard_Real theCreepTime,
                    const Standard_Real theIceLoad);
    Caelus_LoadCase(const Standard_Real theDeadLoad,
                    const Standard_Real theTemperature,
                    const Standard_Real theCreepTime,
                    const Standard_Real theIceLoad,
                    const Standard_Real theWindLoad);
    // destructors
    ~Caelus_LoadCase();

public:

    Standard_Real       CreepTime() const;
    Standard_Real       DeadLoad() const;
    Standard_Real       IceLoad() const;
    Standard_Real       Temperature() const;
    Standard_Real       WindLoad() const;

    void        SetCreepTime(const Standard_Real theCreepTime);
    void        SetDeadLoad(const Standard_Real theDeadLoad);
    void        SetIceLoad(const Standard_Real theIceLoad);
    void        SetTemperature(const Standard_Real theTemperature);
    void        SetWindLoad(const Standard_Real theWindLoad);

private:

    Standard_Real       myCreepTime;
    Standard_Real       myDeadLoad;
    Standard_Real       myIceLoad;
    Standard_Real       myTemperature;
    Standard_Real       myWindLoad;

};

#endif  // __Caelus_LoadCase_hxx__
