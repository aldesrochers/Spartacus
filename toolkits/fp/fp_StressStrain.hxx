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


#ifndef __fp_StressStrain_hxx__
#define __fp_StressStrain_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>


// ============================================================================
/*!
    \brief fp_StressStrain
*/
// ============================================================================
class fp_StressStrain
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    fp_StressStrain();
    fp_StressStrain(const Standard_Real Strain,
                    const Standard_Real Stress);
    // destructors
    ~fp_StressStrain();

public:

    Standard_Real       Strain() const;
    Standard_Real       Stress() const;

    void                SetStrain(const Standard_Real Strain);
    void                SetStress(const Standard_Real Stress);

private:

    Standard_Real       myStrain;
    Standard_Real       myStress;

};

#endif  // __fp_StressStrain_hxx__
