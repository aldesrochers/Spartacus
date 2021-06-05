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


// Caelus
#include <Caelus_LoadCase.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_LoadCase::Caelus_LoadCase()
    : myCreepTime(0.),
      myDeadLoad(0.),
      myIceLoad(0.),
      myTemperature(0.),
      myWindLoad(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_LoadCase::Caelus_LoadCase(const Standard_Real theDeadLoad)
    : myCreepTime(0.),
      myDeadLoad(theDeadLoad),
      myIceLoad(0.),
      myTemperature(0.),
      myWindLoad(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_LoadCase::Caelus_LoadCase(const Standard_Real theDeadLoad,
                                 const Standard_Real theTemperature)
    : myCreepTime(0.),
      myDeadLoad(theDeadLoad),
      myIceLoad(0.),
      myTemperature(theTemperature),
      myWindLoad(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_LoadCase::Caelus_LoadCase(const Standard_Real theDeadLoad,
                                 const Standard_Real theTemperature,
                                 const Standard_Real theCreepTime)
    : myCreepTime(theCreepTime),
      myDeadLoad(theDeadLoad),
      myIceLoad(0.),
      myTemperature(theTemperature),
      myWindLoad(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_LoadCase::Caelus_LoadCase(const Standard_Real theDeadLoad,
                                 const Standard_Real theTemperature,
                                 const Standard_Real theCreepTime,
                                 const Standard_Real theIceLoad)
    : myCreepTime(theCreepTime),
      myDeadLoad(theDeadLoad),
      myIceLoad(theIceLoad),
      myTemperature(theTemperature),
      myWindLoad(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_LoadCase::Caelus_LoadCase(const Standard_Real theDeadLoad,
                                 const Standard_Real theTemperature,
                                 const Standard_Real theCreepTime,
                                 const Standard_Real theIceLoad,
                                 const Standard_Real theWindLoad)
    : myCreepTime(theCreepTime),
      myDeadLoad(theDeadLoad),
      myIceLoad(theIceLoad),
      myTemperature(theTemperature),
      myWindLoad(theWindLoad)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Caelus_LoadCase::~Caelus_LoadCase()
{

}

// ============================================================================
/*!
    \brief CreepTime()
*/
// ============================================================================
Standard_Real Caelus_LoadCase::CreepTime() const
{
    return myCreepTime;
}

// ============================================================================
/*!
    \brief DeadLoad()
*/
// ============================================================================
Standard_Real Caelus_LoadCase::DeadLoad() const
{
    return myDeadLoad;
}

// ============================================================================
/*!
    \brief IceLoad()
*/
// ============================================================================
Standard_Real Caelus_LoadCase::IceLoad() const
{
    return myIceLoad;
}

// ============================================================================
/*!
    \brief Temperature()
*/
// ============================================================================
Standard_Real Caelus_LoadCase::Temperature() const
{
    return myTemperature;
}

// ============================================================================
/*!
    \brief WindLoad()
*/
// ============================================================================
Standard_Real Caelus_LoadCase::WindLoad() const
{
    return myWindLoad;
}

// ============================================================================
/*!
    \brief SetCreepTime()
*/
// ============================================================================
void Caelus_LoadCase::SetCreepTime(const Standard_Real theCreepTime)
{
    myCreepTime = theCreepTime;
}

// ============================================================================
/*!
    \brief SetDeadLoad()
*/
// ============================================================================
void Caelus_LoadCase::SetDeadLoad(const Standard_Real theDeadLoad)
{
    myDeadLoad = theDeadLoad;
}

// ============================================================================
/*!
    \brief SetIceLoad()
*/
// ============================================================================
void Caelus_LoadCase::SetIceLoad(const Standard_Real theIceLoad)
{
    myIceLoad = theIceLoad;
}

// ============================================================================
/*!
    \brief SetTemperature()
*/
// ============================================================================
void Caelus_LoadCase::SetTemperature(const Standard_Real theTemperature)
{
    myTemperature = theTemperature;
}

// ============================================================================
/*!
    \brief SetWindLoad()
*/
// ============================================================================
void Caelus_LoadCase::SetWindLoad(const Standard_Real theWindLoad)
{
    myWindLoad = theWindLoad;
}


