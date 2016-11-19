#include "QtInputImpl.h"

#include <QKeyEvent>

#include "Input/KeyboardKey.h"
#include "Input/MouseButton.h"
#include "Input/Events/KeyboardEvent.h"
#include "Input/Events/MouseButtonEvent.h"
#include "Input/Events/MouseMoveEvent.h"

#include "Core/Util/CloneFactory.h"

namespace Input
{

const std::map<int, KeyboardKey> InputImpl::QKey2KeyboardKey = {{Qt::Key_Escape, KeyboardKey::Esc}, {Qt::Key_Enter, KeyboardKey::Enter}, {Qt::Key_Space, KeyboardKey::Space}};
const std::map<Qt::MouseButton, MouseButton> InputImpl::QButton2MouseButton = {{Qt::LeftButton, MouseButton::Left}, {Qt::RightButton, MouseButton::Right}, {Qt::MiddleButton, MouseButton::Middle}};

InputImpl::InputImpl()
	{
	}

void InputImpl::flushEvents()
	{
	std::lock_guard<std::mutex> prevFrameGuard(prevFrameMutex_);
	std::lock_guard<std::mutex> ongoingGuard(ongoingMutex_);
	prevFrameEvents_ = ongoingEvents_;
	}

std::queue<InputEventPtr> InputImpl::eventQueue() const
	{
	std::lock_guard<std::mutex> prevFrameGuard(prevFrameMutex_);
	return deepCopyToQueue(prevFrameEvents_);
	}

void InputImpl::registerKeyPressEvent(QKeyEvent* event)
	{
	auto it = QKey2KeyboardKey.find(event -> key());
	if (it == QKey2KeyboardKey.end())
		return;
	auto keyEvent = std::make_shared<KeyboardEvent>(it -> second, EventType::KeyPress);
	registerInputEvent(keyEvent);
	}

void InputImpl::registerKeyReleaseEvent(QKeyEvent* event)
	{
	auto it = QKey2KeyboardKey.find(event -> key());
	if (it == QKey2KeyboardKey.end())
		return;
	auto keyEvent = std::make_shared<KeyboardEvent>(it -> second, EventType::KeyRelease);
	registerInputEvent(keyEvent);
	}

void InputImpl::registerMousePressEvent(QMouseEvent* event)
	{
	auto it = QButton2MouseButton.find(event -> button());
	if (it == QButton2MouseButton.end())
		return;
	auto buttonEvent = std::make_shared<MouseButtonEvent>(it -> second, EventType::MousePress);
	registerInputEvent(buttonEvent);
	}

void InputImpl::registerMouseReleaseEvent(QMouseEvent* event)
	{
	auto it = QButton2MouseButton.find(event -> button());
	if (it == QButton2MouseButton.end())
		return;
	auto buttonEvent = std::make_shared<MouseButtonEvent>(it -> second, EventType::MouseRelease);
	registerInputEvent(buttonEvent);
	}

void InputImpl::registerMouseMoveEvent(QMouseEvent* event)
	{
	Point pos = { event -> x(), event -> y() };
	auto moveEvent = std::make_shared<MouseMoveEvent>(pos);
	registerInputEvent(moveEvent);
	}

void InputImpl::registerInputEvent(InputEventPtr event)
	{
	std::lock_guard<std::mutex> ongoinGuard(ongoingMutex_);
	ongoingEvents_.push_back(event);
	}

std::queue<InputEventPtr> InputImpl::deepCopyToQueue(const std::deque<InputEventPtr>& source)
	{
	std::queue<InputEventPtr> result;
	for (auto eventPtr : source)
		result.push(cloneEvent(eventPtr));
	return result;
	}

InputEventPtr InputImpl::cloneEvent(const InputEventPtr event)
	{
	InputEvent* cloned = CloneFactory<InputEvent>::instance().clone(event.get());
	return InputEventPtr(cloned);
	}

}
