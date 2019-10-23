/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* Routines for dealing with IR/RF communications
**********************************************************************
* FileName:        rf.c
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
#include <system.h>
#include "rf.h"

/**
**  Initialize the rf module
**/
void rfInit( )
{
	// input
	set_bit( trisb, 0);
	set_bit( trisa, 3);
	// enable the RB0 interrupt
	set_bit( intcon, INTE);
	// set to rising edge interrupts
	clear_bit( option_reg, INTEDG);
}

/**********************************************
**  checks the rf receiver and returns the 
**  received 14 bit value or 0
**********************************************/
unsigned int rfReceive( void)
{
	unsigned int message = 0;
	unsigned char i, cnt;
	bit           old_rf;
	
	if( rf == 0)
	{
		for( i = 0; i < 13; i++)
		{
			// place current value into message
			message = (message << 1) + !rf;
		
			// wait till middle of next bit
			delay_100us( 14);
		
			// find edge transition
			old_rf = rf;
			cnt = 60;
			do
			{
				delay_us( 10);
				cnt--;
			}while( (old_rf == rf) && cnt != 0);
			
			// determine if there was a transition timeout
			if( cnt == 0)
				return 0;
		}
		// place current value into message
		message = (message << 1) + !rf;
	}
	return message;	
}
