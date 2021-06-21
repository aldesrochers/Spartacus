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

#include <TColStd_SequenceOfReal.hxx>

// Spartacus
#include <XSM_BimetallicCable01.hxx>
#include <UCrM_CableCreep01.hxx>
#include <USSM_CableWire01.hxx>
#include <UThM_Linear.hxx>

#include <mmp_CableCreep01.hxx>


// ============================================================================
/*!
 *  \brief Test
*/
// ============================================================================
int main(int argc, char** argv)
{

    mmp_CableCreep01 creepParameters;
    creepParameters.SetSig0(0.);
    creepParameters.SetSig1(6.019E7);
    creepParameters.SetSig2(9.631E7);
    creepParameters.SetSig3(1.685E8);
    creepParameters.SetA0(0.);
    creepParameters.SetA1(0.004451);
    creepParameters.SetA2(0.007196);
    creepParameters.SetA3(0.039655);
    creepParameters.SetB0(0.20222);
    creepParameters.SetB1(0.22186);
    creepParameters.SetB2(0.23364);
    creepParameters.SetB3(0.16245);
    creepParameters.SetT0(20.);

    Handle(USSM_CableWire01) aStressStrainModel1 =
            new USSM_CableWire01(1.641E11, 1.882E11, 0.0065, 0., 1., 1.217E1, -4.817E1, -5.939E5, 0., 10.);

    Handle(USSM_CableWire01) aStressStrainModel2 =
            new USSM_CableWire01(3.804E10, 5.939E10, 0.0065, 0., 1., 9.898E1, -5.948E4, 5.306E6, 0., 10.);

    Handle(UThM_Linear) aThermalModel1 = new UThM_Linear(0.0000, 20.);
    Handle(UThM_Linear) aThermalModel2 = new UThM_Linear(0.0000, 20.);

    Handle(UCrM_CableCreep01) aCreepModel = new UCrM_CableCreep01(creepParameters);

    Handle(XSM_BimetallicCable01) aModel = new XSM_BimetallicCable01(6.058E-5,
                                                                     6.874E-4,
                                                                     aStressStrainModel1,
                                                                     aStressStrainModel2,
                                                                     aThermalModel1,
                                                                     aThermalModel2,
                                                                     aCreepModel);




    // Initialize creep model
    aModel->SetTrialStrain(0.005);
    aModel->SetTrialTemperature(20.);
    aModel->SetTrialTime(1000.);
    aModel->UpdateInternalState();
    //cout << aModel->GetTrialForce() << endl;
    aModel->CommitState();



    TColStd_SequenceOfReal aList;
    aList.Append(0.002);
    aList.Append(0.003);
    aList.Append(0.004);
    aList.Append(0.005);
    aList.Append(0.006);
    aList.Append(0.004);


    //TColStd_SequenceOfReal::Iterator anIt(aList);
    //Standard_Integer N = 0;
    //for(; anIt.More(); anIt.Next()) {
    //    aModel->SetTrialStrain(anIt.Value());
    //    aModel->SetTrialTemperature(20.);
    //    aModel->SetTrialTime(100.);
    //    aModel->UpdateInternalState();
    //    cout << aModel->GetTrialForce() << endl;
    //    aModel->CommitState();
    //
    //    N += 1;
    //}

}

