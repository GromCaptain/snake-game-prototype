#-------------------------------------------------
#
# Project created by QtCreator 2015-10-10T17:03:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Build
TEMPLATE = app

CONFIG += debug_and_release \
    c++11

CONFIG(release, debug|release) {
    LIBS += "../GameLib/release/libGameLib.a"
} else {
    LIBS += "../GameLib/debug/libGameLib.a"
}

INCLUDEPATH += "../GameLib"

SOURCES += main.cpp
