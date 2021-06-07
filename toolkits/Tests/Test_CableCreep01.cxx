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

#include <iostream>
using namespace std;

// CCLM1d
#include <CCLM1d_CableWire01.hxx>


// ============================================================================
/*!
 *  \brief Test_CableCreep01
 *  Test of uniaxial material CCLM1d_CableCreep01.
*/
// ============================================================================
int main(int argc, char** argv)
{
    Standard_Real Alpha = 1.35;
    Standard_Real K = 6.1;
    Standard_Real Mu = 0.21;
    Standard_Real Phi = 0.025;

    Handle(CCLM1d_CableWire01) aCreepModel =
            new CCLM1d_CableWire01(K, Phi, Alpha, Mu);
    aCreepModel->SetTrialTemperature(100.);
    aCreepModel->SetTrialStress(100E6);
    aCreepModel->SetTrialTime(0);
    aCreepModel->CommitState();
    aCreepModel->SetTrialTemperature(100.);
    aCreepModel->SetTrialStress(100E6);
    aCreepModel->SetTrialTime(40000.);
    cout << aCreepModel->GetTrialStrain() << endl;


}

