#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>


class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
    public:
    explicit GraphicsScene();

    protected:
    // overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // GRAPHICSSCENE_H
