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


#ifndef __Huygens_Desktop_hxx__
#define __Huygens_Desktop_hxx__

// Qt
#include <QMainWindow>

// Huygens
#include <Huygens_Engine.hxx>


// ============================================================================
/*!
    \brief Huygens_Desktop
*/
// ============================================================================
class Huygens_Desktop : public QMainWindow
{
    Q_OBJECT

public:
    // constructors
    Huygens_Desktop(QWidget* theParent = 0);
    // destructors
    ~Huygens_Desktop();

public:

    Huygens_Engine*     GetEngine();

private:

    void                InitializeFileMenu();
    void                InitializeHelpMenu();

private:

    Huygens_Engine*     myEngine;


};

#endif  // __Huygens_Desktop_hxx__
