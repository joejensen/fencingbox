/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* Handles timing of touches as well as score lights and weapon display
* for IBox
**********************************************************************
* FileName:        fencing.c
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
* Copyright (C) 2008 Joe Jensen (joe@joejensen.com)
* fencingbox.sourceforge.net
********************************************************************/
#include <system.h>
#include "Fencing.h"
#include "common.h"
#include "extender.h"
#include "usart.h"
#include "messages.h"
#pragma DATA _CONFIG, _BODEN_OFF & _CP_OFF & _DATA_CP_OFF & _PWRTE_OFF & _WDT_OFF & _LVP_OFF & _MCLRE_OFF & _HS_OSC
#pragma CLOCK_FREQ 20000000

/** Fencing Chip pinout
**
**  RA0 - To 74hc595
**  RA1 - Display Chip(RA1)() or Weapon Select on IBox
**  RA2 - Red C-Line
**  RA3 - Green C-Line
**  RA4 - Display Chip(RA2)(BUZZ)or Weapon Light on IBox
**  RA5 - Piste
**  RA6 - Oscillator
**  RA7 - Oscillator
**  RB0 - Red A-Line
**  RB1 - RX from Receiver
**  RB2 - TX to Display
**  RB3 - Red B-Line
**  RB4 - Green B-Line
**  RB5 - Green A-Line
**  RB6 - Data
**  RB7 - Shift/Latch Clocks
**
** Extender Pinout
**  QA - Unused on Jbox Weapon Light on IBox
**  QB - Red Off Target
**  QC - Red Ground
**  QD - Red Valid
**  QE - Green Valid
**  QF - Green Ground
**  QG - Green Off Target
**  QH - Buzzer
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
		tmr0 = 256 - 250 + 9;  // 250 ticks short of overflow
		clock_int = true;
		clear_bit( intcon, T0IF ); //clear timer 0 interrupt bit
	}
}

/*
*  Clears all lights and prepares the box to detect a new touch
*/
inline void rearm( )
{
	SET_RED_SCORE_OFF;
	SET_GREEN_SCORE_OFF;
	SET_RED_OFF_TARGET_OFF;
	SET_GREEN_OFF_TARGET_OFF;
					
	reset_active = false;
	reset_timer = 0;
	listen[RED] = true;
	listen[GREEN] = true;
	clock_halted = false;
	buzz_active = false;
	SET_BUZZER_OFF;
	buzz_timer = 0;
}

/*
*  Loads timings out of eeprom or text segment
*/
void loadTimings( )
{
	return;
}

/*
*  Loads neccesary mode settings out of eeprom or text segment
*/
void loadModes( )
{
	deMode.buzzer = 1;
	deMode.buzzerDelay = 20000;
	deMode.autoRearm = 1;
	deMode.autoRearmDelay = 20000;
	
	poolMode.buzzer = 1;
	poolMode.buzzerDelay = 20000;
	poolMode.autoRearm = 1;
	poolMode.autoRearmDelay = 20000;
	
	de1Mode.buzzer = 1;
	de1Mode.buzzerDelay = 20000;
	de1Mode.autoRearm = 0;
	de1Mode.autoRearmDelay = 20000;
	
	pool1Mode.buzzer = 1;
	pool1Mode.buzzerDelay = 20000;	
	pool1Mode.autoRearm = 0;
	pool1Mode.autoRearmDelay = 20000;
	
	practiceMode.buzzer = 1;
	practiceMode.buzzerDelay = 10000;
	practiceMode.autoRearm = 1;
	practiceMode.autoRearmDelay = 10000;
	
	// TODO: Make sure these addresses are valid
//	customMode.autoRearm = eeprom_read( 0);
//	customMode.autoRearmDelay = (eeprom_read( 1) << 8) | eeprom_read( 2);
//	customMode.buzzer = eeprom_read(3);
//	customMode.buzzerDelay = ( eeprom_read( 4) << 8) | eeprom_read( 5);
}

/**
**  Sets the chip into the next mode in the series
**/
void advanceMode( )
{
	modeNum++;
	if( modeNum > MAX_MODE)
		modeNum = MODE_STANDARD_DE;
		
	if( modeNum == MODE_STANDARD_DE)
		currMode = &deMode;
	else if( modeNum == MODE_STANDARD_POOL)
		currMode = &poolMode;
	else if( modeNum == MODE_REARM_DE)
		currMode = &de1Mode;
	else if( modeNum == MODE_REARM_POOL)
		currMode = &pool1Mode;
	else if( modeNum == MODE_PRACTICE)
		currMode = &practiceMode;
	else if( modeNum == MODE_CUSTOM)
		currMode = &customMode;
		
	rearm();
}

/**
**  Function polls all relevant connections to passed line
**    and returns results in a single byte
**/
unsigned char readLines( unsigned char pollLine)
{
	unsigned char aval0, bval0, aval1, bval1, trisbBack;
	
	trisbBack = trisb;             // backup the tris
	trisb = BTRISMASK ^ pollLine;  // all but poll line to input
	portb |= pollLine;             // pollLine set high
	
	// get values until they are stable
	do
	{
		delay_us( 5);
		aval0 = porta & AMASK;
		bval0 = portb & BMASK;
		
		delay_us( 5);
		aval1 = porta & AMASK;
		bval1 = portb & BMASK;
	}while( (aval0 != aval1) || (bval0 != bval1));
	
	portb ^= pollLine;  // poll line to low
	trisb = trisbBack; // restore the tris
	
	// return a byte containing state of all lines( can mask out individual line
	// with constants in fencing.h
	return bval1 | ((aval1 << 1) & 0x40) | ((aval1 >> 1) & 0x06);
}

/**
** Determines if line resistance between fencers C-Pin and line
**  is less than ~100Ohms
**/
unsigned char resistanceCheck100( unsigned char line, unsigned char fencer) 
{
	unsigned char i, return_value, trisbBack;
	
	cmcon = 0b00001010; // Assign RA2 and RA3 to comparotors
	vrcon = 0b10001110; // Set Voltage Ref module to 3.4V

	trisbBack = trisb;        // backup the tris
	trisb = BTRISMASK ^ line; // all but poll line to input
	portb |= line;         // pollLine set high

	// Datasheet tables 17-2 & 17-3 suggest 10us for comparator mode change
	// and vrcon stabilization and 400-600ns to comparator response
	delay_us( 11);
	
	// get result of comparison
	if( cmcon & ( 0x40 << fencer)) 
	{	
		// comparator value = 1 -> input voltage < Vref  =>  R > 200R
		return_value = false;		
	} 
	else 
	{		
		// comparator value = 0 -> input voltage > Vref  =>  R < 200R
		return_value = true;
	}
	
	// disable the comparator
	cmcon = 0b00001111;
	
	// restor saved state
	portb ^= line;
	trisb = trisbBack;
	
	// return true if resist less than 100
	return return_value;
}

/**
** Determines if line resistance between fencers C-Pin and line
**  is less than ~450Ohms
**/
unsigned char resistanceCheck450( unsigned char line, unsigned char fencer) 
{
	unsigned char i, return_value, trisbBack;
	
	cmcon = 0b00001010;       // Assign RA2 and RA3 to comparotors
	vrcon = 0b10000111;       // Set Voltage Ref module

	trisbBack = trisb;        // backup the tris 
	trisb = BTRISMASK ^ line; // all but poll line to input
	portb |= line;            // pollLine set high

	// Datasheet tables 17-2 & 17-3 suggest 10us for comparator mode change
	// and vrcon stabilization and 400-600ns to comparator response
	delay_us( 11);
	
	// check comparator state
	if( cmcon & ( 0x40 << fencer)) 
	{
		// comparator value = 1 -> input voltage < Vref  =>  R > 200R
		return_value = false;		
	} 
	else 
	{
		// comparator value = 0 -> input voltage > Vref  =>  R < 200R
		return_value = true;
	}
	
	// disable comparators
	cmcon = 0b00001111;
	
	// restore to saved state
	portb ^= line;
	trisb = trisbBack;
	
	// return true if resistance less than 450
	return return_value;
}

/**
**  performs processing neccesary to detect foil touches
**/
inline void foil( unsigned char fencer)
{
	unsigned char i; // variable to contain the state of the lines
	
	if( fencer == GREEN)
	{
		// Determine what the foil tip is touching
		i = readLines(GREEN_B_LINE);
		
		if( (i & PISTE) && (i & RED_B_LINE) && (i & RED_A_LINE) ) 
		{
			// Touching opponent through the piste/weapon/lame signal path
			i = GREEN_C_LINE;
		}
		else
		{ 
			// Bell and Lame are touching, anti-blocking tests needed
			if((i & RED_C_LINE) && (i & RED_A_LINE)) 
			{
				// Lame and Ground are touched so we do antiblocking tests
				if( resistanceCheck100(RED_A_LINE, RED) ) 
				{
					// Less than 100 Ohms so bell is touching lame, register as valid
					i ^= RED_C_LINE;
				} 
				else 
				{
					// Bell is not touching lame, determine which one the tip is touching
					if( resistanceCheck100(GREEN_B_LINE, RED) ) 
					{
						// it's touching the lame!
						i ^= RED_A_LINE;
					} 
					else 
					{
						// it's touching the guard
						i ^= RED_C_LINE;
					}
				}
			}

			// touching only bellguard, piste, or nothing
			if( i & (PISTE | GREEN_C_LINE | RED_C_LINE))
			{
				valid_timers[GREEN] = 0;
				off_timers[GREEN] = 0;
			} 
			
			// touching opponents lame (yay!)
			else if( i & RED_A_LINE ) 
			{
				valid_timers[GREEN] += TIMING_RESOLUTION;
				
				// register a valid touch yet?
				if ( valid_timers[GREEN] >= foilDebounce ) 
				{	
					// zero out old timers
					valid_timers[GREEN] = 0;
					off_timers[GREEN] = 0;
					
					// start lockout timer
					lockout_timer_active = true;
					
					// Red already scored so stop listening
					listen[GREEN] = false;
					
					// turn on the lights and buzzer
					SET_GREEN_SCORE_ON;
					buzz_active = true;
					
					// put message on bus about the valid touch
					putC( FENCE_TOUCH_GREEN);
				}
			} 
			else 
			{
				// not connected to the RED_C_LINE so off target!
				off_timers[GREEN] += TIMING_RESOLUTION;
				
				// do we register it off-target yet?
				if ( off_timers[GREEN] >= foilDebounce ) 
				{	
					// zero out old timers
					valid_timers[GREEN] = 0;
					off_timers[GREEN] = 0;
					
					// start the lockout timer
					lockout_timer_active = true;
					
					// stop listening to this fencer
					listen[GREEN] = false;
					
					// turn on the lights and buzzer
					SET_GREEN_OFF_TARGET_ON;
					buzz_active = true;
					
					// send message to display/computer about off target light
					putC( FENCE_OFF_GREEN);
				}
			}
		}
		
	}
	// The RED Fencer
	else
	{
		// Determine what the foil tip is touching
		i = readLines(RED_B_LINE);

		if( (i & PISTE) && (i & GREEN_B_LINE) && (i & GREEN_A_LINE) ) 
		{
			// Touching opponent through the piste/weapon/lame signal path
			i = RED_C_LINE;
		}
		else
		{ 
			// Bell and Lame are touching, anti-blocking tests needed
			if((i & GREEN_C_LINE) && (i & GREEN_A_LINE)) 
			{
				// Lame and Ground are touched so we do antiblocking tests
				if( resistanceCheck100(GREEN_A_LINE, GREEN) ) 
				{
					// Less than 100 Ohms so bell is touching lame, register as valid
					i ^= GREEN_C_LINE;
				} 
				else 
				{
					// Bell is not touching lame, determine which one the tip is touching
					if( resistanceCheck100(RED_B_LINE, GREEN) ) 
					{
						// it's touching the lame!
						i ^= GREEN_A_LINE;
					} 
					else 
					{
						// it's touching the guard
						i ^= GREEN_C_LINE;
					}
				}
			}

			// touching only bellguard, piste, or nothing
			if( i & (PISTE | RED_C_LINE | GREEN_C_LINE))
			{
				valid_timers[RED] = 0;
				off_timers[RED] = 0;
			} 
			
			// touching opponents lame (yay!)
			else if( i & GREEN_A_LINE ) 
			{
				valid_timers[RED] += TIMING_RESOLUTION;
				
				// register a valid touch yet?
				if ( valid_timers[RED] >= foilDebounce ) 
				{	
					// zero out old timers
					valid_timers[RED] = 0;
					off_timers[RED] = 0;
					
					// start lockout timer
					lockout_timer_active = true;
					
					// Red already scored so stop listening
					listen[RED] = false;
					
					// turn on the lights and buzzer
					SET_RED_SCORE_ON;
					buzz_active = true;
					
					// place message about valid touch on the buss
					putC( FENCE_TOUCH_RED);
				}
			} 
			else 
			{
				// not connected to the RED_C_LINE so off target!
				off_timers[RED] += TIMING_RESOLUTION;
				
				// do we register it off-target yet?
				if ( off_timers[RED] >= foilDebounce ) 
				{	
					// zero out old timers
					valid_timers[RED] = 0;
					off_timers[RED] = 0;
					
					// start the lockout timer
					lockout_timer_active = true;
					
					// stop listening to this fencer
					listen[RED] = false;
					
					// turn on the lights and buzzer
					SET_RED_OFF_TARGET_ON;
					buzz_active = true;
					
					// put off target message on the buss
					putC( FENCE_OFF_RED);
				}
			}
		}
	}
}

/**
**  performs processing neccesary to detect epee touches
**/
inline void epee( unsigned char fencer)
{
	unsigned char i;
	
	if( fencer == GREEN)
	{
			// What is red's tip touching?
		i = readLines(GREEN_A_LINE);
		
		// is the tip depressed?
		if ( i & GREEN_B_LINE ) 
		{
			// is the tip grounding?
			if ( i & (RED_C_LINE | PISTE) ) 
			{
				// not valid target so reset the touch timer
				valid_timers[GREEN] = 0;
			} 
			else 
			{						
				// touching valid target
				valid_timers[GREEN] += TIMING_RESOLUTION;
				
				// has it been depressed long enough to score?
				if ( valid_timers[GREEN] >= epeeDebounce ) 
				{
						// reset the valid timer
						valid_timers[GREEN] = 0;
						
						// start the lockout timer and stope listening to the green fencer
						lockout_timer_active = true;
						listen[GREEN] = false;
						
						// start light and buzzer
						SET_GREEN_SCORE_ON;
						buzz_active = true;
						
						// put touch message on the buss
						putC( FENCE_TOUCH_GREEN);
				}
			}
		} 
		else
		{
				// nothing depressed so reset valid timer
				valid_timers[GREEN] = 0;
		}
	}
	else
	{
		// What is red's tip touching?
		i = readLines(RED_A_LINE);
		
		// is the tip depressed?
		if ( i & RED_B_LINE ) 
		{
			// is the tip grounding?
			if ( i & (GREEN_C_LINE | PISTE) ) 
			{
				// hitting bell or piste so reset touch timer
				valid_timers[RED] = 0;
			} 
			else 
			{						
				// touching valid target
				valid_timers[RED] += TIMING_RESOLUTION;
				
				// has it been depressed long enough to score
				if ( valid_timers[RED] >= epeeDebounce ) 
				{	
						// reset valid tiemr for next session
						valid_timers[RED] = 0;
						
						// enable the lockout timer and stop listening for more touches on this side
						lockout_timer_active = true;
						listen[RED] = false;
						
						// start lights and buzzer
						SET_RED_SCORE_ON;
						buzz_active = true;
						
						// put touch message on buss
						putC( FENCE_TOUCH_RED);
				}
			}
		} 
		else
		{
				// no depressed at all so reset
				valid_timers[RED] = 0;
		}
	}
}

/**
**  processing for detecting saber touches
**/
inline void saber( unsigned char fencer)
{	
	if( fencer == GREEN)
	{
		return;
	}
	else
	{
		return;
	}
}

/**
**  Main loop performs initialization and main processing loop
**/
void main()
{
	int i;
	unsigned char message;
	
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
	
	// line from clock/display is an input
	clock_tris = 1;
	
	// initialize the score lights and serial port
	extInit( );
	usartInit( );
	
	// load modes from code into memory and eeprom
	loadModes();
	
	// set default mode
	currMode = &deMode;
	modeNum = MODE_STANDARD_DE;
	
	//set initial weapon
	weapon = FOIL_OLD;
	
#ifdef IBOX
	int last = 0;
#endif
	
	// start with all lights turned off
	lights = 0;
	extLoadByte( lights);
	
	tmr0 = 256-250;
	clock_int = false;
	while( 1)
	{
		// Process serial sata
		usartErrorCheck();
		while( serialPeek())
		{
			message = getC( );
			
#ifndef IBOX
			if( message == STATE_WEAPON_FOIL_OLD)
			{
				weapon = FOIL_OLD;
			}
			else if( message == STATE_WEAPON_FOIL_T2005)
			{
				weapon = FOIL_T2005;
			}
			else if( message == STATE_WEAPON_FOIL_A)
			{
				weapon = FOIL_CUSTOM_A;
			}
			else if( message == STATE_WEAPON_FOIL_B)
			{
				weapon = FOIL_CUSTOM_B;
			}
			else if( message == STATE_WEAPON_SABER_OLD)
			{
				weapon = SABER_OLD;
			}
			else if( message == STATE_WEAPON_SABER_T2005)
			{
				weapon = SABER_T2005;
			}
			else if( message == STATE_WEAPON_SABER_A)
			{
				weapon = SABER_CUSTOM_A;
			}
			else if( message == STATE_WEAPON_SABER_B)	
			{
				weapon = SABER_CUSTOM_B;
			}
			else if( message == STATE_WEAPON_EPEE_T2005)
			{
				weapon = EPEE_OLD;
			}
			else if( message == STATE_WEAPON_EPEE_A)
			{
				weapon = EPEE_CUSTOM_A;
			}
			else if( message == STATE_WEAPON_EPEE_B)
			{
				weapon = EPEE_CUSTOM_B;
			}
			else if( message == STATE_WEAPON_EPEE_C)
			{
				weapon = EPEE_CUSTOM_C;
			}
			else if( message == REM_REARM)
			{
				rearm();
			}
			else if( message == REM_MODE_ADVANCE)
				advanceMode( );
#endif //end JBox specific code
			
			putC( message);
		}
		
#ifdef IBOX

			if( !weapon_select && last == 0)
			{
					weapon += 4;
					if( weapon > MAX_WEAPON)
						weapon = 0;
					
					last += 500;
			}
			else if ( last > 0)
			{
				last--;
			}
			
			if( weapon <= FOIL_CUSTOM_B && weapon >= FOIL_OLD)
			{
				if( GET_IBOX_WEAPON)
					SET_IBOX_SABER;
				else
					SET_IBOX_EPEE;
			}
			else if( weapon <= EPEE_CUSTOM_C && weapon >= EPEE_OLD)
				SET_IBOX_EPEE;
			else if( weapon <= SABER_CUSTOM_B && weapon >= SABER_OLD)
				SET_IBOX_SABER;
#endif // end IBox specific code
		
		while( clock_int == false);
		clock_int = false;
		
		// Check Red Fencer
		if( listen[RED])
		{
			if( weapon <= FOIL_CUSTOM_B && weapon >= FOIL_OLD)
				foil( RED);
			else if( weapon <= EPEE_CUSTOM_C && weapon >= EPEE_OLD)
				epee( RED);
			else if( weapon <= SABER_CUSTOM_B && weapon >= SABER_OLD)
				saber( RED);
		}
		while( clock_int == false);
		clock_int = false;
		
		// Check Green Fencer
		if( listen[GREEN])
		{
			if( weapon <= FOIL_CUSTOM_B && weapon >= FOIL_OLD)
				foil( GREEN);
			else if( weapon <= EPEE_CUSTOM_C && weapon >= EPEE_OLD)
				epee( GREEN);
			else if( weapon <= SABER_CUSTOM_B && weapon >= SABER_OLD)
				saber( GREEN);
		}
		while( clock_int == false);
		clock_int = false;
		
		// if the clock expired line has gone high start buzzer
		if( old_clock_expired == false && clock_expired == 1)
		{
			buzz_active = true;
		}
		old_clock_expired = clock_expired;
		
		// is the buzztimer and buzz setting active
		if( currMode->buzzer && buzz_active)
		{
			SET_BUZZER_ON;
			buzz_timer += TIMING_RESOLUTION;
			if( buzz_timer >= currMode->buzzerDelay)
			{
				SET_BUZZER_OFF;
				buzz_active = false;
				buzz_timer = 0;
			}
		}
		
		// is the reset timer active?
		if ( reset_active == true ) 
		{
			// if we havent stopped the clock already do so now
			if( !clock_halted)
			{
				putC( FENCE_CLOCK_STOP);
				clock_halted = true;
			}
			
			// Only update reset timer if we have auto rearming enabled
			if( currMode->autoRearm == 1) 
			{
				reset_timer += TIMING_RESOLUTION;
				if ( reset_timer >= currMode->autoRearmDelay)
					rearm();
			}
		}
			
		// is lockout timer active?
		if ( lockout_timer_active ) 
		{
			// increment the lockout timer
			lockout_timer += TIMING_RESOLUTION;
			
			if ( weapon <= FOIL_CUSTOM_B && weapon >= FOIL_OLD) 
			{
				if ( lockout_timer >= foilLockout ) 
				{
					// reset and stop the lockout timer
					lockout_timer = 0;
					lockout_timer_active = false;
					
					// start the reset functions and disable further scoring until rearm
					reset_active = true;
					listen[RED] = false;
					listen[GREEN] = false;
				}
			}
			else if( weapon <= EPEE_CUSTOM_C && weapon >= EPEE_OLD)
			{
				if ( lockout_timer >= epeeLockout )
				{ 
					// reset and stop lockout timer
					lockout_timer = 0;
					lockout_timer_active = false;
					
					// start reset function and disable till rearm
					reset_active = true;
					listen[RED] = false;
					listen[GREEN] = false;
				}
			}
			else if( weapon <= SABER_CUSTOM_B && weapon >= SABER_OLD)
			{
				;
			}
		}
		
		// Check conductivity and set grounding lights as appropriate
		if ( weapon <= FOIL_CUSTOM_B && weapon >= FOIL_OLD) 
		{
			if( resistanceCheck450(RED_A_LINE, RED) )
				SET_RED_GRND_ON;
			if( resistanceCheck450(GREEN_A_LINE, GREEN) ) 
				SET_GREEN_GRND_ON;
		} 
		else if (weapon <= EPEE_CUSTOM_C && weapon >= EPEE_OLD) 
		{
			if( resistanceCheck450(RED_A_LINE|RED_B_LINE, RED) ) 
				SET_RED_GRND_ON;
			if( resistanceCheck450(GREEN_A_LINE|GREEN_B_LINE, GREEN) ) 
				SET_GREEN_GRND_ON;
		}
		else if( weapon <= SABER_CUSTOM_B && weapon >= SABER_OLD)
		{
			
		}
		
		//load new ligh settings for this cycle
		extLoadByte( lights);
		
		// swap front and back buffer in display chip
		latch_clock=0;
		latch_clock=1;
		
		// disable the ground lights next time if they arent re-enabled
		SET_RED_GRND_OFF;
		SET_GREEN_GRND_OFF;
		
		while( clock_int == false);
		clock_int = false;
	}

}
