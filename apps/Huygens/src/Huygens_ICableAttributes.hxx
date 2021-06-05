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


#ifndef __Huygens_ICableAttributes_hxx__
#define __Huygens_ICableAttributes_hxx__

// Huygens
#include <Huygens_DataObject.hxx>

// Attributes
#define TAG_Designation                     1
#define TAG_ElasticModulous                 100
#define TAG_ThermalExpansionCoefficient     101


// ============================================================================
/*!
    \brief Huygens_ICableAttributes
*/
// ============================================================================
class Huygens_ICableAttributes
{

public:
    // constructors
    Huygens_ICableAttributes(Handle(Huygens_DataObject) theObject) :
        myObject(theObject) {}
    // destructors
    ~Huygens_ICableAttributes() {}

public:

    TCollection_AsciiString     GetDesignation() {return myObject->GetStringAttribute(TAG_Designation);}
    Standard_Real               GetElasticModulous() {return myObject->GetRealAttribute(TAG_ElasticModulous);}
    Standard_Real               GetThermalExpansionCoefficient() {return myObject->GetRealAttribute(TAG_ThermalExpansionCoefficient);}


    void    SetDesignation(const TCollection_AsciiString& theDesignation) {myObject->SetStringAttribute(TAG_Designation, theDesignation);}
    void    SetElasticModulous(const Standard_Real theValue) {myObject->SetRealAttribute(TAG_ElasticModulous, theValue);}
    void    SetThermalExpansionCoefficient(const Standard_Real theValue) {myObject->SetRealAttribute(TAG_ThermalExpansionCoefficient, theValue);}

private:

    Handle(Huygens_DataObject)  myObject;

};

#endif  // __Huygens_ICableAttributes_hxx__
