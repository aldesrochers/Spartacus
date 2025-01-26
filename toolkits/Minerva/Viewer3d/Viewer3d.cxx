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


// Viewer
#include <Viewer3d.hxx>

// OpenCascade
#include <OpenGl_GraphicDriver.hxx>
#include <OSD_Environment.hxx>


// ============================================================================
/*!
 *  \brief CreateViewer()
*/
// ============================================================================
Handle(V3d_Viewer) Viewer3d::CreateViewer(const Standard_Real theProjection,
                                          const V3d_TypeOfOrientation theOrientation,
                                          const Standard_Boolean theComputedMode,
                                          const Standard_Boolean theDefaultComputedMode)
{
    // construct a graphic driver
    static Handle(OpenGl_GraphicDriver) aGraphicDriver;
    if (aGraphicDriver.IsNull()) {
        Handle(Aspect_DisplayConnection) aDisplayConnection;
#if !defined(_WIN32) && !defined(__WIN32__) && (!defined(__APPLE__) || defined(MACOSX_USE_GLX))
        aDisplayConnection = new Aspect_DisplayConnection (OSD_Environment ("DISPLAY").Value());
#endif
        aGraphicDriver = new OpenGl_GraphicDriver (aDisplayConnection);
    }

    // setup viewer with default attributes
    Handle(V3d_Viewer) aViewer = new V3d_Viewer(aGraphicDriver);
    aViewer->SetDefaultViewSize(theProjection);
    aViewer->SetDefaultViewProj(theOrientation);
    aViewer->SetComputedMode(theComputedMode);
    aViewer->SetDefaultComputedMode(theDefaultComputedMode);

    return aViewer;
}
