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


#ifndef __Huygens_StudyObject_hxx__
#define __Huygens_StudyObject_hxx__

// Huygens
#include <Huygens_Object.hxx>
#include <Huygens_DataObject.hxx>

// OpenCascade
#include <TColStd_DataMapOfIntegerTransient.hxx>

// Forward declarations
class Huygens_StudyObject;

// Handles
DEFINE_STANDARD_HANDLE(Huygens_StudyObject, Huygens_Object);


// ============================================================================
/*!
    \brief Huygens_StudyObject
    Class implementation of a generic study object.
*/
// ============================================================================
class Huygens_StudyObject : public Huygens_Object
{

protected:
    // constructors
    Huygens_StudyObject(const TDF_Label& theLabel);

public:
    // constructors
    Huygens_StudyObject(const TDF_Label& theLabel,
                        const Standard_Integer theObjectType);
    // destructors
    ~Huygens_StudyObject();

public:

    static const Standard_GUID&         GetID();
    static Handle(Huygens_StudyObject)  GetStudyObject(const TDF_Label& theLabel);

public:

    Handle(Huygens_DataObject)          AddCable();
    Handle(Huygens_DataObject)          AddLoadCase();
    Handle(Huygens_DataObject)          GetAttributes();
    Handle(Huygens_DataObject)          GetCable(const Standard_Integer theCableId,
                                                 const Standard_Boolean doForce = Standard_True);

private:

    Handle(Huygens_DataObject)          myAttributes;
    TColStd_DataMapOfIntegerTransient   myCables;
    TColStd_DataMapOfIntegerTransient   myAnalyses;

public:

    DEFINE_STANDARD_RTTIEXT(Huygens_StudyObject, Huygens_Object)

};

#endif  // __Huygens_StudyObject_hxx__
