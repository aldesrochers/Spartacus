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
#include <DB_Column.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
DB_Column::DB_Column(const DB_DataType theDataType)
    : myDataType(theDataType),
      myIsAutoIncremented(false),
      myIsNotNull(false),
      myIsPrimaryKey(false),
      myIsUnique(false)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
DB_Column::~DB_Column()
{

}

// ============================================================================
/*!
 *  \brief DataType()
*/
// ============================================================================
DB_DataType DB_Column::DataType() const
{
    return myDataType;
}

// ============================================================================
/*!
 *  \brief IsAutoIncremented()
*/
// ============================================================================
bool DB_Column::IsAutoIncremented() const
{
    return myIsAutoIncremented;
}

// ============================================================================
/*!
 *  \brief IsNotNull()
*/
// ============================================================================
bool DB_Column::IsNotNull() const
{
    return myIsNotNull;
}

// ============================================================================
/*!
 *  \brief IsPrimaryKey()
*/
// ============================================================================
bool DB_Column::IsPrimaryKey() const
{
    return myIsPrimaryKey;
}

// ============================================================================
/*!
 *  \brief IsUnique()
*/
// ============================================================================
bool DB_Column::IsUnique() const
{
    return myIsUnique;
}

// ============================================================================
/*!
 *  \brief SetIsAutoIncremented()
*/
// ============================================================================
void DB_Column::SetIsAutoIncremented(const bool isAutoIncremented)
{
    myIsAutoIncremented = isAutoIncremented;
}

// ============================================================================
/*!
 *  \brief SetIsNotNull()
*/
// ============================================================================
void DB_Column::SetIsNotNull(const bool isNotNull)
{
    myIsNotNull = isNotNull;
}

// ============================================================================
/*!
 *  \brief SetIsPrimaryKey()
*/
// ============================================================================
void DB_Column::SetIsPrimaryKey(const bool isPrimaryKey)
{
    myIsPrimaryKey = isPrimaryKey;
}

// ============================================================================
/*!
 *  \brief SetIsUnique()
*/
// ============================================================================
void DB_Column::SetIsUnique(const bool isUnique)
{
    myIsUnique = isUnique;
}
