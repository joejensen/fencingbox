#####################################################################
#
#                JBox PC Interface
#
#*********************************************************************
# Implementation of dialogue class to display about and license info
#*********************************************************************
# FileName:        JBoxManager.pro
# OS:              Tested on Windows XP
# Compiler:        qmake
#
# Software License Agreement
# This file is part of the JBox PC interface.
#
# The JBox PC Interface is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# JBox PC Interface is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with JBox PC Interface.  If not, see <http://www.gnu.org/licenses/>.
#
# Copyright (C) 2007 Joe Jensen (joe@joejensen.com)
# fencingbox.sourceforge.net
######################################################################
TEMPLATE = app
TARGET += 
DEPENDPATH += .
INCLUDEPATH += ./src
QMAKE_LIBDIR += ./libs
OBJECTS_DIR    = ./obj
MOC_DIR        = ./moc
UI_DIR         = ./uic

# Input
HEADERS += ./src/aboutdialog.h \
           ./src/connectdialog.h \
           ./src/epeetimingbox.h \           
           ./src/foiltimingbox.h \           
           ./src/licensedialog.h \           
           ./src/mainwindow.h \           
           ./src/modebox.h \           
           ./src/sabertimingbox.h \
           ./src/SignalBox.h \
	   ./src/SerialThread.h \
           ./src/JBox.h \
           ./src/messages.h
           
FORMS += ./ui/aboutdialog.ui \         
      ./ui/connectdialog.ui \         
      ./ui/epeetimingbox.ui \         
      ./ui/foiltimingbox.ui \         
      ./ui/licensedialog.ui \         
      ./ui/mainwindow.ui \         
      ./ui/modebox.ui \         
      ./ui/sabertimingbox.ui \
      ./ui/SignalBox.ui

SOURCES += ./src/aboutdialog.cpp \
          ./src/connectdialog.cpp \
           ./src/epeetimingbox.cpp \           
           ./src/foiltimingbox.cpp \           
           ./src/licensedialog.cpp \           
           ./src/main.cpp \           
           ./src/mainwindow.cpp \           
           ./src/modebox.cpp \           
           ./src/sabertimingbox.cpp \
           ./src/SignalBox.cpp \
           ./src/SerialThread.cpp \
	   ./src/JBox.cpp

CONFIG(debug, debug|release):LIBS  += -lqextserialportd
else:LIBS  += -lqextserialport

unix:DEFINES   = _TTY_POSIX_
win32:DEFINES  = _TTY_WIN_
