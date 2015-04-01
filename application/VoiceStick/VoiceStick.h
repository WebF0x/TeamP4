#ifndef VOICESTICK_H
#define VOICESTICK_H

#include "VoiceStickUI.h"
#include "Profile.h"
#include <QFileDialog>

class VoiceStick : public VoiceStickUI
{
    Q_OBJECT

public:
    VoiceStick(const QStringList& phonemNames, QWidget *parent = 0);

public slots:
    //Menu actions
//    virtual void open();
//    virtual bool save();
//    virtual bool saveAs();
    virtual void closeEvent(QCloseEvent *event);
//    virtual void undo();
//    virtual void redo();
//    virtual void undoAll();
//    virtual void profileSelected(int index);
//    virtual void newProfile();
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

    bool isModified = false;   //True if closing the program will lose unsaved changes
};

#endif // VOICESTICK_H
