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

// cable
#include <matp_CableWireCreep01.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
matp_CableWireCreep01::matp_CableWireCreep01()
    : myAlpha(0.), myK(0.), myMu(0.), myPhi(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
matp_CableWireCreep01::matp_CableWireCreep01(const Standard_Real K,
                                             const Standard_Real Phi,
                                             const Standard_Real Alpha,
                                             const Standard_Real Mu)
    : myAlpha(Alpha), myK(K), myMu(Mu), myPhi(Phi)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
matp_CableWireCreep01::~matp_CableWireCreep01()
{

}

// ============================================================================
/*!
    \brief Alpha()
*/
// ============================================================================
Standard_Real matp_CableWireCreep01::Alpha() const
{
    return myAlpha;
}

// ============================================================================
/*!
    \brief K()
*/
// ============================================================================
Standard_Real matp_CableWireCreep01::K() const
{
    return myK;
}

// ============================================================================
/*!
    \brief Mu()
*/
// ============================================================================
Standard_Real matp_CableWireCreep01::Mu() const
{
    return myMu;
}

// ============================================================================
/*!
    \brief Phi()
*/
// ============================================================================
Standard_Real matp_CableWireCreep01::Phi() const
{
    return myPhi;
}

// ============================================================================
/*!
    \brief SetAlpha()
*/
// ============================================================================
void matp_CableWireCreep01::SetAlpha(const Standard_Real Alpha)
{
    myAlpha = Alpha;
}

// ============================================================================
/*!
    \brief SetK()
*/
// ============================================================================
void matp_CableWireCreep01::SetK(const Standard_Real K)
{
    myK = K;
}

// ============================================================================
/*!
    \brief SetMu()
*/
// ============================================================================
void matp_CableWireCreep01::SetMu(const Standard_Real Mu)
{
    myMu = Mu;
}

// ============================================================================
/*!
    \brief SetPhi()
*/
// ============================================================================
void matp_CableWireCreep01::SetPhi(const Standard_Real Phi)
{
    myPhi = Phi;
}

