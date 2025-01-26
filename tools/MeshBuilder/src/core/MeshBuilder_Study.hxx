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

#ifndef __MeshBuilder_Study_hxx__
#define __MeshBuilder_Study_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <TDocStd_Application.hxx>
#include <TDocStd_Document.hxx>

// Handles
DEFINE_STANDARD_HANDLE(MeshBuilder_Study, Standard_Transient)

// ============================================================================
/*!
 *  \brief MeshBuilder_Study
 */
// ============================================================================
class MeshBuilder_Study : public Standard_Transient
{

public:
    // constructors
    MeshBuilder_Study();
    // destructors
    ~MeshBuilder_Study();

private:

    Handle(TDocStd_Application)     myApplication;
    Handle(TDocStd_Document)        myDocument;

public:

    DEFINE_STANDARD_RTTIEXT(MeshBuilder_Study, Standard_Transient)
    
};

#endif  // __MeshBuilder_Study_hxx__
