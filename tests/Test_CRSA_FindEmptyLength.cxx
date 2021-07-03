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
#include <UCrM_CableWire01.hxx>
#include <USSM_CableWire01.hxx>
#include <USSM_CableWire02.hxx>
#include <UThM_Linear.hxx>
#include <XSM_BimetallicCable01.hxx>

#include <CRSA_SpanGeometry.hxx>
#include <CRSA_FindEmptyLength.hxx>
#include <CRSA_LoadCase.hxx>

// OpenCascade
#include <TColStd_SequenceOfReal.hxx>


// ============================================================================
/*!
 *  \brief Test()
*/
// ============================================================================
int main(int argc, char** argv)
{

    // StressStrainModel - Steel
    USSMP_CableWire01 SteelSS;
    SteelSS.SetA0(0.);
    SteelSS.SetA1(8.716E-1);
    SteelSS.SetA2(1.061E1);
    SteelSS.SetA3(-4.198E1);
    SteelSS.SetA4(-5.176E5);
    SteelSS.SetE(1.882E11);
    SteelSS.SetEpsL(0.006);

    // StressStrainModel - Alu
    USSMP_CableWire02 AluSS;
    AluSS.SetA0(0.);
    AluSS.SetA1(6.406E-1);
    AluSS.SetA2(6.341E1);
    AluSS.SetA3(-3.810E4);
    AluSS.SetA4(3.399E6);
    AluSS.SetE(5.939E10);
    AluSS.SetEpsL(0.006);
    AluSS.SetFc(1E7);

    // Creep - Steel
    UCrMP_CableWire01 SteelCreep;
    SteelCreep.SetE(1.882E11);
    SteelCreep.SetT0(20.);
    SteelCreep.SetC(0.002);

    // Creep - Alu
    UCrMP_CableWire01 AluCreep;
    AluCreep.SetA1(12.883);
    AluCreep.SetA2(20.434);
    AluCreep.SetA3(3.213);
    AluCreep.SetB1(-95417.805);
    AluCreep.SetB2(223.374);
    AluCreep.SetB3(0.104);
    AluCreep.SetC(0.003);
    AluCreep.SetE(5.939E10);
    AluCreep.SetT0(20.);

    // Thermal - Steel
    UThMP_Linear SteelThermal;
    SteelThermal.SetAlpha(0.000015);
    SteelThermal.SetT0(20.);

    // Thermal - Alu
    UThMP_Linear AluThermal;
    AluThermal.SetAlpha(0.000018);
    AluThermal.SetT0(20.);


    // ***
    // Create models
    // ***
    Handle(UCrM_CableWire01) SteelCreepModel = new UCrM_CableWire01(SteelCreep);
    Handle(UCrM_CableWire01) AluCreepModel = new UCrM_CableWire01(AluCreep);
    Handle(USSM_CableWire01) SteelStressStrainModel = new USSM_CableWire01(SteelSS);
    Handle(USSM_CableWire02) AluStressStrainModel = new USSM_CableWire02(AluSS);
    Handle(UThM_Linear) SteelThermalModel = new UThM_Linear(SteelThermal);
    Handle(UThM_Linear) AluThermalModel = new UThM_Linear(AluThermal);

    XSMP_BimetallicCable01 Section;
    Section.SetArea1(6.058E-5);
    Section.SetArea2(6.874E-4);
    Section.SetCreepModel1(SteelCreepModel);
    Section.SetCreepModel2(AluCreepModel);
    Section.SetStressStrainModel1(SteelStressStrainModel);
    Section.SetStressStrainModel2(AluStressStrainModel);
    Section.SetThermalModel1(SteelThermalModel);
    Section.SetThermalModel2(AluThermalModel);

    Handle(XSM_BimetallicCable01) aModel = new XSM_BimetallicCable01(Section);

    // ***
    // Sagging
    // ***

    // create span geometry
    CRSA_SpanGeometry aGeometry(400., 0.);

    // create load case
    CRSA_LoadCase aLoadCase1;
    aLoadCase1.SetDeadLoad(20.);
    aLoadCase1.SetTemperature(-30);

    // create load case
    CRSA_LoadCase aLoadCase2;
    aLoadCase2.SetDeadLoad(100.);
    aLoadCase2.SetTemperature(-10);

    // find empty length
    CRSA_FindEmptyLength anAnalysis(aGeometry, aModel);
    anAnalysis.AddSaggingHistory(0., aLoadCase1, 20000.);
    anAnalysis.AddSaggingHistory(0., aLoadCase2, 50000.);

    cout << anAnalysis.EmptyLength() << endl;
    cout << anAnalysis.Error() << endl;

}
