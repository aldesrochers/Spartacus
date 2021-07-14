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


// Huygens
#include <HuygensApp_Desktop.hxx>
#include <HuygensApp_Navigator.hxx>

// Spartacus
#include <Viewer3d_BasicViewerWidget.hxx>

// Qt
#include <QDebug>
#include <QDockWidget>
#include <QMenuBar>
#include <QMenu>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
HuygensApp_Desktop::HuygensApp_Desktop(QWidget* theParent)
    : QMainWindow(theParent)
{
    // initialize an engine
    myEngine = new Huygens_Engine();

    // create menus
    createFileMenu();
    createHelpMenu();

    // create dock widgets
    createNavigatorDockWidget();
    createViewerWidget();


}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
HuygensApp_Desktop::~HuygensApp_Desktop()
{

}

// ============================================================================
/*!
 *  \brief createFileMenu()
*/
// ============================================================================
void HuygensApp_Desktop::createFileMenu()
{
    QMenu* aMenu = menuBar()->addMenu(tr("&File"));

    // action : new document
    QAction* newDocument = aMenu->addAction(GetResourcesMgr()->GetIcon(FWR_NewFileIcon),
                                            tr("New"));
    connect(newDocument, SIGNAL(triggered()), this, SLOT(NewDocument()));

    // action : close document
    QAction* closeDocument = new QAction(GetResourcesMgr()->GetIcon(FWR_CloseFileIcon),
                                         tr("Close"));
    aMenu->addAction(closeDocument);
    connect(closeDocument, SIGNAL(triggered()), this, SLOT(CloseDocument()));

    // action : quit
    aMenu->addSeparator();
    QAction* quit = aMenu->addAction(GetResourcesMgr()->GetIcon(FWR_ExitIcon),
                                     tr("&Quit"));
    connect(quit, SIGNAL(triggered()), this, SLOT(close()));

}

// ============================================================================
/*!
 *  \brief createHelpMenu()
*/
// ============================================================================
void HuygensApp_Desktop::createHelpMenu()
{
    QMenu* aMenu = menuBar()->addMenu(tr("&Help"));
}

// ============================================================================
/*!
 *  \brief createNavigatorDockWidget()
*/
// ============================================================================
void HuygensApp_Desktop::createNavigatorDockWidget()
{
    myNavigatorTreeWidget = new QTreeWidget();
    myNavigatorTreeWidget->setHeaderHidden(true);
    myNavigatorTreeWidget->setColumnCount(1);

    QDockWidget* aDockWidget = new QDockWidget(tr("Navigator"));
    aDockWidget->setWidget(myNavigatorTreeWidget);
    aDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    aDockWidget->setToolTip(tr("Document navigator"));
    addDockWidget(Qt::LeftDockWidgetArea, aDockWidget);


}

// ============================================================================
/*!
 *  \brief createViewerWidget()
*/
// ============================================================================
void HuygensApp_Desktop::createViewerWidget()
{
    Viewer3d_BasicViewerWidget* aViewer = new Viewer3d_BasicViewerWidget();
    setCentralWidget(aViewer);
}

// ============================================================================
/*!
    \brief GetEngine()
*/
// ============================================================================
Handle(Huygens_Engine) HuygensApp_Desktop::GetEngine()
{
    return myEngine;
}

// ============================================================================
/*!
    \brief GetResourcesMgr()
    Convenient shortcut to the framwework resources manager.
*/
// ============================================================================
FWR_Manager* HuygensApp_Desktop::GetResourcesMgr()
{
    return FWR_Manager::Manager();
}

// ============================================================================
/*!
 *  \brief CloseDocument()
*/
// ============================================================================
void HuygensApp_Desktop::CloseDocument()
{

}

// ============================================================================
/*!
 *  \brief NewDocument()
*/
// ============================================================================
void HuygensApp_Desktop::NewDocument()
{
    QTreeWidgetItem* aMaterialItem = new QTreeWidgetItem(1);
    aMaterialItem->setText(0, "Test");
    aMaterialItem->setIcon(0, GetResourcesMgr()->GetIcon(FWR_SpartacusIcon));
    myNavigatorTreeWidget->addTopLevelItem(aMaterialItem);



}
