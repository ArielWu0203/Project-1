#ifndef SCENE_H
#define SCENE_H


#include<QGraphicsScene>
#include<QGraphicsSceneMouseEvent>
#include<QGraphicsPixmapItem>
#include<iostream>
#include<cstdio>
#include<QTimer>
#include<qobject.h>
#include<QProgressBar>
#include"a.h"
#include"build.h"
#include"abuild.h"
using namespace std;
class Scene :public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QObject *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent  *e);
    Build *build[3];
    Abuild *abuild[3];
    int mouse = 1;//change background
    int a_name = 4;//0~3
    int most[4]= {0,0,0,0};

public slots:
    void changebg();
    void add_a1();//double click & add a1
    void add_a2();
    void add_a3();
    void add_a4();

signals:
    void set_start();
private:

};

#endif // SCENE_H
