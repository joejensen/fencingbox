/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* Firmware for chip handling incoming/outgoing IR communications
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

#ifndef _RECEIVER_H_
#define _RECEIVER_H_

// bookkeeping variables
volatile bool clock_int;
unsigned char weapon;

bit running;

// internal pinout mapping
volatile bit weapon_select @ PORTB . 3;
volatile bit weapon_select_tris @ TRISB . 3;

// RF/IR Codes
// 2-bit header, 1bit toggle, 5bit address, 6bit command( reversed sending order)
#define LUP       0b10001101100000
#define REARM     0b10001101010000
#define RUP       0b10001101110000
#define LDOWN     0b10001101001000
#define START     0b10001101101000
#define RDOWN     0b10001101011000
#define LYCARD    0b10001101111000
#define PRIORITY  0b10001101000100
#define RYCARD    0b10001101100100
#define LRCARD    0b10001101010100
#define PERIOD    0b10001101110100
#define RRCARD    0b10001101001100
#define MODE      0b10001101101100
#define RESET     0b10001101011100
#define WPN       0b10001101111100
#define TIMESET   0b10001101000010
#define WLYCARD   0b10001101100010
#define WLRCARD   0b10001101010010
#define WRYCARD   0b10001101110010
#define WRRCARD   0b10001101001010
#define NOPRI     0b10001101101010
#define RPERIOD   0b10001101011010

#endif //_RECEIVER_H_
