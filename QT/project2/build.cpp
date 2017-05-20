#include "build.h"
#include<QVector>
#include<QPolygonF>
#include<QLineF>
#include<QList>
#include<QTimer>
#include<iostream>
#include<cstdio>
#include"abullet.h"
#include"bbullet.h"

Build::Build(int i)
{
  name=i;
  health = 100;
  QTimer *tick = new QTimer();
  QObject::connect(tick,SIGNAL(timeout()),this,SLOT(check_be_attacked()));
  tick->start(5);
  QTimer *tick2 = new QTimer();
  QObject::connect(tick2,SIGNAL(timeout()),this,SLOT(add_bullet_up()));
  QObject::connect(tick2,SIGNAL(timeout()),this,SLOT(add_bullet_down()));
  tick2->start(2000);

}

void Build::add_bullet_up()
{
    Bbullet *bullet = new Bbullet(4);
    QPixmap picture;
    picture.load(":/new/prefix1/Battack.png");
    picture=picture.scaled(50,20);
    bullet->setPixmap(picture);
    bullet->setPos(x()+20,y()+20);
    scene()->addItem(bullet);
}

void Build::add_bullet_down()
{
    Bbullet *bullet = new Bbullet(4);
    QPixmap picture;
    picture.load(":/new/prefix1/Battack.png");
    picture=picture.scaled(50,20);
    bullet->setPixmap(picture);
    bullet->setPos(x()+20,y()+60);
    scene()->addItem(bullet);
}


void Build::check_be_attacked()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Abullet)){
                health-=0.1;
                if(health>0) {
                  emit build_health(health);
                }
                if(health<=0) {
                    scene()->removeItem(this);
                    delete(this);
                    return;
                }
                return;
            }
        }
}
