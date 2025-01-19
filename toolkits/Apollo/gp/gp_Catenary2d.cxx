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

// Spartacus
#include <gp_Catenary2d.hxx>

// OpenCascade
#include <Standard_ConstructionError.hxx>



// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
gp_Catenary2d::gp_Catenary2d()
    : myParameter(1./RealLast())
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
gp_Catenary2d::gp_Catenary2d(const gp_Ax22d& thePosition,
                             const Standard_Real theParameter)
    : myPosition(thePosition),
      myParameter(theParameter)
{
    Standard_ConstructionError_Raise_if(theParameter < 0.,
                                        "gp_Catenary2d::SetParameter() - Must be > 0.");
}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
gp_Catenary2d::gp_Catenary2d(const gp_Ax2d& theMirrorAxis,
                             const Standard_Real theParameter,
                             const Standard_Boolean theSense)
    : myParameter(theParameter)
{
    myPosition = gp_Ax22d(theMirrorAxis, theSense);
    Standard_ConstructionError_Raise_if(theParameter < 0.,
                                        "gp_Catenary2d::SetParameter() - Must be > 0.");
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
gp_Catenary2d::~gp_Catenary2d()
{

}

// ============================================================================
/*!
 *  \brief Location()
*/
// ============================================================================
gp_Pnt2d gp_Catenary2d::Location() const
{
    return myPosition.Location();
}

// ============================================================================
/*!
 *  \brief Mirror()
*/
// ============================================================================
void gp_Catenary2d::Mirror(const gp_Pnt2d &thePoint)
{
    myPosition.Mirror(thePoint);
}

// ============================================================================
/*!
 *  \brief Mirror()
*/
// ============================================================================
void gp_Catenary2d::Mirror(const gp_Ax2d &theAxis)
{
    myPosition.Mirror(theAxis);
}

// ============================================================================
/*!
 *  \brief Mirrored()
*/
// ============================================================================
gp_Catenary2d gp_Catenary2d::Mirrored(const gp_Ax2d &theAxis) const
{
    gp_Ax22d anAxis = myPosition.Mirrored(theAxis);
    return gp_Catenary2d(anAxis, myParameter);
}

// ============================================================================
/*!
 *  \brief MirrorAxis()
*/
// ============================================================================
gp_Ax2d gp_Catenary2d::MirrorAxis() const
{
    return myPosition.XAxis();
}

// ============================================================================
/*!
 *  \brief Parameter()
*/
// ============================================================================
Standard_Real gp_Catenary2d::Parameter() const
{
    return myParameter;
}

// ============================================================================
/*!
 *  \brief Position()
*/
// ============================================================================
gp_Ax22d gp_Catenary2d::Position() const
{
    return myPosition;
}

// ============================================================================
/*!
 *  \brief Reverse()
*/
// ============================================================================
void gp_Catenary2d::Reverse()
{
    gp_Dir2d aXDir = myPosition.XDirection();
    gp_Dir2d aYDir = myPosition.YDirection().Reversed();
    gp_Ax22d anAxis(myPosition.Location(), aXDir, aYDir);
    myPosition.SetAxis(anAxis);
}

// ============================================================================
/*!
 *  \brief Reversed()
*/
// ============================================================================
gp_Catenary2d gp_Catenary2d::Reversed() const
{
    gp_Dir2d aXDir = myPosition.XDirection();
    gp_Dir2d aYDir = myPosition.YDirection().Reversed();
    gp_Ax22d anAxis(myPosition.Location(), aXDir, aYDir);
    return gp_Catenary2d(anAxis, myParameter);
}

// ============================================================================
/*!
 *  \brief Rotate()
*/
// ============================================================================
void gp_Catenary2d::Rotate(const gp_Pnt2d &thePoint,
                           const Standard_Real theAngle)
{
    myPosition.Rotate(thePoint, theAngle);
}

// ============================================================================
/*!
 *  \brief Rotated()
*/
// ============================================================================
gp_Catenary2d gp_Catenary2d::Rotated(const gp_Pnt2d &thePoint,
                                     const Standard_Real theAngle) const
{
    gp_Ax22d anAxis = myPosition.Rotated(thePoint, theAngle);
    return gp_Catenary2d(anAxis, myParameter);
}

// ============================================================================
/*!
 *  \brief Scale()
*/
// ============================================================================
void gp_Catenary2d::Scale(const gp_Pnt2d &thePoint,
                          const Standard_Real theScale)
{
    if(theScale < 0.)
        myParameter *= -1.;
    myPosition.Scale(thePoint, theScale);
}

// ============================================================================
/*!
 *  \brief Scaled()
*/
// ============================================================================
gp_Catenary2d gp_Catenary2d::Scaled(const gp_Pnt2d &thePoint,
                                    const Standard_Real theScale) const
{
    Standard_Real aParameter = myParameter;
    if(theScale < 0.)
        aParameter *= -1.;
    gp_Ax22d anAxis = myPosition.Scaled(thePoint, theScale);
    return gp_Catenary2d(anAxis, aParameter);
}

// ============================================================================
/*!
 *  \brief SetLocation()
*/
// ============================================================================
void gp_Catenary2d::SetLocation(const gp_Pnt2d &theLocation)
{
    myPosition.SetLocation(theLocation);
}

// ============================================================================
/*!
 *  \brief SetMirrorAxis()
*/
// ============================================================================
void gp_Catenary2d::SetMirrorAxis(const gp_Ax2d &theMirrorAxis)
{
    myPosition.SetXAxis(theMirrorAxis);
}

// ============================================================================
/*!
 *  \brief SetParameter()
*/
// ============================================================================
void gp_Catenary2d::SetParameter(const Standard_Real theParameter)
{
    Standard_ConstructionError_Raise_if(theParameter < 0.,
                                        "gp_Catenary2d::SetParameter() - Must be > 0.");
    myParameter = theParameter;
}

// ============================================================================
/*!
 *  \brief SetPosition()
*/
// ============================================================================
void gp_Catenary2d::SetPosition(const gp_Ax22d &thePosition)
{
    myPosition = thePosition;
}

// ============================================================================
/*!
 *  \brief Transform()
*/
// ============================================================================
void gp_Catenary2d::Transform(const gp_Trsf2d &theTransformation)
{
    if(theTransformation.ScaleFactor() < 0.)
        myParameter *= -1.;
    myPosition.Transform(theTransformation);
}

// ============================================================================
/*!
 *  \brief Transformed()
*/
// ============================================================================
gp_Catenary2d gp_Catenary2d::Transformed(const gp_Trsf2d &theTransformation) const
{
    Standard_Real aParameter = myParameter;
    if(theTransformation.ScaleFactor())
        aParameter *= -1.;
    gp_Ax22d anAxis = myPosition.Transformed(theTransformation);
    return gp_Catenary2d(anAxis, aParameter);
}

// ============================================================================
/*!
 *  \brief Translate()
*/
// ============================================================================
void gp_Catenary2d::Translate(const gp_Vec2d &theVector)
{
    myPosition.Translate(theVector);
}

// ============================================================================
/*!
 *  \brief Translate()
*/
// ============================================================================
void gp_Catenary2d::Translate(const gp_Pnt2d &thePoint1,
                              const gp_Pnt2d &thePoint2)
{
    myPosition.Translate(thePoint1, thePoint2);
}

// ============================================================================
/*!
 *  \brief Translated()
*/
// ============================================================================
gp_Catenary2d gp_Catenary2d::Translated(const gp_Vec2d &theVector) const
{
    gp_Ax22d anAxis = myPosition.Translated(theVector);
    return gp_Catenary2d(anAxis, myParameter);
}

// ============================================================================
/*!
 *  \brief Translated()
*/
// ============================================================================
gp_Catenary2d gp_Catenary2d::Translated(const gp_Pnt2d &thePoint1,
                                        const gp_Pnt2d &thePoint2) const
{
    gp_Ax22d anAxis = myPosition.Translated(thePoint1, thePoint2);
    return gp_Catenary2d(anAxis, myParameter);
}


