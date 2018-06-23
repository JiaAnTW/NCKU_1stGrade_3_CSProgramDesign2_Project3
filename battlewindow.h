#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <QPushButton>
#include <QVector>
#include <QString>
#include <cmath>
#include "bullet.h"
#include "enemyatk.h"
#include "character.h"
#include "user.h"
#include "enemy.h"
#include "lcdnumber.h"
#include "ui_button.h"
#include "record.h"
#include "award.h"

namespace Ui {
class BattleWindow;
}

class BattleWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit BattleWindow(QWidget *parent = 0);
    ~BattleWindow();
    void  keyPressEvent(QKeyEvent *event);
    void  mousePressEvent(QMouseEvent *click);
    void setBoss(int type);

public slots:

    void attack();
    void scorecounter(int number);
    void levelChange(bool alive);
    void GameStart(bool);
    void GameEnd(bool);
    void start(bool);
    void win();
    void fail(bool);
    void set_acheivement(bool);


signals:
    void score_change(int);

private:
    Ui::BattleWindow *ui;
    QGraphicsScene *scene,*scene_start,*scene_win,*scene_fail,*scene_record;
    QGraphicsPixmapItem *topic,*topic_fail_1,*topic_fail_2,*topic_win,*topic_record;
    character *player,*boss;
    QTimer *update_timer,*gametimer,*bullettimer,*attacktimer;
    QPushButton *boss_hp_box,*player_hp_box,*score_box,*skill_box,*test;
    LCDnumber *hp_player,*hp_boss,*LCDscore,*LCDskill;
    ui_button *game,*acheivement,*playagain,*back,*sleep,*wrong;
    record *acheivement_deliever;
    award *Award[6];

    int level,atklevel,score;
    bool gaming;
};
#endif // BATTLEWINDOW_H
