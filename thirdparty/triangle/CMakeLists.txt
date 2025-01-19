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


set(Triangle_VERSION_MAJOR 1)
set(Triangle_VERSION_MINOR 6)
set(Triangle_DIRNAME triangle-${Triangle_VERSION_MAJOR}.${Triangle_VERSION_MINOR})
set(Triangle_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${Triangle_DIRNAME})

set(Triangle_INCLUDE_DIRS
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Triangle_ROOT_DIR}
)

set(Triangle_LINKED_LIBRARIES

)

# headers
set(Triangle_HEADERS
    ${Triangle_DIRNAME}/triangle.h
)

# sources
set(Triangle_SOURCES
    ${Triangle_DIRNAME}/triangle.cpp
)

# rules
add_library(triangle SHARED ${Triangle_HEADERS} ${Triangle_SOURCES})
target_compile_definitions(triangle PRIVATE -DTRILIBRARY -DANSI_DECLARATORS)
if(WIN32)
  target_compile_definitions(triangle PRIVATE -DNO_TIMER)
endif()
target_include_directories(triangle PUBLIC ${Triangle_INCLUDE_DIRS})
target_link_libraries(triangle PUBLIC ${Triangle_LINKED_LIBRARIES})

# generate position independent code
set_target_properties(triangle PROPERTIES POSITION_INDEPENDENT_CODE ON)