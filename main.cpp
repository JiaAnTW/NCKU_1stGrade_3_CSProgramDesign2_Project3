#include "battlewindow.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BattleWindow w;
    w.setGeometry(0,0,1200,800);
    w.setStyleSheet("QWidget{ background-color:rgb(49,96,138)}");
    w.show();

    return a.exec();
}
