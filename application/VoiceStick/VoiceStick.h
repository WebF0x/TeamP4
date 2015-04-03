#ifndef VOICESTICK_H
#define VOICESTICK_H

#include "VoiceStickUI.h"
#include "Profile.h"
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QInputDialog>

class VoiceStick : public VoiceStickUI
{
    Q_OBJECT

public:
    VoiceStick(const QStringList& phonemNames, QWidget *parent = 0);
    bool saveAs(const QString& fileName);

public slots:
    //Menu actions
//    virtual void open();
//    virtual bool save();
    virtual bool saveAs();
    virtual void closeEvent(QCloseEvent *event);
//    virtual void undo();
//    virtual void redo();
//    virtual void undoAll();
//    virtual void profileSelected(int index);

    //Prompt user for a profile name.
    //If it's invalid, alert user of the error.
    //If it's valid, create a profile with the corresponding name and empty phonem QKeySequences. Add it to UI and select it.
    virtual void newProfile();

//    virtual void deleteProfile();
//    virtual void deleteAllProfiles();
//    virtual void userManual();
//    virtual void aboutVoiceStick();
    virtual void aboutQt();
    //Buttons
//    virtual void test();
//    virtual void run();

private:
    //Warns the user that unsaved changes might be lost and returns the user's choice:
    //Return values:
    //  QMessageBox::StandardButton::Save
    //  QMessageBox::StandardButton::Discard
    //  QMessageBox::StandardButton::Cancel
    QMessageBox::StandardButton maybeSave();

    //Update the profile choices and the phonem fields of the selected profile
    void updateUI();

    QVector<Profile> m_profiles;
    QString m_currentFileName;
    bool m_isModified = false;   //True if closing the program will lose unsaved changes

    static const int MAX_PROFILE_NAME_LENGTH = 30;
};

#endif // VOICESTICK_H
