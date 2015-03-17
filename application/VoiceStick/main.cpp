#include "VoiceStickUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VoiceStickUI w;
    w.show();

    return a.exec();
}
