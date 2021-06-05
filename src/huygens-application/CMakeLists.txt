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
    ${OpenCASCADE_INCLUDE_DIR}
    ${VTK_INCLUDE_DIRS}
)

# linked libraries
set(_linked_libraries
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${OpenCASCADE_FoundationClasses_LIBRARIES}
    ${OpenCASCADE_ApplicationFramework_LIBRARIES}
)

# headers
set(_headers
    Huygens_Desktop.hxx
)

# sources
set(_sources
    Huygens_Desktop.cxx
    Huygens_Main.cxx
)

# rules
if(WIN32)
    add_executable(HuygensApp WIN32 ${_headers} ${_sources})
else()
    add_executable(HuygensApp ${_headers} ${_sources})
endif()
target_link_libraries(HuygensApp ${_linked_libraries})
if(WIN32)
    set_target_properties(HuygensApp PROPERTIES OUTPUT_NAME Spartacus-Huygens)
else()
    set_target_properties(HuygensApp PROPERTIES OUTPUT_NAME spartacus-huygens)
endif()
install(TARGETS HuygensApp DESTINATION ${Spartacus_INSTALL_BINS})
