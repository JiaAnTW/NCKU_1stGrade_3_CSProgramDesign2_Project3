#include "character.h"
#include <QDebug>

character::character()
{

}

int character::get_skill(){
    return -1;
}

int character::getHP(){
    return HP;
}
void character::setlevel(int number){
    level=number;
}

void character::using_skill_recover(){
    qDebug()<< "do nothing";
};

void character::losingHP()
{
    qDebug()<< "do nothing";
}

void character::Move(){
    qDebug()<< "do nothing";
}
