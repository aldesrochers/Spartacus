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
#include <MeshModel_DiscreteEdge.hxx>

// OpenCASCADE
#include <TopoDS.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshModel_DiscreteEdge::MeshModel_DiscreteEdge()    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MeshModel_DiscreteEdge::~MeshModel_DiscreteEdge()    
{
    
}

// ============================================================================
/*!
    \brief DiscreteCurve()
*/
// ============================================================================
const Handle(MeshModel_DiscreteCurve)& MeshModel_DiscreteEdge::DiscreteCurve() const
{
    return myDiscreteCurve;
}

// ============================================================================
/*!
    \brief Edge()
*/
// ============================================================================
const TopoDS_Edge& MeshModel_DiscreteEdge::Edge() const
{
    return TopoDS::Edge(Shape());
}

// ============================================================================
/*!
    \brief SetDiscreteCurve()
*/
// ============================================================================
void MeshModel_DiscreteEdge::SetDiscreteCurve(const Handle(MeshModel_DiscreteCurve)& theDiscreteCurve)
{
    myDiscreteCurve = theDiscreteCurve;
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshModel_DiscreteEdge, MeshModel_DiscreteShape)
IMPLEMENT_STANDARD_RTTIEXT(MeshModel_DiscreteEdge, MeshModel_DiscreteShape)