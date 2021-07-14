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

project(SpartacusCreateCluster)
set(CreateCluster_VERSION_MAJOR 1)
set(CreateCluster_VERSION_MINOR 0)
set(CreateCluster_VERSION_PATCH 0)

###
# Configure
###

# version
configure_file(CreateCluster_Version.hxx.in CreateCluster_Version.hxx)

###
# Rules : Build Core
###

# check for source files
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/FILES)
    message(FATAL_ERROR "Could not locate files for CreateCluster.")
endif()
file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/src/FILES _files)

# loop files, add to sources
unset(_sources)
foreach(_file ${_files})
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/${_file})
        message(FATAL_ERROR "Could not locate file ${_file}.")
    endif()
    list(APPEND _sources ${CMAKE_CURRENT_SOURCE_DIR}/src/${_file})
endforeach()

# check for prerequisites
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/PREREQUISITES)
    message(FATAL_ERROR "Could not locate prerequisites for CreateCluster.")
endif()
file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/src/PREREQUISITES _prerequisites)

# loop prerequisites, find include directories / libraries
unset(_include_directories)
unset(_linked_libraries)
foreach(_prerequisite ${_prerequisites})
    if(NOT ${_prerequisite}_INCLUDE_DIRS)
        message(FATAL_ERROR "Could not locate include directories for prerequisite ${_prerequisite}.")
    endif()
    if(NOT ${_prerequisite}_LIBRARIES)
        message(FATAL_ERROR "Could not locate libraries for prerequisite ${_prerequisite}.")
    endif()
    list(APPEND _include_directories ${${_prerequisite}_INCLUDE_DIRS})
    list(APPEND _linked_libraries ${${_prerequisite}_LIBRARIES})
endforeach()

# setup include directories
unset(CreateCluster_INCLUDE_DIRS CACHE)
set(CreateCluster_INCLUDE_DIRS
    ${_include_directories}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    CACHE PATH "CreateCluster include directories."
)
include_directories(${CreateCluster_INCLUDE_DIRS})

# rules
if(WIN32)
    add_executable(CreateCluster WIN32 ${_sources})
    set_target_properties(CreateCluster PROPERTIES OUTPUT_NAME CreateCluster)
else()
    add_executable(CreateCluster ${_sources})
    set_target_properties(CreateCluster PROPERTIES OUTPUT_NAME spartacus-createcluster)
endif()
target_link_libraries(CreateCluster ${_linked_libraries})
install(
    TARGETS CreateCluster
    DESTINATION ${Spartacus_INSTALL_BINS}
)
