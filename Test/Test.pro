TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

QT += core

# Google Testing Framework
win32 {
    INCLUDEPATH += "D:/Soft/gtest-1.7.0/include/"
    LIBS += "$$PWD/libGoogleTest.a"
}
unix {
    LIBS += /usr/lib/libgtest.a
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
    GameUtil/ConfigReader.cpp \
    Core/Thread.cpp

include(deployment.pri)
qtcAddDeployment()

