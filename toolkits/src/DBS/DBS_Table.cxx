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
#include <DBS_Table.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
DBS_Table::DBS_Table()
    : myLastError(DBS_NoTableError)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
DBS_Table::~DBS_Table()
{

}

// ============================================================================
/*!
 *  \brief AddColumn()
*/
// ============================================================================
bool DBS_Table::AddColumn(DBS_Column *theColumn)
{
    if(myColumns.contains(theColumn)) {
        SetLastError(DBS_ExistingColumnError);
        return false;
    }
    myColumns.append(theColumn);
    return true;
}

// ============================================================================
/*!
 *  \brief Description()
*/
// ============================================================================
QString DBS_Table::Description() const
{
    return myDescription;
}

// ============================================================================
/*!
 *  \brief HasColumnWithName()
*/
// ============================================================================
bool DBS_Table::HasColumnWithName(const QString &theName)
{
    QVectorIterator anIterator(myColumns);
    while(anIterator.hasNext()) {
        DBS_Column* aColumn = anIterator.next();
        if(QString::compare(aColumn->Name(), theName, Qt::CaseSensitive) == 0)
            return true;
    }
    return false;
}

// ============================================================================
/*!
 *  \brief IndexOfColumn()
*/
// ============================================================================
int DBS_Table::IndexOfColumn(DBS_Column *theColumn)
{
    return myColumns.indexOf(theColumn);
}

// ============================================================================
/*!
 *  \brief IndexOfColumn()
*/
// ============================================================================
int DBS_Table::IndexOfColumn(const QString &theName)
{
    QVectorIterator anIterator(myColumns);
    while(anIterator.hasNext()) {
        DBS_Column* aColumn = anIterator.next();
        if(QString::compare(theName, aColumn->Name(), Qt::CaseSensitive) == 0)
            return IndexOfColumn(aColumn);
    }
    return -1;
}

// ============================================================================
/*!
 *  \brief IsColumn()
*/
// ============================================================================
bool DBS_Table::IsColumn(DBS_Column *theColumn)
{
    if(myColumns.count(theColumn) > 0)
        return true;
    return false;
}

// ============================================================================
/*!
 *  \brief IsEmpty()
*/
// ============================================================================
bool DBS_Table::IsEmpty() const
{
    if(myColumns.size() <= 0)
        return true;
    return false;
}

// ============================================================================
/*!
 *  \brief LastError()
*/
// ============================================================================
DBS_TableError DBS_Table::LastError() const
{
    return myLastError;
}

// ============================================================================
/*!
 *  \brief Name()
*/
// ============================================================================
QString DBS_Table::Name() const
{
    return myName;
}

// ============================================================================
/*!
 *  \brief NbColumns()
*/
// ============================================================================
int DBS_Table::NbColumns() const
{
    return myColumns.size();
}

// ============================================================================
/*!
 *  \brief RemoveColumn()
*/
// ============================================================================
bool DBS_Table::RemoveColumn(DBS_Column *theColumn)
{
    if(!myColumns.removeOne(theColumn)) {
        myLastError = DBS_NoColumnError;
        return false;
    }
    return myColumns.removeOne(theColumn);
}

// ============================================================================
/*!
 *  \brief RemoveColumn()
 *  Remove a column providing a column name.
*/
// ============================================================================
bool DBS_Table::RemoveColumn(const QString& theName)
{
    int anIndex = IndexOfColumn(theName);
    if(anIndex < 0) {
        SetLastError(DBS_NoColumnWithNameError);
        return false;
    }
    myColumns.removeAt(anIndex);
    return true;
}

// ============================================================================
/*!
 *  \brief SetDesription()
*/
// ============================================================================
void DBS_Table::SetDescription(const QString &theDescription)
{
    myDescription = theDescription;
}

// ============================================================================
/*!
 *  \brief SetLastError()
*/
// ============================================================================
void DBS_Table::SetLastError(const DBS_TableError theError)
{
    myLastError = theError;
}

// ============================================================================
/*!
 *  \brief SetName()
*/
// ============================================================================
void DBS_Table::SetName(const QString &theName)
{
    myName = theName;
}
