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
#include <DBQ_ShapeDatabase.hxx>


// ============================================================================
/*!
 *  \brief CreateTableShapeL()
*/
// ============================================================================
QSqlQuery DBQ_ShapeDatabase::CreateTableShapeL(QSqlDatabase &theDatabase,
                                               const QString& theTableName)
{
    QString aString = QString("CREATE TABLE IF NOT EXISTS %1 (").append(theTableName);
    aString += "designation TEXT PRIMARY KEY, ";
    aString += "deadLoad REAL, ";
    aString += "area REAL, ";
    aString += "Ix REAL, Sx REAL, rx REAL, y REAL, ";
    aString += "Iy REAL, Sy REAL, ry REAL, x REAL, ";
    aString += "J REAL, Cw REAL, ";
    aString += "mass REAL, ";
    aString += "d REAL, b REAL, t REAL, ";
    aString += "rxx REAL, y0 REAL, ryy REAL, x0 REAL, r0 REAL, ";
    aString += "omega REAL, alpha REAL)";
    QSqlQuery aQuery(aString, theDatabase);
    aQuery.exec();
    return aQuery;
}

