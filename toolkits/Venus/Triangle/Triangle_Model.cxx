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
#include <Triangle_Model.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Triangle_Model::Triangle_Model()    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Triangle_Model::~Triangle_Model()    
{
    
}

// ============================================================================
/*!
    \brief Edge()
*/
// ============================================================================
void Triangle_Model::Edge(const Standard_Integer theIndex,
                          Standard_Integer& thePoint1,
                          Standard_Integer& thePoint2) const
{
    thePoint1 = myEdges(theIndex, 1);
    thePoint2 = myEdges(theIndex, 2);
}

// ============================================================================
/*!
    \brief EdgeMarker()
*/
// ============================================================================
void Triangle_Model::EdgeMarker(const Standard_Integer theIndex,
                                Standard_Integer& theMarker) const
{
    theMarker = myEdgeMarkers(theIndex);
}

// ============================================================================
/*!
    \brief Hole()
*/
// ============================================================================
void Triangle_Model::Hole(const Standard_Integer theIndex,
                          Standard_Real& theX,
                          Standard_Real& theY) const
{
    theX = myHoles(theIndex, 1);
    theY = myHoles(theIndex, 2);
}

// ============================================================================
/*!
    \brief NbEdges()
*/
// ============================================================================
Standard_Integer Triangle_Model::NbEdges() const
{
    return myEdges.NbRows();
}

// ============================================================================
/*!
    \brief NbHoles()
*/
// ============================================================================
Standard_Integer Triangle_Model::NbHoles() const
{
    return myHoles.NbRows();
}

// ============================================================================
/*!
    \brief NbNormals()
*/
// ============================================================================
Standard_Integer Triangle_Model::NbNormals() const
{
    return myNormals.NbRows();
}

// ============================================================================
/*!
    \brief NbPointAttributes()
*/
// ============================================================================
Standard_Integer Triangle_Model::NbPointAttributes() const
{
    return myPointAttributes.NbRows();
}

// ============================================================================
/*!
    \brief NbPoints()
*/
// ============================================================================
Standard_Integer Triangle_Model::NbPoints() const 
{
    return myPoints.NbRows();
}

// ============================================================================
/*!
    \brief NbRegions()
*/
// ============================================================================
Standard_Integer Triangle_Model::NbRegions() const
{
    return myRegions.NbRows();
}

// ============================================================================
/*!
    \brief NbSegments()
*/
// ============================================================================
Standard_Integer Triangle_Model::NbSegments() const
{
    return mySegments.NbRows();
}

// ============================================================================
/*!
    \brief NbTriangleAttributes()
*/
// ============================================================================
Standard_Integer Triangle_Model::NbTriangleAttributes() const
{
    return myTriangleAttributes.NbRows();
}

// ============================================================================
/*!
    \brief NbTriangleCorners()
*/
// ============================================================================
Standard_Integer Triangle_Model::NbTriangleCorners() const
{
    return myTriangles.NbColumns();
}

// ============================================================================
/*!
    \brief NbTriangles()
*/
// ============================================================================
Standard_Integer Triangle_Model::NbTriangles() const
{
    return myTriangles.NbRows();
}

// ============================================================================
/*!
    \brief Normal()
*/
// ============================================================================
void Triangle_Model::Normal(const Standard_Integer theIndex,
                            Standard_Real& theVX,
                            Standard_Real& theVY) const
{
    theVX = myNormals.Value(theIndex, 1);
    theVY = myNormals.Value(theIndex, 2);
}

// ============================================================================
/*!
    \brief Point()
*/
// ============================================================================
void Triangle_Model::Point(const Standard_Integer theIndex,
                           Standard_Real& theX,
                           Standard_Real& theY) const
{
    theX = myPoints.Value(theIndex, 1);
    theY = myPoints.Value(theIndex, 2);
}

// ============================================================================
/*!
    \brief PointAttribute()
*/
// ============================================================================
void Triangle_Model::PointAttribute(const Standard_Integer theIndex,
                                    const Standard_Integer theAttribute,
                                    Standard_Real& theValue) const
{
    theValue = myPointAttributes.Value(theIndex, theAttribute);
}

// ============================================================================
/*!
    \brief PointMarker()
*/
// ============================================================================
void Triangle_Model::PointMarker(const Standard_Integer theIndex,
                                 Standard_Integer& theMarker) const
{
    theMarker = myPointMarkers.Value(theIndex);
}

// ============================================================================
/*!
    \brief Region()
*/
// ============================================================================
void Triangle_Model::Region(const Standard_Integer theIndex,
                            Standard_Real& theX,
                            Standard_Real& theY,
                            Standard_Real& theMaxArea) const
{
    theX = myRegions.Value(theIndex, 1);
    theY = myRegions.Value(theIndex, 2);
    theMaxArea = myRegions.Value(theIndex, 3);
}

// ============================================================================
/*!
    \brief ResizeEdges()
*/
// ============================================================================
void Triangle_Model::ResizeEdges(const Standard_Integer theNbEdges,
                                 const Standard_Boolean toCopyData)
{
    myEdges.Resize(1, theNbEdges, 1, 2, toCopyData);
    myEdgeMarkers.Resize(1, theNbEdges, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeHoles()
*/
// ============================================================================
void Triangle_Model::ResizeHoles(const Standard_Integer theNbHoles,
                                 const Standard_Boolean toCopyData)
{
    myHoles.Resize(1, theNbHoles, 1, 2, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeNormals()
*/
// ============================================================================
void Triangle_Model::ResizeNormals(const Standard_Integer theNbNormals,
                                   const Standard_Boolean toCopyData)
{
    myNormals.Resize(1, theNbNormals, 1, 2, toCopyData);
}

// ============================================================================
/*!
    \brief ResizePoints()
*/
// ============================================================================
void Triangle_Model::ResizePoints(const Standard_Integer theNbPoints,
                                  const Standard_Integer theNbAttributes,
                                  const Standard_Boolean toCopyData)
{
    myPoints.Resize(1, theNbPoints, 1, 2, toCopyData);
    if(theNbAttributes > 0)
        myPointAttributes.Resize(1, theNbPoints, 1, theNbAttributes, toCopyData);
    myPointMarkers.Resize(1, theNbPoints, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeRegions()
*/
// ============================================================================
void Triangle_Model::ResizeRegions(const Standard_Integer theNbRegions,
                                   const Standard_Boolean toCopyData)
{
    myRegions.Resize(1, theNbRegions, 1, 3, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeSegments()
*/
// ============================================================================
void Triangle_Model::ResizeSegments(const Standard_Integer theNbSegments,
                                    const Standard_Boolean toCopyData)
{
    mySegments.Resize(1, theNbSegments, 1, 2, toCopyData);
    mySegmentMarkers.Resize(1, theNbSegments, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeTriangles()
*/
// ============================================================================
void Triangle_Model::ResizeTriangles(const Standard_Integer theNbTriangles,
                                     const Standard_Integer theNbCorners,
                                     const Standard_Integer theNbAttributes,
                                     const Standard_Boolean toCopyData)
{
    myTriangles.Resize(1, theNbTriangles, 1, theNbCorners, toCopyData);
    myTriangleAttributes.Resize(1, theNbTriangles, 1, theNbAttributes, toCopyData);
    myTriangleMaxAreas.Resize(1, theNbTriangles, toCopyData);
    myTriangleNeighbors.Resize(1, theNbTriangles, 1, 3, toCopyData);
}

// ============================================================================
/*!
    \brief Segment()
*/
// ============================================================================
void Triangle_Model::Segment(const Standard_Integer theIndex,
                             Standard_Integer& thePoint1,
                             Standard_Integer& thePoint2) const
{
    thePoint1 = mySegments.Value(theIndex, 1);
    thePoint2 = mySegments.Value(theIndex, 2);
}

// ============================================================================
/*!
    \brief SegmentMarker()
*/
// ============================================================================
void Triangle_Model::SegmentMarker(const Standard_Integer theIndex,
                                   Standard_Integer& theMarker) const
{
    theMarker = mySegmentMarkers.Value(theIndex);
}

// ============================================================================
/*!
    \brief SetEdge()
*/
// ============================================================================
void Triangle_Model::SetEdge(const Standard_Integer theIndex,
                             const Standard_Integer thePoint1,
                             const Standard_Integer thePoint2)
{
    myEdges.SetValue(theIndex, 1, thePoint1);
    myEdges.SetValue(theIndex, 2, thePoint2);
}

// ============================================================================
/*!
    \brief SetEdgeMarker()
*/
// ============================================================================
void Triangle_Model::SetEdgeMarker(const Standard_Integer theIndex,   
                                   const Standard_Integer theMarker)
{
    myEdgeMarkers.SetValue(theIndex, theMarker);
}

// ============================================================================
/*!
    \brief SetHole()
*/
// ============================================================================
void Triangle_Model::SetHole(const Standard_Integer theIndex,
                           const Standard_Real theX,
                           const Standard_Real theY)
{
    myHoles.SetValue(theIndex, 1, theX);
    myHoles.SetValue(theIndex, 2, theY);
}

// ============================================================================
/*!
    \brief SetNormal()
*/
// ============================================================================
void Triangle_Model::SetNormal(const Standard_Integer theIndex,
                               const Standard_Real theX,
                               const Standard_Real theY)
{
    myNormals.SetValue(theIndex, 1, theX);
    myNormals.SetValue(theIndex, 2, theY);
}

// ============================================================================
/*!
    \brief SetPoint()
*/
// ============================================================================
void Triangle_Model::SetPoint(const Standard_Integer theIndex,
                              const Standard_Real theX,
                              const Standard_Real theY)
{
    myPoints.SetValue(theIndex, 1, theX);
    myPoints.SetValue(theIndex, 2, theY);
}

// ============================================================================
/*!
    \brief SetPointAttribute()
*/
// ============================================================================
void Triangle_Model::SetPointAttribute(const Standard_Integer theIndex,
                                       const Standard_Integer theAttribute,
                                       const Standard_Real theValue)
{
    myPointAttributes.SetValue(theIndex, theAttribute, theValue);
}

// ============================================================================
/*!
    \brief SetPointMarker()
*/
// ============================================================================
void Triangle_Model::SetPointMarker(const Standard_Integer theIndex,
                                    const Standard_Integer theMarker)
{
    myPointMarkers.SetValue(theIndex, theMarker);
}

// ============================================================================
/*!
    \brief SetRegion()
*/
// ============================================================================
void Triangle_Model::SetRegion(const Standard_Integer theIndex,
                               const Standard_Real theX,
                               const Standard_Real theY,
                               const Standard_Real theMaxArea)
{
    myRegions.SetValue(theIndex, 1, theX);
    myRegions.SetValue(theIndex, 2, theY);
    myRegions.SetValue(theIndex, 3, theMaxArea);
}

// ============================================================================
/*!
    \brief SetSegment()
*/
// ============================================================================
void Triangle_Model::SetSegment(const Standard_Integer theIndex,
                                const Standard_Integer thePoint1,
                                const Standard_Integer thePoint2)
{
    mySegments.SetValue(theIndex, 1, thePoint1);
    mySegments.SetValue(theIndex, 2, thePoint2);
}

// ============================================================================
/*!
    \brief SetSegmentMarker()
*/
// ============================================================================
void Triangle_Model::SetSegmentMarker(const Standard_Integer theIndex,
                                      const Standard_Integer theMarker)
{
    mySegmentMarkers.SetValue(theIndex, theMarker);
}

// ============================================================================
/*!
    \brief SetTriangleAttribute()
*/
// ============================================================================
void Triangle_Model::SetTriangleAttribute(const Standard_Integer theIndex,
                                          const Standard_Integer theAttribute,
                                          const Standard_Real theValue)
{
    myTriangleAttributes.SetValue(theIndex, theAttribute, theValue);
}

// ============================================================================
/*!
    \brief SetTriangleCorner()
*/
// ============================================================================
void Triangle_Model::SetTriangleCorner(const Standard_Integer theIndex,
                                       const Standard_Integer theCorner,
                                       const Standard_Integer thePoint)
{
    myTriangles.SetValue(theIndex, theCorner, thePoint);
}

// ============================================================================
/*!
    \brief SetTriangleMaxArea()
*/
// ============================================================================
void Triangle_Model::SetTriangleMaxArea(const Standard_Integer theIndex,
                                        const Standard_Real theMaxArea)
{
    myTriangleMaxAreas.SetValue(theIndex, theMaxArea);
}

// ============================================================================
/*!
    \brief SetTriangleNeighbor()
*/
// ============================================================================
void Triangle_Model::SetTriangleNeighbor(const Standard_Integer theIndex,
                                         const Standard_Integer theNeighbor,
                                         const Standard_Integer thePoint)
{
    myTriangleNeighbors.SetValue(theIndex, theNeighbor, thePoint);
}

// ============================================================================
/*!
    \brief TriangleAttribute()
*/
// ============================================================================
void Triangle_Model::TriangleAttribute(const Standard_Integer theIndex,
                                       const Standard_Integer theAttribute,
                                       Standard_Real& theValue) const
{
    theValue = myTriangleAttributes.Value(theIndex, theAttribute);
}

// ============================================================================
/*!
    \brief TriangleCorner()
*/
// ============================================================================
void Triangle_Model::TriangleCorner(const Standard_Integer theIndex,
                                    const Standard_Integer theCorner,
                                    Standard_Integer& thePoint) const
{
    thePoint = myTriangles.Value(theIndex, theCorner);
}

// ============================================================================
/*!
    \brief TriangleMaxArea()
*/
// ============================================================================
void Triangle_Model::TriangleMaxArea(const Standard_Integer theIndex,   
                                     Standard_Real& theMaxArea) const
{
    theMaxArea = myTriangleMaxAreas.Value(theIndex);
}

// ============================================================================
/*!
    \brief TriangleNeighbor()
*/
// ============================================================================
void Triangle_Model::TriangleNeighbor(const Standard_Integer theIndex,
                                      const Standard_Integer theNeighbor,
                                      Standard_Integer& thePoint) const
{
    thePoint = myTriangleNeighbors.Value(theIndex, theNeighbor);
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Triangle_Model, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(Triangle_Model, Standard_Transient)