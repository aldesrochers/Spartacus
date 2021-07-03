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
#include <Huygens_IOperations.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Huygens_IOperations::Huygens_IOperations(Handle(Huygens_Engine) theEngine,
                                         const Standard_Integer theDocumentId)
    : myDocumentId(theDocumentId),
      myEngine(theEngine)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Huygens_IOperations::~Huygens_IOperations()
{

}

// ============================================================================
/*!
 *  \brief GetApplication()
 *  Convenient shortcut to the application.
*/
// ============================================================================
Handle(TDocStd_Application) Huygens_IOperations::GetApplication()
{
    return GetEngine()->GetApplication();
}

// ============================================================================
/*!
 *  \brief GetDocument()
 *  Convenient shortcut to access document.
*/
// ============================================================================
Handle(TDocStd_Document) Huygens_IOperations::GetDocument()
{
    return GetEngine()->GetDocument(GetDocumentId());
}

// ============================================================================
/*!
 *  \brief GetDocumentId()
*/
// ============================================================================
Standard_Integer Huygens_IOperations::GetDocumentId()
{
    return myDocumentId;
}

// ============================================================================
/*!
 *  \brief GetEngine()
 *  Convenient shortcut to the engine.
*/
// ============================================================================
Handle(Huygens_Engine) Huygens_IOperations::GetEngine()
{
    return myEngine;
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_IOperations, Standard_Transient);
IMPLEMENT_STANDARD_RTTIEXT(Huygens_IOperations, Standard_Transient);
