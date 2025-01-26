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


int main(int argc, char *argv[])
{
    
}


/*

// Spartacus
#include <Triangle.hxx>
#include <Triangle_Builder.hxx>
#include <Triangle_Triangulate.hxx>


int main(int argc, char *argv[])
{

    Triangle_Builder aBuilder;
    aBuilder.ResizePoints(3, 0);
    aBuilder.SetPoint(1, 0., 0.);
    aBuilder.SetPoint(2, 1., 0.);
    aBuilder.SetPoint(3, 0., 1.);
    aBuilder.ResizeSegments(3);
    aBuilder.SetSegment(1, 1, 2);
    aBuilder.SetSegment(2, 2, 3);
    aBuilder.SetSegment(3, 3, 1);

    Handle(Triangle_Model) anInputModel = aBuilder.Model();
    
    Triangle_Parameters aParameters;
    aParameters.SetMaxArea(0.1);
    Triangle_Triangulate anAlgo(anInputModel, aParameters);
    anAlgo.Perform();

    Handle(Triangle_Model) anOutputModel = anAlgo.OutputModel();

    Handle(Poly_Triangulation) aTriangulation = Triangle::Triangulation(anOutputModel);

    cout << aTriangulation->NbTriangles() << endl;
    cout << aTriangulation->NbNodes() << endl;

    return 0;
}

*/