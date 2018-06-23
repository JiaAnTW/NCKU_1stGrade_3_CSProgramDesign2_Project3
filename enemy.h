#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <cmath>
#include "character.h"
#include "bullet.h"


class enemy : public character
{

public:
    enemy();
    enemy(int type);
    int getHP();
    int get_skill();
    void using_skill_recover();


public slots:
    void losingHP();
    void Move();



private:
    bool turnleftside();
    int  boss_level;
    float circleangle,region_L,region_R;
    bool turnleft;
};

#endif // ENEMY_H
