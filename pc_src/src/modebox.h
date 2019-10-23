/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* declaration of class to edit modes
**********************************************************************
* FileName:        modebox.h
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
#ifndef MODEBOX_H
#define MODEBOX_H

#include <QFrame>
#include "ui_modebox.h"

class ModeBox : public QFrame, public Ui::ModeBox
{
	Q_OBJECT

public:
	ModeBox( QWidget* parent = 0);

	QString generateSetting( );
	unsigned int doubleToUint( double value);

	bool isAutoRearm( ); // should we auto-rearm the machine?
	unsigned int getRearmTime( ); // how long before we rearm?

	bool isBuzzer( ); // Should we use the buzzer?
	unsigned int getBuzzerTime( ); // How long to buzz

	unsigned int getPeriods( );

	bool isPeriodTimer( );  // fAre periods timed
	unsigned int getPeriodTimeMin( ); // how long periods last min
	unsigned int getPeriodTimeSec( ); // how long periods last sec

	bool isScoreLimit( ); // are periods score limited?
	unsigned int getScoreLimit( ); // what is the per period limit
	bool isCumulative( ); // are score limits cumulative?

	bool isBreaks( );  // are there breaks between periods?
	bool isBreakTimed( ); // is the break timed?
	unsigned int getBreakTimeMin( ); // how long are breaks min
	unsigned int getBreakTimeSec( ); // how long are breaks sec
	bool isOtBreak( );  // is there a breaks between the final and ot periods

	bool isOtTimer( );  // is OT timed?
	unsigned int getOtTimeMin( ); // how long is the OT period min?
	unsigned int getOtTimeSec( ); // how long is the OT period sec?
	bool isOtScoreLimit( ); // is OT period score limited?
	unsigned int getOtScoreLimit( ); // score limit for OT
	bool isAutoPriority( );    // determine priority automatiically?

};

#endif
