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

   File:       NCFrame.h

   Author:     Michael Andres <ma@suse.de>

/-*/

#ifndef NCFrame_h
#define NCFrame_h

#include <iosfwd>

#include <yui/YFrame.h>
#include "NCWidget.h"

class NCFrame;


class NCFrame : public YFrame, public NCWidget
{
private:

    friend std::ostream & operator<<( std::ostream & STREAM, const NCFrame & OBJ );

    NCFrame & operator=( const NCFrame & );
    NCFrame( const NCFrame & );


    NClabel label;

protected:

    bool gotBuddy();

    virtual const char * location() const { return "NCFrame"; }

    virtual void wRedraw();

public:

    NCFrame( YWidget * parent, const string & label );
    virtual ~NCFrame();

    virtual int preferredWidth();
    virtual int preferredHeight();

    virtual void setSize( int newWidth, int newHeight );

    virtual void setLabel( const string & nlabel );

    virtual void setEnabled( bool do_bv );
};


#endif // NCFrame_h
