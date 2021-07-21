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


#ifndef __DBQ_ShapeDatabase_hxx__
#define __DBQ_ShapeDatabase_hxx__

// Qt
#include <QSqlDatabase>
#include <QSqlQuery>

// Spartacus
#include <DBS_ShapeL.hxx>


// ============================================================================
/*!
 *  \brief DBQ_ShapeDatabase
*/
// ============================================================================
class DBQ_ShapeDatabase
{

public:

    static QSqlQuery        CreateTableShapeL(QSqlDatabase& theDatabase,
                                              const QString& theTableName);

    static QSqlQuery        GetShapeL(QSqlDatabase& theDatabase,
                                      const QString& theTableName,
                                      const QString& theDesignation,
                                      DBS_ShapeL& theShape);

};


#endif  // __DBQ_ShapeDatabase_hxx__
