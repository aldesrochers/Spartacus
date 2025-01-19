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


#ifndef __gp_Catenary_hxx__
#define __gp_Catenary_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <gp_Ax2.hxx>


// ============================================================================
/*!
 *  \brief gp_Catenary
 *  Class implementation of the description of a catenary in 2d parametric
 *  space.
*/
// ============================================================================
class gp_Catenary
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Standard_EXPORT gp_Catenary();
    Standard_EXPORT gp_Catenary(const gp_Ax2& thePosition,
                                const Standard_Real theParameter);
    // destructors
    Standard_EXPORT ~gp_Catenary();

public:

    Standard_EXPORT const gp_Ax1&   Axis() const;
    Standard_EXPORT const gp_Pnt&   Location() const;
    Standard_EXPORT void            Mirror(const gp_Pnt& thePoint);
    Standard_EXPORT void            Mirror(const gp_Ax1& theAxis);
    Standard_EXPORT void            Mirror(const gp_Ax2& thePosition);
    Standard_NODISCARD gp_Catenary  Mirrored(const gp_Pnt& thePoint) const;
    Standard_NODISCARD gp_Catenary  Mirrored(const gp_Ax1& theAxis) const;
    Standard_NODISCARD gp_Catenary  Mirrored(const gp_Ax2& thePosition) const;
    Standard_EXPORT Standard_Real   Parameter() const;
    Standard_EXPORT const gp_Ax2&   Position() const;
    Standard_EXPORT void            Rotate(const gp_Ax1& theAxis,
                                           const Standard_Real theAngle);
    Standard_NODISCARD gp_Catenary  Rotated(const gp_Ax1& theAxis,
                                            const Standard_Real theAngle) const;
    Standard_EXPORT void            Scale(const gp_Pnt& thePoint,
                                          const Standard_Real theScale);
    Standard_NODISCARD gp_Catenary  Scaled(const gp_Pnt& thePoint,
                                           const Standard_Real theScale) const;
    Standard_EXPORT void            SetAxis(const gp_Ax1& theAxis);
    Standard_EXPORT void            SetLocation(const gp_Pnt& thePoint);
    Standard_EXPORT void            SetParameter(const Standard_Real theParameter);
    Standard_EXPORT void            SetPosition(const gp_Ax2& thePosition);
    Standard_EXPORT void            Transform(const gp_Trsf& theTransformation);
    Standard_NODISCARD gp_Catenary  Transformed(const gp_Trsf& theTransformation) const;
    Standard_EXPORT void            Translate(const gp_Vec& theVector);
    Standard_EXPORT void            Translate(const gp_Pnt& thePoint1,
                                              const gp_Pnt& thePoint2);
    Standard_NODISCARD gp_Catenary  Translated(const gp_Vec& theVector) const;
    Standard_NODISCARD gp_Catenary  Translated(const gp_Pnt& thePoint1,
                                               const gp_Pnt& thePoint2) const;
    Standard_EXPORT gp_Ax1          XAxis() const;
    Standard_EXPORT gp_Ax1          YAxis() const;

private:

    Standard_Real       myParameter;
    gp_Ax2              myPosition;

};


#endif // __gp_Catenary_hxx__
