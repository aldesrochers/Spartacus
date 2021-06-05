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
#include <Huygens_StudyObject.hxx>
#include <Huygens_Types.hxx>

// OpenCascade
#include <TDF_ChildIterator.hxx>


// Object ---- GUID
//    |   ---- ObjectType
//    | ==== DataObject (Study Attributes)
//    | ==== Cables
//    |        | ==== DataObject (Cable 1 - Properties)
//    |        | ==== DataObject (Cable ... - Properties)
//    |        | ==== ...
//    | ==== WeatherCases
//    |        | ==== DataObject (LoadCase 1 - Definition)
//    |        | ==== DataObject (LoadCase ... - Definition)
//    |        | ==== ...



#define SUBLABEL_Attributes     1
#define SUBLABEL_Cables         2
#define SUBLABEL_LoadCases          3

#define MACRO_LABEL_CABLE(theCableId)   GetLabel().FindChild(SUBLABEL_Cables).FindChild((theCableId))
#define MACRO_LABEL_LoadCase(theLoadCaseId)     GetLabel().FindChild(SUBLABEL_LoadCases).FindChild((theLoadCaseId))



// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Huygens_StudyObject::Huygens_StudyObject(const TDF_Label& theLabel)
    : Huygens_Object(theLabel)
{
    // initialize study attributes
    TDF_Label aLabel = GetLabel().FindChild(SUBLABEL_Attributes);
    myAttributes = Huygens_DataObject::GetDataObject(aLabel);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Huygens_StudyObject::Huygens_StudyObject(const TDF_Label& theLabel,
                                         const Standard_Integer theObjectType)
    : Huygens_Object(theLabel, theObjectType)
{
    // initialize study attributes
    TDF_Label aLabel = GetLabel().FindChild(SUBLABEL_Attributes);
    myAttributes = new Huygens_DataObject(aLabel, Huygens::StudyAttributes);
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Huygens_StudyObject::~Huygens_StudyObject()
{

}

// ============================================================================
/*!
    \brief GetID()
*/
// ============================================================================
const Standard_GUID& Huygens_StudyObject::GetID()
{
    static Standard_GUID aGUID("18422EAF-211F-4EDE-8919-B369B67A1722");
    return aGUID;
}

// ============================================================================
/*!
    \brief GetAttributes()
*/
// ============================================================================
Handle(Huygens_DataObject) Huygens_StudyObject::GetAttributes()
{
    return myAttributes;
}

// ============================================================================
/*!
    \brief AddCable()
*/
// ============================================================================
Handle(Huygens_DataObject) Huygens_StudyObject::AddCable()
{
    TDF_Label aRootLabel = GetLabel().FindChild(SUBLABEL_Cables);
    TDF_Label aLabel = TDF_TagSource::NewChild(aRootLabel);
    Handle(Huygens_DataObject) anObject =
            new Huygens_DataObject(aLabel, Huygens::CableObject);
    return anObject;
}

// ============================================================================
/*!
    \brief AddLoadCase()
*/
// ============================================================================
Handle(Huygens_DataObject) Huygens_StudyObject::AddLoadCase()
{
    TDF_Label aRootLabel = GetLabel().FindChild(SUBLABEL_LoadCases);
    TDF_Label aLabel = TDF_TagSource::NewChild(aRootLabel);
    Handle(Huygens_DataObject) anObject =
            new Huygens_DataObject(aLabel, Huygens::LoadCaseObject);
    return anObject;
}

// ============================================================================
/*!
    \brief GetCable()
*/
// ============================================================================
Handle(Huygens_DataObject) Huygens_StudyObject::GetCable(const Standard_Integer theCableId,
                                                         const Standard_Boolean doForce)
{
    Handle(Huygens_DataObject) anObject;
    if(myCables.IsBound(theCableId)) {
        anObject = Handle(Huygens_DataObject)::DownCast(myCables(theCableId));
    } else if(doForce) {
        TDF_Label aLabel = MACRO_LABEL_CABLE(theCableId);
        anObject = new Huygens_DataObject(aLabel, Huygens::CableObject);
        myCables.Bind(theCableId, anObject);
    }
    return anObject;
}

// ============================================================================
/*!
    \brief GetStudyObject()
*/
// ============================================================================
Handle(Huygens_StudyObject) Huygens_StudyObject::GetStudyObject(const TDF_Label& theLabel)
{
    Handle(Huygens_StudyObject) anObject;
    if(!theLabel.IsAttribute(GetID()))
        return anObject;
    anObject = new Huygens_StudyObject(theLabel);
    return anObject;
}

// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_StudyObject, Huygens_Object)
IMPLEMENT_STANDARD_RTTIEXT(Huygens_StudyObject, Huygens_Object)
