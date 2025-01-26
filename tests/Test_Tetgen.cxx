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


#include <AIS_InteractiveContext.hxx>
#include <AIS_Triangulation.hxx>
#include <Poly.hxx>
#include <TopTools_DataMapOfIntegerShape.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <TopoDS_Wire.hxx>
#include <AIS_Shape.hxx>

// Spartacus
#include <Tetgen.hxx>
#include <Tetgen_Tetrahedralize.hxx>
#include <Viewer3d_View.hxx>

// Qt
#include <QApplication>


int main(int argc, char *argv[])
{

    Handle(Tetgen_Model) aModel = new Tetgen_Model();
    aModel->ResizePoints(8, 0);
    aModel->SetPoint(1, 0., 0., 0.);
    aModel->SetPoint(2, 1., 0., 0.);
    aModel->SetPoint(3, 0., 1., 0.);
    aModel->SetPoint(4, 1., 1., 0.);
    aModel->SetPoint(5, 0., 0., 1.);
    aModel->SetPoint(6, 1., 0., 1.);
    aModel->SetPoint(7, 0., 1., 1.);
    aModel->SetPoint(8, 1., 1., 1.);

    aModel->ResizeFacets(6);
    Handle(Tetgen_Facet) aFacet1 = new Tetgen_Facet(1);
    Handle(Tetgen_Polygon) aPolygon1 = new Tetgen_Polygon(4);
    aPolygon1->SetPoint(1, 1);
    aPolygon1->SetPoint(2, 2);
    aPolygon1->SetPoint(3, 6);
    aPolygon1->SetPoint(4, 5);
    aFacet1->SetPolygon(1, aPolygon1);
    aModel->SetFacet(1, aFacet1);
    
    Handle(Tetgen_Facet) aFacet2 = new Tetgen_Facet(1);
    Handle(Tetgen_Polygon) aPolygon2 = new Tetgen_Polygon(4);
    aPolygon2->SetPoint(1, 2);
    aPolygon2->SetPoint(2, 4);
    aPolygon2->SetPoint(3, 8);
    aPolygon2->SetPoint(4, 6);
    aFacet2->SetPolygon(1, aPolygon2);
    aModel->SetFacet(2, aFacet2);
    
    Handle(Tetgen_Facet) aFacet3 = new Tetgen_Facet(1);
    Handle(Tetgen_Polygon) aPolygon3 = new Tetgen_Polygon(4);
    aPolygon3->SetPoint(1, 4);
    aPolygon3->SetPoint(2, 3);
    aPolygon3->SetPoint(3, 7);
    aPolygon3->SetPoint(4, 8);
    aFacet3->SetPolygon(1, aPolygon3);
    aModel->SetFacet(3, aFacet3);
    
    Handle(Tetgen_Facet) aFacet4 = new Tetgen_Facet(1);
    Handle(Tetgen_Polygon) aPolygon4 = new Tetgen_Polygon(4);
    aPolygon4->SetPoint(1, 3);
    aPolygon4->SetPoint(2, 1);
    aPolygon4->SetPoint(3, 5);
    aPolygon4->SetPoint(4, 7);
    aFacet4->SetPolygon(1, aPolygon4);
    aModel->SetFacet(4, aFacet4);
    
    Handle(Tetgen_Facet) aFacet5 = new Tetgen_Facet(1);
    Handle(Tetgen_Polygon) aPolygon5 = new Tetgen_Polygon(4);
    aPolygon5->SetPoint(1, 1);
    aPolygon5->SetPoint(2, 3);
    aPolygon5->SetPoint(3, 4);
    aPolygon5->SetPoint(4, 2);
    aFacet5->SetPolygon(1, aPolygon5);
    aModel->SetFacet(5, aFacet5);
    
    Handle(Tetgen_Facet) aFacet6 = new Tetgen_Facet(1);
    Handle(Tetgen_Polygon) aPolygon6 = new Tetgen_Polygon(4);
    aPolygon6->SetPoint(1, 5);
    aPolygon6->SetPoint(2, 6);
    aPolygon6->SetPoint(3, 8);
    aPolygon6->SetPoint(4, 7);
    aFacet6->SetPolygon(1, aPolygon6);
    aModel->SetFacet(6, aFacet6);

    Tetgen_Parameters aParameters;
    aParameters.SetMaxVolume(0.05);
    aParameters.SetIsVerbose(Standard_True);
    aParameters.SetIsQuiet(Standard_False);

    Tetgen_Tetrahedralize anAlgo(aModel, aParameters);
    anAlgo.Perform();
    Handle(Tetgen_Model) aTetgenModel = anAlgo.OutputModel();

    Handle(Poly_Triangulation) aTriangulation = Tetgen::Triangulation(aTetgenModel);

    Poly::Write(aTriangulation, cout);
    

    QApplication aApp(argc, argv);
    
    Viewer3d_View* aView = new Viewer3d_View();
    aView->show();

    Handle(AIS_InteractiveContext) aContext = aView->context();

    TopTools_DataMapOfIntegerShape aMap;
    for(Standard_Integer i = 1; i <= aTriangulation->NbTriangles(); i++) {
        const Poly_Triangle& aTriangle = aTriangulation->Triangle(i);
        Standard_Integer P1, P2, P3;
        aTriangle.Get(P1, P2, P3);
        gp_Pnt aPoint1 = aTriangulation->Node(P1);
        gp_Pnt aPoint2 = aTriangulation->Node(P2);
        gp_Pnt aPoint3 = aTriangulation->Node(P3);
        BRepBuilderAPI_MakePolygon aBuilder(aPoint1, aPoint2, aPoint3, Standard_True);
        TopoDS_Shape aShape = aBuilder.Shape();
        Handle(AIS_Shape) anAIS = new AIS_Shape(aShape);
        aContext->Display(anAIS, Standard_True);
    }


    aView->view()->TriedronDisplay();
    aView->view()->FitAll();
    aView->view()->Update();

    aApp.exec();
}
