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

#ifndef __PGSQL_Application_hxx__
#define __PGSQL_Application_hxx__


// ============================================================================
/*!
 *  \brief PGSQL_Application
 *  Enumeration of postgresql applications.
*/
// ============================================================================
enum PGSQL_Application
{
    PGSQL_archivecleanup,
    PGSQL_basebackup,
    PGSQL_clusterdb,
    PGSQL_config,
    PGSQL_controldata,
    PGSQL_createdb,
    PGSQL_createuser,
    PGSQL_ctl,
    PGSQL_dropdb,
    PGSQL_dropuser,
    PGSQL_dump,
    PGSQL_dumpall,
    PGSQL_ecpg,
    PGSQL_initdb,
    PGSQL_isready,
    PGSQL_pgbench,
    PGSQL_postgres,
    PGSQL_postmaster,
    PGSQL_psql,
    PGSQL_receivewal,
    PGSQL_recvlogical,
    PGSQL_reindexdb,
    PGSQL_resetwal,
    PGSQL_restore,
    PGSQL_rewind,
    PGSQL_test_fsync,
    PGSQL_test_timing,
    PGSQL_upgrade,
    PGSQL_vacuumdb,
    PGSQL_waldump
};

#endif  // __PGSQL_Application_hxx__
