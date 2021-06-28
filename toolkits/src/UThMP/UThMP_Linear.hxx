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


#ifndef __UThMP_Linear_hxx__
#define __UThMP_Linear_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Real.hxx>


// ============================================================================
/*!
 *  \brief UThMP_Linear
*/
// ============================================================================
class UThMP_Linear
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    UThMP_Linear();
    UThMP_Linear(const Standard_Real Alpha);
    UThMP_Linear(const Standard_Real Alpha,
                 const Standard_Real T0);
    // destructors
    ~UThMP_Linear();

public:

    Standard_Real           Alpha() const;
    Standard_Real           T0() const;

    void                    SetAlpha(const Standard_Real Alpha);
    void                    SetT0(const Standard_Real T0);

private:

    Standard_Real           myAlpha;
    Standard_Real           myT0;

};

#endif  // __UThMP_Linear_hxx__
