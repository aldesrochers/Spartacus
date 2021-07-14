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

#ifndef __HuygensApp_Navigator_hxx__
#define __HuygensApp_Navigator_hxx__

// Qt
#include <QTreeView>

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>

// Forward declarations
class HuygensApp_Desktop;
class Huygens_Engine;


// ============================================================================
/*!
 *  \brief HuygensApp_Navigator
 *  Class implementation of a custom tree view to navigate document contents.
*/
// ============================================================================
class HuygensApp_Navigator : public QTreeView
{
    Q_OBJECT

public:
    // constructors
    HuygensApp_Navigator(HuygensApp_Desktop* theDesktop);
    // destructors
    ~HuygensApp_Navigator();

public:

    HuygensApp_Desktop*         getDesktop();
    Handle(Huygens_Engine)      getEngine();

private:

    HuygensApp_Desktop*         myDesktop;

};

#endif  // __HuygensApp_Navigator_hxx__
