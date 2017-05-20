#ifndef ABUILD_H
#define ABUILD_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QTimer>
#include <qobject.h>
#include<QGraphicsPolygonItem>
#include<QPointF>

class Abuild : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Abuild();
};

#endif // ABUILD_H
