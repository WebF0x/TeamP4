/*
 * Profile.h
 * A Profile contains a title and QKeySequence's
 * Author: alle2004,dupm2216,leta1602,maia2604,poum2319,valp2602
 * Date: Hiver 2015
 * Copyright (c) 2015   Département de génie électrique et génie informatique
 *                       Université de Sherbrooke
*/

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

    //Setter and getter for the title
    void setTitle(const QString& title);
    QString getTitle() const;

    //Setter and getter for all key sequences
    void setKeySequences(const QVector<QKeySequence>& keySeqs);
    QVector<QKeySequence> getPhonems() const;

    //Setter and getter for the key sequence of the phonem at the specified index
    //index: index of the profile
    void setKeySequence(int index, const QKeySequence& keySeq);
    QKeySequence getPhonem(int index) const;

private:
   QString m_title;
   QVector<QKeySequence> m_keySequences;

};

#endif // PROFILE

