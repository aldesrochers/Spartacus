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
#include <Huygens_ICableAttributes.hxx>
#include <Huygens_ICableOperations.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Huygens_ICableOperations::Huygens_ICableOperations(Huygens_Engine* theEngine,
                                                   const Standard_Integer theDocumentId,
                                                   const Standard_Integer theStudyId)
    : Huygens_IOperations(theEngine, theDocumentId, theStudyId)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Huygens_ICableOperations::~Huygens_ICableOperations()
{

}

// ============================================================================
/*!
    \brief AddElasticCable()
*/
// ============================================================================
void Huygens_ICableOperations::AddElasticCable(const TCollection_AsciiString &theDesignation,
                                               const Standard_Real theElasticModulous,
                                               const Standard_Real theThermalExpansionCoefficient)
{
    Handle(Huygens_DataObject) anObject = GetStudy()->AddCable();
    Huygens_ICableAttributes attrs(anObject);
    attrs.SetDesignation(theDesignation);
    attrs.SetElasticModulous(theElasticModulous);
    attrs.SetThermalExpansionCoefficient(theThermalExpansionCoefficient);
}
