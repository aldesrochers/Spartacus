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

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>

struct User {
    QString UserName;
    QString Password;
};



// ============================================================================
/*!
 *  \brief Mercury_Main
*/
// ============================================================================
int main(int argc, char** argv)
{

    QSqlDatabase aDatabase = QSqlDatabase::addDatabase("QSQLITE");
    aDatabase.setDatabaseName("/home/alexis/Projects/spartacus/engines/Mercury/src/test.db");
    aDatabase.open();

    QString aString = "CREATE TABLE IF NOT EXISTS users (userName TEXT PRIMARY KEY, password TEXT)";
    QSqlQuery aQuery(aDatabase);
    aQuery.exec(aString);

    QSqlTableModel aModel(nullptr, aDatabase);
    aModel.setTable("users");
    aModel.setEditStrategy(QSqlTableModel::OnManualSubmit);

    QSqlRecord aRecord = aModel.record();
    aRecord.setValue("userName", "alexis");
    aRecord.setValue("password", "test");
    aModel.insertRecord(-1, aRecord);
    aModel.submitAll();

    QString aString2 = QString("SELECT * FROM users WHERE userName = 'alexis'");
    aQuery.exec(aString2);
    while(aQuery.next())
        cout << aQuery.value(0).toString().toStdString() << endl;

    aModel.setFilter("userName = 'alexis'");
    aModel.select();
    for(int i=0; i < aModel.rowCount(); i++)
        cout << aModel.record(i).value("userName").toString().toStdString() << endl;



}
