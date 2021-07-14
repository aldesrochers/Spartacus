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

#ifndef __DBS_Table_hxx__
#define __DBS_Table_hxx__

// Qt
#include <QString>

// Spartacus
#include <DBS_Column.hxx>
#include <DBS_TableError.hxx>
#include <DBS_VectorOfColumn.hxx>


// ============================================================================
/*!
 *  \brief DBS_Table
 *  Class implementation of a table schema.
*/
// ============================================================================
class DBS_Table
{

public:
    // constructors
    DBS_Table();
    // destructors
    ~DBS_Table();

public:

    bool                AddColumn(DBS_Column* theColumn);
    QString             Description() const;
    bool                HasColumnWithName(const QString& theName);
    int                 IndexOfColumn(DBS_Column* theColumn);
    int                 IndexOfColumn(const QString& theName);
    bool                IsColumn(DBS_Column* theColumn);
    bool                IsEmpty() const;
    DBS_TableError      LastError() const;
    QString             Name() const;
    int                 NbColumns() const;
    bool                RemoveColumn(DBS_Column* theColumn);
    bool                RemoveColumn(const QString& theName);
    void                SetDescription(const QString& theDescription);
    void                SetName(const QString& theName);

private:

    void                SetLastError(const DBS_TableError theError);

private:

    DBS_VectorOfColumn  myColumns;
    QString             myDescription;
    DBS_TableError      myLastError;
    QString             myName;

};

#endif  // __DBS_Table_hxx__
