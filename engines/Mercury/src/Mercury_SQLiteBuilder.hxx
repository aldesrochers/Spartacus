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

#ifndef __Mercury_SQLiteBuilder_hxx__
#define __Mercury_SQLiteBuilder_hxx__

// Qt
#include <QSqlQuery>

// Mercury
#include <Mercury_User.hxx>


// ============================================================================
/*!
 *  \brief Mercury_SQLiteBuilder
*/
// ============================================================================
class Mercury_SQLiteBuilder
{

public:

    static QSqlDatabase     NewAdminDatabase(const QString& theFileName);
    static QSqlDatabase     NewCableDatabase(const QString& theFileName);
    static QSqlDatabase     NewShapeDatabase(const QString& theFileName);

    // create tables
    static bool             CreateUsersTable(QSqlQuery& theQuery);
    static bool             CreateShapeLTable(QSqlQuery& theQuery);
    static bool             CreateShapeWTable(QSqlQuery& theQuery);

    // records
    static bool             AddUser(const QSqlDatabase& theDatabase,
                                    const Mercury_User& theUser);
};

#endif  // __Mercury_SQLiteBuilder_hxx__
