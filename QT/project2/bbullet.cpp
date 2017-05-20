#include "bbullet.h"

Bbullet::Bbullet(int i)
{
    name=i;
    QTimer *tick = new QTimer();
    QObject::connect(tick,SIGNAL(timeout()),this,SLOT(move()));
    tick->start(100);
    QTimer::singleShot(1000,tick,SLOT(stop()));
    QTimer::singleShot(1000,this,SLOT(bye()));
}

void Bbullet::move()
{
    if(name == 4) {
      setPos(x()+13,y());
    }
}

void Bbullet::bye()
{
  scene()->removeItem(this);
  delete this;
}
