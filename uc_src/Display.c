/*********************************************************************
*
*                JBox Display Microcontroller Firmware
*
**********************************************************************
* Manages the scoring led displays and timer for the jbox
**********************************************************************
* FileName:        display.c
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

/******************************
* Pinout Overview
*******************************
 RA1 -- Fencing Chip(RA1)
 RA2 -- Fencing Chip(RA4)
 RB1 -- RX
 RB2 -- TX
 RB3 -- Serial Data Out
 RB4 -- Register Clock
 RB5 -- Serial Clock
**/

//  INCLUDES SECTION
#include "Display.h"
#include "extender.h"
#include "messages.h"
#include "usart.h"
#include "eeprom.h"

#pragma DATA _CONFIG, _BODEN_OFF & _CP_OFF & _DATA_CP_OFF & _PWRTE_OFF & _WDT_OFF & _LVP_OFF & _MCLRE_OFF & _HS_OSC
#pragma CLOCK_FREQ 20000000

// initialize mode data in the eeprom
#pragma DATA _EEPROM, \
1, 0x4E, 0x20, 1, 0x4E, 0x20, 3, 15, 1, 3, 0, 1, 15, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1

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
		clear_bit( intcon, T0IF ); //clear timer 0 interrupt bit
		clock_int = true;
	}
}

/**
** Reads and writes to the serial bus
**/
inline void processMessages( )
{
	char message = 0;
	usartErrorCheck();
	while( serialPeek())
	{
		message = getC( );
			
		if( message == REM_SCORE_RED_INC)
			if( timeSet)
				incrementMinutes( );
			else
				incrementScore( RED);
		else if( message == REM_SCORE_RED_DEC)
			if( timeSet)
				decrementMinutes( );
			else
				decrementScore( RED);
		else if( message == REM_SCORE_GREEN_INC)
			if( timeSet)
				incrementSeconds( );
			else
				incrementScore( GREEN);
		else if( message == REM_SCORE_GREEN_DEC)
			if( timeSet)
				decrementSeconds( );
			else
				decrementScore( GREEN);
		else if( message == REM_CLOCK_START)
			startClock( );
		else if( message == REM_CLOCK_STOP)
			haltClock( );
		else if( message == REM_CLOCK_TOGGLE)
		{
			if( running)
				haltClock( );
			else
				startClock( );
		}
		else if( message == REM_YELLOWCARD_RED)
			yellowCardRed( );
		else if( message == REM_YELLOWCARD_GREEN)
			yellowCardGreen( );
		else if( message == REM_REDCARD_RED)
			redCardRed( );
		else if( message == REM_REDCARD_GREEN)
			redCardGreen( );
		else if( message == REM_PRIORITY_RED)
			priorityRed( );
		else if( message == REM_PRIORITY_GREEN)
			priorityGreen( );
		else if( message == REM_PRIORITY_AUTO)
			priorityAuto( );
		else if( message == REM_PRIORITY_NONE)
			priorityNone( );
		else if( message == REM_WITHDRAW_YELLOWCARD_GREEN)
			GREEN_YELLOW_CARD = 0;
		else if( message == REM_WITHDRAW_REDCARD_GREEN)
			GREEN_RED_CARD = 0;
		else if( message == REM_WITHDRAW_YELLOWCARD_RED)
			RED_YELLOW_CARD = 0;
		else if( message == REM_WITHDRAW_REDCARD_RED)
			RED_RED_CARD = 0;
		else if( message == REM_MIN_INC)
			incrementMinutes( );
		else if( message == REM_SEC_INC)
			incrementSeconds( );
		else if( message == REM_MIN_DEC)
			decrementMinutes( );
		else if( message == REM_SEC_DEC)
			decrementSeconds( );
		else if( message == STATE_WEAPON_FOIL_OLD)
			weapon = FOIL_OLD;
		else if( message == STATE_WEAPON_FOIL_T2005)
			weapon = FOIL_T2005;
		else if( message == STATE_WEAPON_FOIL_A)
			weapon = FOIL_CUSTOM_A;
		else if( message == STATE_WEAPON_FOIL_B)
			weapon = FOIL_CUSTOM_B;
		else if( message == STATE_WEAPON_SABER_OLD)
			weapon = SABER_OLD;
		else if( message == STATE_WEAPON_SABER_T2005)
			weapon = SABER_T2005;
		else if( message == STATE_WEAPON_SABER_A)
			weapon = SABER_CUSTOM_A;
		else if( message == STATE_WEAPON_SABER_B)
			weapon = SABER_CUSTOM_B;
		else if( message == STATE_WEAPON_EPEE_T2005)
			weapon = EPEE_OLD;
		else if( message == STATE_WEAPON_EPEE_A)
			weapon = EPEE_CUSTOM_A;
		else if( message == STATE_WEAPON_EPEE_B)
			weapon = EPEE_CUSTOM_B;
		else if( message == STATE_WEAPON_EPEE_C)
			weapon = EPEE_CUSTOM_C;
		else if( message == REM_PERIOD_ADVANCE)
			advancePeriod( );
		else if( message == REM_MODE_ADVANCE)
			advanceMode( );
		else if( message == REM_PERIOD_REVERT)
			revertPeriod( );
		else if( message == REM_RESET)
			resetDisplay( );
		else if( message == REM_TIMESCORE_TOGGLE)
			timeSet = !timeSet;
		else if( message == FENCE_CLOCK_STOP)
			haltClock();
		putC( message);
	}
}

/**
**  Updates weapon indicatoe LED's
**/
inline void updateWeapon( )
{
	FOIL_CATHODE = 0;
	FOIL_ANODE = 0;
	EPEE_CATHODE = 0;
	EPEE_ANODE = 0;
	SABER_CATHODE = 0;
	SABER_ANODE = 0;
	
	if( weapon == FOIL_OLD)
	{
		FOIL_CATHODE = 1;
	}
	else if( weapon == FOIL_T2005)
	{
		FOIL_ANODE = 1;
	}
	else if( weapon == FOIL_CUSTOM_A)
	{
		if( blinkOn)
			FOIL_CATHODE = 0;
		else
			FOIL_CATHODE = 1;
	}
	else if( weapon == FOIL_CUSTOM_B)
	{
		if( blinkOn)
			FOIL_ANODE = 0;
		else
			FOIL_ANODE = 1;
	}
	else if( weapon == EPEE_OLD)
	{
		EPEE_CATHODE = 1;
	}
	else if( weapon == EPEE_CUSTOM_A)
	{
		EPEE_ANODE = 1;
	}
	else if( weapon == EPEE_CUSTOM_B)
	{
		if( blinkOn)
			EPEE_CATHODE = 0;
		else
			EPEE_CATHODE = 1;
	}
	else if( weapon == EPEE_CUSTOM_C)
	{
		if( blinkOn)
			EPEE_ANODE = 0;
		else
			EPEE_ANODE = 1;
	}
	else if( weapon == SABER_OLD)
	{
		SABER_CATHODE = 1;
	}
	else if( weapon == SABER_T2005)
	{
		SABER_ANODE = 1;
	}
	else if( weapon == SABER_CUSTOM_A)
	{
		if( blinkOn)
			SABER_CATHODE = 0;
		else
			SABER_CATHODE = 1;
	}
	else if( weapon == SABER_CUSTOM_B)
	{
		if( blinkOn)
			SABER_ANODE = 0;
		else
			SABER_ANODE = 1;
	}
}

/**
** Display stuff to the panel 1 digit per cycle to save time
**/
void display( )
{
	RED_SCORE_ONES = 0;
	RED_SCORE_TENS = 0;
	GREEN_SCORE_ONES = 0;
	GREEN_SCORE_TENS = 0;
	TIMER_SECONDS_ONES = 0;
	TIMER_SECONDS_TENS = 0;
	TIMER_MINUTES      = 0;
	
	if( phase == 0)
	{
		if( modeDisplay)
		{
			setChar( MODE_HALF_M_VAL);
			RED_SCORE_ONES = 1;
		}
		else
		{
			setChar( scoreOnes[RED]);
			if( victor[RED] && blinkOn)
				RED_SCORE_ONES = 0;
			else
				RED_SCORE_ONES = 1;
		}
	}
	else if( phase == 1)
	{
		if( modeDisplay)
		{
			setChar( MODE_HALF_M_VAL);
			RED_SCORE_TENS = 1;
		}
		else
		{
			setChar( scoreTens[RED]);
			if( victor[RED] && blinkOn)
				RED_SCORE_TENS = 0;
			else
				RED_SCORE_TENS = 1;
		}
	}
	else if( phase == 2)
	{
		if( modeDisplay)
		{
			setChar( modeNum);
			GREEN_SCORE_ONES = 1;
		}
		else
		{
			setChar( scoreOnes[GREEN]);
			if( victor[GREEN] && blinkOn)
				GREEN_SCORE_ONES = 0;
			else
				GREEN_SCORE_ONES = 1;
		}
	}
	else if( phase == 3)
	{
		if( modeDisplay)
		{
			setChar( 0);
			GREEN_SCORE_TENS = 1;
		}
		else
		{
			setChar( scoreTens[GREEN]);
			if( victor[GREEN] && blinkOn)
				GREEN_SCORE_TENS = 0;
			else
				GREEN_SCORE_TENS = 1;
		}
	}
	else if( phase == 4)
	{
		setChar( secondTens);
		if( timeSet && blinkOn)
			TIMER_SECONDS_ONES = 0;
		else
			TIMER_SECONDS_ONES = 1;
	}
	else if( phase == 5)
	{
		setChar( secondOnes);
		if( timeSet && blinkOn)
			TIMER_SECONDS_TENS = 0;
		else
			TIMER_SECONDS_TENS = 1;
	}
	else if( phase == 6)
	{
		setChar( minute);
		if( timeSet && blinkOn)
			TIMER_MINUTES = 0;
		else
			TIMER_MINUTES = 1;
	}
	
	phase++;
	if( phase > MAX_PHASE)
		phase = 0;
}

/******************************************************
** Main loop in display program
*******************************************************/
void main()
{
	int i;
	
	//Configure A/D pins
	cmcon = 0x07;
	
	//Setup Timers
	// Timer0 - 20,000,000 / 4 / *4* => 250 ticks == .2ms
	clear_bit( option_reg, T0CS ); //configure timer0 as a timer
	clear_bit( option_reg, PSA );  //prescaler is assigned to timer0
	clear_bit( option_reg, PS2 );  //prescaler rate 1:*4*
	clear_bit( option_reg, PS1 );
	set_bit( option_reg, PS0 );
	set_bit( option_reg, T0SE );   //increment on high-to-low transition
	clear_bit( t1con, TMR1ON );    //disable timer 1
	clear_bit( t2con, TMR2ON );    //disable timer 2

	//Enable interrupts
	intcon = 0xA0;  // GIE:TMR0IE
	
	clock_expired_tris = 0;
	
	// setup the extender
	extInit( );
	usartInit( );
	loadModes( );
	
	// initialize our variables
	for( i = 0; i < BITS; i++)
	{
		registers[i] = 0;
	}

	phase = 0;
	weapon = FOIL_OLD;
	modeNum = MODE_STANDARD_DE;
	currMode = &deMode;
	timeSet = false;
	resetDisplay( );
	
	clock_int = false;
	while( 1)
	{
		extLoadCharArray( registers, BITS);
		while( clock_int == false);
		clock_int = false;
		
		processMessages( );
		while( clock_int == false);
		clock_int = false;
		
		updateClock( );
		updateWeapon( );
		updatePeriod( );
		display( );
		while( clock_int == false);
		clock_int = false;
		
		processMessages( );
		while( clock_int == false);
		clock_int = false;
	}
}

/**
**  Resets for a new bout
**/
void resetDisplay( )
{
	// should we use period incicators
	if( currMode->periods > 0 && currMode->periods < 4)
		period = PERIOD_FIRST;
	else
		period = PERIOD_NONE;
	
	// Zero out the scores/cards/priority
	score[RED] = 0;
	scoreOnes[RED] = 0;
	scoreTens[RED] = 0;
	score[GREEN] = 0;
	scoreOnes[GREEN] = 0;
	scoreTens[GREEN] = 0;
	inBreak = false;
	victor[RED] = 0;
	victor[GREEN] = 0;
	
	// stop and reset the clock
	running = 0;
	timer = 0;
	setTime( currMode->periodTimeMin, currMode->periodTimeSec);
}

/******************************************************
** Sets the correct 7-segment bits for a give number
** Since all displayable characters have values above
** single digits, values less than ten displayed directly
*******************************************************/
void setChar( unsigned char target)
{
	switch( target)
	{
		case 0:
			TOP = 1;
			TOP_LEFT = 1;
			TOP_RIGHT = 1;
			BOTTOM_LEFT = 1;
			BOTTOM_RIGHT = 1;
			BOTTOM = 1;
			MIDDLE = 0;
			break;
		case 1:
			TOP = 0;
			TOP_LEFT = 0;
			TOP_RIGHT = 1;
			BOTTOM_LEFT = 0;
			BOTTOM_RIGHT = 1;
			BOTTOM = 0;
			MIDDLE = 0;
			break;
		case 2:
			TOP = 1;
			TOP_LEFT = 0;
			TOP_RIGHT = 1;
			BOTTOM_LEFT = 1;
			BOTTOM_RIGHT = 0;
			BOTTOM = 1;
			MIDDLE = 1;
			break;
		case 3:
			TOP = 1;
			TOP_LEFT = 0;
			TOP_RIGHT = 1;
			BOTTOM_LEFT = 0;
			BOTTOM_RIGHT = 1;
			BOTTOM = 1;
			MIDDLE = 1;
			break;
		case 4:
			TOP = 0;
			TOP_LEFT = 1;
			TOP_RIGHT = 1;
			BOTTOM_LEFT = 0;
			BOTTOM_RIGHT = 1;
			BOTTOM = 0;
			MIDDLE = 1;
			break;
		case 5:
			TOP = 1;
			TOP_LEFT = 1;
			TOP_RIGHT = 0;
			BOTTOM_LEFT = 0;
			BOTTOM_RIGHT = 1;
			BOTTOM = 1;
			MIDDLE = 1;
			break;
		case 6:
			TOP = 1;
			TOP_LEFT = 1;
			TOP_RIGHT = 0;
			BOTTOM_LEFT = 1;
			BOTTOM_RIGHT = 1;
			BOTTOM = 1;
			MIDDLE = 1;
			break;
		case 7:
			TOP = 1;
			TOP_LEFT = 0;
			TOP_RIGHT = 1;
			BOTTOM_LEFT = 0;
			BOTTOM_RIGHT = 1;
			BOTTOM = 0;
			MIDDLE = 0;
			break;
		case 8:
			TOP = 1;
			TOP_LEFT = 1;
			TOP_RIGHT = 1;
			BOTTOM_LEFT = 1;
			BOTTOM_RIGHT = 1;
			BOTTOM = 1;
			MIDDLE = 1;
			break;
		case 9:
			TOP = 1;
			TOP_LEFT = 1;
			TOP_RIGHT = 1;
			BOTTOM_LEFT = 0;
			BOTTOM_RIGHT = 1;
			BOTTOM = 1;
			MIDDLE = 1;
			break;
		case MODE_DISP_FOIL_VAL:
			TOP = 1;
			TOP_LEFT = 1;
			TOP_RIGHT = 0;
			BOTTOM_LEFT = 1;
			BOTTOM_RIGHT = 0;
			BOTTOM = 0;
			MIDDLE = 1;
			break;
		case MODE_HALF_M_VAL:
			TOP = 1;
			TOP_LEFT = 1;
			TOP_RIGHT = 1;
			BOTTOM_LEFT = 1;
			BOTTOM_RIGHT = 1;
			BOTTOM = 0;
			MIDDLE = 0;
			break;
		case MODE_LEFT_T_VAL:
			TOP = 1;
			TOP_LEFT = 0;
			TOP_RIGHT = 1;
			BOTTOM_LEFT = 0;
			BOTTOM_RIGHT = 1;
			BOTTOM = 0;
			MIDDLE = 0;
			break;
		case MODE_RIGHT_T_VAL:
			TOP = 1;
			TOP_LEFT = 1;
			TOP_RIGHT = 0;
			BOTTOM_LEFT = 1;
			BOTTOM_RIGHT = 0;
			BOTTOM = 0;
			MIDDLE = 0;
			break;
		case MODE_DISP_EPEE_VAL:
		default:
			TOP = 1;
			TOP_LEFT = 1;
			TOP_RIGHT = 0;
			BOTTOM_LEFT = 1;
			BOTTOM_RIGHT = 0;
			BOTTOM = 1;
			MIDDLE = 1;
			break;
	};
}

void yellowCardRed( )
{
	if( RED_YELLOW_CARD || RED_RED_CARD)
		incrementScore( GREEN);
	else
		RED_YELLOW_CARD = 1;
}

void yellowCardGreen( )
{
	if( GREEN_YELLOW_CARD || GREEN_RED_CARD)
		incrementScore( RED);
	else
		GREEN_YELLOW_CARD = 1;
}

void redCardRed( )
{
	RED_RED_CARD = 1;
	RED_YELLOW_CARD = 1;
	incrementScore( GREEN);
}

void redCardGreen( )
{
	GREEN_RED_CARD = 1;
	GREEN_YELLOW_CARD = 1;
	incrementScore( RED);
}

void priorityRed( )
{
	RED_PRIORITY = 1;
	GREEN_PRIORITY = 0;
}

void priorityGreen( )
{
	RED_PRIORITY = 0;
	GREEN_PRIORITY = 1;
}

void priorityAuto( )
{
	if( rand( ) % 2)
		priorityRed( );
	else
		priorityGreen( );
}

void priorityNone( )
{
	RED_PRIORITY = 0;
	GREEN_PRIORITY = 0;
}

void incrementScore( unsigned char fencer)
{
	score[fencer]++;
	periodTouches[fencer]++;
	if( scoreOnes[fencer] == 9)
	{
		if( scoreTens[fencer] == 9)
			return;
		else
		{
			scoreOnes[fencer] = 0;
			scoreTens[fencer]++;
		}
	}
	else
	{
		scoreOnes[fencer]++;
	}
	
	// handle mode stuff
	if( score[fencer] >= currMode->maxScore)
	{
		victor[fencer] = true;
		running = 0;
	}
	else if( period <= currMode->periods  && currMode->scoreLimited && currMode->cumulative && score[fencer] > currMode->scoreLimit*period)
	{
			advancePeriod();
	}
	else if( period <= currMode->periods && currMode->scoreLimited && !currMode->cumulative && periodTouches[fencer] >= currMode->scoreLimit)
	{
			advancePeriod();
	}
	else if( period > currMode->periods && currMode->otLimited && currMode->otLimit <= periodTouches[fencer])
	{
		victor[fencer] = true;
		running = 0;
	}
}

void decrementScore( unsigned char fencer)
{
	if( score[fencer] == 0)
		return;

	score[fencer]--;
	periodTouches[fencer]--;
	if( scoreOnes[fencer] == 0)
	{
		if( scoreTens[fencer] == 0)
			return;
		else
		{
			scoreOnes[fencer] = 9;
			scoreTens[fencer]--;
		}
	}
	else
	{
		scoreOnes[fencer]--;
	}
	
	// handle mode stuff
	if(( score[fencer] < currMode->maxScore) ||
	  ( period > currMode->periods && currMode->otLimited && currMode->otLimit > periodTouches[fencer]))
	{
			victor[fencer] = false;
	}
}

/**
**  Function to update clock value per cycle
**/
void updateClock( )
{
	// timer for managing all blinking lights
	blinkTimer += TIMING_RESOLUTION;
	if( blinkTimer >= SECOND_TICKS)
		blinkTimer -= SECOND_TICKS;
	if( blinkTimer > SECOND_TICKS/2)
		blinkOn = true;
	else
		blinkOn = false;

	// if were displaying the mode run the timer
	if( modeDisplay)
	{
		modeDisplayTimer += TIMING_RESOLUTION;
		
		if( modeDisplayTimer >= SECOND_TICKS*2)
		{
			modeDisplay = false;
			modeDisplayTimer = 0;
		}
	}
	
	// display the colon on the clock?
	if( running == 0)
	{		
		if( blinkOn)
			TIMER_COLON = 0;
		else
			TIMER_COLON = 1;
		return;
	}
	TIMER_COLON = 1;
	
	// actually update the clock itself
	timer += TIMING_RESOLUTION;
	if( timer >= SECOND_TICKS)
	{
		timer -= SECOND_TICKS;
		if( !decrementSeconds( ))
			clockExpired( );
	}
}

/**
**  increments seconds on the clock
**/
unsigned char incrementSeconds( )
{
	if( secondOnes == 9)
	{
		if( secondTens == 5)
		{
			return incrementMinutes( );
			secondOnes = 0;
			secondTens = 0;
		}
		else
		{
			secondOnes = 0;
			secondTens++;
		}
	}
	else
		secondOnes++;
	return true;
}

/**
**  increments minutes on the clock
**/
unsigned char incrementMinutes( )
{
	if( minute == 9)
		return false;
	else
		minute++;
	return true;
}

/**
**  decrements seconds on the clock
**/
unsigned char decrementSeconds( )
{
	if( secondOnes == 0)
	{
		if( secondTens == 0)
		{
			if( decrementMinutes( ))
			{
				secondOnes = 9;
				secondTens = 5;
			}
			else
			{
				secondOnes = 0;
				secondTens = 0;
				return false;
			}
		}
		else
		{
			secondOnes = 9;
			secondTens--;
		}
	}
	else
		secondOnes--;
	return true;
}

/**
**  decrements minutes on the clock
**/
unsigned char decrementMinutes( )
{
	if( minute == 0)
		return false;
	else
		minute--;
	return true;
}

/**
**  Starts the clock
**/
void startClock( )
{
	running = 1;
}

/**
**  Halts the clock
**/
void haltClock( )
{
	running = 0;
}

/**
**  Sets the time to passed values ( we assume reasonable values)
**/
void setTime(unsigned char minutes, unsigned char seconds )
{
	minute = minutes;
	secondOnes = seconds % 10;
	secondTens = seconds / 10;
	secondOnes = 0;
	secondTens = 0;
}

/**
**  Do clock expired stuff
**/
void clockExpired( )
{
	// raise expired clock line
	clock_expired = 1;
	delay_ms( 1);
	clock_expired = 0;
	
	advancePeriod( );
	timer = 0;
}

/**
**  Called to update the period lights
**/
void updatePeriod( )
{
	PERIOD_ONE = 0;
	PERIOD_TWO = 0;
	PERIOD_THREE = 0;
	PERIOD_OT = 0;
	if( period == PERIOD_FIRST && inBreak)
	{
		if( blinkOn)
			PERIOD_ONE = 0;
		else
			PERIOD_ONE = 1;
	}
	else if( period == PERIOD_SECOND && inBreak)
	{
		if( blinkOn)
			PERIOD_TWO = 0;
		else
			PERIOD_TWO = 1;
	}
	else if( period == PERIOD_THIRD && inBreak)
	{
		if( blinkOn)
			PERIOD_THREE = 0;
		else
			PERIOD_THREE = 1;
	}
	else if( period == PERIOD_FIRST)
	{
		PERIOD_ONE = 1;
	}
	else if( period == PERIOD_SECOND)
	{
		PERIOD_TWO = 1;
	}
	else if( period == PERIOD_THIRD)
	{
		PERIOD_THREE = 1;
	}
	else if( period == PERIOD_EXTRA)
	{
		PERIOD_OT = 1;
	}
}

/**
**  Moves back to previous period
**/
void revertPeriod( )
{
	if( period == PERIOD_NONE)
		return;	
	
	if( period < currMode->periods)
	{
		if( currMode->breaks && !inBreak && period != PERIOD_FIRST)
		{
			period--;
			inBreak = true;
			setTime( currMode->breakTimeMin, currMode->breakTimeSec);
		}
		else
		{
			inBreak = false;
			setTime( currMode->periodTimeMin, currMode->periodTimeSec);
		}
	}
	else if( period == currMode->periods)
	{
		if( currMode->otBreak && !inBreak)
		{
			period--;
			inBreak = true;
			setTime( currMode->breakTimeMin, currMode->breakTimeSec);
		}
		else
		{
			period--;
			inBreak = false;
			setTime( currMode->otTimeMin, currMode->otTimeSec);
		}
	}
	
	victor[RED] = false;
	victor[GREEN] = false;
	
	if( inBreak)
		running = 1;
	else
		running = 0;
		
	periodTouches[RED] = 0;
	periodTouches[GREEN] = 0;
}

/**
**  Moves bout to the next period
**/
void advancePeriod( )
{
	if( period < currMode->periods && period != PERIOD_NONE)
	{
		if( currMode->breaks && !inBreak)
		{
			inBreak = true;
			setTime( currMode->breakTimeMin, currMode->breakTimeSec);
		}
		else
		{
			inBreak = false;
			period++;
			setTime( currMode->periodTimeMin, currMode->periodTimeSec);
		}
	}
	else if( period == currMode->periods && score[RED] == score[GREEN])
	{
		if( currMode->otBreak && !inBreak)
		{
			inBreak = true;
			setTime( currMode->breakTimeMin, currMode->breakTimeSec);
		}
		else
		{
			inBreak = false;
			period ++;
			if( currMode->autoPriority)
				priorityAuto();
			setTime( currMode->otTimeMin, currMode->otTimeSec);
		}
	}
	else
	{
		if( score[RED] > score[GREEN])
			victor[RED] = true;
		else if( score[GREEN] > score[RED])
			victor[GREEN] = true;
		else if( RED_PRIORITY)
			victor[RED] = true;
		else if( GREEN_PRIORITY)
			victor[GREEN] = true;
	}
	
	if( inBreak)
		running = 1;
	else
		running = 0;
		
	periodTouches[RED] = 0;
	periodTouches[GREEN] = 0;
}

/**
** Loads mode descriptions
**/
void loadModes( )
{
	deMode.periods = 3;
	deMode.maxScore = 15;
	deMode.periodTimer = 1;
	deMode.periodTimeMin = 3;
	deMode.periodTimeSec = 0;
	deMode.scoreLimited = 1;
	deMode.scoreLimit = 15;
	deMode.cumulative = 0;
	deMode.breaks = 1;
	deMode.breakTimer = 1;
	deMode.breakTimeMin = 1;
	deMode.breakTimeSec = 0;
	deMode.otBreak = 0;
	deMode.otTimer = 1;
	deMode.otTimeMin = 1;
	deMode.otTimeSec = 0;
	deMode.otLimited = 1;
	deMode.otLimit = 1;
	deMode.autoPriority  = 1;
	
	poolMode.periods = 1;
	poolMode.maxScore = 5;
	poolMode.periodTimer = 1;
	poolMode.periodTimeMin = 3;
	poolMode.periodTimeSec = 0;
	poolMode.scoreLimited = 1;
	poolMode.scoreLimit = 5;
	poolMode.cumulative = 0;
	poolMode.breaks = 0;
	poolMode.breakTimer = 1;
	poolMode.breakTimeMin = 1;
	poolMode.breakTimeSec = 0;
	poolMode.otBreak = 0;
	poolMode.otTimer = 1;
	poolMode.otTimeMin = 1;
	poolMode.otTimeSec = 0;
	poolMode.otLimited = 1;
	poolMode.otLimit = 1;
	poolMode.autoPriority  = 1;
	
	de1Mode.periods = 3;
	de1Mode.maxScore = 15;
	de1Mode.periodTimer = 1;
	de1Mode.periodTimeMin = 3;
	de1Mode.periodTimeSec = 0;
	de1Mode.scoreLimited = 0;
	de1Mode.scoreLimit = 0;
	de1Mode.cumulative = 0;
	de1Mode.breaks = 1;
	de1Mode.breakTimer = 1;
	de1Mode.breakTimeMin = 1;
	de1Mode.breakTimeSec = 0;
	de1Mode.otBreak = 0;
	de1Mode.otTimer = 1;
	de1Mode.otTimeMin = 1;
	de1Mode.otTimeSec = 0;
	de1Mode.otLimited = 1;
	de1Mode.otLimit = 1;
	de1Mode.autoPriority  = 0;
	
	pool1Mode.periods = 1;
	pool1Mode.maxScore = 5;
	pool1Mode.periodTimer = 1;
	pool1Mode.periodTimeMin = 3;
	pool1Mode.periodTimeSec = 0;
	pool1Mode.scoreLimited = 1;
	pool1Mode.scoreLimit = 5;
	pool1Mode.cumulative = 0;
	pool1Mode.breaks = 1;
	pool1Mode.breakTimer = 1;
	pool1Mode.breakTimeMin = 1;
	pool1Mode.breakTimeSec = 0;
	pool1Mode.otBreak = 0;
	pool1Mode.otTimer = 1;
	pool1Mode.otTimeMin = 1;
	pool1Mode.otTimeSec = 0;
	pool1Mode.otLimited = 1;
	pool1Mode.otLimit = 1;
	pool1Mode.autoPriority  = 0;
	
	practiceMode.periods = 0;
	practiceMode.maxScore = 0;
	practiceMode.periodTimer = 0;
	practiceMode.periodTimeMin = 0;
	practiceMode.periodTimeSec = 0;
	practiceMode.scoreLimited = 0;
	practiceMode.scoreLimit = 0;
	practiceMode.cumulative = 0;
	practiceMode.breaks = 0;
	practiceMode.breakTimer = 0;
	practiceMode.breakTimeMin = 0;
	practiceMode.breakTimeSec = 0;
	practiceMode.otBreak = 0;
	practiceMode.otTimer = 0;
	practiceMode.otTimeMin = 0;
	practiceMode.otTimeSec = 0;
	practiceMode.otLimited = 0;
	practiceMode.otLimit = 0;
	practiceMode.autoPriority  = 0;
	
// first 4 removed from struct
//	customMode.autoRearm = eeprom_read( 0);
//	customMode.autoRearmDelay = (eeprom_read( 1) << 8) | eeprom_read( 2);
//	customMode.buzzer = eeprom_read(3);
//	customMode.buzzerDelay = ( eeprom_read( 4) << 8) | eeprom_read( 5);
	customMode.periods = eeprom_read(6);
	customMode.maxScore = eeprom_read(7);
	customMode.periodTimer = eeprom_read(8);
	customMode.periodTimeMin = eeprom_read(9);
	customMode.periodTimeSec = eeprom_read(10);
	customMode.scoreLimited = eeprom_read(11);
	customMode.scoreLimit = eeprom_read(12);
	customMode.cumulative = eeprom_read(13);
	customMode.breaks = eeprom_read(14);
	customMode.breakTimer = eeprom_read(15);
	customMode.breakTimeMin = eeprom_read(16);
	customMode.breakTimeSec = eeprom_read(17);
	customMode.otBreak = eeprom_read(18);
	customMode.otTimer = eeprom_read(19);
	customMode.otTimeMin = eeprom_read(20);
	customMode.otTimeSec = eeprom_read(21);
	customMode.otLimited = eeprom_read(22);
	customMode.otLimit = eeprom_read(23);
	customMode.autoPriority  = eeprom_read(24);
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
		
	modeDisplay = true;
	resetDisplay( );
}
