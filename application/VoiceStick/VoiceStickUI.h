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
#include <QMessageBox>
#include <QKeySequenceEdit>

class VoiceStickUI : public QMainWindow
{
    Q_OBJECT

public:
    VoiceStickUI(QWidget *parent, const QString& phonemA, const QString& phonemB, const QString& phonemC, const QString& phonemD);
    ~VoiceStickUI();

    //Returns the index of the profile in the combo box
    //Returns -1 if the combo box is empty
    int currentProfile();

protected slots:
    //Default message
    void comingSoonInfoPopup();
    //Menu actions
    virtual void open();
    virtual void save();
    virtual void saveAs();
    virtual void exit();
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

private:
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
            QKeySequenceEdit* m_phonemsAKeyEdit;
            QKeySequenceEdit* m_phonemsBKeyEdit;
            QKeySequenceEdit* m_phonemsCKeyEdit;
            QKeySequenceEdit* m_phonemsDKeyEdit;
        QPushButton* m_testPushButton;
        QPushButton* m_runPushButton;

    QStatusBar* m_statusBar;

    //Layouts
    QVBoxLayout* m_mainVBoxLayout;
        QHBoxLayout* m_profileHBoxLayout;
        QFormLayout* m_phonemsFormLayout;



};

#endif // VOICESTICK_H
