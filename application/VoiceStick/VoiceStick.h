#ifndef VOICESTICK_H
#define VOICESTICK_H

#include "VoiceStickUI.h"
#include "Profile.h"
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QInputDialog>
#include <QTextStream>

class VoiceStick : public VoiceStickUI
{
    Q_OBJECT

public:
    VoiceStick(const QStringList& phonemNames, QWidget *parent = 0);
    bool saveAs(const QString& fileName);

public slots:
    //Menu actions
    virtual void open();
    virtual bool save();
    virtual bool saveAs();
    virtual void closeEvent(QCloseEvent *event);
//    virtual void undo();
//    virtual void redo();
//    virtual void undoAll();

    //Prompt user for a profile name.
    //If it's invalid, alert user of the error.
    //If it's valid, create a profile with the corresponding name and empty phonem QKeySequences. Add it to UI and select it.
    virtual void newProfile();

    //Delete selected profile
    virtual void deleteProfile();
    virtual void deleteAllProfiles();
//    virtual void userManual();
//    virtual void aboutVoiceStick();
    virtual void aboutQt();
    //Buttons
//    virtual void test();
//    virtual void run();

    //User chooses profile
    virtual void profileSelected(int index);
    //User changes a phonem's QKeySequence
    virtual void phonemKeySequenceModified();

private:
    //Warns the user that unsaved changes might be lost and returns the user's choice:
    //Return values:
    //  QMessageBox::StandardButton::Save
    //  QMessageBox::StandardButton::Discard
    //  QMessageBox::StandardButton::Cancel
    QMessageBox::StandardButton maybeSave();

    //Update the profile options and the phonem fields of the selected profile
    void updateUI();

    //Update the profile options
    void updateProfileOptions();

    //Update the phonem fields of the selected profile
    void updatePhonemKeySequences();

    QVector<Profile> m_profiles;
    QString m_currentFileName;
    bool m_isModified = false;   //True if closing the program will lose unsaved changes

    static const int MAX_PROFILE_NAME_LENGTH = 30;
};

#endif // VOICESTICK_H
