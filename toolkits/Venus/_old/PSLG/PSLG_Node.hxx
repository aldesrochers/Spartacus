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


#ifndef __PSLG_Node_hxx__
#define __PSLG_Node_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <gp_Pnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>

// Handles
DEFINE_STANDARD_HANDLE(PSLG_Node, Standard_Transient)


// ============================================================================
/*
    \brief PSLG_Node
*/
// ============================================================================
class PSLG_Node : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT PSLG_Node();
    Standard_EXPORT PSLG_Node(const gp_Pnt2d& thePoint);
    Standard_EXPORT PSLG_Node(const gp_Pnt2d& thePoint, 
                              const TColStd_Array1OfReal& theAttributes);
    Standard_EXPORT PSLG_Node(const gp_Pnt2d& thePoint,       
                              const TColStd_Array1OfReal& theAttributes,        
                              const Standard_Integer theBoundaryMarker);
    // destructors
    Standard_EXPORT ~PSLG_Node();

public:

    Standard_EXPORT const TColStd_Array1OfReal& Attributes() const;
    Standard_EXPORT Standard_Integer            BoundaryMarker() const;
    Standard_EXPORT const gp_Pnt2d&             Point() const;
    Standard_EXPORT void                        SetAttributes(const TColStd_Array1OfReal& theAttributes);
    Standard_EXPORT void                        SetBoundaryMarker(const Standard_Integer theBoundaryMarker);
    Standard_EXPORT void                        SetPoint(const gp_Pnt2d& thePoint);
    Standard_EXPORT void                        SetX(const Standard_Real theX);
    Standard_EXPORT void                        SetY(const Standard_Real theY);
    Standard_EXPORT Standard_Real               X() const;
    Standard_EXPORT Standard_Real               Y() const;

private:

    TColStd_Array1OfReal    myAttributes;
    Standard_Integer        myBoundaryMarker;
    gp_Pnt2d                myPoint;

public:

    DEFINE_STANDARD_RTTIEXT(PSLG_Node, Standard_Transient)

};

#endif // __PSLG_Node_hxx__
