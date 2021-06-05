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

// Huygens
#include <Huygens_Desktop.hxx>

// Qt
#include <QMenu>
#include <QMenuBar>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Huygens_Desktop::Huygens_Desktop(QWidget* theParent)
    : QMainWindow(theParent)
{
    // initialize menus
    InitializeFileMenu();
    InitializeHelpMenu();

    // engine
    myEngine = new Huygens_Engine();

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Huygens_Desktop::~Huygens_Desktop()
{

}

// ============================================================================
/*!
    \brief GetEngine()
*/
// ============================================================================
Huygens_Engine* Huygens_Desktop::GetEngine()
{
    return myEngine;
}

// ============================================================================
/*!
    \brief InitializeFileMenu()
*/
// ============================================================================
void Huygens_Desktop::InitializeFileMenu()
{
    QMenu* aMenu = menuBar()->addMenu("&File");
}

// ============================================================================
/*!
    \brief InitializeHelpMenu()
*/
// ============================================================================
void Huygens_Desktop::InitializeHelpMenu()
{
    QMenu* aMenu = menuBar()->addMenu("&Help");
}


