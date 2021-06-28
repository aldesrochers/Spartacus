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
#include <CRSA_Command.hxx>

// OpenCascade
#include <StdFail_NotDone.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
CRSA_Command::CRSA_Command()
    : myIsDone(Standard_False)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
CRSA_Command::~CRSA_Command()
{

}

// ============================================================================
/*!
    \brief Check()
*/
// ============================================================================
void CRSA_Command::Check() const
{
    if(!myIsDone)
        throw StdFail_NotDone("CRSA_Command:: Command not done.");
}

// ============================================================================
/*!
    \brief Done()
*/
// ============================================================================
void CRSA_Command::Done()
{
    myIsDone = Standard_True;
}

// ============================================================================
/*!
    \brief IsDone()
*/
// ============================================================================
Standard_Boolean CRSA_Command::IsDone() const
{
    return myIsDone;
}

// ============================================================================
/*!
    \brief NotDone()
*/
// ============================================================================
void CRSA_Command::NotDone()
{
    myIsDone = Standard_False;
}
