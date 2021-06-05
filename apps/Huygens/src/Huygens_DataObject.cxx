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
#include <TDataStd_Integer.hxx>
#include <TDataStd_Real.hxx>
#include <TDataStd_Comment.hxx>
#include <TDF_Reference.hxx>


// Object ---- GUID
//    |   ---- ObjectType
//    | ==== Attributes

#define SUBLABEL_Attributes   1

#define MACRO_ATTRIBUTE_LABEL(theAttributeId) GetLabel().FindChild(SUBLABEL_Attributes).FindChild((theAttributeId))


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Huygens_DataObject::Huygens_DataObject(const TDF_Label& theLabel)
    : Huygens_Object(theLabel)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Huygens_DataObject::Huygens_DataObject(const TDF_Label& theLabel,
                                       const Standard_Integer theObjectType)
    : Huygens_Object(theLabel, theObjectType)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Huygens_DataObject::~Huygens_DataObject()
{

}

// ============================================================================
/*!
    \brief GetBooleanAttribute()
*/
// ============================================================================
Standard_Boolean Huygens_DataObject::GetBooleanAttribute(const Standard_Integer theAttributeId)
{
    TDF_Label aLabel = MACRO_ATTRIBUTE_LABEL(theAttributeId);
    Handle(TDataStd_Integer) aValue;
    if(!aLabel.FindAttribute(TDataStd_Integer::GetID(), aValue))
        return Standard_False;
    if(aValue->Get() == 1)
        return Standard_True;
    return Standard_False;
}

// ============================================================================
/*!
    \brief GetDataObject()
*/
// ============================================================================
Handle(Huygens_DataObject) Huygens_DataObject::GetDataObject(const TDF_Label& theLabel)
{
    Handle(Huygens_DataObject) anObject;
    if(!theLabel.IsAttribute(GetID()))
        return anObject;
    anObject = new Huygens_DataObject(theLabel);
    return anObject;
}

// ============================================================================
/*!
    \brief GetID()
*/
// ============================================================================
const Standard_GUID& Huygens_DataObject::GetID()
{
    static Standard_GUID aGUID("610CB5FA-5DAD-4A91-B4CD-4C1E46334E26");
    return aGUID;
}

// ============================================================================
/*!
    \brief GetIntegerAttribute()
*/
// ============================================================================
Standard_Integer Huygens_DataObject::GetIntegerAttribute(const Standard_Integer theAttributeId)
{
    TDF_Label aLabel = MACRO_ATTRIBUTE_LABEL(theAttributeId);
    Handle(TDataStd_Integer) aValue;
    if(!aLabel.FindAttribute(TDataStd_Integer::GetID(), aValue))
        return 0;
    return aValue->Get();
}

// ============================================================================
/*!
    \brief GetRealAttribute()
*/
// ============================================================================
Standard_Real Huygens_DataObject::GetRealAttribute(const Standard_Integer theAttributeId)
{
    TDF_Label aLabel = MACRO_ATTRIBUTE_LABEL(theAttributeId);
    Handle(TDataStd_Real) aValue;
    if(!aLabel.FindAttribute(TDataStd_Real::GetID(), aValue))
        return 0.;
    return aValue->Get();
}

// ============================================================================
/*!
    \brief GetReference()
*/
// ============================================================================
Handle(Huygens_DataObject) Huygens_DataObject::GetReferenceAttribute(const Standard_Integer theAttributeId)
{
    Handle(Huygens_DataObject) anObject;
    TDF_Label aLabel = MACRO_ATTRIBUTE_LABEL(theAttributeId);
    Handle(TDF_Reference) aReference;
    if(!aLabel.FindAttribute(TDF_Reference::GetID(), aReference))
        return anObject;
    anObject = Huygens_DataObject::GetDataObject(aReference->Get());
    return anObject;
}

// ============================================================================
/*!
    \brief GetStringAttribute()
*/
// ============================================================================
TCollection_AsciiString Huygens_DataObject::GetStringAttribute(const Standard_Integer theAttributeId)
{
    TDF_Label aLabel = MACRO_ATTRIBUTE_LABEL(theAttributeId);
    TCollection_AsciiString aString;
    Handle(TDataStd_Comment) aValue;
    if(!aLabel.FindAttribute(TDataStd_Comment::GetID(), aValue))
        return aString;
    aString = TCollection_AsciiString(aValue->Get());
    return aString;
}

// ============================================================================
/*!
    \brief SetBooleanAttribute()
*/
// ============================================================================
void Huygens_DataObject::SetBooleanAttribute(const Standard_Integer theAttributeId,
                                             const Standard_Boolean theValue)
{
    TDF_Label aLabel = MACRO_ATTRIBUTE_LABEL(theAttributeId);
    if(theValue == Standard_True)
        TDataStd_Integer::Set(aLabel, 1);
    else
        TDataStd_Integer::Set(aLabel, 0);
}

// ============================================================================
/*!
    \brief SetIntegerAttribute()
*/
// ============================================================================
void Huygens_DataObject::SetIntegerAttribute(const Standard_Integer theAttributeId,
                                             const Standard_Integer theValue)
{
    TDF_Label aLabel = MACRO_ATTRIBUTE_LABEL(theAttributeId);
    TDataStd_Integer::Set(aLabel, theValue);
}

// ============================================================================
/*!
    \brief SetRealAttribute()
*/
// ============================================================================
void Huygens_DataObject::SetRealAttribute(const Standard_Integer theAttributeId,
                                          const Standard_Real theValue)
{
    TDF_Label aLabel = MACRO_ATTRIBUTE_LABEL(theAttributeId);
    TDataStd_Real::Set(aLabel, theValue);
}

// ============================================================================
/*!
 *  \brief SetReferenceAttribute()
*/
// ============================================================================
void Huygens_DataObject::SetReferenceAttribute(const Standard_Integer theAttributeId,
                                               Handle(Huygens_DataObject) theObject)
{
    if(theObject.IsNull())
        return;
    TDF_Label aLabel = MACRO_ATTRIBUTE_LABEL(theAttributeId);
    TDF_Reference::Set(aLabel, theObject->GetLabel());
}

// ============================================================================
/*!
    \brief SetStringAttribute()
*/
// ============================================================================
void Huygens_DataObject::SetStringAttribute(const Standard_Integer theAttributeId,
                                            const TCollection_AsciiString &theString)
{
    TDF_Label aLabel = MACRO_ATTRIBUTE_LABEL(theAttributeId);
    TDataStd_Comment::Set(aLabel, theString);
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_DataObject, Huygens_Object)
IMPLEMENT_STANDARD_RTTIEXT(Huygens_DataObject, Huygens_Object)
