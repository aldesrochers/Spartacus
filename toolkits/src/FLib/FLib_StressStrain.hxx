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


#ifndef __FLib_StressStrain_hxx__
#define __FLib_StressStrain_hxx__

// OpenCascade
#include <Standard_Real.hxx>

// Spartacus
#include <fp_MenegottoPinto.hxx>
#include <fp_Polynomial.hxx>
#include <fp_StressStrain.hxx>


// ============================================================================
/*!
 *  \brief FLib_StressStrain
*/
// ============================================================================
class FLib_StressStrain
{


    static Standard_Real    MenegottoPintoStiffness(const Standard_Real Strain,
                                                    const fp_StressStrain& StressStress0,
                                                    const fp_MenegottoPinto& Parameters);

    static Standard_Real    MenegottoPintoStiffness(const Standard_Real Strain,
                                                    const fp_StressStrain& StressStrainUR,
                                                    const fp_StressStrain& StressStrain0,
                                                    const fp_MenegottoPinto& Parameters);

    static Standard_Real    MenegottoPintoStress(const Standard_Real Strain,
                                                 const fp_StressStrain& StressStress0,
                                                 const fp_MenegottoPinto& Parameters);

    static Standard_Real    MenegottoPintoStress(const Standard_Real Strain,
                                                 const fp_StressStrain& StressStrainUR,
                                                 const fp_StressStrain& StressStrain0,
                                                 const fp_MenegottoPinto& Parameters);

    static Standard_Real    PolynomialStiffness(const Standard_Real Strain,
                                                const fp_Polynomial& Parameters);

    static Standard_Real    PolynomialStiffness(const Standard_Real Strain,
                                                const fp_StressStrain& StressStrainUR,
                                                const fp_Polynomial& Parameters);

    static Standard_Real    PolynomialStress(const Standard_Real Strain,
                                             const fp_Polynomial& Parameters);

    static Standard_Real    PolynomialStress(const Standard_Real Strain,
                                             const fp_StressStrain& StressStrainUR,
                                             const fp_Polynomial& Parameters);

};

#endif  // __FLib_StressStrain_hxx__
