/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* Declarations for remote control firmware
**********************************************************************
* FileName:        messages.h
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
#ifndef _REMOTE_H_
#define _REMOTE_H_

#define TIMING_RESOLUTION 2
#define SECOND_FUNCTION   30000

// bit codes for various commands
#define LUP       0b000001
#define REARM     0b000010
#define RUP       0b000011
#define LDOWN     0b000100
#define START     0b000101
#define RDOWN     0b000110
#define LYCARD    0b000111
#define PRIAUTO   0b001000
#define RYCARD    0b001001
#define LRCARD    0b001010
#define PERIOD    0b001011
#define RRCARD    0b001100
#define MODE      0b001101
#define RESET     0b001110
#define WPN       0b001111
#define PRILEFT   0b010111
#define PRIRIGHT  0b011000

#define TIMESET   0b010000
#define WLYCARD   0b010001
#define WLRCARD   0b010010
#define WRYCARD   0b010011
#define WRRCARD   0b010100
#define NOPRI     0b010101
#define RPERIOD   0b010110

unsigned short pushTimer;


// Pin definition
// Signal Pins
volatile bit ir           @ PORTA . 2;

// Check Pins
volatile bit column0 @ PORTB . 6;
volatile bit column1 @ PORTB . 5;
volatile bit column2 @ PORTB . 4;

// Strobe Pins
volatile bit row0 @ PORTA . 3;
volatile bit row1 @ PORTB . 0;
volatile bit row2 @ PORTB . 1;
volatile bit row3 @ PORTB . 2;
volatile bit row4 @ PORTB . 3;
volatile bit row5 @ PORTB . 7;

#define TRISA_STATE   0b11110011  // Error and 5&4 pins  dropped by 2 for hw upgrade
#define TRISB_STATE   0b01110000

#define STROBE_HIGH_A 0b00100000
#define STROBE_HIGH_B 0b10001111

#endif //_REMOTE_H_

