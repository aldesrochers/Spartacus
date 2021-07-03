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

#ifndef __Huygens_IDomainOperations_hxx__
#define __Huygens_IDomainOperations_hxx__

// Huygens
#include <Huygens_IOperations.hxx>

// Forward declarations
class Huygens_IDomainOperations;
class Huygens_Engine;

// Handles
DEFINE_STANDARD_HANDLE(Huygens_IDomainOperations, Huygens_IOperations);


// ============================================================================
/*!
 *  \brief Huygens_IDomainOperations
 *  Class implementation of operations on document properties.
*/
// ============================================================================
class Huygens_IDomainOperations : public Huygens_IOperations
{

public:
    // constructors
    Huygens_IDomainOperations(Handle(Huygens_Engine) theEngine,
                              const Standard_Integer theDocumentId);
    // destructors
    ~Huygens_IDomainOperations();

public:

    TCollection_AsciiString     GetAuthorFirstName();
    TCollection_AsciiString     GetAuthorLastName();
    TCollection_AsciiString     GetProjectDescription();
    TCollection_AsciiString     GetProjectName();

    void            SetAuthorFirstName(const TCollection_AsciiString& theFirstName);
    void            SetAuthorName(const TCollection_AsciiString& theFirstName,
                                  const TCollection_AsciiString& theLastName);
    void            SetAuthorLastName(const TCollection_AsciiString& theLastName);
    void            SetProjectDescription(const TCollection_AsciiString& theDescription);
    void            SetProjectName(const TCollection_AsciiString& theName);

public:

    DEFINE_STANDARD_RTTIEXT(Huygens_IDomainOperations, Huygens_IOperations);

};

#endif  // __Huygens_IDomainOperations_hxx__
