/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Implementation thread to perform communications with the JBox
**********************************************************************
* FileName:        serialthread.cpp
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

#include "SerialThread.h"

/*
*  Construct the thread with the given port
*/
SerialThread::SerialThread(QextSerialPort* port, QObject* parent) : QThread(parent)
{
    this->port = port;
    stopped = false;
}

/*
*  Continually monitor the box for incoming signals on the serial port
*/
void SerialThread::run( )
{
    assert( port->isOpen());
    
	char c[2];
	while( true)
	{
        stopMutex.lock();
        if( !stopped)
        {
            if( port->bytesAvailable( ) > 0)
		    {
                port->readLine(c, 2);
                emit signalReceived( c[0]);
		    }
        }
        else
            break;
        stopMutex.unlock();
	}
}

void SerialThread::stop( )
{
    stopMutex.lock();
    stopped = true;
    stopMutex.unlock();
}
    
