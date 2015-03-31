#include "VoiceStick.h"

VoiceStick::VoiceStick(const QStringList& phonemNames, QWidget *parent) : VoiceStickUI(phonemNames, parent)
{
}

void VoiceStick::closeEvent(QCloseEvent* event)
{
    if(isModified)
    {
        QMessageBox::StandardButton choice = QMessageBox::question(this,
                                                                   "Unsaved changes",
                                                                   "There are unsaved changes.\nWhat do you want to do?",
                                                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel );

        switch(choice)
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
}

void VoiceStick::aboutQt()
{
    QMessageBox::aboutQt(this,"About Qt");
}
