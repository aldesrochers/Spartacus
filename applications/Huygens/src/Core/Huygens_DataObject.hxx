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

// Forward declarations
class Huygens_DataObject;

// Handles
DEFINE_STANDARD_HANDLE(Huygens_DataObject, Huygens_Object);


// ============================================================================
/*!
 *  \brief Huygens_DataObject
*/
// ============================================================================
class Huygens_DataObject : public Huygens_Object
{

public:
    // constructors
    Huygens_DataObject(const TDF_Label& theLabel,
                       const Huygens::ObjectType theType);
    // destructors
    ~Huygens_DataObject();

protected:
    // constructors
    Huygens_DataObject(const TDF_Label& theLabel);

public:

    static Standard_GUID&               GetID();
    static Handle(Huygens_DataObject)   GetDataObject(const TDF_Label& theLabel);
    static Standard_Boolean             IsDataObject(const TDF_Label& theLabel);

public:

    Standard_Boolean            GetBooleanAttribute(const Standard_Integer theIndex);
    Standard_Integer            GetIntegerAttribute(const Standard_Integer theIndex);
    Standard_Real               GetRealAttribute(const Standard_Integer theIndex);
    TCollection_AsciiString     GetStringAttribute(const Standard_Integer theIndex);

    void        SetBooleanAttribute(const Standard_Integer theIndex,
                                    const Standard_Boolean theValue);
    void        SetIntegerAttribute(const Standard_Integer theIndex,
                                    const Standard_Integer theValue);
    void        SetRealAttribute(const Standard_Integer theIndex,
                                 const Standard_Real theValue);
    void        SetStringAttribute(const Standard_Integer theIndex,
                                   const TCollection_AsciiString& theValue);

public:

    DEFINE_STANDARD_RTTIEXT(Huygens_DataObject, Huygens_Object);

};

#endif  // __Huygens_DataObject_hxx__
