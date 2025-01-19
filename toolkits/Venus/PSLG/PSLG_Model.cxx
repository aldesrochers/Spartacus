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
#include <PSLG_Model.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Model::PSLG_Model()    
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Model::PSLG_Model(const Standard_Integer theNbNodes,
                       const Standard_Integer theNbSegments)
{
    ResizeNodes(theNbNodes);
    ResizeSegments(theNbSegments);
}


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Model::PSLG_Model(const Standard_Integer theNbNodes,
                       const Standard_Integer theNbSegments,   
                       const Standard_Integer theNbHoles,
                       const Standard_Integer theNbRegions)
{
    ResizeNodes(theNbNodes);
    ResizeSegments(theNbSegments);
    ResizeHoles(theNbHoles);
    ResizeRegions(theNbRegions);
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Model::PSLG_Model(const PSLG_Array1OfNode& theNodes,
                       const PSLG_Array1OfSegment& theSegments)
    : myNodes(theNodes), 
    mySegments(theSegments)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
PSLG_Model::PSLG_Model(const PSLG_Array1OfNode& theNodes,
                       const PSLG_Array1OfSegment& theSegments,
                       const PSLG_Array1OfHole& theHoles,
                       const PSLG_Array1OfRegion& theRegions)
    : myNodes(theNodes), 
    mySegments(theSegments), 
    myHoles(theHoles), 
    myRegions(theRegions)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
PSLG_Model::~PSLG_Model()    
{
    
}

// ============================================================================
/*!
    \brief Hole()
*/
// ============================================================================
const Handle(PSLG_Hole)& PSLG_Model::Hole(const Standard_Integer theIndex) const
{
    return myHoles.Value(theIndex);
}

// ============================================================================
/*!
    \brief Holes()
*/
// ============================================================================
const PSLG_Array1OfHole& PSLG_Model::Holes() const
{
    return myHoles;
}


// ============================================================================
/*!
    \brief Holes()
*/
// ============================================================================
PSLG_Array1OfHole& PSLG_Model::Holes()
{
    return myHoles;
}

// ============================================================================
/*!
    \brief Node()
*/
// ============================================================================
const Handle(PSLG_Node)& PSLG_Model::Node(const Standard_Integer theIndex) const
{
    return myNodes.Value(theIndex);
}

// ============================================================================
/*!
    \brief NbHoles()
*/
// ============================================================================
Standard_Integer PSLG_Model::NbHoles() const
{
    return myHoles.Size();
}

// ============================================================================
/*!
    \brief NbNodes()
*/
// ============================================================================
Standard_Integer PSLG_Model::NbNodes() const
{
    return myNodes.Size();
}

// ============================================================================
/*!
    \brief NbRegions()
*/
// ============================================================================
Standard_Integer PSLG_Model::NbRegions() const
{
    return myRegions.Size();
}

// ============================================================================
/*!
    \brief NbSegments()
*/
// ============================================================================
Standard_Integer PSLG_Model::NbSegments() const
{
    return mySegments.Size();
}

// ============================================================================
/*!
    \brief Nodes()
*/
// ============================================================================
const PSLG_Array1OfNode& PSLG_Model::Nodes() const
{
    return myNodes;
}


// ============================================================================
/*!
    \brief Nodes()
*/
// ============================================================================
PSLG_Array1OfNode& PSLG_Model::Nodes()
{
    return myNodes;
}

// ============================================================================
/*!
    \brief Region()
*/
// ============================================================================
const Handle(PSLG_Region)& PSLG_Model::Region(const Standard_Integer theIndex) const
{
    return myRegions.Value(theIndex);
}

// ============================================================================
/*!
    \brief Regions()
*/
// ============================================================================
const PSLG_Array1OfRegion& PSLG_Model::Regions() const
{
    return myRegions;
}


// ============================================================================
/*!
    \brief Regions()
*/
// ============================================================================
PSLG_Array1OfRegion& PSLG_Model::Regions()
{
    return myRegions;
}

// ============================================================================
/*!
    \brief ResizeHoles()
*/
// ============================================================================
void PSLG_Model::ResizeHoles(const Standard_Integer theNbHoles,
                             const Standard_Boolean toCopyData)
{
    myHoles.Resize(1, theNbHoles, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeNodes()
*/
// ============================================================================
void PSLG_Model::ResizeNodes(const Standard_Integer theNbNodes,
                             const Standard_Boolean toCopyData)
{
    myNodes.Resize(1, theNbNodes, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeRegions()
*/
// ============================================================================
void PSLG_Model::ResizeRegions(const Standard_Integer theNbRegions,
                               const Standard_Boolean toCopyData)
{
    myRegions.Resize(1, theNbRegions, toCopyData);
}

// ============================================================================
/*!
    \brief ResizeSegments()
*/
// ============================================================================
void PSLG_Model::ResizeSegments(const Standard_Integer theNbSegments,
                                const Standard_Boolean toCopyData)
{
    mySegments.Resize(1, theNbSegments, toCopyData);
}

// ============================================================================
/*!
    \brief Segment()
*/
// ============================================================================
const Handle(PSLG_Segment)& PSLG_Model::Segment(const Standard_Integer theIndex) const
{
    return mySegments.Value(theIndex);
}

// ============================================================================
/*!
    \brief Segments()
*/
// ============================================================================
const PSLG_Array1OfSegment& PSLG_Model::Segments() const
{
    return mySegments;
}

// ============================================================================
/*!
    \brief Segments()
*/
// ============================================================================
PSLG_Array1OfSegment& PSLG_Model::Segments()
{
    return mySegments;
}

// ============================================================================
/*!
    \brief SetHole()
*/
// ============================================================================
void PSLG_Model::SetHole(const Standard_Integer theIndex,
                         const Handle(PSLG_Hole)& theHole)
{
    myHoles.SetValue(theIndex, theHole);
}

// ============================================================================
/*!
    \brief SetNode()
*/
// ============================================================================
void PSLG_Model::SetNode(const Standard_Integer theIndex,
                         const Handle(PSLG_Node)& theNode)
{
    myNodes.SetValue(theIndex, theNode);
}

// ============================================================================
/*!
    \brief SetRegion()
*/
// ============================================================================
void PSLG_Model::SetRegion(const Standard_Integer theIndex,
                           const Handle(PSLG_Region)& theRegion)
{
    myRegions.SetValue(theIndex, theRegion);
}   

// ============================================================================
/*!
    \brief SetSegment()
*/
// ============================================================================
void PSLG_Model::SetSegment(const Standard_Integer theIndex,
                            const Handle(PSLG_Segment)& theSegment)
{
    mySegments.SetValue(theIndex, theSegment);
}

// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(PSLG_Model, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(PSLG_Model, Standard_Transient)