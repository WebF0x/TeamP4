/*
 * VoiceStick.h
 * VoiceStick is an application to map phonems to a specific key sequence.
 * It manages Profile creations, deletions and modifications, saving, loading and more.
 * VoiceStick implements the slots of VoiceStickUI from which it inherits.
 * Author: alle2004,dupm2216,leta1602,maia2604,poum2319,valp2602
 * Date: Hiver 2015
 * Copyright (c) 2015   Département de génie électrique et génie informatique
 *                       Université de Sherbrooke
*/

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

    //Saves the profiles in a file
    //fileName: path of the file
    //Returns true if successful, false otherwise
    bool saveAs(const QString& fileName);

public slots:   
    //Prompts the user for a file to open and opens it unless the user cancels the action.
    virtual void open();

    //If the current file is unknown: see saveAs()
    //If the current file is known:  saves the profiles in the current file.
    //Returns true if successful, false otherwise
    virtual bool save();

    //Prompts the user for a file to save and saves the profiles in it unless the user cancels the action.
    //Returns true if successful, false otherwise
    virtual bool saveAs();

    //If there are unsaved changes: prompts the user to know if he wants to save before closing, close without saving or cancel and acts accordingly
    //If there are no unsaved changes: closes the application
    virtual void closeEvent(QCloseEvent *event);

    //Prompt user for a profile name.
    //If it's invalid, alert user of the error.
    //If it's valid, create a profile with the corresponding name and empty phonem QKeySequences. Add it to UI and select it.
    virtual void newProfile();

    //Prompt for confirmation and consequently delete or not the selected profile
    virtual void deleteProfile();

    //Prompt for confirmation and consequently delete all profiles.
    virtual void deleteAllProfiles();

    //Shows a dialog window with information about Qt
    virtual void aboutQt();

    //Update the phonems with the selected profile's data
    //index: index of the newly selected profile
    virtual void profileSelected(int index);

    //Update the current profile to reflect the changes
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
