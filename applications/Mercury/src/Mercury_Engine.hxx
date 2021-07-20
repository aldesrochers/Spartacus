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

#ifndef __HuygensApp_DataModel_hxx__
#define __HuygensApp_DataModel_hxx__

// Qt
#include <QAbstractItemModel>

// Huygens
#include <Huygens_Engine.hxx>


// ============================================================================
/*!
 *  \brief HuygensApp_DataModel
 *  Class implementation of a model of the application data.
*/
// ============================================================================
class HuygensApp_DataModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    // constructors
    HuygensApp_DataModel(Handle(Huygens_Engine) theEngine,
                         QObject* theParent = nullptr);
    // destructors
    ~HuygensApp_DataModel();

public:

    bool                        CloseDocument();
    Handle(Huygens_Engine)      GetEngine();
    bool                        NewDocument();

public:

    int                         columnCount(const QModelIndex& Parent = QModelIndex()) const override;
    QVariant                    data(const QModelIndex& Index,
                                     int Role) const override;
    Qt::ItemFlags               flags(const QModelIndex& Index) const override;
    QVariant                    headerData(int Section,
                                           Qt::Orientation Orientation,
                                           int Role = Qt::DisplayRole) const override;
    QModelIndex                 index(int Row,
                                      int Column,
                                      const QModelIndex& Parent = QModelIndex()) const override;
    QModelIndex                 parent(const QModelIndex& Index) const override;
    int                         rowCount(const QModelIndex& Parent = QModelIndex()) const override;


private:

    Handle(Huygens_Engine)      myEngine;

};

#endif  // __HuygensApp_DataModel_hxx__
