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

#ifndef __Huygens_IDocumentProperty_hxx__
#define __Huygens_IDocumentProperty_hxx__

// Huygens
#include <Huygens_DataObject.hxx>

// Attributes
#define ATTR_AuthorFirstName    1
#define ATTR_AuthorLastName     2
#define ATTR_AuthorEmail        3
#define ATTR_StudyName          4
#define ATTR_StudyDescription   5


// ============================================================================
/*!
 *  \brief Huygens_IDocumentProperty
 *  Class implementation of an interface for document properties.
*/
// ============================================================================
class Huygens_IDocumentProperty
{

public:
    // constructors
    Huygens_IDocumentProperty(Handle(Huygens_DataObject) theObject)
        : myObject(theObject) {}
    // destructors
    ~Huygens_IDocumentProperty() {}

public:

    TCollection_AsciiString     GetAuthorEmail() {return myObject->GetStringAttribute(ATTR_AuthorEmail);}
    TCollection_AsciiString     GetAuthorFirstName() {return myObject->GetStringAttribute(ATTR_AuthorFirstName);}
    TCollection_AsciiString     GetAuthorLastName() {return myObject->GetStringAttribute(ATTR_AuthorLastName);}
    TCollection_AsciiString     GetStudyDescription() {return myObject->GetStringAttribute(ATTR_StudyDescription);}
    TCollection_AsciiString     GetStudyName() {return myObject->GetStringAttribute(ATTR_StudyDescription);}

    void    SetAuthorEmail(const TCollection_AsciiString& theEmail) {myObject->SetStringAttribute(ATTR_AuthorEmail, theEmail);}
    void    SetAuthorFirstName(const TCollection_AsciiString& theName) {myObject->SetStringAttribute(ATTR_AuthorFirstName, theName);}
    void    SetAuthorLastName(const TCollection_AsciiString& theName) {myObject->SetStringAttribute(ATTR_AuthorLastName, theName);}
    void    SetStudyDescription(const TCollection_AsciiString& theDescription) {myObject->SetStringAttribute(ATTR_StudyDescription, theDescription);}
    void    SetStudyName(const TCollection_AsciiString& theName) {myObject->SetStringAttribute(ATTR_StudyName, theName);}

private:

    Handle(Huygens_DataObject)      myObject;

};

#endif  // __Huygens_IDocumentProperty_hxx__
