/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* Functions for accessing and writing to eeprom
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
#include "eeprom.h"

/**
**  Take an address and read the memory at that location
**     returning the value
**/
char eeprom_read( char addr)
{
    eeadr = addr;
	eecon1.RD = 1;
	return eedata;
}

/**
**  put data into memory location addr in the eeprom
**/
void eeprom_write( char addr, char data)
{	
	// Ready to write?
	while (test_bit(eecon1, WR)){};

	eeadr = addr;
	eedata = data;
	set_bit(eecon1, WREN);

	// Disable interrupts
	clear_bit(intcon, GIE);

	// The "required sequence" see Datasheet pg. 91
	asm
	{
		MOVLW 55h;
		MOVWF _eecon2;
		MOVLW AAh;
		MOVWF _eecon2;
		BSF _eecon1, WR;
	}

	clear_bit(eecon1, WREN);
	set_bit(intcon, GIE);
	// Write complete, ReEnable interrupts
}
