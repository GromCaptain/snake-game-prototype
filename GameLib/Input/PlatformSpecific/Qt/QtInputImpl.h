#ifndef INPUT_IMPL_H
#define INPUT_IMPL_H

#include <map>
#include <memory>
#include <mutex>
#include <queue>

#include <Qt>

class QKeyEvent;
class QMouseEvent;

namespace Input
{

class InputEvent;
enum class KeyboardKey;
enum class MouseButton;

class InputImpl
	{
	public:
	InputImpl();

	void flushEvents();
	std::queue<std::shared_ptr<InputEvent>> eventQueue() const;

	void registerKeyPressEvent(QKeyEvent* event);
	void registerKeyReleaseEvent(QKeyEvent* event);
	void registerMousePressEvent(QMouseEvent* event);
	void registerMouseReleaseEvent(QMouseEvent* event);
	void registerMouseMoveEvent(QMouseEvent* event);

	private:
	void registerInputEvent(std::shared_ptr<InputEvent> event);

	private:
	static const std::map<int, KeyboardKey> QKey2KeyboardKey;
	static const std::map<Qt::MouseButton, MouseButton> QButton2MouseButton;

	std::queue<std::shared_ptr<InputEvent>> ongoingEvents_;
	std::queue<std::shared_ptr<InputEvent>> prevFrameEvents_;
	std::mutex ongoingMutex_;
	mutable std::mutex prevFrameMutex_;
	};

}

#endif // INPUT_IMPL_H
