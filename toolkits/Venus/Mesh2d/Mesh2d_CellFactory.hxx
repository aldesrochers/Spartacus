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


#ifndef __Mesh2d_CellFactory_hxx__
#define __Mesh2d_CellFactory_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>

// Spartacus
#include <Mesh2d_Cell.hxx>


// ============================================================================
/*
    \brief Mesh2d_CellFactory
*/
// ============================================================================
class Mesh2d_CellFactory
{

public:

    DEFINE_STANDARD_ALLOC;
    
public:
    // constructors
    Standard_EXPORT Mesh2d_CellFactory();
    // destructors
    Standard_EXPORT ~Mesh2d_CellFactory();

public:

    Standard_EXPORT Handle(Mesh2d_Cell)     MakeLinearLine2N(const Standard_Integer theNode1,
                                                             const Standard_Integer theNode2);
    Standard_EXPORT Handle(Mesh2d_Cell)     MakeQuadraticLine3N(const Standard_Integer theNode1,
                                                                const Standard_Integer theNode2,
                                                                const Standard_Integer theNode3);


};

#endif // __Mesh2d_CellFactory_hxx__
