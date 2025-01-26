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


#ifndef __Tetgen_Model_hxx__
#define __Tetgen_Model_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfInteger.hxx>
#include <TColStd_Array2OfReal.hxx>

// Spartacus
#include <Tetgen_Array1OfFacet.hxx>

// Handles
DEFINE_STANDARD_HANDLE(Tetgen_Model, Standard_Transient)


// ============================================================================
/*
    \brief Tetgen_Model
*/
// ============================================================================
class Tetgen_Model : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT Tetgen_Model();
    // destructors
    Standard_EXPORT ~Tetgen_Model();

public:

    Standard_EXPORT const TColStd_Array1OfInteger&  EdgeMarkers() const {return myEdgeMarkers;}
    Standard_EXPORT TColStd_Array1OfInteger&        EdgeMarkers() {return myEdgeMarkers;}

    Standard_EXPORT const TColStd_Array2OfInteger&  Edges() const {return myEdges;}
    Standard_EXPORT TColStd_Array2OfInteger&        Edges() {return myEdges;}

    Standard_EXPORT const TColStd_Array2OfReal&     FacetConstraints() const {return myFacetConstraints;}
    Standard_EXPORT TColStd_Array2OfReal&           FacetConstraints() {return myFacetConstraints;}

    Standard_EXPORT const TColStd_Array1OfInteger&  FacetMarkers() const {return myFacetMarkers;}
    Standard_EXPORT TColStd_Array1OfInteger&        FacetMarkers() {return myFacetMarkers;}

    Standard_EXPORT const Tetgen_Array1OfFacet&     Facets() const {return myFacets;}
    Standard_EXPORT Tetgen_Array1OfFacet&           Facets() {return myFacets;}

    Standard_EXPORT const TColStd_Array2OfReal&     Holes() const {return myHoles;}
    Standard_EXPORT TColStd_Array2OfReal&           Holes() {return myHoles;}

    Standard_EXPORT const TColStd_Array2OfReal&     PointAttributes() const {return myPointAttributes;}
    Standard_EXPORT TColStd_Array2OfReal&           PointAttributes() {return myPointAttributes;}

    Standard_EXPORT const TColStd_Array1OfInteger&  PointMarkers() const {return myPointMarkers;}
    Standard_EXPORT TColStd_Array1OfInteger&        PointMarkers() {return myPointMarkers;}

    Standard_EXPORT const TColStd_Array2OfReal&     Points() const {return myPoints;}    
    Standard_EXPORT TColStd_Array2OfReal&           Points() {return myPoints;}

    Standard_EXPORT const TColStd_Array2OfReal&     Regions() const {return myRegions;}    
    Standard_EXPORT TColStd_Array2OfReal&           Regions() {return myRegions;}

    Standard_EXPORT const TColStd_Array2OfReal&     SegmentConstraints() const {return mySegmentConstraints;}
    Standard_EXPORT TColStd_Array2OfReal&           SegmentConstraints() {return mySegmentConstraints;}

    Standard_EXPORT const TColStd_Array2OfReal&     TetrahedronAttributes() const {return myTetrahedronAttributes;} 
    Standard_EXPORT TColStd_Array2OfReal&           TetrahedronAttributes() {return myTetrahedronAttributes;}

    Standard_EXPORT const TColStd_Array1OfReal&     TetrahedronMaxVolumes() const {return myTetrahedronMaxVolumes;}
    Standard_EXPORT TColStd_Array1OfReal&           TetrahedronMaxVolumes() {return myTetrahedronMaxVolumes;}

    Standard_EXPORT const TColStd_Array2OfInteger&  TetrahedronNeighbors() const {return myTetrahedronNeighbors;}
    Standard_EXPORT TColStd_Array2OfInteger&        TetrahedronNeighbors() {return myTetrahedronNeighbors;}

    Standard_EXPORT const TColStd_Array2OfInteger&  Tetrahedrons() const {return myTetrahedrons;}
    Standard_EXPORT TColStd_Array2OfInteger&        Tetrahedrons() {return myTetrahedrons;}

    Standard_EXPORT const TColStd_Array1OfInteger&  TriangleMarkers() const {return myTriangleMarkers;}
    Standard_EXPORT TColStd_Array1OfInteger&        TriangleMarkers() {return myTriangleMarkers;}

    Standard_EXPORT const TColStd_Array2OfInteger&  Triangles() const {return myTriangles;}
    Standard_EXPORT TColStd_Array2OfInteger&        Triangles() {return myTriangles;}

public:

    Standard_EXPORT void                        Edge(const Standard_Integer theIndex, 
                                                     Standard_Integer& thePoint1,
                                                     Standard_Integer& thePoint2) const;
    Standard_EXPORT void                        EdgeMarker(const Standard_Integer theIndex,
                                                           Standard_Integer& theMarker) const;

    Standard_EXPORT const Handle(Tetgen_Facet)& Facet(const Standard_Integer theIndex) const;
    Standard_EXPORT void                        Facet(const Standard_Integer theIndex,
                                                      Handle(Tetgen_Facet)& theFacet) const;
    Standard_EXPORT void                        FacetConstraint(const Standard_Integer theIndex,
                                                                Standard_Integer& theMarker,
                                                                Standard_Real& theMaxArea) const;
    Standard_EXPORT void                        FacetMarker(const Standard_Integer theIndex,
                                                            Standard_Integer& theMarker) const;

    Standard_EXPORT void                        Hole(const Standard_Integer theIndex,
                                                     Standard_Real& theX,
                                                     Standard_Real& theY,
                                                     Standard_Real& theZ) const;

    Standard_EXPORT Standard_Integer            NbEdges() const;
    Standard_EXPORT Standard_Integer            NbFacetConstraints() const;
    Standard_EXPORT Standard_Integer            NbFacets() const;
    Standard_EXPORT Standard_Integer            NbHoles() const;
    Standard_EXPORT Standard_Integer            NbPointAttributes() const;
    Standard_EXPORT Standard_Integer            NbPoints() const;
    Standard_EXPORT Standard_Integer            NbRegions() const;
    Standard_EXPORT Standard_Integer            NbSegmentConstraints() const;
    Standard_EXPORT Standard_Integer            NbTetrahedronAttributes() const;
    Standard_EXPORT Standard_Integer            NbTetrahedronCorners() const;
    Standard_EXPORT Standard_Integer            NbTetrahedrons() const;
    Standard_EXPORT Standard_Integer            NbTriangles() const;

    Standard_EXPORT void                        Point(const Standard_Integer theIndex,
                                                      Standard_Real& theX,
                                                      Standard_Real& theY,
                                                      Standard_Real& theZ) const;

    Standard_EXPORT void                        PointAttribute(const Standard_Integer theIndex,
                                                               const Standard_Integer theAttribute,
                                                               Standard_Real& theValue) const;

    Standard_EXPORT void                        PointMarker(const Standard_Integer theIndex,
                                                            Standard_Integer& theMarker) const;

    Standard_EXPORT void                        Region(const Standard_Integer theIndex,
                                                       Standard_Real& theX,
                                                       Standard_Real& theY,
                                                       Standard_Real& theZ,
                                                       Standard_Real& theMaxVolumne) const;

    Standard_EXPORT void                        ResizeEdges(const Standard_Integer theNbEdges,
                                                            const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizeFacetConstraints(const Standard_Integer theNbFacetConstraints,
                                                                       const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizeFacets(const Standard_Integer theNbFacets,
                                                             const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizeHoles(const Standard_Integer theNbHoles,
                                                            const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizePoints(const Standard_Integer theNbPoints,
                                                             const Standard_Integer theNbAttributes,  
                                                             const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizeRegions(const Standard_Integer theNbRegions,
                                                              const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizeSegmentConstraints(const Standard_Integer theNbSegmentConstraints,
                                                                         const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizeTetrahedrons(const Standard_Integer theNbTetrahedrons,
                                                                   const Standard_Integer theNbCorners,
                                                                   const Standard_Integer theNbAttributes,
                                                                   const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        ResizeTriangles(const Standard_Integer theNbTriangles,
                                                                const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                        SegmentConstraint(const Standard_Integer theIndex,
                                                                  Standard_Integer& thePoint,
                                                                  Standard_Real& theMaxLength) const;

    Standard_EXPORT void                        SetEdge(const Standard_Integer theIndex,
                                                        const Standard_Integer thePoint1,
                                                        const Standard_Integer thePoint2);

    Standard_EXPORT void                        SetEdgeMarker(const Standard_Integer theIndex,
                                                              const Standard_Integer theMarker);

    Standard_EXPORT void                        SetFacet(const Standard_Integer theIndex,
                                                         const Handle(Tetgen_Facet)& theFacet);

    Standard_EXPORT void                        SetFacetConstraint(const Standard_Integer theIndex,
                                                                   const Standard_Integer theMarker,
                                                                   const Standard_Real theMaxArea);

    Standard_EXPORT void                        SetFacetMarker(const Standard_Integer theIndex,
                                                               const Standard_Integer theMarker);

    Standard_EXPORT void                        SetHole(const Standard_Integer theIndex,
                                                        const Standard_Real theX,
                                                        const Standard_Real theY,
                                                        const Standard_Real theZ);

    Standard_EXPORT void                        SetPoint(const Standard_Integer theIndex,
                                                         const Standard_Real theX,
                                                         const Standard_Real theY,
                                                         const Standard_Real theZ);

    Standard_EXPORT void                        SetPointAttribute(const Standard_Integer theIndex,
                                                                  const Standard_Integer theAttribute,
                                                                  const Standard_Real theValue);

    Standard_EXPORT void                        SetPointMarker(const Standard_Integer theIndex,
                                                               const Standard_Integer theMarker);

    Standard_EXPORT void                        SetRegion(const Standard_Integer theIndex,
                                                          const Standard_Real theX,
                                                          const Standard_Real theY,
                                                          const Standard_Real theZ,
                                                          const Standard_Real theMaxVolume);

    Standard_EXPORT void                        SetSegmentConstraint(const Standard_Integer theIndex,
                                                                     const Standard_Integer thePoint,
                                                                     const Standard_Real theMaxLength);

    Standard_EXPORT void                        SetTetrahedronAttribute(const Standard_Integer theIndex,
                                                                        const Standard_Integer theAttribute,
                                                                        const Standard_Real theValue);

    Standard_EXPORT void                        SetTetrahedronCorner(const Standard_Integer theIndex,
                                                                     const Standard_Integer theCorner,
                                                                     const Standard_Integer thePoint);

    Standard_EXPORT void                        SetTetrahedronMaxVolume(const Standard_Integer theIndex,
                                                                        const Standard_Real theMaxVolume);

    Standard_EXPORT void                        SetTetrahedronNeighbor(const Standard_Integer theIndex,
                                                                       const Standard_Integer theNeighbor,
                                                                       const Standard_Integer thePoint);

    Standard_EXPORT void                        SetTriangle(const Standard_Integer theIndex,
                                                            const Standard_Integer thePoint1,
                                                            const Standard_Integer thePoint2,
                                                            const Standard_Integer thePoint3);

    Standard_EXPORT void                        SetTriangleMarker(const Standard_Integer theIndex,
                                                                  const Standard_Integer theMarker);

    Standard_EXPORT void                        TetrahedronAttribute(const Standard_Integer theIndex,
                                                                     const Standard_Integer theAttribute,
                                                                     Standard_Real& theValue) const;

    Standard_EXPORT void                        TetrahedronCorner(const Standard_Integer theIndex,
                                                                  const Standard_Integer theCorner,
                                                                  Standard_Integer& thePoint) const;

    Standard_EXPORT void                        TetrahedronMaxVolume(const Standard_Integer theIndex,
                                                                     Standard_Real& theMaxVolume) const;

    Standard_EXPORT void                        TetrahedronNeighbor(const Standard_Integer theIndex,
                                                                    const Standard_Integer theNeighbor,
                                                                    Standard_Integer& thePoint) const;

    Standard_EXPORT void                        Triangle(const Standard_Integer theIndex,
                                                         Standard_Integer& thePoint1,
                                                         Standard_Integer& thePoint2,
                                                         Standard_Integer& thePoint3) const;

    Standard_EXPORT void                        TriangleMarker(const Standard_Integer theIndex,
                                                               Standard_Integer& theMarker) const;

private:

    TColStd_Array1OfInteger  myEdgeMarkers;
    TColStd_Array2OfInteger  myEdges;
    TColStd_Array2OfReal     myFacetConstraints;
    TColStd_Array1OfInteger  myFacetMarkers;
    Tetgen_Array1OfFacet     myFacets;
    TColStd_Array2OfReal     myHoles;
    TColStd_Array2OfReal     myPointAttributes;
    TColStd_Array1OfInteger  myPointMarkers;
    TColStd_Array2OfReal     myPoints;
    TColStd_Array2OfReal     myRegions;
    TColStd_Array2OfReal     mySegmentConstraints;
    TColStd_Array2OfReal     myTetrahedronAttributes;
    TColStd_Array1OfReal     myTetrahedronMaxVolumes;
    TColStd_Array2OfInteger  myTetrahedronNeighbors;
    TColStd_Array2OfInteger  myTetrahedrons;
    TColStd_Array1OfInteger  myTriangleMarkers;
    TColStd_Array2OfInteger  myTriangles;

public:

    DEFINE_STANDARD_RTTIEXT(Tetgen_Model, Standard_Transient)

};

#endif // __Tetgen_Model_hxx__
