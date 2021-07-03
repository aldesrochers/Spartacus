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

#ifndef __Huygens_Material_hxx__
#define __Huygens_Material_hxx__

// Huygens
#include <Huygens_Object.hxx>

// Forward declarations
class Huygens_Material;

// Handles
DEFINE_STANDARD_HANDLE(Huygens_Material, Huygens_Object);


// ============================================================================
/*!
 *  \brief Huygens_Material
*/
// ============================================================================
class Huygens_Material : public Huygens_Object
{

public:
    // constructors
    Huygens_Material(const TDF_Label& theLabel,
                     const Huygens::Material theType);
    // destructors
    ~Huygens_Material();

protected:
    // constructors
    Huygens_Material(const TDF_Label& theLabel);

public:

    static Standard_GUID&               GetID();
    static Handle(Huygens_Material)     GetMaterial(const TDF_Label& theLabel);
    static Huygens::Material            GetType(const TDF_Label& theLabel);
    static Standard_Boolean             IsMaterial(const TDF_Label& theLabel);

public:

    Standard_Integer            GetIntegerAttr(const Standard_Integer theIndex);
    Standard_Real               GetRealAttr(const Standard_Integer theIndex);
    Huygens::Material           GetType();


    void        SetIntegerAttr(const Standard_Integer theIndex,
                               const Standard_Integer theValue);
    void        SetRealAttr(const Standard_Integer theIndex,
                            const Standard_Real theValue);

public:

    DEFINE_STANDARD_RTTIEXT(Huygens_Material, Huygens_Object);

};

#endif  // __Huygens_Material_hxx__
