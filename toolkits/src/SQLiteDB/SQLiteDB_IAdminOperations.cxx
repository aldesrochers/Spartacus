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
#include <SQLiteDB_IAdminOperations.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
SQLiteDB_IAdminOperations::SQLiteDB_IAdminOperations(const QSqlDatabase& theDatabase)
    : DB_IAdminOperations(theDatabase)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
SQLiteDB_IAdminOperations::~SQLiteDB_IAdminOperations()
{

}

// ============================================================================
/*!
 *  \brief CreateUserTable()
*/
// ============================================================================
bool SQLiteDB_IAdminOperations::CreateUserTable()
{
    return Query().exec(QString("CREATE TABLE IF NOT EXISTS users ("
"userName TEXT PRIMARY KEY, "
"password TEXT, "
"firstName TEXT, "
"lastName TEXT, "
"firstLogin TEXT, "
"lastLogin TEXT)"));
}
