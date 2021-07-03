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

project(SpartacusTests)

# include directories
include_directories(
    ${OpenCascade_FoundationClasses_INCLUDE_DIRS}
    ${OpenCascade_ModelingData_INCLUDE_DIRS}
    ${OpenCascade_ModelingAlgorithms_INCLUDE_DIRS}
    ${OpenCascade_Visualization_INCLUDE_DIRS}
    ${Qt_Core_INCLUDE_DIRS}
    ${Qt_Gui_INCLUDE_DIRS}
    ${Qt_Widgets_INCLUDE_DIRS}
    ${StkFW_INCLUDE_DIRS}
    ${StkFEM_INCLUDE_DIRS}
    ${StkUI_INCLUDE_DIRS}
    ${Huygens_INCLUDE_DIRS}
)

###
# Test - XSM_BimetallicConductor01
###
if(Spartacus_BUILD_TESTS)
    add_executable(Test_XSM_BimetallicConductor01 Test_XSM_BimetallicConductor01.cxx)
    target_link_libraries(Test_XSM_BimetallicConductor01 ${OpenCascade_FoundationClasses_LIBRARIES} StkFEM)
    install(TARGETS Test_XSM_BimetallicConductor01 DESTINATION ${Spartacus_INSTALL_TESTS})
endif()

###
# Test - CRSA_FindEmptyLength
###
if(Spartacus_BUILD_TESTS)
    add_executable(Test_CRSA_FindEmptyLength Test_CRSA_FindEmptyLength.cxx)
    target_link_libraries(Test_CRSA_FindEmptyLength ${OpenCascade_FoundationClasses_LIBRARIES} StkFEM)
    install(TARGETS Test_CRSA_FindEmptyLength DESTINATION ${Spartacus_INSTALL_TESTS})
endif()

###
# Test - Framework
###
if(Spartacus_BUILD_TESTS)
    add_executable(Test_Framework Test_Framework.cxx)
    target_link_libraries(Test_Framework ${Qt_Core_LIBRARIES} StkFW)
    install(TARGETS Test_Framework DESTINATION ${Spartacus_INSTALL_TESTS})
endif()

###
# Test - Viewer3d
###
if(Spartacus_BUILD_TESTS)
    add_executable(Test_Viewer3d WIN32 Test_Viewer3d.cxx)
    target_link_libraries(Test_Viewer3d
        StkFW StkUI
        ${Qt_Core_LIBRARIES} ${Qt_Gui_LIBRARIES} ${Qt_Widgets_LIBRARIES}
        ${OpenCascade_FoundationClasses_LIBRARIES} ${OpenCascade_Visualization_LIBRARIES}
        ${OpenCascade_ModelingData_LIBRARIES} ${OpenCascade_ModelingAlgorithms_LIBRARIES})
    install(TARGETS Test_Viewer3d DESTINATION ${Spartacus_INSTALL_TESTS})
endif()



