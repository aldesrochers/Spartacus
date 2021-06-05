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

// std
#include <map>

// OpenCascade
#include <TDocStd_Application.hxx>
#include <TDocStd_Document.hxx>
#include <TColStd_DataMapOfIntegerTransient.hxx>

// Huygens
#include <Huygens_StudyObject.hxx>
#include <Huygens_Types.hxx>


// ============================================================================
/*!
    \brief Huygens_Engine
*/
// ============================================================================
class Huygens_Engine
{

public:
    // constructors
    Huygens_Engine();
    // destructors
    ~Huygens_Engine();

public:

    Standard_Boolean                    CloseDocument(const Standard_Integer theDocumentId);
    Handle(TDocStd_Application)         GetApplication();
    Handle(TDocStd_Document)            GetDocument(const Standard_Integer theDocumentId,
                                                    const Standard_Boolean doForce = Standard_True);
    Handle(Huygens_StudyObject)         GetStudy(const Standard_Integer theDocumentId,
                                                 const Standard_Integer theStudyId);
    Standard_Boolean                    LoadDocument(const Standard_Integer theDocumentId,
                                                     const TCollection_AsciiString& theFileName);
    void                                NewDocument(const Standard_Integer theDocumentId,
                                                    const Standard_Integer theDocumentType = Huygens::BinaryDocument);
    Standard_Boolean                    SaveDocument(const Standard_Integer theDocumentId,
                                                     const TCollection_AsciiString& theFileName);

private:

    Handle(TDocStd_Application)         myApplication;
    TColStd_DataMapOfIntegerTransient   myDocuments;

};

#endif  // __Huygens_Engine_hxx__
