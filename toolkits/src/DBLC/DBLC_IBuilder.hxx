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


#ifndef __DBLC_IBuilder__
#define __DBLC_IBuilder__

// Qt
#include <QSqlDatabase>


// ============================================================================
/*!
 *  \brief DBLC_IBuilder
 *  Class implementation of a generic interface for builder operations.
*/
// ============================================================================
class DBLC_IBuilder
{

public:
    // constructors
    DBLC_IBuilder(const QSqlDatabase& theDatabase);
    // destructors
    ~DBLC_IBuilder();

public:

    QSqlDatabase        Database() const;

private:

    QSqlDatabase        myDatabase;

};

#endif  // __DBLC_IBuilder__
