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


#ifndef __MeshDS_Point_hxx__
#define __MeshDS_Point_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>

// Spartacus
#include <gp_Pnt1d.hxx>

// Forward declarations
class MeshDS_Point;

// Handles
DEFINE_STANDARD_HANDLE(MeshDS_Point, Standard_Transient)


// ============================================================================
/*!
 *  \brief MeshDS_Point
*/
// ============================================================================
class MeshDS_Point : public Standard_Transient
{

public:
    // constructors
    Standard_EXPORT MeshDS_Point();
    // destructors
    Standard_EXPORT ~MeshDS_Point();

public:

    virtual Standard_EXPORT Standard_Boolean    IsPoint1d() const;
    virtual Standard_EXPORT Standard_Boolean    IsPoint2d() const;
    virtual Standard_EXPORT Standard_Boolean    IsPoint3d() const;
    virtual Standard_EXPORT const gp_Pnt1d&     Point1d() const;
    virtual Standard_EXPORT const gp_Pnt2d&     Point2d() const;
    virtual Standard_EXPORT const gp_Pnt&       Point3d() const;

public:

    DEFINE_STANDARD_RTTIEXT(MeshDS_Point, Standard_Transient)

};


#endif // __MeshDS_Point_hxx__
