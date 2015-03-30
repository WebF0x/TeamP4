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

class VoiceStickUI : public QMainWindow
{
    Q_OBJECT

public:
    VoiceStickUI(const QStringList& phonemNames, QWidget *parent = 0);
    ~VoiceStickUI();

    //Returns the index of the profile in the combo box
    //Returns -1 if the combo box is empty
    int currentProfile();

    //Set the options in the profiles QComboBox
    void setProfileOptions(const QStringList& profileNames);

    //Returns the QKeySequence associated with the n-th phonem
    //n: index on the phonem between 0 and (numberOfPhonems - 1)
    QKeySequence getPhonemKeySequence(int n);

    //Highlights the QKeySequenceEdit associated with the n-th phonem
    void highlight(int n);

    //Unhighlights the QKeySequenceEdit associated with the n-th phonem
    void unhighlight(int n);

public slots:
    //Menu actions
    virtual void open();
    virtual void save();
    virtual void saveAs();
    virtual void exit();
    virtual void undo();
    virtual void redo();
    virtual void undoAll();
    virtual void profileSelected(int index);
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
    //Default message
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
            QList<QLabel*> m_phonemLabels;
            QList<QKeySequenceEdit*> m_phonemEdits;
        QPushButton* m_testPushButton;
        QPushButton* m_runPushButton;

    QStatusBar* m_statusBar;

    //Layouts
    QVBoxLayout* m_mainVBoxLayout;
        QHBoxLayout* m_profileHBoxLayout;
        QFormLayout* m_phonemsFormLayout;
};

#endif // VOICESTICKUI_H
