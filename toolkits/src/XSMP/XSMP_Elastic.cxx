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


// Spartacus
#include <XSMP_Elastic.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
XSMP_Elastic::XSMP_Elastic()
    : myAlpha(0.), myArea(0.), myE(0.)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
XSMP_Elastic::XSMP_Elastic(const Standard_Real E,
                           const Standard_Real Area)
    : myAlpha(0.), myArea(Area), myE(E)
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
XSMP_Elastic::XSMP_Elastic(const Standard_Real E,
                           const Standard_Real Area,
                           const Standard_Real Alpha)
    : myAlpha(Alpha), myArea(Area), myE(E)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
XSMP_Elastic::~XSMP_Elastic()
{

}

// ============================================================================
/*!
 *  \brief Alpha()
*/
// ============================================================================
Standard_Real XSMP_Elastic::Alpha() const
{
    return myAlpha;
}

// ============================================================================
/*!
 *  \brief Area()
*/
// ============================================================================
Standard_Real XSMP_Elastic::Area() const
{
    return myArea;
}

// ============================================================================
/*!
 *  \brief E()
*/
// ============================================================================
Standard_Real XSMP_Elastic::E() const
{
    return myE;
}

// ============================================================================
/*!
 *  \brief Alpha()
*/
// ============================================================================
void XSMP_Elastic::SetAlpha(const Standard_Real Alpha)
{
    myAlpha = Alpha;
}

// ============================================================================
/*!
 *  \brief Area()
*/
// ============================================================================
void XSMP_Elastic::SetArea(const Standard_Real Area)
{
    myArea = Area;
}

// ============================================================================
/*!
 *  \brief SetE()
*/
// ============================================================================
void XSMP_Elastic::SetE(const Standard_Real E)
{
    myE = E;
}

