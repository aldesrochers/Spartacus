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
#include <TDocStd_XLinkTool.hxx>
#include <TDF_ChildIterator.hxx>

// Structure of a document
// Document ---- DocumentId (in engine)
//     | ==== Properties
//     | ==== Studies
//     | ==== Materials
//     | ==== Cables
//     | ==== Insultators
//     | ==== ...

// Definition of child tags
#define TAG_Properties      1
#define TAG_Materials       2
#define TAG_Sections        3
#define TAG_Studies         4

// Definition of Study Import/Export document types
#define Huygens_BinaryStudyFormat   1
#define Huygens_XmlStudyFormat      2


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Huygens_Engine::Huygens_Engine()
{

    // initialize the OCAF application
    myApplication = new TDocStd_Application();

    // define generic document type for the engine
    myApplication->DefineFormat("Huygens_DocumentFormat",
                                "Document format for Huygens application.",
                                "hef",
                                new BinDrivers_DocumentRetrievalDriver(),
                                new BinDrivers_DocumentStorageDriver());

    // define an xml format for a Huygens document
    myApplication->DefineFormat("Huygens_XmlDocumentFormat",
                                "XML document format for Huygens.",
                                "xml",
                                new XmlDrivers_DocumentRetrievalDriver(),
                                new XmlDrivers_DocumentStorageDriver(TCollection_ExtendedString()));

    // define binary type for a single study
    myApplication->DefineFormat("Huygens_BinaryStudyFormat",
                                "Binary document format for a single Huygens study.",
                                "hsf",
                                new BinDrivers_DocumentRetrievalDriver(),
                                new BinDrivers_DocumentStorageDriver());

    // define xml type for a single study
    myApplication->DefineFormat("Huygens_XmlStudyFormat",
                                "Document format for Huygens studies.",
                                "xml",
                                new XmlDrivers_DocumentRetrievalDriver(),
                                new XmlDrivers_DocumentStorageDriver(TCollection_ExtendedString()));
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Huygens_Engine::~Huygens_Engine()
{

}

// ============================================================================
/*!
 *  \brief GetApplication()
*/
// ============================================================================
Handle(TDocStd_Application) Huygens_Engine::GetApplication()
{
    return myApplication;
}

// ============================================================================
/*!
 *  \brief CloseDocument()
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
 *  \brief GetDocument()
*/
// ============================================================================
Handle(TDocStd_Document) Huygens_Engine::GetDocument(const Standard_Integer theDocumentId,
                                                     const Standard_Boolean force)
{
    Handle(TDocStd_Document) aDoc;
    if(myDocuments.IsBound(theDocumentId)) {
        aDoc = Handle(TDocStd_Document)::DownCast(myDocuments(theDocumentId));
    } else if(force) {
        // create new document
        myApplication->NewDocument("Huygens_DocumentFormat", aDoc);
        // bind in engine
        myDocuments.Bind(theDocumentId, aDoc);
        // add the study id in document
        TDataStd_Integer::Set(aDoc->Main(), theDocumentId);
    }
    return aDoc;
}

// ============================================================================
/*!
 *  \brief GetDocumentProperties()
*/
// ============================================================================
Handle(Huygens_DataObject) Huygens_Engine::GetDocumentProperties(const Standard_Integer theDocumentId,
                                                                 const Standard_Boolean force)
{
    // retrieve document and 'Properties' label
    Handle(TDocStd_Document) aDoc = GetDocument(theDocumentId, force);
    TDF_Label aLabel = aDoc->Main().FindChild(TAG_Properties);
    // find or create new object
    Handle(Huygens_DataObject) anObject;
    if(Huygens_DataObject::IsDataObject(aLabel))
        anObject = Huygens_DataObject::GetDataObject(aLabel);
    else
        anObject = new Huygens_DataObject(aLabel, Huygens::DocumentProperties);
    return anObject;
}

// ============================================================================
/*!
 *  \brief GetIDomainOperations()
*/
// ============================================================================
Handle(Huygens_IDomainOperations) Huygens_Engine::GetIDomainOperations(const Standard_Integer theDocumentId,
                                                                       const Standard_Integer theStudyId)
{

}

// ============================================================================
/*!
 *  \brief GetIPropertyOperations()
*/
// ============================================================================
Handle(Huygens_IPropertyOperations) Huygens_Engine::GetIPropertyOperations(const Standard_Integer theDocumentId)
{
    Handle(Huygens_IPropertyOperations) anOperations =
            new Huygens_IPropertyOperations(this, theDocumentId);
    return anOperations;
}

// ============================================================================
/*!
 *  \brief GetStudy()
*/
// ============================================================================
Handle(Huygens_Study) Huygens_Engine::GetStudy(const Standard_Integer theDocumentId,
                                               const Standard_Integer theStudyId)
{
    // retrieve a document
    Handle(TDocStd_Document) aDocument = GetDocument(theDocumentId);
    // retrieve a label for the study
    TDF_Label aLabel = aDocument->Main().FindChild(TAG_Studies).FindChild(theStudyId);
    // retrieve a study
    Handle(Huygens_Study) aStudy;
    if(Huygens_Study::IsStudy(aLabel))
        aStudy = Huygens_Study::GetStudy(aLabel);
    else
        aStudy = new Huygens_Study(aLabel, Huygens::Study);
    return aStudy;
}

// ============================================================================
/*!
 *  \brief ExportStudyToANY()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::ExportStudyToANY(Handle(Huygens_Study) theStudy,
                                                  const TCollection_AsciiString &theFileName,
                                                  const Standard_Integer theFormat)
{
    if(theStudy.IsNull())
        return Standard_False;
    // create new document for the export
    Handle(TDocStd_Document) outDocument;
    if(theFormat == Huygens_BinaryStudyFormat)
        myApplication->NewDocument("Huygens_BinaryStudyFormat", outDocument);
    else if(theFormat == Huygens_XmlStudyFormat)
        myApplication->NewDocument("Huygens_XmlStudyFormat", outDocument);
    else
        myApplication->NewDocument("Huygens_BinaryStudyFormat", outDocument);
    // copy study content to new document
    TDocStd_XLinkTool aTool;
    aTool.Copy(outDocument->Main(), theStudy->GetLabel());
    // save document to disk
    if(myApplication->SaveAs(outDocument, theFileName) != PCDM_SS_OK)
        return Standard_False;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief ExportStudyToANY()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::ExportStudyToANY(const Standard_Integer theDocumentId,
                                                  const Standard_Integer theStudyId,
                                                  const TCollection_AsciiString &theFileName,
                                                  const Standard_Integer theFormat)
{
    if(!myDocuments.IsBound(theDocumentId))
        return Standard_False;
    Handle(Huygens_Study) aStudy = GetStudy(theDocumentId, theStudyId);
    return ExportStudyToANY(aStudy, theFileName, theFormat);
}

// ============================================================================
/*!
 *  \brief ExportStudyToHSF()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::ExportStudyToHSF(Handle(Huygens_Study) theStudy,
                                                  const TCollection_AsciiString &theFileName)
{
    return ExportStudyToANY(theStudy, theFileName, Huygens_BinaryStudyFormat);
}

// ============================================================================
/*!
 *  \brief ExportStudyToHSF()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::ExportStudyToHSF(const Standard_Integer theDocumentId,
                                                  const Standard_Integer theStudyId,
                                                  const TCollection_AsciiString &theFileName)
{
    return ExportStudyToANY(theDocumentId, theStudyId, theFileName, Huygens_BinaryStudyFormat);
}

// ============================================================================
/*!
 *  \brief ExportStudyToXML()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::ExportStudyToXML(Handle(Huygens_Study) theStudy,
                                                  const TCollection_AsciiString &theFileName)
{
    return ExportStudyToANY(theStudy, theFileName, Huygens_XmlStudyFormat);
}

// ============================================================================
/*!
 *  \brief ExportStudyToXML()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::ExportStudyToXML(const Standard_Integer theDocumentId,
                                                  const Standard_Integer theStudyId,
                                                  const TCollection_AsciiString &theFileName)
{
    return ExportStudyToANY(theDocumentId, theStudyId, theFileName, Huygens_XmlStudyFormat);
}

// ============================================================================
/*!
 *  \brief ImportStudyFromANY()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::ImportStudyFromANY(Handle(Huygens_Study) theStudy,
                                                    const TCollection_AsciiString &theFileName,
                                                    const Standard_Integer theFormat)
{
    // check if valid study
    if(theStudy.IsNull())
        return Standard_False;
    // load study document
    Handle(TDocStd_Document) inDocument;
    if(myApplication->Open(theFileName, inDocument) != PCDM_RS_OK)
        return Standard_False;
    // copy content from file to master document
    TDocStd_XLinkTool aTool;
    aTool.Copy(theStudy->GetLabel(), inDocument->Main());
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief ImportStudyFromANY()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::ImportStudyFromANY(const Standard_Integer theDocumentId,
                                                    const Standard_Integer theStudyId,
                                                    const TCollection_AsciiString &theFileName,
                                                    const Standard_Integer theFormat)
{
    if(!myDocuments.IsBound(theDocumentId))
        return Standard_False;
    // initialize a new study in engine
    Handle(Huygens_Study) aStudy = GetStudy(theDocumentId, theStudyId);
    return ImportStudyFromANY(aStudy, theFileName, theFormat);
}

// ============================================================================
/*!
 *  \brieef ImportStudyFromHSF()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::ImportStudyFromHSF(Handle(Huygens_Study) theStudy,
                                                    const TCollection_AsciiString &theFileName)
{
    return ImportStudyFromANY(theStudy, theFileName, Huygens_BinaryStudyFormat);
}

// ============================================================================
/*!
 *  \brief ImportStudyFromHSF()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::ImportStudyFromHSF(const Standard_Integer theDocumentId,
                                                    const Standard_Integer theStudyId,
                                                    const TCollection_AsciiString &theFileName)
{
    return ImportStudyFromANY(theDocumentId, theStudyId, theFileName, Huygens_BinaryStudyFormat);
}

// ============================================================================
/*!
 *  \brief ImportStudyFromXML()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::ImportStudyFromXML(Handle(Huygens_Study) theStudy,
                                                    const TCollection_AsciiString &theFileName)
{
    return ImportStudyFromANY(theStudy, theFileName, Huygens_XmlStudyFormat);
}

// ============================================================================
/*!
 *  \brief ImportStudyFromXML()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::ImportStudyFromXML(const Standard_Integer theDocumentId,
                                                    const Standard_Integer theStudyId,
                                                    const TCollection_AsciiString &theFileName)
{
    return ImportStudyFromANY(theDocumentId, theStudyId, theFileName, Huygens_XmlStudyFormat);
}

// ============================================================================
/*!
 *  \brief IsStudy()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::IsStudy(const Standard_Integer theDocumentId,
                                         const Standard_Integer theStudyId)
{
    if(!myDocuments.IsBound(theDocumentId))
        return Standard_False;
    Handle(TDocStd_Document) aDoc = GetDocument(theDocumentId);
    TDF_Label aLabel  = aDoc->Main().FindChild(theStudyId);
    return Huygens_Study::IsStudy(aLabel);
}

// ============================================================================
/*!
 *  \brief LoadDocument()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::LoadDocument(const Standard_Integer theDocumentId,
                                              const TCollection_AsciiString &theFileName)
{
    // unbind existing document
    if(myDocuments.IsBound(theDocumentId))
        myDocuments.UnBind(theDocumentId);
    // load document
    Handle(TDocStd_Document) aDoc;
    if(myApplication->Open(theFileName, aDoc) != PCDM_RS_OK)
        return Standard_False;
    // bind in engine
    myDocuments.Bind(theDocumentId, aDoc);
    TDataStd_Integer::Set(aDoc->Main(), theDocumentId);
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief NewMaterial()
 *  Add a new cable material in document.
*/
// ============================================================================
Handle(Huygens_DataObject) Huygens_Engine::NewMaterial(const Standard_Integer theDocumentId,
                                                       const Huygens::ObjectType theType)
{
    Handle(TDocStd_Document) aDoc = GetDocument(theDocumentId);
    TDF_Label aLabel
            = TDF_TagSource::NewChild(aDoc->Main().FindChild(TAG_Materials));
    Handle(Huygens_DataObject) anObject
            = new Huygens_DataObject(aLabel, theType);
    return anObject;
}

// ============================================================================
/*!
 *  \brief NbStudies()
*/
// ============================================================================
Standard_Integer Huygens_Engine::NbStudies(const Standard_Integer theDocumentId)
{
    if(!myDocuments.IsBound(theDocumentId))
        return 0;
    // loop over document main label, check for valid studies
    Standard_Integer N = 0;
    Handle(TDocStd_Document) aDocument = GetDocument(theDocumentId);
    TDF_ChildIterator anIterator(aDocument->Main());
    for(; anIterator.More(); anIterator.Next()) {
        if(Huygens_Study::IsStudy(anIterator.Value()))
            N += 1;
    }
    return N;
}

// ============================================================================
/*!
 *  \brief NewStudy()
*/
// ============================================================================
Handle(Huygens_Study) Huygens_Engine::NewStudy(const Standard_Integer theDocumentId)
{
    // retrieve a document
    Handle(TDocStd_Document) aDocument = GetDocument(theDocumentId);
    // initialize a new label for the study
    TDF_Label aLabel = aDocument->Main().NewChild();
    // initialize a new study
    Handle(Huygens_Study) aStudy = new Huygens_Study(aLabel, Huygens::Study);
    return aStudy;
}

// ============================================================================
/*!
 *  \brief RemoveStudy()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::RemoveStudy(Handle(Huygens_Study) theStudy)
{
    TDF_Label aLabel = theStudy->GetLabel();
    // clear Properties on label and childs
    aLabel.ForgetAllAttributes(Standard_True);
    theStudy.Nullify();
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief RemoveStudy()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::RemoveStudy(const Standard_Integer theDocumentId,
                                             const Standard_Integer theStudyId)
{
    // check if valid document
    if(!myDocuments.IsBound(theDocumentId))
        return Standard_False;
    Handle(Huygens_Study) aStudy = GetStudy(theDocumentId, theStudyId);
    return RemoveStudy(aStudy);
}

// ============================================================================
/*!
 *  \brief SaveDocument()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::SaveDocument(const Standard_Integer theDocumentId,
                                              const TCollection_AsciiString &theFileName)
{
    // check if existing document
    if(!myDocuments.IsBound(theDocumentId))
        return Standard_False;
    Handle(TDocStd_Document) aDoc =
            Handle(TDocStd_Document)::DownCast(myDocuments(theDocumentId));
    if(myApplication->SaveAs(aDoc, theFileName) != PCDM_SS_OK)
        return Standard_False;
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief SaveDocumentAsXML()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::SaveDocumentAsXML(const Standard_Integer theDocumentId,
                                                   const TCollection_AsciiString &theFileName)
{
    // check if document exists
    if(!myDocuments.IsBound(theDocumentId))
        return Standard_False;
    // retrive document
    Handle(TDocStd_Document) aDoc =
            Handle(TDocStd_Document)::DownCast(myDocuments(theDocumentId));
    // create new xml document
    Handle(TDocStd_Document) xmlDoc;
    myApplication->NewDocument("Huygens_XmlDocumentFormat", xmlDoc);
    // copy content
    TDocStd_XLinkTool aTool;
    aTool.Copy(xmlDoc->Main(), aDoc->Main());
    // save xml to disk
    if(myApplication->SaveAs(xmlDoc, theFileName) != PCDM_SS_OK)
        return Standard_False;
    return Standard_True;
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_Engine, Standard_Transient);
IMPLEMENT_STANDARD_RTTIEXT(Huygens_Engine, Standard_Transient);
