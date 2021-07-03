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


#ifndef __CRSA_FindEmptyLength_hxx__
#define __CRSA_FindEmptyLength_hxx__

// OpenCascade
#include <TColStd_SequenceOfReal.hxx>

// Spartacus
#include <CRSA_Command.hxx>
#include <CRSA_Error.hxx>
#include <CRSA_LoadCase.hxx>
#include <CRSA_SequenceOfLoadCase.hxx>
#include <CRSA_SpanGeometry.hxx>
#include <XSM_Model.hxx>

// ============================================================================
/*!
    \brief CRSA_FindEmptyLength
*/
// ============================================================================
class Standard_EXPORT CRSA_FindEmptyLength : public CRSA_Command
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    CRSA_FindEmptyLength(const CRSA_SpanGeometry& theSpanGeometry,
                         Handle(XSM_Model) theSectionModel);
    // destructors
    ~CRSA_FindEmptyLength();

public:

    void                    AddSaggingHistory(const Standard_Real theTime,
                                              const CRSA_LoadCase& theLoadCase,
                                              const Standard_Real theMaximumHTension);
    Standard_Real           EmptyLength();
    CRSA_Error              Error() const;
    void                    SetNbIterations(const Standard_Integer theNbIterations);
    void                    SetPrecision(const Standard_Real thePrecision);
    Standard_Boolean        Solve();

private:

    // Inputs
    Handle(XSM_Model)                   mySectionModel;
    CRSA_SequenceOfLoadCase             mySequenceOfLoadCases;
    TColStd_SequenceOfReal              mySequenceOfMaxHTensions;
    TColStd_SequenceOfReal              mySequenceOfTimes;
    CRSA_SpanGeometry                   mySpanGeometry;

    // Paramters
    Standard_Real                       myNbIterations;
    Standard_Real                       myPrecision;

    // Outputs
    CRSA_Error                          myError;
    Standard_Real                       myEmptyLength;

};

#endif  // __CRSA_FindEmptyLength_hxx__
