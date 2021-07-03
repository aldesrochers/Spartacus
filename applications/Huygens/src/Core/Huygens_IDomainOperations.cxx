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
#include <Huygens_IDocumentProperties.hxx>
#include <Huygens_Engine.hxx>
#include <Huygens_IDomainOperations.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Huygens_IDomainOperations::Huygens_IDomainOperations(Handle(Huygens_Engine) theEngine,
                                                     const Standard_Integer theDocumentId)
    : Huygens_IOperations(theEngine, theDocumentId)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Huygens_IDomainOperations::~Huygens_IDomainOperations()
{

}

// ============================================================================
/*!
 *  \brief GetAuthorFirstName()
*/
// ============================================================================
TCollection_AsciiString Huygens_IDomainOperations::GetAuthorFirstName()
{
    Huygens_IDocumentProperties i(GetDocumentProperties());
    return i.GetAuthorFirstName();
}

// ============================================================================
/*!
 *  \brief GetAuthorLastName()
*/
// ============================================================================
TCollection_AsciiString Huygens_IDomainOperations::GetAuthorLastName()
{
    Huygens_IDocumentProperties i(GetDocumentProperties());
    return i.GetAuthorLastName();
}

// ============================================================================
/*!
 *  \brief GetProjectDescription()
*/
// ============================================================================
TCollection_AsciiString Huygens_IDomainOperations::GetProjectDescription()
{
    Huygens_IDocumentProperties i(GetDocumentProperties());
    return i.GetProjectDescription();
}

// ============================================================================
/*!
 *  \brief GetProjectName()
*/
// ============================================================================
TCollection_AsciiString Huygens_IDomainOperations::GetProjectName()
{
    Huygens_IDocumentProperties i(GetDocumentProperties());
    return i.GetProjectName();
}

// ============================================================================
/*!
 *  \brief SetAuthorFirstName()
*/
// ============================================================================
void Huygens_IDomainOperations::SetAuthorFirstName(const TCollection_AsciiString &theFirstName)
{
    Huygens_IDocumentProperties i(GetDocumentProperties());
    i.SetAuthorFirstName(theFirstName);
}

// ============================================================================
/*!
 *  \brief SetAuthorName()
*/
// ============================================================================
void Huygens_IDomainOperations::SetAuthorLastName(const TCollection_AsciiString &theLastName)
{
    Huygens_IDocumentProperties i(GetDocumentProperties());
    i.SetAuthorLastName(theLastName);
}

// ============================================================================
/*!
 *  \brief SetAuthorName()
*/
// ============================================================================
void Huygens_IDomainOperations::SetAuthorName(const TCollection_AsciiString &theFirstName,
                                                const TCollection_AsciiString &theLastName)
{
    Huygens_IDocumentProperties i(GetDocumentProperties());
    i.SetAuthorFirstName(theFirstName);
    i.SetAuthorLastName(theLastName);
}

// ============================================================================
/*!
 *  \brief SetProjectDescription()
*/
// ============================================================================
void Huygens_IDomainOperations::SetProjectDescription(const TCollection_AsciiString &theDescription)
{
    Huygens_IDocumentProperties i(GetDocumentProperties());
    i.SetProjectDescription(theDescription);
}

// ============================================================================
/*!
 *  \brief SetProjectName()
*/
// ============================================================================
void Huygens_IDomainOperations::SetProjectName(const TCollection_AsciiString &theName)
{
    Huygens_IDocumentProperties i(GetDocumentProperties());
    i.SetProjectName(theName);
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_IDomainOperations, Huygens_IOperations);
IMPLEMENT_STANDARD_RTTIEXT(Huygens_IDomainOperations, Huygens_IOperations);
