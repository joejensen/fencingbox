/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Implementation of foil timing editor screen
**********************************************************************
* FileName:        foiltimingbox.cpp
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
#include <QtGui>
#include "foiltimingbox.h"

FoilTimingBox::FoilTimingBox( QWidget* parent) : QFrame( parent)
{
	setupUi( this);
}

/**
**  Generates a string representing the current settings
**/
QByteArray FoilTimingBox::generateSetting( )
{
	// Format
	// |debounce1|debounce2|lockout1|lockout2|isOt|otdebounce1|
	// otdebounce2|otlockout1|otdebounce2|smoothing|onsmooth|offsmooth|
	// breaklen1|breaklen2|maxbreaks|breakspace1|breakspace2|timeext1|
	// timeext2|antiBlocking|offtargetdisabled

	QByteArray setting;
	setting.resize( 21);

	setting[0] = ( (getDebounce() >> 8) & 0xff);
	setting[1] = ( getDebounce() & 0xff);
	setting[2] = ( getLockout() >> 8 & 0xff);
	setting[3] = ( getLockout() & 0xff);
	setting[4] = ( isOtTimings( ));
	setting[5] = ( getOtDebounce() >> 8 & 0xff);
	setting[6] = ( getOtDebounce() & 0xff);
	setting[7] = ( getOtLockout() >> 8 & 0xff);
	setting[8] = ( getOtLockout() & 0xff);
	setting[9] = ( isSmoothing());
	setting[10] = ( isOnSmoothing());
	setting[11] = ( isOffSmoothing());
	setting[12] = ( getBreakLen() >> 8 & 0xff);
	setting[13] = ( getBreakLen() & 0xff);
	setting[14] = ( getMaxBreaks() & 0xff);
	setting[15] = ( getBreakSpacing() >> 8 & 0xff);
	setting[16] = ( getBreakSpacing() & 0xff);
	setting[17] = ( getTimeExtension() >> 8 & 0xff);
	setting[18] = ( getTimeExtension() & 0xff);
	setting[19] = ( isAntiBlocking());
	setting[20] = ( isOffTargetDisabled());

	return setting;
}

/**
**  apply settings to the display
**/
bool FoilTimingBox::setSetting( QByteArray settings)
{
	if( settings.length() != 21)
		return false;

	setDebounce( (((unsigned int)settings.at(0) << 8) | (unsigned int)settings.at(1) & 0xff));
	setLockout( ((int)(settings[2] << 8)) | (settings[3] & 0xff)); 
	setOtTimings( settings[4]); 
	setOtDebounce( ((int)(settings[5] << 8)) | (settings[6] & 0xff)); 
	setOtLockout( ((int)(settings[7] << 8)) | (settings[8] & 0xff)); 
	setSmoothing( settings[9]);
	setOnSmoothing( settings[10]); 
	setOffSmoothing( settings[11]); 
	setBreakLen( ((int)(settings[12] << 8)) | (settings[13] & 0xff)); 
	setMaxBreaks( settings[14]);
	setBreakSpacing( ((int)(settings[15] << 8)) | (settings[16]& 0xff)); 
	setTimeExtension( ((int)(settings[17] << 8)) | (settings[18]& 0xff)); 
	setAntiBlocking( settings[19]); 
	setOffTargetDisabled( settings[20]);
	return true;
}

double FoilTimingBox::uintToDouble( unsigned int value)
{
	return ((double)value)/10;
}

/**
**  How do we want to convert from Double Spins to uints
**/
unsigned int FoilTimingBox::doubleToUint( double value)
{
	return (unsigned int)( value*10);
}

unsigned int FoilTimingBox::getDebounce( )   // debounce time in 1/10 of ms
{
	return doubleToUint( debounceTime->value());
}

unsigned int FoilTimingBox::getLockout( )    // lockout time in 1/10 of ms
{
	return doubleToUint( lockoutTime->value());
}

bool FoilTimingBox::isOtTimings( )      // are there different off target timings
{
	return offTarget->isChecked( );
}

unsigned int FoilTimingBox::getOtDebounce( ) // off target debounce in 1/10 ms
{
	return doubleToUint( offDebounce->value());
}

unsigned int FoilTimingBox::getOtLockout( )  // OT lockout in 1/10 ms
{
	return doubleToUint( offLockout->value());
}
	
bool FoilTimingBox::isSmoothing( )      // should we smooth microbreaks
{
	return smoothing->isChecked( );
}

bool FoilTimingBox::isOnSmoothing( )    // smooth on target touches
{
	return onSmoothing->isChecked( );
}

bool FoilTimingBox::isOffSmoothing( )   // smooth off target touches
{
	return offSmoothing->isChecked( );
}

unsigned int FoilTimingBox::getBreakLen( ) // Maximum break length in 1/10ms
{
	return doubleToUint( breakTime->value());
}

unsigned int FoilTimingBox::getMaxBreaks( )   // maximum num of breaks in 1/10ms
{
	return (unsigned int)( maxBreaks->value());
}

unsigned int FoilTimingBox::getBreakSpacing( ) // space needed between breaks
{
	return doubleToUint( breakSpacing->value());
}

unsigned int FoilTimingBox::getTimeExtension( ) // should we extend the timer on a microbreak
{
	return doubleToUint( timeExtension->value());
}

bool FoilTimingBox::isAntiBlocking( ) // is anti blocking enabled
{
	return antiBlocking->isChecked( );
}

bool FoilTimingBox::isOffTargetDisabled( ) // are off targets disabled
{
	return disableOffTarget->isChecked( );
}

void FoilTimingBox::setDebounce( unsigned int value)   // debounce time in 1/10 of ms
{
	debounceTime->setValue( uintToDouble( value));
}

void FoilTimingBox::setLockout( unsigned int value)    // lockout time in 1/10 of ms
{
	lockoutTime->setValue( uintToDouble( value));
}

void FoilTimingBox::setOtTimings( bool value)     // are there different off target timings
{
	offTarget->setChecked( value);
}

void FoilTimingBox::setOtDebounce( unsigned int value) // off target debounce in 1/10 ms
{
	offDebounce->setValue( uintToDouble( value));
}

void FoilTimingBox::setOtLockout( unsigned int value)  // OT lockout in 1/10 ms
{
	offLockout->setValue( uintToDouble( value));
}

void FoilTimingBox::setSmoothing( bool value)      // should we smooth microbreaks
{
	smoothing->setChecked( value);
}

void FoilTimingBox::setOnSmoothing( bool value)    // smooth on target touches
{
	onSmoothing->setChecked( value);
}

void FoilTimingBox::setOffSmoothing( bool value)   // smooth off target touches
{
	offSmoothing->setChecked( value);
}

void FoilTimingBox::setBreakLen( unsigned int value) // Maximum break length in 1/10ms
{
	breakTime->setValue( uintToDouble( value));
}

void FoilTimingBox::setMaxBreaks( unsigned int value)   // maximum num of breaks in 1/10ms
{
	maxBreaks->setValue( value);
}

void FoilTimingBox::setBreakSpacing( unsigned int value) // space needed between breaks
{
	breakSpacing->setValue( uintToDouble( value));
}

void FoilTimingBox::setTimeExtension( unsigned int value) // should we extend the timer on a microbreak
{
	timeExtension->setValue( uintToDouble( value));
}

void FoilTimingBox::setAntiBlocking( bool value) // is anti blocking enabled
{
	antiBlocking->setChecked( value);
}

void FoilTimingBox::setOffTargetDisabled( bool value) // are off targets disabled
{
	disableOffTarget->setChecked( value);
}

