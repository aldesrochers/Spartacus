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


#ifndef __MCL1d_Elastic_hxx__
#define __MCL1d_Elastic_hxx__

// Spartacus
#include <MCL1d_Material.hxx>
#include <material_Elastic.hxx>

// Forward declarations
class MCL1d_Elastic;

// Handles
DEFINE_STANDARD_HANDLE(MCL1d_Elastic, MCL1d_Material);


// ============================================================================
/*!
    \brief MCL1d_Elastic
    Base class implementation of a material constitutive law.
*/
// ============================================================================
class MCL1d_Elastic : public MCL1d_Material
{

public:
    // constructors
    MCL1d_Elastic(const Standard_Real E);
    MCL1d_Elastic(const Standard_Real E,
                  const Standard_Real Alpha);
    MCL1d_Elastic(const material_Elastic& theMaterial);
    // destructors
    ~MCL1d_Elastic();

public:

    virtual Standard_Real   CurrentStiffness() const;
    virtual Standard_Real   CurrentStress() const;
    virtual Standard_Real   InitialStiffness() const;

public:

    Standard_Real           Alpha() const;
    Standard_Real           E() const;
    material_Elastic        Material() const;
    void                    SetAlpha(const Standard_Real Alpha);
    void                    SetE(const Standard_Real E);

private:

    material_Elastic        myMaterial;

public:

    DEFINE_STANDARD_RTTIEXT(MCL1d_Elastic, MCL1d_Material);

};

#endif  // __MCL1d_Elastic_hxx__
