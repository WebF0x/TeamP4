#include "VoiceStick.h"

VoiceStick::VoiceStick(const QStringList& phonemNames, QWidget *parent) : VoiceStickUI(phonemNames, parent)
{
}

QMessageBox::StandardButton VoiceStick::maybeSave()
{
    if(!m_isModified) return QMessageBox::StandardButton::Discard;

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

//*
bool VoiceStick::saveAs()
{
    QString fileName(QFileDialog::getSaveFileName());

    return saveAs(fileName);
}

bool VoiceStick::saveAs(const QString& fileName)
{
    QFile file(fileName);   //Closed by destructor

    if(!file.open( QIODevice::WriteOnly ))  //Can't open file
    {
        QMessageBox::warning
                (this,
                 "Save failed",
                 "Cannot open file.",
                 QMessageBox::Ok );

        return false;
    }
    else
    {
        m_currentFileName = fileName;
        //Save (there were no errors)
        //TODO ... Write file
        return true;
    }
}
//*/

/*
void VoiceStick::open()
{
    QUrl url = QFileDialog::getOpenFileUrl();
    // ...
}
//*/
