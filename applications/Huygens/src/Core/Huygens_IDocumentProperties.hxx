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

#ifndef __Huygens_IDocumentProperties_hxx__
#define __Huygens_IDocumentProperties_hxx__

// Huygens
#include <Huygens_DataObject.hxx>

// Properties
#define ATTR_AuthorFirstName        1
#define ATTR_AuthorLastName         2
#define ATTR_CreationDate           3
#define ATTR_ModificationDate       4
#define ATTR_ProjectDescription     5
#define ATTR_ProjectName            6


// ============================================================================
/*!
 *  \brief Huygens_IDocumentProperties
 *  Class implementation of an interface for the definition of document
 *  properties.
*/
// ============================================================================
class Huygens_IDocumentProperties
{

public:
    // constructors
    Huygens_IDocumentProperties(Handle(Huygens_DataObject) theObject)
        : myObject(theObject) {}

public:

    TCollection_AsciiString     GetAuthorFirstName() {return myObject->GetStringAttribute(ATTR_AuthorFirstName);}
    TCollection_AsciiString     GetAuthorLastName() {return myObject->GetStringAttribute(ATTR_AuthorLastName);}
    TCollection_AsciiString     GetCreationDate() {return myObject->GetStringAttribute(ATTR_CreationDate);}
    TCollection_AsciiString     GetModificationDate() {return myObject->GetStringAttribute(ATTR_ModificationDate);}
    TCollection_AsciiString     GetProjectDescription() {return myObject->GetStringAttribute(ATTR_ProjectDescription);}
    TCollection_AsciiString     GetProjectName() {return myObject->GetStringAttribute(ATTR_ProjectName);}

    void    SetAuthorFirstName(const TCollection_AsciiString& theFirstName) {myObject->SetStringAttribute(ATTR_AuthorFirstName, theFirstName);}
    void    SetAuthorLastName(const TCollection_AsciiString& theLastName) {myObject->SetStringAttribute(ATTR_AuthorLastName, theLastName);}
    void    SetCreationDate(const TCollection_AsciiString& theDate) {myObject->SetStringAttribute(ATTR_CreationDate, theDate);}
    void    SetModificationDate(const TCollection_AsciiString& theDate) {myObject->SetStringAttribute(ATTR_ModificationDate, theDate);}
    void    SetProjectDescription(const TCollection_AsciiString& theDescription) {myObject->SetStringAttribute(ATTR_ProjectDescription, theDescription);}
    void    SetProjectName(const TCollection_AsciiString& theName) {myObject->SetStringAttribute(ATTR_ProjectName, theName);}

private:

    Handle(Huygens_DataObject)  myObject;

};

#endif  // __Huygens_IDocumentProperties_hxx__
