#ifndef AWARD_H
#define AWARD_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QObject>
#include <QString>


class award: public QGraphicsPixmapItem
{

public:
    award();
    award(int type);
    void setAward(int fullfill);


private:
    QString Y,N;
    float height,x,y;
};

#endif // AWARD_H
