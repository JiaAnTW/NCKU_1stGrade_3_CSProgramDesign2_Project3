#ifndef ENEMYATK_H
#define ENEMYATK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <cmath>
#include <ctime>
#include <cstdlib>


class enemyatk: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enemyatk();
    enemyatk(int,float xpos_boss=0, float ypos_boss=0,float xpos_player=0, float ypos_player=0);

public slots:
    void fly();
    void deletemyself(bool);

private:
    int att_type;
    float xpos[2];
};

#endif // ENEMYATK_H
