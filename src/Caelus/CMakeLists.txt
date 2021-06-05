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
    ${OpenCASCADE_FoundationClasses_LIBRARIES}
)

# headers
set(_headers
    Caelus_Catenary.hxx
    Caelus_CreepCurve.hxx
    Caelus_CreepFunction.hxx
    Caelus_Equilibrium.hxx
    Caelus_LoadCase.hxx
    Caelus_LoadCaseBuilder.hxx
    Caelus_RulingSpanBuilder.hxx
    Caelus_Section.hxx
    Caelus_SectionBuilder.hxx
    Caelus_SequenceOfSubSection.hxx
    Caelus_SequenceOfSpan.hxx
    Caelus_Span.hxx
    Caelus_StressStrainCurve.hxx
    Caelus_StressStrainFunction.hxx
    Caelus_SubSection.hxx
)

# sources
set(_sources
    Caelus_Catenary.cxx
    Caelus_CreepCurve.cxx
    Caelus_CreepFunction.cxx
    Caelus_Equilibrium.cxx
    Caelus_LoadCase.cxx
    Caelus_LoadCaseBuilder.cxx
    Caelus_RulingSpanBuilder.cxx
    Caelus_Section.cxx
    Caelus_SectionBuilder.cxx
    Caelus_Span.cxx
    Caelus_StressStrainCurve.cxx
    Caelus_StressStrainFunction.cxx
    Caelus_SubSection.cxx
)

# rules
add_executable(Caelus ${_headers} ${_sources} Caelus_Main.cxx)
#add_library(Caelus ${_headers} ${_sources})
target_link_libraries(Caelus ${_linked_libraries})
install(TARGETS Caelus
    RUNTIME DESTINATION ${Caelus_INSTALL_BINS}
    ARCHIVE DESTINATION ${Caelus_INSTALL_LIBS}
    LIBRARY DESTINATION ${Caelus_INSTALL_LIBS})
