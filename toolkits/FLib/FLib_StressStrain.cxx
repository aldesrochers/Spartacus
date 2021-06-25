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


// Caelus
#include <FLib_StressStrain.hxx>


// ============================================================================
/*!
 *  \brief MenegottoPintoStiffness()
*/
// ============================================================================
Standard_Real FLib_StressStrain::MenegottoPintoStiffness(const Standard_Real Strain,
                                                         const fp_StressStrain &StressStress0,
                                                         const fp_MenegottoPinto &Parameters)
{
    fp_StressStrain StressStrainUR(0., 0.);
    return MenegottoPintoStiffness(Strain, StressStrainUR, StressStress0, Parameters);
}

// ============================================================================
/*!
 *  \brief MenegottoPintoStiffness()
 *  Compute the 1st derivative (stiffness) on a MenegottoPinto unixial
 *  constitutive law based on the current strain, the stress/strain of the
 *  previous unloading/reloading curve and the stress/strain couple (Sig0, Eps0)
 *  defining the curve geometry.
*/
// ============================================================================
Standard_Real FLib_StressStrain::MenegottoPintoStiffness(const Standard_Real Strain,
                                                         const fp_StressStrain &StressStrainUR,
                                                         const fp_StressStrain &StressStrain0,
                                                         const fp_MenegottoPinto &Parameters)
{
    Standard_Real Eps = (Strain - StressStrainUR.Strain());
    Standard_Real D = (1.-Parameters.B())/Pow((Pow(Eps, Parameters.R()) + 1.), 1./Parameters.R())
            - (1.-Parameters.B()) * Pow(Eps, Parameters.R())
            * Pow(Pow(Eps, Parameters.R()) + 1., (-1./Parameters.R())-1.) + Parameters.B();
    Standard_Real K = D * ((StressStrain0.Stress() - StressStrainUR.Stress())
            * (StressStrain0.Strain() - StressStrainUR.Strain()));
    return K;
}

// ============================================================================
/*!
 *  \brief MenegottoPintoStress()
*/
// ============================================================================
Standard_Real FLib_StressStrain::MenegottoPintoStress(const Standard_Real Strain,
                                                      const fp_StressStrain& StressStrain0,
                                                      const fp_MenegottoPinto &Parameters)
{
    fp_StressStrain StressStrainUR(0., 0.);
    return MenegottoPintoStress(Strain, StressStrainUR, StressStrain0, Parameters);
}

// ============================================================================
/*!
 *  \brief MenegottoPintoStress()
 *  Compute the stress on a MenegottoPinto unixial constitutive law
 *  based on the current strain, the stress/strain of the previous
 *  unloading/reloading curve and the stress/strain couple (Sig0, Eps0)
 *  defining the curve geometry.
*/
// ============================================================================
Standard_Real FLib_StressStrain::MenegottoPintoStress(const Standard_Real Strain,
                                                      const fp_StressStrain &StressStrainUR,
                                                      const fp_StressStrain &StressStrain0,
                                                      const fp_MenegottoPinto &Parameters)
{
    Standard_Real Eps = (Strain - StressStrainUR.Strain())
            / (StressStrain0.Strain() - StressStrainUR.Strain());
    Standard_Real F = Parameters.B() * Eps +
            ((1. - Parameters.B()) * Eps) / Pow(1. + Pow(Eps, Parameters.R()), 1./Parameters.R());
    Standard_Real Sig = F * (StressStrain0.Stress() - StressStrainUR.Stress())
            + StressStrainUR.Stress();
    return Sig;
}

// ============================================================================
/*!
 *  \brief PolynomialStress()
*/
// ============================================================================
Standard_Real FLib_StressStrain::PolynomialStress(const Standard_Real Strain,
                                                  const fp_Polynomial &Parameters)
{
    fp_StressStrain StressStrainUR(0., 0.);
    return PolynomialStress(Strain, StressStrainUR, Parameters);
}

// ============================================================================
/*!
 *  \brief PolynomialStress()
 *  Compute the stress on a polynomial stress/strain curve based on current
 *  strain, the initial Stress/Stress point of the unloading/reloading curve
 *  and the curve parameters.
*/
// ============================================================================
Standard_Real FLib_StressStrain::PolynomialStress(const Standard_Real Strain,
                                                  const fp_StressStrain &StressStrainUR,
                                                  const fp_Polynomial &Parameters)
{
    TColStd_Array1OfReal Coefficients = Parameters.Coefficients();
    Standard_Real Eps = Strain - StressStrainUR.Strain();
    Standard_Real Stress = 0.;
    TColStd_Array1OfReal::Iterator anIt(Coefficients);
    Standard_Integer N = 0;
    for(; anIt.More(); anIt.Next()) {
        Stress += anIt.Value() * Pow(Eps, N);
        N += 1;
    }
    Standard_Real Sig = Stress + StressStrainUR.Stress();
    return Sig;
}

// ============================================================================
/*!
 *  \brief PolynomialStiffness()
*/
// ============================================================================
Standard_Real FLib_StressStrain::PolynomialStiffness(const Standard_Real Strain,
                                                     const fp_Polynomial &Parameters)
{
    fp_StressStrain StressStrainUR(0., 0.);
    return PolynomialStiffness(Strain, StressStrainUR, Parameters);
}

// ============================================================================
/*!
 *  \brief PolynomialStiffness()
 *  Compute the 1 derivative (stiffness) on a polynomial stress/strain curve
 *  based on current strain, the initial Stress/Stress point of
 *  the unloading/reloading curve and the curve parameters.
*/
// ============================================================================
Standard_Real FLib_StressStrain::PolynomialStiffness(const Standard_Real Strain,
                                                     const fp_StressStrain &StressStrainUR,
                                                     const fp_Polynomial &Parameters)
{
    TColStd_Array1OfReal Coefficients = Parameters.Coefficients();
    Standard_Real Eps = Strain - StressStrainUR.Strain();
    Standard_Real K = 0.;
    TColStd_Array1OfReal::Iterator anIt(Coefficients);
    Standard_Integer N = 0;
    for(; anIt.More(); anIt.Next()) {
        K += N * anIt.Value() * Pow(Eps, N - 1.);
        N += 1;
    }
    return K;
}
