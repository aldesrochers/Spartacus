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
#include <MeshGen_Context.hxx>


// ============================================================================
/*!
 *  \brief Constructor()
*/
// ============================================================================
MeshGen_Context::MeshGen_Context()
{

}

// ============================================================================
/*!
 *  \brief Constructor()
*/
// ============================================================================
MeshGen_Context::MeshGen_Context(const TopoDS_Shape& theShape)
    : myShape(theShape)
{

}

// ============================================================================
/*!
 *  \brief Destructor()
*/
// ============================================================================
MeshGen_Context::~MeshGen_Context()
{

}

// ============================================================================
/*!
 *  \brief SetShape()
*/
// ============================================================================
void MeshGen_Context::SetShape(const TopoDS_Shape& theShape)
{
    myShape = theShape;
}

// ============================================================================
/*!
 *  \brief Shape()
*/
// ============================================================================
const TopoDS_Shape& MeshGen_Context::Shape() const  
{
    return myShape;
}

// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshGen_Context, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(MeshGen_Context, Standard_Transient)