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



// Spartacus
#include <Triangle.hxx>


// ============================================================================
/*!
    \brief Triangulation()
    Populate a triangulation based on a triangle model.
*/
// ============================================================================
Handle(Poly_Triangulation) Triangle::Triangulation(const Handle(Triangle_Model)& theModel)
{
    // initialize data structures
    TColgp_Array1OfPnt myPoints;
    Poly_Array1OfTriangle myTriangles;
    myPoints.Resize(1, theModel->NbPoints(), Standard_False);
    myTriangles.Resize(1, theModel->NbTriangles(), Standard_False);

    // process nodes
    for(Standard_Integer i = 1; i <= theModel->NbPoints(); i++) {
        Standard_Real X, Y;
        theModel->Point(i, X, Y);
        myPoints.SetValue(i, gp_Pnt(X, Y, 0.0));
    }

    // process triangles
    for(Standard_Integer i = 1; i <= theModel->NbTriangles(); i++) {
        Standard_Integer N1, N2, N3;
        theModel->TriangleCorner(i, 1, N1);
        theModel->TriangleCorner(i, 2, N2);
        theModel->TriangleCorner(i, 3, N3);
        Poly_Triangle aTriangle(N1, N2, N3);
        myTriangles.SetValue(i, aTriangle);
    }

    // create a triangulation
    Handle(Poly_Triangulation) aTriangulation = new Poly_Triangulation(myPoints, myTriangles);
    return aTriangulation;
}

