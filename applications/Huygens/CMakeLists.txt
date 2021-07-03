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

project(SpartacusHuygens)
set(Huygens_VERSION_MAJOR 1)
set(Huygens_VERSION_MINOR 0)
set(Huygens_VERSION_PATCH 0)

###
# Configure
###

# version
configure_file(Huygens_Version.hxx.in Huygens_Version.hxx)

###
# Rules : Build documentation
###

# dev
if(Spartacus_BUILD_DOCUMENTATION)
    configure_file(doc/dev/Doxyfile.in doc/dev/Doxyfile)
    execute_process(
        COMMAND ${Doxygen_EXECUTABLE} Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc/dev
        RESULT_VARIABLE _result
        OUTPUT_QUIET
        ERROR_QUIET
    )
    if(NOT ${_result} EQUAL 0)
        message(FATAL_ERROR "Could not generate Huygens developer documentation.")
    endif()
    install(
        DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc/dev/html
        DESTINATION ${Spartacus_INSTALL_DOCS}/dev/Huygens
    )
endif()


###
# Rules : Build Resources
###
qt5_add_resources(_icons res/Icons.qrc)

###
# Rules : Build Core
###

# check for source files
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/FILES)
    message(FATAL_ERROR "Could not locate files for Huygens core.")
endif()
file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/FILES _files)

# loop files, add to sources
unset(_sources)
foreach(_file ${_files})
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/${_file})
        message(FATAL_ERROR "Could not locate file ${_file}.")
    endif()
    list(APPEND _sources ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/${_file})
endforeach()

# check for prerequisites
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/PREREQUISITES)
    message(FATAL_ERROR "Could not locate prerequisites for Huygens application.")
endif()
file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/PREREQUISITES _prerequisites)

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
unset(Huygens_INCLUDE_DIRS CACHE)
set(Huygens_INCLUDE_DIRS
    ${_include_directories}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Core
    CACHE PATH "Huygens include directories."
)
include_directories(${Huygens_INCLUDE_DIRS})

# rules
add_library(HuygensCore ${_sources})
target_link_libraries(HuygensCore ${_linked_libraries})
install(
    TARGETS HuygensCore
    ARCHIVE DESTINATION ${Spartacus_INSTALL_LIBS}
    LIBRARY DESTINATION ${Spartacus_INSTALL_LIBS}
    RUNTIME DESTINATION ${Spartacus_INSTALL_BINS}
)

# expose libraries in cache
unset(Huygens_LIBRARIES CACHE)
set(Huygens_LIBRARIES Huygens CACHE PATH "Huygens libraries.")


###
# Rules : Build Application
###

# check for source files
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/Application/FILES)
    message(FATAL_ERROR "Could not locate files for Huygens application.")
endif()
file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/src/Application/FILES _files)

# loop files, add to sources
unset(_sources)
foreach(_file ${_files})
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/Application/${_file})
        message(FATAL_ERROR "Could not locate file ${_file}.")
    endif()
    list(APPEND _sources ${CMAKE_CURRENT_SOURCE_DIR}/src/Application/${_file})
endforeach()

# check for prerequisites
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/Application/PREREQUISITES)
    message(FATAL_ERROR "Could not locate prerequisites for Huygens application.")
endif()
file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/src/Application/PREREQUISITES _prerequisites)

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
include_directories(
    ${_include_directories}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Application
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Core
)

# rules
if(WIN32)
    add_executable(HuygensApp WIN32 ${_sources} ${_icons})
    target_link_libraries(HuygensApp ${_linked_libraries} HuygensCore)
    set_target_properties(HuygensApp PROPERTIES OUTPUT_NAME Huygens)
else()
    add_executable(HuygensApp ${_sources} ${_icons})
    target_link_libraries(HuygensApp ${_linked_libraries} HuygensCore)
    set_target_properties(HuygensApp PROPERTIES OUTPUT_NAME spartacus-huygens)
endif()
install(TARGETS HuygensApp DESTINATION ${Spartacus_INSTALL_BINS})
