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

	static Resource loadFromFileSystem(const String& fileName);

	private:
	Resource(const ResourceImpl& impl);

	private:
	std::shared_ptr<ResourceImpl> pImpl;
	};

#endif // RESOURCE_H
