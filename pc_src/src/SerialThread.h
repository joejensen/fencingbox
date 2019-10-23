/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Declaration of thread to communicate with the JBox
**********************************************************************
* FileName:        serialthread.h
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
#ifndef SERIALTHREAD_H_
#define SERIALTHREAD_H_

#include <QThread>
#include "qextserialport/qextserialport.h"

class SerialThread : public QThread
{
	Q_OBJECT

public:
	SerialThread( QextSerialPort* port, QObject* parent = 0);
	void stop( );
	void run();

signals:
	void signalReceived( const char message);

private:
	QextSerialPort* port;
	QMutex stopMutex;
	volatile bool stopped;

};
#endif
