#ifndef BALL_H
#define BALL_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include <QVector>
#include "map.h"

class Ball :public Map//cheeses and power pills;
{
public:
    Ball();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void clearPoints(int x,int y);
    bool checkIfEnd();
private:
    QVector<QPoint> points;


};

#endif // BALL_H
