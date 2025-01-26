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
#include <MeshBuilder_Desktop.hxx>
#include <MeshBuilder_Explorer.hxx>
#include <MeshBuilder_StudyModel.hxx>
#include <Viewer3d_View.hxx>

// Qt
#include <QDockWidget>
#include <QIcon>

    #include <BRepPrimAPI_MakeBox.hxx>
    #include <TopoDS_Shape.hxx>
    #include <AIS_Shape.hxx>

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshBuilder_Desktop::MeshBuilder_Desktop(QWidget* theParent)
    : Desktop_MainWindow(theParent)
{
    initialize();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MeshBuilder_Desktop::~MeshBuilder_Desktop()
{
    
}

// ============================================================================
/*!
    \brief initialize()
*/
// ============================================================================
void MeshBuilder_Desktop::initialize()
{
    setWindowIcon(QIcon(":/MeshBuilder.png"));

    QDockWidget* aDockWidget = new QDockWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea, aDockWidget);

    MeshBuilder_Explorer* anExplorer = new MeshBuilder_Explorer(aDockWidget);
    MeshBuilder_StudyModel* aModel = new MeshBuilder_StudyModel();
    aDockWidget->setWidget(anExplorer);
    anExplorer->setModel(aModel);

    Viewer3d_View* aView = new Viewer3d_View(this);
    setCentralWidget(aView);


    Handle(AIS_InteractiveContext) aContext = aView->context();

    TopoDS_Shape aShape = BRepPrimAPI_MakeBox(10, 10, 10).Shape();
    Handle(AIS_Shape) anAIS = new AIS_Shape(aShape);
    anAIS->SetTransparency(0.5);
    aContext->Display(anAIS, Standard_False);

}
