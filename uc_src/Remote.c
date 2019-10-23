/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* Firmware for the remote control
**********************************************************************
* FileName:        remote.c
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
#include "Remote.h"

//Target PIC16F628A configuration word
#pragma DATA _CONFIG, _PWRTE_OFF & _WDT_OFF & _XT_OSC & _CP_OFF & _MCLRE_OFF & _BODEN_OFF & _LVP_OFF

//Set clock frequency
#pragma CLOCK_FREQ	4000000

/********************************************
** Handle interrupts which should be disabled
** anyway
********************************************/
void interrupt( void )
{
	if(intcon.RBIF)		// portb pin 4-7 has changed
    {
    	char pb = portb; // read portb to clear this interrupt and see if trigger fired
		intcon.RBIF=0;
	}
}

/************************************************
** A delay after a button is pressed so we dont
** send several signals for an individual press
*************************************************/
void debounce( )
{
	delay_ms( 750);
}

/************************************************
** Sends a manchester encoded one
** .8ms low then .8ms high with 38khz carrier
*************************************************/
inline void sendOne( )
{
	unsigned char c = 32;
	
	delay_100us( 8);
	
	// 9us high 16 low
	do
	{
		ir = 1;
		delay_us( 9);
		ir = 0;
		delay_us( 16);
	}while( --c > 0);	
}

/*************************************************
** sends manchester encoded Zero
** .8ms high then .8ms low
**************************************************/
inline void sendZero( )
{
	unsigned char c = 32;
	
	// 9us high 16 low
	do
	{
		ir = 1;
		delay_us( 9);
		ir = 0;
		delay_us( 16);
	}while( --c > 0);
	
	delay_100us( 8);	
}

/**************************************************
** Sends a semi-RC5 encoded command
**************************************************/
void sendRC5( unsigned char command)
{
	unsigned char i;
	
	// Send Header
	sendOne( );
	sendZero( );
	// Toggle Bit ( not used for now)
	sendZero( );
	
	// Device Address
	sendZero( );
	sendOne( );
	sendOne( );
	sendZero( );
	sendOne( );
	
	// and now send the command
	for( i = 0; i < 6; i++)
	{
		if( command & 0x1)
			sendOne( );
		else
			sendZero( );
		command >>= 1;
	}
	debounce( );
}

/***************************************************
** Sets up the processor and begins polling the buttons
***************************************************/
void main()
{
	//Configure port A
	trisa = TRISA_STATE;
	//Configure port B
	trisb = TRISB_STATE;
	
	cmcon = 7; //disable comparators
	
	// initialize interrupts
	clear_bit( intcon, GIE);
	clear_bit( intcon, PEIE);
	clear_bit( intcon, T0IE);
	clear_bit( intcon, INTE);
	clear_bit( intcon, RBIF);
	clear_bit( intcon, RBIE);
	
	// zero timer for press delay
	pushTimer = 0;
	
	// set port B internal pull ups
	clear_bit( option_reg, NOT_RBPU);
	ir = 0;
	
	while( 1)
	{
		//Strobe all low
		porta = 0;
		portb = 0;
		
		// sleep till a check pin goes high and clear interrupt
		clear_bit( intcon, RBIF);
		//sleep();
		
		// drop all strobes so we can determine which button was pressed
		porta = STROBE_HIGH_A;
		portb = STROBE_HIGH_B;
		
		// poll lines to determine which button was pressed and send the IR signal
		row0 = 0;
		if( column0 == 0)
			sendRC5( LUP);
		else if( column1 == 0)
			sendRC5( REARM);
		else if( column2 == 0)
			sendRC5( RUP);
		row0 = 1;
		
		row1 = 0;
		if( column0 == 0)
			sendRC5( LDOWN);
		else if( column1 == 0)
			sendRC5( START);
		else if( column2 == 0)
			sendRC5( RDOWN);
		row1 = 1;
		
		row2 = 0;
		if( column0 == 0)
			sendRC5( LYCARD);
		else if( column1 == 0)
			sendRC5( TIMESET);
		else if( column2 == 0)
			sendRC5( RYCARD);
		row2 = 1;
		
		row3 = 0;
		if( column0 == 0)
			sendRC5( LRCARD);
		else if( column1 == 0)
			sendRC5( PERIOD);
		else if( column2 == 0)
			sendRC5( RRCARD);
		row3 = 1;
		
		row4 = 0;
		if( column0 == 0)
			sendRC5( MODE);
		else if( column1 == 0)
			sendRC5( RESET);
		else if( column2 == 0)
			sendRC5( WPN);
		row4 = 1;
		
		row5 = 0;
		if( column0 == 0)
			sendRC5( PRILEFT);
		else if( column1 == 0)
			sendRC5( PRIAUTO);
		else if( column2 == 0)
			sendRC5( PRIRIGHT);
		row5 = 1;
		
		delay_ms( 100);
	};
}