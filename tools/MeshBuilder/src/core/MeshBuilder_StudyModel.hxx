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

#ifndef __MeshBuilder_StudyModel_hxx__
#define __MeshBuilder_StudyModel_hxx__

// OpenCASCADE
#include <Standard.hxx>

// Qt
#include <QStandardItemModel>


// ============================================================================
/*!
 *  \brief MeshBuilder_StudyModel
 */
// ============================================================================
class Standard_EXPORT MeshBuilder_StudyModel : public QStandardItemModel
{

    Q_OBJECT

public:
    // constructors
    MeshBuilder_StudyModel(QObject *theParent = 0);
    // destructors
    ~MeshBuilder_StudyModel();

    
};

#endif  // __MeshBuilder_StudyModel_hxx__
