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
#include <Huygens_Study.hxx>

// OpenCascade
#include <TDataStd_UAttribute.hxx>


// ============================================================================
/*!
 *  \brief Constructor
 *  Basic constructors for existing studies.
*/
// ============================================================================
Huygens_Study::Huygens_Study(const TDF_Label& theLabel)
    : Huygens_Object(theLabel)
{
    // set guid
    TDataStd_UAttribute::Set(theLabel, GetID());
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Huygens_Study::Huygens_Study(const TDF_Label& theLabel,
                             const Huygens::ObjectType theType)
    : Huygens_Object(theLabel, theType)
{
    // set guid
    TDataStd_UAttribute::Set(theLabel, GetID());
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Huygens_Study::~Huygens_Study()
{

}

// ============================================================================
/*!
 *  \brief GetID()
*/
// ============================================================================
Standard_GUID& Huygens_Study::GetID()
{
    static Standard_GUID aGUID("EF8C3F44-8BFB-4332-ADD5-4D58D8C551CD");
    return aGUID;
}

// ============================================================================
/*!
 *  \brief GetStudy()
*/
// ============================================================================
Handle(Huygens_Study) Huygens_Study::GetStudy(const TDF_Label& theLabel)
{
    Handle(Huygens_Study) aStudy;
    if(!theLabel.IsAttribute(GetID()))
        return aStudy;
    aStudy = new Huygens_Study(theLabel);
    return aStudy;
}

// ============================================================================
/*!
 *  \brief IsStudy()
*/
// ============================================================================
Standard_Boolean Huygens_Study::IsStudy(const TDF_Label &theLabel)
{
    return theLabel.IsAttribute(GetID());
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Huygens_Study, Huygens_Object);
IMPLEMENT_STANDARD_RTTIEXT(Huygens_Study, Huygens_Object);
