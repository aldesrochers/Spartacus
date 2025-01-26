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


#ifndef __Cell_Face_hxx__
#define __Cell_Face_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_Array1OfInteger.hxx>

// Spartacus
#include <Cell_Polygon.hxx>

// Handles
DEFINE_STANDARD_HANDLE(Cell_Face, Standard_Transient)


// ============================================================================
/*
    \brief Cell_Face
*/
// ============================================================================
class Cell_Face : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT Cell_Face();
    // destructors
    Standard_EXPORT ~Cell_Face();

public:

    Standard_EXPORT Standard_Integer            NbNodes() const;
    Standard_EXPORT Standard_Integer            Node(const Standard_Integer theIndex) const;
    Standard_EXPORT const Handle(Cell_Polygon)& Polygon() const;
    Standard_EXPORT void                        ResizeNodes(const Standard_Integer theNbNodes,
                                                            const Standard_Boolean toCopyData = Standard_False);
    Standard_EXPORT void                        SetNode(const Standard_Integer theIndex,
                                                        const Standard_Integer theNode);
    Standard_EXPORT void                        SetPolygon(const Handle(Cell_Polygon)& thePolygon);

private:

    Handle(Cell_Polygon)    myPolygon;
    TColStd_Array1OfInteger myNodes;

public:

    DEFINE_STANDARD_RTTIEXT(Cell_Face, Standard_Transient)

};

#endif // __Cell_Face_hxx__
