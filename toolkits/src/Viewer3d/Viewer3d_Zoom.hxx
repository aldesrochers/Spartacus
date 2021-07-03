// ============================================================================
// Copyright (C) 2021-
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// Alexis L. Desrochers (alexisdesrochers@gmail.com)
//
// ============================================================================


#ifndef __Viewer3d_Zoom_hxx__
#define __Viewer3d_Zoom_hxx__


// ============================================================================
/*!
    \brief Viewer3d_ZoomSpeed
*/
// ============================================================================

// enumeration of generic zoom speed
enum Viewer3d_ZoomSpeed
{
    Viewer3d_ZoomSpeed0,
    Viewer3d_ZoomSpeed1,
    Viewer3d_ZoomSpeed2,
    Viewer3d_ZoomSpeed3,
    Viewer3d_ZoomSpeed4,
    Viewer3d_ZoomSpeed5,
    Viewer3d_ZoomSpeed6
};

// function used to retrieve zoom coefficients
static double getZoomCoefficient(Viewer3d_ZoomSpeed theZoomSpeed)
{
    switch (theZoomSpeed) {
    case Viewer3d_ZoomSpeed0:
        return 0.;
    case Viewer3d_ZoomSpeed1:
        return 1./10000;
    case Viewer3d_ZoomSpeed2:
        return 1./5000;
    case Viewer3d_ZoomSpeed3:
        return 1./2500;
    case Viewer3d_ZoomSpeed4:
        return 1./1000;
    case Viewer3d_ZoomSpeed5:
        return 1./250;
    case Viewer3d_ZoomSpeed6:
        return 1./100;
    default:
        return 1./1000;
    }
}

#endif  // __Viewer3d_Zoom_hxx__
