/*
 * VoiceStick.cpp
 * VoiceStick is an application to map phonems to a specific key sequence.
 * It manages Profile creations, deletions and modifications, saving, loading and more.
 * VoiceStick implements the slots of VoiceStickUI from which it inherits.
 * Author: alle2004,dupm2216,leta1602,maia2604,poum2319,valp2602
 * Date: Hiver 2015
 * Copyright (c) 2015   Département de génie électrique et génie informatique
 *                       Université de Sherbrooke
*/

#include "VoiceStick.h"

VoiceStick::VoiceStick(const QStringList& phonemNames, QWidget *parent) : VoiceStickUI(phonemNames, parent)
{
    statusBar()->showMessage("Welcome");
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

void VoiceStick::updateProfileOptions()
{
    QStringList profileOptions;
    for(const Profile& profile : m_profiles)
    {
        profileOptions.append(profile.getTitle());
    }
    setProfileOptions(profileOptions);
}

void VoiceStick::updatePhonemKeySequences()
{
    if(currentProfileIndex() != -1)
    {
        setPhonemKeySequences(m_profiles.at(currentProfileIndex()).getPhonems());
    }
    else
    {
        setPhonemKeySequences( QVector<QKeySequence>(numberOfPhonems(), QKeySequence()) );
    }
}

void VoiceStick::updateUI()
{
    updateProfileOptions();
    updatePhonemKeySequences();
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

void VoiceStick::newProfile()
{
    //Prompt user for profile name
    bool notCancelled;
    QString title = QInputDialog::getText(this,
        "New Profile",
        "Profile name ("+QString::number(MAX_PROFILE_NAME_LENGTH)+" characters or less):",
        QLineEdit::Normal,
        "",
        &notCancelled);

    if(notCancelled)
    {
        title = title.trimmed(); //Remove whitespaces from the start and the end

        if(title.isEmpty())
        {
            QMessageBox::warning(this, "Error", "Profile name cannot be blank.");
            return;
        }

        if(title.length() > MAX_PROFILE_NAME_LENGTH)
        {
            QMessageBox::warning(this, "Error", "Profile name must be "+QString::number(MAX_PROFILE_NAME_LENGTH)+" characters or less.");
            return;
        }

        //Create profile with empty phonems' QKeySequence's. Add to UI and select it.
        QVector<QKeySequence> keySeqs(numberOfPhonems(), QKeySequence());

        m_profiles.append({title, keySeqs});
        updateProfileOptions();
        selectProfile(m_profiles.size()-1);

        m_isModified = true;

        statusBar()->showMessage("Profile created: " + title);
    }
}

void VoiceStick::deleteProfile()
{
    if(currentProfileIndex() == -1) return;   //No profile selected

    //Prompt user for confirmation
    QString currentProfileName = m_profiles.at(currentProfileIndex()).getTitle();
    QMessageBox::StandardButton choice = QMessageBox::warning
            (this,
             "Delete profile",
             "Are you sure you want to delete \"" + currentProfileName + "\"?",
             QMessageBox::Yes | QMessageBox::Cancel,
             QMessageBox::Yes);

    if(choice == QMessageBox::Cancel) return;

    statusBar()->showMessage("Profile deleted: " + m_profiles.at(currentProfileIndex()).getTitle());

    //Delete profile
    m_profiles.remove(currentProfileIndex());
    updateUI();

    //Mark as modified
    m_isModified = true;
}

void VoiceStick::deleteAllProfiles()
{
    //Prompt user for confirmation
    QMessageBox::StandardButton choice = QMessageBox::warning
            (this,
             "Delete all profiles",
             "Are you sure you want to delete all " + QString::number(m_profiles.size()) + " profiles?",
             QMessageBox::Yes | QMessageBox::Cancel,
             QMessageBox::Yes);

    if(choice == QMessageBox::Cancel) return;

    //Delete all profiles
    m_profiles.clear();
    updateUI();

    m_isModified = true;

    statusBar()->showMessage("All profiles deleted");
}

void VoiceStick::aboutQt()
{
    QMessageBox::aboutQt(this,"About Qt");
}

bool VoiceStick::save()
{
    if( saveAs(m_currentFileName) ) //Save successful
    {
        return true;
    }
    else
    {
        return saveAs();
    }
}

bool VoiceStick::saveAs()
{
    QString fileName(QFileDialog::getSaveFileName());

    bool saveSuccessful = saveAs(fileName);

    if(!saveSuccessful)
    {
        QMessageBox::warning
                (this,
                 "Save failed",
                 "Cannot open file.",
                 QMessageBox::Ok );
    }

    return saveSuccessful;
}

bool VoiceStick::saveAs(const QString& fileName)
{
    if(fileName.trimmed().isEmpty()) return false;  //Empty filename

    QFile file(fileName);   //Closed by destructor

    if(!file.open( QIODevice::WriteOnly ))  //Can't open file
    {
        return false;
    }
    else
    {
        //Remember current file name
        m_currentFileName = fileName;

        //Save profiles in file
        QTextStream out(&file);

        for (const Profile& profile : m_profiles)
        {
            out << profile.getTitle() + ";";

            for(const QKeySequence& keySeq : profile.getPhonems())
            {
                out << keySeq.toString() + ";";
            }

            out << "\n";
        }

        m_isModified = false;
        statusBar()->showMessage("Profiles saved");

        return true;
    }
}

void VoiceStick::open()
{
    QString fileName = QFileDialog::getOpenFileName();
    if(fileName.trimmed().isEmpty()) return;  //Empty filename

    QFile file(fileName);

    if(!file.open( QIODevice::ReadOnly ))  //Can't open file
    {
        QMessageBox::warning
                (this,
                 "Open failed",
                 "Cannot open file.",
                 QMessageBox::Ok );

        return;
    }
    else
    {
        //Before losing data, ask user to save
        switch(maybeSave())
        {
        case QMessageBox::StandardButton::Save:
            save();
            break;
        case QMessageBox::StandardButton::Discard:
            break;
        case QMessageBox::StandardButton::Cancel:
            return;
            break;
        default:
            return;
            break;
        }

        //Delete current profiles
        m_profiles.clear();

        //Remember current file name
        m_currentFileName = fileName;

        //Read profiles in file
        QTextStream in(&file);

        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList data = line.split(";");

            QString title = data.at(0);
            QVector<QKeySequence> keySeqs;
            for(int i=1; i<data.size()-1; ++i)
            {
                keySeqs.append(QKeySequence::fromString(data.at(i)));
            }

            m_profiles.append({title,keySeqs});
        }
        updateUI();

        m_isModified = false;
        statusBar()->showMessage("Opened successfully");
    }
}

void VoiceStick::profileSelected(int index)
{
    updatePhonemKeySequences();

    if(index >= 0)
        statusBar()->showMessage("Profile selected: " + m_profiles.at(index).getTitle());
}

void VoiceStick::phonemKeySequenceModified()
{
    if(currentProfileIndex() == -1) return;   //No profile selected

    Profile& currentProfile = m_profiles[ currentProfileIndex() ];  //modifiable reference
    QVector<QKeySequence> keySequences = getPhonemKeySequences();

    currentProfile.setKeySequences(keySequences);
    m_isModified = true;

    statusBar()->showMessage("Key sequence modified");
}
