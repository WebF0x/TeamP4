/*
 * VoiceStickUI.h
 * Interface for VoiceStick application.
 * This is an empty shell. Another class must inherit from VoiceStickUI to implement its slots.
 * Creates the window, menus, buttons and others widgets.
 * Connects every actions with the appropriate slots.
 * By default the action shows a message that says "Coming soon"
 * Author: alle2004,dupm2216,leta1602,maia2604,poum2319,valp2602
 * Date: Hiver 2015
 * Copyright (c) 2015   Département de génie électrique et génie informatique
 *                       Université de Sherbrooke
*/

#ifndef VOICESTICKUI_H
#define VOICESTICKUI_H

#include <QMainWindow>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QStatusBar>
#include <QMenuBar>
#include <QMessageBox>
#include <QKeySequenceEdit>
#include <QStringList>
#include <QCloseEvent>
#include <QVector>

class VoiceStickUI : public QMainWindow
{
    Q_OBJECT

public:
    VoiceStickUI(const QStringList& phonemNames, QWidget *parent = 0);
    virtual ~VoiceStickUI();

    //Returns the index of the profile in the combo box
    //Returns -1 if the combo box is empty
    int currentProfileIndex() const;

    //Set the options in the profiles QComboBox
    void setProfileOptions(const QStringList& profileNames);

    //Returns the QKeySequence associated with the n-th phonem
    //n: index on the phonem between 0 and (numberOfPhonems - 1)
    QKeySequence getPhonemKeySequence(int n) const;

    //Returns the QKeySequence's associated with the phonems
    QVector<QKeySequence> getPhonemKeySequences() const;

    //Sets the phonems' QKeySequence's
    void setPhonemKeySequences(QVector<QKeySequence> keySeqs);

    //Highlights the QKeySequenceEdit associated with the n-th phonem
    void highlight(int n);

    //Unhighlights the QKeySequenceEdit associated with the n-th phonem
    void unhighlight(int n);

    //Returns the number of phonems
    int numberOfPhonems() const;

    //Selects n-th profile
    void selectProfile(int n);

public slots:
    //Menu actions
    virtual void open();
    virtual bool save();    //Returns true at success
    virtual bool saveAs();  //Returns true at success
    virtual void undo();
    virtual void redo();
    virtual void undoAll();
    virtual void newProfile();
    virtual void deleteProfile();
    virtual void deleteAllProfiles();
    virtual void userManual();
    virtual void aboutVoiceStick();
    virtual void aboutQt();
    //Buttons
    virtual void test();
    virtual void run();
    //User chooses profile
    virtual void profileSelected(int index);
    //User changes a phonem's QKeySequence
    virtual void phonemKeySequenceModified();

private:
    //Shows a dialog windows with a default message for unimplemented slots
    void comingSoonInfoPopup();

    //Widgets
    QMenuBar* m_menuBar;
        QMenu* m_fileMenu;
            QAction* m_openAction;
            QAction* m_saveAction;
            QAction* m_saveAsAction;
            QAction* m_exitAction;
        QMenu* m_editMenu;
            QAction* m_undoAction;
            QAction* m_redoAction;
            QAction* m_undoAllAction;
        QMenu* m_profileMenu;
            QAction* m_newProfileAction;
            QAction* m_deleteProfileAction;
            QAction* m_deleteAllProfilesAction;
        QMenu* m_helpMenu;
            QAction* m_userManualAction;
            QAction* m_aboutVoiceStickAction;
            QAction* m_aboutQtAction;

    QWidget* m_mainWidget;
        QGroupBox* m_profileGroupBox;
            QComboBox* m_profileComboBox;
            QPushButton* m_newProfileButton;
            QPushButton* m_deleteProfileButton;
        QGroupBox* m_phonemsGroupBox;
            QVector<QLabel*> m_phonemLabels;
            QVector<QKeySequenceEdit*> m_phonemEdits;
        QPushButton* m_testPushButton;
        QPushButton* m_runPushButton;

    QStatusBar* m_statusBar;

    //Layouts
    QVBoxLayout* m_mainVBoxLayout;
        QHBoxLayout* m_profileHBoxLayout;
        QFormLayout* m_phonemsFormLayout;
};

#endif // VOICESTICKUI_H
