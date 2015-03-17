#include "VoiceStickUI.h"

VoiceStickUI::VoiceStickUI(QWidget *parent,
                           const QString& phonemA, const QString& phonemB, const QString& phonemC, const QString& phonemD)
    : QMainWindow(parent)
{
    //Init widgets
    m_menuBar = new QMenuBar(this);
        m_fileMenu = new QMenu("File", this);
            m_openAction                = new QAction("Open...", this);
            m_saveAction                = new QAction("Save", this);
            m_saveAsAction              = new QAction("Save As...", this);
            m_exitAction                = new QAction("Exit", this);
        m_editMenu= new QMenu("Edit", this);
            m_undoAction                = new QAction("Undo...", this);
            m_redoAction                = new QAction("Redo...", this);
            m_undoAllAction             = new QAction("Undo All...", this);
        m_profileMenu= new QMenu("Profile", this);
            m_newProfileAction          = new QAction("New Profile...", this);
            m_deleteProfileAction       = new QAction("Delete Profile...", this);
            m_deleteAllProfilesAction   = new QAction("Revert All Changes...", this);
        m_helpMenu= new QMenu("Help", this);
            m_userManualAction          = new QAction("User Manual...", this);
            m_aboutVoiceStickAction     = new QAction("About VoiceStick...", this);
            m_aboutQtAction             = new QAction("About Qt...", this);

    m_mainWidget = new QWidget(this);
        m_profileGroupBox = new QGroupBox("Profile",this);
            m_profileComboBox = new QComboBox(this);
            m_newProfileButton = new QPushButton("New...",this);
            m_deleteProfileButton = new QPushButton("Delete...",this);
        m_phonemsGroupBox = new QGroupBox("Phonems",this);
            m_phonemsLabelA = new QLabel(phonemA,this);
            m_phonemsLabelB = new QLabel(phonemB,this);
            m_phonemsLabelC = new QLabel(phonemC,this);
            m_phonemsLabelD = new QLabel(phonemD,this);
            m_phonemsLineEditA = new QLineEdit(this);
            m_phonemsLineEditB = new QLineEdit(this);
            m_phonemsLineEditC = new QLineEdit(this);
            m_phonemsLineEditD = new QLineEdit(this);
        m_testPushButton = new QPushButton("Test",this);
        m_runPushButton = new QPushButton("Run",this);
    m_statusBar = new QStatusBar(this);

    //Init layouts
    m_mainVBoxLayout = new QVBoxLayout(m_mainWidget);
        m_profileHBoxLayout = new QHBoxLayout(m_profileGroupBox);
        m_phonemsFormLayout = new QFormLayout(m_phonemsGroupBox);

    //Arrange actions and menus in menu bar
    m_menuBar->addMenu(m_fileMenu);
        m_fileMenu->addAction(m_openAction);
        m_fileMenu->addSeparator();
        m_fileMenu->addAction(m_saveAction);
        m_fileMenu->addAction(m_saveAsAction);
        m_fileMenu->addSeparator();
        m_fileMenu->addAction(m_exitAction);
    m_menuBar->addMenu(m_editMenu);
        m_editMenu->addAction(m_undoAction);
        m_editMenu->addAction(m_redoAction);
        m_editMenu->addSeparator();
        m_editMenu->addAction(m_undoAllAction);
    m_menuBar->addMenu(m_profileMenu);
        m_profileMenu->addAction(m_newProfileAction);
        m_profileMenu->addSeparator();
        m_profileMenu->addAction(m_deleteProfileAction);
        m_profileMenu->addAction(m_deleteAllProfilesAction);
    m_menuBar->addMenu(m_helpMenu);
        m_helpMenu->addAction(m_userManualAction);
        m_helpMenu->addSeparator();
        m_helpMenu->addAction(m_aboutVoiceStickAction);
        m_helpMenu->addAction(m_aboutQtAction);

    //Arrange widgets in their layouts
    m_mainVBoxLayout->addWidget(m_profileGroupBox);
    m_mainVBoxLayout->addWidget(m_phonemsGroupBox);
    m_mainVBoxLayout->addWidget(m_testPushButton);
    m_mainVBoxLayout->addWidget(m_runPushButton);

    m_profileHBoxLayout->addWidget(m_profileComboBox);
    m_profileHBoxLayout->addWidget(m_newProfileButton);
    m_profileHBoxLayout->addWidget(m_deleteProfileButton);

    m_phonemsFormLayout->addRow(m_phonemsLabelA, m_phonemsLineEditA);
    m_phonemsFormLayout->addRow(m_phonemsLabelB, m_phonemsLineEditB);
    m_phonemsFormLayout->addRow(m_phonemsLabelC, m_phonemsLineEditC);
    m_phonemsFormLayout->addRow(m_phonemsLabelD, m_phonemsLineEditD);

    //Arrange main window
    setMenuBar(m_menuBar);
    setCentralWidget(m_mainWidget);
    setStatusBar(m_statusBar);
}

VoiceStickUI::~VoiceStickUI()
{
    //QMainWindow will take care of deleting all of its children
}
