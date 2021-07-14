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


#ifndef __FW_StandardPaths_hxx__
#define __FW_StandardPaths_hxx__

// Qt
#include <QString>


// ============================================================================
/*!
    \brief FW_StandardPaths
*/
// ============================================================================
class FW_StandardPaths
{

public:

    static QString      BinaryDirPath();
    static QString      LibraryDirPath();
    static QString      RccFileDirPath();
    static QString      RccFilePath(const QString& theFileName);
    static QString      RootDirPath();
    static QString      UserFilePath(const QString& theFileName,
                                     const bool create = true);
    static QString      UserHomeDirPath(const bool create = true);

};

#endif  // __FW_StandardPaths_hxx__
