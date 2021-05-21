#include "mouse.h"

Mouse::Mouse()
{
    setPos(190,340);
    direction = 1;
    setDirection(1);
    mou.load(":/new/prefix1/images/mouse.png");

}

QRectF Mouse::boundingRect() const
{
    return QRectF(posx-15,posy-15,30,30);
}

void Mouse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->translate(-12,-29);


    if(direction == 1 || direction==2|| direction==3||direction==4){
        painter->drawPixmap(moux-15,mouy-15,30,30,mou);

    }

}

void Mouse::setPos(int x,int y)
{
    moux = x;
    mouy = y;
}


void Mouse::setDirection(int a)
{
    nextDirection = a;
}

void Mouse::move()//check if the next position moveable
{
    if(nextDirection != direction){
        if(nextDirection==1){//right
            for (int i=0;i<9;++i){
                if(pathPoints[moux+5][mouy-i]!=-1){
                    direction=1;
                    setPos(moux,mouy-i);
                    ++mouState;
                    break;
                }
                if(pathPoints[moux+5][mouy+i]!=-1){
                    direction=1;
                    setPos(moux,mouy+i);
                    ++mouState;
                    break;
                }
            }
            nextDirection = direction;
        }
        if(nextDirection==2){//down
            for (int i=0;i<9;++i) {
                if(pathPoints[moux-i][mouy+5]!=-1){
                    direction=2;
                    setPos(moux-i,mouy);
                    ++mouState;
                    break;
                }
                if(pathPoints[moux+i][mouy+5]!=-1){
                    direction=2;
                    setPos(moux+i,mouy);
                    ++mouState;
                    break;
                }
            }
            nextDirection = direction;
        }
        if(nextDirection==3){//left
            for (int i=0;i<9;++i) {
                if(pathPoints[moux-5][mouy-i]!=-1){
                    direction=3;
                    setPos(moux,mouy-i);
                    ++mouState;
                    break;
                }
                if(pathPoints[moux-5][mouy+i]!=-1){
                    direction=3;
                    setPos(moux,mouy+i);
                    ++mouState;
                    break;
                }
            }
            nextDirection = direction;
        }
        if(nextDirection==4){//up
            for (int i=0;i<9;++i) {
                if(pathPoints[moux-i][mouy-5]!=-1){
                    direction=4;
                    setPos(moux-i,mouy);
                    ++mouState;
                    break;
                }
                if(pathPoints[moux+i][mouy-5]!=-1){
                    direction=4;
                    setPos(moux+i,mouy);
                    ++mouState;
                    break;
                }
            }
            nextDirection = direction;
        }
    }
    else {

        if(direction==1){//right
            if(moux == 470 && mouy ==290)
                moux = 10;
            if(pathPoints[moux+1][mouy]!=-1){
                setPos(moux+5,mouy);
                ++mouState;
            }
        }
        if(direction==2){//down
            if(pathPoints[moux][mouy+1]!=-1){
                setPos(moux,mouy+5);
                ++mouState;
            }
        }
        if(direction==3){//left
            if(moux==10 && mouy == 290)
                moux = 470;
            if(pathPoints[moux-1][mouy]!=-1){
             setPos(moux-5,mouy);
                ++mouState;
            }
        }
        if(direction==4){//up
            if(pathPoints[moux][mouy-1]!=-1){
                setPos(moux,mouy-5);
                ++mouState;
            }
        }
    }
}
