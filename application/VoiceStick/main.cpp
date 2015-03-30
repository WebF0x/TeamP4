#include "VoiceStick.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList phonemNames({"a (fat)","ɛ (bed)","i (free)","whistle"});
    VoiceStick w(phonemNames);
    w.show();

    return a.exec();
}
