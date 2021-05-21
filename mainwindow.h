#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimer>
#include "ball.h"
#include "graphicsscene.h"
#include "mouse.h"
#include "map.h"
#include "gameend.h"
#include "gameover.h"
#include "cat.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void func();
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    int encounterCat();
    bool eatPowerPill();
    void catTurnWhite();
    void catTurnBlue();
    void checkEncounterCat();



    GraphicsScene *myscene;
    QTimer *myTimer,*cattTimer,*catt4Timer;
    GameEnd *gameend;
    gameover *g;

private slots:
    void update();
    void cat1UpdateWhenScared();
    void cat2UpdateWhenScared();
    void cat3UpdateWhenScared();
    void cat4UpdateWhenScared();
    void ca1Update();
    void cat2Update();
    void cat3Update();
    void cat4Update();
    void closeGame();
private:
    Map *ball;
    Map *mou;
    Map *myMap;
    Map *cat1,*cat2,*cat3,*cat4;
    QTime *t,*time1,*time2,*time3,*time4;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPainter *painter;
    int point=0;
    bool eyeTurnNormal1=false,eyeTurnNormal2=false,eyeTurnNormal3=false,eyeTurnNormal4=false;


};

#endif // MAINWINDOW_H
