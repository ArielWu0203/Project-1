#ifndef BBULLET_H
#define BBULLET_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QTimer>
#include <qobject.h>

class Bbullet : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int name;
    Bbullet(int i);
public slots:
    void move();
    void bye();
};

#endif // BBULLET_H
