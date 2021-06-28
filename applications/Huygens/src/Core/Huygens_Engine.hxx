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

// Huygens
#include <Huygens_DataObject.hxx>
#include <Huygens_IDomainOperations.hxx>
#include <Huygens_IPropertyOperations.hxx>
#include <Huygens_Study.hxx>

// Forward declarations
class Huygens_Engine;

// Handles
DEFINE_STANDARD_HANDLE(Huygens_Engine, Standard_Transient);


// ============================================================================
/*!
 *  \brief Huygens_Engine
*/
// ============================================================================
class Huygens_Engine : public Standard_Transient
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
    Handle(Huygens_DataObject)          GetDocumentProperties(const Standard_Integer theDocumentId,
                                                              const Standard_Boolean force = Standard_True);
    Handle(Huygens_IDomainOperations)   GetIDomainOperations(const Standard_Integer theDocumentId,
                                                             const Standard_Integer theStudyId);
    Handle(Huygens_IPropertyOperations) GetIPropertyOperations(const Standard_Integer theDocumentId);
    Handle(Huygens_Study)               GetStudy(const Standard_Integer theDocumentId,
                                                 const Standard_Integer theStudyId);
    Handle(Huygens_DataObject)          NewMaterial(const Standard_Integer theDocumentId,
                                                    const Huygens::ObjectType theType);
    Standard_Boolean                    SaveDocumentAsXML(const Standard_Integer theDocumentId,
                                                          const TCollection_AsciiString& theFileName);









    Standard_Boolean                    ExportStudyToHSF(Handle(Huygens_Study) theStudy,
                                                         const TCollection_AsciiString& theFileName);
    Standard_Boolean                    ExportStudyToHSF(const Standard_Integer theDocumentId,
                                                         const Standard_Integer theStudyId,
                                                         const TCollection_AsciiString& theFileName);
    Standard_Boolean                    ExportStudyToXML(Handle(Huygens_Study) theStudy,
                                                         const TCollection_AsciiString& theFileName);
    Standard_Boolean                    ExportStudyToXML(const Standard_Integer theDocumentId,
                                                         const Standard_Integer theStudyId,
                                                         const TCollection_AsciiString& theFileName);
    Standard_Boolean                    ImportStudyFromHSF(Handle(Huygens_Study) theStudy,
                                                           const TCollection_AsciiString& theFileName);
    Standard_Boolean                    ImportStudyFromHSF(const Standard_Integer theDocumentId,
                                                           const Standard_Integer theStudyId,
                                                           const TCollection_AsciiString& theFileName);
    Standard_Boolean                    ImportStudyFromXML(Handle(Huygens_Study) theStudy,
                                                           const TCollection_AsciiString& theFileName);
    Standard_Boolean                    ImportStudyFromXML(const Standard_Integer theDocumentId,
                                                           const Standard_Integer theStudyId,
                                                           const TCollection_AsciiString& theFileName);
    Standard_Boolean                    IsStudy(const Standard_Integer theDocumentId,
                                                const Standard_Integer theStudyId);
    Standard_Boolean                    LoadDocument(const Standard_Integer theDocumentId,
                                                     const TCollection_AsciiString& theFileName);
    Standard_Integer                    NbStudies(const Standard_Integer theDocumentId);
    Handle(Huygens_Study)               NewStudy(const Standard_Integer theDocumentId);
    Standard_Boolean                    RemoveStudy(Handle(Huygens_Study) theStudy);
    Standard_Boolean                    RemoveStudy(const Standard_Integer theDocumentId,
                                                    const Standard_Integer theStudyId);
    Standard_Boolean                    SaveDocument(const Standard_Integer theDocumentId,
                                                     const TCollection_AsciiString& theFileName);

private:

    Standard_Boolean                    ExportStudyToANY(Handle(Huygens_Study) theStudy,
                                                         const TCollection_AsciiString& theFileName,
                                                         const Standard_Integer theFormat);
    Standard_Boolean                    ExportStudyToANY(const Standard_Integer theDocumentId,
                                                         const Standard_Integer theStudyId,
                                                         const TCollection_AsciiString& theFileName,
                                                         const Standard_Integer theFormat);
    Standard_Boolean                    ImportStudyFromANY(const Standard_Integer theDocumentId,
                                                           const Standard_Integer theStudyId,
                                                           const TCollection_AsciiString& theFileName,
                                                           const Standard_Integer theFormat);
    Standard_Boolean                    ImportStudyFromANY(Handle(Huygens_Study) theStudy,
                                                           const TCollection_AsciiString& theFileName,
                                                           const Standard_Integer theFormat);

private:

    Handle(TDocStd_Application)         myApplication;
    TColStd_DataMapOfIntegerTransient   myDocuments;

public:

    DEFINE_STANDARD_RTTIEXT(Huygens_Engine, Standard_Transient);

};

#endif  // __Huygens_Engine_hxx__
