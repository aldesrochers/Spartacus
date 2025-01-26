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


// Spartacus
#include <MeshBuilder_Study.hxx>

// OpenCASCADE
#include <BinDrivers_DocumentRetrievalDriver.hxx>
#include <BinDrivers_DocumentStorageDriver.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshBuilder_Study::MeshBuilder_Study()
{

    // define application format
    myApplication = new TDocStd_Application();
    myApplication->DefineFormat("MeshBuilder", 
                                "A standard data format for MeshBuilder", 
                                ".mbs", 
                                new BinDrivers_DocumentRetrievalDriver(),
                                new BinDrivers_DocumentStorageDriver());

    // initialize study document
    myApplication->NewDocument("MeshBuilder", myDocument);
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MeshBuilder_Study::~MeshBuilder_Study()
{
    
}

// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshBuilder_Study, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(MeshBuilder_Study, Standard_Transient)