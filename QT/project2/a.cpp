#include "a.h"
#include<iostream>
#include<cstdio>
#include<QVector>
#include<QPolygonF>
#include<QLineF>
#include"build.h"
#include"bbullet.h"
#include<iostream>
#include<cstdio>

A::A(int i)
{
    name = i;
    QTimer *tick = new QTimer();
    QTimer *tick2 = new QTimer();
    if(name==0) {
      health = 30;
      QObject::connect(tick,SIGNAL(timeout()),this,SLOT(move()));
      tick->start(100);
      QObject::connect(tick2,SIGNAL(timeout()),this,SLOT(get_target()));
      tick2->start(1000);
      QObject::connect(this,SIGNAL(stop()),this,SLOT(back()));
    }
    if(name==1) {
      health = 20;
      QObject::connect(tick,SIGNAL(timeout()),this,SLOT(move()));
      tick->start(100);
      QObject::connect(tick2,SIGNAL(timeout()),this,SLOT(get_target()));
      tick2->start(2000);
      QObject::connect(this,SIGNAL(stop()),this,SLOT(back()));
    }
    if(name==2) {
      health = 10;
      QObject::connect(tick,SIGNAL(timeout()),this,SLOT(move()));
      tick->start(100);
      QObject::connect(tick2,SIGNAL(timeout()),this,SLOT(get_target()));
      tick2->start(1500);
      QObject::connect(this,SIGNAL(stop()),this,SLOT(back()));
    }
    if(name==3) {
      health = 15;
      QObject::connect(tick,SIGNAL(timeout()),this,SLOT(move()));
      tick->start(100);
      QObject::connect(tick2,SIGNAL(timeout()),this,SLOT(get_target()));
      tick2->start(1500);
      QObject::connect(this,SIGNAL(stop()),this,SLOT(back()));
    }


    QVector<QPointF> points;
    int scale;
    if(name==0) {
      points<<QPoint(0,0)<<QPoint(3,0)<<QPoint(3,1)<<QPoint(0,1);
      scale=0;
    }
    if(name==1) {
      points<<QPoint(0,0)<<QPoint(3,0)<<QPoint(3,1)<<QPoint(0,1);
      scale=70;
    }
    if(name==2) {
      points<<QPoint(0,0)<<QPoint(3,0)<<QPoint(3,1)<<QPoint(0,1);
      scale=70;
    }
    if(name==3) {
      points<<QPoint(0,0)<<QPoint(3,0)<<QPoint(3,1)<<QPoint(0,1);
      scale=70;
    }
    for(size_t i=0, n=points.size();i<n;i++) {
        points[i] *= scale;
    }
    area = new QGraphicsPolygonItem(QPolygonF(points), this);
    QPointF poly_center(1.5,0.5);
    poly_center *= scale;
    poly_center = mapToScene(poly_center);
    int X,Y;

    if(name==0) {
      X=98;Y=43;
    }
    if(name==1) {
      X=40;Y=43;
    }
    if(name==2) {
      X=60;Y=43;
    }
    if(name==3) {
      X=10;Y=43;
    }
    QPointF a_center(x()+X,y()+Y);
    QLineF ln(poly_center,a_center);
    area->setPos(x()+ln.dx(),y()+ln.dy());

}


void A::move(){
    if(name==0) {
      setPos(x()-3,y());
    }
    if(name==1) {
      setPos(x()-2,y());
    }
    if(name==2) {
      setPos(x()-2,y());
    }
    if(name==3) {
      setPos(x()-2,y());
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Bbullet)){
                health-=1;
                if(health<=0) {
                    scene()->removeItem(this);
                    delete(this);
                }
                return;
            }
        }
}

void A::back()
{
    if(name==0) {
        setPos(x()+60,y());
    }
    if(name==1) {
        setPos(x()+30,y());
    }
    if(name==2) {
        setPos(x()+28,y());
    }
    if(name==3) {
        setPos(x()+30,y());
    }
}
void A::get_target()
{
    if(name==0) {
      QList<QGraphicsItem *> colliding_items = collidingItems();
      for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Build)){
          emit stop();
          add_bullet();
          return;
        }
      }
    }
    else {
      QList<QGraphicsItem *> colliding_items = area->collidingItems();
      for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Build)){
          emit stop();
          add_bullet();
          return;
        }
      }
    }
}



void A::add_bullet()
{
  Abullet *bullet[3];
  QPixmap b;
  if(name==0) {
      b.load(":/new/prefix1/a11.png");
      b=b.scaled(50,50);
      bullet[0] = new Abullet(0);
  }
  if(name==1) {
      b.load(":/new/prefix1/a22.png");
      b=b.scaled(40,150);
      bullet[0] = new Abullet(1);
  }
  if(name==2) {
      b.load(":/new/prefix1/a33.png");
      b=b.scaled(30,30);
      bullet[0] = new Abullet(2,1);
      bullet[1] = new Abullet(2,2);
      bullet[2] = new Abullet(2,3);
      bullet[1]->setPixmap(b);
      bullet[2]->setPixmap(b);
  }
  if(name==3) {
      b.load(":/new/prefix1/a44.png");
      b=b.scaled(10,10);
      bullet[0] = new Abullet(3);
  }
  bullet[0]->setPixmap(b);

  if(name==0) {
    bullet[0]->setPos(x()-70,y()+22);
  }
  if(name==1) {
      bullet[0]->setPos(x()-100,y()-50);
  }
  if(name==2) {
      bullet[0]->setPos(x()-25,y()+5);
      bullet[1]->setPos(x()-25,y()+25);
      bullet[2]->setPos(x()-25,y()+45);
      scene()->addItem(bullet[1]);
      scene()->addItem(bullet[2]);
  }
  if(name==3) {
      bullet[0]->setPos(x()-15,y()+30);
  }
  scene()->addItem(bullet[0]);
}

