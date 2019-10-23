/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Implementation of class for editing saber timings
**********************************************************************
* FileName:        sabertimingbox.cpp
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
#include "sabertimingbox.h"

SaberTimingBox::SaberTimingBox( QWidget* parent) : QFrame( parent)
{
	setupUi( this);
}

QByteArray SaberTimingBox::generateSetting( )
{
	QByteArray setting;
	setting.resize( 10);

	setting[0] = ((getDebounce() >> 8) & 0xff);
	setting[1] = (getDebounce() & 0xff);
	setting[2] = ((getLockout() >> 8) & 0xff);
	setting[3] = (getLockout() & 0xff);
	setting[4] = (isWhipover());
	setting[5] = ((getRegisterPeriod() >> 8) & 0xff);
	setting[6] = (getRegisterPeriod() & 0xff);
	setting[7] = ((getIgnorePeriod() >> 8) & 0xff);
	setting[8] = (getIgnorePeriod() & 0xff);
	setting[9] = getInterrupts() & 0xff;

	return setting;
}

bool SaberTimingBox::setSetting( QByteArray settings)
{
	setDebounce( ((unsigned int)settings[0] << 8) | (settings[1] & 0xff));
	setLockout( ((int)settings[2] << 8) | (settings[3] & 0xff));
	setWhipover( (bool)settings[4]);
	setRegisterPeriod( ((int)settings[5] << 8)| (settings[6] & 0xff));
	setIgnorePeriod( ((int)settings[7] << 8) | (settings[8] & 0xff));
	setInterrupts( ((unsigned int) settings[9]));

	return true;
}

unsigned int SaberTimingBox::doubleToUint( double value)
{
	return (unsigned int)( value*10);
}

double SaberTimingBox::uintToDouble( unsigned int value)
{
	return ((double)value)/10;
}

unsigned int SaberTimingBox::getDebounce( )
{
	return doubleToUint( debounceTime->value());
}

unsigned int SaberTimingBox::getLockout( )
{
	return doubleToUint( lockoutTime->value());
}

bool SaberTimingBox::isWhipover( )  // Do we do whipover prevention?
{
	return whipover->isChecked( );
}

unsigned int SaberTimingBox::getRegisterPeriod( )  // get how longer to allow touces
{
	return doubleToUint( registerPeriod->value());
}

unsigned int SaberTimingBox::getIgnorePeriod( ) // How long to ignore touches
{
	return doubleToUint( ignorePeriod->value());
}

unsigned int SaberTimingBox::getInterrupts( ) // how many interrupts till ignore ends
{
	return (unsigned int)interrupts->value();
}

void SaberTimingBox::setDebounce( unsigned int value)
{
	debounceTime->setValue( uintToDouble( value));
}

void SaberTimingBox::setLockout( unsigned int value)
{
	lockoutTime->setValue( uintToDouble( value));
}

void SaberTimingBox::setWhipover( bool value)  // Do we do whipover prevention?
{
	whipover->setChecked( value);
}

void SaberTimingBox::setRegisterPeriod( unsigned int value)  // get how longer to allow touces
{
	registerPeriod->setValue( uintToDouble( value));
}

void SaberTimingBox::setIgnorePeriod( unsigned int value) // How long to ignore touches
{
	ignorePeriod->setValue( uintToDouble( value));
}

void SaberTimingBox::setInterrupts( unsigned int value)
{
	interrupts->setValue( value);
}

