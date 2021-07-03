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
#include <Huygens_IMaterial.hxx>
#include <Huygens_IMaterialOperations.hxx>



// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Huygens_IMaterialOperations::Huygens_IMaterialOperations(Handle(Huygens_Engine) theEngine,
                                                         const Standard_Integer theDocumentId)
    : Huygens_IOperations(theEngine, theDocumentId)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Huygens_IMaterialOperations::~Huygens_IMaterialOperations()
{

}

// ============================================================================
/*!
 *  \brief AddElasticMaterial()
*/
// ============================================================================
Handle(Huygens_Material) Huygens_IMaterialOperations::AddElasticMaterial()
{
    Handle(Huygens_Material) anObject
            = GetEngine()->NewMaterial(GetDocumentId(), Huygens::ElasticMaterial);
    return anObject;
}

// ============================================================================
/*!
    \brief AddElasticMaterial()
*/
// ============================================================================
Handle(Huygens_Material) Huygens_IMaterialOperations::AddElasticMaterial(const USSMP_Elastic& theStressStrainParameters,
                                                                         const UThMP_Linear& theThermalParameters)
{
    Handle(Huygens_Material) anObject = AddElasticMaterial();
    EditElasticMaterial(anObject, theStressStrainParameters, theThermalParameters);
    return anObject;
}

// ============================================================================
/*!
    \brief EditElasticMaterial()
*/
// ============================================================================
Standard_Boolean Huygens_IMaterialOperations::EditElasticMaterial(Handle(Huygens_Material) &theMaterial,
                                                                  const USSMP_Elastic &theStressStrainParameters)
{
    // check if valid object, valid type
    if(theMaterial.IsNull())
        return Standard_False;
    if(theMaterial->GetType() != Huygens::ElasticMaterial)
        return Standard_False;
    // create interface, set parameters as attributes in document
    Huygens_IMaterial i(theMaterial);
    i.SetE(theStressStrainParameters.E());
    return Standard_True;
}

// ============================================================================
/*!
    \brief EditElasticMaterial()
*/
// ============================================================================
Standard_Boolean Huygens_IMaterialOperations::EditElasticMaterial(Handle(Huygens_Material) &theMaterial,
                                                                  const UThMP_Linear &theThermalParameters)
{
    // check if valid object, valid type
    if(theMaterial.IsNull())
        return Standard_False;
    if(theMaterial->GetType() != Huygens::ElasticMaterial)
        return Standard_False;
    // create interface, set parameters as attributes in document
    Huygens_IMaterial i(theMaterial);
    i.SetAlpha(theThermalParameters.Alpha());
    i.SetT0(theThermalParameters.T0());
    return Standard_True;
}

// ============================================================================
/*!
    \brief EditElasticMaterial()
*/
// ============================================================================
Standard_Boolean Huygens_IMaterialOperations::EditElasticMaterial(Handle(Huygens_Material) &theMaterial,
                                                                  const USSMP_Elastic &theStressStrainParameters,
                                                                  const UThMP_Linear &theThermalParameters)
{
    if(!EditElasticMaterial(theMaterial, theStressStrainParameters))
        return Standard_False;
    if(!EditElasticMaterial(theMaterial, theThermalParameters))
        return Standard_False;
    return Standard_True;
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_IMaterialOperations, Huygens_IOperations);
IMPLEMENT_STANDARD_RTTIEXT(Huygens_IMaterialOperations, Huygens_IOperations);
