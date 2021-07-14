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


#ifndef __DB_IAdminOperations_hxx__
#define __DB_IAdminOperations_hxx__

// Spartacus
#include <DB_IOperations.hxx>


// ============================================================================
/*!
 *  \brief DB_IAdminOperations
 *  Base class implementation of operations on Spartacus 'admin' databases.
*/
// ============================================================================
class DB_IAdminOperations : public DB_IOperations
{

public:
    // constructors
    DB_IAdminOperations(const QSqlDatabase& theDatabase);
    // destructors
    ~DB_IAdminOperations();

public:

    virtual bool        CreateUserTable() = 0;

    bool                HasUserTable();

};

#endif  // __DB_IAdminOperations_hxx__
