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


#ifndef __DB_Column_hxx__
#define __DB_Column_hxx__

// Qt
#include <QString>

// Spartacus
#include <DB_DataType.hxx>


// ============================================================================
/*!
 *  \brief DB_Column
 *  Base class implementation of a column definition.
*/
// ============================================================================
class DB_Column
{

public:
    // constructors
    DB_Column(const DB_DataType theDataType);
    // destructors
    ~DB_Column();

public:

    DB_DataType     DataType() const;
    bool            IsAutoIncremented() const;
    bool            IsNotNull() const;
    bool            IsPrimaryKey() const;
    bool            IsUnique() const;
    void            SetIsAutoIncremented(const bool isAutoIncremented);
    void            SetIsNotNull(const bool isNotNull);
    void            SetIsPrimaryKey(const bool isPrimaryKey);
    void            SetIsUnique(const bool isUnique);

private:

    DB_DataType     myDataType;
    bool            myIsAutoIncremented;
    bool            myIsNotNull;
    bool            myIsPrimaryKey;
    bool            myIsUnique;

};

#endif  // __DB_Column_hxx__
