#include "lcdnumber.h"
#include <QDebug>

LCDnumber::LCDnumber()
{
    length=0;
}

LCDnumber::LCDnumber(int type){
    switch (type) {
        case 1:  //player's HP
            xpos=1095;
            ypos=725;
            break;
        case 2:  //boss's HP
            xpos=1105;
            ypos=275;
            break;
        case 3:// score
            xpos=1110;
            ypos=65;
            break;
        case 4:// score
            xpos=1110;
            ypos=672.5;
            break;
    }
}

void LCDnumber::setNumber(int where){
    QString address="QPushButton{border-image:url(:/image/message_image/";
    address+=QString::number(save.at(where));
    address+=".png);}";
    LCD[where]->setStyleSheet(address);
}

void LCDnumber::setTotalNumber(int input){
    save.clear();
    save.append(input%10);
    for(int i=1;pow(10,i)<=input;++i){
        int test=input/pow(10,i);
        save.append(test%10);
    }
    length=save.size();
}

float LCDnumber::getPos(float where){
   return xpos-17*(where);
}

void LCDnumber::changeNumber(int input){
    if(input>=0){
        int length_before=length;
        setTotalNumber(input);
        if(length_before>=length){ //when 10->9,9->8.... or 100->99....
            for(int i=0;i< length_before;++i){
                if(i<length){
                    setNumber(i);
                    LCD[i]->setGeometry(getPos(i),ypos,17,26);
                }
                else
                    LCD[i]->hide();
            }
        }
        else{ //when9->10,99->100......
            for(int i=0;i< length;++i){
                if(i<length_before){
                    setNumber(i);
                    LCD[i]->setGeometry(getPos(i),ypos,17,26);
                }
                else{
                    LCD[i]->show();
                    setNumber(i);
                    LCD[i]->setGeometry(getPos(i),ypos,17,26);
                }
            }
        }
    }
}

