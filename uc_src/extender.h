/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* declarations for 74hc595 management library
**********************************************************************
* FileName:        extender.h
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
#ifndef DISP_EXTENDER_H_
#define DISP_EXTENDER_H_
#include <system.h>

extern volatile bit data_tris;
extern volatile bit shift_clock_tris;
extern volatile bit latch_clock_tris;
extern volatile bit data;
extern volatile bit shift_clock;
extern volatile bit latch_clock;

// access functions
void extInit( );
void extLoadByte( unsigned char byte);
void extLoadCharArray( unsigned char* bytes, unsigned char len);
void extLoadBitArray( unsigned char* bytes, unsigned char len);
void extLoadBit( bit b);
void extReset( );

#endif