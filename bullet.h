#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <cmath>


class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();
    bullet(int);

public slots:
    void fly();
    void deletemyself(bool);
private:
    int type;
};

#endif // BULLET_H
