/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Implementation of epee timing editing screen
**********************************************************************
* FileName:        epeetimingbox.cpp
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
#include "epeetimingbox.h"

EpeeTimingBox::EpeeTimingBox( QWidget* parent) : QFrame( parent)
{
	setupUi( this);
}

QString EpeeTimingBox::generateSetting( )
{
	return "";
}

unsigned int EpeeTimingBox::doubleToUint( double value)
{
	return (unsigned int)( value*10);
}

unsigned int EpeeTimingBox::getDebounceTime( )
{
	return doubleToUint( debounceTime->value());
}

unsigned int EpeeTimingBox::getLockoutTime( )
{
	return doubleToUint( lockoutTime->value());
}

bool EpeeTimingBox::isSmoothing( )               // should we smooth touces
{
	return smoothing->isChecked( );
}

unsigned int EpeeTimingBox::getBreakLength( )    // max break length
{
	return doubleToUint( breakTime->value());
}

unsigned int EpeeTimingBox::getMaxBreaks( )      // max number of breaks
{
	return (unsigned int)maxBreaks->value();
}

unsigned int EpeeTimingBox::getBreakSpacing( )   // spacing required between breaks
{
	return doubleToUint( breakSpacing->value());
}

unsigned int EpeeTimingBox::getTimeExtension( )  // time to extend timer on break
{
	return doubleToUint( timeExtension->value());
}

bool EpeeTimingBox::isAutoIncrement( )  // should we automatically increment score?
{
	return autoIncrement->isChecked();
}
