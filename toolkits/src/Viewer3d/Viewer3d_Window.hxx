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


#ifndef __Viewer3d_Window_hxx__
#define __Viewer3d_Window_hxx__

// OpenCascade
#include <Aspect_Window.hxx>

// Qt
#include <QWidget>


// ============================================================================
/*!
    \brief Viewer3d_Window
*/
// ============================================================================
class Viewer3d_Window : public Aspect_Window
{

public:
    // constructors
    Viewer3d_Window(QWidget* theWidget,
                    const Quantity_NameOfColor theBackgroundColor = Quantity_NOC_ALICEBLUE);
    // destructors
    ~Viewer3d_Window();

public:

    virtual Standard_Boolean        DoMapping() const;
    virtual Aspect_TypeOfResize     DoResize();
    virtual Standard_Boolean        IsMapped() const;
    virtual void                    Map() const;
    virtual Aspect_FBConfig         NativeFBConfig() const Standard_OVERRIDE;
    virtual Aspect_Drawable         NativeHandle() const;
    virtual Aspect_Drawable         NativeParentHandle() const;
    virtual void                    Position(Standard_Integer& X1,
                                             Standard_Integer& Y1,
                                             Standard_Integer& X2,
                                             Standard_Integer& Y2) const;
    virtual Standard_Real           Ratio() const;
    virtual void                    Size(Standard_Integer& Width,
                                         Standard_Integer& Height) const;
    virtual void                    Unmap() const;

public:

    DEFINE_STANDARD_RTTIEXT(Viewer3d_Window, Aspect_Window);

protected:

    Standard_Integer        myX1;
    Standard_Integer        myY1;
    Standard_Integer        myX2;
    Standard_Integer        myY2;
    QWidget*                myWidget;

};


#endif  // __Viewer3d_Window_hxx__
