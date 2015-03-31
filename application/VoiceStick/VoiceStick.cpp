#include "VoiceStick.h"

VoiceStick::VoiceStick(const QStringList& phonemNames, QWidget *parent) : VoiceStickUI(phonemNames, parent)
{
}

QMessageBox::StandardButton VoiceStick::maybeSave()
{
    if(!isModified) return QMessageBox::StandardButton::Discard;

    QMessageBox::StandardButton choice = QMessageBox::warning
            (this,
             "Unsaved changes",
             "There are unsaved changes.\nWhat do you want to do?",
             QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel );

    return choice;
}

void VoiceStick::closeEvent(QCloseEvent* event)
{
    switch(maybeSave())
    {
    case QMessageBox::StandardButton::Save:
        if(save()) event->accept();
        else event->ignore();
        break;
    case QMessageBox::StandardButton::Discard:
        event->accept();
        break;
    case QMessageBox::StandardButton::Cancel:
        event->ignore();
        break;
    default:
        event->ignore();
        break;
    }
}

void VoiceStick::aboutQt()
{
    QMessageBox::aboutQt(this,"About Qt");
}
