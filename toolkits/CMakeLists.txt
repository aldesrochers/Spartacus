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
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${OpenCASCADE_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/cable
    ${CMAKE_CURRENT_SOURCE_DIR}/FE
    ${CMAKE_CURRENT_SOURCE_DIR}/MCL
    ${CMAKE_CURRENT_SOURCE_DIR}/MCL1d
    ${CMAKE_CURRENT_SOURCE_DIR}/RS
    ${CMAKE_CURRENT_SOURCE_DIR}/XSM
)

###
# StkFEData
###

set(StkFEData_LinkedLibraries
    ${OpenCASCADE_FoundationClasses_LIBRARIES}
)

set(StkFEData_Headers
    cable/cable_SpanGeometry.hxx
    FE/FE_Domain.hxx
    FE/FE_Node.hxx
    MCL/MCL_Material.hxx
    MCL1d/MCL1d_Elastic.hxx
    MCL1d/MCL1d_Material.hxx
    RS/RS_SaggingAnalysis.hxx
    RS/RS_SpanGeometry.hxx
    XSM/XSM_Generic.hxx
    XSM/XSM_Section.hxx
)

set(StkFEData_Sources
    cable/cable_SpanGeometry.cxx
    FE/FE_Domain.cxx
    FE/FE_Node.cxx
    MCL/MCL_Material.cxx
    MCL1d/MCL1d_Elastic.cxx
    MCL1d/MCL1d_Material.cxx
    RS/RS_SaggingAnalysis.cxx
    RS/RS_SpanGeometry.cxx
    XSM/XSM_Generic.cxx
    XSM/XSM_Section.cxx
)

add_library(StkFEData ${StkFEData_Headers} ${StkFEData_Sources})
target_link_libraries(StkFEData ${StkFEData_LinkedLibraries})
