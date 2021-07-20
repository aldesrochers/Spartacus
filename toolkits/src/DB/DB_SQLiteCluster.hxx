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

#ifndef __DB_SQLiteCluster_hxx__
#define __DB_SQLiteCluster_hxx__

// Qt
#include <QSqlDatabase>

// Spartacus
#include <DB_Cluster.hxx>


// ============================================================================
/*!
 *  \brief DB_SQLiteCluster
 *  Class implementation of a SQLite database cluster.
*/
// ============================================================================
class DB_SQLiteCluster : public DB_Cluster
{

public:
    // constructors
    DB_SQLiteCluster(const QString& theDirectoryPath);
    // destructors
    ~DB_SQLiteCluster();

public:

    bool            Connect() override;

public:

    QString         DirectoryPath() const;
    QString         Password() const;
    void            SetDirectoryPath(const QString& theDirectoryPath);
    void            SetPassword(const QString& thePassword);
    void            SetUserName(const QString& theUserName);
    QString         UserName();

private:

    QString         myDirectoryPath;
    QString         myPassword;
    QString         myUserName;


};

#endif  // __DB_SQLiteCluster_hxx__
