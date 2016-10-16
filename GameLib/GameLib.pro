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

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += \
    Graph/GraphicsManager.cpp \
    Resources/Resources/Resource.cpp \
    Resources/ResourcesManager.cpp \
    Window/Window.cpp \
    Window/WindowManager.cpp \
    Graph/Texture.cpp \
    Graph/GraphicsScene.cpp \
    Graph/Actor.cpp \
    Graph/PlatformSpecific/Qt/QtTextureImpl.cpp \
    Graph/Camera.cpp \
    Graph/Animation.cpp \
    Graph/GraphicsSceneLayer.cpp \
    Graph/Color.cpp \
    Graph/AnimationCollection.cpp \
    UI/Components/ProgressBar.cpp \
    UI/Components/UIComponent.cpp \
    UI/UIScene.cpp \
    Resources/Resources/ResourcePack.cpp \
    Graph/ResourceLoaders/AnimationLoader.cpp \
    Graph/ResourceLoaders/AnimationCollectionLoader.cpp \
    Core/Data/Geometry/ResourceLoaders/GeometryLoader.cpp \
    Core/Data/Geometry/Geometry.cpp \
    Core/Data/Geometry/Point.cpp \
    Core/Data/Geometry/Rectangle.cpp \
    Core/Data/Geometry/Size.cpp \
    Core/Data/PlatformSpecific/Qt/QtStringImpl.cpp \
    Core/Data/String.cpp \
    Core/Task/Async/PlatformSpecific/Qt/QtActionImpl.cpp \
    Core/Task/Async/PlatformSpecific/Qt/QtActionImplRunnable.cpp \
    Core/Task/Async/PlatformSpecific/Qt/QtThreadPoolImpl.cpp \
    Core/Task/Async/Action.cpp \
    Core/Task/Async/Async.cpp \
    Core/Task/Async/ThreadPool.cpp \
    Core/Task/PlatformSpecific/Qt/QtTimerImpl.cpp \
    Core/Task/Timer.cpp \
    Core/Util/ConfigReader.cpp \
    GameEngine/States/States/SwitchInfo/SwitchStateInfo.cpp \
    GameEngine/States/States/SwitchInfo/SwitchToLoadingInfo.cpp \
    GameEngine/States/States/GameState.cpp \
    GameEngine/States/States/IntroState.cpp \
    GameEngine/States/States/LoadingState.cpp \
    GameEngine/States/States/MainState.cpp \
    GameEngine/States/States/MenuState.cpp \
    GameEngine/States/States/PreloadState.cpp \
    GameEngine/States/GameManager.cpp \
    GameEngine/Settings.cpp \
    Resources/Resources/PlatformSpecific/Qt/QtResourceImpl.cpp \
    Resources/FilePath.cpp \
    Window/PlatformSpecific/Qt/QtWindowImpl.cpp \
    Window/PlatformSpecific/Qt/QtWindowManagerImpl.cpp

HEADERS += \
    Graph/GraphicsManager.h \
    Resources/Resources/Byte.h \
    Resources/Resources/Resource.h \
    Resources/Resources/ResourceID.h \
    Resources/ResourcesManager.h \
    Window/Window.h \
    Window/WindowManager.h \
    Window/WindowType.h \
    Graph/Texture.h \
    Graph/GraphicsScene.h \
    Graph/Actor.h \
    Graph/PlatformSpecific/Qt/QtTextureImpl.h \
    Graph/Camera.h \
    Graph/Animation.h \
    Graph/GraphicsSceneLayer.h \
    Graph/Color.h \
    Graph/AnimationCollection.h \
    UI/Components/ProgressBar.h \
    UI/Components/UIComponent.h \
    UI/UIScene.h \
    Resources/Resources/ResourcePack.h \
    Graph/ResourceLoaders/AnimationLoader.h \
    Graph/ResourceLoaders/AnimationCollectionLoader.h \
    Core/Data/Geometry/ResourceLoaders/GeometryLoader.h \
    Core/Data/Geometry/Geometry.h \
    Core/Data/Geometry/Point.h \
    Core/Data/Geometry/Rectangle.h \
    Core/Data/Geometry/Size.h \
    Core/Data/PlatformSpecific/Qt/QtStringImpl.h \
    Core/Data/String.h \
    Core/Task/Async/PlatformSpecific/Qt/QtActionImpl.h \
    Core/Task/Async/PlatformSpecific/Qt/QtActionImplRunnable.h \
    Core/Task/Async/PlatformSpecific/Qt/QtThreadPoolImpl.h \
    Core/Task/Async/Action.h \
    Core/Task/Async/Async.h \
    Core/Task/Async/ThreadPool.h \
    Core/Task/PlatformSpecific/Qt/QtTimerImpl.h \
    Core/Task/Timer.h \
    Core/Util/Assert.h \
    Core/Util/ConfigReader.h \
    GameEngine/States/States/SwitchInfo/SwitchStateInfo.h \
    GameEngine/States/States/SwitchInfo/SwitchToLoadingInfo.h \
    GameEngine/States/States/GameState.h \
    GameEngine/States/States/IntroState.h \
    GameEngine/States/States/LoadingState.h \
    GameEngine/States/States/MainState.h \
    GameEngine/States/States/MenuState.h \
    GameEngine/States/States/PreloadState.h \
    GameEngine/States/GameManager.h \
    GameEngine/Settings.h \
    Resources/Resources/PlatformSpecific/Qt/QtResourceImpl.h \
    Resources/FilePath.h \
    Window/PlatformSpecific/Qt/QtWindowImpl.h \
    Window/PlatformSpecific/Qt/QtWindowManagerImpl.h
