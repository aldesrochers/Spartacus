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

// Huygens
#include <Huygens_Object.hxx>

// OpenCascade
#include <TDataStd_Integer.hxx>
#include <TDataStd_UAttribute.hxx>
#include <TDataStd_AsciiString.hxx>
#include <TDF_Tool.hxx>

// Definition of an object basic data structure
// Object  ---- Type
//   |     ---- GUID
//   | ==== Properties

// Definition of tags
#define TAG_Properties      1
#define PROP_Name           1
#define PROP_Description    2

// Definition of basic macros
#define PROPERTY_LABEL(theIndex)    GetLabel().FindChild(TAG_Properties).FindChild((theIndex))


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Huygens_Object::Huygens_Object(const TDF_Label& theLabel)
    : myLabel(theLabel)
{
    // set GUID on label
    TDataStd_UAttribute::Set(myLabel, GetID());
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Huygens_Object::~Huygens_Object()
{

}

// ============================================================================
/*!
    \brief GetDescription()
*/
// ============================================================================
TCollection_AsciiString Huygens_Object::GetDescription()
{
    TDF_Label aLabel = PROPERTY_LABEL(PROP_Description);
    Handle(TDataStd_AsciiString) aValue;
    if(!aLabel.FindAttribute(TDataStd_AsciiString::GetID(), aValue))
        return TCollection_AsciiString();
    return aValue->Get();
}

// ============================================================================
/*!
 *  \brief GetEntry()
*/
// ============================================================================
TCollection_AsciiString Huygens_Object::GetEntry()
{
    TCollection_AsciiString aString;
    TDF_Tool::Entry(myLabel, aString);
    return aString;
}

// ============================================================================
/*!
 *  \brief GetID()
*/
// ============================================================================
Standard_GUID& Huygens_Object::GetID()
{
    static Standard_GUID aGUID("353A6869-E3B4-487C-B46C-F8B20B997961");
    return aGUID;
}

// ============================================================================
/*!
 *  \brief GetLabel()
*/
// ============================================================================
TDF_Label Huygens_Object::GetLabel()
{
    return myLabel;
}

// ============================================================================
/*!
    \brief GetName()
*/
// ============================================================================
TCollection_AsciiString Huygens_Object::GetName()
{
    TDF_Label aLabel = PROPERTY_LABEL(PROP_Name);
    Handle(TDataStd_AsciiString) aValue;
    if(!aLabel.FindAttribute(TDataStd_AsciiString::GetID(), aValue))
        return TCollection_AsciiString();
    return aValue->Get();
}


// ============================================================================
/*!
 *  \brief GetObject()
*/
// ============================================================================
Handle(Huygens_Object) Huygens_Object::GetObject(const TDF_Label& theLabel)
{
    Handle(Huygens_Object) anObject;
    if(!theLabel.IsAttribute(GetID()))
        return anObject;
    anObject = new Huygens_Object(theLabel);
    return anObject;
}

// ============================================================================
/*!
    \brief SetDescription()
*/
// ============================================================================
void Huygens_Object::SetDescription(const TCollection_AsciiString &theDescription)
{
    TDF_Label aLabel = PROPERTY_LABEL(PROP_Description);
    TDataStd_AsciiString::Set(aLabel, theDescription);
}

// ============================================================================
/*!
    \brief SetName()
*/
// ============================================================================
void Huygens_Object::SetName(const TCollection_AsciiString &theName)
{
    TDF_Label aLabel = PROPERTY_LABEL(PROP_Name);
    TDataStd_AsciiString::Set(aLabel, theName);
}



// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_Object, Standard_Transient);
IMPLEMENT_STANDARD_RTTIEXT(Huygens_Object, Standard_Transient);
