/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* Common declarations need in many firmware modules
**********************************************************************
* FileName:        common.h
* Dependencies:    See INCLUDES section below
* Processor:       PIC16F648A
* Compiler:        BoostC 6.84
*
* Software License Agreement
* This file is part of the JBox firmware.
*
* The JBox firmware is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* JBox firmware  is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with Jbox Firmware.  If not, see <http://www.gnu.org/licenses/>.
*
* Copyright (C) 2007 Joe Jensen (joe@joejensen.com)
* fencingbox.sourceforge.net
********************************************************************/
#ifndef COMMON_H_
#define COMMON_H_

// Fencer variables
#define RED 0
#define GREEN 1

// weapons
#define FOIL_OLD       0
#define FOIL_T2005     1
#define FOIL_CUSTOM_A  2
#define FOIL_CUSTOM_B  3
#define EPEE_OLD       4
#define EPEE_CUSTOM_A  5
#define EPEE_CUSTOM_B  6
#define EPEE_CUSTOM_C  7
#define SABER_OLD      8
#define SABER_T2005    9
#define SABER_CUSTOM_A 10
#define SABER_CUSTOM_B 11
#define MAX_WEAPON 11

// periods
#define PERIOD_NONE        0
#define PERIOD_FIRST       1
#define PERIOD_SECOND      2
#define PERIOD_THIRD       3
#define PERIOD_EXTRA       4
#define MAX_PERIOD         4

// modes
#define MODE_STANDARD_DE   1
#define MODE_STANDARD_POOL 2
#define MODE_REARM_DE      3
#define MODE_REARM_POOL    4
#define MODE_PRACTICE      5
#define MODE_CUSTOM        6
#define MAX_MODE           6

// common struct
struct foilTiming
{

};

struct epeeTiming
{

};

struct saberTiming
{

};


/*
*  Struct for representing mode in display chip
*/
struct mode
{
//	unsigned char  autoRearm;       // reset lights and allow scoring automatically?
//	unsigned short autoRearmDelay;  // how long to wait
//	unsigned char  buzzer;          // should we buzz
//	unsigned short buzzerDelay;     // how long to buzz
	unsigned char  periods;         // how many periods of fencing?
	unsigned char  maxScore;        // what is the maximum score?
	
	unsigned char  periodTimer;     // should periods be timed?
	unsigned char periodTimeMin;    // how long periods are
	unsigned char periodTimeSec;    // how long periods are
	unsigned char  scoreLimited;    // should periods be score limited
	unsigned char  scoreLimit;      // what is max scored in a period?
	unsigned char  cumulative;      // is score added at each period change regardless of whether it's 5 more touches?
	
	unsigned char  breaks;          // are there breaks between periods?
	unsigned char  breakTimer;      // are breaks timed?
	unsigned char  breakTimeMin;    // how long are breaks?
	unsigned char  breakTimeSec;    // how long periods are
	unsigned char  otBreak;         // is there a breaks going into OT
	
	unsigned char  otTimer;         // should periods be timed?
	unsigned char  otTimeMin;       // how long periods are
	unsigned char  otTimeSec;       // how long periods are
	unsigned char  otLimited;       // should periods be score limited
	unsigned char  otLimit;         // what is max scored in a period?
	unsigned char  autoPriority;    // is priority auto asigned or manually assigned?
};

/*
*  Struct for representing the mode in the fencing chip
*/
struct fencingMode
{
	unsigned char  autoRearm;
	unsigned short autoRearmDelay;
	unsigned char  buzzer;
	unsigned short buzzerDelay;
};

#endif
