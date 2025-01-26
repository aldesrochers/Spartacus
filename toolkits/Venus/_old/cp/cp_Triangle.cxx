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


// OpenCascade
#include <Standard_ConstructionError.hxx>

// Spartacus
#include <cp_Triangle.hxx>



// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
cp_Triangle::cp_Triangle()
    : myNodes(1, 3)
{
    
}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
cp_Triangle::cp_Triangle(const TColStd_Array1OfInteger& theNodes)
    : myNodes(theNodes)
{
    if(theNodes.Size() != 3)
        throw Standard_ConstructionError("cp_Triangle::cp_Triangle");
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
cp_Triangle::~cp_Triangle()    
{
    
}
