#include "ball.h"

Ball::Ball()
{
}

QRectF Ball::boundingRect() const
{
    return QRect(0, 0, 450, 550);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::yellow);
    painter->setBrush(Qt::yellow);
    painter->translate(-12,-29);

    for (int i=0;i<480;i+=10) {
        for(int j=0;j<570;j+=10){
            if(pathPoints[i][j]==1)
                painter->drawRect(i-1,j-1,1,1);
        }
    }
    if(pathPoints[40][440] == 3)
        painter->drawEllipse(35,435,10,10);
    if(pathPoints[430][440] == 3)
        painter->drawEllipse(425,435,10,10);
    if(pathPoints[430][130] == 3)
        painter->drawEllipse(425,125,10,10);
    if(pathPoints[40][130] == 3)
        painter->drawEllipse(35,125,10,10);
}

void Ball::clearPoints(int x, int y)
{
    pathPoints[x][y] = 0;
}

bool Ball::checkIfEnd()
{
    for (int i=0;i<480;i+=10) {
        for(int j=0;j<570;j+=10){
            if(pathPoints[i][j]==1 || pathPoints[i][j]==3)
                return false;
        }
    }
    return true;
}

