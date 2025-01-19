# =============================================================================
# Copyright (C) 2021-
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# Alexis L. Desrochers (alexisdesrochers@gmail.com)
#
# =============================================================================



# =============================================================================
# Package : Cell
# =============================================================================

set(Cell_PKG_HEADERS
    Cell/Cell_Array1OfEdge.hxx
    Cell/Cell_Edge.hxx
    Cell/Cell_Face.hxx
    Cell/Cell_Polygon.hxx
    Cell/Cell_Shape.hxx
)

set(Cell_PKG_SOURCES
    Cell/Cell_Edge.cxx
    Cell/Cell_Face.cxx
    Cell/Cell_Polygon.cxx
    Cell/Cell_Shape.cxx
)

# =============================================================================
# Package : CellAbs
# =============================================================================

set(CellAbs_PKG_HEADERS
    CellAbs/CellAbs_TypeOfCell.hxx
    CellAbs/CellAbs_TypeOfDimensionality.hxx
    CellAbs/CellAbs_TypeOfInterpolation.hxx
    CellAbs/CellAbs_TypeOfShape.hxx
)

set(CellAbs_PKG_SOURCES

)

# =============================================================================
# Package : cp
# =============================================================================

set(cp_PKG_HEADERS
    cp/cp_Edge.hxx
    cp/cp_Face.hxx
    cp/cp_Line.hxx
    cp/cp_Polygon.hxx
    cp/cp_Triangle.hxx
)

set(cp_PKG_SOURCES
    cp/cp_Edge.cxx
    cp/cp_Face.cxx
    cp/cp_Line.cxx
    cp/cp_Polygon.cxx
    cp/cp_Triangle.cxx
)

# =============================================================================
# Package : Discrete
# =============================================================================

set(Discrete_PKG_HEADERS
    Discrete/Discrete_Shape.hxx
)

set(Discrete_PKG_SOURCES
    Discrete/Discrete_Shape.cxx
)


# =============================================================================
# Package : Mesh
# =============================================================================

set(Mesh_PKG_HEADERS
    Mesh/Mesh_Cell.hxx
    Mesh/Mesh_CellFactory.hxx
    Mesh/Mesh_Object.hxx
    Mesh/Mesh_TypeOfCell.hxx
)

set(Mesh_PKG_SOURCES
    Mesh/Mesh_Cell.cxx
    Mesh/Mesh_CellFactory.cxx
    Mesh/Mesh_Object.cxx
)

# =============================================================================
# Package : Mesh1d
# =============================================================================

set(Mesh1d_PKG_HEADERS
    Mesh1d/Mesh1d_Array1OfCell.hxx
    Mesh1d/Mesh1d_Array1OfPoint.hxx
    Mesh1d/Mesh1d_Builder.hxx
    Mesh1d/Mesh1d_Cell.hxx
    Mesh1d/Mesh1d_Grid.hxx
    Mesh1d/Mesh1d_Object.hxx
    Mesh1d/Mesh1d_Point.hxx
    Mesh1d/Mesh1d_UnstructuredGrid.hxx
)

set(Mesh1d_PKG_SOURCES
    Mesh1d/Mesh1d_Builder.cxx
    Mesh1d/Mesh1d_Cell.cxx
    Mesh1d/Mesh1d_Grid.cxx
    Mesh1d/Mesh1d_Object.cxx
    Mesh1d/Mesh1d_Point.cxx
    Mesh1d/Mesh1d_UnstructuredGrid.cxx
)

# =============================================================================
# Package : Mesh2d
# =============================================================================

set(Mesh2d_PKG_HEADERS
    Mesh2d/Mesh2d.hxx
    Mesh2d/Mesh2d_Array1OfCell.hxx
    Mesh2d/Mesh2d_Array1OfNode.hxx
    Mesh2d/Mesh2d_Cell.hxx
    Mesh2d/Mesh2d_CellFactory.hxx
    Mesh2d/Mesh2d_Grid.hxx
    Mesh2d/Mesh2d_Node.hxx
    Mesh2d/Mesh2d_TypeOfCell.hxx
)

set(Mesh2d_PKG_SOURCES
    Mesh2d/Mesh2d.cxx
    Mesh2d/Mesh2d_Cell.cxx
    Mesh2d/Mesh2d_CellFactory.cxx
    Mesh2d/Mesh2d_Grid.cxx
    Mesh2d/Mesh2d_Node.cxx
)

# =============================================================================
# Package : MeshAbs
# =============================================================================

set(MeshAbs_PKG_HEADERS
    MeshAbs/MeshAbs_TypeOfObject.hxx
)

set(MeshAbs_PKG_SOURCES

)

# =============================================================================
# Package : MeshAdaptor
# =============================================================================

set(MeshAdaptor_PKG_HEADERS
    MeshAdaptor/MeshAdaptor_Point.hxx
)

set(MeshAbs_PKG_SOURCES
    MeshAdaptor/MeshAdaptor_Point.cxx
)

# =============================================================================
# Package : MeshAlgo
# =============================================================================

set(MeshAlgo_PKG_HEADERS
    MeshAlgo/MeshAlgo_Algorithm.hxx
    MeshAlgo/MeshAlgo_EdgeTessellator.hxx
    MeshAlgo/MeshAlgo_Tessellator.hxx
    MeshAlgo/MeshAlgo_UniformAbscissaTessellator.hxx
)

set(MeshAlgo_PKG_SOURCES
    MeshAlgo/MeshAlgo_Algorithm.cxx
    MeshAlgo/MeshAlgo_EdgeTessellator.cxx
    MeshAlgo/MeshAlgo_Tessellator.cxx
    MeshAlgo/MeshAlgo_UniformAbscissaTessellator.cxx
)

# =============================================================================
# Package : MeshBuilder
# =============================================================================

set(MeshBuilder_PKG_HEADERS
    MeshBuilder/MeshBuilder_CellFactory.hxx
    MeshBuilder/MeshBuilder_Command.hxx
    MeshBuilder/MeshBuilder_MakeMesh1d.hxx
    MeshBuilder/MeshBuilder_MakeObject.hxx
)

set(MeshBuilder_PKG_SOURCES
    MeshBuilder/MeshBuilder_CellFactory.cxx
    MeshBuilder/MeshBuilder_Command.cxx
    MeshBuilder/MeshBuilder_MakeMesh1d.cxx
    MeshBuilder/MeshBuilder_MakeObject.cxx
)

# =============================================================================
# Package : MeshDS
# =============================================================================

set(MeshDS_PKG_HEADERS
    MeshDS/MeshDS.hxx
    MeshDS/MeshDS_Array1OfObject.hxx
    MeshDS/MeshDS_Builder.hxx
    MeshDS/MeshDS_Cell.hxx
    MeshDS/MeshDS_Group.hxx
    MeshDS/MeshDS_Mesh.hxx
    MeshDS/MeshDS_Object.hxx
    MeshDS/MeshDS_Point.hxx
    MeshDS/MeshDS_Point1d.hxx
    MeshDS/MeshDS_Point2d.hxx
    MeshDS/MeshDS_Point3d.hxx
    MeshDS/MeshDS_TCell.hxx
    MeshDS/MeshDS_TEdge.hxx
    MeshDS/MeshDS_TFace.hxx
    MeshDS/MeshDS_TGroup.hxx
    MeshDS/MeshDS_TMesh.hxx
    MeshDS/MeshDS_TObject.hxx
    MeshDS/MeshDS_Tool.hxx
    MeshDS/MeshDS_TVertex.hxx
    MeshDS/MeshDS_Vertex.hxx
)

set(MeshDS_PKG_SOURCES
    MeshDS/MeshDS.cxx
    MeshDS/MeshDS_Builder.cxx
    MeshDS/MeshDS_Cell.cxx
    MeshDS/MeshDS_Group.cxx
    MeshDS/MeshDS_Mesh.cxx
    MeshDS/MeshDS_Object.cxx
    MeshDS/MeshDS_Point.cxx
    MeshDS/MeshDS_Point1d.cxx
    MeshDS/MeshDS_Point2d.cxx
    MeshDS/MeshDS_Point3d.cxx
    MeshDS/MeshDS_TCell.cxx
    MeshDS/MeshDS_TEdge.cxx
    MeshDS/MeshDS_TFace.cxx
    MeshDS/MeshDS_TGroup.cxx
    MeshDS/MeshDS_TMesh.cxx
    MeshDS/MeshDS_TObject.cxx
    MeshDS/MeshDS_Tool.cxx
    MeshDS/MeshDS_TVertex.cxx
    MeshDS/MeshDS_Vertex.cxx
)

# =============================================================================
# Package : MeshGen
# =============================================================================

set(MeshGen_PKG_HEADERS
    MeshGen/MeshGen_Algorithm.hxx
    MeshGen/MeshGen_Context.hxx
    MeshGen/MeshGen_CurveTessellator.hxx
    MeshGen/MeshGen_Edge.hxx
    MeshGen/MeshGen_MeshBuilder.hxx
    MeshGen/MeshGen_Shape.hxx
    MeshGen/MeshGen_UniformAbscissaTessellator.hxx
)

set(MeshGen_PKG_SOURCES
    MeshGen/MeshGen_Algorithm.cxx
    MeshGen/MeshGen_Context.cxx
    MeshGen/MeshGen_CurveTessellator.cxx
    MeshGen/MeshGen_Edge.cxx
    MeshGen/MeshGen_MeshBuilder.cxx
    MeshGen/MeshGen_Shape.cxx
    MeshGen/MeshGen_UniformAbscissaTessellator.cxx
)

# =============================================================================
# Package : MeshGen
# =============================================================================

set(MeshModel_PKG_HEADERS
    MeshModel/MeshModel_Curve.hxx
    MeshModel/MeshModel_Edge.hxx
    MeshModel/MeshModel_Face.hxx
    MeshModel/MeshModel_Shape.hxx
    MeshModel/MeshModel_Wire.hxx
)

set(MeshModel_PKG_SOURCES
    MeshModel/MeshModel_Curve.cxx
    MeshModel/MeshModel_Edge.cxx
    MeshModel/MeshModel_Face.cxx
    MeshModel/MeshModel_Shape.cxx
    MeshModel/MeshModel_Wire.cxx
)

# =============================================================================
# Package : MeshTools
# =============================================================================

set(MeshTools_PKG_HEADERS
    MeshTools/MeshTools_Array1OfObject.hxx
    MeshTools/MeshTools_DataMapIteratorOfDataMapOfIntegerObject.hxx
    MeshTools/MeshTools_DataMapOfIntegerObject.hxx
    MeshTools/MeshTools_IndexedMapOfObject.hxx
    MeshTools/MeshTools_ListIteratorOfListOfObject.hxx
    MeshTools/MeshTools_ListOfObject.hxx
    MeshTools/MeshTools_ObjectMapHasher.hxx
    MeshTools/MeshTools_SequenceOfObject.hxx
)

set(MeshTools_PKG_SOURCES
    MeshTools/MeshTools_ObjectMapHasher.cxx
)

# =============================================================================
# Package : mp
# =============================================================================

set(mp_PKG_HEADERS
    mp/mp_Line2N.hxx
    mp/mp_Line2N1d.hxx
    mp/mp_Line2N2d.hxx
)

set(mp_PKG_SOURCES
    mp/mp_Line2N.cxx
    mp/mp_Line2N1d.cxx
    mp/mp_Line2N2d.cxx
)

# =============================================================================
# Package : mp
# =============================================================================

set(mp_PKG_HEADERS
    mp/mp_Line2N.hxx
    mp/mp_Line2N1d.hxx
    mp/mp_Line2N2d.hxx
)

set(mp_PKG_SOURCES
    mp/mp_Line2N.cxx
    mp/mp_Line2N1d.cxx
    mp/mp_Line2N2d.cxx
)

# =============================================================================
# Package : PLC
# =============================================================================

set(PLC_PKG_HEADERS
    PLC/PLC_Array1OfNode.hxx
    PLC/PLC_Facet.hxx
    PLC/PLC_Model.hxx
    PLC/PLC_Node.hxx
    PLC/PLC_Polygon.hxx
    PLC/PLC_Segment.hxx
)

set(PLC_PKG_SOURCES
    PLC/PLC_Facet.cxx
    PLC/PLC_Model.cxx
    PLC/PLC_Node.cxx
    PLC/PLC_Polygon.cxx
    PLC/PLC_Segment.cxx
)

# =============================================================================
# Package : PSLG
# =============================================================================

set(PSLG_PKG_HEADERS
    PSLG/PSLG_Array1OfHole.hxx
    PSLG/PSLG_Array1OfNode.hxx
    PSLG/PSLG_Array1OfRegion.hxx
    PSLG/PSLG_Array1OfSegment.hxx
    PSLG/PSLG_Hole.hxx
    PSLG/PSLG_Model.hxx
    PSLG/PSLG_Node.hxx
    PSLG/PSLG_Region.hxx
    PSLG/PSLG_Segment.hxx
)

set(PSLG_PKG_SOURCES
    PSLG/PSLG_Hole.cxx
    PSLG/PSLG_Model.cxx
    PSLG/PSLG_Node.cxx
    PSLG/PSLG_Region.cxx
    PSLG/PSLG_Segment.cxx
)


# =============================================================================
# Package : Triangle
# =============================================================================

set(Triangle_PKG_HEADERS
    Triangle/Triangle.hxx
    Triangle/Triangle_Error.hxx
    Triangle/Triangle_Parameters.hxx
    Triangle/Triangle_Triangulate.hxx
    Triangle/Triangle_TypeOfAlgorithm.hxx
)

set(Triangle_PKG_SOURCES
    Triangle/Triangle.cxx
    Triangle/Triangle_Parameters.cxx
    Triangle/Triangle_Triangulate.cxx
)



# =============================================================================
# Library : Venus
# =============================================================================

set(Venus_INCLUDE_DIRS
    ${CGAL_INCLUDE_DIR}
    ${OpenCASCADE_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Cell
    ${CMAKE_CURRENT_SOURCE_DIR}/Discrete
    ${CMAKE_CURRENT_SOURCE_DIR}/Mesh2d
    ${CMAKE_CURRENT_SOURCE_DIR}/MeshAlgo
    ${CMAKE_CURRENT_SOURCE_DIR}/MeshGen
    ${CMAKE_CURRENT_SOURCE_DIR}/MeshModel
    ${CMAKE_CURRENT_SOURCE_DIR}/PLC
    ${CMAKE_CURRENT_SOURCE_DIR}/PSLG
    ${CMAKE_CURRENT_SOURCE_DIR}/Triangle
)

set(Venus_LINKED_LIBRARIES
    ${CGAL_LIBRARIES}
    ${OpenCASCADE_LIBRARIES}
    Apollo
    tetgen
    triangle 
)

set(Venus_HEADERS
    ${Cell_PKG_HEADERS}
    ${Discrete_PKG_HEADERS}
    ${Mesh2d_PKG_HEADERS}
    ${MeshAlgo_PKG_HEADERS}
    ${MeshGen_PKG_HEADERS}
    ${MeshModel_PKG_HEADERS}
    ${PLC_PKG_HEADERS}
    ${PSLG_PKG_HEADERS}
    ${Triangle_PKG_HEADERS}
)

set(Venus_SOURCES
    ${Cell_PKG_SOURCES}
    ${Discrete_PKG_SOURCES}
    ${Mesh2d_PKG_SOURCES}
    ${MeshAlgo_PKG_SOURCES}
    ${MeshGen_PKG_SOURCES}
    ${MeshModel_PKG_SOURCES}
    ${PLC_PKG_SOURCES}
    ${PSLG_PKG_SOURCES}
    ${Triangle_PKG_SOURCES}
)

add_library(Venus SHARED ${Venus_HEADERS} ${Venus_SOURCES})
target_include_directories(Venus PUBLIC ${Venus_INCLUDE_DIRS})
target_link_libraries(Venus PUBLIC ${Venus_LINKED_LIBRARIES})