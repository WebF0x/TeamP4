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
//    virtual void save();
//    virtual void saveAs();
//    virtual void exit();
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
};

#endif // VOICESTICK_H
