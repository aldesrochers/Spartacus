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
#include <MeshAlgo_Algorithm.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshAlgo_Algorithm::MeshAlgo_Algorithm()    
    : myIsDone(Standard_False)
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MeshAlgo_Algorithm::~MeshAlgo_Algorithm()    
{
    
}

// ============================================================================
/*!
    \brief IsDone()
*/
// ============================================================================
Standard_Boolean MeshAlgo_Algorithm::IsDone() const
{
    return myIsDone;
}

// ============================================================================
/*!
    \brief SetDone()
*/
// ============================================================================
void MeshAlgo_Algorithm::SetDone()
{
    myIsDone = Standard_True;
}

// ============================================================================
/*!
    \brief SetNotDone()
*/
// ============================================================================
void MeshAlgo_Algorithm::SetNotDone()
{
    myIsDone = Standard_False;
}



// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshAlgo_Algorithm, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(MeshAlgo_Algorithm, Standard_Transient)