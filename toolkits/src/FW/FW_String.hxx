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


#ifndef __FW_String_hxx__
#define __FW_String_hxx__

// Qt
#include <QString>

// OpenCascade
#include <Standard_CString.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>


// ============================================================================
/*!
 *  \brief FW_String
 *  Definition of a string type.
*/
// ============================================================================
class FW_String
{

public:
    // constructors
    FW_String();
    FW_String(const char* theString);
    FW_String(const QString& theString);
    // destructors
    ~FW_String();

public:

    TCollection_AsciiString     ToAsciiString() const;
    Standard_CString            ToCString() const;
    TCollection_ExtendedString  ToExtendedString() const;
    QString                     ToQString() const;


private:

    QString     myValue;

};

#endif  // __FW_String_hxx__
