#ifndef ABULLET_H
#define ABULLET_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QTimer>
#include <qobject.h>

class Abullet : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Abullet(int i);
    Abullet(int i,int j);
    int name;
    int num = 0;
public slots:
    void move();
    void bye();
signals:
    void attack_build();
};

#endif // ABULLET_H
