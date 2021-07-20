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


#ifndef __DBI_SQLiteAdminDatabase_hxx__
#define __DBI_SQLiteAdminDatabase_hxx__

// Qt
#include <QSqlDatabase>
#include <QSqlTableModel>

// Spartacus
#include <DBI_AdminDatabase.hxx>
#include <DBS_SQLiteUser.hxx>

// ============================================================================
/*!
 *  \brief DBI_SQLiteAdminDatabase
*/
// ============================================================================
class DBI_SQLiteAdminDatabase : public DBI_AdminDatabase
{

public:
    // constructors
    DBI_SQLiteAdminDatabase(const QSqlDatabase& theDatabase);
    // destructors
    ~DBI_SQLiteAdminDatabase();

public:

    bool                AddUser(const DBS_SQLiteUser& theUser);
    bool                CreateUsersTable();
    QSqlTableModel*     GetUsersTableModel();

private:

    void                InitializeUsersTableModel();

private:

    QSqlTableModel*     myUsersTableModel;


};

#endif  // __DBI_SQLiteAdminDatabase_hxx__
