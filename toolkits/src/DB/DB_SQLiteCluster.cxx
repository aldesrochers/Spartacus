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
#include <DB_SQLiteCluster.hxx>

// Qt
#include <QDir>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
DB_SQLiteCluster::DB_SQLiteCluster(const QString& theDirectoryPath)
    : myDirectoryPath(theDirectoryPath)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
DB_SQLiteCluster::~DB_SQLiteCluster()
{

}

// ============================================================================
/*!
 *  \brief Connect()
*/
// ============================================================================
bool DB_SQLiteCluster::Connect()
{
    QString adminPath = myDirectoryPath + QDir::separator() + "spartacus-admin.db";
    QString cablePath = myDirectoryPath + QDir::separator() + "spartacus-cables.db";
    QString shapePath = myDirectoryPath + QDir::separator() + "spartacus-shapes.db";

    // connect to admin database
    QSqlDatabase adminDatabase = QSqlDatabase::addDatabase("QSQLITE");
    adminDatabase.setDatabaseName(adminPath);
    if(!adminDatabase.open())
        return false;

    // connect to cable database
    QSqlDatabase cableDatabase = QSqlDatabase::addDatabase("QSQLITE");
    cableDatabase.setDatabaseName(cablePath);
    if(!cableDatabase.open())
        return false;

    // connect to shape database
    QSqlDatabase shapeDatabase = QSqlDatabase::addDatabase("QSQLITE");
    shapeDatabase.setDatabaseName(shapePath);
    if(!shapeDatabase.open())
        return false;

    return true;
}

// ============================================================================
/*!
 *  \brief DirectoryPath()
*/
// ============================================================================
QString DB_SQLiteCluster::DirectoryPath() const
{
    return myDirectoryPath;
}

// ============================================================================
/*!
 *  \brief Password()
*/
// ============================================================================
QString DB_SQLiteCluster::Password() const
{
    return myPassword;
}

// ============================================================================
/*!
 *  \brief UserName()
*/
// ============================================================================
QString DB_SQLiteCluster::UserName()
{
    return myUserName;
}
