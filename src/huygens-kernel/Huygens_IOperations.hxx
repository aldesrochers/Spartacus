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
#include <Standard_Integer.hxx>
#include <TCollection_AsciiString.hxx>
#include <TDocStd_Document.hxx>

// Huygens
#include <Huygens_StudyObject.hxx>

// Forward declarations
class Huygens_Engine;


// ============================================================================
/*!
    \brief Huygens_IOperations
*/
// ============================================================================
class Huygens_IOperations
{

public:
    // constructors
    Huygens_IOperations(Huygens_Engine* theEngine,
                        const Standard_Integer theDocumentId,
                        const Standard_Integer theStudyId);
    // destructors
    ~Huygens_IOperations();

public:

    Handle(TDocStd_Document)    GetDocument();
    Standard_Integer            GetDocumentId();
    Huygens_Engine*             GetEngine();
    TCollection_AsciiString     GetLastError();
    Handle(Huygens_StudyObject) GetStudy();
    Standard_Integer            GetStudyId();
    void                        SetLastError(const TCollection_AsciiString& theErrorString);

private:

    Standard_Integer            myDocumentId;
    Huygens_Engine*             myEngine;
    TCollection_AsciiString     myLastError;
    Standard_Integer            myStudyId;


};

#endif  // __Huygens_IOperations_hxx__
