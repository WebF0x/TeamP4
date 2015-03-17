#include "VoiceStickUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VoiceStickUI w(0,QString("A"),QString("B"),QString("C"),QString("D"));
    w.show();

    return a.exec();
}
