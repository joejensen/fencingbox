/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Main window of the JBox interface implementation
**********************************************************************
* FileName:        mainwindow.cpp
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
#include "mainwindow.h"
#include "aboutdialog.h"
#include "licensedialog.h"
#include "connectdialog.h"
#include "JBox.h"

/**
** constructor for the main window
**/
MainWindow::MainWindow( QWidget* parent) : QMainWindow( parent)
{
	setupUi( this);
	
	// Set up connections from menu items
	actionAbout->connect( actionAbout, SIGNAL(triggered()), this, SLOT(about()));
	actionOpen->connect( actionOpen, SIGNAL( triggered()), this, SLOT( open()));
	actionSave->connect( actionSave, SIGNAL( triggered()), this, SLOT( save()));
	actionSaveAs->connect( actionSaveAs, SIGNAL( triggered()), this, SLOT( saveAs()));
	actionConnect->connect( actionConnect, SIGNAL( triggered()), this, SLOT( connectToBox()));
	actionDisconnect->connect( actionDisconnect, SIGNAL( triggered()), this, SLOT( disconnectBox()));
	actionLoad->connect( actionLoad, SIGNAL( triggered()), this, SLOT( load()));
	actionWrite->connect( actionWrite, SIGNAL( triggered()), this, SLOT( write()));
	actionExit->connect( actionExit, SIGNAL( triggered()), this, SLOT( close()));
	actionLicense->connect( actionLicense, SIGNAL( triggered()), this, SLOT( license()));
	
	// initialize magic version number for files
	MagicNumber = 0xDEADBEEF;
	
	// Add mode and weapon setting choices
	modeBox->addItem( "Pool Bout");
	modeBox->addItem( "Standard DE Bout");
	modeBox->addItem( "Manual Rearm Pool");
	modeBox->addItem( "Manual Rearm DE Bout");
	modeBox->addItem( "Practice");
	modeBox->addItem( "Custom A");
	modeBox->addItem( "Custom B");
	
	weaponBox->addItem( "Foil");
	weaponBox->addItem( "Epee");
	weaponBox->addItem( "Saber");
}

/*
*  Destructor to make sure we disconnect before closing
*/
MainWindow::~MainWindow()
{
    disconnect();
}

/*
*  Checks if files have been modified before closing
*/
bool MainWindow::okToContinue( )
{
	if( isWindowModified( ))
	{
        // Display prompt to save, cancel, or quit
		int r = QMessageBox::warning(this, tr("Settings Modified!"), tr("The Box Settings have been modified.\nDo you want to save your changes?"),
			QMessageBox::Yes | QMessageBox::Default, QMessageBox::No, QMessageBox::Cancel | QMessageBox::Escape);

		if( r == QMessageBox::Yes)
			return save( );
		else if( r == QMessageBox::Cancel)
			return false;
		else
			return true;
	}
	return true;
}

/*
*  Selects and opens file to load settings from
*/
void MainWindow::open( )
{
	if( okToContinue( ))
	{
        // Display file select dialog
		QString fileName = QFileDialog::getOpenFileName( this, tr("Open Settings File"), ".", tr("JBox Files (*.jbs)"));

        // make sure it isnt empt and open file
		if( !fileName.isEmpty())
			loadFile( fileName );
	}
}

/*
*  extracts file bytes into the setting fields
*/
bool MainWindow::loadFile(  const QString &fileName)
{
    // open the given file
	QFile file( fileName);
	
	// make sure open succeeded
	if( !file.open(QIODevice::ReadOnly))
	{
		QMessageBox::warning( this, tr("JBox Settings"), tr( "Cannot read file %1:\n%2.").arg(file.fileName()).arg(file.errorString()));
		return false;
	}
	// create a byte stream and select file version
	QDataStream in(&file);
	in.setVersion(QDataStream::Qt_4_1);
	
	// Check magic number
	quint32 magic;
	in >> magic;
	if( magic != MagicNumber)
	{
		QMessageBox::warning( this, tr("JBox Setting"), tr("The file is not a valid setting file."));
		return false;
	}

    // variables to hold loaded settings
	quint8 byte;
	QByteArray setting;
	
	// Activate waiting cursor
	QApplication::setOverrideCursor(Qt::WaitCursor);
	
	// Load timing settings
    for( int i = 0; i < 21; i++)
	{
		in >> byte;
		setting[i] = byte;
	}
	foilOld->setSetting( setting);

	for( int i = 0; i < 21; i++)
	{
		in >> byte;
		setting[i] = byte;
	}
	foilT2005->setSetting( setting);

	for( int i = 0; i < 21; i++)
	{
		in >> byte;
		setting[i] = byte;
	}
	foilCustomA->setSetting( setting);

	for( int i = 0; i < 21; i++)
	{
		in >> byte;
		setting[i] = byte;
	}
	foilCustomB->setSetting( setting);

	for( int i = 0; i < 10; i++)
	{
		in >> byte;
		setting[i] = byte;
	}
	saberOld->setSetting( setting);

	for( int i = 0; i < 10; i++)
	{
		in >> byte;
		setting[i] = byte;
	}
	saberT2005->setSetting( setting);

	for( int i = 0; i < 10; i++)
	{
		in >> byte;
		setting[i] = byte;
	}
	saberCustomA->setSetting( setting);

	for( int i = 0; i < 10; i++)
	{
		in >> byte;
		setting[i] = byte;
	}
	saberCustomB->setSetting( setting);

    // restore cursor
	QApplication::restoreOverrideCursor();

    // set our current active file name
	setCurrentFile( fileName);
	
	return true;
}

/*
*  Generates a ByteArray of current settings and saves it to file
*/
bool MainWindow::saveFile(  const QString &fileName)
{
    // Open file
	QFile file( fileName);
	
	// ensure the open succeeded
	if( !file.open( QIODevice::WriteOnly))
	{
		QMessageBox::warning( this, tr("JBoxSetting"), tr("Cannot write file %1:\n%2.").arg( file.fileName()).arg( file.errorString()));
		return false;
	}

    // create readable stream and set version
	QDataStream out( &file);
	out.setVersion( QDataStream::Qt_4_1);

    // write software version number
	out << quint32( MagicNumber);
	
	// waiting cursor
	QApplication::setOverrideCursor( Qt::WaitCursor);

    // temporary string for settings
	QByteArray settings;
	
	// write timing settings
	settings = foilOld->generateSetting( );
	for( int i = 0; i < 21; i++)
	{
		out << quint8(settings[i]);
	}

	settings = foilT2005->generateSetting( );
	for( int i = 0; i < 21; i++)
	{
		out << quint8(settings[i]);
	}

	settings = foilCustomA->generateSetting( );
	for( int i = 0; i < 21; i++)
	{
		out << quint8(settings[i]);
	}

	settings = foilCustomB->generateSetting( );
	for( int i = 0; i < 21; i++)
	{
		out << quint8(settings[i]);
	}

	settings = saberOld->generateSetting( );

	for( int i = 0; i < 10; i++)
	{
		out << quint8(settings[i]);
	}

	settings = saberT2005->generateSetting( );
	for( int i = 0; i < 10; i++)
	{
		out << quint8(settings[i]);
	}

	settings = saberCustomA->generateSetting( );
	for( int i = 0; i < 10; i++)
	{
		out << quint8(settings[i]);
	}

	settings = saberCustomB->generateSetting( );
	for( int i = 0; i < 10; i++)
	{
		out << quint8(settings[i]);
	}

    // restore normal cursor
	QApplication::restoreOverrideCursor( );
	
	// set our currently active file
	setCurrentFile( fileName);
	
	return true;

}

/*
*  Saves all mode and timing settings to a file
*/
bool MainWindow::save( )
{
    // determine if we active a currently active file, if not prompt to select one
	if( curFile.isEmpty())
		return saveAs( );
	else
		return saveFile( curFile);
}

/*
*  Allows to select a new storage location and name to store settings
*/
bool MainWindow::saveAs( )
{
    // prompt for new file location
	QString fileName = QFileDialog::getSaveFileName( this, tr("Save Settings"), ".", tr("JBox Files (*.jbs)"));

    // make sure user selected something
	if( fileName.isEmpty())
		return false;
		
	return saveFile( fileName);
}

/*
*  Allows the user to select a serial port to try and connect to a JBox with
*/
void MainWindow::connectToBox( )
{
    // create and display the connect dialogue
	ConnectDialog dialog;
	dialog.exec( );

    if( dialog.result() == QDialog::Accepted)
    {
        // connect signals coming from the box
        connect(JBox::getInstance(), 
            SIGNAL( redCardSignal( JBox::Fencer, bool)), this, SLOT( setRedCard( JBox::Fencer, bool)));
	    connect(JBox::getInstance(), 
            SIGNAL( yellowCardSignal( JBox::Fencer, bool)), this, SLOT( setYellowCard( JBox::Fencer, bool)));
        connect(JBox::getInstance(), 
            SIGNAL( prioritySignal( JBox::Fencer, bool)), this, SLOT( setPriority( JBox::Fencer, bool)));
        connect(JBox::getInstance(), 
            SIGNAL( scoreSignal( JBox::Fencer, char)), this, SLOT( setScore( JBox::Fencer, char)));
	    connect(JBox::getInstance(), 
            SIGNAL( minuteSignal( char)), this, SLOT( setMinutes( char)));
	    connect(JBox::getInstance(), 
            SIGNAL( secondSignal( char)), this, SLOT( setSeconds( char)));
    	connect(JBox::getInstance(), 
            SIGNAL( timingSignal( char)), this, SLOT( settiming( char)));
    	connect(JBox::getInstance(), 
            SIGNAL( weaponSignal( JBox::Weapon)), this, SLOT( setWeapon( JBox::Weapon)));
    	connect(JBox::getInstance(), 
            SIGNAL( modeSignal( char)), this, SLOT( setMode( char)));
    	connect(JBox::getInstance(), 
            SIGNAL( OnTargetSignal( JBox::Fencer)), this, SLOT( setOnTargetLight( JBox::Fencer)));
    	connect(JBox::getInstance(), 
            SIGNAL( OffTargetSignal( JBox::Fencer)), this, SLOT( setOffTargetLight( JBox::Fencer)));
    	connect(JBox::getInstance(), 
            SIGNAL( groundSignal( JBox::Fencer)), this, SLOT( setGroundLight( JBox::Fencer)));
    	connect(JBox::getInstance(), 
            SIGNAL( genericSignal( const QString&)), signalBox, SLOT( displaySignal( const QString&)));
            
        // connect signals to the box
        
        // tell the box wrapper what to connect to
        JBox::getInstance()->connectToBox( dialog.getPortName());
    }
}

/*
*  Allows the user to terminate all serial connections
*/
void MainWindow::disconnectBox( )
{
    // disconnect signals coming from the box
    disconnect(JBox::getInstance(), 
        SIGNAL( redCardSignal( JBox::Fencer, bool)), this, SLOT( setRedCard( JBox::Fencer, bool)));
	disconnect(JBox::getInstance(), 
        SIGNAL( yellowCardSignal( JBox::Fencer, bool)), this, SLOT( setYellowCard( JBox::Fencer, bool)));
    disconnect(JBox::getInstance(), 
        SIGNAL( prioritySignal( JBox::Fencer, bool)), this, SLOT( setPriority( JBox::Fencer, bool)));
    disconnect(JBox::getInstance(), 
        SIGNAL( scoreSignal( JBox::Fencer, char)), this, SLOT( setScore( JBox::Fencer, char)));
	disconnect(JBox::getInstance(), 
        SIGNAL( minuteSignal( char)), this, SLOT( setMinutes( char)));
	disconnect(JBox::getInstance(), 
        SIGNAL( secondSignal( char)), this, SLOT( setSeconds( char)));
    disconnect(JBox::getInstance(), 
        SIGNAL( timingSignal( char)), this, SLOT( settiming( char)));
    disconnect(JBox::getInstance(), 
        SIGNAL( weaponSignal( JBox::Weapon)), this, SLOT( setWeapon( JBox::Weapon)));
    disconnect(JBox::getInstance(), 
        SIGNAL( modeSignal( char)), this, SLOT( setMode( char)));
    disconnect(JBox::getInstance(), 
        SIGNAL( OnTargetSignal( JBox::Fencer)), this, SLOT( setOnTargetLight( JBox::Fencer)));
    disconnect(JBox::getInstance(), 
        SIGNAL( OffTargetSignal( JBox::Fencer)), this, SLOT( setOffTargetLight( JBox::Fencer)));
    disconnect(JBox::getInstance(), 
        SIGNAL( groundSignal( JBox::Fencer)), this, SLOT( setGroundLight( JBox::Fencer)));
    disconnect(JBox::getInstance(), 
        SIGNAL( genericSignal( const QString&)), signalBox, SLOT( displaySignal( const QString&)));
        
    // disconnect signals going to the box
    
    // tell the box wrapper to disconnect from the serial port
    JBox::getInstance()->disconnectBox();
}

/*
*  Loads the mode and timing settings from the box
*/
bool MainWindow::loadSettings( )
{
	return true;
}

/*
*  Uploads all mode and timing settings to the box
*/
bool MainWindow::writeSettings( )
{
	return true;
}

/*
*  Displays the about dialogue
*/
void MainWindow::about( )
{
	AboutDialog dialog( this);
	dialog.exec();
}

/*
*  Display the GNU GPL license agreement
*/
void MainWindow::license( )
{
	LicenseDialog dialog( this);
	dialog.exec();
}

/*
*  Allows the user to terminate the program
*/
void MainWindow::closeEvent( QCloseEvent* event)
{
	if( okToContinue( ))
		event->accept();
	else
		event->ignore();
}

/*
*  Sets the current file our settings are to be stored in
*/
void MainWindow::setCurrentFile( const QString& fileName)
{
	curFile = fileName;
	setWindowModified(false);

	QString shownName = "Untitled";
	if( !curFile.isEmpty())
		shownName = QFileInfo( curFile).fileName();
	setWindowTitle( tr("%1[*] - %2").arg( shownName).arg( tr("JBox Manager")));

}

void MainWindow::setRedCard( JBox::Fencer side, bool card)
{
    if( side == JBox::Red && card)
        redRedCard->setCheckState( Qt::Checked);
    else if( side == JBox::Red && !card)
        redRedCard->setCheckState( Qt::Unchecked);
    else if( side == JBox::Green && card)
        greenRedCard->setCheckState( Qt::Checked);
    else if( side == JBox::Green && !card)
        greenRedCard->setCheckState( Qt::Unchecked);
}

void MainWindow::setYellowCard( JBox::Fencer side, bool card)
{
    if( side == JBox::Red && card)
        redYellowCard->setCheckState( Qt::Checked);
    else if( side == JBox::Red && !card)
        redYellowCard->setCheckState( Qt::Unchecked);
    else if( side == JBox::Green && card)
        greenYellowCard->setCheckState( Qt::Checked);
    else if( side == JBox::Green && !card)
        greenYellowCard->setCheckState( Qt::Unchecked);
}

void MainWindow::setPriority( JBox::Fencer side, bool card)
{
    if( side == JBox::Red && card)
        redPriority->setCheckState( Qt::Checked);
    else if( side == JBox::Red && !card)
        redPriority->setCheckState( Qt::Unchecked);
    else if( side == JBox::Green && card)
        greenPriority->setCheckState( Qt::Checked);
    else if( side == JBox::Green && !card)
        greenPriority->setCheckState( Qt::Unchecked);
}

void MainWindow::setScore( JBox::Fencer side, char score)
{
    if( side == JBox::Red)
        redScore->setValue( score);
    else
        greenScore->setValue( score);
}


void MainWindow::setMinute( char minute)
{ 
    QTime curr = timeBox->time();

    QTime* newTime = new QTime( 0, minute, curr.second(), curr.msec());
    timeBox->setTime( *newTime);
    delete newTime;
}

void MainWindow::setSecond( char seconds)
{
    QTime curr = timeBox->time();

    QTime* newTime = new QTime( 0, curr.minute(), seconds, curr.msec());
    timeBox->setTime( *newTime);
    delete newTime;
}

void MainWindow::setTiming( char timing)
{
    return;   
}

void MainWindow::setWeapon( JBox::Weapon weap)
{
    return;   
}

void MainWindow::setMode( char mode)
{
    return;   
}

void MainWindow::setOnTargetLight( JBox::Fencer side)
{
    return;   
}

void MainWindow::setOffTargetLight( JBox::Fencer side)
{
    return;   
}

void MainWindow::setGroundLight( JBox::Fencer side)
{
    return;   
}

