#-------------------------------------------------
#
# Project created by QtCreator 2015-10-10T16:15:29
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = GameLib
TEMPLATE = lib
CONFIG += staticlib \
	c++11 \
	debug_and_release

CONFIG(release, debug|release) {
    DESTDIR = release
} else {
    DESTDIR = debug
}

SOURCES += \
    GameUtil/ConfigReader.cpp \
    Core/PlaftormSpecific/QtStringImpl.cpp \
    Core/PlaftormSpecific/QtThreadImpl.cpp \
    Core/States/GameState.cpp \
    Core/States/IntroState.cpp \
    Core/States/MainState.cpp \
    Core/States/MenuState.cpp \
    Core/States/PreloadState.cpp \
    Core/GameManager.cpp \
    Core/String.cpp \
    Core/Thread.cpp \
    Core/Timer.cpp \
    Graph/GraphicsManager.cpp \
    Resources/Resources/PlatformSpecific/QtResourceImpl.cpp \
    Resources/Resources/Resource.cpp \
    Resources/ResourcesManager.cpp \
    Window/PlaftormSpecific/QtWindowImpl.cpp \
    Window/PlaftormSpecific/QtWindowManagerImpl.cpp \
    Window/Window.cpp \
    Window/WindowManager.cpp

HEADERS += \
    GameUtil/ConfigReader.h \
    Core/PlaftormSpecific/QtStringImpl.h \
    Core/PlaftormSpecific/QtThreadImpl.h \
    Core/States/GameState.h \
    Core/States/IntroState.h \
    Core/States/MainState.h \
    Core/States/MenuState.h \
    Core/States/PreloadState.h \
    Core/GameManager.h \
    Core/String.h \
    Core/Thread.h \
    Core/Timer.h \
    Graph/GraphicsManager.h \
    Resources/Resources/PlatformSpecific/QtResourceImpl.h \
    Resources/Resources/Byte.h \
    Resources/Resources/Resource.h \
    Resources/Resources/ResourceID.h \
    Resources/ResourcesManager.h \
    Window/PlaftormSpecific/QtWindowImpl.h \
    Window/PlaftormSpecific/QtWindowManagerImpl.h \
    Window/Window.h \
    Window/WindowManager.h \
    Window/WindowType.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
