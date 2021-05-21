#ifndef CAT_H
#define CAT_H
#include "map.h"
#include <QTime>
#include <QTimer>
#include <qrandom.h>
#include <QElapsedTimer>

class Cat : public Map
{
public:
    Cat(int num, int posx, int posy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setCatPos(int x, int y);
    void setCatColor(int num);
    void setDireciton(int dir);
    void cat1MovePath();
    void cat2MovePath();
    void cat3MovePath();
    void cat4MovePath();
    bool canmove(int a, int posx, int posy);
    void move();
    void move(int moux,int mouy);
    void mouChangeDir();
    void cattTurnBlue();
    void catNotScared();
    void catTurnWhite();
    void catTurnEyeball();
    int getcatfear();
    void catPriorityDirX(int moux,int mouy);
    void catPriorityDirY(int moux,int mouy);
    void catPriorityDirXY(int moux,int mouy);
    int catColor;
    void findShortestDir(int moux,int mouy,int step);
    void allcatPath(int moux,int mouy);

    QTime *mytime;

private:
    int checkPosX,checkPosY,dirx=0,diry=0;
    int catNum;
    int useless=0;
    int shortestDirCheck[2]={0,0},lastShortDirCheck[2]={0,0},step=0;
    bool buttonPressed;
    int direction,nextDirection,catState=0;
    int catfear=0;//0 normal, 1 blue, 2 white, 3 eyeball
    QPixmap cat1,cat2,cat3,cat4,scaredw1,scaredw2,scaredb1,scaredb2,eyeball;

};

#endif // CAT_H
