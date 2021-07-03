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
#include <Huygens_Study.hxx>

// OpenCascade
#include <TDataStd_UAttribute.hxx>
#include <TDataStd_Integer.hxx>
#include <TDataStd_Real.hxx>
#include <TDataStd_AsciiString.hxx>

// Object data structure
// Cable ---- GUID
//   |   ---- Type
//   | ==== Properties (from object)
//   | ==== Attributes
//   | ==== Geometry
//   | ==== Cable

// Define root tags
#define TAG_Properties  1
#define TAG_Attributes  2
#define TAG_Geometry    3
#define TAG_Cable       4

// Define basic macros
#define ATTRIBUTE_LABEL(theIndex)   GetLabel().FindChild(TAG_Attributes).FindChild((theIndex))


// ============================================================================
/*!
 *  \brief Constructor
 *  Basic constructors for existing studies.
*/
// ============================================================================
Huygens_Study::Huygens_Study(const TDF_Label& theLabel)
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
Huygens_Study::Huygens_Study(const TDF_Label& theLabel,
                             const Huygens::Study theType)
    : Huygens_Object(theLabel)
{
    // set guid
    TDataStd_UAttribute::Set(theLabel, GetID());
    // set type attribute on label
    TDataStd_Integer::Set(theLabel, theType);
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Huygens_Study::~Huygens_Study()
{

}

// ============================================================================
/*!
 *  \brief GetID()
*/
// ============================================================================
Standard_GUID& Huygens_Study::GetID()
{
    static Standard_GUID aGUID("EF8C3F44-8BFB-4332-ADD5-4D58D8C551CD");
    return aGUID;
}

// ============================================================================
/*!
    \brief GetIntegerAttr()
*/
// ============================================================================
Standard_Integer Huygens_Study::GetIntegerAttr(const Standard_Integer theIndex)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    Handle(TDataStd_Integer) aValue;
    if(!aLabel.FindAttribute(TDataStd_Integer::GetID(), aValue))
        return 0;
    return aValue->Get();
}

// ============================================================================
/*!
    \brief GetRealAttr()
*/
// ============================================================================
Standard_Real Huygens_Study::GetRealAttr(const Standard_Integer theIndex)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    Handle(TDataStd_Real) aValue;
    if(!aLabel.FindAttribute(TDataStd_Real::GetID(), aValue))
        return 0.;
    return aValue->Get();
}

// ============================================================================
/*!
    \brief GetStringAttr()
*/
// ============================================================================
TCollection_AsciiString Huygens_Study::GetStringAttr(const Standard_Integer theIndex)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    Handle(TDataStd_AsciiString) aValue;
    if(!aLabel.FindAttribute(TDataStd_AsciiString::GetID(), aValue))
        return TCollection_AsciiString();
    return aValue->Get();
}

// ============================================================================
/*!
 *  \brief GetStudy()
*/
// ============================================================================
Handle(Huygens_Study) Huygens_Study::GetStudy(const TDF_Label& theLabel)
{
    Handle(Huygens_Study) aStudy;
    if(!theLabel.IsAttribute(GetID()))
        return aStudy;
    aStudy = new Huygens_Study(theLabel);
    return aStudy;
}

// ============================================================================
/*!
    \brief GetType()
*/
// ============================================================================
Huygens::Study Huygens_Study::GetType(const TDF_Label &theLabel)
{
    if(!theLabel.IsAttribute(GetID()))
        return Huygens::UnknownStudy;
    Handle(TDataStd_Integer) aValue;
    if(!theLabel.FindAttribute(TDataStd_Integer::GetID(), aValue))
        return Huygens::UnknownStudy;
    return (Huygens::Study) aValue->Get();
}

// ============================================================================
/*!
    \brief GetType()
*/
// ============================================================================
Huygens::Study Huygens_Study::GetType()
{
    Handle(TDataStd_Integer) aValue;
    if(!GetLabel().FindAttribute(TDataStd_Integer::GetID(), aValue))
        return Huygens::UnknownStudy;
    return (Huygens::Study) aValue->Get();
}

// ============================================================================
/*!
 *  \brief IsStudy()
*/
// ============================================================================
Standard_Boolean Huygens_Study::IsStudy(const TDF_Label &theLabel)
{
    return theLabel.IsAttribute(GetID());
}

// ============================================================================
/*!
    \brief SetIntegerAttr()
*/
// ============================================================================
void Huygens_Study::SetIntegerAttr(const Standard_Integer theIndex,
                                   const Standard_Integer theValue)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    TDataStd_Integer::Set(aLabel, theValue);
}

// ============================================================================
/*!
    \brief SetRealAttr()
*/
// ============================================================================
void Huygens_Study::SetRealAttr(const Standard_Integer theIndex,
                                const Standard_Real theValue)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    TDataStd_Real::Set(aLabel, theValue);
}

// ============================================================================
/*!
    \brief SetStringAttr()
*/
// ============================================================================
void Huygens_Study::SetStringAttr(const Standard_Integer theIndex,
                                  const TCollection_AsciiString &theValue)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    TDataStd_AsciiString::Set(aLabel, theValue);
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_Study, Huygens_Object);
IMPLEMENT_STANDARD_RTTIEXT(Huygens_Study, Huygens_Object);
