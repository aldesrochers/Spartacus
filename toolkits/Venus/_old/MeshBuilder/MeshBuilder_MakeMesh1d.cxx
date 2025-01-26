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
#include <MeshBuilder_MakeMesh1d.hxx>
#include <MeshDS.hxx>
#include <MeshDS_Builder.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
MeshBuilder_MakeMesh1d::MeshBuilder_MakeMesh1d()
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
MeshBuilder_MakeMesh1d::~MeshBuilder_MakeMesh1d()
{

}

// ============================================================================
/*!
 *  \brief MakeLinearLine()
*/
// ============================================================================
void MeshBuilder_MakeMesh1d::MakeLinearLine(const Standard_Integer theIndex,
                                            const Standard_Integer theVertex1,
                                            const Standard_Integer theVertex2)
{
    MeshDS_Builder aBuilder;
    MeshDS_Cell aCell;

    // get vertices
    MeshDS_Vertex aVertex1 = MeshDS::Vertex(myVertices(theVertex1));
    MeshDS_Vertex aVertex2 = MeshDS::Vertex(myVertices(theVertex2));

    // get points
    gp_Pnt1d aPoint1 = MeshAdaptor_Point(aVertex1).Point1d();
    gp_Pnt1d aPoint2 = MeshAdaptor_Point(aVertex2).Point1d();

    // make cell
    


}

// ============================================================================
/*!
 *  \brief MakeVertex()
*/
// ============================================================================
void MeshBuilder_MakeMesh1d::MakeVertex(const Standard_Integer theIndex,
                                        const gp_Pnt1d& thePoint)
{
    MeshDS_Builder aBuilder;
    MeshDS_Vertex aVertex;
    aBuilder.MakeVertex(aVertex, thePoint);
    myVertices.Bind(theIndex, aVertex);
}

// ============================================================================
/*!
 *  \brief Mesh()
*/
// ============================================================================
const MeshDS_Mesh& MeshBuilder_MakeMesh1d::Mesh()
{
    return MeshDS::Mesh(Object());
}

// ============================================================================
/*!
 *  \brief operator Mesh1dDS_Mesh()
*/
// ============================================================================
MeshBuilder_MakeMesh1d::operator MeshDS_Mesh()
{
    return Mesh();
}
