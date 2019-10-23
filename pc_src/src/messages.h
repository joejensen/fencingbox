/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* defines bytecode messages that can be sent of received with the J/IBox
* all changes should be reflected in the uc_src messages.h and vice-versa
**********************************************************************
* FileName:        messages.h
* Dependencies:    See INCLUDES section below
* OS:              Tested on Windows XP
* Compiler:        MinGW gcc 3.4.2
*
* Software License Agreement
* This file is part of the JBox firmware.
*
* The JBox PC Interface is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* JBox PC Interface is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with JBox PC Interface.  If not, see <http://www.gnu.org/licenses/>.
*
* Copyright (C) 2007 Joe Jensen (joe@joejensen.com)
* fencingbox.sourceforge.net
********************************************************************/
#ifndef MESSAGES_H_
#define MESSAGES_H_

/*******************
**Remote Signals
********************/
// Score control signals
#define REM_SCORE_RED_INC                0x00
#define REM_SCORE_GREEN_INC              0x01
#define REM_SCORE_RED_DEC                0x02
#define REM_SCORE_GREEN_DEC              0x03

// clock control signals
#define REM_CLOCK_START                  0x04
#define REM_CLOCK_STOP                   0x05
#define REM_CLOCK_TOGGLE                 0x06
#define REM_MIN_INC                      0x07
#define REM_MIN_DEC                      0x08
#define REM_SEC_INC                      0x09
#define REM_SEC_DEC                      0x0A

// Card control
#define REM_REDCARD_RED                  0x0B
#define REM_REDCARD_GREEN                0x0C
#define REM_WITHDRAW_REDCARD_RED         0x0D
#define REM_WITHDRAW_REDCARD_GREEN       0x0E
#define REM_YELLOWCARD_RED               0x0F
#define REM_YELLOWCARD_GREEN             0x10
#define REM_WITHDRAW_YELLOWCARD_RED      0x11
#define REM_WITHDRAW_YELLOWCARD_GREEN    0x12

// Priority control
#define REM_PRIORITY_GREEN               0x13
#define REM_PRIORITY_RED                 0x14
#define REM_PRIORITY_AUTO                0x58
#define REM_PRIORITY_NONE                0x15

// Period control
#define REM_PERIOD_ADVANCE               0x16
#define REM_PERIOD_REVERT                0x17

// Mode control
#define REM_MODE_ADVANCE                 0x18

// General control
#define REM_RESET                        0x19
#define REM_REARM                        0x1A
#define REM_TIMESCORE_TOGGLE             0x1B

// Weapon control
#define REM_WEAPON_ADVANCE               0x56

/***********************
**Fencing chip signals
************************/
// Light signals
#define FENCE_TOUCH_RED                  0x1C
#define FENCE_TOUCH_GREEN                0x1D
#define FENCE_OFF_RED                    0x1E
#define FENCE_OFF_GREEN                  0x1F
#define FENCE_GND_RED                    0x20
#define FENCE_GND_GREEN                  0x21
#define FENCE_CLOCK_STOP				 0x57

/************************
**Display chip signals
*************************/
// Priority Signals
#define DISP_PRIOR_GREEN                 0x22
#define DISP_PRIOR_RED                   0x23
#define DISP_PRIOR_NONE                  0x24

/***********************
** State identifiers
************************/
// Weapon mode
#define STATE_WEAPON_FOIL_OLD            0x25
#define STATE_WEAPON_FOIL_T2005          0x26
#define STATE_WEAPON_FOIL_A              0x27
#define STATE_WEAPON_FOIL_B              0x28
#define STATE_WEAPON_SABER_OLD           0x29
#define STATE_WEAPON_SABER_T2005         0x2A
#define STATE_WEAPON_SABER_A             0x2B
#define STATE_WEAPON_SABER_B             0x2C
#define STATE_WEAPON_EPEE_T2005          0x2D
#define STATE_WEAPON_EPEE_A              0x2E
#define STATE_WEAPON_EPEE_B              0x2F
#define STATE_WEAPON_EPEE_C              0x30

// Mode modes
#define MODE_1                           0x4F
#define MODE_2                           0x50
#define MODE_3                           0x51
#define MODE_4                           0x52
#define MODE_5                           0x53
#define MODE_6                           0x54
#define MODE_7                           0x55

/**********************
** Computer signals
***********************/
// Score control signals
#define COM_SCORE_RED_INC                0x31
#define COM_SCORE_GREEN_INC              0x32
#define COM_SCORE_RED_DEC                0x33
#define COM_SCORE_GREEN_DEC              0x34

// clock control signals
#define COM_CLOCK_START                  0x35
#define COM_CLOCK_STOP                   0x36
#define COM_CLOCK_TOGGLE                 0x37
#define COM_MIN_INC                      0x38
#define COM_MIN_DEC                      0x39
#define COM_SEC_INC                      0x3A
#define COM_SEC_DEC                      0x3B

// Card control
#define COM_REDCARD_RED                  0x3C
#define COM_REDCARD_GREEN                0x3D
#define COM_WITHDRAW_REDCARD_RED         0x3E
#define COM_WITHDRAW_REDCARD_GREEN       0x3F
#define COM_YELLOWCARD_RED               0x40
#define COM_YELLOWCARD_GREEN             0x41
#define COM_WITHDRAW_YELLOWCARD_RED      0x42
#define COM_WITHDRAW_YELLOWCARD_GREEN    0x43

// Priority control
#define COM_PRIORITY_GREEN               0x44
#define COM_PRIORITY_RED                 0x45
#define COM_PRIORITY_AUTO                0x46
#define COM_PRIORITY_NONE                0x47

// Period control
#define COM_PERIOD_ADVANCE               0x48
#define COM_PERIOD_REVERT                0x49

// Mode control
#define COM_MODE_SET                     0x4A

// General control
#define COM_RESET                        0x4B
#define COM_REARM                        0x4C
#define COM_TIMESCORE_TOGGLE             0x4D

// Weapon control
#define COM_SET_WEAPON                   0x4E

#define COM_SCORE_RED_SET                0x58
#define COM_SCORE_GREEN_SET              0x59
#define COM_CLOCK_SET_MIN                0x5A
#define COM_CLOCK_SET_SEC                0x5B

#define BOX_FRAMING_ERROR                0x5C
#define BOX_OVERRUN_ERROR                0x5D

// Last used signal value 0x5D

#endif
