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
#include <DataBrowser_TreeModel.hxx>

#include <QDebug>

// ============================================================================
/*!
 *  \brief Constructor
 *  Default constructor. Initialize a tree model with an empty root item.
*/
// ============================================================================
DataBrowser_TreeModel::DataBrowser_TreeModel(QObject* theParent)
    : QAbstractItemModel(theParent)
{
    // create a root item
    myRootItem = new DataBrowser_TreeItem();
}

// ============================================================================
/*!
 *  \brief Constructor
 *  Constructor for a tree model with a single root item.
*/
// ============================================================================
DataBrowser_TreeModel::DataBrowser_TreeModel(DataBrowser_TreeItem* theRootItem,
                                             QObject* theParent)
    : QAbstractItemModel(theParent),
      myRootItem(theRootItem)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
DataBrowser_TreeModel::~DataBrowser_TreeModel()
{

}

// ============================================================================
/*!
 *  \brief columnCount()
*/
// ============================================================================
int DataBrowser_TreeModel::columnCount(const QModelIndex &theParent) const
{
    return myRootItem->ColumnCount();
}

// ============================================================================
/*!
 *  \brief data()
*/
// ============================================================================
QVariant DataBrowser_TreeModel::data(const QModelIndex& theIndex,
                                int theRole) const
{
    if(!theIndex.isValid())
        return QVariant();

    // retrieve the item
    DataBrowser_TreeItem* anItem = Item(theIndex);

    // display role
    if(theRole == Qt::DisplayRole || theRole == Qt::EditRole)
        return anItem->DisplayData(theIndex.column());

    // decoration role
    if(theRole == Qt::DecorationRole)
        return anItem->DecorationData(theIndex.column());

    // tool tip role
    if(theRole == Qt::ItemDataRole::ToolTipRole)
        return anItem->ToolTipData(theIndex.column());

    return QVariant();
}

// ============================================================================
/*!
 *  \brief flags()
*/
// ============================================================================
Qt::ItemFlags DataBrowser_TreeModel::flags(const QModelIndex &theIndex) const
{
    if(!theIndex.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

// ============================================================================
/*!
 *  \brief headerData()
*/
// ============================================================================
QVariant DataBrowser_TreeModel::headerData(int theSection,
                                           Qt::Orientation theOrientation,
                                           int theRole) const
{
    if(theOrientation == Qt::Horizontal && theRole == Qt::DisplayRole)
        return myRootItem->DisplayData(theSection);
    return QVariant();
}

// ============================================================================
/*!
 *  \brief index()
*/
// ============================================================================
QModelIndex DataBrowser_TreeModel::index(int theRow,
                                         int theColumn,
                                         const QModelIndex &theParent) const
{
    if(theParent.isValid() && theParent.column() != 0)
        return QModelIndex();

    DataBrowser_TreeItem* aParent = Item(theParent);
    DataBrowser_TreeItem* aChild = aParent->Child(theRow);

    // if valid child, create index
    if(aChild)
        return createIndex(theRow, theColumn, aChild);

    return QModelIndex();
}

// ============================================================================
/*!
 *  \brief Item()
 *  Internal helper function use to retrieve an item from a model index.
*/
// ============================================================================
DataBrowser_TreeItem* DataBrowser_TreeModel::Item(const QModelIndex &theIndex) const
{
    if(theIndex.isValid()) {
        DataBrowser_TreeItem* anItem
                = static_cast<DataBrowser_TreeItem*>(theIndex.internalPointer());
        if(anItem)
            return anItem;
    }
    return myRootItem;
}

// ============================================================================
/*!
 *  \brief parent()
*/
// ============================================================================
QModelIndex DataBrowser_TreeModel::parent(const QModelIndex &theIndex) const
{
    if(!theIndex.isValid())
        return QModelIndex();

    DataBrowser_TreeItem* aChild = Item(theIndex);
    DataBrowser_TreeItem* aParent = aChild->Parent();

    // check if item parent is root item
    if(aParent == myRootItem)
        return QModelIndex();

    return createIndex(aParent->RowIndex(), 0, aParent);
}

// ============================================================================
/*!
 *  \brief RootItem()
*/
// ============================================================================
DataBrowser_TreeItem* DataBrowser_TreeModel::RootItem() const
{
    return myRootItem;
}

// ============================================================================
/*!
 *  \brief rowCount()
*/
// ============================================================================
int DataBrowser_TreeModel::rowCount(const QModelIndex &theParent) const
{
    DataBrowser_TreeItem* aParentItem = Item(theParent);
    if(aParentItem)
        return aParentItem->ChildCount();
    return 0;
}

// ============================================================================
/*!
 *  \brief setData()
*/
// ============================================================================
bool DataBrowser_TreeModel::setData(const QModelIndex &theIndex,
                                    const QVariant &theValue,
                                    int theRole) const
{
    if(!theIndex.isValid())
        return false;

    // retrieve the item
    DataBrowser_TreeItem* anItem = Item(theIndex);

    // check if edit role ?
    if(theRole == Qt::EditRole) {
        anItem->SetDisplayData(theIndex.column(), theValue);
    }

    return true;
}

// ============================================================================
/*!
 *  \brief setHeaderData()
*/
// ============================================================================
bool DataBrowser_TreeModel::setHeaderData(int theSection,
                                          Qt::Orientation theOrientation,
                                          const QVariant &theValue,
                                          int theRole) const
{
    DataBrowser_TreeItem* aRoot = RootItem();

    if(theOrientation == Qt::Horizontal && theRole == Qt::EditRole)
        aRoot->SetDisplayData(theSection, theValue);

    return true;
}
