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


#ifndef __Tetgen_Polygon_hxx__
#define __Tetgen_Polygon_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_Array1OfInteger.hxx>

// Handles
DEFINE_STANDARD_HANDLE(Tetgen_Polygon, Standard_Transient)

// ============================================================================
/*
    \brief Tetgen_Polygon
*/
// ============================================================================
class Tetgen_Polygon : public Standard_Transient
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Standard_EXPORT Tetgen_Polygon();
    Standard_EXPORT Tetgen_Polygon(const Standard_Integer theNbPoints);
    // destructors
    Standard_EXPORT ~Tetgen_Polygon();

public:

    Standard_EXPORT const TColStd_Array1OfInteger&  Points() const {return myPoints;}
    Standard_EXPORT TColStd_Array1OfInteger&        Points() {return myPoints;}

public:

    Standard_EXPORT Standard_Integer     NbPoints() const;
    Standard_EXPORT Standard_Integer     Point(const Standard_Integer theIndex) const;
    Standard_EXPORT void                 Point(const Standard_Integer theIndex, 
                                               Standard_Integer& thePoint) const;
    Standard_EXPORT void                 ResizePoints(const Standard_Integer theNbPoints,
                                                      const Standard_Boolean toCopyData = Standard_False);
    Standard_EXPORT void                 SetPoint(const Standard_Integer theIndex, 
                                                  const Standard_Integer thePoint);

private:
    
    TColStd_Array1OfInteger     myPoints;

public:

    DEFINE_STANDARD_RTTIEXT(Tetgen_Polygon, Standard_Transient)

};

#endif // __Tetgen_Polygon_hxx__
