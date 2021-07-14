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

// Qt
#include <QApplication>
#include <QDebug>

// DataBrowser
#include <DataBrowser_TreeItem.hxx>
#include <DataBrowser_TreeModel.hxx>
#include <DataBrowser_TreeView.hxx>
#include <FWR_Manager.hxx>


// ============================================================================
/*!
 *  \brief Test()
*/
// ============================================================================
int main(int argc, char** argv)
{
    QApplication anApp(argc, argv);

    DataBrowser_TreeItem* aRoot = new DataBrowser_TreeItem(3);
    aRoot->SetDisplayData(0, "Test");
    aRoot->SetDisplayData(1, "Test1");
    aRoot->SetDisplayData(2, "Test2");

    DataBrowser_TreeModel* aModel = new DataBrowser_TreeModel(aRoot);

    DataBrowser_TreeItem* aChild1 = new DataBrowser_TreeItem(2);
    aChild1->SetDisplayData(0, "Salut");
    aChild1->SetDisplayData(1, "Allo");
    aChild1->SetDecorationData(0, FWR_Manager::Manager()->GetIcon(FWR_SpartacusIcon));
    aRoot->AppendChild(aChild1);

    DataBrowser_TreeItem* aChild2 = new DataBrowser_TreeItem();
    aChild1->AppendChild(aChild2);
    aChild1->AppendChild(aChild2);


    DataBrowser_TreeView* aView = new DataBrowser_TreeView();
    aView->show();
    aView->setModel(aModel);
    aView->update();

    return anApp.exec();
}
