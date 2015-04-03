#ifndef PROFILE
#define PROFILE

#include <QVector>
#include <QKeySequence>
#include <QString>



class Profile
{
 public:
    Profile();
    Profile(const QString& title, const QVector<QKeySequence>&);

    void setTitle(const QString& title);
    QString getTitle() const;

    void setKeySequences(const QVector<QKeySequence>& keySeqs);
    QVector<QKeySequence> getPhonems() const;

    void setKeySequence(int index, const QKeySequence& keySeq);
    QKeySequence getPhonem(int index) const;

private:
   QString m_title;
   QVector<QKeySequence> m_keySequences;

};

#endif // PROFILE

