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


#ifndef __Mesh2d_Cell_hxx__
#define __Mesh2d_Cell_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_Array1OfInteger.hxx>

// Spartacus
#include <Mesh2d_TypeOfCell.hxx>

// Handles
DEFINE_STANDARD_HANDLE(Mesh2d_Cell, Standard_Transient)


// ============================================================================
/*
    \brief Mesh2d_Cell
*/
// ============================================================================
class Mesh2d_Cell : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT Mesh2d_Cell();
    Standard_EXPORT Mesh2d_Cell(const Standard_Integer theNbNodes, 
                                Mesh2d_TypeOfCell theCellType);
    // destructors
    Standard_EXPORT ~Mesh2d_Cell();

public:

    Standard_EXPORT Mesh2d_TypeOfCell   CellType() const;
    Standard_EXPORT Standard_Integer    NbNodes() const;
    Standard_EXPORT Standard_Integer    Node(const Standard_Integer theIndex) const;
    Standard_EXPORT void                ResizeNodes(const Standard_Integer theNbNodes,
                                                    const Standard_Boolean toCopyData = Standard_False);
    Standard_EXPORT void                SetCellType(const Mesh2d_TypeOfCell theCellType);
    Standard_EXPORT void                SetNode(const Standard_Integer theIndex,
                                                const Standard_Integer theNode);

private:

    Mesh2d_TypeOfCell       myCellType;
    TColStd_Array1OfInteger myNodes;

public:

    DEFINE_STANDARD_RTTIEXT(Mesh2d_Cell, Standard_Transient)

};

#endif // __Mesh2d_Cell_hxx__
