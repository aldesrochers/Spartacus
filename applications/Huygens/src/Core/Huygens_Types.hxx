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

#ifndef __Huygens_Types_hxx__
#define __Huygens_Types_hxx__


// ============================================================================
/*!
 *  \brief Huygens_Types
*/
// ============================================================================
namespace Huygens {

enum DataObject {
    DO_Unknown,
    DO_DocumentProperties,
};

// materials
enum Material {
    UnknownMaterial = 0,
    ElasticMaterial = 1
};

// cable sections
enum Cable {
    UnknownCable = 0
};

// study
enum Study
{
    UnknownStudy = 0,
    RulingSpanStudy = 1
};

}

#endif  // __Huygens_Types_hxx__
