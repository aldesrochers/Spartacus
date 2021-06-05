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


// Caelus
#include <Caelus_RulingSpanBuilder.hxx>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_RulingSpanBuilder::Caelus_RulingSpanBuilder()
{

}

// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Caelus_RulingSpanBuilder::Caelus_RulingSpanBuilder(const Caelus_SequenceOfSpan& theSequenceOfSpans)
    : mySequenceOfSpans(theSequenceOfSpans)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Caelus_RulingSpanBuilder::~Caelus_RulingSpanBuilder()
{

}

// ============================================================================
/*!
    \brief AddSpan()
*/
// ============================================================================
void Caelus_RulingSpanBuilder::AddSpan(const Standard_Real theLength)
{
    Caelus_Span aSpan(theLength);
    mySequenceOfSpans.Append(aSpan);
}

// ============================================================================
/*!
    \brief AddSpan()
*/
// ============================================================================
void Caelus_RulingSpanBuilder::AddSpan(const Standard_Real theLength,
                                       const Standard_Real theSlope)
{
    Caelus_Span aSpan(theLength, theSlope);
    mySequenceOfSpans.Append(aSpan);
}

// ============================================================================
/*!
    \brief AddSpan()
*/
// ============================================================================
void Caelus_RulingSpanBuilder::AddSpan(const Caelus_Span &theSpan)
{
    mySequenceOfSpans.Append(theSpan);
}

// ============================================================================
/*!
    \brief NbSpans()
*/
// ============================================================================
Standard_Integer Caelus_RulingSpanBuilder::NbSpans() const
{
    return mySequenceOfSpans.Length();
}

// ============================================================================
/*!
    \brief RulingSpan()
    Compute ruling span as Sqrt( Sum(S^3/S))
*/
// ============================================================================
Caelus_Span Caelus_RulingSpanBuilder::RulingSpan() const
{
    Standard_Real S3;
    Standard_Real S;
    Caelus_SequenceOfSpan::Iterator anIterator(mySequenceOfSpans);
    for(;anIterator.More(); anIterator.Next()) {
        Caelus_Span aSpan = anIterator.Value();
        S3 += Pow(aSpan.Length(), 3);
        S += aSpan.Length();
    }
    Standard_Real RS = Sqrt(S3 / S);
    return Caelus_Span(RS);
}

// ============================================================================
/*!
    \brief SequenceOfSpans()
*/
// ============================================================================
Caelus_SequenceOfSpan Caelus_RulingSpanBuilder::SequenceOfSpans() const
{
    return mySequenceOfSpans;
}



