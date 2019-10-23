/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* Firmware for chip handling incoming/outgoing IR communications
**********************************************************************
* FileName:        receiver.c
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
#include "Receiver.h"
#include "common.h"
#include "messages.h"
#include "usart.h"
#include "rf.h"
#pragma DATA _CONFIG, _BODEN_OFF & _CP_OFF & _DATA_CP_OFF & _PWRTE_OFF & _WDT_OFF & _LVP_OFF & _MCLRE_OFF & _HS_OSC
#pragma CLOCK_FREQ 20000000

// message from receive module
volatile unsigned int rfmessage;

/** Receiver chip pinout
**   RA0 - Weapon select input
**   RB0 - RF/IR Input
**   RB1 - RX from PC
**   RB2 - TX to Fencing Chip
**/

/***************************************************************
**  Handles all program interrupts:
**  timer0 - set 250 ticks(~.1ms) and mark as handled and clr
***************************************************************/

void interrupt( void )
{
	//Handle timer0 interrupt
	if( intcon & (1<<T0IF) )
	{
		tmr0 = 256 - 250;  // 250 ticks short of overflow
		clock_int = true;
		clear_bit( intcon, T0IF ); //clear timer 0 interrupt bit
	}
	if( intcon & (1 << INTF))
	{
		rfmessage = rfReceive( );
		clear_bit( intcon, INTF);
	}
}

/**
**  Advances to next weapon
**/
void advanceWeapon( )
{
	weapon++;
	if( weapon > MAX_WEAPON)
		weapon = 0;
				
	if( weapon == FOIL_OLD)
		putC( STATE_WEAPON_FOIL_OLD);
	else if( weapon == FOIL_T2005)
		putC( STATE_WEAPON_FOIL_T2005);
	else if( weapon == FOIL_CUSTOM_A)
		putC( STATE_WEAPON_FOIL_A);
	else if( weapon == FOIL_CUSTOM_B)
		putC( STATE_WEAPON_FOIL_B);
	else if( weapon == EPEE_OLD)
		putC( STATE_WEAPON_EPEE_T2005);
	else if( weapon == EPEE_CUSTOM_A)
		putC( STATE_WEAPON_EPEE_A);
	else if( weapon == EPEE_CUSTOM_B)
		putC( STATE_WEAPON_EPEE_B);
	else if( weapon == EPEE_CUSTOM_C)
		putC( STATE_WEAPON_EPEE_C);
	else if( weapon == SABER_OLD)
		putC( STATE_WEAPON_SABER_OLD);
	else if( weapon == SABER_T2005)
		putC( STATE_WEAPON_SABER_T2005);
	else if( weapon == SABER_CUSTOM_A)
		putC( STATE_WEAPON_SABER_A);
	else if( weapon == SABER_CUSTOM_B)
		putC( STATE_WEAPON_SABER_B);
}

/************************************************************
** determines if the weapon change button was pressed and
**   performs appropriate actions
************************************************************/
void weaponChange( )
{
	static unsigned char value[4] = {1,1,1,1};  // state history

	value[3] = value[2];
	value[2] = value[1];
	value[1] = weapon_select;
	
	if( (value[1] == value[2]) && (value[1] == value[3]))
	{
		if( value[1] != value[0])
		{
			if( value[1])
			{
				advanceWeapon( );
			}
			value[0] = value[1];
		}
	}
}

/**
** Setup and main processing loop 
**/
void main()
{
	int i;
	unsigned char sermessage;
	
	//Configure A/D pins
	cmcon = 0x07;
	
	//Setup Timers
	// Timer0 - 20,000,000 / 4 / 2 => 250 ticks == .1ms
	clear_bit( option_reg, T0CS ); //configure timer0 as a timer
	clear_bit( option_reg, PSA );  //prescaler is assigned to timer0
	clear_bit( option_reg, PS2 );  //prescaler rate 1:2
	clear_bit( option_reg, PS1 );
	clear_bit( option_reg, PS0 );
	set_bit( option_reg, T0SE );   //increment on high-to-low transition
	clear_bit( t1con, TMR1ON );    //disable timer 1
	clear_bit( t2con, TMR2ON );    //disable timer 2

	//Enable interrupts
	intcon = 0xA0;  // GIE:TMR0IE
	
	weapon_select_tris = 1;
	rfmessage = 0;
	usartInit( );
	rfInit( );
	
	weapon = FOIL_OLD;
	running = true;
	
	clock_int = false;
	while( 1)
	{
		usartErrorCheck();
		while( serialPeek())
		{
			sermessage = getC( );
			putC( sermessage);
		}
		while( clock_int == false);
		clock_int = false;
		
		weaponChange( );
		while( clock_int == false);
		clock_int = false;
		
		if( rfmessage == LUP)
		{
			putC( REM_SCORE_RED_INC);
		}
		else if( rfmessage == REARM)
		{
			putC( REM_REARM);
		}
		else if( rfmessage == RUP)
		{
			putC( REM_SCORE_GREEN_INC);
		}
		else if( rfmessage == LDOWN)
		{
			putC( REM_SCORE_RED_DEC);
		}
		else if( rfmessage == START)
		{
			putC( REM_CLOCK_TOGGLE);
		}
		else if( rfmessage == RDOWN)
		{
			putC( REM_SCORE_GREEN_DEC);
		}
		else if( rfmessage == LYCARD)
		{
			putC( REM_YELLOWCARD_RED);
		}
		else if( rfmessage == PRIORITY)
		{
			putC( REM_PRIORITY_AUTO);
		}
		else if( rfmessage == RYCARD)
		{
			putC( REM_YELLOWCARD_GREEN);
		}
		else if( rfmessage == LRCARD)
		{
			putC( REM_REDCARD_RED);
		}
		else if( rfmessage == PERIOD)
		{
			putC( REM_PERIOD_ADVANCE);
		}
		else if( rfmessage == RRCARD)
		{
			putC( REM_REDCARD_GREEN);
		}
		else if( rfmessage == MODE)
		{
			putC( REM_MODE_ADVANCE);
		}
		else if( rfmessage == RESET)
		{
			putC( REM_RESET);
		}
		else if( rfmessage == WPN)
		{
			advanceWeapon( );
		}
		else if( rfmessage == TIMESET)
		{
			putC( REM_TIMESCORE_TOGGLE);
		}
		else if( rfmessage == WLYCARD)
		{
			putC( REM_WITHDRAW_YELLOWCARD_RED);
		}
		else if( rfmessage == WLRCARD)
		{
			putC( REM_WITHDRAW_REDCARD_RED);
		}
		else if( rfmessage == WRYCARD)
		{
			putC( REM_WITHDRAW_YELLOWCARD_GREEN);
		}
		else if( rfmessage == WRRCARD)
		{
			putC( REM_WITHDRAW_REDCARD_GREEN);
		}
		else if( rfmessage == NOPRI)
		{
			putC( REM_PRIORITY_NONE);
		}
		else if( rfmessage == RPERIOD)
		{
			putC( REM_PERIOD_REVERT);
		}
		
		if( rfmessage != 0)
		{
			rfmessage = 0;
		}
		while( clock_int == false);
		clock_int = false;
	}
}
