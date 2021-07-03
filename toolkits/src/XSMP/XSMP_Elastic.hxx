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


#ifndef __XSMP_Elastic_hxx__
#define __XSMP_Elastic_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Real.hxx>

// Spartacus
#include <XSMP_Model.hxx>


// ============================================================================
/*!
 *  \brief XSMP_Elastic
*/
// ============================================================================
class Standard_EXPORT XSMP_Elastic : public XSMP_Model
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    XSMP_Elastic();
    XSMP_Elastic(const Standard_Real E,
                 const Standard_Real Area);
    XSMP_Elastic(const Standard_Real E,
                 const Standard_Real Area,
                 const Standard_Real Alpha);
    // destructors
    ~XSMP_Elastic();

public:

    Standard_Real           Alpha() const;
    Standard_Real           Area() const;
    Standard_Real           E() const;

    void                    SetAlpha(const Standard_Real Alpha);
    void                    SetArea(const Standard_Real Area);
    void                    SetE(const Standard_Real E);

private:

    Standard_Real           myAlpha;
    Standard_Real           myArea;
    Standard_Real           myE;

};

#endif  // __XSMP_Elastic_hxx__
