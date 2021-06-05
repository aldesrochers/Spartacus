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


#ifndef __Huygens_DataObject_hxx__
#define __Huygens_DataObject_hxx__

// Huygens
#include <Huygens_Object.hxx>

// OpenCascade
#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>

// Forward declarations
class Huygens_DataObject;

// Handles
DEFINE_STANDARD_HANDLE(Huygens_DataObject, Huygens_Object);


// ============================================================================
/*!
    \brief Huygens_DataObject
*/
// ============================================================================
class Huygens_DataObject : public Huygens_Object
{

protected:
    // constructors
    Huygens_DataObject(const TDF_Label& theLabel);

public:
    // constructors
    Huygens_DataObject(const TDF_Label& theLabel,
                       const Standard_Integer theObjectType);
    // destructors
    ~Huygens_DataObject();

public:

    static const Standard_GUID&         GetID();
    static Handle(Huygens_DataObject)   GetDataObject(const TDF_Label& theLabel);

public:

    Standard_Boolean            GetBooleanAttribute(const Standard_Integer theAttributeId);
    Standard_Integer            GetIntegerAttribute(const Standard_Integer theAttributeId);
    Standard_Real               GetRealAttribute(const Standard_Integer theAttributeId);
    Handle(Huygens_DataObject)  GetReferenceAttribute(const Standard_Integer theAttributeId);
    TCollection_AsciiString     GetStringAttribute(const Standard_Integer theAttributeId);

    void        SetBooleanAttribute(const Standard_Integer theAttributeId,
                                    const Standard_Boolean theValue);
    void        SetIntegerAttribute(const Standard_Integer theAttributeId,
                                    const Standard_Integer theValue);
    void        SetRealAttribute(const Standard_Integer theAttributeId,
                                 const Standard_Real theValue);
    void        SetReferenceAttribute(const Standard_Integer theAttributeId,
                                      Handle(Huygens_DataObject) theObject);
    void        SetStringAttribute(const Standard_Integer theAttributeId,
                                   const TCollection_AsciiString& theString);

public:

    DEFINE_STANDARD_RTTIEXT(Huygens_DataObject, Huygens_Object)

};

#endif  // __Huygens_DataObject_hxx__
