/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Declaration of singleton class for managing interaction with a JBox
**********************************************************************
* FileName:        jbox.h
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
#ifndef JBOX_H_
#define JBOX_H_

#include <string>
#include "SerialThread.h"
#include "./qextserialport/qextserialport.h"

class JBox : public QObject
{
    Q_OBJECT
    
public:
    enum Fencer{ Red, Green};
    enum Weapon{ Foil, Epee, Saber};
        
    ~JBox( );
    
    static JBox* getInstance( );
    
    // Box state getters
    bool isRedCard( JBox::Fencer side);
    bool isYellowCard( JBox::Fencer side);
    bool isPriority( JBox::Fencer side);
    char getScore( JBox::Fencer side);
    char getMinute();
    char getSeconds();
    char getTiming();
    char getmode();
    
    // Signal Mapping functions
    QString translateMessage( char message);
    
    //connection management functions
    bool connectToBox( QString portname);
    bool disconnectBox();

// Signals
signals:
    void redCardSignal( JBox::Fencer side, bool card);
    void yellowCardSignal( JBox::Fencer side, bool card);
    void prioritySignal( JBox::Fencer side, bool card);
    void scoreSignal( JBox::Fencer side, char score);
    void minuteSignal( char minute);
    void secondSignal( char seconds);
    void timingSignal( char timing);
    void weaponSignal( JBox::Weapon weap);
    void modeSignal( char mode);
    void onTargetSignal( JBox::Fencer side);
    void offTargetSignal( JBox::Fencer side);
    void groundSignal( JBox::Fencer side);
    void genericSignal( const QString& message);
        
public slots:
    void setRedCard( JBox::Fencer side, bool card);
    void setYellowcard( JBox::Fencer side, bool card);
    void setPriority( JBox::Fencer side, bool card);
    void setScore( JBox::Fencer side, char score);
    void setMinute( char minute);
    void setSeconds(char seconds);
    void setTiming( char timing);
    void setMode( char mode);
    
    void receiveMessage( const char message);
        
protected:
    JBox( QWidget *parent = 0);
    
private:
    static JBox*    instance;
    QextSerialPort* port;
    SerialThread*    boxThread;
};

#endif
