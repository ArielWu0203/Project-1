#include "abullet.h"
#include<iostream>
#include<cstdio>
#include<qmath.h>
#include<QList>
#include"build.h"

Abullet::Abullet(int i)
{
    name=i;

    QTimer *tick = new QTimer();
    if(name==0) {
    QObject::connect(tick,SIGNAL(timeout()),this,SLOT(move()));
    tick->start(100);
    QTimer::singleShot(1000,tick,SLOT(stop()));
    QTimer::singleShot(1000,this,SLOT(bye()));
    }
    if(name==1) {
    QObject::connect(tick,SIGNAL(timeout()),this,SLOT(move()));
    tick->start(100);
    QTimer::singleShot(800,tick,SLOT(stop()));
    QTimer::singleShot(800,this,SLOT(bye()));
    }
    if(name==3) {
    QObject::connect(tick,SIGNAL(timeout()),this,SLOT(move()));
    tick->start(100);
    QTimer::singleShot(1000,tick,SLOT(stop()));
    QTimer::singleShot(1000,this,SLOT(bye()));
    }
}

Abullet::Abullet(int i, int j)
{
    name=i;
    num =j;
    QTimer *tick = new QTimer();
    if(name==2) {
    QObject::connect(tick,SIGNAL(timeout()),this,SLOT(move()));
    tick->start(100);
    QTimer::singleShot(1000,tick,SLOT(stop()));
    QTimer::singleShot(1000,this,SLOT(bye()));
    }

}

void Abullet::move()
{
    if(name==0) {
      setPos(x()+2,y()-2);
      }
    if(name==1) {
      setPos(x(),y());
    }
    if(name==2 && num==1) {
      setPos(x()-7,y()-3);
    }
    if(name==2 && num==2) {
      setPos(x()-7,y());
    }
    if(name==2 && num==3) {
      setPos(x()-7,y()+3);
    }
    if(name==3) {
      setPos(x()-15,y());
    }
}

void Abullet::bye()
{
  scene()->removeItem(this);
  delete this;
}

