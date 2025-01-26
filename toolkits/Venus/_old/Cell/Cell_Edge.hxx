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


#ifndef __Cell_Edge_hxx__
#define __Cell_Edge_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_Array1OfInteger.hxx>

// Handles
DEFINE_STANDARD_HANDLE(Cell_Edge, Standard_Transient)


// ============================================================================
/*
    \brief Cell_Edge
*/
// ============================================================================
class Cell_Edge : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT Cell_Edge();
    // destructors
    Standard_EXPORT ~Cell_Edge();

public:

    Standard_EXPORT Standard_Integer    NbNodes() const;
    Standard_EXPORT Standard_Integer    Node(const Standard_Integer theIndex) const;
    Standard_EXPORT void                ResizeNodes(const Standard_Integer theNbNodes,
                                                    const Standard_Boolean toCopyData = Standard_False);
    Standard_EXPORT void                SetNode(const Standard_Integer theIndex,
                                                const Standard_Integer theNode);

private:

    TColStd_Array1OfInteger myNodes;

public:

    DEFINE_STANDARD_RTTIEXT(Cell_Edge, Standard_Transient)

};

#endif // __Cell_Edge_hxx__
