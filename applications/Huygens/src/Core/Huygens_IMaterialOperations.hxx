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

#ifndef __Huygens_IMaterialOperations_hxx__
#define __Huygens_IMaterialOperations_hxx__

// Huygens
#include <Huygens_IOperations.hxx>
#include <Huygens_Material.hxx>

// Spartacus
#include <USSMP_Elastic.hxx>
#include <UThMP_Linear.hxx>


// Forward declarations
class Huygens_IMaterialOperations;
class Huygens_Engine;

// Handles
DEFINE_STANDARD_HANDLE(Huygens_IMaterialOperations, Huygens_IOperations);


// ============================================================================
/*!
 *  \brief Huygens_IMaterialOperations
*/
// ============================================================================
class Huygens_IMaterialOperations : public Huygens_IOperations
{

public:
    // constructors
    Huygens_IMaterialOperations(Handle(Huygens_Engine) theEngine,
                                const Standard_Integer theDocumentId);
    // destructors
    ~Huygens_IMaterialOperations();

public:

    Handle(Huygens_Material)    AddElasticMaterial();
    Handle(Huygens_Material)    AddElasticMaterial(const USSMP_Elastic& theStressStrainParameters,
                                                   const UThMP_Linear& theThermalParameters);
    Standard_Boolean            EditElasticMaterial(Handle(Huygens_Material)& theMaterial,
                                                    const USSMP_Elastic& theStressStrainParameters);
    Standard_Boolean            EditElasticMaterial(Handle(Huygens_Material)& theMaterial,
                                                    const UThMP_Linear& theThermalParameters);
    Standard_Boolean            EditElasticMaterial(Handle(Huygens_Material)& theMaterial,
                                                    const USSMP_Elastic& theStressStrainParameters,
                                                    const UThMP_Linear& theThermalParameters);

public:

    DEFINE_STANDARD_RTTIEXT(Huygens_IMaterialOperations, Huygens_IOperations);

};

#endif  // __Huygens_IMaterialOperations_hxx__
