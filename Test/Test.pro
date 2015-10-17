TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

QT += core

# Google Testing Framework. My current Win configuration. For unix - copy proper gtest files to /usr/include and /usr/lib
win32 {
    INCLUDEPATH += "D:/Soft/gtest-1.7.0/include/"
    LIBS += "$$PWD/libGoogleTest.a"
}

INCLUDEPATH += "../GameLib"

CONFIG += debug_and_release

CONFIG(release, debug|release) {
    LIBS += "../GameLib/release/libGameLib.a"
} else {
    LIBS += "../GameLib/debug/libGameLib.a"
}

SOURCES += main.cpp \
    Core/String.cpp \
    GameUtil/ConfigReader.cpp

include(deployment.pri)
qtcAddDeployment()

