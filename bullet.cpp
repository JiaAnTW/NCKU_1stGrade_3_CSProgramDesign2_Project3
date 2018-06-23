#include "bullet.h"
#include <QDebug>

bullet::bullet()
{
    setPixmap(QPixmap(":image/bullet_image/bullet_1.png").scaled(30.7,35.3));
    type=2;
}

bullet::bullet(int number){
    switch (number) {
    case 1:
        setPixmap(QPixmap(":image/bullet_image/bullet_1.png").scaled(30.7,35.3));
        break;
    case 2:
        setPixmap(QPixmap(":image/bullet_image/bullet_2.png").scaled(30.7,35.3));
        break;
    case 3:
        setPixmap(QPixmap(":image/bullet_image/bullet_2.png").scaled(30.7,35.3));
        break;
    }
    type=number;
}

void bullet::fly(){
    setPos(x()-6*cos(2*acos(0)*(60+type*15)/180),y()-6*sin(2*acos(0)*(60+type*15)/180));
    if( y() <0 )
        deletemyself(true);
}

void bullet::deletemyself(bool nothing){
    this->scene()->removeItem(this);
    delete this;
}
