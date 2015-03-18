#include "VoiceStickUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList phonemNames({"A","B","C","D"});
    VoiceStickUI w(phonemNames);
    w.show();

    return a.exec();
}
