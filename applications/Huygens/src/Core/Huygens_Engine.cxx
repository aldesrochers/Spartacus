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
//     | ==== Cables
//     | ==== Studies
//     | ==== ...

// Definition of child tags
#define TAG_Properties      1
#define TAG_Materials       2
#define TAG_Cables          3
#define TAG_Studies         4



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
 *  \brief GetApplication()
*/
// ============================================================================
Handle(TDocStd_Application) Huygens_Engine::GetApplication()
{
    return myApplication;
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
 *  Retrieve an instance of the data object containing document properties.
*/
// ============================================================================
Handle(Huygens_DataObject) Huygens_Engine::GetDocumentProperties(const Standard_Integer theDocumentId)
{
    Handle(TDocStd_Document) aDoc = GetDocument(theDocumentId);
    TDF_Label aLabel = aDoc->Main().FindChild(TAG_Properties);

    // find or create the document properties data object
    Handle(Huygens_DataObject) anObject;
    if(Huygens_DataObject::IsDataObject(aLabel))
        anObject = Huygens_DataObject::GetDataObject(aLabel);
    else
        anObject = new Huygens_DataObject(aLabel, Huygens::DO_DocumentProperties);

    return anObject;
}

// ============================================================================
/*!
    \brief GetICableOperations()
*/
// ============================================================================
Handle(Huygens_ICableOperations) Huygens_Engine::GetICableOperations(const Standard_Integer theDocumentId)
{
    Handle(Huygens_ICableOperations) anIOperation;
    if(myICableOperations.IsBound(theDocumentId)) {
        anIOperation = Handle(Huygens_ICableOperations)::DownCast(myICableOperations(theDocumentId));
    } else {
        anIOperation = new Huygens_ICableOperations(this, theDocumentId);
        // bind in engine
        myDocuments.Bind(theDocumentId, anIOperation);
    }
    return anIOperation;
}

// ============================================================================
/*!
 *  \brief GetIGeneralOperations()
*/
// ============================================================================
Handle(Huygens_IGeneralOperations) Huygens_Engine::GetIGeneralOperations(const Standard_Integer theDocumentId)
{
    Handle(Huygens_IGeneralOperations) anIOperation;
    if(myIGeneralOperations.IsBound(theDocumentId)) {
        anIOperation = Handle(Huygens_IGeneralOperations)::DownCast(myIGeneralOperations(theDocumentId));
    } else {
        anIOperation = new Huygens_IGeneralOperations(this, theDocumentId);
        // bind in engine
        myDocuments.Bind(theDocumentId, anIOperation);
    }
    return anIOperation;
}

// ============================================================================
/*!
    \brief GetIMaterialOperations()
*/
// ============================================================================
Handle(Huygens_IMaterialOperations) Huygens_Engine::GetIMaterialOperations(const Standard_Integer theDocumentId)
{
    Handle(Huygens_IMaterialOperations) anIOperation;
    if(myIMaterialOperations.IsBound(theDocumentId)) {
        anIOperation = Handle(Huygens_IMaterialOperations)::DownCast(myIMaterialOperations(theDocumentId));
    } else {
        anIOperation = new Huygens_IMaterialOperations(this, theDocumentId);
        // bind in engine
        myDocuments.Bind(theDocumentId, anIOperation);
    }
    return anIOperation;
}

// ============================================================================
/*!
 *  \brief IsDocument()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::IsDocument(const Standard_Integer theDocumentId)
{
    if(myDocuments.IsEmpty())
        return Standard_False;
    return myDocuments.IsBound(theDocumentId);
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
 *  \brief NewDocument()
*/
// ============================================================================
Standard_Boolean Huygens_Engine::NewDocument(const Standard_Integer theDocumentId)
{
    Handle(TDocStd_Document) aDoc = GetDocument(theDocumentId, Standard_True);
    if(!aDoc.IsNull())
        return Standard_True;
    return Standard_False;
}

// ============================================================================
/*!
    \brief NewMaterial()
*/
// ============================================================================
Handle(Huygens_Material) Huygens_Engine::NewMaterial(const Standard_Integer theDocumentId,
                                                     const Huygens::Material theType)
{
    // find a label for the new material
    TDF_Label aRootLabel
            = GetDocument(theDocumentId)->Main().FindChild(TAG_Materials);
    TDF_Label aLabel = TDF_TagSource::NewChild(aRootLabel);
    // initialize a new material object
    Handle(Huygens_Material) anObject = new Huygens_Material(aLabel, theType);
    return anObject;
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
