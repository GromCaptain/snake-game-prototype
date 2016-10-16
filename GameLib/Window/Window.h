#ifndef WINDOW_H
#define WINDOW_H

#include <memory>

#include "WindowType.h"

namespace Graphics
{
class Texture;
}

namespace Window
{

class WindowImpl;

class Window
	{
	public:
	explicit Window(std::shared_ptr<WindowImpl> impl);

	void setWindowType(WindowType type);
	void setResolution(unsigned w, unsigned h);

	void renderTexture(const Graphics::Texture& texture);

	private:
	std::shared_ptr<WindowImpl> pImpl;
	};

}

#endif // WINDOW_H
