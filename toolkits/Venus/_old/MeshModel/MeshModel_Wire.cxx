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
#include <MeshModel_Wire.hxx>

// OpenCASCADE
#include <TopoDS.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshModel_Wire::MeshModel_Wire(const TopoDS_Wire& theWire)
    : MeshModel_Shape(theWire)    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MeshModel_Wire::~MeshModel_Wire()    
{
    
}

// ============================================================================
/*!
    \brief Wire()
*/
// ============================================================================
const TopoDS_Wire& MeshModel_Wire::Wire() const
{
    return TopoDS::Wire(Shape());
}



// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshModel_Wire, MeshModel_Shape)
IMPLEMENT_STANDARD_RTTIEXT(MeshModel_Wire, MeshModel_Shape)