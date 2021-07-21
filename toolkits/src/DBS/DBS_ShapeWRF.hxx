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


#ifndef __DBS_ShapeWRF_hxx__
#define __DBS_ShapeWRF_hxx__

// Qt
#include <QString>

// ============================================================================
/*!
 *  \brief DBS_ShapeWRF
*/
// ============================================================================
struct DBS_ShapeWRF
{
    QString Designation;
    double Weigth;
    double Mass;
    double Area;
    double Ix;
    double Sxt;
    double Sxb;
    double Rx;
    double Yt;
    double Iy;
    double Sy;
    double Ry;
    double J;
    double Cw;
    double D;
    double B1;
    double B2;
    double T;
    double W;
};

#endif  // __DBS_ShapeWRF_hxx__
