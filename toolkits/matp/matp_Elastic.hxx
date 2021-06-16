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


#ifndef __matp_Elastic_hxx__
#define __matp_Elastic_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>


// ============================================================================
/*!
    \brief matp_Elastic

    Class implementation of parameters for material model "Creep01" which is
    based on the approximate creep model proposed by the CIGRE/Electra
    "Permanent elongation of conductors. Predictor equation and evaluation
    methods"
*/
// ============================================================================
class matp_Elastic
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    matp_Elastic();
    matp_Elastic(const Standard_Real E);
    matp_Elastic(const Standard_Real E, const Standard_Real Nu);
    // destructors
    ~matp_Elastic();

public:

    Standard_Real       E() const;
    Standard_Real       Nu() const;

    void        SetE(const Standard_Real E);
    void        SetNu(const Standard_Real Nu);

private:

    Standard_Real       myE;
    Standard_Real       myNu;

};

#endif  // __matp_Elastic_hxx__
