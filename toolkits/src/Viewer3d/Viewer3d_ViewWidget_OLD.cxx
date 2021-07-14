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
#include <Viewer3d_ViewWidget.hxx>
#include <Viewer3d_Window.hxx>

// Qt
#include <QColor>
#include <QColorDialog>
#include <QCursor>
#include <QDebug>
#include <QMenu>
#include <QRgb>

// OpenCascade
#include <Aspect_ScrollDelta.hxx>
#include <Graphic3d_Vec2.hxx>
#include <OpenGl_GraphicDriver.hxx>


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


    // setup
    setupAction(Viewer3d_PopupAction, Qt::RightButton);
    setupAction(Viewer3d_RotateAction, Qt::Key_Control);
    setupAction(Viewer3d_ZoomOnPointAction, Qt::LeftButton);
    setZoomSpeed(Viewer3d_ZoomSpeed4);
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
    \brief activateAction()
*/
// ============================================================================
void Viewer3d_ViewWidget::activateAction(const Viewer3d_Action theAction,
                                         const bool isActived)
{
    myActiveActions.insert(theAction, isActived);
}

// ============================================================================
/*!
    \brief activateAction()
*/
// ============================================================================
void Viewer3d_ViewWidget::activateAction(const Viewer3d_Action theAction)
{
    activateAction(theAction, true);
}

// ============================================================================
/*!
    \brief deactivateAction()
*/
// ============================================================================
void Viewer3d_ViewWidget::deactivateAction(const Viewer3d_Action theAction)
{
    activateAction(theAction, false);
}

// ============================================================================
/*!
 *  \brief deactivateAllActions()
*/
// ============================================================================
void Viewer3d_ViewWidget::deactivateAllActions()
{
    Viewer3d_MapOfActionBoolean::iterator anIt;
    for(anIt = myActiveActions.begin(); anIt != myActiveActions.end(); anIt++) {
        myActiveActions.insert(anIt.key(), false);
    }
}

// ============================================================================
/*!
    \brief enableAction()
    Set the 'enabled' flag on actions.
*/
// ============================================================================
void Viewer3d_ViewWidget::enableAction(const Viewer3d_Action theAction,
                                       const bool isEnabled)
{
    myEnabledActions.insert(theAction, isEnabled);
}

// ============================================================================
/*!
    \brief fitAll()
    Fit the view within the widget.
*/
// ============================================================================
void Viewer3d_ViewWidget::fitAll()
{
    if(myView.IsNull())
        return;
    myView->FitAll();
    myView->ZFitAll();
    myView->Redraw();
}

// ============================================================================
/*!
    \brief getContext()
*/
// ============================================================================
Handle(AIS_InteractiveContext) Viewer3d_ViewWidget::getContext()
{
    return myContext;
}

// ============================================================================
/*!
    \brief getResourcesMgr()
    Convenient shortcut to the framework resources manager.
*/
// ============================================================================
FWR_Manager* Viewer3d_ViewWidget::getResourcesMgr()
{
    return FWR_Manager::Manager();
}

// ============================================================================
/*!
    \brief isActiveAction()
*/
// ============================================================================
bool Viewer3d_ViewWidget::isActiveAction(const Viewer3d_Action theAction)
{
    if(!myActiveActions.contains(theAction))
        return false;
    return myActiveActions.value(theAction);
}

// ============================================================================
/*!
    \brief isActiveAndEnabledAction()
*/
// ============================================================================
bool Viewer3d_ViewWidget::isActiveAndEnabledAction(const Viewer3d_Action theAction)
{
    if(isEnabledAction(theAction) && isActiveAction(theAction))
        return true;
    return false;
}

// ============================================================================
/*!
    \brief isEnabledAction()
    Check if an action is enabled.
*/
// ============================================================================
bool Viewer3d_ViewWidget::isEnabledAction(const Viewer3d_Action theAction)
{
    if(!myEnabledActions.contains(theAction))
        return false;
    return myEnabledActions.value(theAction);
}

// ============================================================================
/*!
    \brief keyPressEvent()
    Used to active action defined by keyboard triggers.
*/
// ============================================================================
void Viewer3d_ViewWidget::keyPressEvent(QKeyEvent *theEvent)
{
    if(myView.IsNull())
        return;
    Qt::Key aKey = (Qt::Key) theEvent->key();
    Viewer3d_Action anAction = triggeredAction(aKey);
    if(!isEnabledAction(anAction))
        return;

    if(anAction == Viewer3d_PopupAction) {
        showPopupMenu();
    } else if(anAction == Viewer3d_RotateAction) {
        myView->StartRotation(QCursor::pos().x(), QCursor::pos().y());
        activateAction(Viewer3d_RotateAction);
    }
}

// ============================================================================
/*!
    \brief keyReleaseEvent()
*/
// ============================================================================
void Viewer3d_ViewWidget::keyReleaseEvent(QKeyEvent *theEvent)
{
    if(myView.IsNull())
        return;
    Qt::Key aKey = (Qt::Key) theEvent->key();
    Viewer3d_Action anAction = triggeredAction(aKey);

    if(anAction == Viewer3d_RotateAction) {
        deactivateAction(anAction);
    }
}

// ============================================================================
/*!
    \brief mouseMoveEvent()
*/
// ============================================================================
void Viewer3d_ViewWidget::mouseMoveEvent(QMouseEvent *theEvent)
{
    if(myView.IsNull())
        return;

    // rotate ?
    if(isActiveAndEnabledAction(Viewer3d_RotateAction)) {
        myView->Rotation(theEvent->pos().x(), theEvent->pos().y());
    }
}

// ============================================================================
/*!
    \brief mousePressEvent()
*/
// ============================================================================
void Viewer3d_ViewWidget::mousePressEvent(QMouseEvent *theEvent)
{
    if(myView.IsNull())
        return;
    Qt::MouseButton aButton = (Qt::MouseButton) theEvent->button();
    Viewer3d_Action anAction = triggeredAction(aButton);
    if(!isEnabledAction(anAction))
        return;

    if(anAction == Viewer3d_PopupAction) {
        showPopupMenu();
    } else if(anAction == Viewer3d_ZoomOnPointAction) {
        myView->StartZoomAtPoint(QCursor::pos().x(), QCursor::pos().y());
        activateAction(Viewer3d_ZoomOnPointAction);
    }
}

// ============================================================================
/*!
    \brief mouseReleaseEvent()
*/
// ============================================================================
void Viewer3d_ViewWidget::mouseReleaseEvent(QMouseEvent *theEvent)
{
    if(myView.IsNull())
        return;

    if(isActiveAndEnabledAction(Viewer3d_ZoomOnPointAction)) {
        deactivateAction(Viewer3d_ZoomOnPointAction);
    }
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
    \brief popupMenu()
*/
// ============================================================================
QMenu* Viewer3d_ViewWidget::popupMenu()
{
    QMenu* aMenu = new QMenu(this);

    // action : fitAll
    QAction* fitAll = aMenu->addAction(getResourcesMgr()->GetIcon(FWR_ViewFitAllIcon),
                                       tr("Fit All"));
    connect(fitAll, SIGNAL(triggered()), this, SLOT(fitAll()));

    // separator
    aMenu->addSeparator();

    // action : background color
    QAction* bgColor = aMenu->addAction(getResourcesMgr()->GetIcon(FWR_ColorPicker),
                                        tr("Background Color"));
    connect(bgColor, SIGNAL(triggered()), this, SLOT(selectBackgroundColor()));

    // separator
    aMenu->addSeparator();

    // zoom speed modifier menu
    QMenu* zoomSpeedMenu = aMenu->addMenu(getResourcesMgr()->GetIcon(FWR_ViewZoomSettings),
                                          tr("Zoom"));
    for(int i=0; i<=6; i++) {
        QString aName = tr("Zoom Speed %1").arg(i);
        QAction* anAction = new QAction(aName);
        if(i == 0)
            anAction->setIcon(getResourcesMgr()->GetIcon(FWR_MinusIcon));
        if(i == 6)
            anAction->setIcon(getResourcesMgr()->GetIcon(FWR_PlusIcon));
        zoomSpeedMenu->addAction(anAction);
        Viewer3d_ZoomSpeed aSpeed = (Viewer3d_ZoomSpeed) i;
    }

    return aMenu;
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
    \brief setActionTrigger()
*/
// ============================================================================
void Viewer3d_ViewWidget::setActionTrigger(const Viewer3d_Action theAction,
                                           const Qt::Key theKey)
{
    // make sure there's only one trigger per action,
    // remove from mouse triggers
    if(myMouseTriggers.contains(theAction))
        myMouseTriggers.remove(theAction);
    // add in keyboard triggers
    myKeyboardTriggers.insert(theAction, theKey);
}

// ============================================================================
/*!
    \brief setActionTrigger()
*/
// ============================================================================
void Viewer3d_ViewWidget::setActionTrigger(const Viewer3d_Action theAction,
                                           const Qt::MouseButton theButton)
{
    // make sure there's only one trigger per action,
    // remove from keyboard triggers
    if(myKeyboardTriggers.contains(theAction))
        myKeyboardTriggers.remove(theAction);
    // add in mouse triggers
    myMouseTriggers.insert(theAction, theButton);
}

// ============================================================================
/*!
    \brief selectBackgroundColor()
    Use a QColorDialog to select and change the view background color.
*/
// ============================================================================
void Viewer3d_ViewWidget::selectBackgroundColor()
{
    QColorDialog* aDlg = new QColorDialog(this);
    QColor aColor = aDlg->getColor(Qt::gray);
    if(aColor.isValid())
        setBackgroundColor(aColor);
}

// ============================================================================
/*!
    \brief setBackgroundColor()
*/
// ============================================================================
void Viewer3d_ViewWidget::setBackgroundColor(const QColor &theColor)
{
    Standard_Real C1 = (Standard_Real) theColor.redF();
    Standard_Real C2 = (Standard_Real) theColor.greenF();
    Standard_Real C3 = (Standard_Real) theColor.blueF();
    Quantity_Color aColor(C1, C2, C3, Quantity_TOC_RGB);
    myView->SetBackgroundColor(aColor);
    myView->Redraw();
}

// ============================================================================
/*!
    \brief setupAction()
    Initialize an action with a custom trigger, set enabled flag.
*/
// ============================================================================
void Viewer3d_ViewWidget::setupAction(const Viewer3d_Action theAction,
                                      const Qt::Key theKey)
{
    setActionTrigger(theAction, theKey);
    enableAction(theAction, true);
}

// ============================================================================
/*!
    \brief setupAction()
    Initialize an action with a custom trigger, set enabled flag.
*/
// ============================================================================
void Viewer3d_ViewWidget::setupAction(const Viewer3d_Action theAction,
                                      const Qt::MouseButton theButton)
{
    setActionTrigger(theAction, theButton);
    enableAction(theAction, true);
}

// ============================================================================
/*!
    \brief setZoomSpeed()
*/
// ============================================================================
void Viewer3d_ViewWidget::setZoomSpeed(const Viewer3d_ZoomSpeed theZoomSpeed)
{
    myZoomSpeed = theZoomSpeed;
}

// ============================================================================
/*!
    \brief showPopupMenu()
*/
// ============================================================================
void Viewer3d_ViewWidget::showPopupMenu()
{
    QMenu* aMenu = popupMenu();
    aMenu->exec(QCursor::pos());
}

// ============================================================================
/*!
    \brief updateView()
*/
// ============================================================================
void Viewer3d_ViewWidget::updateView()
{
    if(myView.IsNull())
        return;
    update();
}

// ============================================================================
/*!
    \brief triggeredAction()
    Check in keyboard triggers if an action is associated with a key.
*/
// ============================================================================
Viewer3d_Action Viewer3d_ViewWidget::triggeredAction(const Qt::Key theKey)
{
    Viewer3d_MapOfActionKey::iterator anIt;
    for(anIt = myKeyboardTriggers.begin(); anIt != myKeyboardTriggers.end(); anIt++) {
        if(anIt.value() == theKey)
            return anIt.key();
    }
    return Viewer3d_NoAction;
}

// ============================================================================
/*!
    \brief triggeredAction()
    Check in mouse triggers if an action is associated with a button.
*/
// ============================================================================
Viewer3d_Action Viewer3d_ViewWidget::triggeredAction(const Qt::MouseButton theButton)
{
    Viewer3d_MapOfActionMouseButton::iterator anIt;
    for(anIt = myMouseTriggers.begin(); anIt != myMouseTriggers.end(); anIt++) {
        if(anIt.value() == theButton)
            return anIt.key();
    }
    return Viewer3d_NoAction;
}

// ============================================================================
/*!
    \brief wheelEvent()
*/
// ============================================================================
void Viewer3d_ViewWidget::wheelEvent(QWheelEvent *theEvent)
{
    if(myView.IsNull())
        return;
    Standard_Real Coef = (Standard_Real) getZoomCoefficient(myZoomSpeed);
    Standard_Integer Delta = theEvent->angleDelta().y();
    Standard_Integer X1 = (Standard_Integer) theEvent->position().x();
    Standard_Integer Y1 = (Standard_Integer) theEvent->position().y();
    Standard_Integer X2 = X1 + width() * Delta * Coef;
    Standard_Integer Y2 = Y1 + height() * Delta * Coef;

    if(isActiveAndEnabledAction(Viewer3d_ZoomOnPointAction)) {
        // zoom on point
        myView->ZoomAtPoint(X1, Y1, X2, Y2);
    } else {
        // classic zoom
        myView->Zoom(X1, Y1, X2, Y2);
    }

    myView->Redraw();
}
