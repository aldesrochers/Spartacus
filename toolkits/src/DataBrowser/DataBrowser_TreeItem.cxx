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
#include <DataBrowser_TreeItem.hxx>

// qt
#include <QDebug>

// ============================================================================
/*!
 *  \brief Constructor
 *  Default constructor for a tree item, no column.
*/
// ============================================================================
DataBrowser_TreeItem::DataBrowser_TreeItem(const int theColumnCount,
                                           DataBrowser_TreeItem* theParent)
    : myParent(theParent)
{
    // initialize data by setting column count
    SetColumnCount(theColumnCount);
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
DataBrowser_TreeItem::~DataBrowser_TreeItem()
{

}

// ============================================================================
/*!
 *  \brief AppendChild()
*/
// ============================================================================
void DataBrowser_TreeItem::AppendChild(DataBrowser_TreeItem *theChild)
{
    theChild->SetParent(this);
    myChilds.append(theChild);
}

// ============================================================================
/*!
 *  \brief Child()
*/
// ============================================================================
DataBrowser_TreeItem* DataBrowser_TreeItem::Child(int theRow)
{
    return myChilds.at(theRow);
}

// ============================================================================
/*!
 *  \brief ChildCount()
*/
// ============================================================================
int DataBrowser_TreeItem::ChildCount() const
{
    return myChilds.size();
}

// ============================================================================
/*!
 *  \brief ColumnCount()
*/
// ============================================================================
int DataBrowser_TreeItem::ColumnCount() const
{
    return myColumnCount;
}

// ============================================================================
/*!
 *  \brief DecorationData()
*/
// ============================================================================
QVariant DataBrowser_TreeItem::DecorationData(const int theColumn) const
{
    if(theColumn < 0 || theColumn >= myDecorationData.size())
        return QVariant();
    return myDecorationData.at(theColumn);
}

// ============================================================================
/*!
 *  \brief DisplayData()
*/
// ============================================================================
QVariant DataBrowser_TreeItem::DisplayData(const int theColumn) const
{
    if(theColumn < 0 || theColumn >= myDisplayData.size())
        return QVariant();
    return myDisplayData.at(theColumn);
}

// ============================================================================
/*!
 *  \brief IndexOfChild()
*/
// ============================================================================
int DataBrowser_TreeItem::IndexOfChild(DataBrowser_TreeItem *theChild)
{
    return myChilds.indexOf(theChild);
}

// ============================================================================
/*!
 *  \brief Parent()
*/
// ============================================================================
DataBrowser_TreeItem* DataBrowser_TreeItem::Parent()
{
    return myParent;
}

// ============================================================================
/*!
 *  \brief RemoveChild()
*/
// ============================================================================
bool DataBrowser_TreeItem::RemoveChild(DataBrowser_TreeItem *theChild)
{
    if(!myChilds.contains(theChild))
        return false;
    return myChilds.removeOne(theChild);
}

// ============================================================================
/*!
 *  \brief RowIndex()
*/
// ============================================================================
int DataBrowser_TreeItem::RowIndex() const
{
    if(myParent)
        return myParent->IndexOfChild(const_cast<DataBrowser_TreeItem*>(this));
    return 0;
}

// ============================================================================
/*!
 *  \brief SetColumnCount()
 *  Set the column count and resize data containers.
*/
// ============================================================================
void DataBrowser_TreeItem::SetColumnCount(const int theColumnCount)
{
    myColumnCount = theColumnCount;
    // resize data containers
    myDisplayData.resize(theColumnCount);
    myDecorationData.resize(theColumnCount);
    myToolTipData.resize(theColumnCount);
}

// ============================================================================
/*!
 *  \brief  SetDecorationData()
*/
// ============================================================================
bool DataBrowser_TreeItem::SetDecorationData(const int theColumn,
                                             const QVariant &theValue)
{
    if(theColumn < 0 || theColumn > myDecorationData.size())
        return false;
    myDecorationData.insert(theColumn, theValue);
    return true;
}

// ============================================================================
/*!
 *  \brief SetDisplayData()
*/
// ============================================================================
bool DataBrowser_TreeItem::SetDisplayData(const int theColumn,
                                          const QVariant &theValue)
{
    if(theColumn < 0 || theColumn > myDisplayData.size())
        return false;
    myDisplayData.insert(theColumn, theValue);
    return true;
}

// ============================================================================
/*!
 *  \brief SetParent()
*/
// ============================================================================
void DataBrowser_TreeItem::SetParent(DataBrowser_TreeItem *theParent)
{
    myParent = theParent;
}

// ============================================================================
/*!
 *  \brief SetToolTipData()
*/
// ============================================================================
bool DataBrowser_TreeItem::SetToolTipData(const int theColumn,
                                          const QVariant& theValue)
{
    if(theColumn < 0 || theColumn > myToolTipData.size())
        return false;
    myToolTipData.insert(theColumn, theValue);
    return true;
}

// ============================================================================
/*!
 *  \brief ToolTipData()
*/
// ============================================================================
QVariant DataBrowser_TreeItem::ToolTipData(const int theColumn) const
{
    if(theColumn < 0 || theColumn > myToolTipData.size())
        return QVariant();
    return myToolTipData.at(theColumn);
}
