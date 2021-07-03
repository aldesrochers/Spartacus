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
# check for required components
###
set(_required_components
    Core
    Gui
    Widgets
    Sql
)

if(Spartacus_BUILD_Huygens)
    list(APPEND _required_components Xml)
endif()

###
# try to locate Qt libraries
###

# using standard macros
find_package(Qt5 COMPONENTS ${_required_components} REQUIRED)

# check if found properly
if(NOT ${Qt5_FOUND})
    message(FATAL_ERROR "Could not locate Qt5.")
endif()
unset(Qt5_DIR CACHE)

###
# loop each component, configure in cache
###
foreach(_component ${_required_components})
    unset(Qt_${_component}_INCLUDE_DIRS CACHE)
    unset(Qt_${_component}_LIBRARIES CACHE)
    if(NOT ${Qt5${_component}_FOUND})
        message(FATAL_ERROR "Could not locate Qt5 component ${_component}.")
    endif()
    set(Qt_${_component}_INCLUDE_DIRS ${Qt5${_component}_INCLUDE_DIRS} CACHE PATH "Qt ${_component} include directories.")
    set(Qt_${_component}_LIBRARIES ${Qt5${_component}_LIBRARIES} CACHE PATH "Qt ${_component} libraries.")
    unset(Qt5${_component}_DIR CACHE)
    unset(Qt5${_component}_DIR CACHE)
endforeach()

###
# configure default qt behaviour
###
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

###
# Install required libraries - WIN32
###
if(WIN32)
    foreach(_component ${_required_components})
        foreach(_lib ${Qt_${_component}_LIBRARIES})
            get_target_property(_filename ${_lib} LOCATION)
            install(FILES ${_filename} DESTINATION ${Spartacus_INSTALL_BINS})
        endforeach()
    endforeach()
endif()

# install required plugins on windows
if(MINGW)
    if(NOT EXISTS $ENV{MINGW_PREFIX}/share/qt5/plugins/platforms/qwindows.dll)
        message(FATAL_ERROR "Could not locate Qt5 plugins in MinGW distribution.")
    endif()
    install(
        FILES $ENV{MINGW_PREFIX}/share/qt5/plugins/platforms/qwindows.dll
        DESTINATION ${Spartacus_INSTALL_BINS}/platforms
    )
endif()
