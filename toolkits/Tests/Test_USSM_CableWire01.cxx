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
#include <USSMP_CableWire01.hxx>

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
    USSMP_CableWire01 Params;
    Params.SetA0(0.);
    Params.SetA1(6.406E-1);
    Params.SetA2(6.341E1);
    Params.SetA3(-3.810E4);
    Params.SetA4(3.399E6);
    Params.SetE(5.939E10);
    Params.SetEpsL(0.006);
    //Params.SetFc(3E7);

    Handle(USSM_CableWire01) aModel = new USSM_CableWire01(Params);


    TColStd_SequenceOfReal aList;
    aList.Append(0.0);
    aList.Append(0.001);
    aList.Append(0.002);
    aList.Append(0.003);
    aList.Append(0.004);
    aList.Append(0.003);
    aList.Append(0.002);
    aList.Append(0.001);
    aList.Append(0.000);
    aList.Append(-0.001);
    aList.Append(-0.002);
    aList.Append(-0.003);
    aList.Append(-0.004);
    aList.Append(-0.005);
    aList.Append(-0.006);
    aList.Append(-0.005);
    aList.Append(-0.004);
    aList.Append(-0.003);
    aList.Append(-0.002);
    aList.Append(-0.001);
    aList.Append(-0.000);
    aList.Append(0.002);
    aList.Append(0.004);
    aList.Append(0.006);




    TColStd_SequenceOfReal::Iterator anIt(aList);
    for(; anIt.More(); anIt.Next()) {
        aModel->SetTrialStrain(anIt.Value());
        cout << aModel->GetTrialStrain() << " " << aModel->GetTrialStress()<< endl;
        aModel->CommitState();


    }



}

