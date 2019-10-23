/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Declaration of connect dialogue
**********************************************************************
* FileName:        connectdialog.h
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
#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H
#include <QDialog>
#include "ui_connectdialog.h"

class ConnectDialog : public QDialog, public Ui::ConnectDialog
{
	Q_OBJECT
public:
	ConnectDialog( QWidget* parent = 0);
	QString getPortName( );
	
private slots:
	void boxChanged();
};



#endif

