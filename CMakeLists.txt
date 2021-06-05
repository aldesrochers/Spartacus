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

cmake_minimum_required(VERSION 3.3)
project(Spartacus C CXX)
set(Spartacus_VERSION_MAJOR 1)
set(Spartacus_VERSION_MINOR 0)
set(Spartacus_VERSION_PATCH 0)

# check for project cmake files
if(EXISTS ${PROJECT_SOURCE_DIR}/cmake)
    list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
else()
    message(FATAL_ERROR "Could not locate project cmake files.")
endif()

# check for valid system configuration
if(NOT UNIX AND NOT MSYS AND NOT MINGW)
    message(FATAL_ERROR "Only supported on Unix, MSYS and MinGW.")
endif()

# configure
if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

###
# options
###
option(Spartacus_BUILD_DOCUMENTATION  "Build Spartacus documentation ?" ON)
option(Spartacus_BUILD_SHARED         "Build Spartacus in shared mode ?" ON)

###
# configure
###
set(BUILD_SHARED_LIBS ${Spartacus_BUILD_SHARED})

###
# install
###
set(Spartacus_INSTALL_BINS bin)
set(Spartacus_INSTALL_LIBS lib)
set(Spartacus_INSTALL_RCCS res)

###
# prerequisites
###
find_package(Qt5 COMPONENTS Core Gui Widgets Sql Xml Charts REQUIRED)
find_package(OpenCASCADE REQUIRED)
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

###
# sources
###
add_subdirectory(toolkits)
