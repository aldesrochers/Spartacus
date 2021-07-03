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

#ifndef __Huygens_Engine_hxx__
#define __Huygens_Engine_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <TDocStd_Application.hxx>
#include <TDocStd_Document.hxx>
#include <TColStd_DataMapOfIntegerTransient.hxx>

// Spartacus
#include <Huygens_ICableOperations.hxx>
#include <Huygens_IMaterialOperations.hxx>

// Forward declarations
class Huygens_Engine;

// Handles
DEFINE_STANDARD_HANDLE(Huygens_Engine, Standard_Transient);


// ============================================================================
/*!
 *  \brief Huygens_Engine
*/
// ============================================================================
class Standard_EXPORT Huygens_Engine : public Standard_Transient
{

public:
    // constructors
    Huygens_Engine();
    // destructors
    ~Huygens_Engine();

public:

    Handle(TDocStd_Application)         GetApplication();
    Standard_Boolean                    CloseDocument(const Standard_Integer theDocumentId);
    Handle(TDocStd_Document)            GetDocument(const Standard_Integer theDocumentId,
                                                    const Standard_Boolean force = Standard_True);
    Handle(Huygens_ICableOperations)    GetICableOperations(const Standard_Integer theDocumentId);
    Handle(Huygens_IMaterialOperations) GetIMaterialOperations(const Standard_Integer theDocumentId);
    Handle(Huygens_Material)            NewMaterial(const Standard_Integer theDocumentId,
                                                    const Huygens::Material theType);
    Standard_Boolean                    LoadDocument(const Standard_Integer theDocumentId,
                                                     const TCollection_AsciiString& theFileName);
    Standard_Boolean                    SaveDocument(const Standard_Integer theDocumentId,
                                                     const TCollection_AsciiString& theFileName);
    Standard_Boolean                    SaveDocumentAsXML(const Standard_Integer theDocumentId,
                                                          const TCollection_AsciiString& theFileName);

private:

    Handle(TDocStd_Application)         myApplication;
    TColStd_DataMapOfIntegerTransient   myDocuments;
    TColStd_DataMapOfIntegerTransient   myICableOperations;
    TColStd_DataMapOfIntegerTransient   myIMaterialOperations;

public:

    DEFINE_STANDARD_RTTIEXT(Huygens_Engine, Standard_Transient);

};

#endif  // __Huygens_Engine_hxx__
