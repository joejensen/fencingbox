/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* Library to set up and use the usart serial port on PIC chips
**********************************************************************
* FileName:        usart.c
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
#include "usart.h"
#include "messages.h"

char buffer[SERIAL_BUFSIZE];
char bufferPointer;

/****************************************************************
** Initializes the USART serial port
****************************************************************/
void usartInit()
{
	// Enable USART function on PORTB
	trisb.1       = 1;			
	trisb.2       = 1; 		

	// Transmit control register
	txsta.CSRC    = 0;  // Don't care for asynchronous mode
	txsta.TX9     = 0;  // Not using the 9th bit
	txsta.TXEN    = 1;  // Transmit enabled
	txsta.SYNC    = 0;  // Asynchronous mode
	txsta.BRGH    = 1;  // High speed baud rate generator
	txsta.TX9D    = 0;  // clear out the 9th bit slot
	
	// Receive control register
	rcsta.SPEN    = 1;  // enable the serial port!
	rcsta.RX9     = 0;  // 8-bit receive mode
	rcsta.SREN    = 0;  // Single Receive Enable - don't care for asynch
	rcsta.CREN    = 1;  // continuous receive enabled
	rcsta.ADEN    = 0;  // address bit - irrelevent for RX9=0
	rcsta.FERR    = 0;  // No framing errors yet
	// rcsta.OERR = 0; // clear this by negative pulsing CREN Overflow error
	rcsta.RX9D    = 0;  // clear 9th bit area

	// Baud rate setting
    spbrg 	   = BRG;  // seed the baud rate generator
    
    // Clear the 3-deep RCREG register
	asm
	{
		movf	_rcreg, W
		movf	_rcreg, W
		movf	_rcreg, W
	}
}

/***************************************************************
** waits till we're free to tranmit and sends a character
****************************************************************/
void putC( unsigned char tx_char)
{
#ifdef DBG_COMPILE
// Skip when debugging
#warning "Debug build, serial_printf will return immediately"
		return;
#endif

	// Wait until txreg is empty to insert new byte
    while((pir1.TXIF) == 0);
    
    // disable interrupts
	while( intcon.GIE)
		intcon.GIE = 0;
		
	// place byte into transmit register
	txreg = tx_char;
		
	// re-enable interrupts
	intcon.GIE = 1;
}

/***************************************************************
** sends the hex value of a char
****************************************************************/

void putCHex( unsigned char tx_char)
{
	unsigned char i;
	char          hexchar;
	
	for( i = 0; i < 2; i++)
	{
		if( i == 0)
			hexchar = tx_char >> 4;
		else
			hexchar = tx_char & 0x0F;
			
		if( hexchar < 10)
			hexchar = hexchar + '0';
		else
			hexchar = hexchar + ('A' - 10);	

		putC( hexchar);
	}
}

/***************************************************
** Send a string over usart
****************************************************/
void putS( char* source)
{
	while( *source != 0)
		putC( *source++);
	serialLF();
}

/***************************************************
** Gets a char from the usart
***************************************************/
unsigned char getC( )
{
#ifdef DBG_COMPILE
#warning "Debug build, getC will return 0x00"
	return 0x00;
#endif

	unsigned char rx_byte;
	
	// disable the interrupts
	while( intcon.GIE)
		intcon.GIE = 0;
		
	// save data
	rx_byte = rcreg;
	
	// re-enable interrupts
	intcon.GIE = 1;
	
	return rx_byte;
}

/**
**  Initialze the safe send features
**/
void serialSafeInit( )
{
	bufferPointer = 0;
}

/**
**  Put a character into the safety buffer
**/
char safePutC(char data)
{
	buffer[bufferPointer] = data;
	bufferPointer++;

	if (bufferPointer == SERIAL_BUFSIZE){
		return 1;
	}
	return 0;
}

/**
**  get a character out of the safe receive buffer
**/
char safeGetC(char index)
{
	return buffer[index];
}

/**
**  Receive takin out the header and footer
**/
signed char safeReceive( )
{
	bufferPointer = 0;
	char cur;
	char checksum  = 0;
	char loper     = 0;
	bit  got_escape;	

	// Expecting a packet that has the structure
	// <PRE><PRE>[<DATA1><DATA2> ... ]<CRC><EOP>
	
	while (loper < 2){
		cur = getC();
		if (cur == SERIAL_PRE){
			loper ++;
		} else {
			loper = 0;
		}
	}

	// Receive data
	do {
		got_escape = 0;
		
		cur = getC();
		if (cur == SERIAL_ESC){
			cur = getC();
			got_escape = 1;
		}
		
		buffer[bufferPointer] = cur;
		bufferPointer++;
		if (bufferPointer == SERIAL_BUFSIZE){
			return -1;
		}
	} while (cur != SERIAL_EOP || got_escape);
	
	bufferPointer -= 2;
	return bufferPointer;
}

/**
**   Send the buffer with header and footers
**/
char safeSend( )
{
	char loper;
	char cur;
	char checksum;
	
	// Safety check
	if (bufferPointer == 0){
		return 1;
	}
	
	checksum = 0;
	
	// Send header
	putC(SERIAL_PRE);
	putC(SERIAL_PRE);
	
	// Transmit buffer
	for (loper = 0; loper < bufferPointer; loper++)
	{
		cur = buffer[loper];
		
		// Check if we need to send the ESCAPE byte
		if ((cur == SERIAL_PRE) || (cur == SERIAL_EOP) || (cur == SERIAL_ESC)){
			putC(SERIAL_ESC);
		}
		
		// Send data
		putC(cur);
		
		// Update checksum
		checksum += cur;
	}
	
	// Send checksum and EOP
	if ((checksum == SERIAL_PRE) || (checksum == SERIAL_EOP) || (checksum == SERIAL_ESC)){
		putC(SERIAL_ESC);
	}
	
	putC(~checksum + 1);
	putC(SERIAL_EOP);
	
	bufferPointer = 0;
	return 0;
}

/***************************************************************
**  Determine if a usart error has occurred and try to recover
****************************************************************/
void usartErrorCheck()
{
	// if theres an overrun flag
	if( rcsta.OERR)
	{
		// disable interrupts
		while( intcon.GIE)
			intcon.GIE = 0;
	
		// clear the 3-deep rcreg stack
		asm
		{
			movf	_rcreg, W
			movf	_rcreg, W
			movf	_rcreg, W
		}
		
		// negative pulse cren
		rcsta.CREN = 0;
		rcsta.CREN = 1;
		
		// restore interrupts
		intcon.GIE = 1;
		
		// inform of error
		putC( BOX_OVERRUN_ERROR);
	}
	// if theres a framing error
	else if( rcsta.FERR)
	{
		// disable interrupts
		while( intcon.GIE)
			intcon.GIE = 0;
	
		// a single read can clear a framing error
		asm
		{
			movf	_rcreg, W
		}
		
		// restore interrupts
		intcon.GIE = 1;
		
		// inform of error
		putC( BOX_FRAMING_ERROR);
	}
}
