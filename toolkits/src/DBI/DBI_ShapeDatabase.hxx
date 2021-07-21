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


#ifndef __DBI_ShapeDatabase_hxx__
#define __DBI_ShapeDatabase_hxx__

// Spartacus
#include <DBI_Database.hxx>
#include <DBS_ShapeL.hxx>


// ============================================================================
/*!
 *  \brief DBI_ShapeDatabase
 *  Base class implementation of a database interface.
*/
// ============================================================================
class DBI_ShapeDatabase : public DBI_Database
{

public:
    // constructors
    DBI_ShapeDatabase(const QSqlDatabase& theDatabase);
    // destructors
    ~DBI_ShapeDatabase();

public:

    bool            AddShapeL(const QString& theTableName,
                              const DBS_ShapeL& theShape);

    bool            CreateTableShapeL(const QString& theTableName);

    bool            EditShapeL(const QString& theTableName,
                               const DBS_ShapeL& theShape);

    DBS_ShapeL      GetShapeL(const QString& theTableName,
                              const QString& theDesignation);

    bool            RemoveShapeL(const QString& theTableName,
                                 const DBS_ShapeL& theShape);


};

#endif  // __DBI_ShapeDatabase_hxx__
