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
#include <gp_Catenary.hxx>

// OpenCascade
#include <Standard_ConstructionError.hxx>



// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
gp_Catenary::gp_Catenary()
    : myParameter(1./RealLast())
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
gp_Catenary::gp_Catenary(const gp_Ax2& thePosition,
                         const Standard_Real theParameter)
    : myPosition(thePosition),
      myParameter(theParameter)
{
    Standard_ConstructionError_Raise_if(theParameter < 0.,
                                        "gp_Catenary::SetParameter() - Must be > 0.");
}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
gp_Catenary::~gp_Catenary()
{

}

// ============================================================================
/*!
 *  \brief Axis()
*/
// ============================================================================
const gp_Ax1& gp_Catenary::Axis() const
{
    return myPosition.Axis();
}

// ============================================================================
/*!
 *  \brief Location()
*/
// ============================================================================
const gp_Pnt& gp_Catenary::Location() const
{
    return myPosition.Location();
}

// ============================================================================
/*!
 *  \brief Mirror()
*/
// ============================================================================
void gp_Catenary::Mirror(const gp_Pnt &thePoint)
{
    myPosition.Mirror(thePoint);
}

// ============================================================================
/*!
 *  \brief Mirror()
*/
// ============================================================================
void gp_Catenary::Mirror(const gp_Ax1 &theAxis)
{
    myPosition.Mirror(theAxis);
}

// ============================================================================
/*!
 *  \brief Mirror()
*/
// ============================================================================
void gp_Catenary::Mirror(const gp_Ax2 &thePosition)
{
    myPosition.Mirror(thePosition);
}

// ============================================================================
/*!
 *  \brief Mirrored()
*/
// ============================================================================
gp_Catenary gp_Catenary::Mirrored(const gp_Pnt &thePoint) const
{
    gp_Ax2 anAxis = myPosition.Mirrored(thePoint);
    return gp_Catenary(anAxis, myParameter);
}

// ============================================================================
/*!
 *  \brief Mirrored()
*/
// ============================================================================
gp_Catenary gp_Catenary::Mirrored(const gp_Ax1 &theAxis) const
{
    gp_Ax2 anAxis = myPosition.Mirrored(theAxis);
    return gp_Catenary(anAxis, myParameter);
}

// ============================================================================
/*!
 *  \brief Mirrored()
*/
// ============================================================================
gp_Catenary gp_Catenary::Mirrored(const gp_Ax2 &thePosition) const
{
    gp_Ax2 anAxis = myPosition.Mirrored(thePosition);
    return gp_Catenary(anAxis, myParameter);
}

// ============================================================================
/*!
 *  \brief Parameter()
*/
// ============================================================================
Standard_Real gp_Catenary::Parameter() const
{
    return myParameter;
}

// ============================================================================
/*!
 *  \brief Position()
*/
// ============================================================================
const gp_Ax2& gp_Catenary::Position() const
{
    return myPosition;
}

// ============================================================================
/*!
 *  \brief Rotate()
*/
// ============================================================================
void gp_Catenary::Rotate(const gp_Ax1 &theAxis,
                         const Standard_Real theAngle)
{
    myPosition.Rotate(theAxis, theAngle);
}

// ============================================================================
/*!
 *  \brief Rotated()
*/
// ============================================================================
gp_Catenary gp_Catenary::Rotated(const gp_Ax1 &theAxis,
                                 const Standard_Real theAngle) const
{
    gp_Ax2 anAxis = myPosition.Rotated(theAxis, theAngle);
    return gp_Catenary(anAxis, myParameter);
}

// ============================================================================
/*!
 *  \brief Scale()
*/
// ============================================================================
void gp_Catenary::Scale(const gp_Pnt &thePoint,
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
gp_Catenary gp_Catenary::Scaled(const gp_Pnt &thePoint,
                                const Standard_Real theScale) const
{
    Standard_Real aParameter = myParameter;
    if(theScale < 0.)
        aParameter *= -1.;
    gp_Ax2 anAxis = myPosition.Scaled(thePoint, theScale);
    return gp_Catenary(anAxis, aParameter);
}

// ============================================================================
/*!
 *  \brief SetAxis()
*/
// ============================================================================
void gp_Catenary::SetAxis(const gp_Ax1 &theAxis)
{
    myPosition.SetAxis(theAxis);
}

// ============================================================================
/*!
 *  \brief SetLocation()
*/
// ============================================================================
void gp_Catenary::SetLocation(const gp_Pnt &thePoint)
{
    myPosition.SetLocation(thePoint);
}

// ============================================================================
/*!
 *  \brief SetParameter()
*/
// ============================================================================
void gp_Catenary::SetParameter(const Standard_Real theParameter)
{
    myParameter = theParameter;
}

// ============================================================================
/*!
 *  \brief SetPosition()
*/
// ============================================================================
void gp_Catenary::SetPosition(const gp_Ax2 &thePosition)
{
    myPosition = thePosition;
}

// ============================================================================
/*!
 *  \brief Transform()
*/
// ============================================================================
void gp_Catenary::Transform(const gp_Trsf &theTransformation)
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
gp_Catenary gp_Catenary::Transformed(const gp_Trsf &theTransformation) const
{
    Standard_Real aParameter = myParameter;
    if(theTransformation.ScaleFactor())
        aParameter *= -1.;
    gp_Ax2 anAxis = myPosition.Transformed(theTransformation);
    return gp_Catenary(anAxis, aParameter);
}

// ============================================================================
/*!
 *  \brief Translate()
*/
// ============================================================================
void gp_Catenary::Translate(const gp_Vec &theVector)
{
    myPosition.Translate(theVector);
}

// ============================================================================
/*!
 *  \brief Translate()
*/
// ============================================================================
void gp_Catenary::Translate(const gp_Pnt &thePoint1,
                            const gp_Pnt &thePoint2)
{
    myPosition.Translate(thePoint1, thePoint2);
}

// ============================================================================
/*!
 *  \brief Translated()
*/
// ============================================================================
gp_Catenary gp_Catenary::Translated(const gp_Vec &theVector) const
{
    gp_Ax2 anAxis = myPosition.Translated(theVector);
    return gp_Catenary(anAxis, myParameter);
}

// ============================================================================
/*!
 *  \brief Translated()
*/
// ============================================================================
gp_Catenary gp_Catenary::Translated(const gp_Pnt &thePoint1,
                                    const gp_Pnt &thePoint2) const
{
    gp_Ax2 anAxis = myPosition.Translated(thePoint1, thePoint2);
    return gp_Catenary(anAxis, myParameter);
}

// ============================================================================
/*!
 *  \brief XAxis()
*/
// ============================================================================
gp_Ax1 gp_Catenary::XAxis() const
{
    return gp_Ax1(myPosition.Location(), myPosition.XDirection());
}

// ============================================================================
/*!
 *  \brief YAxis()
*/
// ============================================================================
gp_Ax1 gp_Catenary::YAxis() const
{
    return gp_Ax1(myPosition.Location(), myPosition.YDirection());
}
