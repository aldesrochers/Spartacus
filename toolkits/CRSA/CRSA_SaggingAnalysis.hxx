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


#ifndef __CRSA_SaggingAnalysis_hxx__
#define __CRSA_SaggingAnalysis_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <TColStd_SequenceOfTransient.hxx>

// Spartacus
#include <CRSA_Error.hxx>
#include <CRSA_LoadCase.hxx>
#include <CRSA_SaggingCondition.hxx>
#include <CRSA_SpanGeometry.hxx>
#include <XSM_Model.hxx>


// ============================================================================
/*!
    \brief CRSA_SaggingAnalysis
    Class implementation of a 'RulingSpan' single span geometry.
*/
// ============================================================================
class CRSA_SaggingAnalysis
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    CRSA_SaggingAnalysis();
    CRSA_SaggingAnalysis(Handle(CRSA_SpanGeometry) theSpanGeometry,
                         Handle(XSM_Model) theSectionModel);
    // destructors
    ~CRSA_SaggingAnalysis();

public:

    void                            AddSaggingCondition(Handle(CRSA_SaggingCondition) theSaggingCondition);
    CRSA_Error                      GetLastError();
    Handle(CRSA_SaggingCondition)   GetSaggingCondition(const Standard_Integer theIndex);
    Handle(XSM_Model)               GetSectionModel();
    Handle(CRSA_SpanGeometry)       GetSpanGeometry();
    Standard_Integer                NbSaggingConditions();
    void                            SetSectionModel(Handle(XSM_Model) theSectionModel);
    void                            SetSpanGeometry(Handle(CRSA_SpanGeometry) theSpanGeometry);
    Standard_Boolean                Solve();

private:

    // Inputs
    TColStd_SequenceOfTransient     mySaggingConditions;
    Handle(XSM_Model)               mySectionModel;
    Handle(CRSA_SpanGeometry)       mySpanGeometry;

    // Analysis
    CRSA_Error                      myLastError;
    Standard_Integer                myNbIterations;
    Standard_Real                   myPrecision;
    Standard_Real                   myS0;
    Handle(XSM_Model)               myFinalSectionModel;
    Handle(XSM_Model)               myInitialSectionModel;

};

#endif  // __CRSA_SaggingAnalysis_hxx__
