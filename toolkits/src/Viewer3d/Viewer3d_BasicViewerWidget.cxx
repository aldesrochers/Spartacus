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
#include <FWR_Manager.hxx>
#include <Viewer3d_BasicViewerWidget.hxx>
#include <Viewer3d_ViewSettingsDialog.hxx>
#include <Viewer3d_Utilities.hxx>

// Qt
#include <QColorDialog>
#include <QToolBar>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Viewer3d_BasicViewerWidget::Viewer3d_BasicViewerWidget(QWidget* theParent)
    : QMainWindow(theParent)
{
    // create toolbars
    createToolbar();
    // initialize a viewer
    myViewer = Viewer3d_Utilities::createViewer();
    // initialize a context
    myContext = new AIS_InteractiveContext(myViewer);
    // initialize a view
    myViewWidget = new Viewer3d_ViewWidget(myContext);
    setCentralWidget(myViewWidget);
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Viewer3d_BasicViewerWidget::~Viewer3d_BasicViewerWidget()
{

}

// ============================================================================
/*!
 *  \brief createToolbar()
*/
// ============================================================================
void Viewer3d_BasicViewerWidget::createToolbar()
{
    // get a reference to the resources manager
    FWR_Manager* aResMgr = FWR_Manager::Manager();

    // initialize a toolbar
    QToolBar* aToolBar = new QToolBar("Viewer3d_BasicViewerWidget");


    // action : background color
    QAction* bgColor = aToolBar->addAction(tr("Background Color"));
    bgColor->setIcon(aResMgr->GetIcon(FWR_ColorPicker));
    bgColor->setToolTip(tr("Background Color"));
    connect(bgColor, SIGNAL(triggered()), this, SLOT(openColorPickerDialog()));

    // separator
    aToolBar->addSeparator();

    // action : settings
    QAction* settings = aToolBar->addAction(tr("Settings"));
    settings->setIcon(aResMgr->GetIcon(FWR_ViewSettings));
    settings->setToolTip(tr("Settings"));
    connect(settings, SIGNAL(triggered()), this, SLOT(openViewSettingsDialog()));

    // setup & create toolbar
    setToolButtonStyle(Qt::ToolButtonIconOnly);
    addToolBar(Qt::TopToolBarArea, aToolBar);
}

// ============================================================================
/*!
 *  \brief getContext()
*/
// ============================================================================
Handle(AIS_InteractiveContext) Viewer3d_BasicViewerWidget::getContext()
{
    return myContext;
}

// ============================================================================
/*!
 *  \brief openColorPickerDialog()
*/
// ============================================================================
void Viewer3d_BasicViewerWidget::openColorPickerDialog()
{
    QColorDialog* aDialog = new QColorDialog(this);
    QColor aColor = aDialog->getColor(Qt::gray);
    myViewWidget->setBackgroundColor(aColor);
}

// ============================================================================
/*!
 *  \brief openViewSettingsDialog()
*/
// ============================================================================
void Viewer3d_BasicViewerWidget::openViewSettingsDialog()
{
    Viewer3d_ViewSettingsDialog* aDialog
            = new Viewer3d_ViewSettingsDialog(myViewWidget);
    aDialog->show();
}
