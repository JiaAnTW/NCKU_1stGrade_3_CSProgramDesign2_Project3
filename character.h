#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "enemyatk.h"

class character :public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    character();
    int getHP();
    void setlevel(int number);
    virtual int get_skill();
    virtual void using_skill_recover();

public slots:
    virtual void losingHP();
    virtual void Move();

 signals:
    void changeHP(int);
    void addScore(int);
    void changeSkill(int);
    void useSkill(bool);
    void endGame(bool);

protected:
    int HP,level;

};

#endif // CHARACTER_H
