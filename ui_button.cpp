#include "ui_button.h"

ui_button::ui_button()
{

}

ui_button::ui_button(int number)
{
    switch (number) {
    case 1:
        P="QPushButton{border-image:url(:/image/UI_image/GameStart_press.png);}";
        R="QPushButton{border-image:url(:/image/UI_image/GameStart.png);}";
        break;
    case 2:
        P="QPushButton{border-image:url(:/image/UI_image/acheivement_press.png);}";
        R="QPushButton{border-image:url(:/image/UI_image/acheivement.png);}";
        break;
    case 3:
        P="QPushButton{border-image:url(:/image/UI_image/playagain_press.png);}";
        R="QPushButton{border-image:url(:/image/UI_image/playagain.png);}";
        break;
    case 4:
        P="QPushButton{border-image:url(:/image/UI_image/back_press.png);}";
        R="QPushButton{border-image:url(:/image/UI_image/back.png);}";
        break;
    case 5:
        P="QPushButton{border-image:url(:/image/UI_image/sleep_press.png);}";
        R="QPushButton{border-image:url(:/image/UI_image/sleep.png);}";
        break;
    case 6:
        P="QPushButton{border-image:url(:/image/UI_image/wrong_press.png);}";
        R="QPushButton{border-image:url(:/image/UI_image/wrong.png);}";
        break;
    }
}

void ui_button::setbutton(){
    QObject::connect(button,SIGNAL(pressed()),this,SLOT(PressImage()));
    QObject::connect(button,SIGNAL(released()),this,SLOT(ReleaseImage()));
    QObject::connect(button,SIGNAL(clicked(bool)),this,SLOT(hidemyself(bool)));
}


void ui_button::PressImage(){
    button->setStyleSheet(P);
}

void ui_button::ReleaseImage(){
    button->setStyleSheet(R);
}
void ui_button::hidemyself(bool){
    button->hide();
}
