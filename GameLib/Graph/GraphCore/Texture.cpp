#include "Texture.h"
#include "PlatformSpecific/Qt/QtTextureImpl.h"

#include "Core/Data/Geometry/Rectangle.h"
#include "Core/Data/Geometry/Size.h"
#include "Resources/Resources/Resource.h"

namespace Graphics
{

Texture::Texture():
	pImpl(new TextureImpl())
	{
	}

Texture::Texture(const Resources::Resource& resource):
	pImpl(new TextureImpl(resource.impl()))
	{
	}

Texture::Texture(const Size& size, const Color& bkgColor):
	pImpl(new TextureImpl(size, bkgColor))
	{
	}

Texture::Texture(const Texture& other):
	pImpl(new TextureImpl(other.impl()))
	{
	}

Rectangle Texture::rect() const
	{
	return pImpl -> rect();
	}

Texture Texture::crop(const Rectangle& rect) const
	{
	return Texture(pImpl -> crop(rect));
	}

void Texture::drawTexture(const Texture& texture, const Rectangle& rect)
	{
	pImpl -> drawTexture(texture.impl(), rect);
	}

const TextureImpl&Texture::impl() const
	{
	return *pImpl;
	}

Texture::Texture(const TextureImpl& impl):
	pImpl(new TextureImpl(impl))
	{
	}

}
