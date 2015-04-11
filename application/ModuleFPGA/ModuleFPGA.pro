TEMPLATE     = vcapp
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += CommunicationFPGA/CommunicationFPGA.h
SOURCES     += main.cpp

CONFIG(debug, debug|release) {
	LIBS	+= CommunicationFPGA/debug/CommunicationFPGA.lib
} else {
	LIBS	+= CommunicationFPGA/release/CommunicationFPGA.lib
}

QT += widgets