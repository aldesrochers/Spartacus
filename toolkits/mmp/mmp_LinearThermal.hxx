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


#ifndef __matp_CableWireCreep01_hxx__
#define __matp_CableWireCreep01_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>


// ============================================================================
/*!
    \brief matp_CableWireCreep01

    Class implementation of parameters for material model "Creep01" which is
    based on the approximate creep model proposed by the CIGRE/Electra
    "Permanent elongation of conductors. Predictor equation and evaluation
    methods"
*/
// ============================================================================
class matp_CableWireCreep01
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    matp_CableWireCreep01();
    matp_CableWireCreep01(const Standard_Real K,
                          const Standard_Real Phi,
                          const Standard_Real Alpha,
                          const Standard_Real Mu);
    // destructors
    ~matp_CableWireCreep01();

public:

    Standard_Real       Alpha() const;
    Standard_Real       K() const;
    Standard_Real       Mu() const;
    Standard_Real       Phi() const;

    void        SetAlpha(const Standard_Real Alpha);
    void        SetK(const Standard_Real K);
    void        SetMu(const Standard_Real Mu);
    void        SetPhi(const Standard_Real Phi);

private:

    Standard_Real       myAlpha;
    Standard_Real       myK;
    Standard_Real       myMu;
    Standard_Real       myPhi;

};

#endif  // __matp_CableWireCreep01_hxx__
