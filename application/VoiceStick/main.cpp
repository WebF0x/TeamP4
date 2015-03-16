#include "voicestick.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VoiceStick w;
    w.show();

    return a.exec();
}
