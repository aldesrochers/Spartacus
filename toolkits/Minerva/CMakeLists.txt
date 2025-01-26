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
# Package : Desktop
# =============================================================================

set(Desktop_PKG_HEADERS
    Desktop/Desktop_MainWindow.hxx
)

set(Desktop_PKG_SOURCES
    Desktop/Desktop_MainWindow.cxx
)


# =============================================================================
# Package : Viewer3d
# =============================================================================

set(Viewer3d_PKG_HEADERS
    Viewer3d/Viewer3d.hxx
    Viewer3d/Viewer3d_View.hxx
    Viewer3d/Viewer3d_ViewWindow.hxx
)

set(Viewer3d_PKG_SOURCES
    Viewer3d/Viewer3d.cxx
    Viewer3d/Viewer3d_View.cxx
    Viewer3d/Viewer3d_ViewWindow.cxx
)



# =============================================================================
# Library : Minerva
# =============================================================================

set(Minerva_INCLUDE_DIRS
    ${OpenCASCADE_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Desktop
    ${CMAKE_CURRENT_SOURCE_DIR}/Viewer3d
)

set(Minerva_LINKED_LIBRARIES
    ${OpenCASCADE_LIBRARIES}
    ${Qt6Core_LIBRARIES}
    ${Qt6Gui_LIBRARIES}
    ${Qt6Widgets_LIBRARIES}
    Venus
)

set(Minerva_HEADERS
    ${Desktop_PKG_HEADERS}
    ${Viewer3d_PKG_HEADERS}
)

set(Minerva_SOURCES
    ${Desktop_PKG_SOURCES}
    ${Viewer3d_PKG_SOURCES}
)

qt_wrap_cpp(Minerva_SOURCES ${Minerva_HEADERS} TARGET Minerva)
qt_add_library(Minerva ${Minerva_SOURCES} ${Minerva_HEADERS})
#add_library(Minerva SHARED ${Minerva_HEADERS} ${Minerva_SOURCES})
target_include_directories(Minerva PUBLIC ${Minerva_INCLUDE_DIRS})
target_link_libraries(Minerva PUBLIC ${Minerva_LINKED_LIBRARIES})
