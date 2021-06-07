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


// RS
#include <CRSA_LoadCase.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
CRSA_LoadCase::CRSA_LoadCase()
    : myDeadLoad(0.),
      myDuration(0.),
      myIceLoad(0.),
      myTemperature(0.),
      myWindLoad(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
CRSA_LoadCase::CRSA_LoadCase(const Standard_Real theDeadLoad)
    : myDeadLoad(theDeadLoad),
      myDuration(0.),
      myIceLoad(0.),
      myTemperature(0.),
      myWindLoad(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
CRSA_LoadCase::CRSA_LoadCase(const Standard_Real theDeadLoad,
                             const Standard_Real theTemperature)
    : myDeadLoad(theDeadLoad),
      myDuration(0.),
      myIceLoad(0.),
      myTemperature(theTemperature),
      myWindLoad(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
CRSA_LoadCase::CRSA_LoadCase(const Standard_Real theDeadLoad,
                             const Standard_Real theTemperature,
                             const Standard_Real theIceLoad)
    : myDeadLoad(theDeadLoad),
      myDuration(0.),
      myIceLoad(theIceLoad),
      myTemperature(theTemperature),
      myWindLoad(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
CRSA_LoadCase::CRSA_LoadCase(const Standard_Real theDeadLoad,
                             const Standard_Real theTemperature,
                             const Standard_Real theIceLoad,
                             const Standard_Real theWindLoad)
    : myDeadLoad(theDeadLoad),
      myDuration(0.),
      myIceLoad(theIceLoad),
      myTemperature(theTemperature),
      myWindLoad(theWindLoad)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
CRSA_LoadCase::CRSA_LoadCase(const Standard_Real theDeadLoad,
                             const Standard_Real theTemperature,
                             const Standard_Real theIceLoad,
                             const Standard_Real theWindLoad,
                             const Standard_Real theDuration)
    : myDeadLoad(theDeadLoad),
      myDuration(theDuration),
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
CRSA_LoadCase::~CRSA_LoadCase()
{

}

// ============================================================================
/*!
 *  \brief GetDeadLoad()
*/
// ============================================================================
Standard_Real CRSA_LoadCase::GetDeadLoad()
{
    return myDeadLoad;
}

// ============================================================================
/*!
 *  \brief GetDuration()
*/
// ============================================================================
Standard_Real CRSA_LoadCase::GetDuration()
{
    return myDuration;
}

// ============================================================================
/*!
 *  \brief GetIceLoad()
*/
// ============================================================================
Standard_Real CRSA_LoadCase::GetIceLoad()
{
    return myIceLoad;
}

// ============================================================================
/*!
 *  \brief GetTemperature()
*/
// ============================================================================
Standard_Real CRSA_LoadCase::GetTemperature()
{
    return myTemperature;
}

// ============================================================================
/*!
 *  \brief GetTotalLoad()
 *  Get the cable 'total' load defined as Sqrt((D+I)^2 + W^2)
*/
// ============================================================================
Standard_Real CRSA_LoadCase::GetTotalLoad()
{
    return Sqrt(Pow(myDeadLoad + myIceLoad, 2.) + Pow(myWindLoad, 2.));
}

// ============================================================================
/*!
 *  \brief GetWindLoad()
*/
// ============================================================================
Standard_Real CRSA_LoadCase::GetWindLoad()
{
    return myWindLoad;
}

// ============================================================================
/*!
 *  \brief SetDeadLoad()
*/
// ============================================================================
void CRSA_LoadCase::SetDeadLoad(const Standard_Real theDeadLoad)
{
    myDeadLoad = theDeadLoad;
}

// ============================================================================
/*!
 *  \brief SetDuration()
*/
// ============================================================================
void CRSA_LoadCase::SetDuration(const Standard_Real theDuration)
{
    myDuration = theDuration;
}

// ============================================================================
/*!
 *  \brief SetIceLoad()
*/
// ============================================================================
void CRSA_LoadCase::SetIceLoad(const Standard_Real theIceLoad)
{
    myIceLoad = theIceLoad;
}

// ============================================================================
/*!
 *  \brief SetTemperature()
*/
// ============================================================================
void CRSA_LoadCase::SetTemperature(const Standard_Real theTemperature)
{
    myTemperature = theTemperature;
}

// ============================================================================
/*!
 *  \brief SetWindLoad()
*/
// ============================================================================
void CRSA_LoadCase::SetWindLoad(const Standard_Real theWindLoad)
{
    myWindLoad = theWindLoad;
}


// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(CRSA_LoadCase, Standard_Transient);
IMPLEMENT_STANDARD_RTTIEXT(CRSA_LoadCase, Standard_Transient);


