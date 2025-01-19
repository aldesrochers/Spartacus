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
#include <MeshAdaptor_Point.hxx>
#include <MeshDS_Point1d.hxx>
#include <MeshDS_Point2d.hxx>
#include <MeshDS_Point3d.hxx>
#include <MeshDS_Tool.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
MeshAdaptor_Point::MeshAdaptor_Point()
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
MeshAdaptor_Point::MeshAdaptor_Point(const MeshDS_Vertex& theVertex)
{
    Initialize(theVertex);
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
MeshAdaptor_Point::~MeshAdaptor_Point()
{

}

// ============================================================================
/*!
 *  \brief Initialize()
*/
// ============================================================================
void MeshAdaptor_Point::Initialize(const MeshDS_Vertex &theVertex)
{
    myVertex = theVertex;
}

// ============================================================================
/*!
 *  \brief IsPoint1d()
*/
// ============================================================================
Standard_Boolean MeshAdaptor_Point::IsPoint1d() const
{
    Handle(MeshDS_Point) aPoint = MeshDS_Tool::Point(myVertex);
    return aPoint->IsPoint1d();
}

// ============================================================================
/*!
 *  \brief IsPoint2d()
*/
// ============================================================================
Standard_Boolean MeshAdaptor_Point::IsPoint2d() const
{
    Handle(MeshDS_Point) aPoint = MeshDS_Tool::Point(myVertex);
    return aPoint->IsPoint2d();
}

// ============================================================================
/*!
 *  \brief IsPoint3d()
*/
// ============================================================================
Standard_Boolean MeshAdaptor_Point::IsPoint3d() const
{
    Handle(MeshDS_Point) aPoint = MeshDS_Tool::Point(myVertex);
    return aPoint->IsPoint3d();
}

// ============================================================================
/*!
 *  \brief Point1d()
*/
// ============================================================================
const gp_Pnt1d& MeshAdaptor_Point::Point1d() const
{
    Handle(MeshDS_Point) aPoint = MeshDS_Tool::Point(myVertex);
    if(aPoint->IsPoint1d()) {
        const Handle(MeshDS_Point1d)& aPoint1d  = Handle(MeshDS_Point1d)::DownCast(aPoint);
        return aPoint1d->Point1d();
    }
    throw Standard_DomainError("MeshAdaptor_Point::Point1d()");
}

// ============================================================================
/*!
 *  \brief Point2d()
*/
// ============================================================================
const gp_Pnt2d& MeshAdaptor_Point::Point2d() const
{
    Handle(MeshDS_Point) aPoint = MeshDS_Tool::Point(myVertex);
    if(aPoint->IsPoint2d()) {
        const Handle(MeshDS_Point2d)& aPoint2d  = Handle(MeshDS_Point2d)::DownCast(aPoint);
        return aPoint2d->Point2d();
    }
    throw Standard_DomainError("MeshAdaptor_Point::Point2d()");
}

// ============================================================================
/*!
 *  \brief Point3d()
*/
// ============================================================================
const gp_Pnt& MeshAdaptor_Point::Point3d() const
{
    Handle(MeshDS_Point) aPoint = MeshDS_Tool::Point(myVertex);
    if(aPoint->IsPoint3d()) {
        const Handle(MeshDS_Point3d)& aPoint3d  = Handle(MeshDS_Point3d)::DownCast(aPoint);
        return aPoint3d->Point3d();
    }
    throw Standard_DomainError("MeshAdaptor_Point::Point3d()");
}

// ============================================================================
/*!
 *  \brief SetVertex()
*/
// ============================================================================
void MeshAdaptor_Point::SetVertex(const MeshDS_Vertex &theVertex)
{
    myVertex = theVertex;
}

// ============================================================================
/*!
 *  \brief Vertex()
*/
// ============================================================================
const MeshDS_Vertex& MeshAdaptor_Point::Vertex() const
{
    return myVertex;
}
