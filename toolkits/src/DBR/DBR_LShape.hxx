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


#ifndef __DBR_LShape_hxx__
#define __DBR_LShape_hxx__

// Qt
#include <QSqlRecord>
#include <QVariant>


// ============================================================================
/*!
 *  \brief DBR_LShape
*/
// ============================================================================
class DBR_LShape
{


public:
    // constructors
    DBR_LShape(const QSqlRecord& theRecord) : myRecord(theRecord) {};
    // destructors
    ~DBR_LShape() {};

public:

    QString         Password() {return myRecord.value(1).toString();}
    QString         UserName() {return myRecord.value(0).toString();}

    void            SetPassword(const QString& theValue) {myRecord.setValue(1, theValue);}
    void            SetUserName(const QString& theValue) {myRecord.setValue(0, theValue);}

private:

    QSqlRecord      myRecord;

};

#endif  // __DBR_LShape_hxx__
