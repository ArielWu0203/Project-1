#include "scene.h"

Scene::Scene(QObject *parent)
{
  int i;
  for(i=0;i<3;i++) {
      build[i] = new Build(i);
  }
  for(i=0;i<3;i++) {
      abuild[i] = new Abuild();
  }
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *e){
    if(mouse == 1) {
      if(e->scenePos().x() > 600 && e->scenePos().x() <= 850) {
        if(e->scenePos().y() > 50 && e->scenePos().y() <= 130){
          changebg();
          emit set_start();//call Progressbar
          mouse=2;//entry bg2
        }
      }
      if(e->scenePos().x() > 600 && e->scenePos().x() <= 850) {
        if(e->scenePos().y() > 190 && e->scenePos().y() <= 270){

        }
      }
    }
}

void Scene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent  *e){
    while(mouse==3) {
          QPixmap people;
          if(a_name == 0) {
            people.load(":/new/prefix1/a1.png");
          }
          if(a_name == 1) {
            people.load(":/new/prefix1/a2.png");
          }
          if(a_name == 2) {
            people.load(":/new/prefix1/a3.png");
          }
          if(a_name == 3) {
            people.load(":/new/prefix1/a4.png");
          }

          A *a = new A(a_name);
          people=people.scaled(80,80);
          a->setPixmap(people);
          a-> setPos(e->scenePos().x()-30,e->scenePos().y()-30);
          addItem(a);
          a->move();
          mouse=2;
    }
}


void Scene::changebg() {
  QImage bg;
  bg.load(":/new/prefix1/bg2.png");
  bg=bg.scaled(900,450);
  this->setBackgroundBrush(bg);

  int i;
  QPixmap B[6];
  B[0].load(":/new/prefix1/B.png");
  B[1].load(":/new/prefix1/Bbuildmain.png");
  B[2].load(":/new/prefix1/B.png");
  B[3].load(":/new/prefix1/Abuild.png");
  B[4].load(":/new/prefix1/Abuildmain.png");
  B[5].load(":/new/prefix1/Abuild.png");
  B[0]=B[0].scaled(90,90);
  B[1]=B[1].scaled(100,100);
  B[2]=B[2].scaled(90,90);
  B[3]=B[3].scaled(90,90);
  B[4]=B[4].scaled(100,100);
  B[5]=B[5].scaled(90,90);
  for(i=0;i<3;i++) {
    build[i] -> setPixmap(B[i]);
  }
  for(i=0;i<3;i++) {
      abuild[i]->setPixmap(B[i+3]);
  }
  build[0] -> setPos(80,70);
  build[1] -> setPos(30,190);
  build[2] -> setPos(80,320);
  abuild[0] -> setPos(730,70);
  abuild[1] -> setPos(770,190);
  abuild[2] -> setPos(730,320);
  for(i=0;i<3;i++) {
      addItem(build[i]);
  }
  for(i=0;i<3;i++) {
      addItem(abuild[i]);
  }
}

void Scene::add_a1(){
    mouse=3;
    a_name = 0;
}

void Scene::add_a2(){
    mouse=3;
    a_name = 1;
}

void Scene::add_a3(){
    mouse=3;
    a_name = 2;
}

void Scene::add_a4(){
    mouse=3;
    a_name = 3;
}


