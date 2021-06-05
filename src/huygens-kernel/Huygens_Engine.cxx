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

// Huygens
#include <Huygens_Engine.hxx>

// OpenCascade
#include <BinDrivers_DocumentRetrievalDriver.hxx>
#include <BinDrivers_DocumentStorageDriver.hxx>
#include <XmlDrivers_DocumentRetrievalDriver.hxx>
#include <XmlDrivers_DocumentStorageDriver.hxx>
#include <TDataStd_Integer.hxx>

// Document
#define Huygens_XML_DOCUMENT        "Huygens_Xml_Format"
#define Huygens_BINARY_DOCUMENT     "Huygens_Binary_Format"

// Document ---- DocumentId
//    | ==== StudyObject 1
//    | ==== StudyObject 2
//    | ==== ...


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Huygens_Engine::Huygens_Engine()
{
    // initialize application
    myApplication = new TDocStd_Application();

    // define xml format
    myApplication->DefineFormat(Huygens_XML_DOCUMENT,
                                "Huygens XML document format.",
                                "xml",
                                new XmlDrivers_DocumentRetrievalDriver(),
                                new XmlDrivers_DocumentStorageDriver(TCollection_ExtendedString()));

    // define binary format
    myApplication->DefineFormat(Huygens_BINARY_DOCUMENT,
                                "Huygens binary document format.",
                                "hff",
                                new BinDrivers_DocumentRetrievalDriver(),
                                new BinDrivers_DocumentStorageDriver());
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Huygens_Engine::~Huygens_Engine()
{

}

// ============================================================================
/*!
    \brief CloseDocument()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::CloseDocument(const Standard_Integer theDocumentId)
{
    if(!myDocuments.IsBound(theDocumentId))
        return Standard_False;
    myDocuments.UnBind(theDocumentId);
    return Standard_True;
}

// ============================================================================
/*!
    \brief GetDocument()
*/
// ============================================================================
Handle(TDocStd_Document) Huygens_Engine::GetDocument(const Standard_Integer theDocumentId,
                                                     const Standard_Boolean doForce)
{
    Handle(TDocStd_Document) aDocument;
    if(!myDocuments.IsBound(theDocumentId) && doForce)
        this->NewDocument(theDocumentId, Huygens::BinaryDocument);
    if(myDocuments.IsBound(theDocumentId))
        aDocument = Handle(TDocStd_Document)::DownCast(myDocuments(theDocumentId));
    return aDocument;
}

// ============================================================================
/*!
    \brief GetStudy()
*/
// ============================================================================
Handle(Huygens_StudyObject) Huygens_Engine::GetStudy(const Standard_Integer theDocumentId,
                                                     const Standard_Integer theStudyId)
{
    Handle(TDocStd_Document) aDocument = GetDocument(theDocumentId);
    // label for study X
    Handle(Huygens_StudyObject) aStudy;
    TDF_Label aLabel = aDocument->Main().FindChild(theStudyId);
    if(aLabel.IsAttribute(Huygens_StudyObject::GetID())) {
        aStudy = Huygens_StudyObject::GetStudyObject(aLabel);
    } else {
        aStudy = new Huygens_StudyObject(aLabel, Huygens::StudyObject);
    }
    return aStudy;
}

// ============================================================================
/*!
    \brief LoadDocument()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::LoadDocument(const Standard_Integer theDocumentId,
                                              const TCollection_AsciiString &theFileName)
{
    if(myDocuments.IsBound(theDocumentId))
        myDocuments.UnBind(theDocumentId);
    Handle(TDocStd_Document) aDocument;
    if(myApplication->Open(theFileName, aDocument) != PCDM_RS_OK)
        return Standard_False;
    myDocuments.Bind(theDocumentId, aDocument);
    TDataStd_Integer::Set(aDocument->Main(), theDocumentId);
    return Standard_True;
}

// ============================================================================
/*!
    \brief NewDocument()
*/
// ============================================================================
void Huygens_Engine::NewDocument(const Standard_Integer theDocumentId,
                                             const Standard_Integer theDocumentType)
{
    if(myDocuments.IsBound(theDocumentId))
        myDocuments.UnBind(theDocumentId);
    Handle(TDocStd_Document) aDocument;
    // create document with proper format
    switch (theDocumentType) {
    case Huygens::XmlDocument:
        myApplication->NewDocument(Huygens_XML_DOCUMENT, aDocument);
        break;
    default:
        myApplication->NewDocument(Huygens_BINARY_DOCUMENT, aDocument);
        break;
    }
    // bind document in engine
    myDocuments.Bind(theDocumentId, aDocument);
    TDataStd_Integer::Set(aDocument->Main(), theDocumentId);
}

// ============================================================================
/*!
    \brief SaveDocument()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::SaveDocument(const Standard_Integer theDocumentId,
                                              const TCollection_AsciiString &theFileName)
{
    if(!myDocuments.IsBound(theDocumentId))
        return Standard_False;
    Handle(TDocStd_Document) aDocument =
            Handle(TDocStd_Document)::DownCast(myDocuments(theDocumentId));
    myApplication->SaveAs(aDocument, theFileName);
    return Standard_True;
}
