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
    DEFINES += NDEBUG
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
    Window/WindowManager.cpp \
    Core/Async/Async.cpp \
    Core/Async/ThreadPool.cpp \
    Core/Async/PlatformSpecific/Qt/QtThreadPoolImpl.cpp \
    Core/Async/Action.cpp \
    Core/Async/PlatformSpecific/Qt/QtActionImpl.cpp \
    Core/Async/PlatformSpecific/Qt/QtActionImplRunnable.cpp \
    Core/States/LoadingState.cpp \
    Graph/Texture.cpp \
    Graph/GraphicsScene.cpp \
    Core/States/SwitchInfo/SwitchStateInfo.cpp \
    Core/States/SwitchInfo/SwitchToLoadingInfo.cpp \
    Graph/Actor.cpp \
    Graph/PlatformSpecific/Qt/QtTextureImpl.cpp \
    Graph/Camera.cpp \
    GameUtil/Settings.cpp \
    Graph/Animation.cpp \
    Core/Utility/Geometry/Rectangle.cpp \
    Core/Utility/Geometry/Point.cpp \
    Core/Utility/Geometry/Size.cpp \
    Graph/GraphicsSceneLayer.cpp \
    Core/PlaftormSpecific/QtTimerImpl.cpp \
    Graph/Color.cpp \
    Graph/AnimationCollection.cpp \
    UI/Components/ProgressBar.cpp \
    UI/Components/UIComponent.cpp \
    UI/UIScene.cpp \
    Core/Utility/Geometry/Geometry.cpp \
    Resources/Resources/ResourcePack.cpp \
    Graph/ResourceLoaders/AnimationLoader.cpp \
    Graph/ResourceLoaders/AnimationCollectionLoader.cpp \
    GameUtil/FilePath.cpp \
    Core/Utility/Geometry/ResourceLoaders/GeometryLoader.cpp

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
    Window/WindowType.h \
    Core/Async/Async.h \
    Core/Async/ThreadPool.h \
    Core/Async/PlatformSpecific/Qt/QtThreadPoolImpl.h \
    Core/Async/Action.h \
    Core/Async/PlatformSpecific/Qt/QtActionImpl.h \
    Core/Async/PlatformSpecific/Qt/QtActionImplRunnable.h \
    Core/Assert.h \
    Core/States/LoadingState.h \
    Graph/Texture.h \
    Graph/GraphicsScene.h \
    Core/States/SwitchInfo/SwitchStateInfo.h \
    Core/States/SwitchInfo/SwitchToLoadingInfo.h \
    Graph/Actor.h \
    Graph/PlatformSpecific/Qt/QtTextureImpl.h \
    Graph/Camera.h \
    GameUtil/Settings.h \
    Graph/Animation.h \
    Core/Utility/Geometry/Rectangle.h \
    Core/Utility/Geometry/Point.h \
    Core/Utility/Geometry/Size.h \
    Graph/GraphicsSceneLayer.h \
    Core/PlaftormSpecific/QtTimerImpl.h \
    Graph/Color.h \
    Graph/AnimationCollection.h \
    UI/Components/ProgressBar.h \
    UI/Components/UIComponent.h \
    UI/UIScene.h \
    Core/Utility/Geometry/Geometry.h \
    Resources/Resources/ResourcePack.h \
    Graph/ResourceLoaders/AnimationLoader.h \
    Graph/ResourceLoaders/AnimationCollectionLoader.h \
    GameUtil/FilePath.h \
    Core/Utility/Geometry/ResourceLoaders/GeometryLoader.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
