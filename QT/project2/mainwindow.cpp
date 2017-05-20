#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    scene->setSceneRect(0,0,895,448);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setGeometry(QRect(0,0,900,450));
    connect(scene,SIGNAL(set_start()),this,SLOT(start_game()));
    build_pro[0] = new QProgressBar(this);
    build_pro[1] = new QProgressBar(this);
    build_pro[2] = new QProgressBar(this);
    build_pro[3] = new QProgressBar(this);
    build_pro[4] = new QProgressBar(this);
    build_pro[5] = new QProgressBar(this);

    btn[0] = new QPushButton(this);
    btn[1] = new QPushButton(this);
    btn[2] = new QPushButton(this);
    btn[3] = new QPushButton(this);

   connect(btn[0], SIGNAL(clicked(bool)),scene,SLOT(add_a1()));
   connect(btn[1], SIGNAL(clicked(bool)),scene,SLOT(add_a2()));
   connect(btn[2], SIGNAL(clicked(bool)),scene,SLOT(add_a3()));
   connect(btn[3], SIGNAL(clicked(bool)),scene,SLOT(add_a4()));

   QTimer *tick = new QTimer();
   connect(tick,SIGNAL(timeout()),this,SLOT(check_pro()));
   tick->start(50);
   settingBg();
   ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settingBg(){
    QImage bg;
    bg.load(":/new/prefix1/bg1.jpg");
    bg=bg.scaled(900,450);
    scene->setBackgroundBrush(bg);
    build_pro[0]->setGeometry(0,0,0,0);
    build_pro[1]->setGeometry(0,0,0,0);
    build_pro[2]->setGeometry(0,0,0,0);
    build_pro[3]->setGeometry(0,0,0,0);
    build_pro[4]->setGeometry(0,0,0,0);
    build_pro[5]->setGeometry(0,0,0,0);

    btn[0]->setGeometry(0,0,0,0);
    btn[1]->setGeometry(0,0,0,0);
    btn[2]->setGeometry(0,0,0,0);
    btn[3]->setGeometry(0,0,0,0);

}

void MainWindow::check_pro()
{
    QObject::connect(scene->build[0],SIGNAL(build_health(double)),this,SLOT(pro_health0(double)));
    QObject::connect(scene->build[1],SIGNAL(build_health(double)),this,SLOT(pro_health1(double)));
    QObject::connect(scene->build[2],SIGNAL(build_health(double)),this,SLOT(pro_health2(double)));
}

void MainWindow::pro_health0(double i)
{
  build_pro[0]->setValue(i);
}
void MainWindow::pro_health1(double i)
{
  build_pro[1]->setValue(i);
}
void MainWindow::pro_health2(double i)
{
  build_pro[2]->setValue(i);
}
void MainWindow::start_game(){
    int i;
    for(i=0;i<6;i++) {
    build_pro[i]->setMinimum(0);
    build_pro[i]->setMaximum(100);
    build_pro[i]->setValue(100);
    build_pro[i]->setOrientation(Qt::Horizontal);
    }
    build_pro[0]->setGeometry(85,180,85,15);
    build_pro[1]->setGeometry(40,310,85,15);
    build_pro[2]->setGeometry(85,430,85,15);
    build_pro[3]->setGeometry(735,180,85,15);
    build_pro[4]->setGeometry(780,310,85,15);
    build_pro[5]->setGeometry(735,430,85,15);

    for(i=0;i<4;i++) {
        btn[i]->setIconSize(QSize(90,70));
        btn[i]->setStyleSheet("background-color:black;");
        btn[i]->setStyleSheet("QPushButton{border: 0px ;border-radius:0px}");
    }
    btn[0]->setGeometry(510,20,90,40);
    btn[0]->setIcon(QIcon(":new/prefix1/btn1.png"));
    btn[1]->setGeometry(600,20,90,40);
    btn[1]->setIcon(QIcon(":new/prefix1/btn2.png"));
    btn[2]->setGeometry(690,20,90,40);
    btn[2]->setIcon(QIcon(":new/prefix1/btn3.png"));
    btn[3]->setGeometry(780,20,90,40);
    btn[3]->setIcon(QIcon(":new/prefix1/btn4.png"));
}
