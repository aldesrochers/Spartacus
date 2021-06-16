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
    ${CMAKE_CURRENT_SOURCE_DIR}/matp
    ${CMAKE_CURRENT_SOURCE_DIR}/UCrM
    ${CMAKE_CURRENT_SOURCE_DIR}/UThM
    ${CMAKE_CURRENT_SOURCE_DIR}/UMM
    ${CMAKE_CURRENT_SOURCE_DIR}/USSM
    ${CMAKE_CURRENT_SOURCE_DIR}/XSM
)

###
# StkFEData
###

set(StkFEData_LinkedLibraries
    ${OpenCASCADE_FoundationClasses_LIBRARIES}
)

set(StkFEData_Headers
    CRSA/CRSA_Command.hxx
    CRSA/CRSA_Error.hxx
    CRSA/CRSA_FindEmptyLength.hxx
    CRSA/CRSA_LoadCase.hxx
    CRSA/CRSA_SequenceOfLoadCase.hxx
    CRSA/CRSA_SpanGeometry.hxx
    FE/FE_Domain.hxx
    FE/FE_Node.hxx
    FLib/FLib_Catenary.hxx
    matp/matp_CableWireCreep01.hxx
    matp/matp_Elastic.hxx
    matp/matp_WireStressStrain01.hxx
    UCrM/UCrM_CableWire01.hxx
    UCrM/UCrM_Model.hxx
    UThM/UThM_BiLinear.hxx
    UThM/UThM_Model.hxx
    UThM/UThM_Linear.hxx
    UMM/UMM_CableWire01.hxx
    UMM/UMM_Elastic.hxx
    UMM/UMM_Model.hxx
    USSM/USSM_CableWire01.hxx
    USSM/USSM_CableWire02.hxx
    USSM/USSM_Elastic.hxx
    USSM/USSM_Model.hxx
    XSM/XSM_Elastic.hxx
    XSM/XSM_Model.hxx
)

set(StkFEData_Sources
    CRSA/CRSA_Command.cxx
    CRSA/CRSA_FindEmptyLength.cxx
    CRSA/CRSA_LoadCase.cxx
    CRSA/CRSA_SpanGeometry.cxx
    FE/FE_Domain.cxx
    FE/FE_Node.cxx
    FLib/FLib_Catenary.cxx
    matp/matp_CableWireCreep01.cxx
    matp/matp_Elastic.cxx
    matp/matp_WireStressStrain01.cxx
    UCrM/UCrM_CableWire01.cxx
    UCrM/UCrM_Model.cxx
    UThM/UThM_BiLinear.cxx
    UThM/UThM_Model.cxx
    UThM/UThM_Linear.cxx
    UMM/UMM_CableWire01.cxx
    UMM/UMM_Elastic.cxx
    UMM/UMM_Model.cxx
    USSM/USSM_CableWire01.cxx
    USSM/USSM_CableWire02.cxx
    USSM/USSM_Elastic.cxx
    USSM/USSM_Model.cxx
    XSM/XSM_Elastic.cxx
    XSM/XSM_Model.cxx
)

#add_library(StkFEData ${StkFEData_Headers} ${StkFEData_Sources})
add_executable(StkFEData ${StkFEData_Headers} ${StkFEData_Sources} Tests/Test_SaggingAnalysis.cxx)
target_link_libraries(StkFEData ${StkFEData_LinkedLibraries})
