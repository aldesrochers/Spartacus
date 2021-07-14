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
#include <PGSQL_Utilities.hxx>

// Qt
#include <QFile>
#include <QProcess>
#include <QProcessEnvironment>
#include <QStandardPaths>



// ============================================================================
/*!
 *  \brief CanFindExecutable()
*/
// ============================================================================
bool PGSQL_Utilities::CanFindExecutable(const QString &theExecutableName,
                                        const QStringList &thePaths)
{
    QString aPath = ExecutablePath(theExecutableName, thePaths);
    if(aPath.isEmpty())
        return false;
    return true;
}

// ============================================================================
/*!
 *  \brief CanFindExecutable()
*/
// ============================================================================
bool PGSQL_Utilities::CanFindExecutable(const PGSQL_Application theApplication,
                                        const QStringList &thePaths)
{
    QString anExecutableName = ExecutableName(theApplication);
    return CanFindExecutable(anExecutableName, thePaths);
}

// ============================================================================
/*!
 *  \brief ExecutableName()
*/
// ============================================================================
QString PGSQL_Utilities::ExecutableName(const PGSQL_Application theApplication)
{
    switch (theApplication) {
    case PGSQL_archivecleanup:
        return QString("pg_archivecleanup");
    case PGSQL_basebackup:
        return QString("pg_basebackup");
    case PGSQL_clusterdb:
        return QString("clusterdb");
    case PGSQL_config:
        return QString("pg_config");
    case PGSQL_controldata:
        return QString("pg_controldata");
    case PGSQL_ctl:
        return QString("pg_ctl");
    case PGSQL_createdb:
        return QString("createdb");
    case PGSQL_createuser:
        return QString("createuser");
    case PGSQL_dropdb:
        return QString("dropdb");
    case PGSQL_dropuser:
        return QString("dropuser");
    case PGSQL_dump:
        return QString("pg_dump");
    case PGSQL_dumpall:
        return QString("pg_dumpall");
    case PGSQL_ecpg:
        return QString("ecpg");
    case PGSQL_initdb:
        return QString("initdb");
    case PGSQL_isready:
        return QString("pg_isready");
    case PGSQL_pgbench:
        return QString("pgbench");
    case PGSQL_postgres:
        return QString("postgres");
    case PGSQL_postmaster:
        return QString("postmaster");
    case PGSQL_psql:
        return QString("psql");
    case PGSQL_receivewal:
        return QString("pg_receivewal");
    case PGSQL_recvlogical:
        return QString("pg_recvlogical");
    case PGSQL_reindexdb:
        return QString("reindexdb");
    case PGSQL_resetwal:
        return QString("pg_resetwal");
    case PGSQL_restore:
        return QString("pg_restore");
    case PGSQL_rewind:
        return QString("pg_rewind");
    case PGSQL_test_fsync:
        return QString("pg_test_fsync");
    case PGSQL_test_timing:
        return QString("pg_test_timing");
    case PGSQL_upgrade:
        return QString("pg_upgrade");
    case PGSQL_vacuumdb:
        return QString("vaccuumdb");
    case PGSQL_waldump:
        return QString("pg_waldump");
    default:
        return QString();
    }
}

// ============================================================================
/*!
 *  \brief ExecutablePath()
 *  Try to locate a PostgreSQL executable providing an executable name.
*/
// ============================================================================
QString PGSQL_Utilities::ExecutablePath(const QString &theExecutableName,
                                        const QStringList& thePaths)
{
    return QStandardPaths::findExecutable(theExecutableName, thePaths);
}

// ============================================================================
/*!
 *  \brief ExecutablePath()
 *  Try to locate a PostgreSQL executable providing a standard type.
*/
// ============================================================================
QString PGSQL_Utilities::ExecutablePath(const PGSQL_Application theApplication,
                                        const QStringList &thePaths)
{
    QString anExecutableName = ExecutableName(theApplication);
    return ExecutablePath(anExecutableName, thePaths);
}

// ============================================================================
/*!
 *  \brief Version()
 *  Try to locate postgres and the installed version.
*/
// ============================================================================
QVersionNumber PGSQL_Utilities::Version()
{
    // retrieve 'postgres' executable path, check if exists
    QString anExecutablePath = ExecutablePath(PGSQL_postgres);
    if(anExecutablePath.isEmpty())
        return QVersionNumber();

    // run postgres, retrieve version
    QProcess aProcess;
    aProcess.setProgram(anExecutablePath);
    aProcess.setArguments(QStringList() << "--version");
    aProcess.start();
    if(!aProcess.waitForFinished())
        return QVersionNumber();

    // parse version from output
    QString anOutput = (QString) aProcess.readAllStandardOutput();
    if(anOutput.isEmpty())
        return QVersionNumber();
    QString aStringVersion = anOutput.split(" ").at(2);
    QStringList aListVersion = aStringVersion.split(".");

    int Major = 0, Minor = 0, Patch = 0;
    if(aListVersion.size() >= 1)
        Major = aListVersion.at(0).toInt();
    if(aListVersion.size() >= 2)
        Minor = aListVersion.at(1).toInt();
    if(aListVersion.size() >= 3)
        Patch = aListVersion.at(2).toInt();

    return QVersionNumber(Major, Minor, Patch);
}
