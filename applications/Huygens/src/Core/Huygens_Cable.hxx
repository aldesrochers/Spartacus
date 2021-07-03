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

#ifndef __Huygens_Cable_hxx__
#define __Huygens_Cable_hxx__

// Huygens
#include <Huygens_Material.hxx>
#include <Huygens_Object.hxx>
#include <Huygens_SequenceOfMaterial.hxx>

// Forward declarations
class Huygens_Cable;

// Handles
DEFINE_STANDARD_HANDLE(Huygens_Cable, Huygens_Object);


// ============================================================================
/*!
 *  \brief Huygens_Cable
*/
// ============================================================================
class Huygens_Cable : public Huygens_Object
{

public:
    // constructors
    Huygens_Cable(const TDF_Label& theLabel,
                  const Huygens::Cable theType);
    // destructors
    ~Huygens_Cable();

protected:
    // constructors
    Huygens_Cable(const TDF_Label& theLabel);

public:

    static Standard_GUID&               GetID();
    static Handle(Huygens_Cable)        GetCable(const TDF_Label& theLabel);
    static Huygens::Cable               GetType(const TDF_Label& theLabel);
    static Standard_Boolean             IsCable(const TDF_Label& theLabel);

public:

    Standard_Integer            GetIntegerAttr(const Standard_Integer theIndex);
    Standard_Real               GetRealAttr(const Standard_Integer theIndex);
    TCollection_AsciiString     GetStringAttr(const Standard_Integer theIndex);
    Huygens::Cable              GetType();
    void                        SetIntegerAttr(const Standard_Integer theIndex,
                                               const Standard_Integer theValue);
    void                        SetRealAttr(const Standard_Integer theIndex,
                                            const Standard_Real theValue);
    void                        SetStringAttr(const Standard_Integer theIndex,
                                              const TCollection_AsciiString& theValue);

public:

    DEFINE_STANDARD_RTTIEXT(Huygens_Cable, Huygens_Object);

};

#endif  // __Huygens_Cable_hxx__
