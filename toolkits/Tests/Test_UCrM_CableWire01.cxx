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

// OpenCascade
#include <TColStd_SequenceOfReal.hxx>

// Spartacus
#include <UCrM_CableWire01.hxx>


// ============================================================================
/*!
 *  \brief Test_UCrM_CableWire01
*/
// ============================================================================
int main(int argc, char** argv)
{
    UCrMP_CableWire01 Params;
    Params.SetA1(12.883);
    Params.SetA2(20.434);
    Params.SetA3(3.213);
    Params.SetB1(-95417.805);
    Params.SetB2(223.374);
    Params.SetB3(0.104);
    Params.SetE(5.939E10);
    Params.SetC(0.003);
    Params.SetT0(20.);


    Handle(UCrM_CableWire01) aModel = new UCrM_CableWire01(Params);

    Standard_Real Sig1 = 1E8;
    Standard_Real Temp = 20.;


    TColStd_SequenceOfReal aList;
    aList.Append(0.);
    aList.Append(100.);
    aList.Append(200.);
    aList.Append(300.);
    aList.Append(400.);
    aList.Append(500.);
    aList.Append(600.);
    aList.Append(700.);
    aList.Append(800.);
    aList.Append(900.);
    aList.Append(1000.);


    TColStd_SequenceOfReal::Iterator anIt(aList);
    for(; anIt.More(); anIt.Next()) {
        aModel->SetTrialStress(Sig1);
        aModel->SetTrialTemperature(Temp);
        aModel->SetTrialTime(anIt.Value());
        cout << aModel->GetTrialStrain() << endl;
        aModel->CommitState();


    }



}

