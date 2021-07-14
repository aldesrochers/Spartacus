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


#ifndef __FW_Real_hxx__
#define __FW_Real_hxx__

// OpenCascade
#include <Standard_Real.hxx>


// ============================================================================
/*!
 *  \brief FW_Real
 *  Definition of an real type.
*/
// ============================================================================
class FW_Real
{

public:
    // constructors
    FW_Real();
    FW_Real(const int theValue);
    // destructors
    ~FW_Real();

public:

    double          ToDouble() const;
    Standard_Real   ToStandardReal() const;

private:

    double          myValue;

};

#endif  // __FW_Real_hxx__
