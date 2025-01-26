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
#include <MeshModel_Curve.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
MeshModel_Curve::MeshModel_Curve()    
{
    
}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
MeshModel_Curve::~MeshModel_Curve()    
{
    
}

// ============================================================================
/*!
    \brief AddPoint()
*/
// ============================================================================
void MeshModel_Curve::AddPoint(const gp_Pnt& thePoint, 
                               const Standard_Real theParameter)
{
    myPoints.Append(thePoint);
    myParameters.Append(theParameter);
}

// ============================================================================
/*!
    \brief NbPoints()
*/
// ============================================================================
Standard_Integer MeshModel_Curve::NbPoints() const
{
    return myPoints.Size();
}

// ============================================================================
/*!
    \brief Parameter()
*/
// ============================================================================
Standard_Real MeshModel_Curve::Parameter(const Standard_Integer theIndex) const
{
    return myParameters.Value(theIndex);
}

// ============================================================================
/*!
    \brief Point()
*/
// ============================================================================
const gp_Pnt& MeshModel_Curve::Point(const Standard_Integer theIndex) const
{
    return myPoints.Value(theIndex);
}

// ============================================================================
/*!
    \brief RemovePoint()
*/
// ============================================================================
void MeshModel_Curve::RemovePoint(const Standard_Integer theIndex)
{
    myPoints.Remove(theIndex);
    myParameters.Remove(theIndex);
}

// ============================================================================
/*!
    \brief SetPoint()
*/
// ============================================================================
void MeshModel_Curve::SetPoint(const Standard_Integer theIndex, 
                                const gp_Pnt& thePoint,
                                const Standard_Real theParameter)
{
    myPoints.SetValue(theIndex, thePoint);
    myParameters.SetValue(theIndex, theParameter);
}



// ****************************************************************************
// Handles
// ****************************************************************************
IMPLEMENT_STANDARD_HANDLE(MeshModel_Curve, Standard_Transient)
IMPLEMENT_STANDARD_RTTIEXT(MeshModel_Curve, Standard_Transient)