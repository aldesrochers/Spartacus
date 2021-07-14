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


#ifndef __DB_RealColumn_hxx__
#define __DB_RealColumn_hxx__

// Spartacus
#include <DB_Column.hxx>


// ============================================================================
/*!
 *  \brief DB_RealColumn
 *  Class implementation of a real column definition.
*/
// ============================================================================
class DB_RealColumn : public DB_Column
{

public:
    // constructors
    DB_RealColumn();
    // destructors
    ~DB_RealColumn();

public:

    double      DefaultValue() const;
    void        SetDefaultValue(const double theValue);

private:

    double      myDefaultValue;

};

#endif  // __DB_RealColumn_hxx__
