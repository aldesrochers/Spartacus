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


#ifndef __Tetgen_Tetrahedralize_hxx__
#define __Tetgen_Tetrahedralize_hxx__

// OpenCASCADE
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>

// Spartacus
#include <Tetgen_Error.hxx>
#include <Tetgen_Model.hxx>
#include <Tetgen_Parameters.hxx>



// ============================================================================
/*
    \brief Tetgen_Tetrahedralize
*/
// ============================================================================
class Tetgen_Tetrahedralize 
{

public:
    // constructors
    Standard_EXPORT Tetgen_Tetrahedralize();
    Standard_EXPORT Tetgen_Tetrahedralize(const Handle(Tetgen_Model)& theInputModel,
                                         const Tetgen_Parameters& theParameters = Tetgen_Parameters());
    // destructors
    Standard_EXPORT ~Tetgen_Tetrahedralize();

public:

    Standard_EXPORT const Tetgen_Error&             Error() const;
    Standard_EXPORT const Handle(Tetgen_Model)&     InputModel() const;
    Standard_EXPORT Standard_Boolean                IsDone() const;
    Standard_EXPORT const Handle(Tetgen_Model)&     OutputModel() const;
    Standard_EXPORT const Tetgen_Parameters&        Parameters() const;
    Standard_EXPORT void                            Perform();
    Standard_EXPORT void                            SetInputModel(const Handle(Tetgen_Model)& theModel); 
    Standard_EXPORT void                            SetParameters(const Tetgen_Parameters& theParameters);

private:

    Tetgen_Error          myError;
    Handle(Tetgen_Model)  myInputModel;
    Standard_Boolean      myIsDone;
    Handle(Tetgen_Model)  myOutputModel;
    Tetgen_Parameters     myParameters;

};


#endif // __Tetgen_Tetrahedralize_hxx__
