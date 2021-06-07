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
#include <CRSA_SaggingAnalysis.hxx>
#include <XSM_Elastic.hxx>


// ============================================================================
/*!
 *  \brief Test
*/
// ============================================================================
int main(int argc, char** argv)
{
    Handle(CRSA_SpanGeometry) aGeometry = new CRSA_SpanGeometry(400.);
    Handle(XSM_Elastic) aSection = new XSM_Elastic(0.01, 1E9);

    CRSA_SaggingAnalysis anAnalysis(aGeometry, aSection);

    Handle(CRSA_LoadCase) deadLoad = new CRSA_LoadCase(10.);
    Handle(CRSA_LoadCase) iceLoad = new CRSA_LoadCase(10., 0., 30.);
    Handle(CRSA_SaggingCondition) sag1 = new CRSA_SaggingCondition(deadLoad, 5000.);
    Handle(CRSA_SaggingCondition) sag2 = new CRSA_SaggingCondition(iceLoad, 25000.);

    anAnalysis.AddSaggingCondition(sag1);
    anAnalysis.AddSaggingCondition(sag2);
    cout << anAnalysis.Solve() << endl;



}

