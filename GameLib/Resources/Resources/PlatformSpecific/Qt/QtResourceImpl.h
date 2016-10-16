#ifndef RESOURCE_IMPL_H
#define RESOURCE_IMPL_H

#include <QByteArray>

#include "Core/Data/String.h"
#include "Resources/Resources/Byte.h"

namespace Resources
{

class ResourceImpl
	{
	public:
	ResourceImpl();

	const Byte* data() const;
	unsigned dataSize() const;
	String asString() const;

	QByteArray byteArray() const;

	static ResourceImpl loadFromFileSystem(const String& fileName);

	private:
	explicit ResourceImpl(const QByteArray& b);

	private:
	QByteArray bytes;
	};

}

#endif // RESOURCE_IMPL_H
