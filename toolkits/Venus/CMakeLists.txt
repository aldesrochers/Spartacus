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

Spartacus_FIND_PACKAGE_FILES(${CMAKE_CURRENT_SOURCE_DIR}/MeshModel MeshModel_PKG_HEADERS MeshModel_PKG_SOURCES)
Spartacus_FIND_PACKAGE_FILES(${CMAKE_CURRENT_SOURCE_DIR}/Tetgen Tetgen_PKG_HEADERS Tetgen_PKG_SOURCES)
Spartacus_FIND_PACKAGE_FILES(${CMAKE_CURRENT_SOURCE_DIR}/Triangle Triangle_PKG_HEADERS Triangle_PKG_SOURCES)




# =============================================================================
# Library : Venus
# =============================================================================

set(Venus_INCLUDE_DIRS
    ${OpenCASCADE_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/MeshModel
    ${CMAKE_CURRENT_SOURCE_DIR}/Tetgen
    ${CMAKE_CURRENT_SOURCE_DIR}/Triangle
)

set(Venus_LINKED_LIBRARIES
    ${OpenCASCADE_LIBRARIES}
    Apollo
    tetgen
    triangle 
)

set(Venus_HEADERS
    ${MeshModel_PKG_HEADERS}
    ${Tetgen_PKG_HEADERS}
    ${Triangle_PKG_HEADERS}
)

set(Venus_SOURCES
    ${MeshModel_PKG_SOURCES}
    ${Tetgen_PKG_SOURCES}
    ${Triangle_PKG_SOURCES}
)

add_library(Venus SHARED ${Venus_HEADERS} ${Venus_SOURCES})
target_include_directories(Venus PUBLIC ${Venus_INCLUDE_DIRS})
target_link_libraries(Venus PUBLIC ${Venus_LINKED_LIBRARIES})