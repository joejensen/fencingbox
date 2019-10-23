/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Singleton class for managing all interaction with a JBox
**********************************************************************
* FileName:        jbox.cpp
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
#include "JBox.h"
#include "messages.h"
#include <QtGui>

JBox* JBox::instance = 0; // initialize pointer

/*
*  Get the existing JBox object or create a new one
*/
JBox* JBox::getInstance()
{
    if( instance == 0)
        return (instance = new JBox());
    else
        return instance;
}

/*
*  Construct a new unconnected instance of the box
*/
JBox::JBox( QWidget* parent) : QObject(parent)
{
    port = NULL;
    boxThread = NULL;
    
    return;
}

/*
*  Destroys any dynamic objects controlled by the JBox class
*/
JBox::~JBox( )
{
    disconnectBox();
}

/*
*  Determines if a red card has been awarded to side
*/
bool JBox::isRedCard( JBox::Fencer side)
{
    return false;
}

/*
*  Determines if a yellow card has been awarded to side
*/
bool JBox::isYellowCard( JBox::Fencer side)
{
    return false;
}

/*
*  Determines if side has priority or not
*/
bool JBox::isPriority( JBox::Fencer side)
{
    return false;
}

/*
*  Gets the value of  sides current score
*/
char JBox::getScore( JBox::Fencer side)
{
    return 0;
}

/*
*  Gets the current minute from the box
*/
char JBox::getMinute()
{
    return 0;
}
 
/*
*  Gets the number of seconds remaining from the clock
*/
char JBox::getSeconds()
{
    return 0;
}

/*
*  Gets the byte code for the currently acitve timing
*/
char JBox::getTiming()
{
    return 0;
}

/*
*  Gets the code for the currently active mode
*/
char JBox::getmode()
{
    return 0;
}

/*
*  Sets or clears the Red Card light for the appropriate fencer
*/
void JBox::setRedCard( Fencer side, bool card)
{
    if( side == JBox::Red && card)
        port->putChar( COM_REDCARD_RED);
    else if( side == JBox::Red && !card)
        port->putChar( COM_WITHDRAW_REDCARD_RED);
    else if( side == JBox::Green && card)
        port->putChar( COM_REDCARD_GREEN);
    else if( side == JBox::Green && !card)
        port->putChar( COM_WITHDRAW_REDCARD_GREEN);
}

/*
*  Sets or clears the yellow card light for the appropriate fencer
*/
void JBox::setYellowcard( Fencer side, bool card)
{
    if( side == JBox::Red && card)
        port->putChar( COM_YELLOWCARD_RED);
    else if( side == JBox::Red && !card)
        port->putChar( COM_WITHDRAW_YELLOWCARD_RED);
    else if( side == JBox::Green && card)
        port->putChar( COM_YELLOWCARD_GREEN);
    else if( side == JBox::Green && !card)
        port->putChar( COM_YELLOWCARD_GREEN);
}

/*
*  Sets or clears priority for the appropriate fencer
*  TODO: Add functionality for clearing individual priorities1
*/
void JBox::setPriority( Fencer side, bool card)
{
    if( side == JBox::Red && card)
        port->putChar( COM_PRIORITY_RED);
    else if( side == JBox::Red && !card)
    {
        port->putChar( COM_PRIORITY_NONE);
    }
    else if( side == JBox::Green && card)
        port->putChar( COM_PRIORITY_GREEN);
    else if( side == JBox::Green && !card)
    {
        port->putChar( COM_PRIORITY_NONE);
    }
}

/*
*  Sends a set score command and the score value
*/
void JBox::setScore( Fencer side, char score)
{
    if( side == Red)
        port->putChar( COM_SCORE_RED_SET);
    else
        port->putChar( COM_SCORE_GREEN_SET);
        
    port->putChar( score);
}
 
/*
*  Sends a command byte followed by a value byte to set the minute
*/
void JBox::setMinute( char minute)
{
    port->putChar( COM_CLOCK_SET_MIN);
    port->putChar( minute);
}

/*
*  Sends a command byte and 2 value bytes to set the second count
*/
void JBox::setSeconds(char seconds)
{
    port->putChar( COM_CLOCK_SET_SEC);
    port->putChar( (seconds/10) % 10 );
    port->putChar( seconds % 10 );
}
 
/*
*  Sends a set command and then the timing code
*/
void JBox::setTiming( char timing)
{
    port->putChar( COM_SET_WEAPON);
    port->putChar( timing);
}
 
/*
*  Sends set command followed by mode
*/
void JBox::setMode( char mode)
{
    port->putChar( COM_MODE_SET);
    port->putChar( mode);
}

/*
*  Translates a received message code into a descriptive string
* TODO: This is a horribly inefficient function: change to array of string
*         and have this function just map to correct slot in array
*/
QString JBox::translateMessage( char message)
{
    switch( message)
    {
        case REM_SCORE_RED_INC: return tr( "Remote used to increment Red's Score");
        case REM_SCORE_GREEN_INC: return tr( "Remote used to increment Green's Score");
        case REM_SCORE_RED_DEC: return tr( "Remote used to decrement Red's Score");
        case REM_SCORE_GREEN_DEC: return tr( "Remote used to decrement Green's Score");
        case REM_CLOCK_START: return tr( "Remote used to start clock");
        case REM_CLOCK_STOP: return tr( "Remote used to stop clock");
        case REM_CLOCK_TOGGLE: return tr( "Remote used to toggle clock");
        case REM_MIN_INC: return tr( "Remote used to increment minutes remaining");
        case REM_MIN_DEC: return tr( "Remote used to decrement minutes remaining");
        case REM_SEC_INC: return tr( "Remote used to increment seconds remaining");
        case REM_SEC_DEC: return tr( "Remote used to decrement seconds remaining");
        case REM_REDCARD_RED: return tr( "Remote used to issue red card to fencer on left");
        case REM_REDCARD_GREEN: return tr( "Remote used to issue red card to fencer on right");
        case REM_WITHDRAW_REDCARD_RED: return tr( "Remote used to withdraw red card from fencer on left");
        case REM_WITHDRAW_REDCARD_GREEN: return tr( "Remote used to withdraw red card from fencer on right");
        case REM_YELLOWCARD_RED: return tr( "Remote used to issue yellow card to fencer on left");
        case REM_YELLOWCARD_GREEN: return tr( "Remote used to issue yellow card to fencer on right");
        case REM_WITHDRAW_YELLOWCARD_RED: return tr( "Remote used to withdraw yellow card from fencer on left");
        case REM_WITHDRAW_YELLOWCARD_GREEN: return tr( "Remote used to withdraw yellow card from fencer on right");
        case REM_PRIORITY_GREEN: return tr( "Remote used to award priority to fencer on right");
        case REM_PRIORITY_RED: return tr( "Remote used to award priority to fencer on left");
        case REM_PRIORITY_AUTO: return tr( "Remote used to automatically award priority");
        case REM_PRIORITY_NONE: return tr( "Remote used to withdraw priority");
        case REM_PERIOD_ADVANCE: return tr( "Remote used to advance period");
        case REM_PERIOD_REVERT: return tr( "Remote used to return to previous period");
        case REM_MODE_ADVANCE: return tr( "Remote used to advance box mode");
        case REM_RESET: return tr( "Remote used to reset the box");
        case REM_REARM: return tr( "Remote used to rearm the box");
        case REM_TIMESCORE_TOGGLE: return tr( "Remote used to toggle between time and score editing mode");
        case REM_WEAPON_ADVANCE: return tr( "Remote used to advance weapon and timing selection");
        case FENCE_TOUCH_RED: return tr( "Valid touch detected for left fencer (againt right)");
        case FENCE_TOUCH_GREEN: return tr( "Valid touch detected for right fencer (against left)");
        case FENCE_OFF_RED: return tr( "Off target touch detected for left fencer (against right)");
        case FENCE_OFF_GREEN: return tr( "Off target touch detected for right fencer (against left)");
        case FENCE_GND_RED: return tr( "Red grounding light active");
        case FENCE_GND_GREEN: return tr( "Green grounding light active");
        case FENCE_CLOCK_STOP: return tr( "Clock stopped due to touch");
        case DISP_PRIOR_GREEN: return tr( "Priority awarded to right fencer");
        case DISP_PRIOR_RED: return tr( "Prioirty awarded to left fencer");
        case DISP_PRIOR_NONE: return tr( "Priority removed");
        case STATE_WEAPON_FOIL_OLD: return tr( "Old Foil timings active");
        case STATE_WEAPON_FOIL_T2005: return tr( "T2005 Foil timings active");
        case STATE_WEAPON_FOIL_A: return tr( "Custom A Foil timings active");
        case STATE_WEAPON_FOIL_B: return tr( "Custom B Foil timings active");
        case STATE_WEAPON_SABER_OLD: return tr( "Old Saber timings active");
        case STATE_WEAPON_SABER_T2005: return tr( "T2005 Saber timings active");
        case STATE_WEAPON_SABER_A: return tr( "Custom A Saber timings active");
        case STATE_WEAPON_SABER_B: return tr( "Custom B Saber timings active");
        case STATE_WEAPON_EPEE_T2005: return tr( "Default Epee timings active");
        case STATE_WEAPON_EPEE_A: return tr( "Custom A Epee timings active");
        case STATE_WEAPON_EPEE_B: return tr( "Custom B Epee timings active");
        case STATE_WEAPON_EPEE_C: return tr( "Custom C Epee timings active");
        case MODE_1: return tr( "Mode 1 active");
        case MODE_2: return tr( "Mode 2 active");
        case MODE_3: return tr( "Mode 3 active");
        case MODE_4: return tr( "Mode 4 active");
        case MODE_5: return tr( "Mode 5 active");
        case MODE_6: return tr( "Mode 6 active");
        case MODE_7: return tr( "Mode 7 active");
        case COM_SCORE_RED_INC: return tr( "Computer used to increment Red's score");
        case COM_SCORE_GREEN_INC: return tr( "Computer used to increment Green's score");
        case COM_SCORE_RED_DEC: return tr( "Computer used to decrement Red's score");
        case COM_SCORE_GREEN_DEC: return tr( "Computer used to decrement Green's score");
        case COM_CLOCK_START: return tr( "Computer used to start clock");
        case COM_CLOCK_STOP: return tr( "Computer used to stop clock");
        case COM_CLOCK_TOGGLE: return tr( "Computer usedd to toggle clock");
        case COM_MIN_INC: return tr( "Computer used to increment minutes remaining");
        case COM_MIN_DEC: return tr( "Computer used to decrement minutes remaining");
        case COM_SEC_INC: return tr( "computer used to increment seconds remaining");
        case COM_SEC_DEC: return tr( "Computer used to decrement seconds remaining");
        case COM_REDCARD_RED: return tr( "Computer used to issue red card to left fencer");
        case COM_REDCARD_GREEN: return tr( "Computer used to issue red card to right fencer");
        case COM_WITHDRAW_REDCARD_RED: return tr( "Computer used to withdraw red card from left");
        case COM_WITHDRAW_REDCARD_GREEN: return tr( "Computer used to withdraw red card from right");
        case COM_YELLOWCARD_RED: return tr( "Computer used to issue yellow card to left fencer");
        case COM_YELLOWCARD_GREEN: return tr( "Computer used to issue yellow card to right fencer");
        case COM_WITHDRAW_YELLOWCARD_RED: return tr( "Computer used to withdraw yellow card from left fencer");
        case COM_WITHDRAW_YELLOWCARD_GREEN: return tr( "Computer used to withdraw yellow card from right fencer");
        case COM_PRIORITY_GREEN: return tr( "Computer used to award priority to right");
        case COM_PRIORITY_RED: return tr( "Computer used to award priority to left");
        case COM_PRIORITY_AUTO: return tr( "Computer used to automatically award priority");
        case COM_PRIORITY_NONE: return tr( "Computer used to remove priority");
        case COM_PERIOD_ADVANCE: return tr( "Computer used to advance period");
        case COM_PERIOD_REVERT: return tr( "Computer used to return to previous period");
        case COM_MODE_SET: return tr( "Computer used to set mode");
        case COM_RESET: return tr( "Computer used to reset box");
        case COM_REARM: return tr( "Computer used to rearm box");
        case COM_TIMESCORE_TOGGLE: return tr( "Computer used to toggle time/score setting mode");
        case COM_SET_WEAPON: return tr( "Computer used to set weapon/timing mode");
        case BOX_OVERRUN_ERROR: return tr( "Serial Communication Overrun Error!");
        case BOX_FRAMING_ERROR: return tr( "Serial Communication Framing Error!");
        default: return tr( "Unknown message received( 0x") + QString::number(message, 16).toUpper() + ")";
    };
    
    // just here to eliminate a compiler warning
    return tr("Error:  Invalid code segment executed");
}

/*
*  Connects us to the specified port if possible
*/
bool JBox::connectToBox( QString portname)
{
    // make sure the port is currently closed
    if( port == NULL)
    {
       // Build and open the new port
       port = new QextSerialPort( portname, QextSerialPort::Polling);
	   port->setBaudRate(BAUD57600);
	   port->setFlowControl(FLOW_OFF);
	   port->setParity(PAR_NONE);
	   port->setDataBits(DATA_8);
	   port->setStopBits(STOP_1);
	   port->open(QIODevice::ReadWrite);
	   
	   // Activate a thread to monitor the new port
	   boxThread = new SerialThread( port);
	   
	   // Connect the thread the signal in JBox class and start monitoring port
	   connect( boxThread, SIGNAL(signalReceived( const char)), this, SLOT(receiveMessage( const char)));
	   boxThread->start();
	   return true;
    }
    else
        return false;
}

/*
*  Disconnects from any port we are attached to
*/
bool JBox::disconnectBox()
{
    // Make sure the thread exists so we can disconnect it
    if( boxThread != NULL)
    {
        disconnect( boxThread, SIGNAL( signalreceived( const char)), this, SLOT( receiveMessage( const char)));
        boxThread->stop();
        boxThread->wait();
        delete boxThread;
        boxThread = NULL;
    }
    
    // Make sure we dont try to delete port if it's already been deleted
    if( port != NULL)
    {
        delete port;
        port = NULL;
    }
    
    return true;
}

/*
*  receives bytesize messages from the box and turns them into signals
*  for the gui to use
*/
void JBox::receiveMessage(const char message)
{
    emit genericSignal( translateMessage( message));
    switch( message)
    {
        case COM_REDCARD_RED:
        case REM_REDCARD_RED:
            emit redCardSignal( JBox::Red, true);
            break;
        case COM_REDCARD_GREEN:
        case REM_REDCARD_GREEN:
            emit redCardSignal( JBox::Green, true);
            break;
        case COM_YELLOWCARD_RED:
        case REM_YELLOWCARD_RED:
            emit yellowCardSignal( JBox::Red, true);
            break;
        case COM_YELLOWCARD_GREEN:
        case REM_YELLOWCARD_GREEN:
            emit yellowCardSignal( JBox::Green, true);
            break;
        case COM_WITHDRAW_YELLOWCARD_RED:
        case REM_WITHDRAW_YELLOWCARD_RED:
            emit yellowCardSignal( JBox::Red, false);
            break;
        case COM_WITHDRAW_YELLOWCARD_GREEN:
        case REM_WITHDRAW_YELLOWCARD_GREEN:
            emit yellowCardSignal( JBox::Green, false);
            break;
        case COM_WITHDRAW_REDCARD_RED:
        case REM_WITHDRAW_REDCARD_RED:
            emit redCardSignal( JBox::Red, false);
            break;
        case COM_WITHDRAW_REDCARD_GREEN:
        case REM_WITHDRAW_REDCARD_GREEN:
            emit redCardSignal( JBox::Green, false);
            break;
        case REM_SCORE_RED_INC:
        case COM_SCORE_RED_INC:
            break;
        case REM_SCORE_GREEN_INC:
        case COM_SCORE_GREEN_INC:
            break;
        case REM_SCORE_RED_DEC:
        case COM_SCORE_RED_DEC:
            break;
        case REM_SCORE_GREEN_DEC:
        case COM_SCORE_GREEN_DEC:
            break;
        case REM_CLOCK_START:
        case COM_CLOCK_START:
            break;
        case REM_CLOCK_STOP:
        case COM_CLOCK_STOP:
            break;
        case REM_CLOCK_TOGGLE:
        case COM_CLOCK_TOGGLE:
            break;
        case REM_MIN_INC:
        case COM_MIN_INC:
            break;
        case REM_MIN_DEC:
        case COM_MIN_DEC:
            break;
        case REM_SEC_INC:
        case COM_SEC_INC:
            break;
        case REM_SEC_DEC:
        case COM_SEC_DEC:
            break;
        case REM_PRIORITY_GREEN:
        case COM_PRIORITY_GREEN:
            break;
        case REM_PRIORITY_RED:
        case COM_PRIORITY_RED:
            break;
        case REM_PRIORITY_AUTO:
        case COM_PRIORITY_AUTO:
            break;
        case REM_PRIORITY_NONE:
        case COM_PRIORITY_NONE:
            break;
        case REM_PERIOD_ADVANCE:
        case COM_PERIOD_ADVANCE:
            break;
        case REM_PERIOD_REVERT:
        case COM_PERIOD_REVERT:
            break;
        case REM_MODE_ADVANCE:
            break;
        case COM_MODE_SET:
            break;
        case COM_RESET:
        case REM_RESET:
            break;
        case REM_REARM:
        case COM_REARM:
            break;
        case REM_TIMESCORE_TOGGLE:
        case COM_TIMESCORE_TOGGLE:
            break;
        case REM_WEAPON_ADVANCE:
            break;
        case COM_SET_WEAPON:
            break;
        case FENCE_CLOCK_STOP:
            break;
    };
}
