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
#include <Viewer3d_BasicViewerWidget.hxx>

// Qt
#include <QApplication>

// OpenCascade
#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <OSD_Environment.hxx>
#include <V3d_Viewer.hxx>

#include <BRepPrimAPI_MakeBox.hxx>


// ============================================================================
/*!
 *  \brief Test()
*/
// ============================================================================
int main(int argc, char** argv)
{

    // create a shape
    BRepPrimAPI_MakeBox aBuilder(10., 20., 30.);
    TopoDS_Shape aShape = aBuilder.Shape();

    // create presentable object
    Handle(AIS_Shape) anObject = new AIS_Shape(aShape);


    // create an application
    QApplication anApp(argc, argv);

    // create a view widget
    Viewer3d_BasicViewerWidget* aWidget = new Viewer3d_BasicViewerWidget();
    aWidget->show();

    aWidget->getContext()->Display(anObject, Standard_True);


    return anApp.exec();
}
