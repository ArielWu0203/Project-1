#-------------------------------------------------
#
# Project created by QtCreator 2017-05-13T20:17:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    build.cpp \
    a.cpp \
    abullet.cpp \
    abuild.cpp \
    bbullet.cpp

HEADERS  += mainwindow.h \
    scene.h \
    build.h \
    a.h \
    abullet.h \
    abuild.h \
    bbullet.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
