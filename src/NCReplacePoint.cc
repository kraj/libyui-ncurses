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

   File:       NCReplacePoint.cc

   Author:     Michael Andres <ma@suse.de>

/-*/

#define  YUILogComponent "ncurses"
#include <yui/YUILog.h>
#include "NCurses.h"
#include "NCReplacePoint.h"


NCReplacePoint::NCReplacePoint( YWidget * parent )
	: YReplacePoint( parent )
	, NCWidget( parent )
{
    yuiDebug() << std::endl;
    wstate = NC::WSdumb;
}


NCReplacePoint::~NCReplacePoint()
{
    yuiDebug() << std::endl;
}


void NCReplacePoint::setSize( int newwidth, int newheight )
{
    wRelocate( wpos( 0 ), wsze( newheight, newwidth ) );
    YReplacePoint::setSize( newwidth, newheight );
}


void NCReplacePoint::setEnabled( bool do_bv )
{
    NCWidget::setEnabled( do_bv );
    YReplacePoint::setEnabled( do_bv );
}
