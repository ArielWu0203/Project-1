#ifndef BUILD_H
#define BUILD_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QTimer>
#include <qobject.h>
#include<QGraphicsPolygonItem>
#include<QPointF>
#include"bbullet.h"

class Build : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Build(int i);
    int name;
    double health;
    QGraphicsPolygonItem *area;

public slots:
    void check_be_attacked();
    void add_bullet_up();
    void add_bullet_down();

signals:
    void build_health(double i);
    void check_health();
};

#endif // BUILD_H
