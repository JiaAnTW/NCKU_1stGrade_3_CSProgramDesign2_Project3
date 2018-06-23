#include "user.h"

user::user()
{
    setPixmap(QPixmap(":/image/player_image/player.png").scaled(QSize(80.3,56.42)));
    character::HP=100;
    character::level=1;
    skill=3;
}

int user::get_skill(){
    return skill;
}

void user::using_skill_recover(){
    if(skill>0&&character::HP>0){
        character::HP=100;
        skill--;
        setPixmap(QPixmap(":/image/player_image/player.png").scaled(QSize(80.3,56.42)));
        emit character::changeHP(character::HP);
        emit changeSkill(skill);
        emit useSkill(true);
    }
}

void user::losingHP()
{
    //it's a collider
    QList<QGraphicsItem*> record_items=collidingItems();
    for(int i=0;i<record_items.size();++i){
        if(typeid(*(record_items[i]))==typeid(enemyatk)){
            scene()->removeItem(record_items[i]);
            delete record_items[i];
            if(character::HP>0){
                character::HP-=(character::level>2)?5:1;
                if(character::HP<80)
                    setPixmap(QPixmap(":/image/player_image/player2.png").scaled(QSize(80.3,56.42)));
                if(character::HP<60)
                    setPixmap(QPixmap(":/image/player_image/player3.png").scaled(QSize(80.3,56.42)));
                if(character::HP<40)
                    setPixmap(QPixmap(":/image/player_image/player4.png").scaled(QSize(80.3,56.42)));
                if(character::HP<20)
                    setPixmap(QPixmap(":/image/player_image/player4.png").scaled(QSize(80.3,56.42)));
                if(character::HP<10)
                    setPixmap(QPixmap(":/image/player_image/player5.png").scaled(QSize(80.3,56.42)));
                character::HP=(character::HP<0)?0:character::HP;
                emit character::changeHP(character::HP);
                emit character::addScore(-10);
                if(character::HP<=0)
                    emit character::endGame(false);
            }
        }
    }
}
