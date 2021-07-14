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
#include <FW_StandardPaths.hxx>

// Qt
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>


// ============================================================================
/*!
    \brief BinaryDirPath()
*/
// ============================================================================
QString FW_StandardPaths::BinaryDirPath()
{
    QString aPath = RootDirPath() + QDir::separator()
            + QString(Spartacus_BINS_PATH);
    return aPath;
}

// ============================================================================
/*!
    \brief LibraryDirPath()
*/
// ============================================================================
QString FW_StandardPaths::LibraryDirPath()
{
    QString aPath = RootDirPath() + QDir::separator()
            + QString(Spartacus_LIBS_PATH);
    return aPath;
}

// ============================================================================
/*!
    \brief RccFileDirPath()
*/
// ============================================================================
QString FW_StandardPaths::RccFileDirPath()
{
    QString aPath = RootDirPath() + QDir::separator()
            + QString(Spartacus_RCCS_PATH);
    return aPath;
}

// ============================================================================
/*!
    \brief RccFilePath()
*/
// ============================================================================
QString FW_StandardPaths::RccFilePath(const QString &theFileName)
{
    return RccFileDirPath() + QDir::separator() + theFileName;
}

// ============================================================================
/*!
    \brief RootDirPath()
    Get the absolute path to the  root installation directory. This
    function used the QCoreApplication path as a main entry point and compute
    the relative rootPath from directories containing executables. By default,
    all applications are in the 'bin' subdirectory, so the root path is taken
    as ../bin.

    Alternatively, one can declare the  root path using the
    Spartacus__ROOT_PATH environment variable but this is an unsafe
    way.
*/
// ============================================================================
QString FW_StandardPaths::RootDirPath()
{
    // try from environment variable, should not really be defined normally
    QString aPath = qgetenv("Spartacus__ROOT_PATH");
    // try from running application
    if(aPath.isEmpty()) {
        // applications are in 'bin' directory, one up from the
        //  installation path.
        QString appPath = QCoreApplication::applicationDirPath();
        QDir aDir(appPath);
        aDir.cdUp();
        aPath = aDir.absolutePath();
    }
    return aPath;
}

// ============================================================================
/*!
 *  \brief UserFilePath()
 *  Get the absolute path to a user file.
 *
 *  The file will be located in the 'user' root directory under subpath
 *  provided by 'fileName'
*/
// ============================================================================
QString FW_StandardPaths::UserFilePath(const QString &theFileName,
                                       const bool create)
{
    QString aPath = UserHomeDirPath() + QDir::separator() + theFileName;
    QFileInfo anInfo(aPath);
    if(!anInfo.absoluteDir().exists() && create)
        QDir().mkpath(anInfo.absoluteDir().absolutePath());
    return aPath;
}

// ============================================================================
/*!
    \brief UserHomeDirPath()
    Get the absolute path to the 'user' root directory.

    The default behaviour is to use default cross-platform settings for the
    user root path, but this can be changed using the Spartacus_USER_HOME_PATH
    environnement variable.
*/
// ============================================================================
QString FW_StandardPaths::UserHomeDirPath(const bool create)
{
    QString aPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation)
            + QDir::separator() + QString(".Spartacus");
    QDir aDir(aPath);
    if(create && !aDir.exists())
        QDir().mkpath(aPath);
    return aDir.absolutePath();
}
