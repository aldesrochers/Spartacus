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

// Mercury
#include <Mercury_SQLiteBuilder.hxx>

// Qt
#include <QSqlTableModel>

// ============================================================================
/*!
 *  \brief AddUser()
*/
// ============================================================================
bool Mercury_SQLiteBuilder::AddUser(const QSqlDatabase &theDatabase,
                                    const Mercury_User &theUser)
{

}

// ============================================================================
/*!
 *  \brief CreateUsersTable()
*/
// ============================================================================
bool Mercury_SQLiteBuilder::CreateUsersTable(QSqlQuery &theQuery)
{
    QString aString = "CREATE TABLE IF NOT EXISTS users (";
    aString += "userName TEXT PRIMARY KEY, ";
    aString += "password TEXT)";
    return theQuery.exec(aString);
}
