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


#ifndef __DB_QuantityColumn_hxx__
#define __DB_QuantityColumn_hxx__

// Qt
#include <QString>

// Spartacus
#include <DB_Column.hxx>


// ============================================================================
/*!
 *  \brief DB_QuantityColumn
 *  Class implementation of a string column definition.
*/
// ============================================================================
class DB_QuantityColumn : public DB_Column
{

public:
    // constructors
    DB_QuantityColumn();
    // destructors
    ~DB_QuantityColumn();

public:

    QString     DefaultUnit() const;
    double      DefaultValue() const;
    void        SetDefaultUnit(const QString& theUnit);
    void        SetDefaultValue(const double theValue);

private:

    QString     myDefaultUnit;
    double      myDefaultValue;

};

#endif  // __DB_QuantityColumn_hxx__
