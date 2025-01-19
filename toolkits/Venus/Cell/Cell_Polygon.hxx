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


#ifndef __Cell_Polygon_hxx__
#define __Cell_Polygon_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>

// Spartacus
#include <Cell_Array1OfEdge.hxx>

// Handles
DEFINE_STANDARD_HANDLE(Cell_Polygon, Standard_Transient)


// ============================================================================
/*
    \brief Cell_Polygon
*/
// ============================================================================
class Cell_Polygon : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT Cell_Polygon();
    // destructors
    Standard_EXPORT ~Cell_Polygon();

public:

    Standard_EXPORT const Handle(Cell_Edge)&    Edge(const Standard_Integer theIndex) const;
    Standard_EXPORT Standard_Integer            NbEdges() const;
    Standard_EXPORT void                        ResizeEdges(const Standard_Integer theNbEdges,
                                                            const Standard_Boolean toCopyData = Standard_False);
    Standard_EXPORT void                        SetEdge(const Standard_Integer theIndex,
                                                        const Handle(Cell_Edge)& theEdge);

private:

    Cell_Array1OfEdge   myEdges;

public:

    DEFINE_STANDARD_RTTIEXT(Cell_Polygon, Standard_Transient)

};

#endif // __Cell_Polygon_hxx__
