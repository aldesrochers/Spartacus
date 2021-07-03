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


#ifndef __Viewer3d_Action_hxx__
#define __Viewer3d_Action_hxx__


// ============================================================================
/*!
    \brief Viewer3d_Action
*/
// ============================================================================

// enumeration of viewer actions
enum Viewer3d_Action
{
    Viewer3d_MoveAction,
    Viewer3d_NoAction,
    Viewer3d_RotateAction,
    Viewer3d_PopupAction,
    Viewer3d_ZoomAction,
    Viewer3d_ZoomOnPointAction
};

// enumeration of viewer action flags
enum Viewer3d_ActionFlag
{
    Viewer3d_EndMoveAction,
    Viewer3d_EndRotateAction,
    Viewer3d_EndZoomOnPointAction,
    Viewer3d_ShowPopupMenu,
    Viewer3d_StartMoveAction,
    Viewer3d_StartRotateAction,
    Viewer3d_StartZoomOnPointAction

};

#endif  // __Viewer3d_Action_hxx__
