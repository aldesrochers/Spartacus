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


#ifndef __DBS_ShapeL_hxx__
#define __DBS_ShapeL_hxx__

// Qt
#include <QString>

// ============================================================================
/*!
 *  \brief DBS_ShapeL
 *  Structure definition of a L-Shape.
*/
// ============================================================================
struct DBS_ShapeL
{
    QString Designation;
    double DeadLoad;
    double Mass;
    double Area;
    double B;
    double D;
    double T;
    double Ix;
    double Sx;
    double Rx;
    double Y;
    double Iy;
    double Sy;
    double Ry;
    double X;
    double J;
    double Cw;
    double Rxx;
    double Y0;
    double Ryy;
    double X0;
    double R0;
    double Omega;
    double Alpha;
};

#endif  // __DBS_ShapeL_hxx__
