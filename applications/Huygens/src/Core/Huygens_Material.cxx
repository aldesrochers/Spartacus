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
#include <Huygens_Material.hxx>

// OpenCascade
#include <TDataStd_UAttribute.hxx>
#include <TDataStd_Integer.hxx>
#include <TDataStd_Real.hxx>
#include <TDataStd_AsciiString.hxx>

// Object data structure
// Material ---- GUID
//    |     ---- Type
//    | ==== Properties (From object)
//    | ==== Attributes

// Define root tags
#define TAG_Properties  1
#define TAG_Attributes  2

// Define basic macros
#define ATTRIBUTE_LABEL(theIndex)   GetLabel().FindChild(TAG_Attributes).FindChild((theIndex))


// ============================================================================
/*!
 *  \brief Constructor
 *  Basic constructors for existing studies.
*/
// ============================================================================
Huygens_Material::Huygens_Material(const TDF_Label& theLabel)
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
Huygens_Material::Huygens_Material(const TDF_Label& theLabel,
                                   const Huygens::Material theType)
    : Huygens_Object(theLabel)
{
    // set guid
    TDataStd_UAttribute::Set(theLabel, GetID());
    // set type on label
    TDataStd_Integer::Set(theLabel, theType);
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Huygens_Material::~Huygens_Material()
{

}

// ============================================================================
/*!
 *  \brief GetID()
*/
// ============================================================================
Standard_GUID& Huygens_Material::GetID()
{
    static Standard_GUID aGUID("D68D7398-B566-4882-A8A6-A04245A14656");
    return aGUID;
}

// ============================================================================
/*!
    \brief GetIntegerAttr()
*/
// ============================================================================
Standard_Integer Huygens_Material::GetIntegerAttr(const Standard_Integer theIndex)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    Handle(TDataStd_Integer) aValue;
    if(!aLabel.FindAttribute(TDataStd_Integer::GetID(), aValue))
        return 0;
    return aValue->Get();
}

// ============================================================================
/*!
    \brief GetMaterial()
*/
// ============================================================================
Handle(Huygens_Material) Huygens_Material::GetMaterial(const TDF_Label& theLabel)
{
    Handle(Huygens_Material) anObject;
    if(theLabel.IsAttribute(GetID()))
        return anObject = new Huygens_Material(theLabel);
    return anObject;
}

// ============================================================================
/*!
    \brief GetRealAttr()
*/
// ============================================================================
Standard_Real Huygens_Material::GetRealAttr(const Standard_Integer theIndex)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    Handle(TDataStd_Real) aValue;
    if(!aLabel.FindAttribute(TDataStd_Real::GetID(), aValue))
        return 0.;
    return aValue->Get();
}

// ============================================================================
/*!
    \brief GetType()
*/
// ============================================================================
Huygens::Material Huygens_Material::GetType(const TDF_Label &theLabel)
{
    if(!theLabel.IsAttribute(GetID()))
        return Huygens::UnknownMaterial;
    Handle(TDataStd_Integer) aValue;
    if(!theLabel.FindAttribute(TDataStd_Integer::GetID(), aValue))
        return Huygens::UnknownMaterial;
    return (Huygens::Material) aValue->Get();
}

// ============================================================================
/*!
    \brief GetType()
*/
// ============================================================================
Huygens::Material Huygens_Material::GetType()
{
    Handle(TDataStd_Integer) aValue;
    if(!GetLabel().FindAttribute(TDataStd_Integer::GetID(), aValue))
        return Huygens::UnknownMaterial;
    return (Huygens::Material) aValue->Get();
}

// ============================================================================
/*!
    \brief IsMaterial()
*/
// ============================================================================
Standard_Boolean Huygens_Material::IsMaterial(const TDF_Label &theLabel)
{
    return theLabel.IsAttribute(GetID());
}

// ============================================================================
/*!
    \brief SetIntegerAttr()
*/
// ============================================================================
void Huygens_Material::SetIntegerAttr(const Standard_Integer theIndex,
                                      const Standard_Integer theValue)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    TDataStd_Integer::Set(aLabel, theValue);
}

// ============================================================================
/*!
    \brief SetRealAttribute()
*/
// ============================================================================
void Huygens_Material::SetRealAttr(const Standard_Integer theIndex,
                                   const Standard_Real theValue)
{
    TDF_Label aLabel = ATTRIBUTE_LABEL(theIndex);
    TDataStd_Real::Set(aLabel, theValue);
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_Material, Huygens_Object);
IMPLEMENT_STANDARD_RTTIEXT(Huygens_Material, Huygens_Object);
