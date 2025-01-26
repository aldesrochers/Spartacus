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
#include <Viewer3d.hxx>
#include <Viewer3d_View.hxx>
#include <Viewer3d_ViewWindow.hxx>

// Qt
#include <QMouseEvent>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Viewer3d_View::Viewer3d_View(QWidget* theParent)
    : QWidget(theParent)
{
    initialize();
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Viewer3d_View::~Viewer3d_View()
{

}

// ============================================================================
/*!
 *  \brief context()
*/
// ============================================================================
Handle(AIS_InteractiveContext) Viewer3d_View::context()
{
    return myContext;
}

// ============================================================================
/*!
 *  \brief fitAll()
*/
// ============================================================================
void Viewer3d_View::fitAll()
{
    if(myView.IsNull())
        return;
    myView->FitAll();
    myView->ZFitAll();
}

// ============================================================================
/*!
 *  \brief initialize()
*/
// ============================================================================
void Viewer3d_View::initialize()
{
    // initialize attributes
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_NativeWindow);
    setBackgroundRole(QPalette::NoRole);
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);

    // initialize view
    myViewer = Viewer3d::CreateViewer();
    myContext = new AIS_InteractiveContext(myViewer);
    myView = new V3d_View(myViewer);

    Handle(Viewer3d_ViewWindow) hWnd = new Viewer3d_ViewWindow(this);
    myView->SetWindow(hWnd);
    if (!hWnd->IsMapped())
        hWnd->Map();
}

// ============================================================================
/*!
 *  \brief mouseMoveEvent()
*/
// ============================================================================
void Viewer3d_View::mouseMoveEvent(QMouseEvent *theEvent)
{
    myView->Rotation(theEvent->position().x(), theEvent->position().y());
}

// ============================================================================
/*!
 *  \brief mousePressEvent()
*/
// ============================================================================
void Viewer3d_View::mousePressEvent(QMouseEvent *theEvent)
{
    if(theEvent->button() == Qt::RightButton)
        myView->StartRotation(theEvent->pos().x(), theEvent->pos().y());
}

// ============================================================================
/*!
 *  \brief mouseReleaseEvent()
*/
// ============================================================================
void Viewer3d_View::mouseReleaseEvent(QMouseEvent *theEvent)
{

}

// ============================================================================
/*!
 *  \brief paintEngine()
*/
// ============================================================================
QPaintEngine* Viewer3d_View::paintEngine() const
{
    return nullptr;
}

// ============================================================================
/*!
 *  \brief paintEvent()
*/
// ============================================================================
void Viewer3d_View::paintEvent(QPaintEvent *theEvent)
{
    if(myView.IsNull())
        return;
    myView->InvalidateImmediate();
    //FlushViewEvents(myContext, myView, true);
}

// ============================================================================
/*!
 *  \brief resizeEvent()
*/
// ============================================================================
void Viewer3d_View::resizeEvent(QResizeEvent *theEvent)
{
    if(!myView.IsNull())
        myView->MustBeResized();
}

// ============================================================================
/*!
 *  \brief setBackgroundColor()
 *  Set view's background color.
*/
// ============================================================================
void Viewer3d_View::setBackgroundColor(const QColor &theColor)
{
    if(myView.IsNull())
        return;
    Standard_Real V1 = (Standard_Real) theColor.redF();
    Standard_Real V2 = (Standard_Real) theColor.greenF();
    Standard_Real V3 = (Standard_Real) theColor.blueF();
    myView->SetBackgroundColor(Quantity_TOC_RGB, V1, V2, V3);
}

// ============================================================================
/*!
 *  \brief view()
*/
// ============================================================================
Handle(V3d_View) Viewer3d_View::view()
{
    return myView;
}

