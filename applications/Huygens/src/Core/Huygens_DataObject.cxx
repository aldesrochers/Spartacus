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
#include <Huygens_DataObject.hxx>

// OpenCascade
#include <TDataStd_UAttribute.hxx>
#include <TDataStd_Integer.hxx>
#include <TDataStd_Real.hxx>
#include <TDataStd_AsciiString.hxx>

// ***
// Definition of the object data structure
// ***
// DataObject ---- GUID
//     |      ---- Type
//     | ==== Attribute 1
//     | ==== Attribute 2
//     | ==== ...

#define     ATTRIBUTE_LABEL(theIndex)   GetLabel().FindChild((theIndex))


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Huygens_DataObject::Huygens_DataObject(const TDF_Label& theLabel)
    : Huygens_Object(theLabel)
{
    // set guid
    TDataStd_UAttribute::Set(theLabel, GetID());
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Huygens_DataObject::Huygens_DataObject(const TDF_Label& theLabel,
                                       const Huygens::DataObject theType)
    : Huygens_Object(theLabel)
{
    // set guid
    TDataStd_UAttribute::Set(theLabel, GetID());
    // set type
    TDataStd_Integer::Set(theLabel, theType);
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Huygens_DataObject::~Huygens_DataObject()
{

}

// ============================================================================
/*!
 *  \brief GetID()
*/
// ============================================================================
Standard_GUID& Huygens_DataObject::GetID()
{
    static Standard_GUID aGUID("4C4DA5ED-CD6C-4435-B401-CC101A48E840");
    return aGUID;
}

// ============================================================================
/*!
 *  \brief GetBooleanAttribute()
*/
// ============================================================================
Standard_Boolean Huygens_DataObject::GetBooleanAttribute(const Standard_Integer theIndex)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    Handle(TDataStd_Integer) aValue;
    if(!aLabel.FindAttribute(TDataStd_Integer::GetID(), aValue))
        return Standard_False;
    return (Standard_Boolean) aValue->Get();
}

// ============================================================================
/*!
 *  \brief GetDataObject()
*/
// ============================================================================
Handle(Huygens_DataObject) Huygens_DataObject::GetDataObject(const TDF_Label& theLabel)
{
    Handle(Huygens_DataObject) aDataObject;
    if(!theLabel.IsAttribute(GetID()))
        return aDataObject;
    aDataObject = new Huygens_DataObject(theLabel);
    return aDataObject;
}

// ============================================================================
/*!
 *  \brief GetIntegerAttribute()
*/
// ============================================================================
Standard_Integer Huygens_DataObject::GetIntegerAttribute(const Standard_Integer theIndex)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    Handle(TDataStd_Integer) aValue;
    if(!aLabel.FindAttribute(TDataStd_Integer::GetID(), aValue))
        return 0;
    return aValue->Get();
}

// ============================================================================
/*!
 *  \brief GetRealAttribute()
*/
// ============================================================================
Standard_Real Huygens_DataObject::GetRealAttribute(const Standard_Integer theIndex)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    Handle(TDataStd_Real) aValue;
    if(!aLabel.FindAttribute(TDataStd_Real::GetID(), aValue))
        return 0.;
    return aValue->Get();
}

// ============================================================================
/*!
 *  \brief GetStringAttribute()
*/
// ============================================================================
TCollection_AsciiString Huygens_DataObject::GetStringAttribute(const Standard_Integer theIndex)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    Handle(TDataStd_AsciiString) aValue;
    if(!aLabel.FindAttribute(TDataStd_AsciiString::GetID(), aValue))
        return TCollection_AsciiString();
    return aValue->Get();
}

// ============================================================================
/*!
 *  \brief GetType()
*/
// ============================================================================
Huygens::DataObject Huygens_DataObject::GetType(const TDF_Label &theLabel)
{
    if(!theLabel.IsAttribute(GetID()))
        return Huygens::DO_Unknown;
    Handle(TDataStd_Integer) aValue;
    if(!theLabel.FindAttribute(TDataStd_Integer::GetID(), aValue))
        return Huygens::DO_Unknown;
    return (Huygens::DataObject) aValue->Get();
}

// ============================================================================
/*!
 *  \brief GetType()
*/
// ============================================================================
Huygens::DataObject Huygens_DataObject::GetType()
{
    Handle(TDataStd_Integer) aValue;
    if(!myLabel.FindAttribute(TDataStd_Integer::GetID(), aValue))
        return Huygens::DO_Unknown;
    return (Huygens::DataObject) aValue->Get();
}

// ============================================================================
/*!
 *  \brief IsDataObject()
*/
// ============================================================================
Standard_Boolean Huygens_DataObject::IsDataObject(const TDF_Label &theLabel)
{
    return theLabel.IsAttribute(GetID());
}

// ============================================================================
/*!
 *  \brief SetBooleanAttribute()
*/
// ============================================================================
void Huygens_DataObject::SetBooleanAttribute(const Standard_Integer theIndex,
                                             const Standard_Boolean theValue)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    TDataStd_Integer::Set(aLabel, theValue);
}

// ============================================================================
/*!
 *  \brief SetIntegerAttribute()
*/
// ============================================================================
void Huygens_DataObject::SetIntegerAttribute(const Standard_Integer theIndex,
                                             const Standard_Integer theValue)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    TDataStd_Integer::Set(aLabel, theValue);
}

// ============================================================================
/*!
 *  \brief SetRealAttribute()
*/
// ============================================================================
void Huygens_DataObject::SetRealAttribute(const Standard_Integer theIndex,
                                          const Standard_Real theValue)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    TDataStd_Real::Set(aLabel, theValue);
}

// ============================================================================
/*!
 *  \brief SetStringAttribute()
*/
// ============================================================================
void Huygens_DataObject::SetStringAttribute(const Standard_Integer theIndex,
                                            const TCollection_AsciiString &theValue)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    TDataStd_AsciiString::Set(aLabel, theValue);
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_DataObject, Huygens_Object);
IMPLEMENT_STANDARD_RTTIEXT(Huygens_DataObject, Huygens_Object);
