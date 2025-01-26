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
#include <Viewer3d_ViewWindow.hxx>



// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Viewer3d_ViewWindow::Viewer3d_ViewWindow(QWidget* theWidget,
                                         const Quantity_NameOfColor theBackgroundColor)
    : Aspect_Window(),
      myWidget(theWidget)
{
    SetBackground(theBackgroundColor);
    myXLeft   = myWidget->rect().left();
    myYTop    = myWidget->rect().top();
    myXRight  = myWidget->rect().right();
    myYBottom = myWidget->rect().bottom();
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Viewer3d_ViewWindow::~Viewer3d_ViewWindow()
{
    Destroy();
}

// ============================================================================
/*!
 *  \brief Destroy()
*/
// ============================================================================
void Viewer3d_ViewWindow::Destroy()
{
  myWidget = NULL;
}

// ============================================================================
/*!
 *  \brief DoMapping()
*/
// ============================================================================
Standard_Boolean Viewer3d_ViewWindow::DoMapping() const
{
    return Standard_True;
}

// ============================================================================
/*!
 *  \brief DoResize()
*/
// ============================================================================
Aspect_TypeOfResize Viewer3d_ViewWindow::DoResize()
{
    int                 aMask = 0;
    Aspect_TypeOfResize aMode = Aspect_TOR_UNKNOWN;

    if (!myWidget->isMinimized()) {
        if (Abs(myWidget->rect().left()   - myXLeft   ) > 2 ) aMask |= 1;
        if (Abs(myWidget->rect().right()  - myXRight  ) > 2 ) aMask |= 2;
        if (Abs(myWidget->rect().top()    - myYTop    ) > 2 ) aMask |= 4;
        if (Abs(myWidget->rect().bottom() - myYBottom ) > 2 ) aMask |= 8;

        switch (aMask) {
            case 0:
                aMode = Aspect_TOR_NO_BORDER;
                break;
            case 1:
                aMode = Aspect_TOR_LEFT_BORDER;
                break;
            case 2:
                aMode = Aspect_TOR_RIGHT_BORDER;
                break;
            case 4:
                aMode = Aspect_TOR_TOP_BORDER;
                break;
            case 5:
                aMode = Aspect_TOR_LEFT_AND_TOP_BORDER;
                break;
            case 6:
                aMode = Aspect_TOR_TOP_AND_RIGHT_BORDER;
                break;
            case 8:
                aMode = Aspect_TOR_BOTTOM_BORDER;
                break;
            case 9:
                aMode = Aspect_TOR_BOTTOM_AND_LEFT_BORDER;
                break;
            case 10:
                aMode = Aspect_TOR_RIGHT_AND_BOTTOM_BORDER;
                break;
            default:
                break;
        }

        myXLeft   = myWidget->rect().left();
        myXRight  = myWidget->rect().right();
        myYTop    = myWidget->rect().top();
        myYBottom = myWidget->rect().bottom();
    }

    return aMode;
}

// ============================================================================
/*!
 *  \brief IsMapped()
*/
// ============================================================================
Standard_Boolean Viewer3d_ViewWindow::IsMapped() const
{
    return !(myWidget->isMinimized() || myWidget->isHidden());
}

// ============================================================================
/*!
 *  \brief Map()
*/
// ============================================================================
void Viewer3d_ViewWindow::Map() const
{
    myWidget->show();
    myWidget->update();
}

// ============================================================================
/*!
 *  \brief NativeFBConfig()
*/
// ============================================================================
Aspect_FBConfig Viewer3d_ViewWindow::NativeFBConfig() const
{
    return NULL;
}

// ============================================================================
/*!
 *  \brief NativeHandle()
*/
// ============================================================================
Aspect_Drawable Viewer3d_ViewWindow::NativeHandle() const
{
    return (Aspect_Drawable) myWidget->winId();
}

// ============================================================================
/*!
 *  \brief NativeParentHandle()
*/
// ============================================================================
Aspect_Drawable Viewer3d_ViewWindow::NativeParentHandle() const
{
    QWidget* aParentWidget = myWidget->parentWidget();
    if (aParentWidget != NULL)
        return (Aspect_Drawable)aParentWidget->winId();
    else
        return 0;
}

// ============================================================================
/*!
 *  \brief Position()
*/
// ============================================================================
void Viewer3d_ViewWindow::Position(Standard_Integer& theX1,
                                   Standard_Integer& theY1,
                                   Standard_Integer& theX2,
                                   Standard_Integer& theY2) const
{
    theX1 = myWidget->rect().left();
    theX2 = myWidget->rect().right();
    theY1 = myWidget->rect().top();
    theY2 = myWidget->rect().bottom();
}

// ============================================================================
/*!
 *  \brief Ratio()
*/
// ============================================================================
Standard_Real Viewer3d_ViewWindow::Ratio() const
{
    QRect aRect = myWidget->rect();
    Standard_Real dX(aRect.right() - aRect.left());
    Standard_Real dY(aRect.bottom() - aRect.top());
    return Standard_Real(dX/dY);
}

// ============================================================================
/*!
 *  \brief Size()
*/
// ============================================================================
void Viewer3d_ViewWindow::Size(Standard_Integer& theWidth,
                               Standard_Integer& theHeight) const
{
    QRect aRect = myWidget->rect();
    theWidth  = aRect.width();
    theHeight = aRect.height();
}

// ============================================================================
/*!
 *  \brief Unmap()
*/
// ============================================================================
void Viewer3d_ViewWindow::Unmap() const
{
    myWidget->hide();
    myWidget->update();
}




// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_RTTIEXT(Viewer3d_ViewWindow, Aspect_Window);
