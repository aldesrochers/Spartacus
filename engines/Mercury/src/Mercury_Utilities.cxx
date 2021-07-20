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
#include <Mercury_Utilities.hxx>


// ============================================================================
/*!
 *  \brief DatabaseName()
*/
// ============================================================================
QString Mercury_Utilities::DatabaseName(const Mercury_DatabaseType theType)
{
    switch (theType) {
    case Mercury_AdminDatabase:
        return QString("admin");
    case Mercury_CableDatabase:
        return QString("cable");
    case Mercury_ShapeDatabase:
        return QString("shape");
    case Mercury_UnknownDatabase:
        return QString("unknown");
    default:
        return QString("unknown");
    }
}

// ============================================================================
/*!
 *  \brief DriverName()
*/
// ============================================================================
QString Mercury_Utilities::DriverName(const Mercury_DriverType theType)
{
    switch (theType) {
    case Mercury_PostgreSQLDriver:
        return QString("PQSQL");
    case Mercury_SQLiteDriver:
        return QString("QSQLITE");
    case Mercury_UnknownDriver:
        return QString("UNKNOWN");
    default:
        return QString("UNKNWON");
    }
}
