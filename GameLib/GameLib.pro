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
    Graph/GraphCore/Texture.cpp \
    Graph/Render/GraphicsScene/GraphicsScene.cpp \
    Graph/Render/GraphicsScene/Actor.cpp \
    Graph/GraphCore/PlatformSpecific/Qt/QtTextureImpl.cpp \
    Graph/Render/GraphicsScene/Camera.cpp \
    Graph/GraphCore/Animation.cpp \
    Graph/Render/GraphicsScene/GraphicsSceneLayer.cpp \
    Graph/GraphCore/Color.cpp \
    Graph/GraphCore/AnimationCollection.cpp \
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
    Window/PlatformSpecific/Qt/QtWindowManagerImpl.cpp \
    GameEngine/States/States/SwitchInfo/SwitchToIntroInfo.cpp \
    Input/Input.cpp \
    Input/PlatformSpecific/Qt/QtInputImpl.cpp \
    Input/Events/InputEvent.cpp \
    Input/Events/KeyboardEvent.cpp \
    Input/Events/MouseButtonEvent.cpp \
    Input/Events/MouseMoveEvent.cpp \
    UI/Components/Background.cpp \
    GameEngine/States/States/SwitchInfo/SwitchIntroToLoadingInfo.cpp \
    Graph/Render/RenderingPipeline.cpp \
    Graph/Render/GraphicsScene/GameGraphicsScene.cpp \
    Graph/Render/SingleAnimationRenderer.cpp \
    Graph/Render/UIGraphicsScene/UIActor.cpp \
    Graph/Render/UIGraphicsScene/UIGraphicsScenePage.cpp

HEADERS += \
    Graph/GraphicsManager.h \
    Resources/Resources/Byte.h \
    Resources/Resources/Resource.h \
    Resources/Resources/ResourceID.h \
    Resources/ResourcesManager.h \
    Window/Window.h \
    Window/WindowManager.h \
    Window/WindowType.h \
    Graph/GraphCore/Texture.h \
    Graph/Render/GraphicsScene/GraphicsScene.h \
    Graph/Render/GraphicsScene/Actor.h \
    Graph/GraphCore/PlatformSpecific/Qt/QtTextureImpl.h \
    Graph/Render/GraphicsScene/Camera.h \
    Graph/GraphCore/Animation.h \
    Graph/Render/GraphicsScene/GraphicsSceneLayer.h \
    Graph/GraphCore/Color.h \
    Graph/GraphCore/AnimationCollection.h \
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
    Window/PlatformSpecific/Qt/QtWindowManagerImpl.h \
    GameEngine/States/States/SwitchInfo/SwitchToIntroInfo.h \
    Input/KeyboardKey.h \
    Input/Input.h \
    Input/PlatformSpecific/Qt/QtInputImpl.h \
    Input/Events/InputEvent.h \
    Input/Events/KeyboardEvent.h \
    Input/MouseButton.h \
    Input/Events/MouseButtonEvent.h \
    Input/Events/MouseMoveEvent.h \
    Core/Util/CloneFactory.h \
    UI/Components/Background.h \
    Core/Util/UnorderedMap.h \
    GameEngine/States/States/SwitchInfo/SwitchIntroToLoadingInfo.h \
    Graph/Render/RenderingPipeline.h \
    Graph/Render/InitialRenderingStage.h \
    Graph/Render/IntermediateRenderingStage.h \
    Graph/Render/GraphicsScene/GameGraphicsScene.h \
    Graph/Render/GraphicsScene/ActorID.h \
    Graph/Render/GraphicsScene/LayersOwner.h \
    Graph/Render/SingleAnimationRenderer.h \
    Graph/Render/UIGraphicsScene/UIGraphicsScene.h \
    Graph/Render/UIGraphicsScene/UIActor.h \
    Graph/Render/UIGraphicsScene/UIGraphicsScenePage.h
