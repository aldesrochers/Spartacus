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


#ifndef __Mech1d_Element_hxx__
#define __Mech1d_Element_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>

// Handles
DEFINE_STANDARD_HANDLE(Mech1d_Element, Standard_Transient)


// ============================================================================
/*
    \brief Mech1d_Element
*/
// ============================================================================
class Mech1d_Element : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT Mech1d_Element();
    // destructors
    Standard_EXPORT ~Mech1d_Element();

public:

    Standard_EXPORT virtual math_Vector     TrialDisplacements() const = 0;
    Standard_EXPORT virtual math_Vector     TrialForces() const = 0;
    Standard_EXPORT virtual math_Matrix     TrialStiffness() const = 0;
    Standard_EXPORT virtual void            SetTrialDisplacements(const math_Vector& theDisplacements) = 0;

public:

    DEFINE_STANDARD_RTTIEXT(Mech1d_Element, Standard_Transient)

};

#endif // __Mech1d_Element_hxx__
