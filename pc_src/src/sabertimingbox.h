/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Declaration of class to edit saber timings
**********************************************************************
* FileName:        sabertimingbox.h
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
#ifndef SABERTIMINGBOX
#define SABERTIMINGBOX

#include <QFrame>
#include "ui_sabertimingbox.h"

class SaberTimingBox : public QFrame, public Ui::SaberTimingBox
{
	Q_OBJECT

public:
	SaberTimingBox( QWidget* parent = 0);
	QByteArray generateSetting( );
	unsigned int doubleToUint( double value);
	double uintToDouble( unsigned int value);
	bool       setSetting( QByteArray settings);

	unsigned int getDebounce( );
	unsigned int getLockout( );
	bool isWhipover( );  // Do we do whipover prevention?
	unsigned int getRegisterPeriod( );  // get how longer to allow touces
	unsigned int getIgnorePeriod( ); // How long to ignore touches
	unsigned int getInterrupts( ); // how many interrupts till ignore ends

	void setDebounce( unsigned int value);
	void setLockout( unsigned int value);
	void setWhipover( bool value);  // Do we do whipover prevention?
	void setRegisterPeriod( unsigned int value);  // get how longer to allow touces
	void setIgnorePeriod( unsigned int value); // How long to ignore touches
	void setInterrupts( unsigned int value); // how many interrupts till ignore ends
};

#endif

