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
#include <QWheelEvent>
#include <QWidget>

// Spartacus
#include <FWR_Manager.hxx>
#include <Viewer3d_MapOfActionBoolean.hxx>
#include <Viewer3d_MapOfActionKey.hxx>
#include <Viewer3d_MapOfActionMouseButton.hxx>
#include <Viewer3d_Zoom.hxx>

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
    // destructors
    ~Viewer3d_ViewWidget();


public:

    void                            activateAction(const Viewer3d_Action theAction,
                                                   const bool isActived);
    void                            enableAction(const Viewer3d_Action theAction,
                                                 const bool isEnabled);
    void                            fitAll();
    Handle(AIS_InteractiveContext)  getContext();
    FWR_Manager*                    getResourcesMgr();
    bool                            isActiveAction(const Viewer3d_Action theAction);
    bool                            isActiveAndEnabledAction(const Viewer3d_Action theAction);
    bool                            isEnabledAction(const Viewer3d_Action theAction);
    virtual QPaintEngine*           paintEngine() const;
    void                            setActionTrigger(const Viewer3d_Action theAction,
                                                     const Qt::Key theKey);
    void                            setActionTrigger(const Viewer3d_Action theAction,
                                                     const Qt::MouseButton theButton);
    void                            setBackgroundColor(const QColor& theColor);
    Viewer3d_Action                 triggeredAction(const Qt::Key theKey);
    Viewer3d_Action                 triggeredAction(const Qt::MouseButton theButton);

protected:

    void                            activateAction(const Viewer3d_Action theAction);
    void                            deactivateAction(const Viewer3d_Action theAction);
    virtual void                    keyPressEvent(QKeyEvent* theEvent);
    virtual void                    keyReleaseEvent(QKeyEvent* theEvent);
    virtual void                    mouseMoveEvent(QMouseEvent* theEvent);
    virtual void                    mousePressEvent(QMouseEvent* theEvent);
    virtual void                    mouseReleaseEvent(QMouseEvent* theEvent);
    virtual void                    paintEvent(QPaintEvent* theEvent);
    virtual QMenu*                  popupMenu();
    virtual void                    resizeEvent(QResizeEvent* theEvent);
    void                            setZoomSpeed(const Viewer3d_ZoomSpeed theZoomSpeed);
    void                            setupAction(const Viewer3d_Action theAction,
                                                const Qt::Key theKey);
    void                            setupAction(const Viewer3d_Action theAction,
                                                const Qt::MouseButton theButton);
    void                            updateView();
    virtual void                    wheelEvent(QWheelEvent* theEvent);

public slots:

    void                            deactivateAllActions();
    void                            selectBackgroundColor();
    void                            showPopupMenu();

private:

    Viewer3d_MapOfActionBoolean             myActiveActions;
    Handle(AIS_InteractiveContext)          myContext;
    Viewer3d_MapOfActionBoolean             myEnabledActions;
    Viewer3d_MapOfActionKey                 myKeyboardTriggers;
    Viewer3d_MapOfActionMouseButton         myMouseTriggers;
    Handle(V3d_View)                        myView;
    Viewer3d_ZoomSpeed                      myZoomSpeed;

};

#endif  // __Viewer3d_ViewWidget_hxx__
