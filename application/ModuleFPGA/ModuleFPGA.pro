TEMPLATE     = vcapp
CONFIG      += warn_on qt debug_and_release windows console c++11
HEADERS     += CommunicationFPGA/CommunicationFPGA.h ModuleFPGA.h
SOURCES     += main.cpp ModuleFPGA.cpp

CONFIG(debug, debug|release) {
	LIBS	+= CommunicationFPGA/debug/CommunicationFPGA.lib
} else {
	LIBS	+= CommunicationFPGA/release/CommunicationFPGA.lib
}

QT += widgets