TEMPLATE = lib
CONFIG += console c++11
CONFIG += shared
CONFIG -= qt

# wir bauen eine shared lib/DLL
DEFINES += BUILD_LIB

DESTDIR = ../lib

SOURCES += \
	TestLib.cpp

HEADERS += \
	TestLib.h \
	TestLibConfig.h
