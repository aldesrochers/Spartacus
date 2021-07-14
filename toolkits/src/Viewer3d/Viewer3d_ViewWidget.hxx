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


#ifndef __Viewer3d_ViewWidget_hxx__
#define __Viewer3d_ViewWidget_hxx__

// Qt
#include <QAction>
#include <QColor>
#include <QKeyEvent>
#include <QMap>
#include <QMouseEvent>
#include <QRgb>
#include <QSettings>
#include <QWheelEvent>
#include <QWidget>

// Spartacus
#include <FWR_Manager.hxx>
#include <Viewer3d_Action.hxx>

// OpenCascade
#include <AIS_InteractiveContext.hxx>
#include <V3d_View.hxx>


// ============================================================================
/*!
    \brief Viewer3d_ViewWidget
    Class implementation of an OCCT view widget.
*/
// ============================================================================
class Standard_EXPORT Viewer3d_ViewWidget : public QWidget
{
    Q_OBJECT

public:
    // constructors
    Viewer3d_ViewWidget(Handle(AIS_InteractiveContext) theContext,
                        QWidget* theParent = 0);
    Viewer3d_ViewWidget(Handle(AIS_InteractiveContext) theContext,
                        QSettings* theSettings,
                        QWidget* theParent = 0);
    // destructors
    ~Viewer3d_ViewWidget();


public:

    QColor                          backgroundColor() const;
    virtual QPaintEngine*           paintEngine() const;
    void                            setBackgroundColor(const QColor& theColor);

protected:

    virtual void                    keyPressEvent(QKeyEvent* theEvent);
    virtual void                    keyReleaseEvent(QKeyEvent* theEvent);
    virtual void                    mouseMoveEvent(QMouseEvent* theEvent);
    virtual void                    mousePressEvent(QMouseEvent* theEvent);
    virtual void                    mouseReleaseEvent(QMouseEvent* theEvent);
    virtual void                    paintEvent(QPaintEvent* theEvent);
    virtual void                    resizeEvent(QResizeEvent* theEvent);
    virtual void                    wheelEvent(QWheelEvent* theEvent);

private:

    Viewer3d_Action                 currentAction() const;
    void                            initialize();
    void                            setCurrentAction(const Viewer3d_Action& theAction);

private:

    Handle(AIS_InteractiveContext)          myContext;
    Viewer3d_Action                         myCurrentAction;
    QSettings*                              mySettings;
    Handle(V3d_View)                        myView;

};

#endif  // __Viewer3d_ViewWidget_hxx__
