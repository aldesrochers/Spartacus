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
#include <TDF_Tool.hxx>

// Object  ---- Type
//   |     ---- GUID


// ============================================================================
/*!
 *  \brief Constructor
 *  Basic constructor for existing objects.
*/
// ============================================================================
Huygens_Object::Huygens_Object(const TDF_Label& theLabel)
    : myLabel(theLabel)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Huygens_Object::Huygens_Object(const TDF_Label& theLabel,
                               const Huygens::ObjectType theType)
    : myLabel(theLabel)
{
    // set GUID on label
    TDataStd_UAttribute::Set(myLabel, GetID());
    // set type on label
    TDataStd_Integer::Set(myLabel, theType);
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
 *  \brief GetType()
*/
// ============================================================================
Standard_Integer Huygens_Object::GetType(const TDF_Label &theLabel)
{
    if(!theLabel.IsAttribute(GetID()))
        return -1;
    Handle(TDataStd_Integer) aValue;
    if(!theLabel.FindAttribute(TDataStd_Integer::GetID(), aValue))
        return -1;
    return aValue->Get();
}

// ============================================================================
/*!
 *  \brief GetType()
*/
// ============================================================================
Standard_Integer Huygens_Object::GetType()
{
    Handle(TDataStd_Integer) aValue;
    if(!myLabel.FindAttribute(TDataStd_Integer::GetID(), aValue))
        return -1;
    return aValue->Get();
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_Object, Standard_Transient);
IMPLEMENT_STANDARD_RTTIEXT(Huygens_Object, Standard_Transient);
