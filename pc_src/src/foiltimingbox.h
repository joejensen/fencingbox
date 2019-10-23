/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Declaration of foil timing edit screen
**********************************************************************
* FileName:        foiltimingbox.h
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
#ifndef FOILTIMINGBOX
#define FOILTIMINGBOX

#include <QFrame>
#include <QString>
#include "ui_foiltimingbox.h"

class FoilTimingBox : public QFrame, public Ui::FoilTimingBox
{
	Q_OBJECT

public:
	FoilTimingBox( QWidget* parent = 0);
	QByteArray generateSetting( );
	bool       setSetting( QByteArray settings);
	unsigned int doubleToUint( double value);
	double uintToDouble( unsigned int value);

	unsigned int getDebounce( );   // debounce time in 1/10 of ms
	unsigned int getLockout( );    // lockout time in 1/10 of ms
	bool isOtTimings( );      // are there different off target timings
	unsigned int getOtDebounce( ); // off target debounce in 1/10 ms
	unsigned int getOtLockout( );  // OT lockout in 1/10 ms
	bool isSmoothing( );      // should we smooth microbreaks
	bool isOnSmoothing( );    // smooth on target touches
	bool isOffSmoothing( );   // smooth off target touches
	unsigned int getBreakLen( ); // Maximum break length in 1/10ms
	unsigned int getMaxBreaks( );   // maximum num of breaks in 1/10ms
	unsigned int getBreakSpacing( ); // space needed between breaks
	unsigned int getTimeExtension( ); // should we extend the timer on a microbreak
	bool isAntiBlocking( ); // is anti blocking enabled
	bool isOffTargetDisabled( ); // are off targets disabled

	void setDebounce( unsigned int value);   // debounce time in 1/10 of ms
	void setLockout( unsigned int value);    // lockout time in 1/10 of ms
	void setOtTimings( bool value);      // are there different off target timings
	void setOtDebounce( unsigned int value); // off target debounce in 1/10 ms
	void setOtLockout( unsigned int value);  // OT lockout in 1/10 ms
	void setSmoothing( bool value);      // should we smooth microbreaks
	void setOnSmoothing( bool value);    // smooth on target touches
	void setOffSmoothing( bool value);   // smooth off target touches
	void setBreakLen( unsigned int value); // Maximum break length in 1/10ms
	void setMaxBreaks( unsigned int value);   // maximum num of breaks in 1/10ms
	void setBreakSpacing( unsigned int value); // space needed between breaks
	void setTimeExtension( unsigned int value); // should we extend the timer on a microbreak
	void setAntiBlocking( bool value); // is anti blocking enabled
	void setOffTargetDisabled( bool value); // are off targets disabled
};

#endif
