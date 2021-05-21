#include "map.h"


Map::Map()
{
    for (int i=0;i<480;++i) {
        for(int j=0;j<570;j++){
            pathPoints[i][j] = -1;
        }
    }
    //horizontal path
    addPathPoints(40,70,210,70);
    addPathPoints(260,70,430,70);
    addPathPoints(40,130,430,130);
    addPathPoints(40,180,120,180);
    addPathPoints(170,180,210,180);
    addPathPoints(260,180,310,180);
    addPathPoints(360,180,430,180);
    addPathPoints(170,240,310,240);
    addPathPoints(10,290,170,290);
    addPathPoints(310,290,460,290);
    addPathPoints(170,340,310,340);
    addPathPoints(40,390,210,390);
    addPathPoints(260,390,430,390);
    addPathPoints(40,440,70,440);
    addPathPoints(120,440,360,440);
    addPathPoints(400,440,430,440);
    addPathPoints(40,490,120,490);
    addPathPoints(170,490,210,490);
    addPathPoints(260,490,310,290);
    addPathPoints(360,490,430,490);
    addPathPoints(40,550,430,550);
    //vertical path
    addPathPoints(40,70,40,180);
    addPathPoints(40,390,40,440);
    addPathPoints(40,490,40,550);
    addPathPoints(70,440,70,490);
    addPathPoints(120,70,120,490);
    addPathPoints(170,130,170,180);
    addPathPoints(170,240,170,390);
    addPathPoints(170,440,170,490);
    addPathPoints(210,70,210,130);
    addPathPoints(210,180,210,240);
    addPathPoints(210,390,210,440);
    addPathPoints(210,490,210,550);
    addPathPoints(260,70,260,130);
    addPathPoints(260,180,260,240);
    addPathPoints(260,390,260,440);
    addPathPoints(260,490,260,550);
    addPathPoints(310,130,310,180);
    addPathPoints(310,240,310,390);
    addPathPoints(310,440,310,490);
    addPathPoints(360,70,360,490);
    addPathPoints(400,440,400,490);
    addPathPoints(430,70,430,180);
    addPathPoints(430,390,430,440);
    addPathPoints(430,490,430,550);
    for (int i=10;i<21;++i) {
        pathPoints[i][290] = 0;
    }
    for (int i=461;i<471;++i) {
        pathPoints[i][290] = 0;
    }
}

QRectF Map::boundingRect() const
{

    return QRectF();
}


void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void Map::addPathPoints(int x1, int y1, int x2, int y2)
{//set path and balls and power pill
    if(x1 == x2){
        if(y1 < y2){
            for(int y=y1;y<y2+1;++y){
                    pathPoints[x1][y] = 0;
            }
            for(int y=y1;y<y2+1;y+=10){pathPoints[x1][y] = 1;}
        }
        else {
            for (int y=y1;y>y2-1;--y) {
                    pathPoints[x1][y] = 0;
            }
            for (int y=y1;y>y2-1;y-=10) {pathPoints[x1][y] = 1;}
        }
    }
    else{
        if(x1 < x2){
            for(int x=x1;x<x2+1;++x){
                    pathPoints[x][y1] = 0;
            }
            for(int x=x1;x<x2+1;x+=10){pathPoints[x][y1] = 1;}
        }
        else {
            for (int x=x1;x>x2-1;--x) {
                    pathPoints[x][y1] = 0;
            }
            for (int x=x1;x>x2-1;x-=10) {pathPoints[x][y1] = 1;}
        }
    }
    pathPoints[40][440] = 3;
    pathPoints[430][440] = 3;
    pathPoints[40][130] = 3;
    pathPoints[430][130] = 3;
}



void Map::move()
{

}

void Map::setDirection(int a)
{

}



