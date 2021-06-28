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
#include <Huygens_IStudyOperations.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Huygens_IStudyOperations::Huygens_IStudyOperations(Handle(Huygens_Engine) theEngine,
                                                   const Standard_Integer theDocumentId,
                                                   const Standard_Integer theStudyId)
    : Huygens_IOperations(theEngine, theDocumentId),
      myStudyId(theStudyId)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Huygens_IStudyOperations::~Huygens_IStudyOperations()
{

}

// ============================================================================
/*!
 *  \brief GetStudy()
 *  Convenient shortcut to access the study.
*/
// ============================================================================
Handle(Huygens_Study) Huygens_IStudyOperations::GetStudy()
{
    return GetEngine()->GetStudy(GetDocumentId(), GetStudyId());
}

// ============================================================================
/*!
 *  \brief GetStudyId()
*/
// ============================================================================
Standard_Integer Huygens_IStudyOperations::GetStudyId()
{
    return myStudyId;
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_IStudyOperations, Huygens_IOperations);
IMPLEMENT_STANDARD_RTTIEXT(Huygens_IStudyOperations, Huygens_IOperations);
