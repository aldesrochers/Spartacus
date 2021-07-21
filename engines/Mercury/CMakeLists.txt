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

project(SpartacusMercury)
set(Mercury_VERSION_MAJOR 1)
set(Mercury_VERSION_MINOR 0)
set(Mercury_VERSION_PATCH 0)

# configure version
configure_file(Mercury_Version.hxx.in Mercury_Version.hxx)


###
# library
###

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Qt_Core_INCLUDE_DIRS}
    ${Qt_Sql_INCLUDE_DIRS}
    ${StkDB_INCLUDE_DIRS}
)

set(_linked_libraries
    ${Qt_Core_LIBRARIES}
    ${Qt_Sql_LIBRARIES}
    ${StkDB_LIBRARIES}
)

set(_headers
    src/Mercury_Cluster.hxx
    src/Mercury_Engine.hxx
)

set(_sources
    src/Mercury_Cluster.cxx
    src/Mercury_Engine.cxx
)

#add_library(Mercury ${_headers} ${_sources})
add_executable(Mercury ${_headers} ${_sources} src/Mercury_Main.cxx)
target_link_libraries(Mercury ${_linked_libraries})
install(TARGETS Mercury DESTINATION ${Spartacus_INSTALL_LIBS})



