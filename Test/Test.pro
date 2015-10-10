TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "D:/Soft/gtest-1.7.0/include/" \
    "../GameLib"

CONFIG += debug_and_release \
    c++11

CONFIG(release, debug|release) {
    LIBS += "../GameLib/release/libGameLib.a"
} else {
    LIBS += "../GameLib/debug/libGameLib.a"
}

LIBS += "$$PWD/libGoogleTest.a"

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

