#ifndef MOUSE_H
#define MOUSE_H
#include "map.h"


class Mouse : public Map
{
public:
    Mouse();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPos(int x,int y);
    void move();
    void setDirection(int a);


private:
    int mouState=0;
    int direction,nextDirection;//1 right, 2 down, 3 left, 4 up
    QPixmap mou;
    //up1,up2,up3,right0,right1,right2,right3,down0,down1,down2,down3,left0,left1,left2,left3;
};

#endif // MOUSE_H
