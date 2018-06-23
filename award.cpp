#include "award.h"
#include <QDebug>

award::award()
{

}
award::award(int type){
    switch (type) {
    case 1:
        Y=":/image/record_image/acheive_Y_ult.png";
        N=":/image/record_image/acheive_N_ult.png";
        height=288.3;
        break;
    case 2:
        Y=":/image/record_image/acheive_Y_87.png";
        N=":/image/record_image/acheive_N_87.png";
        height=292.2;
        break;
    case 3:
        Y=":/image/record_image/acheive_Y_perfect.png";
        N=":/image/record_image/acheive_N_perfect.png";
        height=292.2;
        break;
    case 4:
        Y=":/image/record_image/acheive_Y_buddha.png";
        N=":/image/record_image/acheive_N_buddha.png";
        height=288.3;
        break;
    case 5:
        Y=":/image/record_image/acheive_Y_TA.png";
        N=":/image/record_image/acheive_N_TA.png";
        height=288.3;
        break;
    case 6:
        Y=":/image/record_image/acheive_Y_cannot.png";
        N=":/image/record_image/acheive_N_cannot.png";
        height=281;
        break;
    default:
        break;
    }
}
void award::setAward(int fullfill){
       const QString address=(fullfill==1)?Y:N;
       setPixmap(QPixmap(address).scaled(282,height));
}
