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


#ifndef __PSLG_Model_hxx__
#define __PSLG_Model_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>

// Spartacus
#include <PSLG_Array1OfHole.hxx>
#include <PSLG_Array1OfNode.hxx>
#include <PSLG_Array1OfRegion.hxx>
#include <PSLG_Array1OfSegment.hxx>

// Handles
DEFINE_STANDARD_HANDLE(PSLG_Model, Standard_Transient)


// ============================================================================
/*
    \brief PSLG_Model
*/
// ============================================================================
class PSLG_Model : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT PSLG_Model();
    Standard_EXPORT PSLG_Model(const Standard_Integer theNbNodes,
                               const Standard_Integer theNbSegments);
    Standard_EXPORT PSLG_Model(const Standard_Integer theNbNodes,
                               const Standard_Integer theNbSegments,
                               const Standard_Integer theNbHoles,
                               const Standard_Integer theNbRegions);
    Standard_EXPORT PSLG_Model(const PSLG_Array1OfNode& theNodes,
                               const PSLG_Array1OfSegment& theSegments);
    Standard_EXPORT PSLG_Model(const PSLG_Array1OfNode& theNodes,    
                               const PSLG_Array1OfSegment& theSegments,
                               const PSLG_Array1OfHole& theHoles,
                               const PSLG_Array1OfRegion& theRegions);
    // destructors
    Standard_EXPORT ~PSLG_Model();

public:

    Standard_EXPORT const Handle(PSLG_Hole)&    Hole(const Standard_Integer theIndex) const;
    Standard_EXPORT const PSLG_Array1OfHole&    Holes() const;
    Standard_EXPORT PSLG_Array1OfHole&          Holes();
    Standard_EXPORT const Handle(PSLG_Node)&    Node(const Standard_Integer theIndex) const;
    Standard_EXPORT Standard_Integer            NbHoles() const;
    Standard_EXPORT Standard_Integer            NbNodes() const;
    Standard_EXPORT Standard_Integer            NbRegions() const;
    Standard_EXPORT Standard_Integer            NbSegments() const;
    Standard_EXPORT const PSLG_Array1OfNode&    Nodes() const;
    Standard_EXPORT PSLG_Array1OfNode&          Nodes();
    Standard_EXPORT const Handle(PSLG_Region)&  Region(const Standard_Integer theIndex) const;
    Standard_EXPORT const PSLG_Array1OfRegion&  Regions() const;
    Standard_EXPORT PSLG_Array1OfRegion&        Regions();
    Standard_EXPORT void                        ResizeHoles(const Standard_Integer theNbHoles,
                                                            const Standard_Boolean toCopyData = Standard_False);
    Standard_EXPORT void                        ResizeNodes(const Standard_Integer theNbNodes,
                                                            const Standard_Boolean toCopyData = Standard_False);
    Standard_EXPORT void                        ResizeRegions(const Standard_Integer theNbRegions,
                                                              const Standard_Boolean toCopyData = Standard_False);
    Standard_EXPORT void                        ResizeSegments(const Standard_Integer theNbSegments,    
                                                               const Standard_Boolean toCopyData = Standard_False);
    Standard_EXPORT const Handle(PSLG_Segment)& Segment(const Standard_Integer theIndex) const;
    Standard_EXPORT const PSLG_Array1OfSegment& Segments() const;
    Standard_EXPORT PSLG_Array1OfSegment&       Segments();
    Standard_EXPORT void                        SetHole(const Standard_Integer theIndex,
                                                        const Handle(PSLG_Hole)& theHole);
    Standard_EXPORT void                        SetNode(const Standard_Integer theIndex,
                                                        const Handle(PSLG_Node)& theNode);
    Standard_EXPORT void                        SetRegion(const Standard_Integer theIndex,
                                                          const Handle(PSLG_Region)& theRegion);
    Standard_EXPORT void                        SetSegment(const Standard_Integer theIndex, 
                                                           const Handle(PSLG_Segment)& theSegment);

private:

    PSLG_Array1OfHole       myHoles;
    PSLG_Array1OfNode       myNodes;
    PSLG_Array1OfRegion     myRegions;
    PSLG_Array1OfSegment    mySegments;

public:

    DEFINE_STANDARD_RTTIEXT(PSLG_Model, Standard_Transient)

};

#endif // __PSLG_Model_hxx__
