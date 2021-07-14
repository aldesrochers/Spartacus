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
#include <FW_StandardPaths.hxx>
#include <Viewer3d_ViewSettingsDialog.hxx>
#include <Viewer3d_ViewWidget.hxx>
#include <Viewer3d_Window.hxx>

// Qt
#include <QColorDialog>
#include <QDebug>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Viewer3d_ViewWidget::Viewer3d_ViewWidget(Handle(AIS_InteractiveContext) theContext,
                                         QWidget* theParent)
    : QWidget(theParent),
      myContext(theContext)
{
    // use default view settings
    QString aPath = FW_StandardPaths::UserFilePath("ViewWidget_BasicSettings.ini");
    mySettings = new QSettings(aPath, QSettings::IniFormat);

    // initialize
    initialize();
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Viewer3d_ViewWidget::Viewer3d_ViewWidget(Handle(AIS_InteractiveContext) theContext,
                                         QSettings* theSettings,
                                         QWidget* theParent)
    : QWidget(theParent),
      myContext(theContext),
      mySettings(theSettings)
{
    // initialize
    initialize();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Viewer3d_ViewWidget::~Viewer3d_ViewWidget()
{

}

// ============================================================================
/*!
 *  \brief backgroundColor()
*/
// ============================================================================
QColor Viewer3d_ViewWidget::backgroundColor() const
{
    Standard_Real R, G, B;
    myView->BackgroundColor(Quantity_TOC_RGB, R, G, B);
    QColor aColor(R, G, B);
    return aColor;
}

// ============================================================================
/*!
 *  \brief currentAction()
*/
// ============================================================================
Viewer3d_Action Viewer3d_ViewWidget::currentAction() const
{
    return myCurrentAction;
}

// ============================================================================
/*!
    \brief keyPressEvent()
    Used to active action defined by keyboard triggers.
*/
// ============================================================================
void Viewer3d_ViewWidget::keyPressEvent(QKeyEvent *theEvent)
{

}

// ============================================================================
/*!
    \brief keyReleaseEvent()
*/
// ============================================================================
void Viewer3d_ViewWidget::keyReleaseEvent(QKeyEvent *theEvent)
{

}

// ============================================================================
/*!
 *  \brief initialize()
*/
// ============================================================================
void Viewer3d_ViewWidget::initialize()
{
#if !defined(_WIN32) && (!defined(__APPLE__) || defined(MACOSX_USE_GLX)) && QT_VERSION < 0x050000
    XSynchronize(x11Info().display(),true);
#endif

    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_NoSystemBackground);
    setBackgroundRole(QPalette::NoRole);
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);

    if(myView.IsNull())
        myView = myContext->CurrentViewer()->CreateView();

    Handle(Viewer3d_Window) aWindow = new Viewer3d_Window(this);
    myView->SetWindow(aWindow);
    if(!aWindow->IsMapped())
        aWindow->Map();

    myView->MustBeResized();
    myView->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_BLACK, 0.1);

    // action
    myCurrentAction = Viewer3d_NoAction;

}

// ============================================================================
/*!
    \brief mouseMoveEvent()
*/
// ============================================================================
void Viewer3d_ViewWidget::mouseMoveEvent(QMouseEvent *theEvent)
{
    // retrieve cursor position
    QPoint aPoint = theEvent->pos();
    Standard_Real X = (Standard_Real) aPoint.x();
    Standard_Real Y = (Standard_Real) aPoint.y();

    if(myCurrentAction == Viewer3d_RotateAction) {
        myView->Rotation(X, Y);
    } else if(myCurrentAction == Viewer3d_MoveAction) {

    }
}

// ============================================================================
/*!
    \brief mousePressEvent()
*/
// ============================================================================
void Viewer3d_ViewWidget::mousePressEvent(QMouseEvent *theEvent)
{
    // retrieve cursor position
    QPoint aPoint = theEvent->pos();
    Standard_Real X = (Standard_Real) aPoint.x();
    Standard_Real Y = (Standard_Real) aPoint.y();

    if(theEvent->button() == Qt::RightButton) {
        myView->StartRotation(X, Y);
        myCurrentAction = Viewer3d_RotateAction;
    } else if(theEvent->button() == Qt::MiddleButton) {
        myCurrentAction = Viewer3d_MoveAction;
    }

}

// ============================================================================
/*!
    \brief mouseReleaseEvent()
*/
// ============================================================================
void Viewer3d_ViewWidget::mouseReleaseEvent(QMouseEvent *theEvent)
{
    if(theEvent->button() == Qt::RightButton)
        myCurrentAction = Viewer3d_NoAction;
    else if(theEvent->button() == Qt::MiddleButton)
        myCurrentAction = Viewer3d_NoAction;
}

// ============================================================================
/*!
    \brief paintEvent()
*/
// ============================================================================
void Viewer3d_ViewWidget::paintEvent(QPaintEvent *theEvent)
{
    myView->InvalidateImmediate();
    myView->Redraw();
}

// ============================================================================
/*!
    \brief paintEngine()
*/
// ============================================================================
QPaintEngine* Viewer3d_ViewWidget::paintEngine() const
{
    return NULL;
}

// ============================================================================
/*!
    \brief resizeEvent()
*/
// ============================================================================
void Viewer3d_ViewWidget::resizeEvent(QResizeEvent *theEvent)
{
    if(!myView.IsNull())
        myView->MustBeResized();
}

// ============================================================================
/*!
 *  \brief setBackgroundColor()
*/
// ============================================================================
void Viewer3d_ViewWidget::setBackgroundColor(const QColor &theColor)
{
    Standard_Real R = (Standard_Real) theColor.redF();
    Standard_Real G = (Standard_Real) theColor.greenF();
    Standard_Real B = (Standard_Real) theColor.blueF();
    myView->SetBackgroundColor(Quantity_TOC_RGB, R, G, B);
}

// ============================================================================
/*!
 *  \brief setCurrentAction()
*/
// ============================================================================
void Viewer3d_ViewWidget::setCurrentAction(const Viewer3d_Action &theAction)
{
    myCurrentAction = theAction;
}

// ============================================================================
/*!
    \brief wheelEvent()
    Wheel event are only used to process zoom at point.
*/
// ============================================================================
void Viewer3d_ViewWidget::wheelEvent(QWheelEvent *theEvent)
{
    QPointF aPoint = theEvent->position();
    QPoint aDelta = theEvent->angleDelta();
    Standard_Real Xi = (Standard_Real) aPoint.x();
    Standard_Real Yi = (Standard_Real) aPoint.y();
    Standard_Real Xj = Xi;
    Standard_Real Yj = Yi + (Standard_Real) aDelta.y();
    myView->StartZoomAtPoint(Xi, Yi);
    myView->ZoomAtPoint(Xi, Yi, Xj, Yj);
}


