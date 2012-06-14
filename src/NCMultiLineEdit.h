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

   File:       NCMultiLineEdit.h

   Author:     Michael Andres <ma@suse.de>

/-*/

#ifndef NCMultiLineEdit_h
#define NCMultiLineEdit_h

#include <iosfwd>

#include <yui/YMultiLineEdit.h>
#include "NCPadWidget.h"
#include "NCTextPad.h"


class NCMultiLineEdit : public YMultiLineEdit, public NCPadWidget
{
private:
    friend std::ostream & operator<<( std::ostream & STREAM, const NCMultiLineEdit & OBJ );

    NCMultiLineEdit & operator=( const NCMultiLineEdit & );
    NCMultiLineEdit( const NCMultiLineEdit & );

    NCstring ctext;

protected:

    /**
     * Overload myPad to narrow the type
     */
    virtual NCTextPad * myPad() const
    { return dynamic_cast<NCTextPad*>( NCPadWidget::myPad() ); }

protected:

    virtual const char * location() const { return "NCMultiLineEdit"; }

    virtual void wRedraw();

    virtual NCPad * CreatePad();
    virtual void    DrawPad();

public:

    NCMultiLineEdit( YWidget * parent, const string & label );

    virtual ~NCMultiLineEdit();

    virtual int preferredWidth();
    virtual int preferredHeight();

    virtual void setSize( int newWidth, int newHeight );

    virtual void setLabel( const string & nlabel );
    virtual void setValue( const string & ntext );

    virtual string value();

    virtual NCursesEvent wHandleInput( wint_t key );

    virtual void setEnabled( bool do_bv );

    virtual bool setKeyboardFocus()
    {
	if ( !grabFocus() )
	    return YWidget::setKeyboardFocus();

	return true;
    }

    // sets the maximum number of characters of the NCTextPad
    void setInputMaxLength( int numberOfChars );

};


#endif // NCMultiLineEdit_h
