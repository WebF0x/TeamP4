#ifndef VOICESTICK_H
#define VOICESTICK_H

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

class VoiceStickUI : public QMainWindow
{
    Q_OBJECT

public:
    VoiceStickUI(QWidget *parent, const QString& phonemA, const QString& phonemB, const QString& phonemC, const QString& phonemD);
    ~VoiceStickUI();

protected:
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
            QLabel* m_phonemsLabelA;
            QLabel* m_phonemsLabelB;
            QLabel* m_phonemsLabelC;
            QLabel* m_phonemsLabelD;
            QLineEdit* m_phonemsLineEditA;
            QLineEdit* m_phonemsLineEditB;
            QLineEdit* m_phonemsLineEditC;
            QLineEdit* m_phonemsLineEditD;
        QPushButton* m_testPushButton;
        QPushButton* m_runPushButton;

    QStatusBar* m_statusBar;

    //Layouts
    QVBoxLayout* m_mainVBoxLayout;
        QHBoxLayout* m_profileHBoxLayout;
        QFormLayout* m_phonemsFormLayout;



};

#endif // VOICESTICK_H
