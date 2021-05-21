#include "cat.h"

Cat::Cat(int num, int posx, int posy)
{
    mytime = new QTime;
    setCatPos(posx,posy);
    catColor = num;
    setCatColor(catColor);
    setDireciton(1);
}

QRectF Cat::boundingRect() const
{
    return QRectF(posx-15,posy-15,30,30);
}

void Cat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->translate(-12,-29);
    if(catfear==0){
        if(direction == 1){
            if(catState%4 == 0 ||catState%4 == 1){
                painter->drawPixmap(posx-15,posy-15,30,30,cat1);
                painter->drawPixmap(posx-15,posy-15,30,30,cat2);
                painter->drawPixmap(posx-15,posy-15,30,30,cat3);
                painter->drawPixmap(posx-15,posy-15,30,30,cat4);

            }
            else{
                painter->drawPixmap(posx-15,posy-15,30,30,cat1);
                painter->drawPixmap(posx-15,posy-15,30,30,cat2);
                painter->drawPixmap(posx-15,posy-15,30,30,cat3);
                painter->drawPixmap(posx-15,posy-15,30,30,cat4);

            }
        }
        if(direction == 2){
            if(catState%4 == 0 ||catState%4 == 1)
               { painter->drawPixmap(posx-15,posy-15,30,30,cat1);
                painter->drawPixmap(posx-15,posy-15,30,30,cat2);
                painter->drawPixmap(posx-15,posy-15,30,30,cat3);
                painter->drawPixmap(posx-15,posy-15,30,30,cat4);}

            else{
                painter->drawPixmap(posx-15,posy-15,30,30,cat1);
                painter->drawPixmap(posx-15,posy-15,30,30,cat2);
                painter->drawPixmap(posx-15,posy-15,30,30,cat3);
                painter->drawPixmap(posx-15,posy-15,30,30,cat4);}

        }
        if(direction == 3){
            if(catState%4 == 0 ||catState%4 == 1)
            {painter->drawPixmap(posx-15,posy-15,30,30,cat1);
                painter->drawPixmap(posx-15,posy-15,30,30,cat2);
                painter->drawPixmap(posx-15,posy-15,30,30,cat3);
                painter->drawPixmap(posx-15,posy-15,30,30,cat4);}

            else{
                    painter->drawPixmap(posx-15,posy-15,30,30,cat1);
                    painter->drawPixmap(posx-15,posy-15,30,30,cat2);
                    painter->drawPixmap(posx-15,posy-15,30,30,cat3);
                    painter->drawPixmap(posx-15,posy-15,30,30,cat4);

                }

        }
        if(direction == 4){
            if(catState%4 == 0 ||catState%4 == 1)
               { painter->drawPixmap(posx-15,posy-15,30,30,cat1);
                painter->drawPixmap(posx-15,posy-15,30,30,cat2);
                painter->drawPixmap(posx-15,posy-15,30,30,cat3);
                painter->drawPixmap(posx-15,posy-15,30,30,cat4);}

            else{
                painter->drawPixmap(posx-15,posy-15,30,30,cat1);
                painter->drawPixmap(posx-15,posy-15,30,30,cat2);
                painter->drawPixmap(posx-15,posy-15,30,30,cat3);
                painter->drawPixmap(posx-15,posy-15,30,30,cat4);
                }
        }
    }
    if(catfear==1){
        if(catState%4 == 0 ||catState%4 == 1)
            painter->drawPixmap(posx-15,posy-15,30,30,scaredb1);
         else
            painter->drawPixmap(posx-15,posy-15,30,30,scaredb2);
    }
    if(catfear==2){
         if(catState%4 == 0 ||catState%4 == 1)
           painter->drawPixmap(posx-15,posy-15,30,30,scaredw1);
        else
            painter->drawPixmap(posx-15,posy-15,30,30,scaredw2);
    }
    if(catfear==3){
        painter->drawPixmap(posx-15,posy-15,30,30,eyeball);
    }


}

void Cat::setCatPos(int x,int y)
{
    this->posx = x;
    this->posy = y;
}

void Cat::setCatColor(int num)
{
    scaredb1.load(":/new/prefix1/images/cat_frightned.png");
    scaredb2.load(":/new/prefix1/images/cat_frightned.png");
   scaredw1.load(":/new/prefix1/images/cat_frightned.png");
   scaredw2.load(":/new/prefix1/images/cat_frightned.png");
    eyeball.load(":/new/prefix1/images/eyeball.png");
    switch (num) {
    case 1:
        cat1.load(":/new/prefix1/images/cat_orange1.png");

        break;
    case 2:
        cat2.load(":/new/prefix1/images/cat_yellow.png");

        break;
    case 3:
        cat3.load(":/new/prefix1/images/cat_pink.png");

        break;
    case 4:
        cat4.load(":/new/prefix1/images/cat_gray.png");

        break;
    default:
        break;

    }
}

void Cat::setDireciton(int dir)
{
    direction = dir;
}

void Cat::cat1MovePath()
{
    qsrand(QTime::currentTime().msec()+3);
    while(!canmove(direction,posx,posy)){
        direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setCatPos(posx+5,posy);
        break;
    case 2:
        setCatPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setCatPos(posx-5,posy);
        break;
    case 4:
        setCatPos(posx,posy-5);
        break;
    default:
        break;
    }

}

void Cat::cat2MovePath()
{
    int count=0;
    qsrand(QTime::currentTime().msec()+6);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;
    if(count>2)
        direction = qrand()%4+1;
    while(!canmove(direction,posx,posy)){
        direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setCatPos(posx+5,posy);
        break;
    case 2:
        setCatPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setCatPos(posx-5,posy);
        break;
    case 4:
        setCatPos(posx,posy-5);
        break;
    default:
        break;
    }
}

void Cat::cat3MovePath()
{
    if(buttonPressed == true){
        direction = qrand()%4+1;
        while(!canmove(direction,posx,posy)){
            direction = qrand()%4+1;
        }
    }
    int count=0;
    qsrand(QTime::currentTime().msec()+1);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;
    if(count>2)
        direction = qrand()%4+1;
    while(!canmove(direction,posx,posy)){
        direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setCatPos(posx+5,posy);
        break;
    case 2:
        setCatPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setCatPos(posx-5,posy);
        break;
    case 4:
        setCatPos(posx,posy-5);
        break;
    default:
        break;
    }
    buttonPressed = false;
}

void Cat::cat4MovePath()
{
    int count=0;
    qsrand(QTime::currentTime().msec()+6);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;
    if(count>2){
        direction = qrand()%4+1;
    }
    while(!canmove(direction,posx,posy)){
        direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setCatPos(posx+5,posy);
        break;
    case 2:
        setCatPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setCatPos(posx-5,posy);
        break;
    case 4:
        setCatPos(posx,posy-5);
        break;
    default:
        break;
    }
}

bool Cat::canmove(int a,int posx,int posy)
{
    switch (a) {
    case 1:
        if(posx==470 && posy == 290)
            return true;
        if(pathPoints[posx+1][posy]!=-1)
            return true;
        else
            return false;
    case 2:
        if(pathPoints[posx][posy+1]!=-1)
            return true;
        else
            return false;
    case 3:
        if(posx==10 && posy == 290)
            return true;
        if(pathPoints[posx-1][posy]!=-1)
            return true;
        else
            return false;
    case 4:
        if(pathPoints[posx][posy-1]!=-1)
            return true;
        else
            return false;
    default:
        break;
    }
}

void Cat::move()//when cats are scared
{
    if(catColor==1){
        cat1MovePath();
        catState++;
    }
    if(catColor==2){
        cat2MovePath();
        catState++;
    }
    if(catColor==3){
        cat3MovePath();
        catState++;
    }
    if(catColor==4){
        cat4MovePath();
        catState++;
    }
}

void Cat::move(int pacx, int pacy)//when cats are not scared
{
    if(catColor==1){
        catPriorityDirY(pacx,pacy);
        catState++;
    }
    if(catColor==2){
        catPriorityDirX(pacx,pacy);
        catState++;
    }
    if(catColor==3){
        catPriorityDirXY(pacx,pacy);
        catState++;
    }
    if(catColor==4){
        cat4MovePath();
        catState++;
    }
}

void Cat::mouChangeDir()
{
    buttonPressed = true;
}

void Cat::cattTurnBlue()
{
    catfear = 1;
}

void Cat::catNotScared()
{
    catfear = 0;
}

void Cat::catTurnWhite()
{
    catfear = 2;
}

void Cat::catTurnEyeball()
{
    catfear = 3;
}

void Cat::catPriorityDirX(int moux, int mouy)
{
    int count=0;
    qsrand(QTime::currentTime().msec()+6);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;
    if(count>2){
        int dirx=0,diry=0;
        if(moux-posx>0)
            dirx = 1;
        if(moux-posx<0)
            dirx = 3;
        if(mouy-posy>0)
            diry = 2;
        if(mouy-posy<0)
            diry = 4;
        if(canmove(1,posx,posy)&&dirx==1)
            direction = 1;
        else if(canmove(3,posx,posy)&&dirx==3)
            direction = 3;
        else if(canmove(2,posx,posy)&&diry==2)
            direction = 2;
        else if(canmove(4,posx,posy)&&diry==4)
            direction = 4;
    }
    while(!canmove(direction,posx,posy)){
        int dirx=0,diry=0;
        if(moux-posx>0)
            dirx = 1;
        if(moux-posx<0)
            dirx = 3;
        if(mouy-posy>0)
            diry = 2;
        if(mouy-posy<0)
            diry = 4;
        if(canmove(1,posx,posy)&&dirx==1)
            direction = 1;
        else if(canmove(3,posx,posy)&&dirx==3)
            direction = 3;
        else if(canmove(2,posx,posy)&&diry==2)
            direction = 2;
        else if(canmove(4,posx,posy)&&diry==4)
            direction = 4;
        if(!canmove(direction,posx,posy))
            direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setCatPos(posx+5,posy);
        break;
    case 2:
        setCatPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setCatPos(posx-5,posy);
        break;
    case 4:
        setCatPos(posx,posy-5);
        break;
    default:
        break;
    }
}

void Cat::catPriorityDirY(int moux, int mouy)
{
    int count=0;
    qsrand(QTime::currentTime().msec()+4);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;
    if(count>2){
        int dirx=0,diry=0;
        if(moux-posx>0)
            dirx = 1;
        if(moux-posx<0)
            dirx = 3;
        if(mouy-posy>0)
            diry = 2;
        if(mouy-posy<0)
            diry = 4;
        if(canmove(2,posx,posy)&&diry==2)
            direction = 2;
        else if(canmove(4,posx,posy)&&diry==4)
            direction = 4;
        else if(canmove(1,posx,posy)&&dirx==1)
            direction = 1;
        else if(canmove(3,posx,posy)&&dirx==3)
            direction = 3;
    }
    while(!canmove(direction,posx,posy)){
        int dirx=0,diry=0;
        if(moux-posx>0)
            dirx = 1;
        if(moux-posx<0)
            dirx = 3;
        if(mouy-posy>0)
            diry = 2;
        if(mouy-posy<0)
            diry = 4;
        if(canmove(2,posx,posy)&&diry==2)
            direction = 2;
        else if(canmove(4,posx,posy)&&diry==4)
            direction = 4;
        else if(canmove(1,posx,posy)&&dirx==1)
            direction = 1;
        else if(canmove(3,posx,posy)&&dirx==3)
            direction = 3;

        if(!canmove(direction,posx,posy))
            direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setCatPos(posx+5,posy);
        break;
    case 2:
        setCatPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setCatPos(posx-5,posy);
        break;
    case 4:
        setCatPos(posx,posy-5);
        break;
    default:
        break;
    }
}

void Cat::catPriorityDirXY(int moux, int pacy)
{
    ++useless;
    int count=0;
    qsrand(QTime::currentTime().msec()+8);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;
    if(useless%2==0){
        if(count>2){
            int dirx=0,diry=0;
            if(moux-posx>0)
                dirx = 1;
            if(moux-posx<0)
                dirx = 3;
            if(pacy-posy>0)
                diry = 2;
            if(pacy-posy<0)
                diry = 4;
            if(canmove(1,posx,posy)&&dirx==1)
                direction = 1;
            else if(canmove(3,posx,posy)&&dirx==3)
                direction = 3;
            else if(canmove(2,posx,posy)&&diry==2)
                direction = 2;
            else if(canmove(4,posx,posy)&&diry==4)
                direction = 4;
        }
        while(!canmove(direction,posx,posy)){
            int dirx=0,diry=0;
            if(moux-posx>0)
                dirx = 1;
            if(moux-posx<0)
                dirx = 3;
            if(pacy-posy>0)
                diry = 2;
            if(pacy-posy<0)
                diry = 4;
            if(canmove(1,posx,posy)&&dirx==1)
                direction = 1;
            else if(canmove(3,posx,posy)&&dirx==3)
                direction = 3;
            else if(canmove(2,posx,posy)&&diry==2)
                direction = 2;
            else if(canmove(4,posx,posy)&&diry==4)
                direction = 4;
            if(!canmove(direction,posx,posy))
                direction = qrand()%4+1;
        }
    }
    else {
        if(count>2){
            int dirx=0,diry=0;
            if(moux-posx>0)
                dirx = 1;
            if(moux-posx<0)
                dirx = 3;
            if(pacy-posy>0)
                diry = 2;
            if(pacy-posy<0)
                diry = 4;
            if(canmove(2,posx,posy)&&diry==2)
                direction = 2;
            else if(canmove(4,posx,posy)&&diry==4)
                direction = 4;
            else if(canmove(1,posx,posy)&&dirx==1)
                direction = 1;
            else if(canmove(3,posx,posy)&&dirx==3)
                direction = 3;
        }
        while(!canmove(direction,posx,posy)){
            int dirx=0,diry=0;
            if(moux-posx>0)
                dirx = 1;
            if(moux-posx<0)
                dirx = 3;
            if(pacy-posy>0)
                diry = 2;
            if(pacy-posy<0)
                diry = 4;
            if(canmove(2,posx,posy)&&diry==2)
                direction = 2;
            else if(canmove(4,posx,posy)&&diry==4)
                direction = 4;
            else if(canmove(1,posx,posy)&&dirx==1)
                direction = 1;
            else if(canmove(3,posx,posy)&&dirx==3)
                direction = 3;

            if(!canmove(direction,posx,posy))
                direction = qrand()%4+1;
        }
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setCatPos(posx+5,posy);
        break;
    case 2:
        setCatPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setCatPos(posx-5,posy);
        break;
    case 4:
        setCatPos(posx,posy-5);
        break;
    default:
        break;
    }
}

int Cat::getcatfear()
{
    return catfear;
}

