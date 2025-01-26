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
#include <Tetgen_Model.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Tetgen_Model::Tetgen_Model()    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Tetgen_Model::~Tetgen_Model()    
{
    
}

// ============================================================================
/*!
    \brief Edge()
*/
// ============================================================================
void Tetgen_Model::Edge(const Standard_Integer theIndex,
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
void Tetgen_Model::EdgeMarker(const Standard_Integer theIndex,
                              Standard_Integer& theMarker) const
{
    theMarker = myEdgeMarkers(theIndex);
}

// ============================================================================
/*!
    \brief Facet()
*/
// ============================================================================
const Handle(Tetgen_Facet)& Tetgen_Model::Facet(const Standard_Integer theIndex) const
{
    return myFacets.Value(theIndex);
}

// ============================================================================
/*!
    \brief Facet()
*/
// ============================================================================
void Tetgen_Model::Facet(const Standard_Integer theIndex,
                         Handle(Tetgen_Facet)& theFacet) const
{
    theFacet = myFacets.Value(theIndex);
}

// ============================================================================
/*!
    \brief FacetConstraint()
*/
// ============================================================================
void Tetgen_Model::FacetConstraint(const Standard_Integer theIndex,
                                   Standard_Integer& theMarker,
                                   Standard_Real& theMaxArea) const
{
    theMarker = myFacetConstraints(theIndex, 1);
    theMaxArea = myFacetConstraints(theIndex, 2);
}

// ============================================================================
/*!
    \brief FacetMarker()
*/
// ============================================================================
void Tetgen_Model::FacetMarker(const Standard_Integer theIndex,
                               Standard_Integer& theMarker) const
{
    theMarker = myFacetMarkers.Value(theIndex);
}

// ============================================================================
/*!
    \brief Hole()
*/
// ============================================================================
void Tetgen_Model::Hole(const Standard_Integer theIndex,
                        Standard_Real& theX,
                        Standard_Real& theY,
                        Standard_Real& theZ) const
{
    theX = myHoles(theIndex, 1);
    theY = myHoles(theIndex, 2);
    theZ = myHoles(theIndex, 3);
}

// ============================================================================
/*!
    \brief NbEdges()
*/
// ============================================================================
Standard_Integer Tetgen_Model::NbEdges() const
{
    return myEdges.NbRows();
}

// ============================================================================
/*!
    \brief NbFacetConstraints()
*/
// ============================================================================
Standard_Integer Tetgen_Model::NbFacetConstraints() const
{
    return myFacetConstraints.NbRows();
}

// ============================================================================
/*!
    \brief NbFacets()
*/
// ============================================================================
Standard_Integer Tetgen_Model::NbFacets() const
{
    return myFacets.Length();
}

// ============================================================================
/*!
    \brief NbHoles()
*/
// ============================================================================
Standard_Integer Tetgen_Model::NbHoles() const
{
    return myHoles.NbRows();
}

// ============================================================================
/*!
    \brief NbPointAttributes()
*/
// ============================================================================
Standard_Integer Tetgen_Model::NbPointAttributes() const
{
    return myPointAttributes.NbRows();
}

// ============================================================================
/*!
    \brief NbPoints()
*/
// ============================================================================
Standard_Integer Tetgen_Model::NbPoints() const 
{
    return myPoints.NbRows();
}

// ============================================================================
/*!
    \brief NbRegions()
*/
// ============================================================================
Standard_Integer Tetgen_Model::NbRegions() const
{
    return myRegions.NbRows();
}

// ============================================================================
/*!
    \brief NbSegmentConstraints()
*/
// ============================================================================
Standard_Integer Tetgen_Model::NbSegmentConstraints() const
{
    return mySegmentConstraints.NbRows();
}

// ============================================================================
/*!
    \brief NbTetrahedronAttributes()
*/
// ============================================================================
Standard_Integer Tetgen_Model::NbTetrahedronAttributes() const
{
    return myTetrahedronAttributes.NbRows();
}

// ============================================================================
/*!
    \brief NbTetrahedronCorners()
*/
// ============================================================================
Standard_Integer Tetgen_Model::NbTetrahedronCorners() const
{
    return myTetrahedrons.NbColumns();
}

// ============================================================================
/*!
    \brief NbTetrahedrons()
*/
// ============================================================================
Standard_Integer Tetgen_Model::NbTetrahedrons() const
{
    return myTetrahedrons.NbRows();
}

// ============================================================================
/*!
    \brief NbTriangles()
*/
// ============================================================================
Standard_Integer Tetgen_Model::NbTriangles() const
{
    return myTriangles.NbRows();
}

// ============================================================================
/*!
    \brief Point()
*/
// ============================================================================
void Tetgen_Model::Point(const Standard_Integer theIndex,
                         Standard_Real& theX,
                         Standard_Real& theY,
                         Standard_Real& theZ) const
{
    theX = myPoints.Value(theIndex, 1);
    theY = myPoints.Value(theIndex, 2);
    theZ = myPoints.Value(theIndex, 3);
}

// ============================================================================
/*!
    \brief PointAttribute()
*/
// ============================================================================
void Tetgen_Model::PointAttribute(const Standard_Integer theIndex,
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
void Tetgen_Model::PointMarker(const Standard_Integer theIndex,
                               Standard_Integer& theMarker) const
{
    theMarker = myPointMarkers.Value(theIndex);
}

// ============================================================================
/*!
    \brief Region()
*/
// ============================================================================
void Tetgen_Model::Region(const Standard_Integer theIndex,
                          Standard_Real& theX,
                          Standard_Real& theY,
                          Standard_Real& theZ,
                          Standard_Real& theMaxVolumne) const
{
    theX = myRegions.Value(theIndex, 1);
    theY = myRegions.Value(theIndex, 2);
    theZ = myRegions.Value(theIndex, 3);
    theMaxVolumne = myRegions.Value(theIndex, 4);
}

// ============================================================================
/*!
    \brief ResizeEdges()
*/
// ============================================================================
void Tetgen_Model::ResizeEdges(const Standard_Integer theNbEdges,
                               const Standard_Boolean toCopyData)
{
    myEdges.Resize(1, theNbEdges, 1, 2, toCopyData);
    myEdgeMarkers.Resize(1, theNbEdges, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeFacetConstraints()
*/
// ============================================================================
void Tetgen_Model::ResizeFacetConstraints(const Standard_Integer theNbFacetConstraints,
                                         const Standard_Boolean toCopyData)
{
    myFacetConstraints.Resize(1, theNbFacetConstraints, 1, 2, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeFacets()
*/
// ============================================================================
void Tetgen_Model::ResizeFacets(const Standard_Integer theNbFacets,
                                const Standard_Boolean toCopyData)
{
    myFacets.Resize(1, theNbFacets, toCopyData);
    myFacetMarkers.Resize(1, theNbFacets, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeHoles()
*/
// ============================================================================
void Tetgen_Model::ResizeHoles(const Standard_Integer theNbHoles,
                               const Standard_Boolean toCopyData)
{
    myHoles.Resize(1, theNbHoles, 1, 3, toCopyData);
}

// ============================================================================
/*!
    \brief ResizePoints()
*/
// ============================================================================
void Tetgen_Model::ResizePoints(const Standard_Integer theNbPoints,
                                const Standard_Integer theNbAttributes,
                                const Standard_Boolean toCopyData)
{
    myPoints.Resize(1, theNbPoints, 1, 3, toCopyData);
    if(theNbAttributes > 0)
        myPointAttributes.Resize(1, theNbPoints, 1, theNbAttributes, toCopyData);
    myPointMarkers.Resize(1, theNbPoints, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeRegions()
*/
// ============================================================================
void Tetgen_Model::ResizeRegions(const Standard_Integer theNbRegions,
                                 const Standard_Boolean toCopyData)
{
    myRegions.Resize(1, theNbRegions, 1, 4, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeSegmentConstraints()
*/
// ============================================================================
void Tetgen_Model::ResizeSegmentConstraints(const Standard_Integer theNbConstraints,
                                            const Standard_Boolean toCopyData)
{
    mySegmentConstraints.Resize(1, theNbConstraints, 1, 2, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeTetrahedrons()
*/
// ============================================================================
void Tetgen_Model::ResizeTetrahedrons(const Standard_Integer theNbTetrahedrons,
                                      const Standard_Integer theNbCorners,
                                      const Standard_Integer theNbAttributes,
                                      const Standard_Boolean toCopyData)
{
    myTetrahedrons.Resize(1, theNbTetrahedrons, 1, theNbCorners, toCopyData);
    if(theNbAttributes > 0)
        myTetrahedronAttributes.Resize(1, theNbTetrahedrons, 1, theNbAttributes, toCopyData);
    myTetrahedronNeighbors.Resize(1, theNbTetrahedrons, 1, 4, toCopyData);
    myTetrahedronMaxVolumes.Resize(1, theNbTetrahedrons, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeTriangles()
*/
// ============================================================================
void Tetgen_Model::ResizeTriangles(const Standard_Integer theNbTriangles,
                                   const Standard_Boolean toCopyData)
{
    myTriangles.Resize(1, theNbTriangles, 1, 3, toCopyData);
    myTriangleMarkers.Resize(1, theNbTriangles, toCopyData);
}

// ============================================================================
/*!
    \brief SegmentConstraint()
*/
// ============================================================================
void Tetgen_Model::SegmentConstraint(const Standard_Integer theIndex,
                                     Standard_Integer& thePoint,
                                     Standard_Real& theMaxLength) const
{
    thePoint = mySegmentConstraints.Value(theIndex, 1);
    theMaxLength = mySegmentConstraints.Value(theIndex, 2);
}

// ============================================================================
/*!
    \brief SetEdge()
*/
// ============================================================================
void Tetgen_Model::SetEdge(const Standard_Integer theIndex,
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
void Tetgen_Model::SetEdgeMarker(const Standard_Integer theIndex,   
                                 const Standard_Integer theMarker)
{
    myEdgeMarkers.SetValue(theIndex, theMarker);
}

// ============================================================================
/*!
    \brief SetFacet()
*/
// ============================================================================
void Tetgen_Model::SetFacet(const Standard_Integer theIndex,
                            const Handle(Tetgen_Facet)& theFacet)
{
    myFacets.SetValue(theIndex, theFacet);
}

// ============================================================================
/*!
    \brief SetFacetConstraint()
*/
// ============================================================================
void Tetgen_Model::SetFacetConstraint(const Standard_Integer theIndex,
                                      const Standard_Integer theMarker,
                                      const Standard_Real theMaxArea)
{
    myFacetConstraints.SetValue(theIndex, 1, theMarker);
    myFacetConstraints.SetValue(theIndex, 2, theMaxArea);
}

// ============================================================================
/*!
    \brief SetFacetMarker()
*/
// ============================================================================
void Tetgen_Model::SetFacetMarker(const Standard_Integer theIndex,
                                  const Standard_Integer theMarker)
{
    myFacetMarkers.SetValue(theIndex, theMarker);
}

// ============================================================================
/*!
    \brief SetHole()
*/
// ============================================================================
void Tetgen_Model::SetHole(const Standard_Integer theIndex,
                           const Standard_Real theX,
                           const Standard_Real theY,
                           const Standard_Real theZ)
{
    myHoles.SetValue(theIndex, 1, theX);
    myHoles.SetValue(theIndex, 2, theY);
    myHoles.SetValue(theIndex, 3, theZ);
}

// ============================================================================
/*!
    \brief SetPoint()
*/
// ============================================================================
void Tetgen_Model::SetPoint(const Standard_Integer theIndex,
                            const Standard_Real theX,
                            const Standard_Real theY,
                            const Standard_Real theZ)
{
    myPoints.SetValue(theIndex, 1, theX);
    myPoints.SetValue(theIndex, 2, theY);
    myPoints.SetValue(theIndex, 3, theZ);
}

// ============================================================================
/*!
    \brief SetPointAttribute()
*/
// ============================================================================
void Tetgen_Model::SetPointAttribute(const Standard_Integer theIndex,
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
void Tetgen_Model::SetPointMarker(const Standard_Integer theIndex,
                                  const Standard_Integer theMarker)
{
    myPointMarkers.SetValue(theIndex, theMarker);
}

// ============================================================================
/*!
    \brief SetRegion()
*/
// ============================================================================
void Tetgen_Model::SetRegion(const Standard_Integer theIndex,
                             const Standard_Real theX,
                             const Standard_Real theY,
                             const Standard_Real theZ,
                             const Standard_Real theMaxVolume)
{
    myRegions.SetValue(theIndex, 1, theX);
    myRegions.SetValue(theIndex, 2, theY);
    myRegions.SetValue(theIndex, 3, theZ);
    myRegions.SetValue(theIndex, 4, theMaxVolume);
}

// ============================================================================
/*!
    \brief SetSegmentConstraint()
*/
// ============================================================================
void Tetgen_Model::SetSegmentConstraint(const Standard_Integer theIndex,
                                        const Standard_Integer thePoint,
                                        const Standard_Real theMaxLength)
{
    mySegmentConstraints.SetValue(theIndex, 1, thePoint);
    mySegmentConstraints.SetValue(theIndex, 2, theMaxLength);
}

// ============================================================================
/*!
    \brief SetTetrahedronAttribute()
*/
// ============================================================================
void Tetgen_Model::SetTetrahedronAttribute(const Standard_Integer theIndex,
                                           const Standard_Integer theAttribute,
                                           const Standard_Real theValue)
{
    myTetrahedronAttributes.SetValue(theIndex, theAttribute, theValue);
}

// ============================================================================
/*!
    \brief SetTetrahedronCorner()
*/
// ============================================================================
void Tetgen_Model::SetTetrahedronCorner(const Standard_Integer theIndex,
                                        const Standard_Integer theCorner,
                                        const Standard_Integer thePoint)
{
    myTetrahedrons.SetValue(theIndex, theCorner, thePoint);
}

// ============================================================================
/*!
    \brief SetTetrahedronMaxVolume()
*/
// ============================================================================
void Tetgen_Model::SetTetrahedronMaxVolume(const Standard_Integer theIndex,
                                           const Standard_Real theMaxVolume)
{
    myTetrahedronMaxVolumes.SetValue(theIndex, theMaxVolume);
}

// ============================================================================
/*!
    \brief SetTetrahedronNeighbor()
*/
// ============================================================================
void Tetgen_Model::SetTetrahedronNeighbor(const Standard_Integer theIndex,
                                          const Standard_Integer theNeighbor,
                                          const Standard_Integer thePoint)
{
    myTetrahedronNeighbors.SetValue(theIndex, theNeighbor, thePoint);
}

// ============================================================================
/*!
    \brief SetTriangle()
*/
// ============================================================================
void Tetgen_Model::SetTriangle(const Standard_Integer theIndex,
                               const Standard_Integer thePoint1,
                               const Standard_Integer thePoint2,
                               const Standard_Integer thePoint3)
{
    myTriangles.SetValue(theIndex, 1, thePoint1);
    myTriangles.SetValue(theIndex, 2, thePoint2);
    myTriangles.SetValue(theIndex, 3, thePoint3);
}

// ============================================================================
/*!
    \brief SetTriangleMarker()
*/
// ============================================================================
void Tetgen_Model::SetTriangleMarker(const Standard_Integer theIndex,
                                     const Standard_Integer theMarker)
{
    myTriangleMarkers.SetValue(theIndex, theMarker);
}

// ============================================================================
/*!
    \brief TetrahedronAttribute()
*/
// ============================================================================
void Tetgen_Model::TetrahedronAttribute(const Standard_Integer theIndex,
                                        const Standard_Integer theAttribute,
                                        Standard_Real& theValue) const
{
    theValue = myTetrahedronAttributes.Value(theIndex, theAttribute);
}

// ============================================================================
/*!
    \brief TetrahedronCorner()
*/
// ============================================================================
void Tetgen_Model::TetrahedronCorner(const Standard_Integer theIndex,
                                     const Standard_Integer theCorner,
                                     Standard_Integer& thePoint) const
{
    thePoint = myTetrahedrons.Value(theIndex, theCorner);
}

// ============================================================================
/*!
    \brief TetrahedronMaxVolume()
*/
// ============================================================================
void Tetgen_Model::TetrahedronMaxVolume(const Standard_Integer theIndex,
                                        Standard_Real& theMaxVolume) const
{
    theMaxVolume = myTetrahedronMaxVolumes.Value(theIndex);
}

// ============================================================================
/*!
    \brief TetrahedronNeighbor()
*/
// ============================================================================
void Tetgen_Model::TetrahedronNeighbor(const Standard_Integer theIndex,
                                       const Standard_Integer theNeighbor,
                                       Standard_Integer& thePoint) const
{
    thePoint = myTetrahedronNeighbors.Value(theIndex, theNeighbor);
}

// ============================================================================
/*!
    \brief Triangle()
*/
// ============================================================================
void Tetgen_Model::Triangle(const Standard_Integer theIndex,
                            Standard_Integer& thePoint1,
                            Standard_Integer& thePoint2,
                            Standard_Integer& thePoint3) const
{
    thePoint1 = myTriangles.Value(theIndex, 1);
    thePoint2 = myTriangles.Value(theIndex, 2);
    thePoint3 = myTriangles.Value(theIndex, 3);
}

// ============================================================================
/*!
    \brief TriangleMarker()
*/
// ============================================================================
void Tetgen_Model::TriangleMarker(const Standard_Integer theIndex,
                                  Standard_Integer& theMarker) const
{
    theMarker = myTriangleMarkers.Value(theIndex);
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(Tetgen_Model, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(Tetgen_Model, Standard_Transient)