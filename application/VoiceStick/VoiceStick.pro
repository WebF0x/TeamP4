QT += core gui widgets

TARGET = VoiceStick

TEMPLATE = vcapp
CONFIG+=c++11
SOURCES += main.cpp \
    VoiceStickUI.cpp \
    VoiceStick.cpp \
    Profile.cpp \
	ModuleFPGA.cpp
	
DEFINES += Q_COMPILER_INITIALIZER_LISTS

HEADERS  += VoiceStickUI.h \
   Profile.h \
    VoiceStick.h \
	ModuleFPGA.h
 
CONFIG(debug, debug|release) {
	LIBS	+= CommunicationFPGA/libDebug/CommunicationFPGA.lib
	CONFIG += console
} else {
	LIBS	+= CommunicationFPGA/libRelease/CommunicationFPGA.lib
}