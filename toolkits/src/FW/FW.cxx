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
#include <FW_Configuration.hxx>
#include <FW.hxx>

// Qt
#include <QVariant>



// ============================================================================
/*!
    \brief MajorVersion()
*/
// ============================================================================
int FW::MajorVersion()
{
    return Version().majorVersion();
}

// ============================================================================
/*!
    \brief MinorVersion()
*/
// ============================================================================
int FW::MinorVersion()
{
    return Version().minorVersion();
}

// ============================================================================
/*!
    \brief Name()
    Return the framework generic name.
*/
// ============================================================================
QString FW::Name()
{
    return QString("Spartacus");
}

// ============================================================================
/*!
    \brief PatchVersion()
*/
// ============================================================================
int FW::PatchVersion()
{
    return Version().microVersion();
}

// ============================================================================
/*!
    \brief StringVersion()
*/
// ============================================================================
QString FW::StringVersion()
{
    return Version().toString();
}

// ============================================================================
/*!
    \brief Version()
    Retrieve the framework version.
*/
// ============================================================================
QVersionNumber FW::Version()
{
    return QVersionNumber(QVariant(Spartacus_VERSION_MAJOR).toInt(),
                          QVariant(Spartacus_VERSION_MINOR).toInt(),
                          QVariant(Spartacus_VERSION_PATCH).toInt());
}
