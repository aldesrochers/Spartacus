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
#include <MeshDS_Point1d.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
MeshDS_Point1d::MeshDS_Point1d()
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
MeshDS_Point1d::MeshDS_Point1d(const gp_Pnt1d& thePoint1d)
    : myPoint1d(thePoint1d)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
MeshDS_Point1d::~MeshDS_Point1d()
{

}

// ============================================================================
/*!
 *  \brief IsPoint1d()
*/
// ============================================================================
Standard_Boolean MeshDS_Point1d::IsPoint1d() const
{
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief Point1d()
*/
// ============================================================================
const gp_Pnt1d& MeshDS_Point1d::Point1d() const
{
    return myPoint1d;
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshDS_Point1d, MeshDS_Point)
IMPLEMENT_STANDARD_RTTIEXT(MeshDS_Point1d, MeshDS_Point)
