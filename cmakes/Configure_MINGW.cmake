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

# list required MINGW standard libraries
set(_libraries
    avcodec-58
    avformat-58
    avutil-56
    libaom
    libbluray-2
    libbrotlicommon
    libbrotlidec
    libbz2-1
    libcelt0-2
    libcrypto-1_1-x64
    libdav1d
    libdeflate
    libdouble-conversion
    libgcc_s_seh-1
    libffi-7
    libfreeimage-3
    libfreetype-6
    libglib-2.0-0
    libgmp-10
    libgnutls-30
    libgraphite2
    libgomp-1
    libgsm
    libharfbuzz-0
    libHalf-2_5
    libhogweed-6
    libiconv-2
    libicudt68
    libicuin68
    libicuuc68
    libidn2-0
    libImath-2_5
    libIex-2_5
    libIlmImf-2_5
    libIlmThread-2_5
    libintl-8
    libjasper-4
    libjbig-0
    libjpeg-8
    libjpegxr
    libjxrglue
    liblcms2-2
    liblzma-5
    libmfx-1
    libmodplug-1
    libmp3lame-0
    libnettle-8
    libogg-0
    libopencore-amrnb-0
    libopencore-amrwb-0
    libopenjp2-7
    libopenvr_api
    libopus-0
    libp11-kit-0
    libpcre-1
    libpcre2-16-0
    libpng16-16
    libraw-20
    librtmp-1
    libsoxr
    libspeex-1
    libsrt
    libssp-0
    libstdc++-6
    libtasn1-6
    libtheoradec-1
    libtheoraenc-1
    libtiff-5
    libunistring-2
    libvorbis-0
    libvorbisenc-2
    libvulkan-1
    libvpx-1
    libwebp-7
    libwebpmux-3
    libwinpthread-1
    libx264-159
    libx265
    libxml2-2
    libzstd
    xvidcore
    swresample-3
    swscale-5
    zlib1
)

# loop each library, try to locate, install
foreach(_lib ${_libraries})
    if(NOT EXISTS $ENV{MINGW_PREFIX}/bin/${_lib}.dll)
        message(FATAL_ERROR "Could not locate MinGW library ${_lib}.")
    endif()
    install(FILES $ENV{MINGW_PREFIX}/bin/${_lib}.dll DESTINATION ${Spartacus_INSTALL_BINS})
endforeach()
