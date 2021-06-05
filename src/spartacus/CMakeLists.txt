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

# configure
configure_file(Spartacus_Version.hxx.in Spartacus_Version.hxx)

# include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Qt5Core_INCLUDE_DIRS}
)

# linked libraries
set(_linked_libraries
    ${Qt5Core_LIBRARIES}
)

# headers
set(_headers
    Spartacus_Export.hxx
    Spartacus_StandardPaths.hxx
)

# sources
set(_sources
    Spartacus_StandardPaths.cxx
)

# rules
add_library(Spartacus ${_headers} ${_sources})
target_link_libraries(Spartacus ${_linked_libraries})
install(TARGETS Spartacus
    RUNTIME DESTINATION ${Spartacus_INSTALL_BINS}
    ARCHIVE DESTINATION ${Spartacus_INSTALL_LIBS}
    LIBRARY DESTINATION ${Spartacus_INSTALL_LIBS})
