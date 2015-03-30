#include "VoiceStick.h"

VoiceStick::VoiceStick(const QStringList& phonemNames, QWidget *parent) : VoiceStickUI(phonemNames, parent)
{
}

void VoiceStick::aboutQt()
{
    QMessageBox::aboutQt(this,"About Qt");
}
