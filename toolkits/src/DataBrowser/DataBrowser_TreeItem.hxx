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


#ifndef __DataBrowser_TreeItem_hxx__
#define __DataBrowser_TreeItem_hxx__

// Qt
#include <QIcon>
#include <QObject>

// Spartacus
#include <DataBrowser_VectorOfVariant.hxx>
#include <DataBrowser_VectorOfTreeItem.hxx>
#include <FW_Export.hxx>


// ============================================================================
/*!
 *  \brief DataBrowser_TreeItem
 *  Class implementation of a basic tree item.
*/
// ============================================================================
class FW_EXPORT DataBrowser_TreeItem : public QObject
{
    Q_OBJECT

public:
    // constructors
    DataBrowser_TreeItem(const int theColumnCount = 1,
                         DataBrowser_TreeItem* theParent = nullptr);
    // destructors
    ~DataBrowser_TreeItem();

public:

    void                        AppendChild(DataBrowser_TreeItem* theChild);
    DataBrowser_TreeItem*       Child(int theRow);
    int                         ChildCount() const;
    int                         ColumnCount() const;
    QVariant                    DecorationData(const int theColumn) const;
    QVariant                    DisplayData(const int theColumn) const;
    int                         IndexOfChild(DataBrowser_TreeItem* theChild);
    DataBrowser_TreeItem*       Parent();
    bool                        RemoveChild(DataBrowser_TreeItem* theChild);
    int                         RowIndex() const;
    void                        SetColumnCount(const int theColumnCount);
    bool                        SetDecorationData(const int theColumn,
                                                  const QVariant& theValue);
    bool                        SetDisplayData(const int theColumn,
                                               const QVariant& theValue);
    bool                        SetToolTipData(const int theColumn,
                                               const QVariant& theValue);
    QVariant                    ToolTipData(const int theColumn) const;


protected:

    void                        SetParent(DataBrowser_TreeItem* theParent);

private:

    DataBrowser_VectorOfTreeItem    myChilds;
    int                             myColumnCount;
    DataBrowser_VectorOfVariant     myDecorationData;
    DataBrowser_VectorOfVariant     myDisplayData;
    DataBrowser_VectorOfVariant     myToolTipData;
    DataBrowser_TreeItem*           myParent;

};

#endif  // __DataBrowser_TreeItem_hxx__
