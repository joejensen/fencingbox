/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Implementation of dialogue class to edit modes
**********************************************************************
* FileName:        modebox.cpp
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
#include "modebox.h"

ModeBox::ModeBox( QWidget* parent) : QFrame( parent)
{
	setupUi( this);
}

QString ModeBox::generateSetting( )
{
	return "";
}

unsigned int ModeBox::doubleToUint( double value)
{
	return (unsigned int)( value*10);
}

bool ModeBox::isAutoRearm( ) // should we auto-rearm the machine?
{
	return autoRearm->isChecked( );
}

unsigned int ModeBox::getRearmTime( ) // how long before we rearm?
{
	return doubleToUint( rearmTime->value( ));
}

bool ModeBox::isBuzzer( ) // Should we use the buzzer?
{
	return buzzer->isChecked( );
}

unsigned int ModeBox::getBuzzerTime( ) // How long to buzz
{
	return doubleToUint( buzzTime->value());
}

unsigned int ModeBox::getPeriods( )
{
	return (unsigned int)periods->value();
}

bool ModeBox::isPeriodTimer( )  // fAre periods timed
{
	return periodTimed->isChecked( );
}

unsigned int ModeBox::getPeriodTimeMin( ) // how long periods last
{
	return (unsigned int)( periodTime->time().minute());
}

unsigned int ModeBox::getPeriodTimeSec( ) // how long periods last
{
	return (unsigned int)( periodTime->time().second());
}

bool ModeBox::isScoreLimit( ) // are periods score limited?
{
	return periodScoreLimited->isChecked( );
}

unsigned int ModeBox::getScoreLimit( ) // what is the per period limit
{
	return (unsigned int)periodScoreLimit->value( );
}

bool ModeBox::isCumulative( ) // are score limits cumulative?
{
	return cumulative->isChecked( );
}

bool ModeBox::isBreaks( )  // are there breaks between periods?
{
	return breaks->isChecked( );
}

bool ModeBox::isBreakTimed( ) // is the break timed?
{
	return breakTimed->isChecked( );
}

unsigned int ModeBox::getBreakTimeMin( ) // how long are breaks
{
	return (unsigned int)( breakTime->time().minute());
}

unsigned int ModeBox::getBreakTimeSec( ) // how long are breaks
{
	return (unsigned int)( breakTime->time().second());
}

bool ModeBox::isOtBreak( )  // is there a breaks between the final and ot periods
{
	return otBreak->isChecked( );
}

bool ModeBox::isOtTimer( )  // is OT timed?
{
	return otTimed->isChecked( );
}

unsigned int ModeBox::getOtTimeMin( ) // how long is the OT period?
{
	return (unsigned int)( otTime->time().minute());
}

unsigned int ModeBox::getOtTimeSec( ) // how long is the OT period?
{
	return (unsigned int)( otTime->time().second());
}

bool ModeBox::isOtScoreLimit( ) // is OT period score limited?
{
	return otScoreLimited->isChecked( );
}

unsigned int ModeBox::getOtScoreLimit( ) // score limit for OT
{
	return doubleToUint( otScoreLimit->value());
}

bool ModeBox::isAutoPriority( )    // determine priority automatiically?
{
	return autoPriority->isChecked( );
}
