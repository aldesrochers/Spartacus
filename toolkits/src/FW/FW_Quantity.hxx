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


#ifndef __FW_Quantity_hxx__
#define __FW_Quantity_hxx__

// OpenCascade
#include <UnitsAPI.hxx>

// Spartacus
#include <FW_Boolean.hxx>
#include <FW_Integer.hxx>
#include <FW_Real.hxx>
#include <FW_String.hxx>


// ============================================================================
/*!
 *  \brief FW_Quantity
 *  Class implementation of a quantity data type.
*/
// ============================================================================
class FW_Quantity
{

public:
    // constructors
    FW_Quantity();
    FW_Quantity(const FW_Real& theValue, const FW_String& theUnit);
    // destructors
    ~FW_Quantity();

public:

    FW_Boolean      ConvertToSI();
    FW_String       ToString() const;

private:

    FW_String       myUnit;
    FW_Real         myValue;


};

#endif  // __FW_Quantity_hxx__
