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

private:
	QStringList *phonemNames;
	QIcon myIcon;
	QFont myFont;
	QPushButton *running;
	bool m_isRunning = false;
	bool m_isTesting = false;
	int windowWidth;
	int windowHeight;
	//composantes du menu
	QMenuBar* m_menuBar;
	QMenu* m_fileMenu;
	QMenu* m_editMenu;
	QMenu* m_profileMenu;
	QMenu* m_helpMenu;

	//Sous-menus
	QAction* m_openAction;
	QAction* m_saveAction;
	QAction* m_saveAsAction;
	QAction* m_exitAction;
	QAction* m_newProfileAction;
	QAction* m_deleteProfileAction;
	QAction* m_deleteAllProfilesAction;
	QAction* m_userManualAction;
	QAction* m_aboutVoiceStickAction;
	QAction* m_aboutQtAction;

	//Widgets principaux
	QWidget* m_mainWidget;
	QComboBox* m_profileComboBox;
	QPushButton* m_newProfileButton;
	QPushButton* m_deleteProfileButton;
	QPushButton* m_testPushButton;
	QPushButton* m_runPushButton;

	//AUTRES WIDGETS	
	QVector<QLabel*> m_phonemLabels;
	QVector<QKeySequenceEdit*> m_phonemEdits;
	QStatusBar* m_statusBar;

	//layouts
	QGroupBox* m_phonemsGroupBox;
	QGroupBox* m_emptySpacerBox;
	QGroupBox* m_profileGroupBox;
	QVBoxLayout* m_mainVBoxLayout;
	QHBoxLayout* m_profileHBoxLayout;
	QFormLayout* m_phonemsFormLayout;

	//fonctions de structure
	void createMenu();
	void createTop();
	void createMid();
	void createBot();
	void comingSoonInfoPopup();
	
public:
    VoiceStickUI(QWidget *parent = 0);
    virtual ~VoiceStickUI();

	bool isRunning() { return m_isRunning; }
	bool isTesting() { return m_isTesting; }

    int currentProfileIndex() const;//Returns the index of the profile in the combo box
    void setProfileOptions(const QStringList& profileNames);//Set the options in the profiles QComboBox
	void selectProfile(int n);//Selects n-th profile

	QKeySequence getPhonemKeySequence(int n) const;//Returns the QKeySequence associated with the n-th phonem
    QVector<QKeySequence> getPhonemKeySequences() const;//Returns the QKeySequence's associated with the phonems
	void setPhonemKeySequences(QVector<QKeySequence> keySeqs); //Sets the phonems' QKeySequence's
	int numberOfPhonems() const;//Returns the number of phonems

    void highlight(int n);//Highlights the QKeySequenceEdit associated with the n-th phonem
    void unhighlight(int n);//Unhighlights the QKeySequenceEdit associated with the n-th phonem

public slots:
    //Menu actions
    virtual void open();
    virtual bool save();    //Returns true at success
    virtual bool saveAs();  //Returns true at success
    virtual void newProfile();
    virtual void deleteProfile();
    virtual void deleteAllProfiles();
    virtual void userManual();
    virtual void aboutVoiceStick();
    virtual void aboutQt();

    //Buttons
    virtual void test();
    virtual void run();

	virtual void testTriggered();
	virtual void runTriggered();

    virtual void profileSelected(int index);
    virtual void phonemKeySequenceModified();
};

#endif // VOICESTICKUI_H
