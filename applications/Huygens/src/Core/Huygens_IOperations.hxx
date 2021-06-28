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

#ifndef __Huygens_IOperations_hxx__
#define __Huygens_IOperations_hxx__

// OpenCascade
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <TDocStd_Application.hxx>
#include <TDocStd_Document.hxx>

// Huygens
#include <Huygens_DataObject.hxx>

// Forward declarations
class Huygens_IOperations;
class Huygens_Engine;

// Handles
DEFINE_STANDARD_HANDLE(Huygens_IOperations, Standard_Transient);


// ============================================================================
/*!
 *  \brief Huygens_IOperations
 *  Class implementation of a basic operations interface.
*/
// ============================================================================
class Huygens_IOperations : public Standard_Transient
{

public:
    // constructors
    Huygens_IOperations(Handle(Huygens_Engine) theEngine,
                        const Standard_Integer theDocumentId);
    // destructors
    ~Huygens_IOperations();

public:

    Handle(TDocStd_Application) GetApplication();
    Handle(TDocStd_Document)    GetDocument();
    Standard_Integer            GetDocumentId();
    Handle(Huygens_DataObject)  GetDocumentProperties();
    Handle(Huygens_Engine)      GetEngine();

private:

    Standard_Integer            myDocumentId;
    Handle(Huygens_Engine)      myEngine;

public:

    DEFINE_STANDARD_RTTIEXT(Huygens_IOperations, Standard_Transient);

};

#endif  // __Huygens_IOperations_hxx__
