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
# check for VTK
###
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
unset(VTK_DIR CACHE)
unset(VTKm_DIR CACHE)

###
# check for required components
###
set(_required_components
    FoundationClasses
    ModelingData
    ModelingAlgorithms
    Visualization
    ApplicationFramework
)

###
# locate OpenCascade
###
find_package(OpenCASCADE REQUIRED)
if(NOT OpenCASCADE_FOUND)
    message(FATAL_ERROR "Could not locate OpenCascade.")
endif()
unset(OpenCASCADE_DIR CACHE)

###
# loop required components, configure in cache
###
foreach(_component ${_required_components})
    unset(OpenCascade_${_component}_INCLUDE_DIRS CACHE)
    unset(OpenCascade_${_component}_LIBRARIES CACHE)
    if(NOT OpenCASCADE_${_component}_LIBRARIES)
        message(FATAL_ERROR "Could not locate libraries for OpenCascade component ${_component}.")
    endif()
    set(OpenCascade_${_component}_INCLUDE_DIRS ${OpenCASCADE_INCLUDE_DIR} CACHE PATH "OpenCascade ${_component} include directories.")
    set(OpenCascade_${_component}_LIBRARIES ${OpenCASCADE_${_component}_LIBRARIES} CACHE PATH "OpenCascade ${_component} libraries.")
endforeach()

###
# Install required libraries - WIN32
###
if(WIN32)
    foreach(_component ${_required_components})
        foreach(_lib ${OpenCascade_${_component}_LIBRARIES})
            get_target_property(_filename ${_lib} LOCATION)
            install(FILES ${_filename} DESTINATION ${Spartacus_INSTALL_BINS})
        endforeach()
    endforeach()
endif()


