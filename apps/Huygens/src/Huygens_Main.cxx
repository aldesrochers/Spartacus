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
#include <Huygens_Desktop.hxx>
#include <Huygens_Engine.hxx>


// ============================================================================
/*!
    \brief Huygens_Main
*/
// ============================================================================
int main(int argc, char** argv)
{
    QApplication anApp(argc, argv);
    anApp.setApplicationName("Spartacus-Huygens");
    anApp.setApplicationDisplayName("Huygens");


    // command-line parser
    QCommandLineParser aParser;
    QCommandLineOption optionDesktop(QStringList() << "d" << "desktop",
                                     QString("Start in desktop mode."));
    aParser.addOption(optionDesktop);
    aParser.addHelpOption();
    aParser.addVersionOption();

    // start in desktop mode ?
    if(argc <= 1 || aParser.isSet(optionDesktop)) {
        Huygens_Desktop* aDesktop = new Huygens_Desktop();
        aDesktop->show();
        return anApp.exec();
    }

    return 0;
}
