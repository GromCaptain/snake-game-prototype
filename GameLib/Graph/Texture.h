#ifndef TEXTURE_H
#define TEXTURE_H

#include <memory>

#include "Color.h"

class Resource;
class Rectangle;
class Size;

namespace Graphics
{

class TextureImpl;

class Texture
	{
	public:
	Texture();
	explicit Texture(const Resource& resource);
	Texture(const Size& size, const Color& bkgColor = Color::Black);
	Texture(const Texture& other);

	Rectangle rect() const;

	Texture crop(const Rectangle& rect) const;

	void drawTexture(const Texture& texture, const Rectangle& rect);

	const TextureImpl& impl() const;

	private:
	explicit Texture(const TextureImpl& impl);

	private:
	std::shared_ptr<TextureImpl> pImpl;
	};

}

#endif // TEXTURE_H
