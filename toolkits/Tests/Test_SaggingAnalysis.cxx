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
#include <CRSA_FindEmptyLength.hxx>
#include <XSM_Elastic.hxx>
#include <UMM_Elastic.hxx>
#include <UThM_BiLinear.hxx>
#include <USSM_CableWire02.hxx>
#include <TColStd_SequenceOfReal.hxx>


// ============================================================================
/*!
 *  \brief Test
*/
// ============================================================================
int main(int argc, char** argv)
{
    Handle(XSM_Elastic) aSection = new XSM_Elastic(0.01, 1E9);

    CRSA_SpanGeometry aGeometry(400.);

    CRSA_LoadCase aLoadCase1(10.);
    CRSA_LoadCase aLoadCase2(15.);

    CRSA_FindEmptyLength anAnalysis(aGeometry, aSection);
    anAnalysis.AddSaggingHistory(0., aLoadCase1, 5000.);
    anAnalysis.AddSaggingHistory(0., aLoadCase2, 5000.);

    cout << anAnalysis.EmptyLength() << endl;
    cout << anAnalysis.Error() << endl;
    cout << anAnalysis.IsDone() << endl;


    Handle(USSM_CableWire02) aMaterial = new USSM_CableWire02(1E10, 1E10, 0.1, 0., 1.02, -4.21, 49., -729., 2600., 10., 2E8, 0.001);


    TColStd_SequenceOfReal aList;
    aList.Append(0.01);
    aList.Append(0.02);
    aList.Append(0.03);
    aList.Append(0.04);
    aList.Append(0.05);
    aList.Append(0.06);
    aList.Append(0.07);
    aList.Append(0.05);
    aList.Append(0.03);
    aList.Append(0.01);
    aList.Append(-0.01);
    aList.Append(-0.03);
    aList.Append(-0.05);
    aList.Append(-0.07);
    aList.Append(-0.08);
    aList.Append(-0.1);
    aList.Append(-0.08);
    aList.Append(-0.06);
    aList.Append(-0.04);
    aList.Append(-0.02);
    aList.Append(-0.00);
    aList.Append(0.02);
    aList.Append(0.04);
    aList.Append(0.06);
    aList.Append(0.08);
    aList.Append(0.10);
    aList.Append(0.08);
    aList.Append(0.06);
    aList.Append(0.04);
    aList.Append(0.02);
    aList.Append(0.00);
    aList.Append(-0.02);
    aList.Append(0.00);
    aList.Append(0.02);
    aList.Append(0.04);
    aList.Append(0.06);
    aList.Append(0.08);
    aList.Append(0.10);
    aList.Append(0.12);
    aList.Append(0.14);


    TColStd_SequenceOfReal::Iterator anIt(aList);
    for(; anIt.More(); anIt.Next()) {
        aMaterial->SetTrialStrain(-anIt.Value());
        aMaterial->UpdateInternalState();
        cout << -anIt.Value() << " " << aMaterial->GetTrialStress() << endl;
        aMaterial->CommitState();


    }

}

