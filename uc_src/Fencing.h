/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* Variable declarations for fencing microcontroller
**********************************************************************
* FileName:        fencing.h
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

#ifndef _FENCING_H_
#define _FENCING_H_

#define IBOX

#define TIMING_RESOLUTION 4
#define MAX_PHASE 6

// Extender settings *see extender.h
volatile bit data_tris        @ TRISB . 6;
volatile bit shift_clock_tris @ TRISA . 0;
volatile bit latch_clock_tris @ TRISB . 7;
volatile bit clock_tris @ TRISA . 4;
volatile bit data         @ PORTB . 6;
volatile bit shift_clock  @ PORTA . 0;
volatile bit latch_clock  @ PORTB . 7;
volatile bit clock_expired @ PORTA . 4;

// constant timings( in 1/10 ms)
#define FOIL_OLD_DEBOUNCE    30
#define FOIL_OLD_LOCKOUT     7500
#define FOIL_T2005_DEBOUNCE  130
#define FOIL_T2005_LOCKOUT   3000
#define EPEE_OLD_DEBOUNCE 50
#define EPEE_OLD_LOCKOUT  450
#define RESET_TIME 20000

// variables for bookkeeping
volatile unsigned char lights;
volatile bool clock_int;

// signals from display box
volatile bit weapon_select @ PORTA . 1;

// port fencing line masks
#define AMASK 0b00101100	// RA2:RA3:RA5
#define BMASK 0b00111001	// RB0:RB3:RB4:RB5  RB1:RB2 are 1 due to serial routine
#define BTRISMASK 0b00111111	// RB0:RB3:RB4:RB5  RB1:RB2 are 1 due to serial routine

// Light update macros
#define SET_GREEN_OFF_TARGET_ON  { lights |= 0x02; }
#define SET_GREEN_OFF_TARGET_OFF { lights &= 0xff-0x02; }
#define GET_GREEN_OFF_TARGET     { lights & 0x02; }
#define SET_GREEN_GRND_ON        { lights |= 0x04; }
#define SET_GREEN_GRND_OFF       { lights &= 0xff-0x04; }
#define GET_GREEN_GRND           { lights & 0x04; }
#define SET_GREEN_SCORE_ON       { lights |= 0x08; }
#define SET_GREEN_SCORE_OFF      { lights &= 0xff-0x08; }
#define GET_GREEN_SCORE          { lights & 0x08; }
#define SET_RED_OFF_TARGET_ON    { lights |= 0x40; }
#define SET_RED_OFF_TARGET_OFF   { lights &= 0xff-0x40; }
#define GET_RED_OFF_TARGET       { lights & 0x40; }
#define SET_RED_GRND_ON          { lights |= 0x20; }
#define SET_RED_GRND_OFF         { lights &= 0xff-0x20; }
#define GET_RED_GRND             { lights & 0x20; }
#define SET_RED_SCORE_ON         { lights |= 0x10; }
#define SET_RED_SCORE_OFF        { lights &= 0xff-0x10; }
#define GET_RED_SCORE            { lights & 0x10; }
#define SET_BUZZER_ON            { lights |= 0x01; }
#define SET_BUZZER_OFF           { lights &= 0xff-0x01; }
#define GET_BUZZER               { lights & 0x01; }
#define CLEAR_LIGHTS             { lights = 0x00; }
#define SET_IBOX_SABER           { lights &= 0xff - 0x80;}
#define SET_IBOX_EPEE            { lights |= 0x80;}
#define GET_IBOX_WEAPON          lights & 0x80

// Define pin to fencing line mapping( from read line return byte)
#define PISTE			0x40  // Duh
#define RED_C_LINE		0x04  // 20mm pin C ( Ground Line)
#define RED_A_LINE		0x08  // 15mm pin A ( Lame or Epee Tip)
#define RED_B_LINE		0x01  // centre pin B ( Foil Tip or Epee Return)
#define GREEN_C_LINE    0x02  // 20mm pin C
#define GREEN_A_LINE    0x10  // 15mm pin A
#define GREEN_B_LINE    0x20  // centre pin B

// Timing and other operational global variables
bool lockout_timer_active           = false; 
bool reset_active    = false;
bool clock_halted = false;
unsigned char listen[2]   = {true, true};
unsigned char weapon;			// active weapon type
unsigned short valid_timers[2] = { 0, 0 };
unsigned short off_timers[2] = { 0, 0 };
unsigned short lockout_timer = 0; 
unsigned short reset_timer = 0;
unsigned short modeNum = 0;
bool buzz_active = false;
unsigned short buzz_timer = 0;
bool old_clock_expired = false;

// weapon timing variables
struct foilTiming* currFoil;
struct epeeTiming* currEpee;
struct saberTiming* currSaber;

struct fencingMode* currMode;
struct fencingMode deMode;
struct fencingMode poolMode;
struct fencingMode de1Mode;
struct fencingMode pool1Mode;
struct fencingMode practiceMode;
struct fencingMode customMode;

unsigned short foilDebounce = 130;
unsigned short foilLockout = 3000;
unsigned short epeeDebounce = 50; 
unsigned short epeeLockout = 450;

#endif //_FENCING_H_
