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
#include <DBS_Column.hxx>


// ============================================================================
/*!
 *  \brief Constructor
 *  Creates an indefinite (no type) column.
*/
// ============================================================================
DBS_Column::DBS_Column()
    : myType(DBS_UnknownColumnType)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
DBS_Column::DBS_Column(const DBS_ColumnType theType)
    : myType(theType)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
DBS_Column::DBS_Column(const DBS_ColumnType theType,
                       const QString& theName)
    : myName(theName),
      myType(theType)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
DBS_Column::~DBS_Column()
{

}

// ============================================================================
/*!
 *  \brief DefaultValue()
*/
// ============================================================================
QVariant DBS_Column::DefaultValue() const
{
    return myDefaultValue;
}

// ============================================================================
/*!
 *  \brief Description()
*/
// ============================================================================
QString DBS_Column::Description() const
{
    return myDescription;
}

// ============================================================================
/*!
 *  \brief IsAutoIncremented()
*/
// ============================================================================
bool DBS_Column::IsAutoIncremented() const
{
    return myIsAutoIncremented;
}

// ============================================================================
/*!
 *  \brief IsNotNull()
*/
// ============================================================================
bool DBS_Column::IsNotNull() const
{
    return myIsNotNull;
}

// ============================================================================
/*!
 *  \brief IsPrimaryKey()
*/
// ============================================================================
bool DBS_Column::IsPrimaryKey() const
{
    return myIsPrimaryKey;
}

// ============================================================================
/*!
 *  \brief IsUnique()
*/
// ============================================================================
bool DBS_Column::IsUnique() const
{
    return myIsUnique;
}

// ============================================================================
/*!
 *  \brief Name()
*/
// ============================================================================
QString DBS_Column::Name() const
{
    return myName;
}

// ============================================================================
/*!
 *  \brief SetDefaultValue()
*/
// ============================================================================
void DBS_Column::SetDefaultValue(const QVariant &theValue)
{
    myDefaultValue = theValue;
}

// ============================================================================
/*!
 *  \brief SetDescription()
*/
// ============================================================================
void DBS_Column::SetDescription(const QString &theDescription)
{
    myDescription = theDescription;
}

// ============================================================================
/*!
 *  \brief SetIsAutoIncremented()
*/
// ============================================================================
void DBS_Column::SetIsAutoIncremented(const bool isAutoIncremented)
{
    myIsAutoIncremented = isAutoIncremented;
}

// ============================================================================
/*!
 *  \brief SetIsNotNull()
*/
// ============================================================================
void DBS_Column::SetIsNotNull(const bool isNotNull)
{
    myIsNotNull = isNotNull;
}

// ============================================================================
/*!
 *  \bref SetIsPrimaryKey()
*/
// ============================================================================
void DBS_Column::SetIsPrimaryKey(const bool isPrimaryKey)
{
    myIsPrimaryKey = isPrimaryKey;
}

// ============================================================================
/*!
 *  \brief SetIsUnique()
*/
// ============================================================================
void DBS_Column::SetIsUnique(const bool isUnique)
{
    myIsUnique = isUnique;
}

// ============================================================================
/*!
 *  \brief SetName()
*/
// ============================================================================
void DBS_Column::SetName(const QString &theName)
{
    myName = theName;
}

// ============================================================================
/*!
 *  \brief SetType()
*/
// ============================================================================
void DBS_Column::SetType(const DBS_ColumnType theType)
{
    myType = theType;
}

// ============================================================================
/*!
 *  \brief Type()
*/
// ============================================================================
DBS_ColumnType DBS_Column::Type() const
{
    return myType;
}
