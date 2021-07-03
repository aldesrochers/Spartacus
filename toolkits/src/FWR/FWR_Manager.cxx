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
#include <FWR_Manager.hxx>
#include <FW_StandardPaths.hxx>

// Qt
#include <QDebug>
#include <QDir>
#include <QFile>

// Hold a singleton reference to the resource manager
FWR_Manager* FWR_Manager::myManager = nullptr;


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
FWR_Manager::FWR_Manager()
{
    RegisterIconResources();
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
FWR_Manager::~FWR_Manager()
{

}

// ============================================================================
/*!
    \brief GetFileName()
    Provides a mapping between icon types and filenames in rcc file.
*/
// ============================================================================
QString FWR_Manager::GetFileName(const FWR_Icon theIcon)
{
    switch (theIcon) {
    case FWR_CloseFileIcon:
        return QString("file_close.png");
    case FWR_CloseIcon:
        return QString("close.png");
    case FWR_ColorPicker:
        return QString("color_picker.png");
    case FWR_DBConfigIcon:
        return QString("db_configuration.png");
    case FWR_ExitIcon:
        return QString("exit.png");
    case FWR_ExportFileIcon:
        return QString("file_export.png");
    case FWR_ImportFileIcon:
        return QString("file_import.png");
    case FWR_NewFileIcon:
        return QString("file_new.png");
    case FWR_NotFoundIcon:
        return QString("not_found");
    case FWR_OpenFileIcon:
        return QString("file_open.png");
    case FWR_SaveFileIcon:
        return QString("file_save.png");
    case FWR_SpartacusIcon:
        return QString("spartacus.png");
    case FWR_ViewFitAllIcon:
        return QString("view_fit_all.png");
    case FWR_ViewMove:
        return QString("view_move.png");
    case FWR_ViewRotate:
        return QString("view_rotate.png");
    case FWR_ViewZoomInIcon:
        return QString("view_zoom_in.png");
    case FWR_ViewZoomOutIcon:
        return QString("view_zoom_out.png");
    default:
        return QString("not_found.png");
    }
}

// ============================================================================
/*!
    \brief GetFilePath()
*/
// ============================================================================
QString FWR_Manager::GetFilePath(const FWR_Icon theIcon,
                                 const FWR_Theme theTheme)
{
    QString aFileName = GetFileName(theIcon);
    QString aSubDir = GetThemeDir(theTheme);
    QString aPath = QString(":/icons") + QDir::separator()
            + aSubDir + QDir::separator() + aFileName;
    return aPath;
}

// ============================================================================
/*!
    \brief GetIcon()
*/
// ============================================================================
QIcon FWR_Manager::GetIcon(const FWR_Icon theIcon,
                           const FWR_Theme theTheme)
{
    QString aPath = GetFilePath(theIcon, theTheme);
    QFile aFile(aPath);
    if(!aFile.exists())
        return QIcon();
    return QIcon(aFile.fileName());
}

// ============================================================================
/*!
    \brief GetThemeDir()
    Get the path of a 'theme' subdirectory.
*/
// ============================================================================
QString FWR_Manager::GetThemeDir(const FWR_Theme theTheme)
{
    switch (theTheme) {
    case FWR_StandardTheme:
        return QString("standard");
    default:
        return QString("standard");
    }
}

// ============================================================================
/*!
    \brief Manager()
    Get a reference to the resources manager.
*/
// ============================================================================
FWR_Manager* FWR_Manager::Manager()
{
    if(myManager == nullptr)
        myManager = new FWR_Manager();
    return myManager;
}

// ============================================================================
/*!
    \brief RegisterIconResources()
*/
// ============================================================================
bool FWR_Manager::RegisterIconResources()
{
    QString aPath = FW_StandardPaths::RccFilePath("Spartacus_Icons.rcc");
    QFile aFile(aPath);
    if(!aFile.exists())
        qDebug() << "FWR_Manager::ResgisterIconResources()->File not found";
    return QResource::registerResource(aPath, "/icons");
}
