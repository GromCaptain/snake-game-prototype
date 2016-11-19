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

using InputEventPtr = std::shared_ptr<InputEvent>;

class InputImpl
	{
	public:
	InputImpl();

	void flushEvents();
	std::queue<InputEventPtr> eventQueue() const;

	void registerKeyPressEvent(QKeyEvent* event);
	void registerKeyReleaseEvent(QKeyEvent* event);
	void registerMousePressEvent(QMouseEvent* event);
	void registerMouseReleaseEvent(QMouseEvent* event);
	void registerMouseMoveEvent(QMouseEvent* event);

	private:
	void registerInputEvent(InputEventPtr event);
	static std::queue<InputEventPtr> deepCopyToQueue(const std::deque<InputEventPtr>& source);
	static InputEventPtr cloneEvent(const InputEventPtr event);

	private:
	static const std::map<int, KeyboardKey> QKey2KeyboardKey;
	static const std::map<Qt::MouseButton, MouseButton> QButton2MouseButton;

	std::deque<InputEventPtr> ongoingEvents_;
	std::deque<InputEventPtr> prevFrameEvents_;
	std::mutex ongoingMutex_;
	mutable std::mutex prevFrameMutex_;
	};

}

#endif // INPUT_IMPL_H
