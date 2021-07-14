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

#ifndef __DBS_Column_hxx__
#define __DBS_Column_hxx__

// Qt
#include <QString>
#include <QVariant>

// Spartacus
#include <DBS_ColumnType.hxx>

// ============================================================================
/*!
 *  \brief DBS_Column
 *  Class implementation of a column schema.
*/
// ============================================================================
class DBS_Column
{

public:
    // constructors
    DBS_Column();
    DBS_Column(const DBS_ColumnType theType);
    DBS_Column(const DBS_ColumnType theType,
               const QString& theName);
    // destructors
    ~DBS_Column();

public:

    QVariant            DefaultValue() const;
    QString             Description() const;
    bool                IsAutoIncremented() const;
    bool                IsNotNull() const;
    bool                IsPrimaryKey() const;
    bool                IsUnique() const;
    QString             Name() const;
    void                SetDefaultValue(const QVariant& theValue);
    void                SetDescription(const QString& theDescription);
    void                SetIsAutoIncremented(const bool isAutoIncremented);
    void                SetIsNotNull(const bool isNotNull);
    void                SetIsPrimaryKey(const bool isPrimaryKey);
    void                SetIsUnique(const bool isUnique);
    void                SetName(const QString& theName);
    void                SetType(const DBS_ColumnType theType);
    DBS_ColumnType      Type() const;

private:

    QVariant            myDefaultValue;
    QString             myDescription;
    bool                myIsAutoIncremented;
    bool                myIsNotNull;
    bool                myIsPrimaryKey;
    bool                myIsUnique;
    QString             myName;
    DBS_ColumnType      myType;

};

#endif  // __DBS_Column_hxx__
