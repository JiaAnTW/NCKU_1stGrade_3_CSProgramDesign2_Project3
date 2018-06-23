#ifndef USER_H
#define USER_H
#include "character.h"


class user :public character
{

public:
    user();
    int get_skill();
    void using_skill_recover();


public slots:
    void losingHP();


private:
    int skill;
};

#endif // USER_H
