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

   File:       NCPopup.h

   Author:     Michael Andres <ma@suse.de>

/-*/

#ifndef NCPopup_h
#define NCPopup_h

#include <iosfwd>

#include "NCDialog.h"


class NCPopup : public NCDialog
{

    NCPopup & operator=( const NCPopup & );
    NCPopup( const NCPopup & );

protected:

    NCursesEvent postevent;

    void popupDialog();
    void popdownDialog();

    virtual NCursesEvent wHandleInput( wint_t ch );

    NCPopup( const wpos at, const bool boxed = true );
    virtual ~NCPopup();

    virtual bool postAgain()
    {
	if ( postevent != NCursesEvent::cancel )
	    postevent.detail = 0;

	return false;
    }

public:

    int post( NCursesEvent * returnevent = 0 );

};


#endif // NCPopup_h


