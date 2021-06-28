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

#ifndef __Huygens_Object_hxx__
#define __Huygens_Object_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <TDF_Label.hxx>

// Spartacus
#include <Huygens_Types.hxx>

// Forward declarations
class Huygens_Object;

// Handles
DEFINE_STANDARD_HANDLE(Huygens_Object, Standard_Transient);


// ============================================================================
/*!
 *  \brief Huygens_Object
*/
// ============================================================================
class Huygens_Object : public Standard_Transient
{

public:
    // constructors
    Huygens_Object(const TDF_Label& theLabel,
                   const Huygens::ObjectType theType);
    // destructors
    ~Huygens_Object();

protected:
    // constructors
    Huygens_Object(const TDF_Label& theLabel);

public:

    static Standard_GUID&           GetID();
    static Handle(Huygens_Object)   GetObject(const TDF_Label& theLabel);
    static Standard_Integer         GetType(const TDF_Label& theLabel);

public:

    TCollection_AsciiString     GetEntry();
    TDF_Label                   GetLabel();
    Standard_Integer            GetType();

private:

    TDF_Label                   myLabel;

public:

    DEFINE_STANDARD_RTTIEXT(Huygens_Object, Standard_Transient);

};

#endif  // __Huygens_Object_hxx__
