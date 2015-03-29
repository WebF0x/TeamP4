#include "VoiceStickUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList phonemNames({"a (fat)","ɛ (bed)","i (free)","whistle"});
    VoiceStickUI w(phonemNames);
    w.show();

    return a.exec();
}
