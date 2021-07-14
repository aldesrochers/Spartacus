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


#ifndef __DataBrowser_TreeModel_hxx__
#define __DataBrowser_TreeModel_hxx__

// Qt
#include <QAbstractItemModel>

// Spartacus
#include <DataBrowser_TreeItem.hxx>
#include <FW_Export.hxx>

// ============================================================================
/*!
 *  \brief DataBrowser_TreeModel
 *  Class implementation of a generic model for the data browser.
*/
// ============================================================================
class FW_EXPORT DataBrowser_TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    // constructors
    DataBrowser_TreeModel(QObject* theParent = nullptr);
    DataBrowser_TreeModel(DataBrowser_TreeItem* theRootItem,
                          QObject* theParent = nullptr);
    // destructors
    ~DataBrowser_TreeModel();

public:

    DataBrowser_TreeItem*       RootItem() const;

public:

    int             columnCount(const QModelIndex& theParent = QModelIndex()) const;

    QVariant        data(const QModelIndex& theIndex,
                         int theRole = Qt::DisplayRole) const;

    Qt::ItemFlags   flags(const QModelIndex& theIndex) const;

    QVariant        headerData(int theSection,
                               Qt::Orientation theOrientation,
                               int theRole = Qt::DisplayRole) const;

    QModelIndex     index(int theRow,
                          int theColumn,
                          const QModelIndex& theParent = QModelIndex()) const;

    QModelIndex     parent(const QModelIndex& theIndex) const;

    int             rowCount(const QModelIndex& theParent = QModelIndex()) const;

    bool            setData(const QModelIndex& theIndex,
                            const QVariant& theValue,
                            int theRole = Qt::EditRole) const;

    bool            setHeaderData(int theSection,
                                  Qt::Orientation theOrientation,
                                  const QVariant& theValue,
                                  int theRole = Qt::EditRole) const;

private:

    DataBrowser_TreeItem*       Item(const QModelIndex& theIndex) const;

private:

    DataBrowser_TreeItem*   myRootItem;

};

#endif  // __DataBrowser_TreeModel_hxx__
