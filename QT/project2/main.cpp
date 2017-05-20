#include "mainwindow.h"
#include <QApplication>
#include<QDesktopWidget>
#include<QProgressBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget wid;
    int screenW=903;
    int screenH=495;
    w.setGeometry(wid.screen()->width()/2-(screenW/2),wid.screen()->height()/2-(screenH/2),screenW,screenH);
    w.setWindowTitle("WAR GAME");
    w.show();
    return a.exec();
}
