#ifndef PROFILE
#define PROFILE

#include <QVector>
#include <QKeySequence>
#include <QString>



class Profile
{

 private:
    int index;
    QString Title;
    QVector<QKeySequence> VProfile;

 public:
    Profile(QString, QVector<QKeySequence>);
    Profile();
    ~Profile();

};

#endif // PROFILE

