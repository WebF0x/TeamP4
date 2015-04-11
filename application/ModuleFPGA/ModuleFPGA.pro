TEMPLATE     = vcapp
CONFIG      += warn_on qt debug windows console
HEADERS     += CommunicationFPGA/CommunicationFPGA.h
SOURCES     += main.cpp

LIBS += CommunicationFPGA/CommunicationFPGA.lib

QT += widgets