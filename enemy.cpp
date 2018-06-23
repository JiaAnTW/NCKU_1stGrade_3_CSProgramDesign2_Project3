#include "enemy.h"
#include <QDebug>

enemy::enemy()
{
    setPixmap(QPixmap(":/image/boss_image/Boss_1.png").scaled(143.75,150.25));
}
enemy::enemy(int type)
{
    boss_level=type;
    switch (type) {
        case 1:
            setPixmap(QPixmap(":/image/boss_image/Boss_1.png").scaled(143.75,150.25));
            setPos(300,50);
            turnleft=true;
            region_L=70;
            region_R=630;
            character::HP=5;
            break;
        case 2:
            setPixmap(QPixmap(":/image/boss_image/Boss_2.png").scaled(102.25,143.5));
            setPos(400,300);
            circleangle=0;
            character::HP=10;
            break;
        case 3:
            setPixmap(QPixmap(":/image/boss_image/Boss_3.png").scaled(234,200));
            setPos(350,100);
            region_L=70;
            region_R=530;
            character::HP=25;
            break;
        case 4:
            setPixmap(QPixmap(":/image/boss_image/Boss_4.png").scaled(186.8,209.2));
            setPos(300,100);
            character::HP=40;
            break;

    }

}

int enemy::get_skill(){
    return -1;
}
int enemy::getHP(){
    return character::HP;
}

void enemy::using_skill_recover(){
    qDebug()<< "do nothing";
};

void enemy::losingHP()
{
    //it's a collider
    QList<QGraphicsItem*> record_items=collidingItems();
    for(int i=0;i<record_items.size();++i){
        if(typeid(*(record_items[i]))==typeid(bullet)){
            scene()->removeItem(record_items[i]);
            character::HP--;
            delete record_items[i];
            emit character::changeHP(character::HP);
            if(character::HP==0){
                emit character::addScore(10);
                emit character::endGame(true);
            }
            else{
                if(level>2)
                    emit character::addScore(2);
                else
                    emit character::addScore(1);
            }
        }
    }   

}

void enemy::Move(){
    switch (boss_level) {
        case 1:
            if(turnleftside())
                setPos(x()-1,y());
            else
                setPos(x()+1,y());
            break;

        case 2:
            setPos(350+150*cos(2*acos(0)*circleangle/180),200+150*sin(2*acos(0)*circleangle/180));
            if(circleangle!=360)
                circleangle+=0.5;
            else
                circleangle=0;
            break;

        case 3:
            if(turnleftside()){
                if(x()>250)
                    setPos(x()-pow(2,-1/2),y()-0.5*pow(2,-1/2));
                else
                    setPos(x()-pow(2,-1/2),y()+0.5*pow(2,-1/2));
            }
            else{
                if(x()<250)
                    setPos(x()+pow(2,-1/2),y()-0.5*pow(2,-1/2));
                else
                    setPos(x()+pow(2,-1/2),y()+0.5*pow(2,-1/2));
            }
            break;

        case 4:
            setPos(300+250*cos(2*acos(0)*circleangle/180),100+50*sin(2*acos(0)*circleangle/180));
            if(circleangle!=360)
                circleangle+=1.5;
            else
                circleangle=0;
                break;

        default:
            if(turnleftside())
                setPos(x()-1,y());
            else
                setPos(x()+1,y());
            break;
    }

}

bool enemy::turnleftside(){
    if(x()==region_L)
        turnleft=false;
    if(x()==region_R)
        turnleft=true;
    return turnleft;
}
