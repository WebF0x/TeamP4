#ifndef VOICESTICK_H
#define VOICESTICK_H

#include "VoiceStickUI.h"

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
    bool isModified = false;   //True if closing the program will lose unsaved changes
};

#endif // VOICESTICK_H
