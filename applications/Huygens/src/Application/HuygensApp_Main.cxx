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
#include <QCommandLineParser>
#include <QCommandLineOption>

// Huygens
#include <HuygensApp_Desktop.hxx>
#include <Huygens_Version.hxx>


// ============================================================================
/*!
 *  \brief Huygens_Main
 *  Application main entry point.
*/
// ============================================================================
int main(int argc, char** argv)
{
    QApplication anApp(argc, argv);
    anApp.setApplicationName("spartacus-huygens");
    anApp.setApplicationDisplayName("Huygens");
    anApp.setApplicationVersion(Huygens_VERSION_STRING);
    anApp.setWindowIcon(QIcon(":/Huygens.png"));

    // setup a basic command-line parser
    QCommandLineParser aParser;
    QCommandLineOption optionDesktop = QCommandLineOption(QStringList() << "d" << "desktop",
                                                          QString("Start in desktop mode ?"));
    aParser.addOption(optionDesktop);
    aParser.addHelpOption();
    aParser.addVersionOption();
    aParser.process(anApp);

    // check if desktop option
    if(aParser.isSet(optionDesktop) || argc <= 1) {
        HuygensApp_Desktop* aDesktop = new HuygensApp_Desktop();
        aDesktop->show();
    }

    // executable event-loop
    return anApp.exec();
}
