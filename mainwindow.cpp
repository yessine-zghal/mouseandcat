#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    myTimer = new QTimer(this);
    cattTimer = new QTimer(this);
    catt4Timer = new QTimer(this);
    t = new QTime;
    time1 = new QTime;
    time2 = new QTime;
    time3 = new QTime;
    time4 = new QTime;

    ui->setupUi(this);
    this->scene = new QGraphicsScene(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2);
    ui->graphicsView->setScene(scene);
    myTimer->start(50);
    cattTimer->start(70);
    catt4Timer->start(50);

    scene->setBackgroundBrush(Qt::darkBlue);
    scene->addPixmap(QPixmap(":/new/prefix1/images/map.png"));
    ball = new Ball();
    mou = new Mouse();
    myMap = new Map();
    cat1 = new Cat(1,430,70);
    cat2 = new Cat(2,40,70);
    cat3 = new Cat(3,40,550);
    cat4 = new Cat(4,430,550);
    scene->addItem(myMap);
    scene->addItem(ball);
    scene->addItem(mou);
    scene->addItem(cat1);
    scene->addItem(cat2);
    scene->addItem(cat3);
    scene->addItem(cat4);
    connect(myTimer,SIGNAL(timeout()),this,SLOT(update()));
    connect(cattTimer,SIGNAL(timeout()),this,SLOT(ca1Update()));
    connect(cattTimer,SIGNAL(timeout()),this,SLOT(cat2Update()));
    connect(cattTimer,SIGNAL(timeout()),this,SLOT(cat3Update()));
    connect(catt4Timer,SIGNAL(timeout()),this,SLOT(cat4Update()));
    ui->label->setText("SCORE : ");
    ui->pointlabel->setNum(point);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{

    qDebug()<<e->x()<<e->y();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_D){//right
        mou->setDirection(1);
        static_cast<Cat*>(cat3)->mouChangeDir();
    }
    if(e->key()==Qt::Key_S){//dwon
        mou->setDirection(2);
        static_cast<Cat*>(cat3)->mouChangeDir();
    }
    if(e->key()==Qt::Key_A){
        mou->setDirection(3);
        static_cast<Cat*>(cat3)->mouChangeDir();
    }
    if(e->key()==Qt::Key_W){
        mou->setDirection(4);
        static_cast<Cat*>(cat3)->mouChangeDir();
    }
}

int MainWindow::encounterCat()
{

    if((mou->moux-6 < cat1->posx && mou->moux+6 > cat1->posx && mou->mouy == cat1->posy)||
       (mou->mouy-6 < cat1->posy && mou->mouy+6 > cat1->posy && mou->moux == cat1->posx)){
        if(static_cast<Cat*>(cat1)->getcatfear()==0){
            return 0;
        }
        else if(static_cast<Cat*>(cat1)->getcatfear()==1||static_cast<Cat*>(cat1)->getcatfear()==2){
            return 1;
        }
    }
    else if((mou->moux-6 < cat2->posx && mou->moux+6 > cat2->posx && mou->mouy == cat2->posy)||
            (mou->mouy-6 < cat2->posy && mou->mouy+6 > cat2->posy && mou->moux == cat2->posx)){
        if(static_cast<Cat*>(cat2)->getcatfear()==0){
            return 0;
        }
        else if(static_cast<Cat*>(cat2)->getcatfear()==1||static_cast<Cat*>(cat2)->getcatfear()==2){
            return 2;
        }
    }
    else if((mou->moux-6 < cat3->posx && mou->moux+6 > cat3->posx && mou->mouy == cat3->posy)||
            (mou->mouy-6 < cat3->posy && mou->mouy+6 > cat3->posy && mou->moux == cat3->posx)){
        if(static_cast<Cat*>(cat3)->getcatfear()==0){
            return 0;
        }
        else if(static_cast<Cat*>(cat3)->getcatfear()==1||static_cast<Cat*>(cat3)->getcatfear()==2){
            return 3;
        }
    }
    else if((mou->moux-6 < cat4->posx && mou->moux+6 > cat4->posx && mou->mouy == cat4->posy)||
            (mou->mouy-6 < cat4->posy && mou->mouy+6 > cat4->posy && mou->moux == cat4->posx)){
        if(static_cast<Cat*>(cat4)->getcatfear()==0){
            return 0;
        }
        else if(static_cast<Cat*>(cat4)->getcatfear()==1||static_cast<Cat*>(cat4)->getcatfear()==2){
            return 4;
        }
    }
    return 5;
}

bool MainWindow::eatPowerPill()
{
    if(ball->pathPoints[mou->moux][mou->mouy] == 3)
        return true;
    else {
        return false;
    }
}

void MainWindow::catTurnWhite()
{
    if((t->elapsed()>7000&&t->elapsed()<7100)||(t->elapsed()>8000&&t->elapsed()<8100)||(t->elapsed()>9000&&t->elapsed()<9100)){
        if(static_cast<Cat*>(cat1)->getcatfear()!=0&&static_cast<Cat*>(cat1)->getcatfear()!=3)
            static_cast<Cat*>(cat1)->catTurnWhite();
        if(static_cast<Cat*>(cat2)->getcatfear()!=0&&static_cast<Cat*>(cat2)->getcatfear()!=3)
            static_cast<Cat*>(cat2)->catTurnWhite();
        if(static_cast<Cat*>(cat3)->getcatfear()!=0&&static_cast<Cat*>(cat3)->getcatfear()!=3)
            static_cast<Cat*>(cat3)->catTurnWhite();
        if(static_cast<Cat*>(cat4)->getcatfear()!=0&&static_cast<Cat*>(cat4)->getcatfear()!=3)
            static_cast<Cat*>(cat4)->catTurnWhite();
    }
}

void MainWindow::catTurnBlue()
{
    if((t->elapsed()>7500&&t->elapsed()<7600)||(t->elapsed()>8500&&t->elapsed()<8600)||(t->elapsed()>9500&&t->elapsed()<9600)){

        if(static_cast<Cat*>(cat1)->getcatfear()!=0&&static_cast<Cat*>(cat1)->getcatfear()!=3)
            static_cast<Cat*>(cat1)->cattTurnBlue();
        if(static_cast<Cat*>(cat2)->getcatfear()!=0&&static_cast<Cat*>(cat2)->getcatfear()!=3)
            static_cast<Cat*>(cat2)->cattTurnBlue();
        if(static_cast<Cat*>(cat3)->getcatfear()!=0&&static_cast<Cat*>(cat3)->getcatfear()!=3)
            static_cast<Cat*>(cat3)->cattTurnBlue();
        if(static_cast<Cat*>(cat4)->getcatfear()!=0&&static_cast<Cat*>(cat4)->getcatfear()!=3)
            static_cast<Cat*>(cat4)->cattTurnBlue();
    }
}

void MainWindow::checkEncounterCat()
{
    if(encounterCat()==0){
        g = new gameover(point);
        g->show();
        connect(g,SIGNAL(closeGame()),this,SLOT(closeGame()));
        disconnect(myTimer,SIGNAL(timeout()),this,SLOT(update()));
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(ca1Update()));
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat2Update()));
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat3Update()));
        disconnect(catt4Timer,SIGNAL(timeout()),this,SLOT(cat4Update()));
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat1UpdateWhenScared()));
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat2UpdateWhenScared()));
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat3UpdateWhenScared()));
        disconnect(catt4Timer,SIGNAL(timeout()),this,SLOT(cat4UpdateWhenScared()));
    }
    else if(encounterCat()==1){
        point+=200;
        ui->pointlabel->setNum(point);
        cat1->posx = 430;
        cat1->posy = 70;
        qDebug()<<"disconnectscared1aaaaa";
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat1UpdateWhenScared()));
        time1->start();
        qDebug()<<time1->elapsed();
        static_cast<Cat*>(cat1)->catTurnEyeball();
        eyeTurnNormal1 = true;
    }
    else if(encounterCat()==2){
        point+=200;
        ui->pointlabel->setNum(point);
        cat2->posx = 40;
        cat2->posy = 70;
        qDebug()<<"disconnectscared2aaaaa";
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat2UpdateWhenScared()));
        time2->start();
        qDebug()<<time2->elapsed();
        static_cast<Cat*>(cat2)->catTurnEyeball();
        eyeTurnNormal2 = true;
    }
    else if(encounterCat()==3){
        point+=200;
        ui->pointlabel->setNum(point);
        cat3->posx = 40;
        cat3->posy = 550;
        qDebug()<<"disconnectscared3aaaaa";
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat3UpdateWhenScared()));
        time3->start();
        qDebug()<<time3->elapsed();
        static_cast<Cat*>(cat3)->catTurnEyeball();
        eyeTurnNormal3 = true;
    }
    else if(encounterCat()==4){
        point+=200;
        ui->pointlabel->setNum(point);
        cat4->posx = 430;
        cat4->posy = 550;
        qDebug()<<"disconnectscared4aaaaa";
        disconnect(catt4Timer,SIGNAL(timeout()),this,SLOT(cat4UpdateWhenScared()));
        time4->start();
        qDebug()<<time4->elapsed();
        static_cast<Cat*>(cat4)->catTurnEyeball();
        eyeTurnNormal4 = true;
    }
}

void MainWindow::update()
{
    mou->move();

    if(ball->pathPoints[mou->moux][mou->mouy] == 1){//eat ball
        static_cast<Ball*>(ball)->clearPoints(mou->moux,mou->mouy);//path are setted to 0 only in *ball
        point+=10;
        ui->pointlabel->setNum(point);
    }

    if(eatPowerPill()){//eat powerpill
        if(static_cast<Cat*>(cat1)->getcatfear()==0){
            qDebug()<<"disconnect1bbb connectscared1bbb";
            disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(ca1Update()));
            connect(cattTimer,SIGNAL(timeout()),this,SLOT(cat1UpdateWhenScared()));
        }
        if(static_cast<Cat*>(cat1)->getcatfear()==3){
            qDebug()<<"connectscared1bbb";
            connect(cattTimer,SIGNAL(timeout()),this,SLOT(cat1UpdateWhenScared()));
        }
        if(static_cast<Cat*>(cat2)->getcatfear()==0){
            qDebug()<<"disconnect2bbb connectscared2bbb";
            disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat2Update()));
            connect(cattTimer,SIGNAL(timeout()),this,SLOT(cat2UpdateWhenScared()));
        }
        if(static_cast<Cat*>(cat2)->getcatfear()==3){
            qDebug()<<"connectscared2bbb";
            connect(cattTimer,SIGNAL(timeout()),this,SLOT(cat2UpdateWhenScared()));
        }
        if(static_cast<Cat*>(cat3)->getcatfear()==0){
            qDebug()<<"disconnect3bbb connectscared3bbb";
            disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat3Update()));
            connect(cattTimer,SIGNAL(timeout()),this,SLOT(cat3UpdateWhenScared()));
        }
        if(static_cast<Cat*>(cat3)->getcatfear()==3){
            qDebug()<<"connectscared3bbb";
            connect(cattTimer,SIGNAL(timeout()),this,SLOT(cat3UpdateWhenScared()));
        }
        if(static_cast<Cat*>(cat4)->getcatfear()==0){
            qDebug()<<"disconnect4bbb connectscared4bbb";
            disconnect(catt4Timer,SIGNAL(timeout()),this,SLOT(cat4Update()));
            connect(catt4Timer,SIGNAL(timeout()),this,SLOT(cat4UpdateWhenScared()));
        }
        if(static_cast<Cat*>(cat4)->getcatfear()==3){
            qDebug()<<"connectscared4bbb";
            connect(catt4Timer,SIGNAL(timeout()),this,SLOT(cat4UpdateWhenScared()));
        }
        static_cast<Cat*>(cat1)->cattTurnBlue();
        static_cast<Cat*>(cat2)->cattTurnBlue();
        static_cast<Cat*>(cat3)->cattTurnBlue();
        static_cast<Cat*>(cat4)->cattTurnBlue();
        t->start();
    }
    catTurnWhite();
    catTurnBlue();
    if(t->elapsed()>10000&&t->elapsed()<10100){
        if(static_cast<Cat*>(cat1)->getcatfear()!=0){
            qDebug()<<"disconnectscared1ccc connect1ccc";
            connect(cattTimer,SIGNAL(timeout()),this,SLOT(ca1Update()));
            disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat1UpdateWhenScared()));
        }
        if(static_cast<Cat*>(cat2)->getcatfear()!=0){
           qDebug()<<"disconnectscared2ccc connect2ccc";
            connect(cattTimer,SIGNAL(timeout()),this,SLOT(cat2Update()));
            disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat2UpdateWhenScared()));
        }
        if(static_cast<Cat*>(cat3)->getcatfear()!=0){
            qDebug()<<"disconnectscared3ccc connect3ccc";
            connect(cattTimer,SIGNAL(timeout()),this,SLOT(cat3Update()));
            disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat3UpdateWhenScared()));
        }
        if(static_cast<Cat*>(cat4)->getcatfear()!=0){
            qDebug()<<"disconnectscared4ccc connect4ccc";
            connect(catt4Timer,SIGNAL(timeout()),this,SLOT(cat4Update()));
            disconnect(catt4Timer,SIGNAL(timeout()),this,SLOT(cat4UpdateWhenScared()));
        }
        static_cast<Cat*>(cat1)->catNotScared();
        static_cast<Cat*>(cat2)->catNotScared();
        static_cast<Cat*>(cat3)->catNotScared();
        static_cast<Cat*>(cat4)->catNotScared();
    }
    if(ball->pathPoints[mou->moux][mou->mouy] == 3){//check if eat powerpill
        static_cast<Ball*>(ball)->clearPoints(mou->moux,mou->mouy);//path are setted to 0 only in *ball
        point+=50;
        ui->pointlabel->setNum(point);
    }

    if(static_cast<Ball*>(ball)->checkIfEnd()){//check if end
        gameend = new GameEnd(point);
        gameend->show();
        connect(gameend,SIGNAL(closeGame()),this,SLOT(closeGame()));
        disconnect(myTimer,SIGNAL(timeout()),this,SLOT(update()));
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(ca1Update()));
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat2Update()));
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat3Update()));
        disconnect(catt4Timer,SIGNAL(timeout()),this,SLOT(cat4Update()));
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat1UpdateWhenScared()));
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat2UpdateWhenScared()));
        disconnect(cattTimer,SIGNAL(timeout()),this,SLOT(cat3UpdateWhenScared()));
        disconnect(catt4Timer,SIGNAL(timeout()),this,SLOT(cat4UpdateWhenScared()));

    }
    //dqDebug()<<static_cast<Ghost*>(ghost1)->getghostfear()<<static_cast<Ghost*>(ghost2)->getghostfear()<<static_cast<Ghost*>(ghost3)->getghostfear()<<static_cast<Ghost*>(ghost4)->getghostfear();
    checkEncounterCat();
    if(eyeTurnNormal1==true&&static_cast<Cat*>(cat1)->getcatfear()==3){
        if(time1->elapsed()>2000 && time1->elapsed()<2100){
            qDebug()<<"connect1 ddd";
            qDebug()<<"1";
            static_cast<Cat*>(cat1)->catNotScared();
            connect(cattTimer,SIGNAL(timeout()),this,SLOT(ca1Update()));
            eyeTurnNormal1 = false;
        }
    }
    if(eyeTurnNormal2==true&&static_cast<Cat*>(cat2)->getcatfear()==3){
        if(time2->elapsed()>2000 && time2->elapsed()<2100){
            qDebug()<<"connect2 ddd";
            qDebug()<<"2";
            static_cast<Cat*>(cat2)->catNotScared();
            connect(cattTimer,SIGNAL(timeout()),this,SLOT(cat2Update()));
            eyeTurnNormal2 = false;
        }
    }
    if(eyeTurnNormal3==true&&static_cast<Cat*>(cat3)->getcatfear()==3){
        if(time3->elapsed()>2000 && time3->elapsed()<2100){
            qDebug()<<"connect3 ddd";
            qDebug()<<"3";
            static_cast<Cat*>(cat3)->catNotScared();
            connect(cattTimer,SIGNAL(timeout()),this,SLOT(cat3Update()));
            eyeTurnNormal3 = false;
        }
    }
    if(eyeTurnNormal4==true&&static_cast<Cat*>(cat4)->getcatfear()==3){
        if(time4->elapsed()>2000 && time4->elapsed()<2100){
            qDebug()<<"connect4 ddd";
            qDebug()<<"4";
            static_cast<Cat*>(cat4)->catNotScared();
            connect(catt4Timer,SIGNAL(timeout()),this,SLOT(cat4Update()));
            eyeTurnNormal4 = false;
        }
    }
    scene->update();

}

void MainWindow::cat1UpdateWhenScared()
{
    cat1->move();
    scene->update();
}
void MainWindow::cat2UpdateWhenScared()
{
    cat2->move();
    scene->update();
}
void MainWindow::cat3UpdateWhenScared()
{
    cat3->move();
    scene->update();
}
void MainWindow::cat4UpdateWhenScared()
{
    cat4->move();
    scene->update();
}

void MainWindow::ca1Update()
{
    static_cast<Cat*>(cat1)->move(mou->moux,mou->mouy);
    scene->update();
}

void MainWindow::cat2Update()
{
    static_cast<Cat*>(cat2)->move(mou->moux,mou->mouy);
    scene->update();
}
void MainWindow::cat3Update()
{
    static_cast<Cat*>(cat3)->move(mou->moux,mou->mouy);
    scene->update();
}
void MainWindow::cat4Update()
{
    static_cast<Cat*>(cat4)->move();
    scene->update();
}

void MainWindow::closeGame()
{
    close();
}
