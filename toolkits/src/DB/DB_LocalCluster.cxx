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

// Spartacus
#include <DB_LocalCluster.hxx>

// Qt
#include <QDir>
#include <QSqlDatabase>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
DB_LocalCluster::DB_LocalCluster()
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
DB_LocalCluster::~DB_LocalCluster()
{

}

// ============================================================================
/*!
    \brief New()
    Creates a new local cluster.
*/
// ============================================================================
DB_LocalCluster* DB_LocalCluster::New(const QString &theDirectoryPath,
                                      const QString &theAdminUserName,
                                      const QString &theAdminPassword)
{
    DB_LocalCluster* aCluster;

    QDir aDir(theDirectoryPath);
    if(!aDir.exists())
        return aCluster;
    if(!aDir.isEmpty())
        return aCluster;

    // create admin database
    QString adminPath = theDirectoryPath + QDir::separator() + QString("spartacus-admin.db");
    QSqlDatabase adminDatabase = QSqlDatabase::addDatabase("QSQLITE");
    adminDatabase.setDatabaseName(adminPath);
    if(!adminDatabase.open())
        return aCluster;

    // create cable database
    QString cablePath = theDirectoryPath + QDir::separator() + QString("spartacus-cable.db");
    QSqlDatabase cableDatabase = QSqlDatabase::addDatabase("QSQLITE");
    cableDatabase.setDatabaseName(cablePath);
    if(!cableDatabase.open())
        return aCluster;

    // create shape database
    QString shapePath = theDirectoryPath + QDir::separator() + QString("spartacus-shape.db");
    QSqlDatabase shapeDatabase = QSqlDatabase::addDatabase("QSQLITE");
    shapeDatabase.setDatabaseName(shapePath);
    if(!shapeDatabase.open())
        return aCluster;


}
