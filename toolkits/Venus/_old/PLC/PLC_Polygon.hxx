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


#ifndef __PLC_Polygon_hxx__
#define __PLC_Polygon_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>

// Handles
DEFINE_STANDARD_HANDLE(PLC_Polygon, Standard_Transient)


// ============================================================================
/*
    \brief PLC_Polygon
*/
// ============================================================================
class PLC_Polygon : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT PLC_Polygon();
    // destructors
    Standard_EXPORT ~PLC_Polygon();

public:

    DEFINE_STANDARD_RTTIEXT(PLC_Polygon, Standard_Transient)

};

#endif // __PLC_Polygon_hxx__
