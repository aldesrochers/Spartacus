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

#ifndef __CreateCluster_Main_hxx__
#define __CreateCluster_Main_hxx__

#include <iostream>
using namespace std;

// Qt
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

// CreateCluster
#include <CreateCluster_Version.hxx>

#include <FW_Quantity.hxx>



// ============================================================================
/*!
 *  \brief ApplicationDescription()
 *  Long description of the application.
*/
// ============================================================================
static QString ApplicationDescription()
{
    return QCoreApplication::tr("A utility to create a Spartacus database cluster.");
}


// ============================================================================
/*!
 *  \brief CreateCluster_Main
 *  Main entry point for the application.
*/
// ============================================================================
int main(int argc, char** argv)
{
    QCoreApplication anApp(argc, argv);
    anApp.setApplicationName("Spartacus-CreateCluster");
    anApp.setApplicationVersion(CreateCluster_VERSION_STRING);

    // initialize a command-line parser
    QCommandLineParser aParser;
    aParser.setApplicationDescription(ApplicationDescription());

    // option : cluster directory
    aParser.addPositionalArgument(QCoreApplication::tr("<dirpath>"),
                                  QCoreApplication::tr("Directory where to create the database cluster."));

    // option : cluster type
    aParser.addPositionalArgument(QCoreApplication::tr("<type>"),
                                  QCoreApplication::tr("Type of the cluster to be create (sqlite, postgresql)."));

    // option : help
    aParser.addHelpOption();

    // option : version
    aParser.addVersionOption();

    // process command-line arguments
    aParser.process(anApp);

    // check if positional arguments are correctly provided
    //if(aParser.positionalArguments().size() < 2)
    //    aParser.showHelp(-1);

    // retrieve directory, type from positional arguments
    //QString aDirPath = aParser.positionalArguments().at(0);
    //QString aType = aParser.positionalArguments().at(1);


    FW_Quantity aQuantity(10, "m");
    cout << aQuantity.ToString().ToQString().toStdString() << endl;

}

#endif  // __CreateCluster_Main_hxx__

