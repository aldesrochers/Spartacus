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


#include <iostream>
using namespace std;

// Spartacus
#include <Viewer3d_ViewWidget.hxx>

// Qt
#include <QApplication>

// OpenCascade
#include <Aspect_DisplayConnection.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <V3d_Viewer.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>

#include <BRepPrimAPI_MakeBox.hxx>


// ============================================================================
/*!
 *  \brief Test()
*/
// ============================================================================
int main(int argc, char** argv)
{

    static Handle(OpenGl_GraphicDriver) aGraphicDriver;
    if (aGraphicDriver.IsNull())
    {
      Handle(Aspect_DisplayConnection) aDisplayConnection;
  #if !defined(_WIN32) && !defined(__WIN32__) && (!defined(__APPLE__) || defined(MACOSX_USE_GLX))
      aDisplayConnection = new Aspect_DisplayConnection (OSD_Environment ("DISPLAY").Value());
  #endif
      aGraphicDriver = new OpenGl_GraphicDriver (aDisplayConnection);
    }

    // create a viewer
    Handle(V3d_Viewer) myViewer = new V3d_Viewer (aGraphicDriver);
    myViewer->SetDefaultViewSize(1000.);
    myViewer->SetDefaultViewProj(V3d_XposYnegZpos);
    myViewer->SetComputedMode(Standard_True);
    myViewer->SetDefaultComputedMode(Standard_True);
    myViewer->SetDefaultLights();
    myViewer->SetLightOn();

    // initialize context
    Handle(AIS_InteractiveContext) myContext = new AIS_InteractiveContext(myViewer);

    // create a shape
    BRepPrimAPI_MakeBox aBuilder(10., 20., 30.);
    TopoDS_Shape aShape = aBuilder.Shape();

    // create presentable object
    Handle(AIS_Shape) anObject = new AIS_Shape(aShape);
    myContext->Display(anObject, AIS_Shaded, 0, Standard_True);

    // create an application
    QApplication anApp(argc, argv);

    // create a view widget
    Viewer3d_ViewWidget* aWidget = new Viewer3d_ViewWidget(myContext);
    aWidget->show();


    return anApp.exec();
}
