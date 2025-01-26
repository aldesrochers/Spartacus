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


#ifndef __Triangle_Model_hxx__
#define __Triangle_Model_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfInteger.hxx>
#include <TColStd_Array2OfReal.hxx>

// Handles
DEFINE_STANDARD_HANDLE(Triangle_Model, Standard_Transient)


// ============================================================================
/*
    \brief Triangle_Model
*/
// ============================================================================
class Triangle_Model : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT Triangle_Model();
    // destructors
    Standard_EXPORT ~Triangle_Model();

public:

    Standard_EXPORT const TColStd_Array1OfInteger&  EdgeMarkers() const {return myEdgeMarkers;}
    Standard_EXPORT TColStd_Array1OfInteger&        EdgeMarkers() {return myEdgeMarkers;}

    Standard_EXPORT const TColStd_Array2OfInteger&  Edges() const {return myEdges;}
    Standard_EXPORT TColStd_Array2OfInteger&        Edges() {return myEdges;}

    Standard_EXPORT const TColStd_Array2OfReal&     Holes() const {return myHoles;}
    Standard_EXPORT TColStd_Array2OfReal&           Holes() {return myHoles;}

    Standard_EXPORT const TColStd_Array2OfReal&     Normals() const {return myNormals;}
    Standard_EXPORT TColStd_Array2OfReal&           Normals() {return myNormals;}

    Standard_EXPORT const TColStd_Array2OfReal&     PointAttributes() const {return myPointAttributes;}
    Standard_EXPORT TColStd_Array2OfReal&           PointAttributes() {return myPointAttributes;}

    Standard_EXPORT const TColStd_Array1OfInteger&  PointMarkers() const {return myPointMarkers;}
    Standard_EXPORT TColStd_Array1OfInteger&        PointMarkers() {return myPointMarkers;}

    Standard_EXPORT const TColStd_Array2OfReal&     Points() const {return myPoints;}    
    Standard_EXPORT TColStd_Array2OfReal&           Points() {return myPoints;}

    Standard_EXPORT const TColStd_Array2OfReal&     Regions() const {return myRegions;}    
    Standard_EXPORT TColStd_Array2OfReal&           Regions() {return myRegions;}

    Standard_EXPORT const TColStd_Array2OfInteger&  Segments() const {return mySegments;}
    Standard_EXPORT TColStd_Array2OfInteger&        Segments() {return mySegments;}

    Standard_EXPORT const TColStd_Array1OfInteger&  SegmentMarkers() const {return mySegmentMarkers;}
    Standard_EXPORT TColStd_Array1OfInteger&        SegmentMarkers() {return mySegmentMarkers;}

    Standard_EXPORT const TColStd_Array2OfReal&     TriangleAttributes() const {return myTriangleAttributes;}
    Standard_EXPORT TColStd_Array2OfReal&           TriangleAttributes() {return myTriangleAttributes;}

    Standard_EXPORT const TColStd_Array2OfInteger&  TriangleNeighbors() const {return myTriangleNeighbors;}
    Standard_EXPORT TColStd_Array2OfInteger&        TriangleNeighbors() {return myTriangleNeighbors;}

    Standard_EXPORT const TColStd_Array1OfReal&     TriangleMaxAreas() const {return myTriangleMaxAreas;}
    Standard_EXPORT TColStd_Array1OfReal&           TriangleMaxAreas() {return myTriangleMaxAreas;}

    Standard_EXPORT const TColStd_Array2OfInteger&  Triangles() const {return myTriangles;}
    Standard_EXPORT TColStd_Array2OfInteger&        Triangles() {return myTriangles;}

public:

    Standard_EXPORT void                        Edge(const Standard_Integer theIndex, 
                                                     Standard_Integer& thePoint1,
                                                     Standard_Integer& thePoint2) const;
    Standard_EXPORT void                        EdgeMarker(const Standard_Integer theIndex,
                                                           Standard_Integer& theMarker) const;

    Standard_EXPORT void                        Hole(const Standard_Integer theIndex,
                                                     Standard_Real& theX,
                                                     Standard_Real& theY) const;

    Standard_EXPORT Standard_Integer            NbEdges() const;
    Standard_EXPORT Standard_Integer            NbHoles() const;
    Standard_EXPORT Standard_Integer            NbNormals() const;
    Standard_EXPORT Standard_Integer            NbPointAttributes() const;
    Standard_EXPORT Standard_Integer            NbPoints() const;
    Standard_EXPORT Standard_Integer            NbRegions() const;
    Standard_EXPORT Standard_Integer            NbSegments() const;
    Standard_EXPORT Standard_Integer            NbTriangleAttributes() const;
    Standard_EXPORT Standard_Integer            NbTriangleCorners() const;
    Standard_EXPORT Standard_Integer            NbTriangles() const;

    Standard_EXPORT void                        Normal(const Standard_Integer theIndex,
                                                       Standard_Real& theVX,
                                                       Standard_Real& theVY) const;

    Standard_EXPORT void                        Point(const Standard_Integer theIndex,
                                                      Standard_Real& theX,
                                                      Standard_Real& theY) const;

    Standard_EXPORT void                        PointAttribute(const Standard_Integer theIndex,
                                                               const Standard_Integer theAttribute,
                                                               Standard_Real& theValue) const;

    Standard_EXPORT void                        PointMarker(const Standard_Integer theIndex,
                                                            Standard_Integer& theMarker) const;

    Standard_EXPORT void                        Region(const Standard_Integer theIndex,
                                                       Standard_Real& theX,
                                                       Standard_Real& theY,
                                                       Standard_Real& theMaxArea) const;

    Standard_EXPORT void                        ResizeEdges(const Standard_Integer theNbEdges,
                                                            const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizeHoles(const Standard_Integer theNbHoles,
                                                            const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizeNormals(const Standard_Integer theNbNormals,
                                                              const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizePoints(const Standard_Integer theNbPoints,
                                                             const Standard_Integer theNbAttributes,  
                                                             const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizeRegions(const Standard_Integer theNbRegions,
                                                              const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizeSegments(const Standard_Integer theNbSegments,
                                                               const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizeTriangles(const Standard_Integer theNbTriangles,
                                                                const Standard_Integer theNbCorners,
                                                                const Standard_Integer theNbAttributes,
                                                                const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        Segment(const Standard_Integer theIndex,
                                                        Standard_Integer& thePoint1,
                                                        Standard_Integer& thePoint2) const;

    Standard_EXPORT void                        SegmentMarker(const Standard_Integer theIndex,
                                                              Standard_Integer& theMarker) const;

    Standard_EXPORT void                        SetEdge(const Standard_Integer theIndex,
                                                        const Standard_Integer thePoint1,
                                                        const Standard_Integer thePoint2);

    Standard_EXPORT void                        SetEdgeMarker(const Standard_Integer theIndex,
                                                              const Standard_Integer theMarker);

    Standard_EXPORT void                        SetHole(const Standard_Integer theIndex,
                                                        const Standard_Real theX,
                                                        const Standard_Real theY);

    Standard_EXPORT void                        SetNormal(const Standard_Integer theIndex,
                                                          const Standard_Real theVX,
                                                          const Standard_Real theVY);

    Standard_EXPORT void                        SetPoint(const Standard_Integer theIndex,
                                                         const Standard_Real theX,
                                                         const Standard_Real theY);

    Standard_EXPORT void                        SetPointAttribute(const Standard_Integer theIndex,
                                                                  const Standard_Integer theAttribute,
                                                                  const Standard_Real theValue);

    Standard_EXPORT void                        SetPointMarker(const Standard_Integer theIndex,
                                                               const Standard_Integer theMarker);

    Standard_EXPORT void                        SetRegion(const Standard_Integer theIndex,
                                                          const Standard_Real theX,
                                                          const Standard_Real theY,
                                                          const Standard_Real theMaxArea);

    Standard_EXPORT void                        SetSegment(const Standard_Integer theIndex,
                                                           const Standard_Integer thePoint1,
                                                           const Standard_Integer thePoint2);

    Standard_EXPORT void                        SetSegmentMarker(const Standard_Integer theIndex,
                                                                 const Standard_Integer theMarker);

    Standard_EXPORT void                        SetTriangleAttribute(const Standard_Integer theIndex,
                                                                     const Standard_Integer theAttribute,
                                                                     const Standard_Real theValue);

    Standard_EXPORT void                        SetTriangleCorner(const Standard_Integer theIndex,
                                                                  const Standard_Integer theCorner,
                                                                  const Standard_Integer thePoint);

    Standard_EXPORT void                        SetTriangleMaxArea(const Standard_Integer theIndex,
                                                                   const Standard_Real theMaxArea);

    Standard_EXPORT void                        SetTriangleNeighbor(const Standard_Integer theIndex,
                                                                    const Standard_Integer theNeighbor,
                                                                    const Standard_Integer thePoint);

    Standard_EXPORT void                        TriangleAttribute(const Standard_Integer theIndex,
                                                                  const Standard_Integer theAttribute,
                                                                  Standard_Real& theValue) const;

    Standard_EXPORT void                        TriangleCorner(const Standard_Integer theIndex,
                                                               const Standard_Integer theCorner,
                                                               Standard_Integer& thePoint) const;

    Standard_EXPORT void                        TriangleMaxArea(const Standard_Integer theIndex,
                                                                Standard_Real& theMaxArea) const;

    Standard_EXPORT void                        TriangleNeighbor(const Standard_Integer theIndex,
                                                                 const Standard_Integer theNeighbor,
                                                                 Standard_Integer& thePoint) const;

private:

    TColStd_Array1OfInteger  myEdgeMarkers;
    TColStd_Array2OfInteger  myEdges;
    TColStd_Array2OfReal     myHoles;
    TColStd_Array2OfReal     myNormals;
    TColStd_Array2OfReal     myPointAttributes;
    TColStd_Array1OfInteger  myPointMarkers;
    TColStd_Array2OfReal     myPoints;
    TColStd_Array2OfReal     myRegions;
    TColStd_Array2OfInteger  mySegments;
    TColStd_Array1OfInteger  mySegmentMarkers;
    TColStd_Array2OfReal     myTriangleAttributes;
    TColStd_Array1OfReal     myTriangleMaxAreas;
    TColStd_Array2OfInteger  myTriangleNeighbors;
    TColStd_Array2OfInteger  myTriangles;

public:

    DEFINE_STANDARD_RTTIEXT(Triangle_Model, Standard_Transient)

};

#endif // __Triangle_Model_hxx__
