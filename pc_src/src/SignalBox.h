/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* declare a class to display signals to/from a box
**********************************************************************
* FileName:        signalbox.h
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
#ifndef SIGNALBOX_H
#define SIGNALBOX_H

#include <QFrame>
#include "ui_signalbox.h"
#include "SerialThread.h"
#include "./qextserialport/qextserialport.h"

class SignalBox : public QFrame, public Ui::SignalBox
{
	Q_OBJECT

public:
	SignalBox( QWidget* parent = 0);

public slots:
	void displaySignal( const QString& signal);

private:
};

#endif
