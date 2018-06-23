#ifndef UI_BUTTON_H
#define UI_BUTTON_H
#include <QObject>
#include <QPushButton>
#include <QString>

class ui_button: public QObject
{
    Q_OBJECT
public:
    ui_button();
    ui_button(int number);
    QPushButton *button;
    void setbutton();

public slots:
    void PressImage();
    void ReleaseImage();
    void hidemyself(bool);//hi


private:
    int type,l;
    QString R,P;
};

#endif // UI_BUTTON_H
