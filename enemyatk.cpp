#include "enemyatk.h"
#include <QDebug>

enemyatk::enemyatk()
{
    setPixmap(QPixmap(":image/bullet_image/HelloWorld/Hello_H.png").scaled(40,40));
    setPos(400,100);
}

enemyatk::enemyatk(int type, float xpos_boss, float ypos_boss, float xpos_player, float ypos_player){
    srand(time(NULL));
    switch (type) {
        // Hello World
        case 1:
            setPixmap(QPixmap(":image/bullet_image/HelloWorld/Hello_H.png").scaled(40,40));
            break;
        case 2:
            setPixmap(QPixmap(":image/bullet_image/HelloWorld/Hello_E.png").scaled(40,40));
            break;
        case 3:
            setPixmap(QPixmap(":image/bullet_image/HelloWorld/Hello_L.png").scaled(40,40));
            break;
        case 4:
            setPixmap(QPixmap(":image/bullet_image/HelloWorld/Hello_L.png").scaled(40,40));
            break;
        case 5:
            setPixmap(QPixmap(":image/bullet_image/HelloWorld/Hello_O.png").scaled(40,40));
            break;

        case 6:
            setPixmap(QPixmap(":image/bullet_image/HelloWorld/World_W.png").scaled(40,40));
            break;
        case 7:
            setPixmap(QPixmap(":image/bullet_image/HelloWorld/World_O.png").scaled(40,40));
            break;

        case 8:
            setPixmap(QPixmap(":image/bullet_image/HelloWorld/World_R.png").scaled(40,40));
            break;
        case 9:
            setPixmap(QPixmap(":image/bullet_image/HelloWorld/World_L.png").scaled(40,40));
            break;
        case 10:
            setPixmap(QPixmap(":image/bullet_image/HelloWorld/World_D.png").scaled(40,40));
            break;

            //for and while loop

        case 11:
            setPixmap(QPixmap(":image/bullet_image/loop/for.png").scaled(47.3,46.4));
            xpos[1]=1;//left or right
            xpos[2]=0;//angle
            break;
        case 12:
            setPixmap(QPixmap(":image/bullet_image/loop/while.png").scaled(47.3,46.4));
            xpos[1]=-1;
            xpos[2]=0;
            break;

            // class
        case 13:
            setPixmap(QPixmap(":image/bullet_image/class/ctor.png").scaled(40.6,39.6));
            xpos[0]=(xpos_player+40-xpos_boss-117)/(700-ypos_boss);
            xpos[1]=(y()<ypos_player)?1:-1;
            break;

        case 14:
            setPixmap(QPixmap(":image/bullet_image/class/dtor.png").scaled(21.25,56.25));
            xpos[0]=(xpos_player+40-xpos_boss-117)/(700-ypos_boss);
            xpos[1]=(y()<ypos_player)?1:-1;
            break;

            //Qt
        case 15:
            setPixmap(QPixmap(":image/bullet_image/evilQt/SIGNAL.png").scaled(40,40));
            xpos[0]=xpos_player;
            break;

        case 16:
            setPixmap(QPixmap(":image/bullet_image/evilQt/QPushButton.png").scaled(40,40));
            xpos[0]=xpos_player;
            break;

        case 17:
            setPixmap(QPixmap(":image/bullet_image/evilQt/SLOT.png").scaled(40,40));
            xpos[0]=xpos_player;
            break;

    }
    if(type<6)
        att_type=type;
    else if(type<11)
        att_type=type-5;
    else if(type<13){
        att_type=type;
    }
    else
        att_type=type;
}

void enemyatk::fly(){
    if(att_type<11){
        setPos(x()-2*cos(2*acos(0)*(45+att_type*15)/180),y()+2*sin(2*acos(0)*(45+att_type*15)/180));
    }
    else if(att_type==11||att_type==12){
       xpos[2]+=5;
       setPos(x()+xpos[1]*4*sin(2*acos(0)*(xpos[2])/180),y()+3);
       if(xpos[2]>=360)
            xpos[2]=0;
    }
    else if(att_type<15){
        setPos(x()+5*xpos[0],y()+5*xpos[1]);
    }
    else if(att_type<18){
        setPos(x()-5*cos(2*acos(0)*(xpos[0])/180),y()+5*sin(2*acos(0)*(xpos[0])/180));
    }
    if( y()>700 )
        deletemyself(true);
}

void enemyatk::deletemyself(bool nothing){
    scene()->removeItem(this);
    delete this;
}
