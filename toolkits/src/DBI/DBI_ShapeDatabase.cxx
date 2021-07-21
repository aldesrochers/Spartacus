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
 *  \brief AddShapeL()
*/
// ============================================================================
bool DBI_ShapeDatabase::AddShapeL(const QString &theTableName,
                                  const DBS_ShapeL &theShape)
{
    QString aString = QString("INSERT INTO %1 (").arg(theTableName);
    aString += "designation, deadLoad, area, ";
    aString += "Ix, Sx, rx, y, Iy, Sy, ry, x, J, Cw, mass, ";
    aString += "d, b, t, rxx, y0, ryy, x0, r0, omega, alpha";
    aString += ") VALUES (";
    aString += "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,";
    aString += "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    myQuery.prepare(aString);
    myQuery.addBindValue(theShape.Designation);
    myQuery.addBindValue(theShape.DeadLoad);
    myQuery.addBindValue(theShape.Area);
    myQuery.addBindValue(theShape.Ix);
    myQuery.addBindValue(theShape.Sx);
    myQuery.addBindValue(theShape.Rx);
    myQuery.addBindValue(theShape.Y);
    myQuery.addBindValue(theShape.Iy);
    myQuery.addBindValue(theShape.Sy);
    myQuery.addBindValue(theShape.Ry);
    myQuery.addBindValue(theShape.X);
    myQuery.addBindValue(theShape.J);
    myQuery.addBindValue(theShape.Cw);
    myQuery.addBindValue(theShape.Mass);
    myQuery.addBindValue(theShape.D);
    myQuery.addBindValue(theShape.B);
    myQuery.addBindValue(theShape.T);
    myQuery.addBindValue(theShape.Rxx);
    myQuery.addBindValue(theShape.Y0);
    myQuery.addBindValue(theShape.Ryy);
    myQuery.addBindValue(theShape.X0);
    myQuery.addBindValue(theShape.R0);
    myQuery.addBindValue(theShape.Omega);
    myQuery.addBindValue(theShape.Alpha);
    return myQuery.exec();
}

// ============================================================================
/*!
    \brief CreateTableShapeL()
*/
// ============================================================================
bool DBI_ShapeDatabase::CreateTableShapeL(const QString& theTableName)
{
    QString aString = QString("CREATE TABLE IF NOT EXISTS %1 (").arg(theTableName);
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
    return myQuery.exec(aString);
}

// ============================================================================
/*!
 *  \brief EditShapeL()
*/
// ============================================================================
bool DBI_ShapeDatabase::EditShapeL(const QString &theTableName,
                                   const DBS_ShapeL &theShape)
{
    QString aString = QString("UPDATE %1 SET ").arg(theTableName);
    aString += QString("deadLoad = %1 ").arg(theShape.DeadLoad);
    aString += QString("area = %1 ").arg(theShape.Area);
    aString += QString("Ix = %1 ").arg(theShape.Ix);
    aString += QString("Sx = %1 ").arg(theShape.Sx);
    aString += QString("rx = %1 ").arg(theShape.Rx);
    aString += QString("y = %1 ").arg(theShape.Y);
    aString += QString("Iy = %1 ").arg(theShape.Iy);
    aString += QString("Sy = %1 ").arg(theShape.Sy);
    aString += QString("ry = %1 ").arg(theShape.Ry);
    aString += QString("x = %1 ").arg(theShape.X);
    aString += QString("J = %1 ").arg(theShape.J);
    aString += QString("Cw = %1 ").arg(theShape.Cw);
    aString += QString("mass = %1 ").arg(theShape.Mass);
    aString += QString("d = %1 ").arg(theShape.D);
    aString += QString("b = %1 ").arg(theShape.B);
    aString += QString("t = %1 ").arg(theShape.T);
    aString += QString("rxx = %1 ").arg(theShape.Rxx);
    aString += QString("y0 = %1 ").arg(theShape.Y0);
    aString += QString("ryy = %1 ").arg(theShape.Ryy);
    aString += QString("x0 = %1 ").arg(theShape.X0);
    aString += QString("r0 = %1 ").arg(theShape.R0);
    aString += QString("omega = %1 ").arg(theShape.Omega);
    aString += QString("alpha = %1 ").arg(theShape.Alpha);
    aString += QString("WHERE designation = '%1'").arg(theShape.Designation);
    return myQuery.exec(aString);
}

// ============================================================================
/*!
 *  \brief GetShapeL()
*/
// ============================================================================
DBS_ShapeL DBI_ShapeDatabase::GetShapeL(const QString &theTableName,
                                        const QString &theDesignation)
{
    DBS_ShapeL aShape;
    QString aString = QString("SELECT * FROM %1 ").arg(theTableName);
    aString += QString("WHERE designation = '%1'").arg(theDesignation);
    if(!myQuery.exec(aString))
        return aShape;
    if(!myQuery.next())
        return aShape;
    aShape.Designation = myQuery.value("designation").toString();
    aShape.DeadLoad = myQuery.value("deadLoad").toDouble();
    aShape.Area = myQuery.value("area").toDouble();
    aShape.Ix = myQuery.value("Ix").toDouble();
    aShape.Sx = myQuery.value("Sx").toDouble();
    aShape.Rx = myQuery.value("rx").toDouble();
    aShape.Y = myQuery.value("y").toDouble();
    aShape.Iy = myQuery.value("Iy").toDouble();
    aShape.Sy = myQuery.value("Sy").toDouble();
    aShape.Ry = myQuery.value("ry").toDouble();
    aShape.X = myQuery.value("x").toDouble();
    aShape.J = myQuery.value("J").toDouble();
    aShape.Cw = myQuery.value("Cw").toDouble();
    aShape.Mass = myQuery.value("mass").toDouble();
    aShape.D = myQuery.value("d").toDouble();
    aShape.B = myQuery.value("b").toDouble();
    aShape.T = myQuery.value("t").toDouble();
    aShape.Rxx = myQuery.value("rxx").toDouble();
    aShape.Y0 = myQuery.value("y0").toDouble();
    aShape.Ryy = myQuery.value("ryy").toDouble();
    aShape.X0 = myQuery.value("x0").toDouble();
    aShape.R0 = myQuery.value("r0").toDouble();
    aShape.Omega = myQuery.value("omega").toDouble();
    aShape.Alpha = myQuery.value("alpha").toDouble();
    return aShape;
}

// ============================================================================
/*!
 *  \brief RemoveShapeL()
*/
// ============================================================================
bool DBI_ShapeDatabase::RemoveShapeL(const QString &theTableName,
                                     const DBS_ShapeL &theShape)
{
    QString aString = QString("DELETE FROM %1 ").arg(theTableName);
    aString += QString("WHERE designation = '%1'").arg(theShape.Designation);
    return myQuery.exec();
}
