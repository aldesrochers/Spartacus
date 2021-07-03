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
#include <Viewer3d_Window.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Viewer3d_Window::Viewer3d_Window(QWidget* theWidget,
                                 const Quantity_NameOfColor theBackgroundColor)
    : Aspect_Window(),
      myWidget(theWidget)
{
    SetBackground(theBackgroundColor);
    myX1 = myWidget->rect().left();
    myY1 = myWidget->rect().top();
    myX2 = myWidget->rect().right();
    myY2 = myWidget->rect().bottom();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Viewer3d_Window::~Viewer3d_Window()
{
    myWidget = nullptr;
}

// ============================================================================
/*!
    \brief DoMapping()
*/
// ============================================================================
Standard_Boolean Viewer3d_Window::DoMapping() const
{
    return Standard_True;
}

// ============================================================================
/*!
    \brief DoResize()
*/
// ============================================================================
Aspect_TypeOfResize Viewer3d_Window::DoResize()
{
    int                 aMask = 0;
    Aspect_TypeOfResize aMode = Aspect_TOR_UNKNOWN;

    if(!myWidget->isMinimized())
    {
          if(Abs(myWidget->rect().left() - myX1) > 2)
              aMask |= 1;
          if(Abs(myWidget->rect().right() - myX2) > 2)
              aMask |= 2;
          if(Abs(myWidget->rect().top() - myY1) > 2)
              aMask |= 4;
          if(Abs(myWidget->rect().bottom() - myY2) > 2)
              aMask |= 8;

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

          myX1   = myWidget->rect().left();
          myX2  = myWidget->rect().right();
          myY1    = myWidget->rect().top();
          myY2 = myWidget->rect().bottom();
    }

    return aMode;
}

// ============================================================================
/*!
    \brief IsMapped()
*/
// ============================================================================
Standard_Boolean Viewer3d_Window::IsMapped() const
{
    return !(myWidget->isMinimized() || myWidget->isHidden());
}

// ============================================================================
/*!
    \brief Map()
*/
// ============================================================================
void Viewer3d_Window::Map() const
{
    myWidget->show();
    myWidget->update();
}

// ============================================================================
/*!
    \brief NativeFBConfig()
*/
// ============================================================================
Aspect_FBConfig Viewer3d_Window::NativeFBConfig() const
{
    return NULL;
}

// ============================================================================
/*!
    \brief NativeHandle()
*/
// ============================================================================
Aspect_Drawable Viewer3d_Window::NativeHandle() const
{
    return (Aspect_Drawable) myWidget->winId();
}

// ============================================================================
/*!
    \brief NativeParentHandle()
*/
// ============================================================================
Aspect_Drawable Viewer3d_Window::NativeParentHandle() const
{
    QWidget* aParent = myWidget->parentWidget();
    if(aParent != nullptr)
        return (Aspect_Drawable) aParent->winId();
    return NULL;
}

// ============================================================================
/*!
    \brief Position()
*/
// ============================================================================
void Viewer3d_Window::Position(Standard_Integer &X1,
                               Standard_Integer &Y1,
                               Standard_Integer &X2,
                               Standard_Integer &Y2) const
{
    X1 = myWidget->rect().left();
    X2 = myWidget->rect().right();
    Y1 = myWidget->rect().top();
    Y2 = myWidget->rect().bottom();
}

// ============================================================================
/*!
    \brief Ratio()
*/
// ============================================================================
Standard_Real Viewer3d_Window::Ratio() const
{
    QRect aRect = myWidget->rect();
    Standard_Real aWidth = aRect.right() - aRect.left();
    Standard_Real aHeight = aRect.bottom() - aRect.top();
    return aWidth/aHeight;
}

// ============================================================================
/*!
    \brief Size()
*/
// ============================================================================
void Viewer3d_Window::Size(Standard_Integer &Width, Standard_Integer &Height) const
{
    QRect aRect = myWidget->rect();
    Width = aRect.width();
    Height = aRect.height();
}

// ============================================================================
/*!
    \brief Unmap()
*/
// ============================================================================
void Viewer3d_Window::Unmap() const
{
    myWidget->hide();
    myWidget->update();
}


// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_RTTIEXT(Viewer3d_Window, Aspect_Window);
