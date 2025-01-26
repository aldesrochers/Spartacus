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


#ifndef __MeshModel_DiscreteCurve_hxx__
#define __MeshModel_DiscreteCurve_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_Transient.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TColStd_SequenceOfReal.hxx>

// Handles
DEFINE_STANDARD_HANDLE(MeshModel_DiscreteCurve, Standard_Transient)

// ============================================================================
/*
    \brief MeshModel_DiscreteCurve
*/
// ============================================================================
class MeshModel_DiscreteCurve : public Standard_Transient
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Standard_EXPORT MeshModel_DiscreteCurve();
    // destructors
    Standard_EXPORT ~MeshModel_DiscreteCurve();

public:

    Standard_EXPORT void                AddPoint(const gp_Pnt& thePoint, 
                                                 const Standard_Real theParameter);
    Standard_EXPORT Standard_Integer    NbPoints() const;
    Standard_EXPORT Standard_Real       Parameter(const Standard_Integer theIndex) const;
    Standard_EXPORT const gp_Pnt&       Point(const Standard_Integer theIndex) const;
    Standard_EXPORT void                Point(const Standard_Integer theIndex, 
                                              gp_Pnt& thePoint,
                                              Standard_Real& theParameter) const;

private:

    TColStd_SequenceOfReal  myParameters;
    TColgp_SequenceOfPnt    myPoints;
    

public:

    DEFINE_STANDARD_RTTIEXT(MeshModel_DiscreteCurve, Standard_Transient)

};

#endif // __MeshModel_DiscreteCurve_hxx__
