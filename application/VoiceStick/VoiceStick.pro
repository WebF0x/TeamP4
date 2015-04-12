QT += core gui widgets

TARGET = VoiceStick

TEMPLATE = vcapp

SOURCES += main.cpp \
    VoiceStickUI.cpp \
    VoiceStick.cpp \
    Profile.cpp \
	ModuleFPGA.cpp

HEADERS  += VoiceStickUI.h \
   Profile.h \
    VoiceStick.h \
	ModuleFPGA.h
 
CONFIG(debug, debug|release) {
	LIBS	+= CommunicationFPGA/debug/CommunicationFPGA.lib
	CONFIG += console
} else {
	LIBS	+= CommunicationFPGA/release/CommunicationFPGA.lib
}