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

#ifndef __HuygensApp_Desktop_hxx__
#define __HuygensApp_Desktop_hxx__

// Qt
#include <QMainWindow>

// Huygens
#include <Huygens_Engine.hxx>

// Spartacus
#include <FWR_Manager.hxx>



// ============================================================================
/*!
 *  \brief HuygensApp_Desktop
*/
// ============================================================================
class HuygensApp_Desktop : public QMainWindow
{
    Q_OBJECT

public:
    // constructors
    HuygensApp_Desktop(QWidget* theParent = 0);
    // destructors
    ~HuygensApp_Desktop();

public:

    Handle(Huygens_Engine)  GetEngine();
    FWR_Manager*            GetResourcesMgr();

private:

    void                    CreateFileMenu();
    void                    CreateHelpMenu();

private:

    Handle(Huygens_Engine)  myEngine;

};

#endif  // __HuygensApp_Desktop_hxx__
