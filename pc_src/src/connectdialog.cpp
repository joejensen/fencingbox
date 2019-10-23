/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Declaration of the connect dialogue
**********************************************************************
* FileName:        connectdialog.cpp
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
#include <QtGui>
#include "./qextserialport/qextserialenumerator.h"
#include "./qextserialport/qextserialport.h"
#include "connectdialog.h"

/**
**  Constructor to setup connections
**/
ConnectDialog::ConnectDialog( QWidget* parent) : QDialog( parent)
{
	setupUi( this);

	connect( connectButton, SIGNAL( clicked()), this, SLOT( accept()));
	connect( cancelButton, SIGNAL( clicked()), this, SLOT( reject()));
	connect( comboBox, SIGNAL( currentIndexChanged(int index)), this, SLOT( boxChanged()));
	
	// Enumerate available ports and add to combobox
	QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
	for (int i = 0; i < ports.size(); i++)
	    comboBox->addItem( tr(ports.at(i).friendName.toLocal8Bit().constData()), ports.at(i).portName.toLocal8Bit().constData());
 
    // Enable connect button if the initial selection is valid
    boxChanged();
}

/**
**  Text has changed so we need to enable the connect dialogue?
**/
void ConnectDialog::boxChanged()
{
     if( comboBox->currentIndex() != -1)
         connectButton->setEnabled( true);
}

/*
*  Gets the name of a selected port
*/
QString ConnectDialog::getPortName()
{
    assert( result() == QDialog::Accepted);
    
    return comboBox->itemData( comboBox->currentIndex()).toString();
}
