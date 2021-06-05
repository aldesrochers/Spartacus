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


#ifndef __Huygens_IStudyOperations_hxx__
#define __Huygens_IStudyOperations_hxx__

// Huygens
#include <Huygens_IOperations.hxx>

// Forward declarations
class Huygens_Engine;


// ============================================================================
/*!
    \brief Huygens_IStudyOperations
*/
// ============================================================================
class Huygens_IStudyOperations : public Huygens_IOperations
{

public:
    // constructors
    Huygens_IStudyOperations(Huygens_Engine* theEngine,
                             const Standard_Integer theDocumentId,
                             const Standard_Integer theStudyId);
    // destructors
    ~Huygens_IStudyOperations();

public:

    void        SetAuthorName(const TCollection_AsciiString& theFirstName,
                              const TCollection_AsciiString& theLastName);

};

#endif  // __Huygens_IStudyOperations_hxx__
