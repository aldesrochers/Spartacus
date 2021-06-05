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


#ifndef __Huygens_ILoadCaseAttributes_hxx__
#define __Huygens_ILoadCaseAttributes_hxx__

// Huygens
#include <Huygens_DataObject.hxx>

// Attributes
#define TAG_Designation                     1
#define TAG_IceVolumicMass                  100
#define TAG_IceThickness                    101
#define TAG_WindPressure                    101
#define TAG_Temperature                     102
#define TAG_CreepTime                       103



// ============================================================================
/*!
    \brief Huygens_ILoadCaseAttributes
*/
// ============================================================================
class Huygens_ILoadCaseAttributes
{

public:
    // constructors
    Huygens_ILoadCaseAttributes(Handle(Huygens_DataObject) theObject) :
        myObject(theObject) {}
    // destructors
    ~Huygens_ILoadCaseAttributes() {}

public:

    Standard_Real               GetCreepTime() {return myObject->GetRealAttribute(TAG_CreepTime);}
    TCollection_AsciiString     GetDesignation() {return myObject->GetStringAttribute(TAG_Designation);}
    Standard_Real               GetIceVolumicMass() {return myObject->GetRealAttribute(TAG_IceVolumicMass);}
    Standard_Real               GetIceThickness() {return myObject->GetRealAttribute(TAG_IceThickness);}
    Standard_Real               GetTemperature() {return myObject->GetRealAttribute(TAG_Temperature);}
    Standard_Real               GetWindPressure() {return myObject->GetRealAttribute(TAG_WindPressure);}


    void    SetCreepTime(const Standard_Real theValue) {myObject->SetRealAttribute(TAG_CreepTime, theValue);}
    void    SetDesignation(const TCollection_AsciiString& theDesignation) {myObject->SetStringAttribute(TAG_Designation, theDesignation);}
    void    SetIceVolumicMass(const Standard_Real theValue) {myObject->SetRealAttribute(TAG_IceVolumicMass, theValue);}
    void    SetIceThickness(const Standard_Real theValue) {myObject->SetRealAttribute(TAG_IceThickness, theValue);}
    void    SetTemperature(const Standard_Real theValue) {myObject->SetRealAttribute(TAG_Temperature, theValue);}
    void    SetWindPressure(const Standard_Real theValue) {myObject->SetRealAttribute(TAG_WindPressure, theValue);}

private:

    Handle(Huygens_DataObject)  myObject;

};

#endif  // __Huygens_ILoadCaseAttributes_hxx__
