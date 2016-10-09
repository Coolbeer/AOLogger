#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T23:13:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AO-Logparser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    t_entity.cpp \
    t_damage.cpp

HEADERS  += mainwindow.h \
    t_entity.h \
    t_damage.h

FORMS    += mainwindow.ui
