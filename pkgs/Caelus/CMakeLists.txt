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
    ${OpenCASCADE_INCLUDE_DIR}
)

# linked libraries
set(_linked_libraries
    ${OpenCASCADE_FoundationClasses}
)

# headers
set(_headers
    Caelus_Equations.hxx
    Caelus_Export.hxx
)

# sources
set(_sources
    Caelus_Equations.cxx
)

# rules
add_library(Caelus ${_headers} ${_sources})
target_link_libraries(Caelus ${_linked_libraries})
