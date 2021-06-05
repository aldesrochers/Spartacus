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
    ${OpenCASCADE_INCLUDE_DIR}
    ${VTK_INCLUDE_DIRS}
)

# linked libraries
set(_linked_libraries
    ${OpenCASCADE_FoundationClasses_LIBRARIES}
    ${OpenCASCADE_ApplicationFramework_LIBRARIES}
)

# headers
set(_headers
    Huygens_DataObject.hxx
    Huygens_Engine.hxx
    Huygens_Export.hxx
    Huygens_ICableAttributes.hxx
    Huygens_IOperations.hxx
    Huygens_IStudyAttributes.hxx
    Huygens_Object.hxx
    Huygens_StudyObject.hxx
    Huygens_Types.hxx
)

# sources
set(_sources
    Huygens_DataObject.cxx
    Huygens_Engine.cxx
    Huygens_ILoadCaseAttributes.hxx
    Huygens_IOperations.cxx
    Huygens_Object.cxx
    Huygens_StudyObject.cxx
)

# rules
add_library(HuygensKernel ${_headers} ${_sources})
target_link_libraries(HuygensKernel ${_linked_libraries})
set_target_properties(HuygensKernel PROPERTIES OUTPUT_NAME Huygens)
install(TARGETS HuygensKernel
    RUNTIME DESTINATION ${Spartacus_INSTALL_BINS}
    ARCHIVE DESTINATION ${Spartacus_INSTALL_LIBS}
    LIBRARY DESTINATION ${Spartacus_INSTALL_LIBS})
