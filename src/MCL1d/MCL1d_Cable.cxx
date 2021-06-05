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
#include <MCL1d_Cable.hxx>



// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MCL1d_Cable::MCL1d_Cable(const material_Cable& theMaterial)
    : myMaterial(theMaterial),
      myMaxStrain(0.),
      myMinStrain(0.),
      myMaxStress(0.),
      myMinStress(0.),
      myPreviousStrain(0.),
      myPreviousStress(0.),
      myCurrentMaxStrain(0.),
      myCurrentMinStrain(0.),
      myCurrentMaxStress(0.),
      myCurrentMinStress(0.)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MCL1d_Cable::~MCL1d_Cable()
{

}

// ============================================================================
/*!
    \brief CommitState()
*/
// ============================================================================
Standard_Boolean MCL1d_Cable::CommitState()
{
    if(myTrialStrain > myMaxStrain)
        myMaxStrain = myTrialStrain;
    if(myTrialStrain < myMinStrain)
        myMinStrain = myTrialStrain;

    // update based upon loading direction
    if(myTrialStrain >= 0.) {
        if(myTrialStrain >= myPreviousStrain && myTrialStrain >= myCurrentMaxStrain) {
            myCurrentMaxStrain = myTrialStrain;
            myCurrentMaxStress = myTrialStress;
        }
    } else {
        if(myTrialStrain <= myPreviousStrain && myTrialStrain <= myCurrentMinStrain) {
            myCurrentMinStrain = myTrialStrain;
            myCurrentMinStress = myTrialStress;
        }
    }

    myPreviousStrain = myTrialStrain;
    myPreviousStress = myTrialStress;
    return Standard_True;
}

#include <iostream>
using namespace std;

// ============================================================================
/*!
    \brief ComputeInternalState()
*/
// ============================================================================
Standard_Boolean MCL1d_Cable::ComputeInternalState()
{
    Standard_Real E = myMaterial.E();
    Standard_Real Ect = myMaterial.Ect();
    Standard_Real Fyc = myMaterial.Fyc();
    Standard_Real A0 = myMaterial.A0();
    Standard_Real A1 = myMaterial.A1();
    Standard_Real A2 = myMaterial.A2();
    Standard_Real A3 = myMaterial.A3();
    Standard_Real A4 = myMaterial.A4();
    Standard_Real A5 = myMaterial.A5();
    Standard_Real A6 = myMaterial.A6();

    // historic
    Standard_Real x2t = (E*myCurrentMaxStrain - myCurrentMaxStress)/(E-Ect);
    Standard_Real y2t = Ect*x2t;
    Standard_Real x1c = Fyc / E;
    Standard_Real y1c = Fyc;
    Standard_Real x2c = (E*myCurrentMinStrain - myCurrentMinStress)/(E-Ect);
    Standard_Real y2c = Ect*x2c;

    if(myTrialStrain >= 0.) {
        if(myTrialStrain > myPreviousStrain) {
            if(myTrialStrain >= myMaxStrain) {
                // monotonic curve
                myTrialStress = (A6*Pow(myTrialStrain,6) + A5*Pow(myTrialStrain,5)
                                 + A4*Pow(myTrialStrain,4) + A3*Pow(myTrialStrain,3)
                                 + A2*Pow(myTrialStrain,2) + A1*Pow(myTrialStrain,1) + A0)*E;
            } else if(myTrialStrain >= x2t) {
                // elastic curve
                myTrialStress = (myTrialStrain - x2t) * E + y2t;
            } else {
                // dummy curve
                myTrialStress = (myTrialStrain - 0.) * Ect + 0.;
            }
        } else {
            if(myTrialStrain > x2t) {
                // elastic curve
                myTrialStress = (myTrialStrain - myCurrentMaxStrain) * E + myCurrentMaxStress;
            } else {
                // dummy curve
                myTrialStress = (myTrialStrain - x2t) * Ect + y2t;
            }
        }
    } else {

    }


}

// ============================================================================
/*!
    \brief CurrentStiffness()
*/
// ============================================================================
Standard_Real MCL1d_Cable::CurrentStiffness() const
{
    return InitialStiffness();
}

#include <iostream>
using namespace std;

// ============================================================================
/*!
    \brief CurrentStress()
*/
// ============================================================================
Standard_Real MCL1d_Cable::CurrentStress() const
{
    return myTrialStress;
}

// ============================================================================
/*!
    \brief InitialStiffness()
*/
// ============================================================================
Standard_Real MCL1d_Cable::InitialStiffness() const
{
    return myMaterial.E();
}



// ****************************************************************************
// HANDLES
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MCL1d_Cable, MCL1d_Material);
IMPLEMENT_STANDARD_RTTIEXT(MCL1d_Cable, MCL1d_Material);
