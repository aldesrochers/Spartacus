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


#ifndef __Viewer3d_View_hxx__
#define __Viewer3d_View_hxx__

// Qt
#include <QColor>
#include <QWidget>

// OpenCascade
#include <AIS_InteractiveContext.hxx>
#include <AIS_ViewController.hxx>
#include <V3d_View.hxx>


// ============================================================================
/*!
 *  \brief Viewer3d_View
 *  Class implementation of a view.
*/
// ============================================================================
class Standard_EXPORT Viewer3d_View : public QWidget, protected AIS_ViewController
{
    Q_OBJECT

public:
    // constructors
    Viewer3d_View(QWidget* theParent = nullptr);
    // destructors
    ~Viewer3d_View();

public:

    virtual QPaintEngine*           paintEngine() const override;

public:

    Handle(AIS_InteractiveContext)  context();
    void                            initialize();
    void                            setBackgroundColor(const QColor& theColor);
    Handle(V3d_View)                view();

public slots:

    void                            fitAll();

protected:

    virtual void                    mouseMoveEvent(QMouseEvent* theEvent) override;
    virtual void                    mousePressEvent(QMouseEvent* theEvent) override;
    virtual void                    mouseReleaseEvent(QMouseEvent* theEvent) override;
    virtual void                    paintEvent(QPaintEvent* theEvent) override;
    virtual void                    resizeEvent(QResizeEvent* theEvent) override;

private:

    Handle(AIS_InteractiveContext)  myContext;
    Handle(V3d_View)                myView;
    Handle(V3d_Viewer)              myViewer;

};

#endif // __Viewer3d_View_hxx__
