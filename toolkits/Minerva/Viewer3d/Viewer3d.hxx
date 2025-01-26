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


#ifndef __Viewer3d_Viewer_hxx__
#define __Viewer3d_Viewer_hxx__


// OpenCascade
#include <Standard.hxx>
#include <V3d_Viewer.hxx>


// ============================================================================
/*!
 *  \brief Viewer3d
 *  Class implementation of utility functions for the package.
*/
// ============================================================================
class Viewer3d
{

public:

    static Standard_EXPORT Handle(V3d_Viewer)   CreateViewer(const Standard_Real theProjection = 1000.0,
                                                             const V3d_TypeOfOrientation theOrientation = V3d_XposYnegZpos,
                                                             const Standard_Boolean theComputedMode = Standard_True,
                                                             const Standard_Boolean theDefaultComputedMode = Standard_True);

};

#endif // __Viewer3d_Viewer_hxx__
