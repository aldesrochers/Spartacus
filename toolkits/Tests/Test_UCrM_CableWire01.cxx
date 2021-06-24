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
#include <UCrM_CableWire02.hxx>


// ============================================================================
/*!
 *  \brief Test_UCrM_CableWire01
*/
// ============================================================================
int main(int argc, char** argv)
{
    UCrMP_CableWire01 Params1;
    Params1.SetA1(12.883);
    Params1.SetA2(20.434);
    Params1.SetA3(3.213);
    Params1.SetB1(-95417.805);
    Params1.SetB2(223.374);
    Params1.SetB3(0.104);
    Params1.SetE(5.939E10);
    Params1.SetC(0.003);
    Params1.SetT0(20.);

    UCrMP_CableWire02 Params2;
    Params2.SetA0(0.);
    Params2.SetA1(5.562E-5);
    Params2.SetA2(8.999E-5);
    Params2.SetA3(4.832E-4);
    Params2.SetB0(0.2017);
    Params2.SetB1(0.2219);
    Params2.SetB2(0.2336);
    Params2.SetB3(0.1608);
    Params2.SetE(5.939E10);
    Params2.SetC(0.003);
    Params2.SetEps0(0.);
    Params2.SetEps1(8.053E-4);
    Params2.SetEps2(1.273E-3);
    Params2.SetEps3(2.050E-3);
    Params2.SetT0(20.);


    Handle(UCrM_CableWire01) aModel1 = new UCrM_CableWire01(Params1);
    Handle(UCrM_CableWire02) aModel2 = new UCrM_CableWire02(Params2);

    Standard_Real Sig1 = 1.218E8;
    Standard_Real Temp = 20.;


    TColStd_SequenceOfReal aList;
    aList.Append(0.);
    aList.Append(100.);
    aList.Append(500.);
    aList.Append(1000.);
    aList.Append(2000.);
    aList.Append(3000.);
    aList.Append(4000.);
    aList.Append(5000.);
    aList.Append(6000.);
    aList.Append(8760.);
    aList.Append(87600.);


    TColStd_SequenceOfReal::Iterator anIt(aList);
    for(; anIt.More(); anIt.Next()) {
        aModel1->SetTrialStress(Sig1);
        aModel1->SetTrialTemperature(Temp);
        aModel1->SetTrialTime(anIt.Value());
        cout << aModel1->GetTrialStressGrowthRate() << endl;
        aModel1->CommitState();
    }

    TColStd_SequenceOfReal::Iterator anIt2(aList);
    for(; anIt2.More(); anIt2.Next()) {
        aModel2->SetTrialStress(Sig1);
        aModel2->SetTrialTemperature(Temp);
        aModel2->SetTrialTime(anIt2.Value());
        cout << aModel2->GetTrialStressGrowthRate() << endl;
        aModel2->CommitState();
    }

}

