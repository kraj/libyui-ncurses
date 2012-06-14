/*
  |****************************************************************************
  |
  | Copyright (c) 2000 - 2012 Novell, Inc.
  | All Rights Reserved.
  |
  | This program is free software; you can redistribute it and/or
  | modify it under the terms of version 2 of the GNU General Public License as
  | published by the Free Software Foundation.
  |
  | This program is distributed in the hope that it will be useful,
  | but WITHOUT ANY WARRANTY; without even the implied warranty of
  | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the
  | GNU General Public License for more details.
  |
  | You should have received a copy of the GNU General Public License
  | along with this program; if not, contact Novell, Inc.
  |
  | To contact Novell about this file by physical or electronic mail,
  | you may find current contact information at www.novell.com
  |
  |****************************************************************************
*/


/*-/

   File:       NCButtonBox.h

   Author:     Michael Andres <ma@suse.de>

/-*/

#ifndef NCButtonBox_h
#define NCButtonBox_h

#include <iosfwd>

#include <yui/YButtonBox.h>
#include "NCWidget.h"

class NCButtonBox;


class NCButtonBox : public YButtonBox, public NCWidget
{

public:

    NCButtonBox( YWidget * parent );
    virtual ~NCButtonBox();

    virtual void moveChild( YWidget * child, int newX, int newY );
    virtual void setSize( int newWidth, int newHeight );
    virtual void setEnabled( bool enabled );

private:

    friend std::ostream & operator<<( std::ostream & stream, const NCButtonBox & widget );

    NCButtonBox & operator=( const NCButtonBox & );
    NCButtonBox( const NCButtonBox & );

};


#endif // NCButtonBox_h
