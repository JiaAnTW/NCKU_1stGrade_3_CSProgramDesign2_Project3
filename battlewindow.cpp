#include "battlewindow.h"
#include "ui_battlewindow.h"
#include <QDebug>

//constructor of BattleWindow

BattleWindow::BattleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BattleWindow),
    scene_start(new QGraphicsScene(0,0,800,700)),
    scene_win(new QGraphicsScene(0,0,1200,800)),
    update_timer(new QTimer),
    gametimer(new QTimer)
{    
    ui->setupUi(this);   
    bullettimer=new QTimer;
    level=1;
    gaming=false;




    //set the start window


    ui->graphicsView->setGeometry(0,0,1200,800);
    ui->graphicsView->setScene(scene_start);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //set start image
    scene_start->addPixmap(QPixmap(":/image/UI_image/start.png"));
    topic=new QGraphicsPixmapItem;
    topic->setPixmap(QPixmap(":/image/UI_image/start_text.png").scaled(660,365));
    scene_start->addItem(topic);
    topic->setPos(150,75);

    game=new ui_button(1);
    game->button=new QPushButton(this);
    game->button->setStyleSheet("QPushButton{border-image:url(:/image/UI_image/GameStart.png);}");
    game->button->setGeometry(550,500,138.5,40);
    game->setbutton();
    QObject::connect(game->button,SIGNAL(clicked(bool)),this,SLOT(GameStart(bool)));


    acheivement=new ui_button(2);
    acheivement->button=new QPushButton(this);
    acheivement->button->setStyleSheet("QPushButton{border-image:url(:/image/UI_image/acheivement.png);}");
    acheivement->button->setGeometry(550,560,138.5,40);
    acheivement->setbutton();
    QObject::connect(acheivement->button,SIGNAL(clicked(bool)),this,SLOT(set_acheivement(bool)));

    QObject::connect(acheivement->button,SIGNAL(clicked(bool)),game,SLOT(hidemyself(bool)));
    QObject::connect(game->button,SIGNAL(clicked(bool)),acheivement,SLOT(hidemyself(bool)));






    //set the Gaming window

    scene=new QGraphicsScene(0,0,800,700);
    scene->addPixmap(QPixmap(":/image/UI_image/background.png"));
    //set player
    //player=new user;
    //player->setPos(350,640);
    //scene->addItem(static_cast<QGraphicsPixmapItem*>(player));

    //set player skill box
    skill_box=new QPushButton(this);
    skill_box->setGeometry(943.4,665,230.4,39);
    skill_box->setStyleSheet("QPushButton{border-image:url(:/image/message_image/skill.png);}");
    skill_box->hide();

    //set skill message
    LCDskill= new LCDnumber(4);
    for(int i=0;i<9;++i){
       LCDskill->LCD[i]=new QPushButton(this);
       LCDskill->LCD[i]->hide();
    }


    //set player HP box
    player_hp_box=new QPushButton(this);
    player_hp_box->setGeometry(850,700,314.4,74.7);
    player_hp_box->setStyleSheet("QPushButton{border-image:url(:/image/message_image/player_hp.png);}");
    player_hp_box->hide();

    //set player HP message
    hp_player= new LCDnumber(1);
    for(int i=0;i<9;++i){
       hp_player->LCD[i]=new QPushButton(this);
       hp_player->LCD[i]->hide();
    }
    //end player setting




    //set boss atk
    atklevel=5;

    //set boss hp box
    boss_hp_box=new QPushButton(this);
    boss_hp_box->setGeometry(850,250,314.4,74.7);
    //boss_hp_box->setStyleSheet("QPushButton{border-image:url(:/image/message_image/boss_hp_1.png);}");
    boss_hp_box->hide();

    //set boss hp message
    hp_boss=new LCDnumber(2);
    for(int i=0;i<9;++i){
       hp_boss->LCD[i]=new QPushButton(this);
       hp_boss->LCD[i]->hide();
    }
    //end boss setting


    //set score
    score=0;

    //set score box
    score_box=new QPushButton(this);
    score_box->setGeometry(900,50,303.3,50);
    score_box->setStyleSheet("QPushButton{border-image:url(:/image/message_image/score.png);}");
    score_box->hide();

    //set score message
    LCDscore=new LCDnumber(3);
    LCDscore->setTotalNumber(score);
    for(int i=0;i<9;++i){
        LCDscore->LCD[i]=new QPushButton(this);
        LCDscore->LCD[i]->hide();
    }
    //end score setting






    //set fail window


    scene_fail=new QGraphicsScene(0,0,1200,800),
    scene_fail->addPixmap(QPixmap(":/image/UI_image/fail.png"));
    topic_fail_1=new QGraphicsPixmapItem;
    topic_fail_1->setPixmap(QPixmap(":/image/UI_image/fail_text_1.png").scaled(564,228));
    scene_fail->addItem(topic_fail_1);
    topic_fail_1->setPos(175,50);
    topic_fail_2=new QGraphicsPixmapItem;
    topic_fail_2->setPixmap(QPixmap(":/image/UI_image/fail_text_2.png").scaled(996,228));
    scene_fail->addItem(topic_fail_2);
    topic_fail_2->setPos(55,300);

    playagain=new ui_button(3);
    playagain->button=new QPushButton(this);
    playagain->button->setStyleSheet("QPushButton{border-image:url(:/image/UI_image/playagain.png);}");
    playagain->button->setGeometry(550,600,123.5,41.5);
    playagain->setbutton();
    playagain->button->hide();
    QObject::connect(playagain->button,SIGNAL(clicked(bool)),this,SLOT(start(bool)));





    //set win window
    scene_win=new QGraphicsScene(0,0,1200,800),
    scene_win->addPixmap(QPixmap(":/image/UI_image/win.png"));
    topic_win=new QGraphicsPixmapItem;
    topic_win->setPixmap(QPixmap(":/image/UI_image/win_text.png").scaled(744.75,309.75));
    scene_win->addItem(topic_win);
    topic_win->setPos(250,150);


    back=new ui_button(4);
    back->button=new QPushButton(this);
    back->button->setStyleSheet("QPushButton{border-image:url(:/image/UI_image/back.png);}");
    back->button->setGeometry(400,500,123.5,41.5);
    back->setbutton();
    back->button->hide();
    QObject::connect(back->button,SIGNAL(clicked(bool)),this,SLOT(fail(bool)));

    sleep=new ui_button(5);
    sleep->button=new QPushButton(this);
    sleep->button->setStyleSheet("QPushButton{border-image:url(:/image/UI_image/sleep.png);}");
    sleep->button->setGeometry(700,500,123.5,41.5);
    sleep->setbutton();
    sleep->button->hide();
    QObject::connect(sleep->button,SIGNAL(clicked(bool)),this,SLOT(set_acheivement(bool)));

    QObject::connect(sleep->button,SIGNAL(clicked(bool)),back,SLOT(hidemyself(bool)));
    QObject::connect(back->button,SIGNAL(clicked(bool)),sleep,SLOT(hidemyself(bool)));

    acheivement_deliever=new record;
    scene_record=new QGraphicsScene(0,0,1200,800),
    scene_record->addPixmap(QPixmap(":/image/UI_image/start.png"));
    for(int j=0;j<2;++j){
        for(int i=0;i<3;++i){
            int n=acheivement_deliever->sendData().at(j*3+i);
            Award[j*3+i]= new award(j*3+i+1);
            scene_record->addItem(static_cast<QGraphicsPixmapItem*>(Award[j*3+i]));
            Award[j*3+i]->setAward(n);
            Award[j*3+i]->setPos(100+i*295,150+j*305);
        }
    }
    wrong=new ui_button(6);
    wrong->button=new QPushButton(this);
    wrong->button->setStyleSheet("QPushButton{border-image:url(:/image/UI_image/wrong.png);}");
    wrong->button->setGeometry(1000,700,133.5,40);
    wrong->setbutton();
    wrong->button->hide();
    QObject::connect(wrong->button,SIGNAL(clicked(bool)),this,SLOT(start(bool)));
    topic_record=new QGraphicsPixmapItem;
    topic_record->setPixmap(QPixmap(":/image/record_image/record.png").scaled(593,80));
    scene_record->addItem(topic_record);
    topic_record->setPos(100,50);


}
//end constructor


// the functions of the game
void BattleWindow::attack(){
    switch (level) {
    case 1:
        enemyatk *attack_1[5];
        atklevel=(atklevel==5)?0:5;
        for(int i=0;i<5;++i){
            attack_1[i]= new enemyatk(atklevel+i+1);
            attack_1[i]->connect(update_timer,SIGNAL(timeout()),attack_1[i],SLOT(fly()));
            attack_1[i]->connect(player,SIGNAL(endGame(bool)),attack_1[i],SLOT(deletemyself(bool)));
            attack_1[i]->connect(boss,SIGNAL(endGame(bool)),attack_1[i],SLOT(deletemyself(bool)));
            attack_1[i]->connect(player,SIGNAL(useSkill(bool)),attack_1[i],SLOT(deletemyself(bool)));
            scene->addItem(static_cast<QGraphicsPixmapItem*>(attack_1[i]));
            attack_1[i]->setPos(boss->x()+60,boss->y()+110);
        }
        break;
    case 2:
        enemyatk *attack_2[2];
        for(int i=0;i<2;++i){
            attack_2[i]= new enemyatk(i+11);
            attack_2[i]->connect(update_timer,SIGNAL(timeout()),attack_2[i],SLOT(fly()));
            attack_2[i]->connect(player,SIGNAL(endGame(bool)),attack_2[i],SLOT(deletemyself(bool)));
            attack_2[i]->connect(boss,SIGNAL(endGame(bool)),attack_2[i],SLOT(deletemyself(bool)));
            attack_2[i]->connect(player,SIGNAL(useSkill(bool)),attack_2[i],SLOT(deletemyself(bool)));
            scene->addItem(static_cast<QGraphicsPixmapItem*>(attack_2[i]));
            attack_2[i]->setPos(boss->x()+40,boss->y()+70);
        }
        break;
    case 3:
        enemyatk *attack_3;
        atklevel=(atklevel==1)?0:1;
        attack_3= new enemyatk(atklevel+13,boss->x(),boss->y(),player->x(),player->y());
        attack_3->connect(update_timer,SIGNAL(timeout()),attack_3,SLOT(fly()));
        attack_3->connect(player,SIGNAL(endGame(bool)),attack_3,SLOT(deletemyself(bool)));
        attack_3->connect(boss,SIGNAL(endGame(bool)),attack_3,SLOT(deletemyself(bool)));
        attack_3->connect(player,SIGNAL(useSkill(bool)),attack_3,SLOT(deletemyself(bool)));
        scene->addItem(static_cast<QGraphicsPixmapItem*>(attack_3));
        attack_3->setPos(boss->x()+117,boss->y()+120);
        break;
    case 4:
        enemyatk *attack_4[6];
        atklevel+=15;
        for(int i=0;i<3;++i){
            attack_4[i]= new enemyatk(i+15,0,0,atklevel+i*5,0);
            attack_4[5-i]= new enemyatk(i+15,0,0,atklevel+i*5-180,0);
            attack_4[i]->connect(update_timer,SIGNAL(timeout()),attack_4[i],SLOT(fly()));
            attack_4[i]->connect(player,SIGNAL(endGame(bool)),attack_4[i],SLOT(deletemyself(bool)));
            attack_4[i]->connect(boss,SIGNAL(endGame(bool)),attack_4[i],SLOT(deletemyself(bool)));
            attack_4[i]->connect(player,SIGNAL(useSkill(bool)),attack_4[i],SLOT(deletemyself(bool)));
            scene->addItem(static_cast<QGraphicsPixmapItem*>(attack_4[i]));
            attack_4[i]->setPos(boss->x()+90,boss->y()+75);
        }
        atklevel=(atklevel>=360)?0:atklevel;
        break;
    default:
        break;
    }


}

void BattleWindow::scorecounter(int howmuch){
    score+=howmuch;
    if(score<0)
        score=0;
    emit score_change(score);
}

void BattleWindow::levelChange(bool alive){// set level
    scene->removeItem(static_cast<QGraphicsPixmapItem*>(boss));
    delete boss;
    QObject::disconnect(bullettimer,SIGNAL(timeout()),this,SLOT(attack()));
    if(alive==true){
        ++level;
        player->setlevel(level);
        setBoss(level);
        if(level>4){
            acheivement_deliever->recieveData(level,player->getHP(),player->get_skill(),score);
            GameEnd(false);
            win();
        }
    }
    else{
        acheivement_deliever->recieveData(level,player->getHP(),player->get_skill(),score);
        GameEnd(false);
        fail(false);//hi
    }
}

void BattleWindow::setBoss(int type){
    boss = new enemy(type);
    scene->addItem(static_cast<QGraphicsPixmapItem*>(boss));
    boss->setlevel(level);
    QObject::connect(update_timer,SIGNAL(timeout()),boss,SLOT(losingHP()));
    QObject::connect(update_timer,SIGNAL(timeout()),boss,SLOT(Move()));
    const QString address="QPushButton{border-image:url(:/image/message_image/boss_hp_"+QString::number(level)+".png);}";
    boss_hp_box->setStyleSheet(address);
    if(level!=1){
        QObject::connect(boss,SIGNAL(changeHP(int)),hp_boss,SLOT(changeNumber(int)));
        hp_boss->changeNumber(boss->getHP());
        QObject::connect(boss,SIGNAL(endGame(bool)),this,SLOT(levelChange(bool)));
        QObject::connect(boss,SIGNAL(addScore(int)),this,SLOT(scorecounter(int)));
        QObject::connect(bullettimer,SIGNAL(timeout()),this,SLOT(attack()));
        atklevel=0;
    }
    if(level>2)
        bullettimer->start(250);
}


void BattleWindow::GameStart(bool click){
    if(click==false){
        gaming=true;
        update_timer->start(10);
        bullettimer->start(1500);
        ui->graphicsView->setGeometry(50,50,800,700);
        ui->graphicsView->setScene(scene);
        level=1;
        setBoss(level);
        player=new user;
        player->setPos(350,640);
        player->setlevel(level);
        scene->addItem(static_cast<QGraphicsPixmapItem*>(player));
        QObject::connect(update_timer,SIGNAL(timeout()),player,SLOT(losingHP()));
        QObject::connect(player,SIGNAL(changeSkill(int)),LCDskill,SLOT(changeNumber(int)));
        QObject::connect(player,SIGNAL(changeHP(int)),hp_player,SLOT(changeNumber(int)));
        QObject::connect(player,SIGNAL(endGame(bool)),this,SLOT(levelChange(bool)));
        QObject::connect(player,SIGNAL(addScore(int)),this,SLOT(scorecounter(int)));
        QObject::connect(bullettimer,SIGNAL(timeout()),this,SLOT(attack()));
        QObject::connect(boss,SIGNAL(changeHP(int)),hp_boss,SLOT(changeNumber(int)));
        QObject::connect(boss,SIGNAL(endGame(bool)),this,SLOT(levelChange(bool)));
        QObject::connect(boss,SIGNAL(addScore(int)),this,SLOT(scorecounter(int)));
        QObject::connect(this,SIGNAL(score_change(int)),LCDscore,SLOT(changeNumber(int)));
        skill_box->show();
        LCDskill->LCD[0]->show();
        LCDskill->setTotalNumber(0);
        LCDskill->changeNumber(3);
        player_hp_box->show();
        hp_player->LCD[0]->show();
        hp_player->setTotalNumber(0);
        hp_player->changeNumber(player->getHP());
        boss_hp_box->show();
        hp_boss->LCD[0]->show();
        hp_boss->setTotalNumber(0);
        hp_boss->changeNumber(boss->getHP());
        score_box->show();
        LCDscore->LCD[0]->show();
        LCDscore->setNumber(0);
        LCDscore->LCD[0]->setGeometry(LCDscore->getPos(0),65,17,26);

    }
}

void BattleWindow::GameEnd(bool click){
    if(click==false){
        gaming=false;
        QObject::disconnect(update_timer,SIGNAL(timeout()),player,SLOT(losingHP()));
        QObject::disconnect(player,SIGNAL(addScore(int)),this,SLOT(scorecounter(int)));
        QObject::disconnect(player,SIGNAL(changeSkill(int)),LCDskill,SLOT(changeNumber(int)));
        QObject::disconnect(player,SIGNAL(changeHP(int)),hp_player,SLOT(changeNumber(int)));
        QObject::disconnect(player,SIGNAL(endGame(bool)),this,SLOT(levelChange(bool)));
        QObject::disconnect(this,SIGNAL(score_change(int)),LCDscore,SLOT(changeNumber(int)));
        skill_box->hide();
        LCDskill->changeNumber(3);
        LCDskill->LCD[0]->hide();
        player_hp_box->hide();
        hp_player->changeNumber(0);
        hp_player->LCD[0]->hide();
        boss_hp_box->hide();
        hp_boss->setTotalNumber(0);
        hp_boss->changeNumber(0);
        hp_boss->LCD[0]->hide();
        score_box->hide();
        LCDscore->changeNumber(0);
        LCDscore->LCD[0]->hide();
        delete player;

    }
}

void BattleWindow::start(bool click){
    if(click==false){
        ui->graphicsView->setScene(scene_start);
        game->button->show();
        acheivement->button->show();
    }
}

void BattleWindow::win(){
    ui->graphicsView->setGeometry(0,0,1200,800);
    ui->graphicsView->setScene(scene_win);
    back->button->show();
    sleep->button->show();
}

void BattleWindow::fail(bool click){
    if(click==false){
        ui->graphicsView->setGeometry(0,0,1200,800);
        ui->graphicsView->setScene(scene_fail);
        playagain->button->show();
    }
}

void BattleWindow::set_acheivement(bool click){
    if(click==false){
        ui->graphicsView->setGeometry(0,0,1200,800);
        ui->graphicsView->setScene(scene_record);
        wrong->button->show();
        for(int j=0;j<2;++j){
            for(int i=0;i<3;++i){
                int n=acheivement_deliever->sendData().at(j*3+i);
                Award[j*3+i]->setAward(n);
            }
        }
    }
}
// end of function setting



// the control of the game
void BattleWindow::keyPressEvent(QKeyEvent *event){
    if(gaming==true){
    switch (event->key()) {
    case Qt::Key_W:
        if(player->y()>0)
            player->setPos(player->x(),player->y()-15);
        break;

    case Qt::Key_S:
        if(player->y()<640)
            player->setPos(player->x(),player->y()+15);
        break;

    case Qt::Key_A:
        if(player->x()>0)
            player->setPos(player->x()-15,player->y());
        break;

    case Qt::Key_D:
        if(player->x()<720)
            player->setPos(player->x()+15,player->y());
        break;
    case Qt::Key_R:
        player-> using_skill_recover();
        break;
    }
    }
}


void  BattleWindow::mousePressEvent(QMouseEvent *click){
    if(gaming==true){
        for(int i=0;i<3;i++){
            bullet *shootme = new bullet(i+1);
            shootme->setPos(player->x()+player->pixmap().width()/2 - shootme->pixmap().width()/2 , player->y()+player->pixmap().height()/2 - shootme->pixmap().height()/2);
            shootme->connect(update_timer,SIGNAL(timeout()),shootme,SLOT(fly()));
            scene->addItem(static_cast<QGraphicsPixmapItem*>(shootme));
        }
    }
}


//end of the control setting



BattleWindow::~BattleWindow()
{
    delete ui;
}
