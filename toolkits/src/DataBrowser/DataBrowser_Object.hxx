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


#ifndef __DataBrowser_Object_hxx__
#define __DataBrowser_Object_hxx__

// Qt
#include <QString>

// Spartacus
#include <FW_Export.hxx>


// ============================================================================
/*!
 *  \brief DataBrowser_Object
 *  Class implementation of a generic object for the data browser. The object
 *  does not hold the data internally but holds the necessary references to
 *  the data model.
*/
// ============================================================================
class FW_EXPORT DataBrowser_Object
{

public:
    // constructors
    DataBrowser_Object();
    DataBrowser_Object(const QString& theLabel);
    DataBrowser_Object(const QString& theLabel,
                       const QString& theName);
    // destructors
    ~DataBrowser_Object();

public:

    QString     Label() const;
    QString     Name() const;

    void        SetLabel(const QString& theLabel);
    void        SetName(const QString& theName);

private:

    QString     myLabel;
    QString     myName;


};

#endif  // __DataBrowser_Object_hxx__
