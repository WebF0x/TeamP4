#include "Profile.h"
using namespace std;


Profile::Profile (const QString &title, const QVector<QKeySequence> & keySeq)
{
    m_title = title;
    m_keySequences = keySeq;
}


void Profile::setTitle(const QString& title)
{
    m_title = title;
}

QString Profile::getTitle()
{
    return m_title;
}

void Profile::setKeySequences(const QVector<QKeySequence>& keySeqs)
{
    m_keySequences = keySeqs;
}

QVector<QKeySequence> Profile::getPhonems()
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

QKeySequence Profile::getPhonem(int index)
{
    return m_keySequences.value(index);
}
