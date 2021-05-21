#include "graphicsscene.h"

GraphicsScene::GraphicsScene()
{

}
void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "pressed";
    qDebug() << event->pos().x();
}
