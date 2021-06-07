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
    ${CMAKE_CURRENT_SOURCE_DIR}/CRSA
    ${CMAKE_CURRENT_SOURCE_DIR}/FE
    ${CMAKE_CURRENT_SOURCE_DIR}/FLib
    ${CMAKE_CURRENT_SOURCE_DIR}/UMM
    ${CMAKE_CURRENT_SOURCE_DIR}/XSM
)

###
# StkFEData
###

set(StkFEData_LinkedLibraries
    ${OpenCASCADE_FoundationClasses_LIBRARIES}
)

set(StkFEData_Headers
    CRSA/CRSA_Error.hxx
    CRSA/CRSA_LoadCase.hxx
    CRSA/CRSA_SaggingAnalysis.hxx
    CRSA/CRSA_SaggingCondition.hxx
    CRSA/CRSA_SpanGeometry.hxx
    FE/FE_Domain.hxx
    FE/FE_Node.hxx
    FLib/FLib_Catenary.hxx
    UMM/UMM_Model.hxx
    XSM/XSM_Elastic.hxx
    XSM/XSM_Model.hxx
)

set(StkFEData_Sources
    CRSA/CRSA_LoadCase.cxx
    CRSA/CRSA_SaggingAnalysis.cxx
    CRSA/CRSA_SaggingCondition.cxx
    CRSA/CRSA_SpanGeometry.cxx
    FE/FE_Domain.cxx
    FE/FE_Node.cxx
    FLib/FLib_Catenary.cxx
    UMM/UMM_Model.cxx
    XSM/XSM_Elastic.cxx
    XSM/XSM_Model.cxx
)

#add_library(StkFEData ${StkFEData_Headers} ${StkFEData_Sources})
add_executable(StkFEData ${StkFEData_Headers} ${StkFEData_Sources} Tests/Test_SaggingAnalysis.cxx)
target_link_libraries(StkFEData ${StkFEData_LinkedLibraries})
