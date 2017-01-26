#include "QtTextureImpl.h"

#include <QColor>
#include <QPainter>
#include <QRect>

#include "Core/Data/Geometry/Rectangle.h"
#include "Core/Data/Geometry/Size.h"
#include "Core/Util/Assert.h"
#include "Graph/GraphCore/Color.h"
#include "Resources/Resources/PlatformSpecific/Qt/QtResourceImpl.h"

namespace Graphics
{

TextureImpl::TextureImpl()
	{
	}

TextureImpl::TextureImpl(const Resources::ResourceImpl& resource)
	{
	image_.loadFromData(resource.byteArray());
	ASSERT(!image_.isNull(), "Texture loading from resource failed. Texture is null.");
	}

TextureImpl::TextureImpl(const Size& size, const Color& bkgColor):
	image_(size.width(), size.height(), QImage::Format_ARGB32)
	{
	int r = bkgColor.red(), g = bkgColor.green(), b = bkgColor.blue(), a = bkgColor.alpha();
	image_.fill(QColor(r, g, b, a));
	ASSERT(!image_.isNull(), "Texture is null. Should be filled with color texture.");
	}

TextureImpl::TextureImpl(const TextureImpl& other):
	image_(other.image_.copy())
	{
	}

Rectangle TextureImpl::rect() const
	{
	return Rectangle(0, 0, image_.width(), image_.height());
	}

TextureImpl TextureImpl::crop(const Rectangle& rect) const
	{
	return TextureImpl(image_.copy(rect.left(), rect.top(), rect.width(), rect.height()));
	}

void TextureImpl::drawTexture(const TextureImpl& texture, const Rectangle& rect)
	{
	ASSERT(!image_.isNull(), "Could not draw on null texture");
	if (texture.image().isNull())
		return;
	int left = rect.left(), top = rect.top(), w = rect.width(), h = rect.height();
	QRect target = { left, top, w, h };
	QPainter painter(&image_);
	painter.drawImage(target, texture.image_);
	}

const QImage& TextureImpl::image() const
	{
	return image_;
	}

TextureImpl::TextureImpl(const QImage& image):
	image_(image.copy())
	{
	}

}
