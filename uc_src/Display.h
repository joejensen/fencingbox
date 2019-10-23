/*********************************************************************
*
*                JBox Display Microcontroller Firmware
*
**********************************************************************
* Variable and pin declarations for display firmware
**********************************************************************
* FileName:        display.h
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
#ifndef DISPLAY_H
#define DISPLAY_H
#include <system.h>
#include <rand.h>
#include "common.h"

// Extender settings *see extender.h
volatile bit data_tris        @ TRISB . 3;
volatile bit shift_clock_tris @ TRISB . 5;
volatile bit latch_clock_tris @ TRISB . 4;
volatile bit data         @ PORTB . 3;
volatile bit shift_clock  @ PORTB . 5;
volatile bit latch_clock  @ PORTB . 4;
volatile bit clock_expired_tris @ TRISA . 2;
volatile bit clock_expired @ PORTA . 2;

// Hardware associated constants
#define BITS 40
#define TIMING_RESOLUTION 4
#define SECOND_TICKS 5000
#define MAX_PHASE 6

// Data array and index mapping declaration
volatile unsigned char registers[BITS];
#define BOTTOM             registers[7]
#define BOTTOM_LEFT        registers[1]
#define BOTTOM_RIGHT       registers[6]
#define MIDDLE             registers[2]
#define TOP_LEFT           registers[3]
#define TOP_RIGHT          registers[5]
#define TOP                registers[4]

#define RED_SCORE_ONES     registers[26]
#define RED_SCORE_TENS     registers[25]
#define RED_YELLOW_CARD  registers[34]
#define RED_RED_CARD     registers[33]
#define RED_PRIORITY     registers[31]

#define GREEN_SCORE_ONES   registers[10]
#define GREEN_SCORE_TENS   registers[9]
#define GREEN_YELLOW_CARD  registers[11]
#define GREEN_RED_CARD     registers[12]
#define GREEN_PRIORITY     registers[13]

#define FOIL_CATHODE       registers[29]
#define FOIL_ANODE         registers[30]
#define EPEE_CATHODE       registers[27]
#define EPEE_ANODE         registers[28]
#define SABER_CATHODE      registers[22]
#define SABER_ANODE        registers[23]

#define PERIOD_ONE         registers[21]
#define PERIOD_TWO         registers[20]
#define PERIOD_THREE       registers[15]
#define PERIOD_OT          registers[14]

#define TIMER_COLON        registers[35]
#define TIMER_SECONDS_ONES registers[19]
#define TIMER_SECONDS_TENS registers[18]
#define TIMER_MINUTES      registers[17]

// How long to display a mode change message
#define MODE_DISPLAY_TIME 20000
#define WEAPON_DISPLAY_TIME 20000

// Data for maintaining bout state and thus display state
unsigned char weapon;     // currently selected weapon
unsigned int phase;  // what to update next
volatile bool clock_int;

// Function prototypes
void setChar( char target);

void display( );
void updateWeapon( ); // update weapon light bits
void yellowCardRed( ); //
void yellowCardGreen( );
void redCardRed( );
void redCardGreen( );
void priorityRed( );
void priorityGreen( );
void priorityAuto( );
void priorityNone( );
void processMessages( );
void reset( );

/***************************************************************
** CLOCK SECTION
****************************************************************/
unsigned int timer;       // ticks since last second on clock panel
unsigned int blinkTimer;  // ticks since last second real time for blinking
unsigned char running;    // is the clock currently running?
unsigned char minute;     // minutes remaining
unsigned char secondOnes; // seconds % 10
unsigned char secondTens; // seconds / 10
bool blinkOn;             // Should blinking things be on or off?
bool timeSet;             // is the time being set?

void startClock( );
void haltClock( );
void updateClock( );
void clockExpired( ); // what to do when the clock expires
void setTime(unsigned char minutes, unsigned char seconds );
unsigned char incrementSeconds( );
unsigned char incrementMinutes( );
unsigned char decrementSeconds( );
unsigned char decrementMinutes( );

/****************************************************************
** PERIOD SECTION
*****************************************************************/
unsigned char period;     // current period number
bool inBreak;             // is the current period a break?

void updatePeriod( );
void advancePeriod( );
void revertPeriod( );

/*****************************************************************
**  SCORE SECTION
******************************************************************/
unsigned char score[2];
unsigned char scoreOnes[2];
unsigned char scoreTens[2];
unsigned char victor[2];
unsigned char periodTouches[2]; // touches score in current period

void incrementScore( unsigned char fencer);
void decrementScore( unsigned char fencer);

/********************************************************************
** MODE SECTION
*********************************************************************/
// Constants for displaying mode or weapon changes
#define MODE_DISP_FOIL_VAL  10
#define MODE_DISP_EPEE_VAL  11
#define MODE_DISP_SABRE_VAL 5
#define MODE_HALF_M_VAL     12
#define MODE_LEFT_T_VAL     13
#define MODE_RIGHT_T_VAL    14

unsigned char modeNum;
bool          modeDisplay = false;  // are we displaying the mode settings currently
unsigned int  modeDisplayTimer = 0;

struct mode* currMode;
struct mode deMode;
struct mode poolMode;
struct mode de1Mode;
struct mode pool1Mode;
struct mode practiceMode;
struct mode customMode;

void advanceMode( );
void loadModes( );

extern void resetDisplay( );

#endif

