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


#ifndef __PSLG_Region_hxx__
#define __PSLG_Region_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <gp_Pnt2d.hxx>

// Handles
DEFINE_STANDARD_HANDLE(PSLG_Region, Standard_Transient)


// ============================================================================
/*
    \brief PSLG_Region
*/
// ============================================================================
class PSLG_Region : public Standard_Transient
{
    
public:
    // constructors
    Standard_EXPORT PSLG_Region();
    Standard_EXPORT PSLG_Region(const gp_Pnt2d& thePoint);
    Standard_EXPORT PSLG_Region(const gp_Pnt2d& thePoint, 
                                const Standard_Real theAttribute);
    Standard_EXPORT PSLG_Region(const gp_Pnt2d& thePoint,       
                                const Standard_Real theAttribute,        
                                const Standard_Real theMaximumArea);
    // destructors
    Standard_EXPORT ~PSLG_Region();

public:

    Standard_EXPORT Standard_Real       Attribute() const;
    Standard_EXPORT Standard_Real       MaximumArea() const;
    Standard_EXPORT const gp_Pnt2d&     Point() const;
    Standard_EXPORT void                SetAttribute(const Standard_Real theAttribute);
    Standard_EXPORT void                SetMaximumArea(const Standard_Real theMaximumArea);
    Standard_EXPORT void                SetPoint(const gp_Pnt2d& thePoint);
    Standard_EXPORT void                SetX(const Standard_Real theX);
    Standard_EXPORT void                SetY(const Standard_Real theY);
    Standard_EXPORT Standard_Real       X() const;
    Standard_EXPORT Standard_Real       Y() const;

private:

    Standard_Real           myAttribute;
    Standard_Real           myMaximumArea;
    gp_Pnt2d                myPoint;

public:

    DEFINE_STANDARD_RTTIEXT(PSLG_Region, Standard_Transient)

};

#endif // __PSLG_Region_hxx__
