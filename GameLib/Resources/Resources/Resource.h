#ifndef RESOURCE_H
#define RESOURCE_H

#include <memory>

#include "Byte.h"
#include "Core/String.h"

class ResourceImpl;

class Resource
	{
	public:
	Resource();

	const Byte* data() const;
	unsigned dataSize() const;
	String asString() const;

	const ResourceImpl& impl() const;

	static Resource loadFromFileSystem(const String& fileName);

	private:
	explicit Resource(const ResourceImpl& impl);

	private:
	std::shared_ptr<ResourceImpl> pImpl;
	};

#endif // RESOURCE_H
