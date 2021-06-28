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

project(SpartacusToolkits)

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
        message(FATAL_ERROR "Could not generate toolkits developer documentation.")
    endif()
    install(
        DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc/dev/html
        DESTINATION ${Spartacus_INSTALL_DOCS}/dev/Spartacus
    )
endif()

###
# Rules : Build resources
###

# icons
qt5_add_binary_resources(Spartacus_Icons res/icons/Resources.qrc)
install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/Spartacus_Icons.rcc
    DESTINATION ${Spartacus_INSTALL_RCCS}
)

###
# Rules : Build toolkits
###

# check for toolkits definition
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/TOOLKITS)
    message(FATAL_ERROR "Could not locate toolkits definition file.")
endif()
file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/src/TOOLKITS _toolkits)

#
# loop each toolkit, process input files
#
foreach(_toolkit ${_toolkits})
    # check for packages definition
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/${_toolkit}/PACKAGES)
        message("Could not locate packages definition for toolkit ${_toolkit}.")
    endif()

    # check for prerequisites definition
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/${_toolkit}/PREREQUISITES)
        message("Could not locate prerequisites definition for toolkit ${_toolkit}.")
    endif()

    # read packages
    file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/src/${_toolkit}/PACKAGES _packages)

    # read prerequisites
    file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/src/${_toolkit}/PREREQUISITES _prerequisites)

    # find source files / include directories for packages
    unset(_source_directories)
    unset(_source_files)
    foreach(_package ${_packages})

        # check for files definition in package
        if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/${_package}/FILES)
            message(FATAL_ERROR "Could not locate files definition for package ${_package}.")
        endif()

        # append package directory
        list(APPEND _source_directories ${CMAKE_CURRENT_SOURCE_DIR}/src/${_package})

        # read files
        file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/src/${_package}/FILES _files)

        # loop files, check if exists, append to sources
        foreach(_file ${_files})
            if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/${_package}/${_file})
                message(FATAL_ERROR "Could not locate file ${_file} in package ${_package}.")
            endif()
            list(APPEND _source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/${_package}/${_file})
        endforeach()
    endforeach()

    message(${OpenCascade_FoundationClasses_INCLUDE_DIRS})

    # find required libraries (intern / extern)
    unset(_include_directories)
    unset(_linked_libraries)
    foreach(_prerequisite ${_prerequisites})

        # check for include directories
        if(NOT ${_prerequisite}_INCLUDE_DIRS)
            message(FATAL_ERROR "Could not locate prerequisite ${_prerequisite} include directories.")
        endif()
        list(APPEND _include_directories ${${_prerequisite}_INCLUDE_DIRS})

        # check for required libraries
        if(NOT ${_prerequisite}_LIBRARIES)
            message(FATAL_ERROR "Could not locate prerequisite ${_prerequisite} libraries.")
        endif()
        list(APPEND _linked_libraries ${${_prerequisite}_LIBRARIES})

    endforeach()

    # rules
    include_directories(${_source_directories} ${_include_directories})
    add_library(${_toolkit} ${_source_files})
    target_link_libraries(${_toolkit} ${_linked_libraries})
    install(
        TARGETS ${_toolkit}
        ARCHIVE DESTINATION ${Spartacus_INSTALL_LIBS}
        LIBRARY DESTINATION ${Spartacus_INSTALL_LIBS}
        RUNTIME DESTINATION ${Spartacus_INSTALL_BINS}
    )

    # expose target in cache
    set(${_toolkit}_INCLUDE_DIRS ${_source_directories} CACHE PATH "Toolkit ${_toolkit} include directories.")
    set(${_toolkit}_LIBRARIES ${_toolkit} CACHE PATH "Toolkit ${_toolkit} libraries.")

endforeach()

