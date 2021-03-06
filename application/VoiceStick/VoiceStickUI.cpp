/*
 * VoiceStickUI.cpp
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

#include "VoiceStickUI.h"

VoiceStickUI::VoiceStickUI(QWidget *parent) : QMainWindow(parent)
{
	phonemNames = new QStringList({ "a (fat)", "i (free)", "u (boot)", "whistle" });
	myIcon.addFile("logo.jpg");

	myFont.setPointSize(14);
	myFont.setStyleStrategy(QFont::ForceOutline);

	//Creation de l'interface
	createMenu();
	createTop();
	createMid();
	createBot();

	//Arrange main window
	setMenuBar(m_menuBar);
	setCentralWidget(m_mainWidget);
	setStatusBar(m_statusBar);

	setWindowIcon(myIcon);

	adjustSize();
	setFixedSize(size());
	statusBar()->setSizeGripEnabled(false);
}

VoiceStickUI::~VoiceStickUI()
{
	//QMainWindow will take care of deleting all of its children
}	

//fonction qui genere le menu
void VoiceStickUI::createMenu(){
	//Init widgets
	m_menuBar = new QMenuBar(this);
	m_fileMenu = new QMenu("&File", this);
	m_openAction = new QAction("Open...", this);
	m_saveAction = new QAction("Save", this);
	m_saveAsAction = new QAction("Save As...", this);
	m_exitAction = new QAction("Exit", this);
	m_editMenu = new QMenu("&Edit", this);
	m_profileMenu = new QMenu("&Profile", this);
	m_newProfileAction = new QAction("New Profile...", this);
	m_deleteProfileAction = new QAction("Delete Profile...", this);
	m_deleteAllProfilesAction = new QAction("Delete All Profiles...", this);
	m_helpMenu = new QMenu("&Help", this);
	m_userManualAction = new QAction("User Manual...", this);
	m_aboutVoiceStickAction = new QAction("About VoiceStick...", this);
	m_aboutQtAction = new QAction("About Qt...", this);

	//Arrange actions and menus in menu bar
	m_menuBar->addMenu(m_fileMenu);
	m_fileMenu->addAction(m_openAction);
	m_fileMenu->addSeparator();
	m_fileMenu->addAction(m_saveAction);
	m_fileMenu->addAction(m_saveAsAction);
	m_fileMenu->addSeparator();
	m_fileMenu->addAction(m_exitAction);
	m_menuBar->addMenu(m_editMenu);
	m_editMenu->addAction(m_newProfileAction);
	m_editMenu->addSeparator();
	m_editMenu->addAction(m_deleteProfileAction);
	m_editMenu->addAction(m_deleteAllProfilesAction);
	m_menuBar->addMenu(m_helpMenu);
	m_helpMenu->addAction(m_userManualAction);
	m_helpMenu->addSeparator();
	m_helpMenu->addAction(m_aboutVoiceStickAction);
	m_helpMenu->addAction(m_aboutQtAction);

	//Connect menu actions to slots
	connect(m_openAction, SIGNAL(triggered()), this, SLOT(open()));
	connect(m_saveAction, SIGNAL(triggered()), this, SLOT(save()));
	connect(m_saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));
	connect(m_exitAction, SIGNAL(triggered()), this, SLOT(close()));
	connect(m_newProfileAction, SIGNAL(triggered()), this, SLOT(newProfile()));
	connect(m_deleteProfileAction, SIGNAL(triggered()), this, SLOT(deleteProfile()));
	connect(m_deleteAllProfilesAction, SIGNAL(triggered()), this, SLOT(deleteAllProfiles()));
	connect(m_userManualAction, SIGNAL(triggered()), this, SLOT(userManual()));
	connect(m_aboutVoiceStickAction, SIGNAL(triggered()), this, SLOT(aboutVoiceStick()));
	connect(m_aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));

	//Keyboard shortcuts for menu actions
	m_openAction->setShortcut(QKeySequence::Open);
	m_saveAction->setShortcut(QKeySequence::Save);
	m_saveAsAction->setShortcut(QKeySequence::SaveAs);
	m_exitAction->setShortcut(QKeySequence::Quit);

	m_newProfileAction->setShortcut(QKeySequence::New);
	m_deleteProfileAction->setShortcut(QKeySequence::Delete);

	m_userManualAction->setShortcut(QKeySequence::HelpContents);
	m_aboutVoiceStickAction->setShortcut(QKeySequence::WhatsThis);
}

//fonction qui genere la partie du haut de l'interface principale
void VoiceStickUI::createTop(){
	m_mainWidget = new QWidget(this);
	QPixmap bckgrnd("background.jpg");
	bckgrnd = bckgrnd.scaled(QSize(width(), height()), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bckgrnd);
	this->setPalette(palette);

	m_profileGroupBox = new QGroupBox("Profile", this);
	m_profileGroupBox->setStyleSheet("QGroupBox { color : white; }");
	m_profileGroupBox->setFont(myFont);

	m_profileComboBox = new QComboBox(this);
	//Make sure the longest profile fits in the comboBox
	QFontMetrics fm(m_profileComboBox->font());
	m_profileComboBox->setFixedWidth(fm.width(QString(MAX_PROFILE_NAME_LENGTH, 'W'))*1.10);

	m_newProfileButton = new QPushButton("New...", this);
	m_deleteProfileButton = new QPushButton("Delete...", this);

	m_mainVBoxLayout = new QVBoxLayout(m_mainWidget);
	m_emptySpacerBox = new QGroupBox();
	m_emptySpacerBox->setStyleSheet("QGroupBox { border : 0px; }");
	m_mainVBoxLayout->addWidget(m_profileGroupBox);
	m_mainVBoxLayout->addWidget(m_emptySpacerBox);
	m_profileHBoxLayout = new QHBoxLayout(m_profileGroupBox);
	m_profileHBoxLayout->addWidget(m_profileComboBox);
	m_profileHBoxLayout->addWidget(m_newProfileButton);
	m_profileHBoxLayout->addWidget(m_deleteProfileButton);

	connect(m_newProfileButton, SIGNAL(clicked()), this, SLOT(newProfile()));
	connect(m_deleteProfileButton, SIGNAL(clicked()), this, SLOT(deleteProfile()));
	connect(m_profileComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(profileSelected(int)));

	//Make buttons pressable by pressing "enter"
	m_newProfileButton->setAutoDefault(true);
	m_deleteProfileButton->setAutoDefault(true);
}


//fonction qui genere la partie centrale de l'interface principale
void VoiceStickUI::createMid(){
	m_phonemsGroupBox = new QGroupBox("Phonems", this);
	m_phonemsGroupBox->setStyleSheet("QGroupBox, QLabel { color : white;}");
	m_phonemsGroupBox->setFont(myFont);
	m_phonemsFormLayout = new QFormLayout(m_phonemsGroupBox);

	for (int i = 0; i < phonemNames->size(); ++i)
	{
		m_phonemLabels.append(new QLabel(phonemNames->at(i), this));
		m_phonemEdits.append(new QKeySequenceEdit(this));
	}

	m_mainVBoxLayout->addWidget(m_phonemsGroupBox);

	for (int i = 0; i < phonemNames->size(); ++i)
	{
		m_phonemsFormLayout->addRow(m_phonemLabels.at(i), m_phonemEdits.at(i));
	}

	//User changes phonem's QKeySequence
	for (QKeySequenceEdit* field : m_phonemEdits)
	{
		connect(field, SIGNAL(editingFinished()), this, SLOT(phonemKeySequenceModified()));
	}

}


//fonction qui genere la partie du bas de l'interface principale
void VoiceStickUI::createBot(){
	m_testPushButton = new QPushButton("Test", this);
	m_runPushButton = new QPushButton("Run", this);
	m_statusBar = new QStatusBar(this);
	m_statusBar->setStyleSheet("QStatusBar, QLabel { color : white; }");
	m_statusBar->setFont(myFont);


	m_mainVBoxLayout->addWidget(m_testPushButton);
	m_mainVBoxLayout->addWidget(m_runPushButton);

	connect(m_testPushButton, SIGNAL(clicked()), this, SLOT(testTriggered()));
	connect(m_runPushButton, SIGNAL(clicked()), this, SLOT(runTriggered()));

	m_testPushButton->setAutoDefault(true);
	m_runPushButton->setAutoDefault(true);
}


int VoiceStickUI::currentProfileIndex() const
{
	return m_profileComboBox->currentIndex();
}

void VoiceStickUI::selectProfile(int n)
{
	m_profileComboBox->setCurrentIndex(n);
}

void VoiceStickUI::setProfileOptions(const QStringList& profileNames)
{
	m_profileComboBox->clear();
	m_profileComboBox->addItems(profileNames);
}

QKeySequence VoiceStickUI::getPhonemKeySequence(int n) const
{
	QKeySequenceEdit* sequenceEditField = m_phonemEdits.value(n);

	if (!sequenceEditField) return QKeySequence();

	return sequenceEditField->keySequence();
}

QVector<QKeySequence> VoiceStickUI::getPhonemKeySequences() const
{
	QVector<QKeySequence> keySequences;

	for (QKeySequenceEdit* field : m_phonemEdits)
	{
		keySequences.append(field->keySequence());
	}

	return keySequences;
}

void VoiceStickUI::setPhonemKeySequences(QVector<QKeySequence> keySeqs)
{
	for (int i = 0; i < keySeqs.size(); ++i)
	{
		m_phonemEdits.at(i)->setKeySequence(keySeqs.at(i));
	}
}

void VoiceStickUI::highlight(int n)
{
	QKeySequenceEdit* sequenceEditField = m_phonemEdits.value(n);

	if (sequenceEditField)
		sequenceEditField->setStyleSheet("QLineEdit {background-color: lightgreen;}");
}

void VoiceStickUI::unhighlight(int n)
{
	QKeySequenceEdit* sequenceEditField = m_phonemEdits.value(n);

	if (sequenceEditField)
		sequenceEditField->setStyleSheet("QLineEdit {background-color: white;}");
}

int VoiceStickUI::numberOfPhonems() const
{
	return m_phonemLabels.size();
}

void VoiceStickUI::comingSoonInfoPopup()
{
	QMessageBox::information(this,
		"Coming soon",
		"Not implemented yet.");
}

void VoiceStickUI::open()
{
	comingSoonInfoPopup();
}

bool VoiceStickUI::save()
{
	comingSoonInfoPopup();
	return false;
}

bool VoiceStickUI::saveAs()
{
	comingSoonInfoPopup();
	return false;
}

void VoiceStickUI::newProfile()
{
	comingSoonInfoPopup();
}

void VoiceStickUI::deleteProfile()
{
	comingSoonInfoPopup();
}

void VoiceStickUI::deleteAllProfiles()
{
	comingSoonInfoPopup();
}

void VoiceStickUI::userManual()
{
	comingSoonInfoPopup();
}

void VoiceStickUI::aboutVoiceStick()
{
	QMessageBox::information(this,
		"About Voicestick",
		"Voicestick is a proprietary phonem recognition software!\r\nAuthors: Emeri Allard, Marc-Antoine Poulin, Alex Maisonneuve, Maxime Dupuis, Philippe Vallee-Lefebvre, Adam Letourneau"
		);
}

void VoiceStickUI::aboutQt()
{
	comingSoonInfoPopup();
}

void VoiceStickUI::testTriggered()
{
	//Toggle
	m_isTesting = !m_isTesting;

	//Update button text
	if (m_isTesting)
	{
		m_testPushButton->setText("Stop");
		m_runPushButton->setEnabled(false);
	}
	else 
	{
		m_testPushButton->setText("Test");
		m_runPushButton->setEnabled(true);
	}

	test();
}

void VoiceStickUI::runTriggered()
{
	//Toggle
	m_isRunning = !m_isRunning;

	//Update button text
	if (m_isRunning)
	{
		m_runPushButton->setText("Stop");
		m_testPushButton->setEnabled(false);
	}
	else
	{
		m_runPushButton->setText("Run");
		m_testPushButton->setEnabled(true);
	}

	run();
}

void VoiceStickUI::run()
{
	comingSoonInfoPopup();
}

void VoiceStickUI::test()
{
	comingSoonInfoPopup();
}

void VoiceStickUI::profileSelected(int index)
{
	comingSoonInfoPopup();
}

void VoiceStickUI::phonemKeySequenceModified()
{
	comingSoonInfoPopup();
}
