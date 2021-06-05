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


#ifndef __Huygens_IStudyAttributes_hxx__
#define __Huygens_IStudyAttributes_hxx__

// Huygens
#include <Huygens_DataObject.hxx>

// Attributes
#define TAG_AuthorFirstName 1
#define TAG_AuthorLastName  2


// ============================================================================
/*!
    \brief Huygens_IStudyAttributes
*/
// ============================================================================
class Huygens_IStudyAttributes
{

public:
    // constructors
    Huygens_IStudyAttributes(Handle(Huygens_DataObject) theObject) :
        myObject(theObject) {}
    // destructors
    ~Huygens_IStudyAttributes() {}

public:

    TCollection_AsciiString     GetAuthorFirstName() {return myObject->GetStringAttribute(TAG_AuthorFirstName);}
    TCollection_AsciiString     GetAuthorLastName() {return myObject->GetStringAttribute(TAG_AuthorLastName);}

    void    SetAuthorFirstName(const TCollection_AsciiString& theFirstName) {myObject->SetStringAttribute(TAG_AuthorFirstName, theFirstName);}
    void    SetAuthorLastName(const TCollection_AsciiString& theLastName) {myObject->SetStringAttribute(TAG_AuthorLastName, theLastName);}

private:

    Handle(Huygens_DataObject)  myObject;

};

#endif  // __Huygens_IStudyAttributes_hxx__
