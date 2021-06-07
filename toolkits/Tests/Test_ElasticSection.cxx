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
#include <XSM_Elastic.hxx>

// ============================================================================
/*!
 *  \brief Test
*/
// ============================================================================
int main(int argc, char** argv)
{
    Standard_Real A = 0.1;
    Standard_Real E = 2E11;
    Standard_Real Alpha = 0.001;

    Handle(XSM_Elastic) aSection = new XSM_Elastic(A, E, Alpha);

    // initialize
    aSection->SetTrialTime(0.);
    aSection->SetTrialTemperature(0.);
    aSection->SetTrialStrain(0.);
    aSection->CommitState();

    // add strain
    aSection->SetTrialStrain(0.1);
    cout << aSection->GetTrialForce() << endl;
    aSection->CommitState();

    // add temperature
    aSection->SetTrialTemperature(20);
    cout << aSection->GetTrialForce() << endl;
    aSection->CommitState();

}

