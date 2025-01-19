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
#include <Triangle_Triangulate.hxx>
#include <Triangle_Parameters.hxx>


int main(int argc, char *argv[])
{

    Handle(PSLG_Model) aModel = new PSLG_Model();
    aModel->ResizeNodes(3);
    aModel->SetNode(1, new PSLG_Node(gp_Pnt2d(0,0)));
    aModel->SetNode(2, new PSLG_Node(gp_Pnt2d(1,0)));    
    aModel->SetNode(3, new PSLG_Node(gp_Pnt2d(0,1)));
    aModel->ResizeSegments(3);
    aModel->SetSegment(1, new PSLG_Segment(1,2));
    aModel->SetSegment(2, new PSLG_Segment(2,3));
    aModel->SetSegment(3, new PSLG_Segment(3,1));
    
    Triangle_Parameters aParameters;
    aParameters.MaximumArea = 0.01;

    Triangle_Triangulate aTriangulator;
    aTriangulator.SetModel(aModel);
    aTriangulator.SetParameters(aParameters);
    aTriangulator.Perform();

    cout << aTriangulator.IsDone () << endl;

    Handle(Mesh2d_Grid) aGrid = aTriangulator.Grid();

    cout << aGrid->NbCells() << endl;
    cout << aGrid->NbNodes() << endl;
    
    return 0;



}
