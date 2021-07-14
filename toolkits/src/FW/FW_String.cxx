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
#include <FW_String.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
FW_String::FW_String()
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
FW_String::FW_String(const char* theString)
    : myValue(theString)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
FW_String::FW_String(const QString& theString)
    : myValue(theString)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
FW_String::~FW_String()
{

}

// ============================================================================
/*!
 *  \brief ToAsciiString()
*/
// ============================================================================
TCollection_AsciiString FW_String::ToAsciiString() const
{
    return TCollection_AsciiString(myValue.toStdString().c_str());
}

// ============================================================================
/*!
 *  \brief ToCString()
*/
// ============================================================================
Standard_CString FW_String::ToCString() const
{
    Standard_CString aString;
    aString = myValue.toStdString().c_str();
    return aString;
}

// ============================================================================
/*!
 *  \brief ToExtendedString()
*/
// ============================================================================
TCollection_ExtendedString FW_String::ToExtendedString() const
{
    return TCollection_ExtendedString(myValue.toStdString().c_str());
}

// ============================================================================
/*!
 *  \brief ToQString()
*/
// ============================================================================
QString FW_String::ToQString() const
{
    return myValue;
}
