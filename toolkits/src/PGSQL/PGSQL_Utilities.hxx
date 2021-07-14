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

#ifndef __PGSQL_Utilities_hxx__
#define __PGSQL_Utilities_hxx__

// Qt
#include <QString>
#include <QStringList>
#include <QVersionNumber>

// Spartacus
#include <PGSQL_Application.hxx>


// ============================================================================
/*!
 *  \brief PGSQL_Utilities
 *  Class implementation of package PGSQL utility functions.
*/
// ============================================================================
class PGSQL_Utilities
{

public:

    static bool             CanFindExecutable(const QString& theExecutableName,
                                              const QStringList& thePaths = QStringList());

    static bool             CanFindExecutable(const PGSQL_Application theApplication,
                                              const QStringList& thePaths = QStringList());

    static QString          ExecutableName(const PGSQL_Application theApplication);

    static QString          ExecutablePath(const QString& theExecutableName,
                                           const QStringList& thePaths = QStringList());

    static QString          ExecutablePath(const PGSQL_Application theApplication,
                                           const QStringList& thePaths = QStringList());

    static QVersionNumber   Version();

};

#endif  // __PGSQL_Utilities_hxx__
