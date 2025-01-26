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


#ifndef __Tetgen_Facet_hxx__
#define __Tetgen_Facet_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <Tetgen_Array1OfPolygon.hxx>

// Handles
DEFINE_STANDARD_HANDLE(Tetgen_Facet, Standard_Transient)

// ============================================================================
/*
    \brief Tetgen_Facet
*/
// ============================================================================
class Tetgen_Facet : public Standard_Transient
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Standard_EXPORT Tetgen_Facet();
    Standard_EXPORT Tetgen_Facet(const Standard_Integer theNbPolygons);
    Standard_EXPORT Tetgen_Facet(const Standard_Integer theNbPolygons,
                                 const Standard_Integer theNbHoles);
    // destructors
    Standard_EXPORT ~Tetgen_Facet();

public:

    Standard_EXPORT const TColStd_Array2OfReal&     Holes() const {return myHoles;}
    Standard_EXPORT TColStd_Array2OfReal&           Holes() {return myHoles;}
    Standard_EXPORT const Tetgen_Array1OfPolygon&   Polygons() const {return myPolygons;}
    Standard_EXPORT Tetgen_Array1OfPolygon&         Polygons() {return myPolygons;}

public:

    Standard_EXPORT void                            Hole(const Standard_Integer theIndex,
                                                         Standard_Real& theX,
                                                         Standard_Real& theY,
                                                         Standard_Real& theZ) const;

    Standard_EXPORT Standard_Integer                NbHoles() const;
    Standard_EXPORT Standard_Integer                NbPolygons() const;

    Standard_EXPORT const Handle(Tetgen_Polygon)&   Polygon(const Standard_Integer theIndex) const;
    Standard_EXPORT void                            Polygon(const Standard_Integer theIndex,
                                                            Handle(Tetgen_Polygon)& thePolygon) const;

    Standard_EXPORT void                            ResizeHoles(const Standard_Integer theNbHoles,
                                                                const Standard_Boolean toCopyData = Standard_False);
    Standard_EXPORT void                            ResizePolygons(const Standard_Integer theNbPolygons,
                                                                   const Standard_Boolean toCopyData = Standard_False);

    Standard_EXPORT void                            SetHole(const Standard_Integer theIndex,
                                                            const Standard_Real theX,
                                                            const Standard_Real theY,
                                                            const Standard_Real theZ);

    Standard_EXPORT void                            SetPolygon(const Standard_Integer theIndex,
                                                               const Handle(Tetgen_Polygon)& thePolygon);


private:
    
    TColStd_Array2OfReal        myHoles;
    Tetgen_Array1OfPolygon      myPolygons;

public:

    DEFINE_STANDARD_RTTIEXT(Tetgen_Facet, Standard_Transient)

};

#endif // __Tetgen_Facet_hxx__
