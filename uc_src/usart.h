/*********************************************************************
*
*                JBox Microcontroller Firmware
*
**********************************************************************
* Declarations for the usart setup library
**********************************************************************
* FileName:        usart.h
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
#ifndef USART_H_
#define USART_H_

#include <system.h>

#define BRG 21

// Safe send data
#define SERIAL_PRE     'O'
#define SERIAL_EOP     'P'
#define SERIAL_ESC     'L'
#define SERIAL_BUFSIZE 32

#define serialPeek() (pir1.RCIF)
#define serialLF() 	putC(0x0a); putC(0x0d)

void usartInit( );
void putC( unsigned char tx_char);
void putCHex( unsigned char tx_char);
void putS( char* source);
unsigned char getC( );

void serialSafeInit( );
char safePutC(char data);
char safeSend( );
char safeGetC(char index);
signed char safeReceive( );
void usartErrorCheck();

#endif