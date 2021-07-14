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

// Huygens
#include <HuygensApp_DataModel.hxx>

// Definitions
#define HuygensApp_DocumentId   1


#include <QDebug>

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
HuygensApp_DataModel::HuygensApp_DataModel(Handle(Huygens_Engine) theEngine,
                                           QObject* theParent)
    : QAbstractItemModel(theParent),
      myEngine(theEngine)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
HuygensApp_DataModel::~HuygensApp_DataModel()
{

}

// ============================================================================
/*!
 *  \brief columnCount()
*/
// ============================================================================
int HuygensApp_DataModel::columnCount(const QModelIndex &Parent) const
{
    return 1;
}

// ============================================================================
/*!
 *  \brief CloseDocument()
*/
// ============================================================================
bool HuygensApp_DataModel::CloseDocument()
{
    bool aResult = (bool) myEngine->CloseDocument(HuygensApp_DocumentId);
    return aResult;
}

// ============================================================================
/*!
 *  \brief data()
*/
// ============================================================================
QVariant HuygensApp_DataModel::data(const QModelIndex &Index, int Role) const
{
    if(!myEngine->IsDocument(HuygensApp_DocumentId))
        return QVariant();

    if(Role != Qt::DisplayRole)
        return QVariant();

    return QString("test");
}

// ============================================================================
/*!
 *  \brief flags()
*/
// ============================================================================
Qt::ItemFlags HuygensApp_DataModel::flags(const QModelIndex &Index) const
{
    if(!Index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(Index);
}

// ============================================================================
/*!
 *  \brief GetEngine()
*/
// ============================================================================
Handle(Huygens_Engine) HuygensApp_DataModel::GetEngine()
{
    return myEngine;
}

// ============================================================================
/*!
 *  \brief headerData()
*/
// ============================================================================
QVariant HuygensApp_DataModel::headerData(int Section, Qt::Orientation Orientation, int Role) const
{
    return QVariant();
}

// ============================================================================
/*!
 *  \brief index()
*/
// ============================================================================
QModelIndex HuygensApp_DataModel::index(int Row, int Column, const QModelIndex &Parent) const
{
    if(!hasIndex(Row, Column, Parent))
        return QModelIndex();

    if(!Parent.isValid())
        return createIndex(Row, Column, nullptr);

    return QModelIndex();
}

// ============================================================================
/*!
 *  \brief NewDocument()
*/
// ============================================================================
bool HuygensApp_DataModel::NewDocument()
{
    if(myEngine->IsDocument(HuygensApp_DocumentId))
        myEngine->CloseDocument(HuygensApp_DocumentId);
    bool aResult = (bool) myEngine->NewDocument(HuygensApp_DocumentId);
    return aResult;
}

// ============================================================================
/*!
 *  \brief parent()
*/
// ============================================================================
QModelIndex HuygensApp_DataModel::parent(const QModelIndex &Index) const
{
    if(!Index.isValid())
        return QModelIndex();

    return QModelIndex();
   // return createIndex(Index.row(), 0, nullptr);
}

// ============================================================================
/*!
 *  \brief rowCount()
*/
// ============================================================================
int HuygensApp_DataModel::rowCount(const QModelIndex &Parent) const
{
    if(!myEngine->IsDocument(HuygensApp_DocumentId))
        return 0;

    return 4;
}
