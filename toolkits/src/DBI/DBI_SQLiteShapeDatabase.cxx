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
#include <DBI_SQLiteShapeDatabase.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
DBI_SQLiteShapeDatabase::DBI_SQLiteShapeDatabase(const QSqlDatabase& theDatabase)
    : DBI_ShapeDatabase(theDatabase)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
DBI_SQLiteShapeDatabase::~DBI_SQLiteShapeDatabase()
{

}

// ============================================================================
/*!
 *  \brief CreateLShapeTable()
*/
// ============================================================================
bool DBI_SQLiteShapeDatabase::CreateLShapeTable()
{
    QString aString = "CREATE TABLE IF NOT EXISTS l_shapes (";
    aString += "id INTEGER PRIMARY KEY AUTOINCREMENT, ";
    aString += "designation TEXT, ";
    aString += "dataSource TEXT, ";
    aString += "d REAL, ";
    aString += "b REAL, ";
    aString += "t REAL)";
    return Query().exec(aString);
}

// ============================================================================
/*!
 *  \brief CreateWShapeTable()
*/
// ============================================================================
bool DBI_SQLiteShapeDatabase::CreateWShapeTable()
{
    QString aString = "CREATE TABLE IF NOT EXISTS w_shapes (";
    aString += "id INTEGER PRIMARY KEY AUTOINCREMENT, ";
    aString += "designation TEXT, ";
    aString += "dataSource TEXT, ";
    aString += "d REAL, ";
    aString += "b REAL, ";
    aString += "t REAL, ";
    aString += "w REAL)";
    return Query().exec(aString);
}
