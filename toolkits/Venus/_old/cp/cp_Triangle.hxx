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


#ifndef __cp_Triangle_hxx__
#define __cp_Triangle_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <TColStd_Array1OfInteger.hxx>


// ============================================================================
/*
    \brief cp_Triangle
*/
// ============================================================================
class cp_Triangle
{

public:

    DEFINE_STANDARD_ALLOC;
    
public:
    // constructors
    Standard_EXPORT cp_Triangle();
    Standard_EXPORT cp_Triangle(const TColStd_Array1OfInteger& theNodes);
    // destructors
    Standard_EXPORT ~cp_Triangle();

private:

    TColStd_Array1OfInteger     myNodes;

};

#endif // __cp_Triangle_hxx__
