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
    ${PROJECT_BINARY_DIR}
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Gui_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Sql_INCLUDE_DIRS}
    ${OpenCASCADE_INCLUDE_DIR}
    ${VTK_INCLUDE_DIRS}
)

# linked libraries
set(_linked_libraries
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5Sql_LIBRARIES}
    ${OpenCASCADE_FoundationClasses_LIBRARIES}
    ${OpenCASCADE_ApplicationFramework_LIBRARIES}
)

# headers
set(_headers
    Huygens_AboutDialog.hxx
    Huygens_DataObject.hxx
    Huygens_Desktop.hxx
    Huygens_Dialog.hxx
    Huygens_Engine.hxx
    Huygens_Export.hxx
    #Huygens_IAnalysisOperations.hxx
    Huygens_ICableAttributes.hxx
    #Huygens_ICableOperations.hxx
    #Huygens_ILoadCaseOperations.hxx
    Huygens_IOperations.hxx
    Huygens_IStudyAttributes.hxx
    #Huygens_IStudyOperations.hxx
    Huygens_Object.hxx
    Huygens_StudyObject.hxx
    Huygens_TreeView.hxx
    Huygens_Types.hxx
)

# sources
set(_sources
    Huygens_AboutDialog.cxx
    Huygens_DataObject.cxx
    Huygens_Desktop.cxx
    Huygens_Dialog.cxx
    Huygens_Engine.cxx
    Huygens_Main.cxx
    #Huygens_IAnalysisOperations.cxx
    #Huygens_ICableOperations.cxx
    Huygens_ILoadCaseAttributes.hxx
    #Huygens_ILoadCaseOperations.cxx
    Huygens_IOperations.cxx
    Huygens_Object.cxx
    Huygens_StudyObject.cxx
    #Huygens_IStudyOperations.cxx
    Huygens_TreeView.cxx
)

# rules
if(WIN32)
    add_executable(Huygens WIN32 ${_headers} ${_sources})
else()
    add_executable(Huygens ${_headers} ${_sources})
endif()
target_link_libraries(Huygens ${_linked_libraries})
if(WIN32)
    set_target_properties(Huygens PROPERTIES OUTPUT_NAME Huygens)
else()
    set_target_properties(Huygens PROPERTIES OUTPUT_NAME spartacus-huygens)
endif()
install(TARGETS Huygens DESTINATION ${Spartacus_INSTALL_BINS})
