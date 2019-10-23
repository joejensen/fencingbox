/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Declaration of epee timing editing screen
**********************************************************************
* FileName:        epeetimingbox.h
* Dependencies:    See INCLUDES section below
* OS:              Tested on Windows XP
* Compiler:        MinGW gcc 3.4.2
*
* Software License Agreement
* This file is part of the JBox firmware.
*
* The JBox PC Interface is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* JBox PC Interface is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with JBox PC Interface.  If not, see <http://www.gnu.org/licenses/>.
*
* Copyright (C) 2007 Joe Jensen (joe@joejensen.com)
* fencingbox.sourceforge.net
********************************************************************/
#ifndef EPEETIMINGBOX
#define EPEETIMINGBOX

#include <QFrame>
#include "ui_epeetimingbox.h"

class EpeeTimingBox : public QFrame, public Ui::EpeeTimingBox
{
	Q_OBJECT
public:
	EpeeTimingBox( QWidget* parent = 0);
	QString generateSetting( );
	unsigned int doubleToUint( double value);
	unsigned int getDebounceTime( );
	unsigned int getLockoutTime( );
	bool isSmoothing( );               // should we smooth touces
	unsigned int getBreakLength( );    // max break length
	unsigned int getMaxBreaks( );      // max number of breaks
	unsigned int getBreakSpacing( );   // spacing required between breaks
	unsigned int getTimeExtension( );  // time to extend timer on break
	bool isAutoIncrement( );  // should we automatically increment score?
};

#endif

