/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* Library to manage the use of 74hc595 shift registers 
**********************************************************************
* FileName:        extender.c
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
#include "extender.h"

/************************************************
** inits variables neccesary for USART to function
************************************************/
void extInit( )
{
	// set IO directions to output
	data_tris        = 0;
	shift_clock_tris = 0;
	latch_clock_tris = 0;
	
	// reset regs and set intial IOs
	data = 0;        
	shift_clock = 0;
	latch_clock = 0; // set all other pins low
}

/************************************************
** Loads bits from a byte onto the shift register
*************************************************/
void extLoadByte( unsigned char byte)
{
	unsigned char i;
	
	for( i = 0; i < 8; i++)
	{
		data = (byte & 0x01);
		byte = byte >> 1;
		
		// shift onto the regs ( positive edge)
		shift_clock = 0;
		shift_clock = 1;
	}
}

/************************************************
** Loads each char in array as a bit
************************************************/
void extLoadCharArray( unsigned char* bytes, unsigned char len)
{
	unsigned char i;
	for( i = len; i > 0; i--)
	{
		if( bytes[i-1] > 0)
			data = 1;
		else
			data = 0;
			
		shift_clock = 0;
		shift_clock = 1;
	}
	
	latch_clock = 0;
	latch_clock = 1;
}

/***********************************************
** Loads all the bits in an array onto the regs
************************************************/
void extLoadBitArray( unsigned char* bytes, unsigned char len)
{
	unsigned char i,j;
	unsigned char byte;
	
	for( i = len; i > 0; i--)
		extLoadByte( bytes[i-1]);
		
	latch_clock = 0;
	latch_clock = 1;
}

/**********************************************
** Reset the shift register array
** ----NOT IMPLEMENTED IN HARDWARE ----
***********************************************/
void extReset( )
{
/*	reset = 0;
	reset = 1;
*/
}

/************************************************
** Loads a single bit onto the shift reg
*************************************************/
void extLoadBit( bit b)
{
	data = b;
	// shift onto the regs ( positive edge)
	shift_clock = 0;
	shift_clock = 1;
	
	// clock to latches ( positive edge)
	latch_clock = 0;
	latch_clock = 1;
}
