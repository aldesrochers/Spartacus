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

###
# Core
###

set(MeshBuilder_CORE_HEADERS
    src/core/MeshBuilder_Study.hxx
    src/core/MeshBuilder_StudyModel.hxx
)

set(MeshBuilder_CORE_SOURCES
    src/core/MeshBuilder_Study.cxx
    src/core/MeshBuilder_StudyModel.cxx
)


###
# UI
###

set(MeshBuilder_UI_HEADERS
    src/ui/MeshBuilder_Desktop.hxx
    src/ui/MeshBuilder_Explorer.hxx
)

set(MeshBuilder_UI_SOURCES
    src/ui/MeshBuilder_Desktop.cxx
    src/ui/MeshBuilder_Explorer.cxx
    src/ui/MeshBuilder_Main.cxx
)

set(MeshBuilder_INCLUDE_DIRS
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui
    ${Qt6Core_INCLUDE_DIRS}
    ${Qt6Gui_INCLUDE_DIRS}
    ${Qt6Widgets_INCLUDE_DIRS}
)

set(MeshBuilder_LINKED_LIBRARIES
    ${Qt6Core_LIBRARIES}
    ${Qt6Gui_LIBRARIES}
    ${Qt6Widgets_LIBRARIES}
    Minerva
)

set(MeshBuilder_HEADERS
    ${MeshBuilder_CORE_HEADERS}
    ${MeshBuilder_UI_HEADERS}
)

set(MeshBuilder_SOURCES
    ${MeshBuilder_CORE_SOURCES}
    ${MeshBuilder_UI_SOURCES}
)

qt_add_resources(MeshBuilder_RESOURCES res/MeshBuilder.qrc)
qt_wrap_cpp(MeshBuilder_SOURCES ${MeshBuilder_HEADERS} TARGET MeshBuilder)
qt_add_executable(MeshBuilder ${MeshBuilder_SOURCES} ${MeshBuilder_HEADERS} ${MeshBuilder_RESOURCES})

#qt_wrap_cpp(MeshBuilder_MOCS ${MeshBuilder_HEADERS})
#add_executable(MeshBuilder ${MeshBuilder_HEADERS} ${MeshBuilder_SOURCES} ${MeshBuilder_MOCS})
target_include_directories(MeshBuilder PRIVATE ${MeshBuilder_INCLUDE_DIRS})
target_link_libraries(MeshBuilder PRIVATE ${MeshBuilder_LINKED_LIBRARIES})
