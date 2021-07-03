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

#ifndef __Huygens_Study_hxx__
#define __Huygens_Study_hxx__

// Huygens
#include <Huygens_Object.hxx>

// Forward declarations
class Huygens_Study;

// Handles
DEFINE_STANDARD_HANDLE(Huygens_Study, Huygens_Object);


// ============================================================================
/*!
 *  \brief Huygens_Study
*/
// ============================================================================
class Huygens_Study : public Huygens_Object
{

public:
    // constructors
    Huygens_Study(const TDF_Label& theLabel,
                  const Huygens::Study theType);
    // destructors
    ~Huygens_Study();

protected:
    // constructors
    Huygens_Study(const TDF_Label& theLabel);

public:

    static Standard_GUID&           GetID();
    static Handle(Huygens_Study)    GetStudy(const TDF_Label& theLabel);
    static Huygens::Study           GetType(const TDF_Label& theLabel);
    static Standard_Boolean         IsStudy(const TDF_Label& theLabel);

public:

    Standard_Integer            GetIntegerAttr(const Standard_Integer theIndex);
    Standard_Real               GetRealAttr(const Standard_Integer theIndex);
    TCollection_AsciiString     GetStringAttr(const Standard_Integer theIndex);
    Huygens::Study              GetType();

    void            SetIntegerAttr(const Standard_Integer theIndex,
                                   const Standard_Integer theValue);
    void            SetRealAttr(const Standard_Integer theIndex,
                                const Standard_Real theValue);
    void            SetStringAttr(const Standard_Integer theIndex,
                                  const TCollection_AsciiString& theValue);

public:

    DEFINE_STANDARD_RTTIEXT(Huygens_Study, Huygens_Object);

};

#endif  // __Huygens_Study_hxx__
