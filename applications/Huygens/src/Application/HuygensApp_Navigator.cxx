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
#include <HuygensApp_Desktop.hxx>
#include <HuygensApp_Navigator.hxx>
#include <Huygens_Engine.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
HuygensApp_Navigator::HuygensApp_Navigator(HuygensApp_Desktop* theDesktop)
    : QTreeView(theDesktop),
      myDesktop(theDesktop)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
HuygensApp_Navigator::~HuygensApp_Navigator()
{

}

// ============================================================================
/*!
 *  \brief getDesktop()
*/
// ============================================================================
HuygensApp_Desktop* HuygensApp_Navigator::getDesktop()
{
    return myDesktop;
}

// ============================================================================
/*!
 *  \brief GetEngine()
*/
// ============================================================================
Handle(Huygens_Engine) HuygensApp_Navigator::getEngine()
{
    return myDesktop->GetEngine();
}
