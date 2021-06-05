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
    \brief Constructor
*/
// ============================================================================
Huygens_IOperations::Huygens_IOperations(Huygens_Engine* theEngine,
                                         const Standard_Integer theDocumentId,
                                         const Standard_Integer theStudyId)
    : myDocumentId(theDocumentId),
      myEngine(theEngine),
      myStudyId(theStudyId)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Huygens_IOperations::~Huygens_IOperations()
{

}

// ============================================================================
/*!
    \brief GetDocument()
*/
// ============================================================================
Handle(TDocStd_Document) Huygens_IOperations::GetDocument()
{
    return GetEngine()->GetDocument(GetDocumentId());
}

// ============================================================================
/*!
    \brief GetDocumentId()
*/
// ============================================================================
Standard_Integer Huygens_IOperations::GetDocumentId()
{
    return myDocumentId;
}

// ============================================================================
/*!
    \brief GetEngine()
*/
// ============================================================================
Huygens_Engine* Huygens_IOperations::GetEngine()
{
    return myEngine;
}

// ============================================================================
/*!
    \brief GetLastError()
*/
// ============================================================================
TCollection_AsciiString Huygens_IOperations::GetLastError()
{
    return myLastError;
}

// ============================================================================
/*!
    \brief GetStudy()
    Convenient shortcut.
*/
// ============================================================================
Handle(Huygens_StudyObject) Huygens_IOperations::GetStudy()
{
    return GetEngine()->GetStudy(GetDocumentId(), GetStudyId());
}

// ============================================================================
/*!
    \brief GetStudyId()
*/
// ============================================================================
Standard_Integer Huygens_IOperations::GetStudyId()
{
    return myStudyId;
}

// ============================================================================
/*!
    \brief SetLastError()
*/
// ============================================================================
void Huygens_IOperations::SetLastError(const TCollection_AsciiString &theErrorString)
{
    myLastError = theErrorString;
}
