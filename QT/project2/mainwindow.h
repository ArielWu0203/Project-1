#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <cstdio>
#include <QMainWindow>
#include<QGraphicsScene>
#include <QProgressBar>
#include<QGraphicsPixmapItem>
#include<QPushButton>
#include<QLabel>
#include"scene.h"
#include"build.h"
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Scene *scene;
    QProgressBar *build_pro[6];
    QPushButton *btn[4];
public slots:
    void start_game();
    void settingBg();
    void check_pro();
    void pro_health0(double i);
    void pro_health1(double i);
    void pro_health2(double i);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
