# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/Qt_MinGW-Windows
TARGET = GProxy
VERSION = 2.2
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
QT = core gui network
SOURCES += source/thread/GproxyUpdateThread.cpp source/socket.cpp source/thread/DownloadThread.cpp source/GhostGrazLogininformationDialog.cpp source/Packet.cpp source/statspage/Statspage.cpp source/widget/ClickableListWidget.cpp source/widget/ClickableLineEdit.cpp source/bnetprotocol.cpp source/Slot.cpp source/bnet.cpp source/Player.cpp source/thread/SleepThread.cpp source/ConfigGUI.cpp source/color/ColoredMessage.cpp source/Config.cpp source/gameprotocol.cpp source/delegate/GamelistDelegate.cpp source/delegate/ChannellistDelegate.cpp source/MainGUI.cpp source/widget/MTextEdit.cpp source/color/ColorUtil.cpp source/commandpacket.cpp source/widget/MButton.cpp source/Util.cpp source/widget/MColorDialog.cpp source/gpsprotocol.cpp source/gproxy.cpp source/bncsutilinterface.cpp
HEADERS += source/widget/MTextEdit.h source/commandpacket.h source/gproxy.h source/ConfigGUI.h source/GhostGrazLogininformationDialog.h source/thread/GproxyUpdateThread.h source/gpsprotocol.h source/widget/MColorDialog.h source/widget/MButton.h source/bnet.h source/gameprotocol.h source/Packet.h source/widget/ClickableLineEdit.h source/statspage/Statspage.h source/bnetprotocol.h source/Util.h source/Config.h source/thread/SleepThread.h source/color/ColorUtil.h source/MainGUI.h source/Slot.h source/delegate/ChannellistDelegate.h source/Player.h source/thread/DownloadThread.h source/delegate/GamelistDelegate.h source/socket.h source/widget/ClickableListWidget.h source/color/ColoredMessage.h source/bncsutilinterface.h
FORMS += source/GhostGrazLogininformationDialog.ui source/MainGUI.ui source/ConfigGUI.ui
RESOURCES += source/resources.qrc
TRANSLATIONS +=
OBJECTS_DIR = build/Release/Qt_MinGW-Windows
MOC_DIR = source
RCC_DIR = source
UI_DIR = source
QMAKE_CC = mingw32-gcc.exe
QMAKE_CXX = mingw32-g++.exe
DEFINES += 
INCLUDEPATH += source ../BNCSUtil/src . . . . . . . . . . . . . . . . 
LIBS += source/ms_sdk/version.lib source/ms_sdk/ws2_32.lib -L../BNCSUtil/dist/Release/Qt_MinGW-Windows ../BNCSUtil/dist/Release/Qt_MinGW-Windows/BNCSUtil.dll  
