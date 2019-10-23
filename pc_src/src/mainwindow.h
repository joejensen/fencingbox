/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Declaration of interface's main window
**********************************************************************
* FileName:        mainwindow.h
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "SerialThread.h"
#include "JBox.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT

public:
	MainWindow( QWidget* parent = 0);
	~MainWindow();

protected:
	void closeEvent( QCloseEvent* event);

public slots:
	void open( );
	bool save( );
	bool saveAs( );
	void connectToBox( );
	void disconnectBox( );
	bool loadSettings( );
	bool writeSettings( );
	void about( );
	void license( );
	void setRedCard( JBox::Fencer side, bool card);
	void setYellowCard( JBox::Fencer side, bool card);
	void setPriority( JBox::Fencer side, bool card);
	void setScore( JBox::Fencer side, char score);
    void setMinute( char minute);
    void setSecond( char seconds);
    void setTiming( char timing);
    void setWeapon( JBox::Weapon weap);
    void setMode( char mode);
    void setOnTargetLight( JBox::Fencer side);
    void setOffTargetLight( JBox::Fencer side);
    void setGroundLight( JBox::Fencer side);
	
private:
	bool okToContinue( );
	bool loadFile( const QString &fileName);
	bool saveFile( const QString &fileName);
	void setCurrentFile( const QString &fileName);

	QString curFile;
	quint32 MagicNumber;
};

#endif
