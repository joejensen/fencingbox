/*********************************************************************
*
*                JBox PC Interface
*
**********************************************************************
* Implementation of dialogue class to display about and license info
**********************************************************************
* FileName:        aboutdialg.cpp
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

#include "aboutdialog.h"
#include "licensedialog.h"

/**
**  Constructor to setup connections
**/
AboutDialog::AboutDialog( QWidget* parent) : QDialog( parent)
{
	setupUi( this);

	connect( okButton, SIGNAL( clicked()), this, SLOT( accept()));
	connect( licenseButton, SIGNAL( clicked()), this, SLOT( showLicense()));
}

/**
**  Function to show the license page
**/
void AboutDialog::showLicense( )
{
	LicenseDialog dialog(this);
	dialog.exec();
}

