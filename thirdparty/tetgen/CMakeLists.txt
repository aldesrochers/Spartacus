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


set(Tetgen_VERSION_MAJOR 1)
set(Tetgen_VERSION_MINOR 6)
set(Tetgen_VERSION_PATCH 0)
set(Tetgen_DIRNAME tetgen-${Tetgen_VERSION_MAJOR}.${Tetgen_VERSION_MINOR}.${Tetgen_VERSION_PATCH})
set(Tetgen_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${Tetgen_DIRNAME})

set(Tetgen_INCLUDE_DIRS
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Tetgen_ROOT_DIR}
)

set(Tetgen_LINKED_LIBRARIES

)

# headers
set(Tetgen_HEADERS
    ${Tetgen_DIRNAME}/tetgen.h
)

# sources
set(Tetgen_SOURCES
    ${Tetgen_DIRNAME}/predicates.cxx
    ${Tetgen_DIRNAME}/tetgen.cxx
)

# rules
add_library(tetgen SHARED ${Tetgen_HEADERS} ${Tetgen_SOURCES})
target_compile_definitions(tetgen PRIVATE -DTETLIBRARY)
target_include_directories(tetgen PUBLIC ${Tetgen_INCLUDE_DIRS})
target_link_libraries(tetgen PUBLIC ${Tetgen_LINKED_LIBRARIES})
target_sources(tetgen PRIVATE ${Tetgen_SOURCES} ${Tetgen_HEADERS})

# generate position independent code
set_target_properties(tetgen PROPERTIES POSITION_INDEPENDENT_CODE ON)