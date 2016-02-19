#ifndef TEXTURE_IMPL_H
#define TEXTURE_IMPL_H

#include <QImage>

class ResourceImpl;
class Rectangle;
class Size;

namespace Graphics
{

class Color;

class TextureImpl
	{
	public:
	TextureImpl();
	explicit TextureImpl(const ResourceImpl& resource);
	TextureImpl(const Size& size, const Color& bkgColor);
	TextureImpl(const TextureImpl& other);

	Rectangle rect() const;

	TextureImpl crop(const Rectangle& rect) const;

	void drawTexture(const TextureImpl& texture, const Rectangle& rect);

	const QImage& image() const;

	private:
	explicit TextureImpl(const QImage& image);

	private:
	QImage image_;
	};

}

#endif // TEXTURE_IMPL_H
