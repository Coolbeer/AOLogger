
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
    t_damage.cpp \
    t_parser.cpp \
    t_entities.cpp \
    t_event.cpp \
    t_error.cpp \
    t_damagecontainer.cpp \
    t_toon.cpp

HEADERS  += mainwindow.h \
    t_entity.h \
    t_damage.h \
    t_parser.h \
    t_entities.h \
    t_event.h \
    t_error.h \
    t_damagecontainer.h \
    t_toon.h

FORMS    += mainwindow.ui
