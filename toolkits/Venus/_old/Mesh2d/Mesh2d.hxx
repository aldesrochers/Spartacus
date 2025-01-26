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


#ifndef __Mesh2d_hxx__
#define __Mesh2d_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Poly_Triangulation.hxx>

// Spartacus
#include <Mesh2d_Grid.hxx>


// ============================================================================
/*
    \brief Mesh2d
*/
// ============================================================================
class Mesh2d
{

public:

    DEFINE_STANDARD_ALLOC;
    
public:

    static Standard_EXPORT Handle(Poly_Triangulation)  Triangulation(const Handle(Mesh2d_Grid)& theGrid);



};

#endif // __Mesh2d_hxx__
