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


#ifndef __Caelus_RulingSpanBuilder_hxx__
#define __Caelus_RulingSpanBuilder_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>

// Caelus
#include <Caelus_SequenceOfSpan.hxx>


// ============================================================================
/*!
    \brief Caelus_RulingSpanBuilder
*/
// ============================================================================
class Caelus_RulingSpanBuilder
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    Caelus_RulingSpanBuilder();
    Caelus_RulingSpanBuilder(const Caelus_SequenceOfSpan& theSequenceOfSpans);
    // destructors
    ~Caelus_RulingSpanBuilder();

public:

    void                AddSpan(const Standard_Real theLength);
    void                AddSpan(const Standard_Real theLength,
                                const Standard_Real theSlope);
    void                AddSpan(const Caelus_Span& theSpan);

    Standard_Integer    NbSpans() const;

    Caelus_Span         RulingSpan() const;

private:

    Caelus_SequenceOfSpan       SequenceOfSpans() const;

private:

    Caelus_SequenceOfSpan       mySequenceOfSpans;

};

#endif  // __Caelus_RulingSpanBuilder_hxx__
