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

# include directories
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${OpenCASCADE_INCLUDE_DIR}
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Gui_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Charts_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/material
    ${CMAKE_CURRENT_SOURCE_DIR}/MaterialCLaw
    ${CMAKE_CURRENT_SOURCE_DIR}/MaterialFLib
    ${CMAKE_CURRENT_SOURCE_DIR}/MCL
    ${CMAKE_CURRENT_SOURCE_DIR}/MCL1d
    ${CMAKE_CURRENT_SOURCE_DIR}/ShapeXS
)

###
# StkBase
###

# linked libraries
set(_linked_libraries
    ${OpenCASCADE_FoundationClasses_LIBRARIES}
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5Charts_LIBRARIES}
)

# headers
set(_headers
    material/material_Elastic.hxx
    material/material_Cable.hxx
    MaterialCLaw/MaterialCLaw_UniaxialPolynomial01.hxx
    MaterialFLib/MaterialFLib_PolynomialCurve.hxx
    MCL/MCL_UniaxialCableMaterial01.hxx
    MCL1d/MCL1d_Cable.hxx
    MCL1d/MCL1d_Elastic.hxx
    MCL1d/MCL1d_Material.hxx
    ShapeXS/ShapeXS_L.hxx
)

# sources
set(_sources
    material/material_Elastic.cxx
    material/material_Cable.cxx
    MaterialCLaw/MaterialCLaw_UniaxialPolynomial01.cxx
    MaterialFLib/MaterialFLib_PolynomialCurve.cxx
    MCL/MCL_UniaxialCableMaterial01.cxx
    MCL1d/MCL1d_Cable.cxx
    MCL1d/MCL1d_Elastic.cxx
    MCL1d/MCL1d_Material.cxx
    ShapeXS/ShapeXS_L.cxx
)

# rules
#add_library(StkBase ${_headers} ${_sources})
add_executable(StkBase ${_headers} ${_sources} Test_Material.cxx)
target_link_libraries(StkBase ${_linked_libraries} Qt5::Charts)
