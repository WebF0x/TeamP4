#include "Profile.h"
using namespace std;


Profile::Profile (const QString &title, const QVector<QKeySequence> & keySeq)
{
    m_title = title;
    m_keySequences = keySeq;
}

Profile::Profile()
{
    m_title = "Default Profile";
    m_keySequences = QVector<QKeySequence>(4, QKeySequence());
}

void Profile::setTitle(const QString& title)
{
    m_title = title;
}

QString Profile::getTitle() const
{
    return m_title;
}

void Profile::setKeySequences(const QVector<QKeySequence>& keySeqs)
{
    m_keySequences = keySeqs;
}

QVector<QKeySequence> Profile::getPhonems() const
{
    return m_keySequences;
}

void Profile::setKeySequence(int index, const QKeySequence& keySeq)
{
    if (index < m_keySequences.size() && index >= 0)
    {
        m_keySequences[index] = keySeq;
    }
}

QKeySequence Profile::getPhonem(int index) const
{
    return m_keySequences.value(index);
}
