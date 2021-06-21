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

// Spartacus
#include <USSM_CableWire01.hxx>

// OpenCascade
#include <TColStd_SequenceOfReal.hxx>



// ============================================================================
/*!
 *  \brief Test_CableCreep01
 *  Test of uniaxial material CCLM1d_CableCreep01.
*/
// ============================================================================
int main(int argc, char** argv)
{

    Handle(USSM_CableWire01) aModel =
            new USSM_CableWire01(1.641E11, 1.882E11, 0.0065, 0., 1., 1.217E1, -4.817E1, -5.939E5, 0., 10.);


    TColStd_SequenceOfReal aList;
    aList.Append(0.0);
    aList.Append(0.001);
    aList.Append(0.002);
    aList.Append(0.003);
    aList.Append(0.004);
    aList.Append(0.005);
    aList.Append(0.006);
    aList.Append(0.005);
    aList.Append(0.004);
    aList.Append(0.003);
    aList.Append(0.002);
    aList.Append(0.001);
    aList.Append(0.0);
    aList.Append(-0.001);
    aList.Append(-0.002);
    aList.Append(-0.003);
    aList.Append(-0.004);
    aList.Append(-0.005);
    aList.Append(-0.006);
    aList.Append(-0.007);
    aList.Append(-0.008);
    aList.Append(-0.009);
    aList.Append(-0.010);




    TColStd_SequenceOfReal::Iterator anIt(aList);
    for(; anIt.More(); anIt.Next()) {
        aModel->SetTrialStrain(anIt.Value());
        aModel->UpdateInternalState();
        cout << aModel->GetTrialStress()<< endl;
        aModel->CommitState();


    }



}

