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

#include <TColStd_ListOfReal.hxx>
#include <MCL1d_Cable.hxx>
#include <material_Cable.hxx>

#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include <QMainWindow>
#include <QApplication>


#include <MaterialCLaw_UniaxialPolynomial01.hxx>

int main(int argc, char** argv)
{

    Standard_Real E = 1E10;
    Standard_Real EpsM = 0.1;
    Standard_Real Fyc = 10E6;
    Standard_Real Beta = 20;
    Standard_Real A0 = 0.;
    Standard_Real A1 = 1.027792;
    Standard_Real A2 = -2.805717;
    Standard_Real A3 = 42.63799;
    Standard_Real A4 = -1060.292;
    Standard_Real A5 = 5066.059;
    Standard_Real A6 = 0.;
    Handle(MaterialCLaw_UniaxialPolynomial01) aMaterial =
            new MaterialCLaw_UniaxialPolynomial01(E, EpsM, Fyc, Beta, A0, A1, A2, A3, A4, A5, A6);

    cout << aMaterial->EpsCM() << endl;

    TColStd_ListOfReal aList;
    aList.Append(0.);
    aList.Append(-0.0002);
    aList.Append(-0.0004);
    aList.Append(-0.0006);
    aList.Append(-0.0008);
    aList.Append(-0.0010);
    aList.Append(-0.0012);
    aList.Append(-0.0014);
    aList.Append(-0.0016);
    aList.Append(-0.0018);
    aList.Append(-0.0020);
    aList.Append(-0.001);

    QtCharts::QLineSeries* aSeries = new QtCharts::QLineSeries();

    TColStd_ListOfReal::Iterator anIt(aList);
    for(;anIt.More();anIt.Next()) {
        Standard_Real Eps = anIt.Value();
        aMaterial->SetTrialStrain(Eps);
        aMaterial->UpdateInternalState();
        Standard_Real Sig = aMaterial->CurrentStress();
        aMaterial->CommitState();
        aSeries->append(Eps, Sig);
    }

    QApplication anApp(argc, argv);

    QtCharts::QChart* aChart = new QtCharts::QChart();
    aChart->addSeries(aSeries);
    aChart->createDefaultAxes();

    QtCharts::QChartView* aView = new QtCharts::QChartView(aChart);


    QMainWindow aWindow;
    aWindow.setCentralWidget(aView);
    aWindow.show();
    return anApp.exec();

}

