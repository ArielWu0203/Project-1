#ifndef A_H
#define A_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QTimer>
#include<QGraphicsPolygonItem>
#include<QPointF>
#include <qobject.h>
#include"abullet.h"

class A : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    A(int i);
    int name;
    QGraphicsPolygonItem *area;
    void add_bullet();

public slots:
    void move();
    void get_target();
    void back();

signals:
    void stop();

private:
    double health;
};

#endif // A_H
