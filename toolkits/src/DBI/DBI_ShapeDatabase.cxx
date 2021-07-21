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
#include <DBI_ShapeDatabase.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
DBI_ShapeDatabase::DBI_ShapeDatabase(const QSqlDatabase& theDatabase)
    : DBI_Database(theDatabase)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
DBI_ShapeDatabase::~DBI_ShapeDatabase()
{

}

// ============================================================================
/*!
    \brief CreateTableShapeL()
*/
// ============================================================================
bool DBI_ShapeDatabase::CreateTableShapeL()
{
    QString aString = "CREATE TABLE IF NOT EXISTS shape_l (";
    aString += "Designation TEXT PRIMARY KEY, ";
    aString += "B REAL, ";
    aString += "D REAL, ";
    aString += "T REAL)";
}
