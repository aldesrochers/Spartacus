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


#ifndef __gp_Catenary2d_hxx__
#define __gp_Catenary2d_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <gp_Ax22d.hxx>


// ============================================================================
/*!
 *  \brief gp_Catenary2d
 *  Class implementation of the description of a catenary in 2d parametric
 *  space.
*/
// ============================================================================
class gp_Catenary2d
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Standard_EXPORT gp_Catenary2d();
    Standard_EXPORT gp_Catenary2d(const gp_Ax22d& thePosition,
                                  const Standard_Real theParameter);
    Standard_EXPORT gp_Catenary2d(const gp_Ax2d& theMirrorAxis,
                                  const Standard_Real theParameter,
                                  const Standard_Boolean theSense = Standard_True);
    // destructors
    Standard_EXPORT ~gp_Catenary2d();

public:

    Standard_EXPORT gp_Pnt2d            Location() const;
    Standard_EXPORT void                Mirror(const gp_Pnt2d& thePoint);
    Standard_EXPORT void                Mirror(const gp_Ax2d& theAxis);
    Standard_EXPORT gp_Ax2d             MirrorAxis() const;
    Standard_NODISCARD gp_Catenary2d    Mirrored(const gp_Ax2d& theAxis) const;
    Standard_EXPORT Standard_Real       Parameter() const;
    Standard_EXPORT gp_Ax22d            Position() const;
    Standard_EXPORT void                Reverse();
    Standard_NODISCARD gp_Catenary2d    Reversed() const;
    Standard_EXPORT void                Rotate(const gp_Pnt2d& thePoint,
                                               const Standard_Real theAngle);
    Standard_NODISCARD gp_Catenary2d    Rotated(const gp_Pnt2d& thePoint,
                                                const Standard_Real theAngle) const;
    Standard_EXPORT void                Scale(const gp_Pnt2d& thePoint,
                                              const Standard_Real theScale);
    Standard_NODISCARD gp_Catenary2d    Scaled(const gp_Pnt2d& thePoint,
                                               const Standard_Real theScale) const;
    Standard_EXPORT void                SetLocation(const gp_Pnt2d& theLocation);
    Standard_EXPORT void                SetMirrorAxis(const gp_Ax2d& theMirrorAxis);
    Standard_EXPORT void                SetParameter(const Standard_Real theParameter);
    Standard_EXPORT void                SetPosition(const gp_Ax22d& thePosition);
    Standard_EXPORT void                Transform(const gp_Trsf2d& theTransformation);
    Standard_NODISCARD gp_Catenary2d    Transformed(const gp_Trsf2d& theTransformation) const;
    Standard_EXPORT void                Translate(const gp_Vec2d& theVector);
    Standard_EXPORT void                Translate(const gp_Pnt2d& thePoint1,
                                                  const gp_Pnt2d& thePoint2);
    Standard_NODISCARD gp_Catenary2d    Translated(const gp_Vec2d& theVector) const;
    Standard_NODISCARD gp_Catenary2d    Translated(const gp_Pnt2d& thePoint1,
                                                   const gp_Pnt2d& thePoint2) const;

private:

    Standard_Real       myParameter;
    gp_Ax22d            myPosition;

};


#endif // __gp_Catenary2d_hxx__
