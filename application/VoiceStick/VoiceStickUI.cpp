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
            m_undoAction                = new QAction("Undo", this);
            m_redoAction                = new QAction("Redo", this);
            m_undoAllAction             = new QAction("Undo All...", this);
        m_profileMenu= new QMenu("Profile", this);
            m_newProfileAction          = new QAction("New Profile...", this);
            m_deleteProfileAction       = new QAction("Delete Profile...", this);
            m_deleteAllProfilesAction   = new QAction("Delete All Profiles...", this);
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
            m_phonemsAKeyEdit = new QKeySequenceEdit(this);
            m_phonemsBKeyEdit = new QKeySequenceEdit(this);
            m_phonemsCKeyEdit = new QKeySequenceEdit(this);
            m_phonemsDKeyEdit = new QKeySequenceEdit(this);
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

    m_phonemsFormLayout->addRow(m_phonemsLabelA, m_phonemsAKeyEdit);
    m_phonemsFormLayout->addRow(m_phonemsLabelB, m_phonemsBKeyEdit);
    m_phonemsFormLayout->addRow(m_phonemsLabelC, m_phonemsCKeyEdit);
    m_phonemsFormLayout->addRow(m_phonemsLabelD, m_phonemsDKeyEdit);

    //Arrange main window
    setMenuBar(m_menuBar);
    setCentralWidget(m_mainWidget);
    setStatusBar(m_statusBar);

    //Connect menu actions to slots
    connect(m_openAction, SIGNAL(triggered()), this, SLOT(open()));
    connect(m_saveAction, SIGNAL(triggered()), this, SLOT(save()));
    connect(m_saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));
    connect(m_undoAction, SIGNAL(triggered()), this, SLOT(undo()));
    connect(m_redoAction, SIGNAL(triggered()), this, SLOT(redo()));
    connect(m_undoAllAction, SIGNAL(triggered()), this, SLOT(undoAll()));
    connect(m_newProfileAction, SIGNAL(triggered()), this, SLOT(newProfile()));
    connect(m_deleteProfileAction, SIGNAL(triggered()), this, SLOT(deleteProfile()));
    connect(m_deleteAllProfilesAction, SIGNAL(triggered()), this, SLOT(deleteAllProfiles()));
    connect(m_userManualAction, SIGNAL(triggered()), this, SLOT(userManual()));
    connect(m_aboutVoiceStickAction, SIGNAL(triggered()), this, SLOT(aboutVoiceStick()));
    connect(m_aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));

    //Connect buttons to slots
    connect(m_newProfileButton, SIGNAL(clicked()), this, SLOT(newProfile()));
    connect(m_deleteProfileButton, SIGNAL(clicked()), this, SLOT(deleteProfile()));
    connect(m_testPushButton, SIGNAL(clicked()), this, SLOT(test()));
    connect(m_runPushButton, SIGNAL(clicked()), this, SLOT(run()));
}

VoiceStickUI::~VoiceStickUI()
{
    //QMainWindow will take care of deleting all of its children
}

int VoiceStickUI::currentProfile()
{
    return m_profileComboBox->currentIndex();
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

void VoiceStickUI::save()
{
    comingSoonInfoPopup();
}

void VoiceStickUI::saveAs()
{
    comingSoonInfoPopup();
}

void VoiceStickUI::exit()
{
    comingSoonInfoPopup();
}

void VoiceStickUI::undo()
{
    comingSoonInfoPopup();
}

void VoiceStickUI::redo()
{
    comingSoonInfoPopup();
}

void VoiceStickUI::undoAll()
{
    comingSoonInfoPopup();
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
    comingSoonInfoPopup();
}

void VoiceStickUI::aboutQt()
{
    comingSoonInfoPopup();
}

void VoiceStickUI::test()
{
    comingSoonInfoPopup();
}

void VoiceStickUI::run()
{
    comingSoonInfoPopup();
}
