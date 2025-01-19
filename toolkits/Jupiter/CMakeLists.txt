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
# Package : CM
# =============================================================================

set(CM_PKG_HEADERS
    CM/CM_Model.hxx
)

set(CM_PKG_SOURCES
    CM/CM_Model.cxx
)

# =============================================================================
# Package : Mech1d
# =============================================================================

set(Mech1d_PKG_HEADERS
    Mech1d/Mech1d_ElasticTruss.hxx
    Mech1d/Mech1d_Element.hxx
    Mech1d/Mech1d_Truss.hxx
)

set(Mech1d_PKG_SOURCES
    Mech1d/Mech1d_ElasticTruss.cxx
    Mech1d/Mech1d_Element.cxx
    Mech1d/Mech1d_Truss.cxx
)


# =============================================================================
# Library : Jupiter
# =============================================================================

set(Jupiter_INCLUDE_DIRS
    ${OpenCASCADE_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/CM
    ${CMAKE_CURRENT_SOURCE_DIR}/Mech1d
)

set(Jupiter_LINKED_LIBRARIES
    ${OpenCASCADE_LIBRARIES}
    Apollo
)

set(Jupiter_HEADERS
    ${CM_PKG_HEADERS}
    ${Mech1d_PKG_HEADERS}
)

set(Jupiter_SOURCES
    ${CM_PKG_SOURCES}
    ${Mech1d_PKG_SOURCES}
)

add_library(Jupiter SHARED ${Jupiter_HEADERS} ${Jupiter_SOURCES})
target_include_directories(Jupiter PUBLIC ${Jupiter_INCLUDE_DIRS})
target_link_libraries(Jupiter PUBLIC ${Jupiter_LINKED_LIBRARIES})