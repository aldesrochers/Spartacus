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


#include <iostream>
using namespace std;

// Huygens
#include <Huygens_Engine.hxx>


// ============================================================================
/*!
 *  \brief Test()
*/
// ============================================================================
int main(int argc, char** argv)
{

    Handle(Huygens_Engine) anEngine = new Huygens_Engine();

    Handle(Huygens_IPropertyOperations) op = anEngine->GetIPropertyOperations(1);
    op->SetAuthorFirstName("Alexis");
    op->SetAuthorLastName("Desrochers");

    anEngine->SaveDocumentAsXML(1, "/home/alexis/Projects/spartacus/applications/Huygens/src/Core/test.xml");


}
