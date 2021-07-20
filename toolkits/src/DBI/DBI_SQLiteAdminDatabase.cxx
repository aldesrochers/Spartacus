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

// Spartacus
#include <DBI_SQLiteAdminDatabase.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
DBI_SQLiteAdminDatabase::DBI_SQLiteAdminDatabase(const QSqlDatabase& theDatabase)
    : DBI_AdminDatabase(theDatabase)
{
    // initialize table models
    InitializeUsersTableModel();
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
DBI_SQLiteAdminDatabase::~DBI_SQLiteAdminDatabase()
{

}

// ============================================================================
/*!
 *  \brief AddUser()
*/
// ============================================================================
bool DBI_SQLiteAdminDatabase::AddUser(const DBS_SQLiteUser &theUser)
{
    QSqlTableModel* aModel = GetUsersTableModel();
    aModel->insertRows(0, 1);
    aModel->setData(aModel->index(0, 0), "allo");
    aModel->setData(aModel->index(0, 1), "test");
    aModel->setData(aModel->index(0, 2), "allo");
    aModel->setData(aModel->index(0, 3), "test");
    return aModel->submitAll();
}

// ============================================================================
/*!
 *  \brief CreateUsersTable()
*/
// ============================================================================
bool DBI_SQLiteAdminDatabase::CreateUsersTable()
{
    QString aString = "CREATE TABLE IF NOT EXISTS users (";
    aString += "userName TEXT PRIMARY KEY, ";
    aString += "password TEXT, ";
    aString += "firstName TEXT, ";
    aString += "lastName TEXT)";
    return Query().exec(aString);
}

// ============================================================================
/*!
 *  \brief GetUsersTableModel()
*/
// ============================================================================
QSqlTableModel* DBI_SQLiteAdminDatabase::GetUsersTableModel()
{
    return myUsersTableModel;
}

// ============================================================================
/*!
 *  \brief InitializeUsersTableModel()
*/
// ============================================================================
void DBI_SQLiteAdminDatabase::InitializeUsersTableModel()
{
    myUsersTableModel = new QSqlTableModel(nullptr, myDatabase);
    myUsersTableModel->setTable("users");
    myUsersTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

