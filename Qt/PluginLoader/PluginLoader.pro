TEMPLATE = app
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

INCLUDEPATH += \
	../TestPlugin

#DEFINES += TEST_DIRECT_LINKING
#LIBS += -L../lib -lTestPlugin
#-lTestLib

SOURCES += \
	PluginLoader.cpp \
	main.cpp

HEADERS += \
	PluginLoader.h
