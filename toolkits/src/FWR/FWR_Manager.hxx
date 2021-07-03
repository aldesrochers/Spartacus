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


#ifndef __FWR_Manager_hxx__
#define __FWR_Manager_hxx__

// Qt
#include <QIcon>
#include <QResource>

// Spartacus
#include <FWR_Icon.hxx>
#include <FWR_Theme.hxx>


// ============================================================================
/*!
    \brief FWR_Manager
    Class implementation of a resource manager.
*/
// ============================================================================
class FWR_Manager
{

private:
    // constructors
    FWR_Manager();
    // destructors
    ~FWR_Manager();

public:

    static FWR_Manager*     Manager();

public:

    QIcon           GetIcon(const FWR_Icon theIcon,
                            const FWR_Theme theTheme = FWR_StandardTheme);

private:

    QString         GetFileName(const FWR_Icon theIcon);
    QString         GetFilePath(const FWR_Icon theIcon,
                                const FWR_Theme theTheme = FWR_StandardTheme);
    QString         GetThemeDir(const FWR_Theme theTheme);

    bool            RegisterIconResources();

private:

    static FWR_Manager*     myManager;

};

#endif  // __FWR_Manager_hxx__
