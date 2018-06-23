#ifndef RECORD_H
#define RECORD_H
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QVector>


class record
{
public:
    record();
    void recieveData(int level,int HP,int ult,int score);
    void saveData();
    QVector<int> sendData();

private:
    QString data;
    QVector<int> save;
};

#endif // RECORD_H
