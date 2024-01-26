TEMPLATE = lib
CONFIG += c++11
CONFIG += shared
QT -= gui

INCLUDEPATH += ../TestLib

# wir bauen eine shared lib/DLL
DEFINES += BUILD_PLUGIN

DESTDIR = ../lib

LIBS += -L../lib -lTestLib

SOURCES += \
	TestPlugin.cpp

HEADERS += \
	AbstractPluginInterface.h \
	PluginInterface.h \
	TestPlugin.h

