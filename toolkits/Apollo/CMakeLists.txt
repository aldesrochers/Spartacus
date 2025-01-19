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
# Package : gp
# =============================================================================

set(gp_PKG_HEADERS
    gp/gp_Catenary.hxx
    gp/gp_Catenary2d.hxx
    gp/gp_Pnt1d.hxx
)

set(gp_PKG_SOURCES
    gp/gp_Catenary.cxx
    gp/gp_Catenary2d.cxx
    gp/gp_Pnt1d.cxx
)

# =============================================================================
# Package : TColgp
# =============================================================================

set(TColgp_PKG_HEADERS
    TColgp/TColgp_Array1OfPnt1d.hxx
)

set(TColgp_PKG_SOURCES

)



# =============================================================================
# Library : Apollo
# =============================================================================

set(Apollo_INCLUDE_DIRS
    ${OpenCASCADE_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/gp
    ${CMAKE_CURRENT_SOURCE_DIR}/TColgp
)

set(Apollo_LINKED_LIBRARIES
    ${OpenCASCADE_LIBRARIES}
)

set(Apollo_HEADERS
    ${gp_PKG_HEADERS}
    ${TColgp_PKG_HEADERS}
)

set(Apollo_SOURCES
    ${gp_PKG_SOURCES}
    ${TColgp_PKG_SOURCES}
)

add_library(Apollo SHARED ${Apollo_HEADERS} ${Apollo_SOURCES})
target_include_directories(Apollo PUBLIC ${Apollo_INCLUDE_DIRS})
target_link_libraries(Apollo ${Apollo_LINKED_LIBRARIES})

#install(TARGETS Apollo DESTINATION lib)