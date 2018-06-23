#ifndef LCDNUMBER_H
#define LCDNUMBER_H
#include <QObject>
#include <QString>
#include <QPushButton>
#include <QVector>
#include "cmath"


class LCDnumber:public QObject
{
    Q_OBJECT

public:
    LCDnumber();
    LCDnumber(int type);
    void setNumber(int where);
    void setTotalNumber(int input);
    float getPos(float where);
    QPushButton *LCD[9];

public slots:
    void changeNumber(int input);

private:
    QVector<int> save;
    float length,xpos,ypos;
};

#endif // LCDNUMBER_H
