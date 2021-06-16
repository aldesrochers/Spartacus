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

// Spartacus
#include <CRSA_FindEmptyLength.hxx>
#include <FLib_Catenary.hxx>

// OpenCascade
#include <Precision.hxx>

#include <iostream>
using namespace std;

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
CRSA_FindEmptyLength::CRSA_FindEmptyLength(const CRSA_SpanGeometry& theSpanGeometry,
                                           Handle(XSM_Model) theSectionModel)
    : mySectionModel(theSectionModel),
      mySpanGeometry(theSpanGeometry),
      myNbIterations(100),
      myPrecision(1E-6),
      myError(CRSA_NoError)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
CRSA_FindEmptyLength::~CRSA_FindEmptyLength()
{

}

// ============================================================================
/*!
    \brief AddSaggingHistory()
*/
// ============================================================================
void CRSA_FindEmptyLength::AddSaggingHistory(const Standard_Real theTime,
                                             const CRSA_LoadCase &theLoadCase,
                                             const Standard_Real theMaximumHTension)
{
    mySequenceOfTimes.Append(theTime);
    mySequenceOfLoadCases.Append(theLoadCase);
    mySequenceOfMaxHTensions.Append(theMaximumHTension);
    // reset the 'Done' flag
    NotDone();
}

// ============================================================================
/*!
    \brief EmptyLength()
*/
// ============================================================================
Standard_Real CRSA_FindEmptyLength::EmptyLength()
{
    if(!IsDone())
        Solve();
    return myEmptyLength;
}

// ============================================================================
/*!
    \brief Error()
*/
// ============================================================================
CRSA_Error CRSA_FindEmptyLength::Error() const
{
    return myError;
}

// ============================================================================
/*!
    \brief SetNbIterations()
    Set the maximum number of iterations.
*/
// ============================================================================
void CRSA_FindEmptyLength::SetNbIterations(const Standard_Integer theNbIterations)
{
    myNbIterations = theNbIterations;
}

// ============================================================================
/*!
    \brief SetPrecision()
*/
// ============================================================================
void CRSA_FindEmptyLength::SetPrecision(const Standard_Real thePrecision)
{
    myPrecision = thePrecision;
}

// ============================================================================
/*!
    \brief Solve()
    Compute the cable empty length based on the provided sagging load history.
    Once completed, update the internal myEmptyLength variable.
*/
// ============================================================================
Standard_Boolean CRSA_FindEmptyLength::Solve()
{
    // check if analysis already done
    if(IsDone())
        return Standard_True;

    // reset the section model to its initial state
    if(mySectionModel.IsNull()) {
        myError = CRSA_InvalidSectionModel;
        return Standard_False;
    }
    mySectionModel->RevertToInitialState();

    // check for a valid span geometry
    Standard_Real a = mySpanGeometry.Length();
    Standard_Real b = mySpanGeometry.Slope();
    if(a <= 1./Precision::Infinite()) {
        myError = CRSA_InvalidSpanLength;
        return Standard_False;
    }

    // check for a valid sagging history
    if(mySequenceOfTimes.Length() <= 0) {
        myError = CRSA_NoSaggingHistory;
        return Standard_False;
    }

    // ***
    // loop over loading history. Update the cable section model based
    // on his
    // ***

    Standard_Real S0 = 0.;
    Standard_Real PreviousTime = 0.;

    for(int i=1; i<=mySequenceOfTimes.Length(); i++) {

        // retrieve history parameters
        CRSA_LoadCase aLoadCase = mySequenceOfLoadCases.Value(i);
        Standard_Real Time = mySequenceOfTimes.Value(i);
        Standard_Real H = mySequenceOfMaxHTensions.Value(i);
        Standard_Real wD = aLoadCase.DeadLoad();
        Standard_Real wI = aLoadCase.IceLoad();
        Standard_Real wW = aLoadCase.WindLoad();
        Standard_Real Temp = aLoadCase.Temperature();

        // check for valid time // always go forward in history
        if(Time < PreviousTime) {
            myError = CRSA_SaggingHistoryError;
            return Standard_False;
        }

        // compute cable "total" load
        Standard_Real w = Sqrt(Pow(wD+wI,2.) + Pow(wW, 2.));

        // compute cable length (S) and 'external' mean tension (TMe)
        Standard_Real S = FLib_Catenary::S(H, w, a, b);
        Standard_Real TMe = FLib_Catenary::TM(H, w, a, b);

        // compute cable deformation (Eps)
        // use a standard newton/raphson algorithm
        Standard_Real Eps = 0.;
        mySectionModel->SetTrialTime(Time);
        mySectionModel->SetTrialTemperature(Temp);
        mySectionModel->SetTrialStrain(Eps);
        Standard_Real Function = TMe - mySectionModel->GetTrialForce();
        Standard_Real Derivative = mySectionModel->GetTrialStiffness();
        Standard_Integer N = 0;
        while(Abs(Function) > myPrecision) {
            Eps = Eps - Function / Derivative;
            mySectionModel->SetTrialStrain(Eps);
            Function = mySectionModel->GetTrialForce();
            Derivative = mySectionModel->GetTrialStiffness();
            if(N >= myNbIterations) {
                myError = CRSA_SolutionNotFound;
                return Standard_False;
            }
            N += 1;
        }

        // if S0i > S0, set as initial empty length value
        Standard_Real S0i = S / (1. + Eps);
        if(S0i > S0)
            S0 = S0i;

        // setup previous time
        PreviousTime = Time;

        // commit section internal state
        mySectionModel->CommitState();
    }

    // set done flag, set internal result
    myEmptyLength = S0;
    Done();
    return Standard_True;
}
