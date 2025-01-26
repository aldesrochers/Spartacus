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


#ifndef __Viewer3d_ViewWindow_hxx__
#define __Viewer3d_ViewWindow_hxx__

// Qt
#include <QWidget>

// OpenCascade
#include <Aspect_Window.hxx>



// ============================================================================
/*!
 *  \brief Viewer3d_ViewWindow
*/
// ============================================================================
class Viewer3d_ViewWindow : public Aspect_Window
{

public:
    // constructors
    Viewer3d_ViewWindow(QWidget* theWidget,
                        const Quantity_NameOfColor theBackgroundColor = Quantity_NOC_ALICEBLUE);
    // destructors
    ~Viewer3d_ViewWindow();


    virtual void                    Destroy();
    virtual Standard_Boolean        DoMapping() const Standard_OVERRIDE;
    virtual Aspect_TypeOfResize     DoResize() Standard_OVERRIDE;
    virtual Standard_Boolean        IsMapped() const Standard_OVERRIDE;
    virtual void                    Map() const Standard_OVERRIDE;
    virtual Aspect_FBConfig         NativeFBConfig() const Standard_OVERRIDE;
    virtual Aspect_Drawable         NativeHandle() const Standard_OVERRIDE;
    virtual Aspect_Drawable         NativeParentHandle() const Standard_OVERRIDE;
    virtual void                    Position(Standard_Integer& theX1,
                                             Standard_Integer& theY1,
                                             Standard_Integer& theX2,
                                             Standard_Integer& theY2) const Standard_OVERRIDE;
    virtual Standard_Real           Ratio() const Standard_OVERRIDE;
    virtual void                    Size(Standard_Integer& theWidth,
                                         Standard_Integer& theHeight) const Standard_OVERRIDE;
    virtual void                    Unmap() const Standard_OVERRIDE;

protected:

    Standard_Integer    myXLeft;
    Standard_Integer    myXRight;
    Standard_Integer    myYTop;
    Standard_Integer    myYBottom;
    QWidget*            myWidget;

public:

    DEFINE_STANDARD_RTTIEXT(Viewer3d_ViewWindow, Aspect_Window);

};


#endif // __Viewer3d_ViewWindow_hxx__
