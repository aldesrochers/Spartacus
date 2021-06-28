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

project(SpartacusTests)

# include directories
include_directories(
    ${OpenCascade_FoundationClasses_INCLUDE_DIRS}
    ${StkFEM_INCLUDE_DIRS}
    ${Huygens_INCLUDE_DIRS}
)

# linked libraries
set(_linked_libraries
    ${OpenCascade_FoundationClasses_LIBRARIES}
    ${StkFEM_LIBRARIES}
    ${Huygens_LIBRARIES}
)

###
# list of tests
###
set(_files
    Test_Huygens.cxx
    Test_XSM_BimetallicCable01.cxx
)

###
# rules
###
foreach(_file ${_files})
    get_filename_component(_executable ${_file} NAME_WE)
    add_executable(${_executable} ${_file})
    target_link_libraries(${_executable} ${_linked_libraries})
endforeach()
