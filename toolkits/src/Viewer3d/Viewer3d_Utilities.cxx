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

// Spartacus
#include <Viewer3d_Utilities.hxx>

// OpenCascade
#include <OSD_Environment.hxx>


// ============================================================================
/*!
 *  \brief createGraphicDriver()
*/
// ============================================================================
Handle(OpenGl_GraphicDriver) Viewer3d_Utilities::createGraphicDriver()
{
    static Handle(OpenGl_GraphicDriver) aGraphicDriver;

    if (aGraphicDriver.IsNull()) {
        Handle(Aspect_DisplayConnection) aDisplayConnection;
#ifndef WIN32
        aDisplayConnection = new Aspect_DisplayConnection(OSD_Environment ("DISPLAY").Value());
#endif
        aGraphicDriver = new OpenGl_GraphicDriver(aDisplayConnection);
    }

    return aGraphicDriver;
}

// ============================================================================
/*!
 *  \brief createViewer()
 *  Create a viewer with default configuration.
*/
// ============================================================================
Handle(V3d_Viewer) Viewer3d_Utilities::createViewer()
{
    Handle(V3d_Viewer) aViewer = new V3d_Viewer(createGraphicDriver());

    // setup basic viewer configuration
    aViewer->SetDefaultViewSize(1000.);
    aViewer->SetDefaultViewProj(V3d_XposYnegZpos);
    aViewer->SetComputedMode(Standard_True);
    aViewer->SetDefaultComputedMode(Standard_True);
    aViewer->SetDefaultLights();
    aViewer->SetLightOn();

    return aViewer;
}
