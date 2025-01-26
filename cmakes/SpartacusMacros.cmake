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


# =============================================================================
# Macro : Spartacus_BUILD_DEVELOPER_DOCUMENTATION
# Macro used to build developer documentation.
#
# Arguments :
#   - _component_name : Name of the component.
#   - _doxyfile_in : Path to Doxyfile.in
# =============================================================================
macro(Spartacus_BUILD_DEVELOPER_DOCUMENTATION _component_name _doxyfile_in)
    # configure Doxyfile.in
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${_doxyfile_in} doc/dev/Doxyfile)

    # execute doxygen
    execute_process(COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc/dev
        RESULT_VARIABLE _result
        OUTPUT_VARIABLE _output)

    # install
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc/dev/html
        DESTINATION ${Spartacus_INSTALL_DOCUMENTATION}/${_component_name}/dev)

endmacro()

# =============================================================================
# Macro : Spartacus_BUILD_TESTS
# Macro used to build a series of Spartacus tests.
# =============================================================================
macro(Spartacus_BUILD_TESTS _name)

    # try to locate Tests package definition
    set(Tests_FILES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/${_name}/FILES)
    if(NOT EXISTS ${Tests_FILES_FILE})
        message(FATAL_ERROR "Could not find tests files file at path ${Tests_FILES_FILE}")
    endif()

    # try to locate Tests prerequisites definition
    set(Tests_PREREQUISITES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/${_name}/PREREQUISITES)
    if(NOT EXISTS ${Tests_PREREQUISITES_FILE})
        message(FATAL_ERROR "Could not find tests prerequisites file at path ${Tests_PREREQUISITES_FILE}")
    endif()

    # read FILES in Tests
    file(STRINGS ${Tests_FILES_FILE} Tests_FILES_LIST)

    # read prerequisites used by Tests
    file(STRINGS ${Tests_PREREQUISITES_FILE} Tests_PREREQUISITES_LIST)

    ##
    # loop over prerequisites, retrieve linked attributes
    ##
    unset(Tests_EXTERN_INCLUDE_DIRS)
    unset(Tests_EXTERN_LIBRARIES)
    foreach(Tests_PREREQUISITE ${Tests_PREREQUISITES_LIST})
        list(APPEND Tests_EXTERN_INCLUDE_DIRS ${${Tests_PREREQUISITE}_INCLUDE_DIRS})
        list(APPEND Tests_EXTERN_LIBRARIES ${${Tests_PREREQUISITE}_LIBRARIES})
    endforeach()

    ##
    # include directories
    ##
    include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/${_name}
        ${Tests_EXTERN_INCLUDE_DIRS}
    )

    ##
    # rules
    ##
    foreach(Tests_FILE ${Tests_FILES_LIST})
        get_filename_component(Test_NAME ${Tests_FILE} NAME_WE)
        add_executable(${Test_NAME} WIN32 ${CMAKE_CURRENT_SOURCE_DIR}/${_name}/${Tests_FILE})
        target_link_libraries(${Test_NAME} ${Tests_EXTERN_LIBRARIES})
    endforeach()

endmacro()

# =============================================================================
# Macro : Spartacus_BUILD_TOOLKIT
# Macro used to build & configure a Spartacus toolkit.
# =============================================================================
macro(Spartacus_BUILD_TOOLKIT _name)

    # check for toolkit subdirectory
    set(Toolkit_DIR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Tk${_name})
    if(NOT EXISTS ${Toolkit_DIR_PATH})
        message(FATAL_ERROR "Could not locate source directory for toolkit ${_name}.")
    endif()

    # locate extern include dirs
    set(Toolkit_EXTERN_INCLUDE_DIRS_FILE ${Toolkit_DIR_PATH}/EXTERN_INCLUDE_DIRS)
    if(NOT EXISTS ${Toolkit_EXTERN_INCLUDE_DIRS_FILE})
        message(FATAL_ERROR "Could not locate extern include directories for toolkit ${_name}.")
    endif()
    file(STRINGS ${Toolkit_EXTERN_INCLUDE_DIRS_FILE} Toolkit_EXTERN_INCLUDE_DIRS_LIST)
    set(Toolkit_EXTERN_INCLUDE_DIRS "")
    foreach(Toolkit_EXTERN_INCLUDE_DIR ${Toolkit_EXTERN_INCLUDE_DIRS_LIST})
        list(APPEND Toolkit_EXTERN_INCLUDE_DIRS ${${Toolkit_EXTERN_INCLUDE_DIR}})
    endforeach()

    # locate extern libraries
    set(Toolkit_EXTERN_LIBRARIES_FILE ${Toolkit_DIR_PATH}/EXTERN_LIBRARIES)
    if(NOT EXISTS ${Toolkit_EXTERN_LIBRARIES_FILE})
        message(FATAL_ERROR "Could not locate extern libraries for toolkit ${_name}.")
    endif()
    file(STRINGS ${Toolkit_EXTERN_LIBRARIES_FILE} Toolkit_EXTERN_LIBRARIES_LIST)
    set(Toolkit_EXTERN_LIBRARIES "")
    foreach(Toolkit_EXTERN_INCLUDE_DIR ${Toolkit_EXTERN_LIBRARIES_LIST})
        list(APPEND Toolkit_EXTERN_LIBRARIES ${${Toolkit_EXTERN_INCLUDE_DIR}})
    endforeach()

    # locate packages
    set(Toolkit_PACKAGES_FILE ${Toolkit_DIR_PATH}/PACKAGES)
    if(NOT EXISTS ${Toolkit_PACKAGES_FILE})
        message(FATAL_ERROR "Could not locate packages definition for toolkit ${_name}.")
    endif()
    file(STRINGS ${Toolkit_PACKAGES_FILE} Toolkit_PACKAGES_LIST)

    # initialize toolkit headers, sources, include directories variables
    set(Toolkit_INCLUDE_DIRS "")
    set(Toolkit_HEADERS "")
    set(Toolkit_SOURCES "")
    list(APPEND Toolkit_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
    list(APPEND Toolkit_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR})

    ##
    # process packages
    ##
    foreach(Toolkit_PACKAGE ${Toolkit_PACKAGES_LIST})

        # append package to include directories
        list(APPEND Toolkit_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/${Toolkit_PACKAGE})

        # read files in package
        set(Package_FILES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/${Toolkit_PACKAGE}/FILES)
        if(NOT EXISTS ${Package_FILES_FILE})
            message(FATAL_ERROR "Could not locate files for package ${Toolkit_PACKAGE}.")
        endif()
        file(STRINGS ${Package_FILES_FILE} Package_FILES_LIST)

        # process sources
        foreach(Package_FILE ${Package_FILES_LIST})
            set(Package_FILE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${Toolkit_PACKAGE}/${Package_FILE})
            get_filename_component(FILE_EXTENSION ${Package_FILE_PATH} EXT)
            if(${FILE_EXTENSION} STREQUAL ".hxx")
                list(APPEND Toolkit_HEADERS ${Package_FILE_PATH})
            elseif(${FILE_EXTENSION} STREQUAL ".h")
                list(APPEND Toolkit_HEADERS ${Package_FILE_PATH})
            else()
                list(APPEND Toolkit_SOURCES ${Package_FILE_PATH})
            endif()
        endforeach()

    endforeach()

    # include directories
    include_directories(
        ${Toolkit_EXTERN_INCLUDE_DIRS}
        ${Toolkit_INCLUDE_DIRS}
    )

    # rules
    add_library(Tk${_name} SHARED ${Toolkit_HEADERS} ${Toolkit_SOURCES})
    target_link_libraries(Tk${_name} ${Toolkit_EXTERN_LINKED_LIBRARIES})
    install(
        TARGETS Tk${_name}
        ARCHIVE DESTINATION ${Spartacus_INSTALL_LIBRARIES}
        LIBRARY DESTINATION ${Spartacus_INSTALL_BINARIES}
        RUNTIME DESTINATION ${Spartacus_INSTALL_BINARIES}
    )

    # install headers
    if(Spartacus_BUILD_DEVELOPMENT)
        install(FILES ${Toolkit_HEADERS} DESTINATION ${Spartacus_INSTALL_HEADERS})
    endif()

    # expose target
    unset(${_name}_INCLUDE_DIRS CACHE)
    unset(${_name}_LIBRARIES CACHE)
    set(${_name}_INCLUDE_DIRS ${Toolkit_INCLUDE_DIRS} CACHE PATH "Toolkit ${_name} include directories.")
    set(${_name}_LIBRARIES Tk${_name} CACHE PATH "Toolkit ${_name} libraries.")

endmacro()

# =============================================================================
# Macro : Spartacus_BUILD_TOOLKIT
# Macro used to build & configure a Spartacus toolkit.
# =============================================================================
macro(Spartacus_BUILD_TOOLKITS _name)


    # try to locate toolkit package definition
    set(Toolkit_PACKAGES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/${_name}/PACKAGES)
    if(NOT EXISTS ${Toolkit_PACKAGES_FILE})
        message(FATAL_ERROR "Could not find toolkit packages file at path ${Toolkit_PACKAGES_FILE}")
    endif()

    # try to locate toolkit prerequisites definition
    set(Toolkit_PREREQUISITES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/${_name}/PREREQUISITES)
    if(NOT EXISTS ${Toolkit_PREREQUISITES_FILE})
        message(FATAL_ERROR "Could not find toolkit prerequisites file at path ${Toolkit_PREREQUISITES_FILE}")
    endif()

    # read packages in toolkit
    file(STRINGS ${Toolkit_PACKAGES_FILE} Toolkit_PACKAGES_LIST)

    # read prerequisites used by toolkit
    file(STRINGS ${Toolkit_PREREQUISITES_FILE} Toolkit_PREREQUISITES_LIST)

    ##
    # loop over packages, retrieve sources files
    ##
    unset(Toolkit_HEADERS)
    unset(Toolkit_SOURCES)
    unset(Toolkit_INCLUDE_DIRS)
    foreach(Toolkit_PACKAGE ${Toolkit_PACKAGES_LIST})
        # try to locate packages definition file
        set(Package_SOURCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/${Toolkit_PACKAGE}/FILES)
        if(NOT EXISTS ${Package_SOURCE_FILE})
            message(FATAL_ERROR "Could not find package sources at path ${Package_SOURCE_FILE}")
        endif()
        # read sources in packages
        file(STRINGS ${Package_SOURCE_FILE} Package_SOURCES_LIST)
        # loop over sources, process
        foreach(Package_SOURCE_FILE ${Package_SOURCES_LIST})
            set(Package_SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${Toolkit_PACKAGE}/${Package_SOURCE_FILE})
            get_filename_component(FILE_EXTENSION ${Package_SOURCE_PATH} EXT)
            if(${FILE_EXTENSION} STREQUAL ".hxx")
                list(APPEND Toolkit_HEADERS ${Package_SOURCE_PATH})
            elseif(${FILE_EXTENSION} STREQUAL ".cxx")
                list(APPEND Toolkit_HEADERS ${Package_SOURCE_PATH})
            else()
                message(FATAL_ERROR "Invalid source file extension ${FILE_EXTENSION}")
            endif()
        endforeach()
        # add package path to include dirs
        list(APPEND Toolkit_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/${Toolkit_PACKAGE})
    endforeach()

    ##
    # loop over prerequisites, retrieve linked attributes
    ##
    unset(Toolkit_EXTERN_INCLUDE_DIRS)
    unset(Toolkit_EXTERN_LIBRARIES)
    foreach(Toolkit_PREREQUISITE ${Toolkit_PREREQUISITES_LIST})
        list(APPEND Toolkit_EXTERN_INCLUDE_DIRS ${${Toolkit_PREREQUISITE}_INCLUDE_DIRS})
        list(APPEND Toolkit_EXTERN_LIBRARIES ${${Toolkit_PREREQUISITE}_LIBRARIES})
    endforeach()

    ##
    # rules
    ##

    # include directories
    include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${Toolkit_INCLUDE_DIRS}
        ${Toolkit_EXTERN_INCLUDE_DIRS}
    )

    # build library
    add_library(${_name} SHARED ${Toolkit_HEADERS} ${Toolkit_SOURCES})
    target_link_libraries(${_name} ${Toolkit_EXTERN_LIBRARIES})
    install(
        TARGETS ${_name}
        ARCHIVE DESTINATION ${Spartacus_INSTALL_LIBRARIES}
        LIBRARY DESTINATION ${Spartacus_INSTALL_BINARIES}
        RUNTIME DESTINATION ${Spartacus_INSTALL_BINARIES}
    )

    # install headers
    if(Spartacus_BUILD_DEVELOPMENT)
        install(FILES ${Toolkit_HEADERS} DESTINATION ${Spartacus_INSTALL_HEADERS})
    endif()

    # expose target
    unset(${_name}_INCLUDE_DIRS CACHE)
    unset(${_name}_LIBRARIES CACHE)
    set(${_name}_INCLUDE_DIRS ${Toolkit_INCLUDE_DIRS} CACHE PATH "Toolkit ${_name} include directories.")
    set(${_name}_LIBRARIES ${_name} CACHE PATH "Toolkit ${_name} libraries.")

endmacro()


# =============================================================================
# Macro : Spartacus_FIND_PACKAGE_FILES
# Macro used to process files within a package.
# =============================================================================
macro(Spartacus_FIND_PACKAGE_FILES _directory _headers _sources)

    # try to locate package source files definition (file named FILES)
    set(Package_DEFINITION_FILE ${_directory}/FILES)
    if(NOT EXISTS ${Package_DEFINITION_FILE})
        message(FATAL_ERROR "Could not locate file FILES in directory ${_directory}")
    endif()

    # read sources in packages
    file(STRINGS ${Package_DEFINITION_FILE} Package_FILES_LIST)

    # loop over files, process
    set(Package_HEADERS "")
    set(Package_SOURCES "")
    foreach(Package_FILE ${Package_FILES_LIST})
        set(Package_FILE_PATH ${_directory}/${Package_FILE})
        get_filename_component(FILE_EXTENSION ${Package_FILE_PATH} EXT)
        if(${FILE_EXTENSION} STREQUAL ".hxx")
            list(APPEND Package_HEADERS ${Package_FILE_PATH})
        elseif(${FILE_EXTENSION} STREQUAL ".h")
            list(APPEND Package_HEADERS ${Package_FILE_PATH})
        else()
            list(APPEND Package_SOURCES ${Package_FILE_PATH})
        endif()
    endforeach()

    # return headers, sources
    list(APPEND ${_headers} ${Package_HEADERS})
    list(APPEND ${_sources} ${Package_SOURCES})

endmacro()

# =============================================================================
# Macro : Spartacus_FIND_TOOLKIT_CONFIGURATION
# Macro used to process files with a toolkit.
# =============================================================================
macro(Spartacus_FIND_TOOLKIT_CONFIGURATION _subdirectories _include_dirs _headers _sources)

    # set variables
    set(Toolkit_INCLUDE_DIRS "")
    set(Toolkit_HEADERS "")
    set(Toolkit_SOURCES "")

    # add cmake current/binary directory to include directories
    list(APPEND Toolkit_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR})
    list(APPEND Toolkit_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

    # loop over each subdirectory, check if exists, process files
    foreach(Toolkit_SUBDIR ${_subdirectories})
        if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${Toolkit_SUBDIR})
            message(FATAL_ERROR "Toolkit subdirectory ${Toolkit_SUBDIR} does not exists.")
        endif()
        Spartacus_FIND_PACKAGE_FILES(${CMAKE_CURRENT_SOURCE_DIR}/${Toolkit_SUBDIR} Package_HEADERS Package_SOURCES)
        list(APPEND Toolkit_HEADERS ${Package_HEADERS})
        list(APPEND Toolkit_SOURCES ${Package_SOURCES})
        list(APPEND Toolkit_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/${Toolkit_SUBDIR})
    endforeach()

    # return headers, sources
    set(${_headers} ${Toolkit_HEADERS})
    set(${_sources} ${Toolkit_SOURCES})
    set(${_include_dirs} ${Toolkit_INCLUDE_DIRS})

endmacro()

# =============================================================================
# Macro : Spartacus_INSTALL_LIBRARY
# Macro used to install library targets.
# =============================================================================
macro(Spartacus_INSTALL_LIBRARY _target)
    if(Spartacus_BUILD_STANDALONE)
        install(TARGETS ${_target} RUNTIME DESTINATION ${Spartacus_INSTALL_BINARIES})
    else()
        install(TARGETS ${_target}
            ARCHIVE DESTINATION ${Spartacus_INSTALL_LIBRARIES}
            LIBRARY DESTINATION ${Spartacus_INSTALL_LIBRARIES}
            RUNTIME DESTINATION ${Spartacus_INSTALL_BINARIES})
    endif()
endmacro()


# =============================================================================
# Macro : Spartacus_INSTALL_MINGW_LIBRARY
# Macro used to locate a MinGW library and make proper framework configuration.
# =============================================================================
macro(Spartacus_INSTALL_MINGW_LIBRARY _library)
    set(_filename $ENV{MINGW_PREFIX}/bin/${_library})
    if(NOT EXISTS ${_filename})
        message(FATAL_ERROR "Could not locate MINGW runtime library at path ${_filename}")
    endif()
    install(FILES ${_filename} DESTINATION ${Spartacus_INSTALL_BINARIES})
endmacro()


# =============================================================================
# Macro : Spartacus_SETUP_INSTALL_PATHS()
# Setup the installation paths.
# =============================================================================
macro(Spartacus_SETUP_INSTALL_PATHS)
    if(UNIX)
        if(Spartacus_BUILD_STANDALONE)
            set(Spartacus_INSTALL_BINARIES  ${CMAKE_INSTALL_PREFIX}/bin)
            set(Spartacus_INSTALL_CONFIGS   ${CMAKE_INSTALL_PREFIX}/etc)
            set(Spartacus_INSTALL_HEADERS   ${CMAKE_INSTALL_PREFIX}/include)
            set(Spartacus_INSTALL_LIBRARIES ${CMAKE_INSTALL_PREFIX}/lib)
            set(Spartacus_INSTALL_RCCS      ${CMAKE_INSTALL_PREFIX}/lib)
        else()
            set(Spartacus_INSTALL_BINARIES  ${CMAKE_INSTALL_PREFIX}/bin)
            set(Spartacus_INSTALL_CONFIGS   ${CMAKE_INSTALL_PREFIX}/etc/spartacus)
            set(Spartacus_INSTALL_HEADERS   ${CMAKE_INSTALL_PREFIX}/include/spartacus)
            set(Spartacus_INSTALL_LIBRARIES ${CMAKE_INSTALL_PREFIX}/lib/spartacus)
            set(Spartacus_INSTALL_RCCS ${CMAKE_INSTALL_PREFIX}/lib/spartacus)
        endif()
    elseif(WIN32)
        if(Spartacus_BUILD_STANDALONE)
            set(Spartacus_INSTALL_BINARIES  ${CMAKE_INSTALL_PREFIX})
            set(Spartacus_INSTALL_CONFIGS   ${CMAKE_INSTALL_PREFIX}/configs)
            set(Spartacus_INSTALL_HEADERS   ${CMAKE_INSTALL_PREFIX}/include)
            set(Spartacus_INSTALL_LIBRARIES ${CMAKE_INSTALL_PREFIX})
            set(Spartacus_INSTALL_RCCS ${CMAKE_INSTALL_PREFIX})
        else()
            set(Spartacus_INSTALL_BINARIES  ${CMAKE_INSTALL_PREFIX}/bin)
            set(Spartacus_INSTALL_CONFIGS   ${CMAKE_INSTALL_PREFIX}/etc/spartacus)
            set(Spartacus_INSTALL_HEADERS   ${CMAKE_INSTALL_PREFIX}/include/spartacus)
            set(Spartacus_INSTALL_LIBRARIES ${CMAKE_INSTALL_PREFIX}/lib/spartacus)
            set(Spartacus_INSTALL_RCCS ${CMAKE_INSTALL_PREFIX}/lib/spartacus)
        endif()
    else()
        message(FATAL_ERROR "Only valid on Windows an Unix.")
    endif()
endmacro()
