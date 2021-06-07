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

#include <iostream>
using namespace std;

// Spartacus
#include <CRSA_SaggingAnalysis.hxx>
#include <FLib_Catenary.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
CRSA_SaggingAnalysis::CRSA_SaggingAnalysis()
    : myNbIterations(100),
      myPrecision(1E-8),
      myLastError(CRSA_AnalysisNotDone)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
CRSA_SaggingAnalysis::CRSA_SaggingAnalysis(Handle(CRSA_SpanGeometry) theSpanGeometry,
                                           Handle(XSM_Model) theSectionModel)
    : mySpanGeometry(theSpanGeometry),
      mySectionModel(theSectionModel),
      myNbIterations(100),
      myPrecision(1E-8),
      myLastError(CRSA_AnalysisNotDone)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
CRSA_SaggingAnalysis::~CRSA_SaggingAnalysis()
{

}

// ============================================================================
/*!
 *  \brief AddSaggingCondition()
*/
// ============================================================================
void CRSA_SaggingAnalysis::AddSaggingCondition(Handle(CRSA_SaggingCondition) theSaggingCondition)
{
    mySaggingConditions.Append(theSaggingCondition);
}

// ============================================================================
/*!
 *  \brief GetLastError()
*/
// ============================================================================
CRSA_Error CRSA_SaggingAnalysis::GetLastError()
{
    return myLastError;
}

// ============================================================================
/*!
 *  \brief GetSaggingCondition()
*/
// ============================================================================
Handle(CRSA_SaggingCondition) CRSA_SaggingAnalysis::GetSaggingCondition(const Standard_Integer theIndex)
{
    Handle(CRSA_SaggingCondition) theSaggingCondition;
    if(theIndex <= mySaggingConditions.Length())
        theSaggingCondition = Handle(CRSA_SaggingCondition)::DownCast(mySaggingConditions(theIndex));
    return theSaggingCondition;
}

// ============================================================================
/*!
 *  \brief GetSectionModel()
*/
// ============================================================================
Handle(XSM_Model) CRSA_SaggingAnalysis::GetSectionModel()
{
    return mySectionModel;
}

// ============================================================================
/*!
 *  \brief GetSpanGeometry()
*/
// ============================================================================
Handle(CRSA_SpanGeometry) CRSA_SaggingAnalysis::GetSpanGeometry()
{
    return mySpanGeometry;
}

// ============================================================================
/*!
 *  \brief NbSaggingConditions()
*/
// ============================================================================
Standard_Integer CRSA_SaggingAnalysis::NbSaggingConditions()
{
    return mySaggingConditions.Length();
}

// ============================================================================
/*!
 *  \brief SetSectionModel()
*/
// ============================================================================
void CRSA_SaggingAnalysis::SetSectionModel(Handle(XSM_Model) theSectionModel)
{
    mySectionModel = theSectionModel;
}

// ============================================================================
/*!
 *  \brief SetSpanGeometry()
*/
// ============================================================================
void CRSA_SaggingAnalysis::SetSpanGeometry(Handle(CRSA_SpanGeometry) theSpanGeometry)
{
    mySpanGeometry = theSpanGeometry;
}

// ============================================================================
/*!
 *  \brief Solve()
 *  Analysis solve function. This function loops over the sagging conditions,
 *  accumulated the cable history and compute the cable empty length.
*/
// ============================================================================
Standard_Boolean CRSA_SaggingAnalysis::Solve()
{
    // check for valid geometry
    if(mySpanGeometry.IsNull()) {
        myLastError = CRSA_UndefinedGeometry;
        return Standard_False;
    }

    // revert section model to its initial state.
    if(mySectionModel.IsNull())
        return CRSA_UndefinedSectionModel;
    mySectionModel->RevertToInitialState();

    // retrieve span geometry
    Standard_Real a = mySpanGeometry->Length();
    Standard_Real b = mySpanGeometry->Slope();

    TColStd_SequenceOfTransient::Iterator anIterator(mySaggingConditions);
    for(; anIterator.More(); anIterator.Next()) {

        // get tension/load from sagging condition
        Handle(CRSA_SaggingCondition) aSaggingCondition =
                Handle(CRSA_SaggingCondition)::DownCast(anIterator.Value());
        Standard_Real H = aSaggingCondition->GetHorizontalTension();
        Standard_Real w = aSaggingCondition->GetLoadCase()->GetTotalLoad();

        // compute cable length (external equilibrium)
        Standard_Real S = FLib_Catenary::S(H, w, a, b);
        Standard_Real TMe = FLib_Catenary::TM(H, w, a, b);

        // solve for the cable section deformation for which
        // the external mean cable tension equals the internal
        // section force using a classic newton/raphson algorithm
        Standard_Real Eps = 0.;
        mySectionModel->SetTrialStrain(Eps);
        Standard_Real TMi = mySectionModel->GetTrialForce();
        Standard_Real Value = TMe - TMi;
        Standard_Real Derivative = -mySectionModel->GetTrialStiffness();

        for(int i=0; i<myNbIterations; i++) {
            Eps = Eps - Value / Derivative;
            mySectionModel->SetTrialStrain(Eps);
            TMi = mySectionModel->GetTrialForce();
            Value = TMe - TMi;
            Derivative = -mySectionModel->GetTrialStiffness();
            if(Abs(Value) <= myPrecision) {
                mySectionModel->CommitState();
                break;
            }
        }
        if(Abs(Value) > myPrecision) {
            myLastError = CRSA_SolutionNotFound;
            return Standard_False;
        }

        // compute empty length
        Standard_Real S0 = S / (1. + Eps);
        if(S0 > myS0)
            myS0 = S0;
    }

    return Standard_True;
}
