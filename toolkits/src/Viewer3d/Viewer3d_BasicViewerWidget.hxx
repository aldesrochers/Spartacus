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


#ifndef __Viewer3d_BasicViewerWidget_hxx__
#define __Viewer3d_BasicViewerWidget_hxx__

// Qt
#include <QMainWindow>

// OpenCascade
#include <AIS_InteractiveContext.hxx>
#include <V3d_Viewer.hxx>

// Spartacus
#include <Viewer3d_ViewWidget.hxx>


// ============================================================================
/*!
 *  \brief Viewer3d_BasicViewerWidget
 *  Class implementation of a basic viewer widget. A viewer widget manage
 *  a single view inside a main window.
*/
// ============================================================================
class Viewer3d_BasicViewerWidget : public QMainWindow
{
    Q_OBJECT

public:
    // constructors
    Viewer3d_BasicViewerWidget(QWidget* theParent = 0);
    // destructors
    ~Viewer3d_BasicViewerWidget();

public:

    Handle(AIS_InteractiveContext)  getContext();
    Viewer3d_ViewWidget*            getViewWidget();
    Handle(V3d_Viewer)              getViewer();

protected:

    virtual void                    createToolbar();

private slots:

    void                            openColorPickerDialog();
    void                            openViewSettingsDialog();

private:

    Handle(AIS_InteractiveContext)  myContext;
    Viewer3d_ViewWidget*            myViewWidget;
    Handle(V3d_Viewer)              myViewer;

};

#endif  // __Viewer3d_BasicViewerWidget_hxx__
